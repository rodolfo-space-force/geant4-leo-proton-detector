#ifndef SteppingAction_h
#define SteppingAction_h 1

#include <G4UserSteppingAction.hh>

class EventAction;
class DetectorConstruction;

class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction(EventAction* eventAction, DetectorConstruction* detectorConstruction);
    virtual ~SteppingAction();

    virtual void UserSteppingAction(const G4Step* step);

private:
    EventAction* fEventAction;
    DetectorConstruction* fDetectorConstruction;
};

#endif