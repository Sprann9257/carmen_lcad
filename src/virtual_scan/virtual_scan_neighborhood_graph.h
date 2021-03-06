/*
 * virtual_scan.h
 *
 *  Created on: Nov 09, 2017
 *	  Author: claudine
 */

#ifndef SRC_VIRTUAL_SCAN_VIRTUAL_SCAN_NEIGHBORHOOD_GRAPH_H_
#define SRC_VIRTUAL_SCAN_VIRTUAL_SCAN_NEIGHBORHOOD_GRAPH_H_

typedef struct
{
	int num_pointers;
	void **pointers;
} virtual_scan_elements_t;

struct _virtual_scan_complete_sub_graph_t;
typedef struct _virtual_scan_graph_node_t
{
	virtual_scan_box_model_t box_model;
	double timestamp;
	_virtual_scan_complete_sub_graph_t *complete_sub_graph;
	virtual_scan_elements_t parents;
	virtual_scan_elements_t children;
	virtual_scan_elements_t siblings;
} virtual_scan_graph_node_t;

typedef struct _virtual_scan_complete_sub_graph_t
{
	int num_nodes;
	virtual_scan_graph_node_t *nodes;
	int selected;
} virtual_scan_complete_sub_graph_t; // Pensar em um nome melhor

typedef struct _virtual_scan_disconnected_sub_graph_t
{
	int num_sub_graphs;
	virtual_scan_complete_sub_graph_t *sub_graphs;
	_virtual_scan_disconnected_sub_graph_t *previous;
	_virtual_scan_disconnected_sub_graph_t *next;
	virtual_scan_extended_t *virtual_scan_extended;
} virtual_scan_disconnected_sub_graph_t;// Pensar em um nome melhor

typedef struct
{
	virtual_scan_disconnected_sub_graph_t *disconnected_sub_graph; // graph
	int sub_graph_index; //
	int node_index;
} virtual_scan_disconnected_sub_graph_iterator_t;

typedef struct
{
	int num_sub_graphs;
	int max_num_sub_graphs;
	virtual_scan_disconnected_sub_graph_t *first;
	virtual_scan_disconnected_sub_graph_t *last;
} virtual_scan_neighborhood_graph_t;


virtual_scan_disconnected_sub_graph_t *
virtual_scan_get_disconnected_sub_graph(virtual_scan_neighborhood_graph_t *neighborhood_graph, int i);

virtual_scan_neighborhood_graph_t *
virtual_scan_initiate_neighborhood_graph (int max_num_sub_graphs);

void
update_neighborhood_graph(virtual_scan_neighborhood_graph_t *neighborhood_graph,
		virtual_scan_box_model_hypotheses_t *box_model_hypotheses,
		virtual_scan_extended_t *virtual_scan_extended);


#endif /* SRC_VIRTUAL_SCAN_VIRTUAL_SCAN_NEIGHBORHOOD_GRAPH_H_ */
