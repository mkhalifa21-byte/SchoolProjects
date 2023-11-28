// Mohamed Khalifa
// CPSC 121L-05
// 04/25/2023
// mkhalifa@csu.fullerton.edu
// mkhalifa21-byte
//
// Lab 13-2

#include "impostor.h"

#include <iostream>

#include "crewmate.h"

Impostor::Impostor(const std::string& name, const graphics::Color& color)
    : Astronaut(name, color) {}

Impostor::Impostor()
    : Impostor("default impostor", graphics::Color(GetColor().Blue())) {}

void Impostor::Kill(Crewmate& crewmate) const {
  std::cout << GetName() << " killed " << crewmate.GetName() << std::endl;
  crewmate.SetIsAlive(false);
}