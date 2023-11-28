// Mohamed Khalifa
// CPSC 121L-05
// 04/25/2023
// mkhalifa@csu.fullerton.edu
// mkhalifa21-byte
//
// Lab 13-2

#include "astronaut.h"
#include "crewmate.h"

#ifndef IMPOSTOR_H
#define IMPOSTOR_H

class Impostor : public Astronaut {
 public:
  Impostor(const std::string& name, const graphics::Color& color);
  Impostor();

  void Kill(Crewmate& crewmate) const;
};

#endif  // IMPOSTOR_H
