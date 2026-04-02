#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>

class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event*) override;

    double GetIncidentEnergyMeV() const;

private:
    G4ParticleGun* particleGun;
};

#endif