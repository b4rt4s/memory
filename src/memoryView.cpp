#include "memoryView.hpp"

void MemoryView::displayBoard(std::vector<char> board, int width,
                              int height) const {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      std::cout << "[" << board.at(y * width + x) << "]";
    }

    std::cout << std::endl;
  }

  std::cout << "\n";
}

void MemoryView::displayStats(int score, int moves, int possibleMoves) const {
  std::cout << "Points: " << score << "\n";
  std::cout << "Moves done: " << moves << "\n";
  std::cout << "Possible moves left: " << possibleMoves << "\n\n";
}

void MemoryView::renderGame(BoardRender boardRender, int score, int moves,
                            int possibleMoves) const {
  system("clear");

  displayStats(score, moves, possibleMoves);

  displayBoard(boardRender.board, boardRender.width, boardRender.height);
}
