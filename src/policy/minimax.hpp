#pragma once
#include "../state/state.hpp"

/**
 * @brief Policy class for minimax policy, 
 */
class Minimax{
public:
  static Move get_move(State *state, int depth);
  static int minimax(State *state, int depth, bool isMax);
};