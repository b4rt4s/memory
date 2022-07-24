#include "memoryController.hpp"
#include "memoryModel.hpp"
#include "memoryView.hpp"

int main() {
  MemoryModel model;
  MemoryView view;
  MemoryController ctrl{model, view};

  ctrl.play();
}
