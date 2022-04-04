#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}
  ~Snake();
  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  float getSpeed() const;
  void setSpeed(float s);
  float getSize() const;
  void setSize(float s);
  Direction getDirection() const;
  void setDirection(Direction d);
  std::vector<SDL_Point> getBody() const ;

  bool alive{true};
  float head_x;
  float head_y;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
  float speed{0.1f};
  int size{1};
  std::vector<SDL_Point> body;
  Direction direction = Direction::kUp;

};

#endif