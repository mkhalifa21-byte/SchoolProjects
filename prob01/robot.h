#include <string>

#include "cpputils/graphics/image.h"

class Robot {
 public:
  Robot(const std::string& filename1, const std::string& filename2);
  void SetPosition(int x, int y);
  int GetX() const;
  int GetY() const;
  void Draw(graphics::Image& image);

 private:
  void DrawIconOnImage(graphics::Image& icon, graphics::Image& image) const;
  std::string filename1_;
  std::string filename2_;
  graphics::Image icon1_;
  graphics::Image icon2_;
  graphics::Color color_;
  int x_ = 0;
  int y_ = 0;
  int mod_ = 0;
};
