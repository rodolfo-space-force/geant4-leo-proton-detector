#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"


#include <G4RunManager.hh>
#include <G4UImanager.hh>
#include <G4UIExecutive.hh>
#include <G4VisExecutive.hh>

int main(int argc, char** argv) {

    // 🔴 CRIA RUN MANAGER EM MODO SINGLE-THREAD
    auto* runManager = new G4RunManager();
    runManager->SetNumberOfThreads(1);  // ESSENCIAL

    // 🔧 INICIALIZAÇÃO DO DETECTOR E FÍSICA
    auto* detector = new DetectorConstruction();
    runManager->SetUserInitialization(detector);

    runManager->SetUserInitialization(new PhysicsList());

    // ⚙️ AÇÕES DO USUÁRIO
    auto* primary = new PrimaryGeneratorAction();
    runManager->SetUserAction(primary);

    auto* runAction = new RunAction();
    runManager->SetUserAction(runAction);

    auto* eventAction = new EventAction(runAction, primary);
    runManager->SetUserAction(eventAction);

    runManager->SetUserAction(new SteppingAction(eventAction, detector));

    // 🚀 INICIALIZAÇÃO
    runManager->Initialize();

    // 🎨 VISUALIZAÇÃO
    auto* visManager = new G4VisExecutive();
    visManager->Initialize();

    auto* uiManager = G4UImanager::GetUIpointer();

    // 🖥️ MODO INTERATIVO OU MACRO
    if (argc == 1) {
        auto* ui = new G4UIExecutive(argc, argv);
        uiManager->ApplyCommand("/control/execute macros/init.mac");
        ui->SessionStart();
        delete ui;
    } else {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        uiManager->ApplyCommand(command + fileName);
    }

    // 🧹 LIMPEZA
    delete visManager;
    delete runManager;

    return 0;
}