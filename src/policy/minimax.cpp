#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"

/**
 * @brief Minimax algorithm
 * 
 * @param state Now state
 * @param depth 
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  if(state->player == 0){
    int max = -1000000;
    Move result = state->legal_actions[0];
    if(depth == 0 || state->game_state == WIN){
      result = state->legal_actions[0];
    }
    else{
      for(auto action: state->legal_actions){
        auto next_state = state->next_state(action);
        int value = minimax(next_state, depth-1, false);
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
    Move result = state->legal_actions[0];
    if(depth == 0 || state->game_state == WIN){
      result = state->legal_actions[0];
    }
    else{
      for(auto action: state->legal_actions){
        auto next_state = state->next_state(action);
        int value = minimax(next_state, depth-1, true);
        if(value < min){
          min = value;
          result = action;
        }
      }
    }
    return result;
  }
}

int Minimax::minimax(State *state, int depth, bool isMax){
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
      int value = minimax(next_state, depth-1, false);
      if(value > max){
        max = value;
      }
    }
    return max;
  }else{
    int min = 1000000;
    for(auto action: state->legal_actions){
      auto next_state = state->next_state(action);
      int value = minimax(next_state, depth-1, true);
      if(value < min){
        min = value;
      }
    }
    return min;
  }
}