#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4Geantino.hh"
#include "G4IonTable.hh"
#include "Randomize.hh"

#include "run.hh"

class ActionInitialization : public G4VUserActionInitialization{
public:
  ActionInitialization();
  ~ActionInitialization();
  
  virtual void Build() const; 
};

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction{
public:
  PrimaryGenerator();
  ~PrimaryGenerator();

  virtual void GeneratePrimaries(G4Event* anEvent);
private:
  G4ParticleGun *fParticleGun;
};

#endif
