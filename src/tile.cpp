#include "tile.hpp"

char Tile::seek() const { return sign; }

void Tile::reveal() { isRevealed = true; }

bool Tile::getIsRevealed() const { return isRevealed; }
