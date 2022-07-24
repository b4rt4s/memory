#pragma once
#include "coordinates.hpp"
#include "infinityTile.hpp"
#include "limitedTile.hpp"
#include "tile.hpp"
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <memory>
#include <vector>

class MemoryBoard {
  int width;
  int height;

  std::vector<std::unique_ptr<Tile>> board;

public:
  MemoryBoard();

  std::unique_ptr<Tile> tileGenerator(char sign, int reveals);

  int getWidth() const;
  int getHeight() const;

  char getSignAt(Coordinates coords) const;
  void revealTiles(std::vector<Coordinates> &coordsList);
  int getRevealsLeftAt(Coordinates coords) const;
  void subtractRevealsAt(Coordinates coords);
  bool isRevealedAt(Coordinates coords) const;
  char getTileTypeAt(Coordinates coords) const;

  int unrevealedTiles() const;
  int movesLeft() const;
};
