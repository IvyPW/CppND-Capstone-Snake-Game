#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <set>
#include "config.h"

int main() {
  std::cout << "Game Starting...!\n";
  std::cout << "Choose difficulty level:" << std::endl;
  std::cout << "Beginner: 1" << std::endl;
  std::cout << "Normal: 2" << std::endl;
  std::cout << "Hard: 3" << std::endl;
  int playerLevel;
  std::cin >> playerLevel;
  std::set<int> mySet {1, 2, 3};
  if(mySet.find(playerLevel) == mySet.end()){
    std::cout << "Wrong input. Only 1, 2 or 3 is accepted" << std::endl;
    return 0;
  }
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame, playerLevel);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}