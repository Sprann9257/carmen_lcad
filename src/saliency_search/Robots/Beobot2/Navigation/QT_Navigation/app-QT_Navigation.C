/*!@file Robots/Beobot2/Navigation/QT_Navigation/app-QT_Navigation.C
 Nearness Diagram Navigation */
// //////////////////////////////////////////////////////////////////// //
// The iLab Neuromorphic Vision C++ Toolkit - Copyright (C) 2000-2002   //
// by the University of Southern California (USC) and the iLab at USC.  //
// See http://iLab.usc.edu for information about this project.          //
// //////////////////////////////////////////////////////////////////// //
// Major portions of the iLab Neuromorphic Vision Toolkit are protected //
// under the U.S. patent ``Computation of Intrinsic Perceptual Saliency //
// in Visual Environments, and Applications'' by Christof Koch and      //
// Laurent Itti, California Institute of Technology, 2001 (patent       //
// pending; application number 09/912,225 filed July 23, 2001; see      //
// http://pair.uspto.gov/cgi-bin/final/home.pl for current status).     //
// //////////////////////////////////////////////////////////////////// //
// This file is part of the iLab Neuromorphic Vision C++ Toolkit.       //
//                                                                      //
// The iLab Neuromorphic Vision C++ Toolkit is free software; you can   //
// redistribute it and/or modify it under the terms of the GNU General  //
// Public License as published by the Free Software Foundation; either  //
// version 2 of the License, or (at your option) any later version.     //
//                                                                      //
// The iLab Neuromorphic Vision C++ Toolkit is distributed in the hope  //
// that it will be useful, but WITHOUT ANY WARRANTY; without even the   //
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      //
// PURPOSE.  See the GNU General Public License for more details.       //
//                                                                      //
// You should have received a copy of the GNU General Public License    //
// along with the iLab Neuromorphic Vision C++ Toolkit; if not, write   //
// to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,   //
// Boston, MA 02111-1307 USA.                                           //
// //////////////////////////////////////////////////////////////////// //
//
// Primary maintainer for this file: Christian Siagian <siagian@usc.edu>
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/Robots/Beobot2/Navigation/QT_Navigation/app-QT_Navigation.C $
// $Id: app-QT_Navigation.C 12962 2010-03-06 02:13:53Z irock $
//

#include "Component/ModelManager.H"
#include "Component/ModelComponent.H"
#include "Component/ModelOptionDef.H"
#include "Robots/Beobot2/Navigation/QT_Navigation/QT_Navigation.H"

#include <Ice/Ice.h>
#include <Ice/Service.h>
#include "Ice/RobotSimEvents.ice.H"
#include "Ice/SimEventsUtils.H"
#include "Ice/IceImageUtils.H"
#include "Ice/RobotBrainObjects.ice.H"

// ######################################################################
// ######################################################################
class RobotBrainServiceService : public Ice::Service {
  protected:
    virtual bool start(int, char* argv[]);
    virtual bool stop() {
      if (itsMgr)
        delete itsMgr;
      return true;
    }

  private:
    Ice::ObjectAdapterPtr itsAdapter;
    ModelManager *itsMgr;
};

// ######################################################################
bool RobotBrainServiceService::start(int argc, char* argv[])
{
  MYLOGVERB = LOG_INFO;

  char adapterStr[255];

  //Create the adapter
  int port = RobotBrainObjects::RobotBrainPort;
  bool connected = false;

  // try to connect to ports until successful
  LDEBUG("Opening Connection");
  while(!connected)
  {
    try
    {
      LINFO("Trying Port:%d", port);
      sprintf(adapterStr, "default -p %i", port);
      itsAdapter = communicator()->createObjectAdapterWithEndpoints
        ("QT_Navigation", adapterStr);
      connected = true;
    }
    catch(Ice::SocketException)
    {
      port++;
    }
  }

  //Create the manager and its objects
  itsMgr = new ModelManager("QT_NavigationService");

  LINFO("Starting QT_Navigation System");
  nub::ref<QT_Navigation>
    nav(new QT_Navigation(*itsMgr, "QT_Navigation", "QT_Navigation"));
  LINFO("QT_Navigation created");
  itsMgr->addSubComponent(nav);
  LINFO("QT_Navigation Added As a subcomponent");
  nav->init(communicator(), itsAdapter);
  LINFO("QT_Navigation initiated");

  // check command line inputs/options
  itsMgr->parseCommandLine(argc, argv, "", 0, 0);

  // activate manager and adapter
  itsAdapter->activate();
  itsMgr->start();

  return true;
}

// ######################################################################
int main(int argc, char** argv) {

  RobotBrainServiceService svc;
  return svc.main(argc, argv);
}

// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */

