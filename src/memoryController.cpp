#include "memoryController.hpp"

using namespace std::chrono_literals;

MemoryController::MemoryController(MemoryModel &model, const MemoryView &view)
    : model(model), view(view) {}

int MemoryController::enterParametr(char p) {
  int k;

  std::cout << "Enter " << p << ": ";

  while (!(std::cin >> k)) {
    std::cout << "Enter " << p << ": ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return k;
}

Coordinates MemoryController::enterCoordinates() {
  int x = enterParametr('x'), y = enterParametr('y');

  return {x, y};
}

void MemoryController::setValues(Coordinates &coords, bool &g, char &c) {
  coords = enterCoordinates();
  g = true;
  c = model.getSignAt(coords);

  securityBasic(coords, g);
}

void MemoryController::securityBasic(Coordinates &coords, bool &g) {
  if (model.isTileRevealedAt(coords)) {
    std::cout << "Entered tile is already revealed, please chose another tile "
                 "to reveal!\n";
    g = false;
  }

  if (model.getRevealsLeftAt(coords) == 0) {
    std::cout << "You ran out of reveals for this tile, please chose another "
                 "tile to reveal!\n";
    g = false;
  }
}

void MemoryController::securityParticular(Coordinates &coords1,
                                          Coordinates &coords2, bool &g,
                                          char &c) {
  if (coords1.x == coords2.x && coords1.y == coords2.y) {
    std::cout << "You chosed same time as your second guess, please chose "
                 "another tile to reveal!\n";
    g = false;
  } else {
    securityBasic(coords2, g);

    c = model.getSignAt(coords2);
  }
}

void MemoryController::makeGuess(Coordinates &coords, char &c, int &moves,
                                 BoardRender &boardRender) {
  std::vector<Coordinates> coordsList{coords};
  model.subtractRevealsAt(coordsList);
  model.setPlayerBoardAt(coords, c);

  boardRender.board = model.getPlayerBoard();
  view.renderGame(boardRender, model.getScore(), moves,
                  model.getPossibleMovesLeft());

  std::this_thread::sleep_for(1s);
}

void MemoryController::setAndVerifyGameVariables(Coordinates &coords, bool &g,
                                                 char &c) {
  do {
    setValues(coords, g, c);
  } while (!g);
}

void MemoryController::setAndVerifyGameVariables(Coordinates &coords1,
                                                 Coordinates &coords2, bool &g,
                                                 char &c) {
  do {
    setValues(coords2, g, c);
    securityParticular(coords1, coords2, g, c);
  } while (!g);
}

void MemoryController::setNumberOrStar(std::vector<Coordinates> &coordsList) {
  for (Coordinates coords : coordsList) {
    if (model.getTileTypeAt(coords) == 'l')
      model.setPlayerBoardAt(
          coords, *std::to_string(model.getRevealsLeftAt(coords)).c_str());
    else
      model.setPlayerBoardAt(coords, '*');
  }
}

void MemoryController::checkMatch(Coordinates &coords1, Coordinates &coords2,
                                  char &c1, char &c2) {
  std::vector<Coordinates> coordsList{coords1, coords2};

  if (c1 != c2)
    setNumberOrStar(coordsList);
  else {
    model.revealTiles(coordsList);
    model.addScore(2);
  }
}

void MemoryController::checkWiningContidion(bool &won) {
  if (model.getUnrevealedTiles() == 0) {
    won = true;
  }
}

void MemoryController::winningMessage(bool won, int moves) const {
  if (won) {
    std::cout << "You won!\nMoves done: " << moves
              << "\nPoints: " << model.getScore() << "\n";
  } else {
    std::cout << "You lost!\nRemaining tiles: " << model.getUnrevealedTiles()
              << "\n";
  }

  std::this_thread::sleep_for(5s);
}

void MemoryController::play() {
  system("clear");

  Coordinates coords1, coords2;
  int moves = 0;
  char c1, c2;
  bool g1, g2, won = false;

  BoardRender boardRender;

  boardRender.height = model.getWidth();
  boardRender.width = model.getHeight();

  while (model.getUnrevealedTiles() > 0 && model.getPossibleMovesLeft() > 0) {
    boardRender.board = model.getPlayerBoard();
    view.renderGame(boardRender, model.getScore(), moves,
                    model.getPossibleMovesLeft());

    // Guess 1
    setAndVerifyGameVariables(coords1, g1, c1);
    makeGuess(coords1, c1, moves, boardRender);

    // Guess 2
    setAndVerifyGameVariables(coords1, coords2, g2, c2);
    makeGuess(coords2, c2, moves, boardRender);

    checkMatch(coords1, coords2, c1, c2);
    checkWiningContidion(won);

    ++moves;
  }

  winningMessage(won, moves);
}
