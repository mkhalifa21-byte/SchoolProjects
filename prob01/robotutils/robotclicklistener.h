#include <iostream>
#include <memory>
#include <string>

#include "../cpputils/graphics/image.h"
#include "../robot.h"

class RobotClickListener : public graphics::MouseEventListener,
                           public graphics::AnimationEventListener {
 public:
  // Tear down.
  ~RobotClickListener() {
    image_.RemoveMouseEventListener(*this);
    image_.RemoveAnimationEventListener(*this);
  }

  // Set up
  void Start();

  void OnMouseEvent(const graphics::MouseEvent& event) override;

  void OnAnimationStep() override;

 private:
  const int kSize_ = 500;
  std::unique_ptr<Robot> robot_;
  graphics::Image image_;
  int last_x_ = kSize_ / 2;
  int last_y_ = kSize_ / 2;
};
