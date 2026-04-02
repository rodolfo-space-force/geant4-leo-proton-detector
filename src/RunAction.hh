#ifndef RunAction_h
#define RunAction_h

#include <G4UserRunAction.hh>
#include <fstream>

class G4Run;

class RunAction : public G4UserRunAction {
public:
    RunAction();
    ~RunAction();

    virtual void BeginOfRunAction(const G4Run*) override;
    virtual void EndOfRunAction(const G4Run*) override;

    // 🔴 AGORA COM 4 PARÂMETROS
    void WriteEventData(int eventId, double energy, double edep, double let);

private:
    std::ofstream file;
};

#endif