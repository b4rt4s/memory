#pragma once

class Tile {
protected:
  char sign;
  bool isRevealed;

public:
  virtual int getRevealsLeft() = 0;
  virtual void subtractReveal() = 0;
  virtual char getType() = 0;

  bool getIsRevealed() const;
  char seek() const;

  void reveal();
};