#ifndef SteppingAction_h
#define SteppingAction_h

#include <G4UserSteppingAction.hh>

class EventAction;
class DetectorConstruction;
class G4Step;

class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction(EventAction* event, DetectorConstruction* det);
    ~SteppingAction();

    virtual void UserSteppingAction(const G4Step*) override;

private:
    EventAction* fEvent;
    DetectorConstruction* fDetector;
};

#endif