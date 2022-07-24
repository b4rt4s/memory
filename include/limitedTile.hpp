#pragma once
#include "tile.hpp"

class LimitedTile : public Tile {
  int revealsLeft;

public:
  LimitedTile(char _sign, int reveals);

  int getRevealsLeft() override;
  void subtractReveal() override;
  char getType() override;
};