#include "robotclicklistener.h"

#include <iostream>
#include <memory>
#include <string>

const graphics::Color kWhite(graphics::Color(255, 255, 255));
const double kAnimationRatio = 8;
const int kAnimationMs = 60;

using std::cin;
using std::cout;
using std::string;

void RobotClickListener::Start() {
  string filename1;
  string filename2;
  cout << "Enter a filename for the robot icon: ";
  cin >> filename1;
  cout << "Enter another filename for the robot icon: ";
  cin >> filename2;
  robot_ = std::make_unique<Robot>(filename1, filename2);

  image_.Initialize(kSize_, kSize_);
  image_.AddMouseEventListener(*this);
  image_.AddAnimationEventListener(*this);

  robot_->SetPosition(last_x_, last_y_);
  robot_->Draw(image_);
  image_.ShowUntilClosed("Robot friend", kAnimationMs);
}

void RobotClickListener::OnMouseEvent(const graphics::MouseEvent& event) {
  // When the mouse moves or drags, update the mouse coordinates.
  if (event.GetMouseAction() == graphics::MouseAction::kMoved ||
      event.GetMouseAction() == graphics::MouseAction::kDragged) {
    last_x_ = event.GetX();
    last_y_ = event.GetY();
  }
}

void RobotClickListener::OnAnimationStep() {
  // Erase the image_.
  // Maybe not the most efficient solution but works fine on this scale.
  image_.DrawRectangle(0, 0, image_.GetWidth(), image_.GetHeight(), kWhite);
  // Find the next robot point.
  int x = (last_x_ + robot_->GetX() * (kAnimationRatio - 1)) / kAnimationRatio;
  int y = (last_y_ + robot_->GetY() * (kAnimationRatio - 1)) / kAnimationRatio;
  // Move the robot.
  robot_->SetPosition(x, y);
  // Draw the robot.
  robot_->Draw(image_);
  // Ensure the image_ is updated.
  image_.Flush();
}
