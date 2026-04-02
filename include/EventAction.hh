#ifndef EventAction_h
#define EventAction_h 1

#include <G4UserEventAction.hh>

class RunAction;
class PrimaryGeneratorAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* runAction, PrimaryGeneratorAction* primaryAction);
    virtual ~EventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

    void AddEdep(double edep);

private:
    double fEdep;
    RunAction* fRunAction;
    PrimaryGeneratorAction* fPrimaryAction;
};

#endif