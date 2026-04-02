#include "PhysicsList.hh"

#include <G4DecayPhysics.hh>
#include <G4EmStandardPhysics.hh>
#include <G4HadronElasticPhysics.hh>
#include <G4HadronPhysicsQGSP_BIC.hh>
#include <G4IonPhysics.hh>

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4HadronElasticPhysics());
    RegisterPhysics(new G4HadronPhysicsQGSP_BIC());
    RegisterPhysics(new G4IonPhysics());
}

PhysicsList::~PhysicsList() {}