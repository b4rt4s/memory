#pragma once
#include "boardRender.hpp"
#include <iostream>
#include <vector>

class MemoryView {
  void displayStats(int score, int moves, int possibleMoves) const;

public:
  void renderGame(BoardRender board, int score, int moves,
                  int possibleMoves) const;
  void displayBoard(std::vector<char> board, int width, int height) const;
};
