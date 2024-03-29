#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VSensitiveDetector.hh"
#include "G4NistManager.hh" 
#include "G4Material.hh"
#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4Cons.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"

class DetectorConstruction : public G4VUserDetectorConstruction{
public:
  DetectorConstruction();
  ~DetectorConstruction();
  
  virtual G4VPhysicalVolume* Construct();
  virtual void ConstructSDandField();
  
private:
  G4VPhysicalVolume* PhysicalWorld;
  
  
  G4LogicalVolume* PreDetLog;
  G4LogicalVolume* PostDetLog;
};

class SensitiveDetector : public G4VSensitiveDetector{
public:
  SensitiveDetector(G4String);
  ~SensitiveDetector();

private:
  virtual G4bool ProcessHits(G4Step *aStep, G4TouchableHistory *R0hist);
  G4VPhysicalVolume* physVol;
};

#endif
