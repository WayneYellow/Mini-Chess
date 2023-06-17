#include <cstdlib>
#include <chrono>

#include "../state/state.hpp"
#include "./IDDFS.hpp"

const std::chrono::milliseconds TIMEOUT_THRESHOLD(700);
/**
 * @brief Minimax algorithm with alpha-beta pruning
 * 
 * @param state Now state
 * @param depth 
 * @return Move 
 */
Move Policy::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  bool player = state->player;
  if(player){
    state->sort_legal_actions(-1);
  }
  else{
    state->sort_legal_actions(1);
  }
  int max = 1000000*(player*2-1);
  Move result;
  if(depth == 0 || state->game_state == WIN)
    result = state->legal_actions[0];
  else{
    for(auto action: state->legal_actions){
      auto next_state = state->next_state(action);
      int value = search(next_state, depth-1, player, -1000000, 1000000);
      if((player*2-1)*value < (player*2-1)*max){
        max = value;
        result = action;
      }
    }
    return result;
  }
}

int Policy::search(State *state, int depth, bool isMax, int alpha, int beta){
  
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
      int value = search(next_state, depth-1, !isMax, alpha, beta);
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
      int value = search(next_state, depth-1, !isMax, alpha, beta);
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

/**
 * @brief Iterative deepening depth-first search with time limit
 * 
 * @param state 
 * @param depth 
 * @return int 
 */
Move Policy::iterative_deepening(State *state){
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    int depth = 5;
    Move result;
    while(duration < TIMEOUT_THRESHOLD){
        result = get_move(state, depth);
        end = std::chrono::system_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        if(duration > TIMEOUT_THRESHOLD){
            break;
        }
        depth++;
    }
    return result;
}