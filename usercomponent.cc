/* 
This is free software: you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published 
by the Free Software Foundation version 3 of the License
http://www.gnu.org/licenses/

It is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

//Author: Alexei Sytov alexei.sytov@cern.ch

#include "BDSIMClass.hh" // bdsim interface

#include "CrystalDeflector.hh"
#include "CrystalDeflectorConstructor.hh"

#include "FTFP_BERT.hh"
#include "G4FastSimulationPhysics.hh"
#include "G4StepLimiterPhysics.hh"
#include <iostream>

int main(int argc, char** argv)
{
  // construct an instance of bdsim
  BDSIM* bds = new BDSIM();

  // Physics list
  G4VModularPhysicsList* physicsList = new FTFP_BERT;
  // -- Create helper tool, used to activate the fast simulation:
  G4FastSimulationPhysics* fastSimulationPhysics = new G4FastSimulationPhysics();
  fastSimulationPhysics->BeVerbose();
  // -- activation of fast simulation for particles having fast simulation models
  // -- attached in the mass geometry:
  fastSimulationPhysics->ActivateFastSimulation("e-");
  fastSimulationPhysics->ActivateFastSimulation("e+");
  // -- Attach the fast simulation physics constructor to the physics list:
  physicsList->RegisterPhysics( fastSimulationPhysics );
  physicsList->RegisterPhysics(new G4StepLimiterPhysics());
  bds->RegisterUserPhysicsList(physicsList);

  // register a custom component by name udipole with a user-provided constructor
  // BDSIM will delete the constructor at the end.
  bds->RegisterUserComponent("crystaldeflector", new CrystalDeflectorConstructor());

  // construct geometry and physics
  bds->Initialise(argc, argv);
  if (!bds->Initialised()) // check if there was a problem.
    {std::cout << "Intialisation failed" << std::endl; return 1;}
  
  bds->BeamOn(); // run the simulation
  delete bds;    // clean up
  return 0;      // exit nicely
}
