#include "car_model.h"


double
predict_next_pose_step(carmen_ackerman_traj_point_p new_robot_state, double targuet_v, double delta_t,
		double &achieved_curvature, const double &desired_curvature, double &max_curvature_change,
		carmen_robot_ackerman_config_t robot_config)
{
	carmen_ackerman_traj_point_t initial_robot_state = *new_robot_state;

	double delta_curvature = fabs(achieved_curvature - desired_curvature);
	double command_curvature_signal = (achieved_curvature < desired_curvature) ? 1.0 : -1.0;

	achieved_curvature = achieved_curvature + command_curvature_signal * fmin(delta_curvature, max_curvature_change);
	new_robot_state->phi = carmen_get_phi_from_curvature(achieved_curvature, initial_robot_state.v,
			robot_config.understeer_coeficient,	robot_config.distance_between_front_and_rear_axles);

	new_robot_state->phi = carmen_clamp(-robot_config.max_phi, new_robot_state->phi, robot_config.max_phi);

	// Tem que checar se as equacoes que governam esta mudancca de v estao corretas (precisa de um Euler?) e fazer o mesmo no caso do rrt_path_follower.
	double delta_v = fabs(initial_robot_state.v - targuet_v);
	double command_v_signal = (initial_robot_state.v <= targuet_v) ? 1.0 : -1.0;
	new_robot_state->v = initial_robot_state.v + command_v_signal * delta_v;

	double move_x = new_robot_state->v * delta_t * cos(initial_robot_state.theta);
	double move_y = new_robot_state->v * delta_t * sin(initial_robot_state.theta);

	new_robot_state->x	   += move_x;
	new_robot_state->y	   += move_y;
	new_robot_state->theta += new_robot_state->v * delta_t * tan(new_robot_state->phi) / robot_config.distance_between_front_and_rear_axles;

	return sqrt(move_x * move_x + move_y * move_y);
}


carmen_ackerman_traj_point_t
carmen_libcarmodel_recalc_pos_ackerman(carmen_ackerman_traj_point_t robot_state, double targuet_v, double targuet_phi,
		double full_time_interval, double *distance_traveled, double delta_t, carmen_robot_ackerman_config_t robot_config)
{
	int n = floor(full_time_interval / delta_t);
	double remaining_time = full_time_interval - ((double) n * delta_t);
	carmen_ackerman_traj_point_t achieved_robot_state = robot_state; // achieved_robot_state eh computado iterativamente abaixo a partir do estado atual do robo

	double curvature = carmen_get_curvature_from_phi(targuet_phi, targuet_v,
			robot_config.understeer_coeficient,	robot_config.distance_between_front_and_rear_axles);

	double new_curvature = carmen_get_curvature_from_phi(achieved_robot_state.phi, achieved_robot_state.v,
			robot_config.understeer_coeficient,	robot_config.distance_between_front_and_rear_axles);

	double max_curvature_change = robot_config.maximum_steering_command_rate * delta_t;

	// Euler method
	for (int i = 0; i < n; i++)
	{
		double dist_walked = predict_next_pose_step(&achieved_robot_state, targuet_v, delta_t,
				new_curvature, curvature, max_curvature_change, robot_config);

		if (distance_traveled)
			*distance_traveled += dist_walked;
	}

	if (remaining_time > 0.0)
	{
		double dist_walked = predict_next_pose_step(&achieved_robot_state, targuet_v, delta_t,
				new_curvature, curvature, max_curvature_change, robot_config);

		if (distance_traveled)
			*distance_traveled += dist_walked;
	}

	achieved_robot_state.theta = carmen_normalize_theta(achieved_robot_state.theta);
	robot_state = achieved_robot_state;

	return (achieved_robot_state);
}
