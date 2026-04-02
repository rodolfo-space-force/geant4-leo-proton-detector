#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include <G4Step.hh>
#include <G4TouchableHandle.hh>
#include <G4VPhysicalVolume.hh>

SteppingAction::SteppingAction(EventAction* event, DetectorConstruction* det)
    : fEvent(event), fDetector(det) {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {

    // 🔴 Segurança: verificar ponteiros
    if (!step) return;

    auto prePoint = step->GetPreStepPoint();
    if (!prePoint) return;

    auto touchable = prePoint->GetTouchableHandle();
    if (!touchable) return;

    auto volume = touchable->GetVolume();
    if (!volume) return;

    // 🔴 Nome do volume
    G4String volumeName = volume->GetName();

    // 🔴 FILTRO: só o detector
    if (volumeName != "Detector") return;

    // 🔴 Energia depositada no passo
    G4double edep = step->GetTotalEnergyDeposit();

    if (edep > 0.0) {
        fEvent->AddEdep(edep);
    }
}