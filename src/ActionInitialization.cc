#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

ActionInitialization::ActionInitialization() {}
ActionInitialization::~ActionInitialization() {}

void ActionInitialization::Build() const {

    auto* primary = new PrimaryGeneratorAction();
    SetUserAction(primary);

    auto* runAction = new RunAction();
    SetUserAction(runAction);

    auto* eventAction = new EventAction(runAction, primary);
    SetUserAction(eventAction);

    SetUserAction(new SteppingAction(eventAction, nullptr));
}