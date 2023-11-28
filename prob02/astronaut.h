// Mohamed Khalifa
// CPSC 121L-05
// 04/25/2023
// mkhalifa@csu.fullerton.edu
// mkhalifa21-byte
//
// Lab 13-2

#include <string>

#include "cpputils/graphics/image.h"

#ifndef ASTRONAUT_H
#define ASTRONAUT_H

class Astronaut {
 public:
  Astronaut(const std::string& name, const graphics::Color& color);

  const std::string& GetName() const;
  const graphics::Color& GetColor() const;
  const std::string& GetIconFilename() const;

 private:
  std::string name_;
  graphics::Color color_;
};

#endif  // ASTRONAUT_H
