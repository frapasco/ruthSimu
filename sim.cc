#include <iostream>
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"


#include "DetectorConstruction.hh"
#include "physics.hh"
#include "action.hh"

int main(int argc, char** argv){
  G4RunManager* runManager = new G4RunManager();
  runManager->SetUserInitialization(new DetectorConstruction());
  runManager->SetUserInitialization(new PhysicsList());
  runManager->SetUserInitialization(new ActionInitialization());
    
  runManager->Initialize();
 
  G4UIExecutive* ui = new G4UIExecutive(argc,argv);

  G4VisManager* visManager = new G4VisExecutive();
  visManager->Initialize();

  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/viewpointVector 1 1 1");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/scene/add/axes 0 0 0 20 cm ");
      
  ui->SessionStart();

  return 0;
}