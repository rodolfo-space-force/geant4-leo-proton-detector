#ifndef EventAction_h
#define EventAction_h

#include <G4UserEventAction.hh>
#include <G4Event.hh>

class RunAction;
class PrimaryGeneratorAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* run, PrimaryGeneratorAction* primary);
    ~EventAction();

    virtual void EndOfEventAction(const G4Event*) override;

    void AddEdep(double edep);

private:
    RunAction* fRunAction;
    PrimaryGeneratorAction* fPrimary;
    double fEdep;
};

#endif