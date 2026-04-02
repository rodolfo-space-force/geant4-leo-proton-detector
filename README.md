# Geant4 LEO Proton Detector Simulation

Simulation of proton interactions in a silicon detector using Geant4.

## Overview

This project models energy deposition of protons in a silicon detector under simplified Low Earth Orbit (LEO) radiation conditions.

The simulation includes:

- Proton beam generation (10–200 MeV)
- Silicon detector (300 µm thickness)
- Energy deposition tracking per event
- CSV output for statistical analysis

## Physics

The model captures:

- Ionization energy loss (Bethe-Bloch regime)
- Energy deposition fluctuations (Landau-like distribution)
- Particle transport through matter

## Structure

- `src/` → Geant4 implementation
- `macros/` → simulation control files
- `analysis/` → Python scripts for data analysis
- `results/` → output data

## Build

```bash
mkdir build
cd build
cmake .. -DGeant4_DIR="C:\Geant4\install\lib\cmake\Geant4"
cmake --build . --config Release