cmake_minimum_required(VERSION 3.16)
project(leo_detector)

find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})

include_directories(include)

add_executable(leo_detector
    src/main.cc
    src/DetectorConstruction.cc
    src/EventAction.cc
    src/PhysicsList.cc
    src/RunAction.cc
    src/SteppingAction.cc
    src/PrimaryGeneratorAction.cc   # 🔴 ESTE ESTAVA FALTANDO
)

target_link_libraries(leo_detector ${Geant4_LIBRARIES})