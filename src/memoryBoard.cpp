#include "memoryBoard.hpp"

MemoryBoard::MemoryBoard() : width(6), height(6) {
  std::vector<char> letters;

  for (int i = 65; i <= 90; i++) {
    letters.push_back(i);
  }

  srand(time(NULL));
  random_shuffle(std::begin(letters), std::end(letters));

  for (int i = 0; i < width * height; i += 2) {
    char letter = letters.back();
    letters.pop_back();

    int amountOfTileReveals = rand() % 10; // range 0 - 9
    // if amount is "< 2" then its inifity tile!

    for (int i = 0; i < 2; i++) {
      board.emplace_back(tileGenerator(letter, amountOfTileReveals));
    }
  }

  random_shuffle(std::begin(board), std::end(board));
}

std::unique_ptr<Tile> MemoryBoard::tileGenerator(char sign, int reveals) {
  if (reveals < 2) {
    return std::make_unique<InfinityTile>(sign);
  } else {
    return std::make_unique<LimitedTile>(sign, reveals);
  }
}

int MemoryBoard::getWidth() const { return width; }

int MemoryBoard::getHeight() const { return height; }

char MemoryBoard::getSignAt(Coordinates coords) const {
  return board.at(coords.y * width + coords.x)->seek();
}

void MemoryBoard::revealTiles(std::vector<Coordinates> &coordsList) {
  for (Coordinates coords : coordsList) {
    board.at(coords.y * width + coords.x)->reveal();
  }
}

int MemoryBoard::getRevealsLeftAt(Coordinates coords) const {
  int returnValue = board.at(coords.y * width + coords.x)->getRevealsLeft();

  if (returnValue < 0) {
    returnValue = 0;
  }

  return returnValue;
}

void MemoryBoard::subtractRevealsAt(Coordinates coords) {

  board.at(coords.y * width + coords.x)->subtractReveal();
}

bool MemoryBoard::isRevealedAt(Coordinates coords) const {
  return board.at(coords.y * width + coords.x)->getIsRevealed();
}

int MemoryBoard::unrevealedTiles() const {
  int unrevealed = 0;

  for (auto &tile : board) {
    if (!(tile->getIsRevealed())) {
      unrevealed++;
    }
  }

  return unrevealed;
}

int MemoryBoard::movesLeft() const {
  int moves = 0;

  for (auto &tile : board) {
    if (!(tile->getIsRevealed())) {
      moves += tile->getRevealsLeft();
    }
  }

  return moves;
}

char MemoryBoard::getTileTypeAt(Coordinates coords) const {
  return board.at(coords.y * width + coords.x)->getType();
}
