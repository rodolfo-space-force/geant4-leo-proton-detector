#include "PrimaryGeneratorAction.hh"

#include <G4ParticleTable.hh>
#include <G4ParticleDefinition.hh>
#include <G4SystemOfUnits.hh>
#include <G4Event.hh>

PrimaryGeneratorAction::PrimaryGeneratorAction() {

    particleGun = new G4ParticleGun(1);

    auto particle = G4ParticleTable::GetParticleTable()->FindParticle("proton");

    particleGun->SetParticleDefinition(particle);
    particleGun->SetParticleEnergy(100 * MeV);
    particleGun->SetParticlePosition(G4ThreeVector(0, 0, -20 * cm));
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    particleGun->GeneratePrimaryVertex(event);
}

double PrimaryGeneratorAction::GetIncidentEnergyMeV() const {
    return particleGun->GetParticleEnergy() / MeV;
}