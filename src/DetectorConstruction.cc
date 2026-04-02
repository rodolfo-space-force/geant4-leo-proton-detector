#include "DetectorConstruction.hh"

#include <G4NistManager.hh>
#include <G4Material.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4SystemOfUnits.hh>

DetectorConstruction::DetectorConstruction() {}
DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {

    auto nist = G4NistManager::Instance();

    // 🌌 World (vácuo)
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_Galactic");

    // 🔬 Detector (Si)
    G4Material* detectorMat = nist->FindOrBuildMaterial("G4_Si");

    // 🛰️ Blindagem (Al)
    G4Material* shieldMat = nist->FindOrBuildMaterial("G4_Al");

    // ===============================
    // 🌌 WORLD
    // ===============================
    G4double worldSize = 1.0 * m;

    auto solidWorld = new G4Box("World",
        worldSize/2,
        worldSize/2,
        worldSize/2);

    auto logicWorld = new G4LogicalVolume(
        solidWorld,
        worldMat,
        "World");

    auto physWorld = new G4PVPlacement(
        nullptr,
        G4ThreeVector(),
        logicWorld,
        "World",
        nullptr,
        false,
        0,
        true);

    // ===============================
    // 🛰️ SHIELD (Alumínio)
    // ===============================
    G4double shieldXY = 5.0 * cm;
    G4double shieldThickness = 2.0 * mm;

    auto solidShield = new G4Box("Shield",
        shieldXY/2,
        shieldXY/2,
        shieldThickness/2);

    auto logicShield = new G4LogicalVolume(
        solidShield,
        shieldMat,
        "Shield");

    // posição: antes do detector
    new G4PVPlacement(
        nullptr,
        G4ThreeVector(0, 0, -5 * mm),
        logicShield,
        "Shield",
        logicWorld,
        false,
        0,
        true);

    // ===============================
    // 🔬 DETECTOR (Silício)
    // ===============================
    G4double detectorSizeXY = 5.0 * cm;
    G4double detectorThickness = 300 * um;

    auto solidDetector = new G4Box("Detector",
        detectorSizeXY/2,
        detectorSizeXY/2,
        detectorThickness/2);

    auto logicDetector = new G4LogicalVolume(
        solidDetector,
        detectorMat,
        "Detector");

    // posição: depois do shield
    new G4PVPlacement(
        nullptr,
        G4ThreeVector(0, 0, 5 * mm),
        logicDetector,
        "Detector",
        logicWorld,
        false,
        0,
        true);

    return physWorld;
}