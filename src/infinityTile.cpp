#include "infinityTile.hpp"

InfinityTile::InfinityTile(char _sign) {
  sign = _sign;
  isRevealed = false;
}

int InfinityTile::getRevealsLeft() { return 1; }

void InfinityTile::subtractReveal() { return; }

char InfinityTile::getType() {
  return 'i'; // i - infinity
}
