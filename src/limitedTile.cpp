#include "limitedTile.hpp"

LimitedTile::LimitedTile(char _sign, int reveals) : revealsLeft(reveals) {
  sign = _sign;
  isRevealed = false;
}

int LimitedTile::getRevealsLeft() { return revealsLeft; }

void LimitedTile::subtractReveal() { --revealsLeft; }

char LimitedTile::getType() {
  return 'l'; // l - limited
}
