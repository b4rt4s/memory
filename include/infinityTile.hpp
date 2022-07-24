#pragma once
#include "tile.hpp"

class InfinityTile : public Tile {
public:
  InfinityTile(char _sign);

  int getRevealsLeft() override;
  void subtractReveal() override;
  char getType() override;
};
