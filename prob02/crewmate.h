// Mohamed Khalifa
// CPSC 121L-05
// 04/25/2023
// mkhalifa@csu.fullerton.edu
// mkhalifa21-byte
//
// Lab 13-2

#include "astronaut.h"

#ifndef CREWMATE_H
#define CREWMATE_H

class Crewmate : public Astronaut {
 public:
  Crewmate(const std::string& name, const graphics::Color& color);
  Crewmate();

  bool GetIsAlive() const;
  void SetIsAlive(bool is_alive);

  int GetTaskCount() const;

  void DoTask(const std::string& task_name);

  graphics::Color GetColor() const;
  std::string GetIconFilename() const;

 private:
  bool is_alive_ = true;
  int task_count_ = 0;
};
#endif  // CREWMATE_H
