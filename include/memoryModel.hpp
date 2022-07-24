#pragma once
#include "memoryBoard.hpp"

class MemoryModel {
  MemoryBoard board;
  std::vector<char> playerBoard;
  int score;

public:
  MemoryModel();

  std::vector<char> getPlayerBoard() const;

  void setPlayerBoardAt(Coordinates coords, char c);

  void addScore(int amount);
  int getScore() const;

  int getWidth() const;
  int getHeight() const;
  int getUnrevealedTiles() const;
  int getRevealsLeftAt(Coordinates coords) const;
  int getPossibleMovesLeft() const;
  char getSignAt(Coordinates coords) const;
  char getTileTypeAt(Coordinates coords) const;

  bool isTileRevealedAt(Coordinates coords) const;
  void revealTiles(std::vector<Coordinates> &coordsList);
  void subtractRevealsAt(std::vector<Coordinates> &coordsList);
};
