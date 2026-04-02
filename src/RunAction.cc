#include "RunAction.hh"
#include <iostream>

RunAction::RunAction() {
    file.open("output.csv");

    if (!file.is_open()) {
        std::cout << "ERRO: nao abriu output.csv\n";
    } else {
        std::cout << "CSV criado com sucesso!\n";
        file << "Event,IncidentEnergy(MeV),DepositedEnergy(MeV),LET(MeV/cm)\n";
    }
}

RunAction::~RunAction() {
    if (file.is_open()) {
        file.close();
        std::cout << "CSV fechado.\n";
    }
}

void RunAction::BeginOfRunAction(const G4Run*) {}
void RunAction::EndOfRunAction(const G4Run*) {}

void RunAction::WriteEventData(
    int eventId,
    double energy,
    double edep,
    double let
) {
    if (file.is_open()) {
        file << eventId << ","
             << energy << ","
             << edep << ","
             << let << "\n";
    }
}