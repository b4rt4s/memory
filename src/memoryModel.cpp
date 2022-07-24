#include "memoryModel.hpp"

MemoryModel::MemoryModel()
    : playerBoard(board.getWidth() * board.getHeight(), ' '), score(0) {}

std::vector<char> MemoryModel::getPlayerBoard() const { return playerBoard; }

void MemoryModel::setPlayerBoardAt(Coordinates coords, char c) {
  playerBoard.at(coords.y * board.getWidth() + coords.x) = c;
}

void MemoryModel::addScore(int amount) { score += amount; }

int MemoryModel::getScore() const { return score; }

int MemoryModel::getWidth() const { return board.getWidth(); }

int MemoryModel::getHeight() const { return board.getHeight(); }

int MemoryModel::getUnrevealedTiles() const { return board.unrevealedTiles(); }

int MemoryModel::getRevealsLeftAt(Coordinates coords) const {
  return board.getRevealsLeftAt(coords);
}

int MemoryModel::getPossibleMovesLeft() const { return board.movesLeft(); }

char MemoryModel::getSignAt(Coordinates coords) const {
  return board.getSignAt(coords);
}

char MemoryModel::getTileTypeAt(Coordinates coords) const {
  return board.getTileTypeAt(coords);
}

bool MemoryModel::isTileRevealedAt(Coordinates coords) const {
  return board.isRevealedAt(coords);
}
void MemoryModel::revealTiles(std::vector<Coordinates> &coordsList) {
  board.revealTiles(coordsList);
}
void MemoryModel::subtractRevealsAt(std::vector<Coordinates> &coordsList) {
  for (Coordinates coords : coordsList) {
    board.subtractRevealsAt(coords);
  }
}