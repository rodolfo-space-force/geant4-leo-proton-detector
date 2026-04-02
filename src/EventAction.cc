#include "EventAction.hh"
#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh"

EventAction::EventAction(RunAction* run, PrimaryGeneratorAction* primary)
    : fRunAction(run), fPrimary(primary), fEdep(0.0) {}

EventAction::~EventAction() {}

void EventAction::EndOfEventAction(const G4Event* event) {
    double energy = fPrimary->GetIncidentEnergyMeV();

    double thickness_cm = 0.03; // 300 µm

    double LET = fEdep / thickness_cm; // MeV/cm

fRunAction->WriteEventData(
    event->GetEventID(),
    energy,
    fEdep,
    LET
);


    fEdep = 0.0;
}

void EventAction::AddEdep(double edep) {
    fEdep += edep;
}