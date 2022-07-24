#pragma once
#include "memoryModel.hpp"
#include "memoryView.hpp"
#include <chrono>
#include <limits>
#include <thread>
#include <tuple>
#include <vector>

class MemoryController {
protected:
  MemoryModel &model;
  const MemoryView &view;

public:
  MemoryController(MemoryModel &model, const MemoryView &view);

  int enterParametr(char p);
  Coordinates enterCoordinates();

  void setValues(Coordinates &coords, bool &g, char &c);
  void securityBasic(Coordinates &coords, bool &g);
  void securityParticular(Coordinates &coords1, Coordinates &coords2, bool &g,
                          char &c);
  void makeGuess(Coordinates &coords, char &c, int &moves,
                 BoardRender &boardRender);
  void setAndVerifyGameVariables(Coordinates &coords, bool &g, char &c);
  void setAndVerifyGameVariables(Coordinates &coords1, Coordinates &coords2,
                                 bool &g, char &c);
  void setNumberOrStar(std::vector<Coordinates> &coordsList);
  void checkMatch(Coordinates &coords1, Coordinates &coords2, char &c1,
                  char &c2);
  void checkWiningContidion(bool &won);
  void winningMessage(bool won, int moves) const;

  virtual void play();
};
