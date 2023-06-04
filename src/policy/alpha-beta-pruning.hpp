#pragma once
#include "../state/state.hpp"

/**
 * @brief Policy class for minimax policy, 
 */
class AlphaBetaPruning{
public:
  static Move get_move(State *state, int depth);
  static int search(State *state, int depth, bool isMax, int alpha, int beta);
};