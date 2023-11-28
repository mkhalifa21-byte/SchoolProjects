// Mohamed Khalifa
// CPSC 121L-05
// 04/25/2023
// mkhalifa@csu.fullerton.edu
// mkhalifa21-byte
//
// Lab 13-2

#include "crewmate.h"

#include <iostream>

Crewmate::Crewmate(const std::string& name, const graphics::Color& color)
    : Astronaut(name, color) {}

Crewmate::Crewmate() : Astronaut("no name", graphics::Color(0, 0, 0)) {}

bool Crewmate::GetIsAlive() const {
  return is_alive_;
}

void Crewmate::SetIsAlive(bool alive) {
  is_alive_ = alive;
}

int Crewmate::GetTaskCount() const {
  return task_count_;
}

void Crewmate::DoTask(const std::string& task_name) {
  task_count_++;
  std::cout << GetName() << " is doing " << task_name << std::endl;
}

graphics::Color Crewmate::GetColor() const {
  if (is_alive_) {
    return Astronaut::GetColor();
  } else {
    graphics::Color original_color = Astronaut::GetColor();
    graphics::Color shifted((original_color.Red() + 256) / 2,
                            (original_color.Green() + 256) / 2,
                            (original_color.Blue() + 256) / 2);
    return shifted;
  }
}

std::string Crewmate::GetIconFilename() const {
  if (is_alive_) {
    return Astronaut::GetIconFilename();
  } else {
    return "ghost.bmp";
  }
}