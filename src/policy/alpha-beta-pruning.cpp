#include <cstdlib>

#include "../state/state.hpp"
#include "./alpha-beta-pruning.hpp"

/**
 * @brief Minimax algorithm with alpha-beta pruning
 * 
 * @param state Now state
 * @param depth 
 * @return Move 
 */
Move AlphaBetaPruning::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  if(state->player == 0){
    int max = -1000000;
    Move result;
    if(depth == 0 || state->game_state == WIN){
      result = state->legal_actions[0];
    }
    else{
      for(auto action: state->legal_actions){
        auto next_state = state->next_state(action);
        int value = search(next_state, depth-1, false, -1000000, 1000000);
        if(value > max){
          max = value;
          result = action;
        }
      }
    }
    return result;
  }
  else{
    int min = 1000000;
    Move result;
    if(depth == 0 || state->game_state == WIN){
      result = state->legal_actions[0];
    }
    else{
      for(auto action: state->legal_actions){
        auto next_state = state->next_state(action);
        int value = search(next_state, depth-1, true, -1000000, 1000000);
        if(value < min){
          min = value;
          result = action;
        }
      }
    }
    return result;
  }
}

int AlphaBetaPruning::search(State *state, int depth, bool isMax, int alpha, int beta){
  
  if(state->game_state == WIN && isMax){
    return 1000000;
  }
  else if(state->game_state == WIN && !isMax){
    return -1000000;
  }
  if(depth == 0){
    return state->evaluate();
  }
  if(isMax){
    int max = -1000000;
    for(auto action: state->legal_actions){
      auto next_state = state->next_state(action);
      int value = search(next_state, depth-1, false, alpha, beta);
      if(value > max){
        max = value;
      }
      alpha = std::max(alpha, max);
      if(alpha >= beta){
        break;
      }
    }
    return max;
  }else{
    int min = 1000000;
    for(auto action: state->legal_actions){
      auto next_state = state->next_state(action);
      int value = search(next_state, depth-1, true, alpha, beta);
      if(value < min){
        min = value;
      }
      beta = std::min(beta, min);
      if(alpha >= beta){
        break;
      }
    }
    return min;
  }
}