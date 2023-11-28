// Mohamed Khalifa
// CPSC 121L-05
// 04/25/2023
// mkhalifa@csu.fullerton.edu
// mkhalifa21-byte
//
// Lab 13-2

#include "astronaut.h"

Astronaut::Astronaut(const std::string& name, const graphics::Color& color)
    : name_(name), color_(color) {}

const std::string& Astronaut::GetName() const {
  return name_;
}

const graphics::Color& Astronaut::GetColor() const {
  return color_;
}

const std::string& Astronaut::GetIconFilename() const {
  static const std::string filename = "astronaut.bmp";
  return filename;
}