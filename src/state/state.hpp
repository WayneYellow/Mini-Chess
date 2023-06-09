#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

#include "../config.hpp"


typedef std::pair<size_t, size_t> Point;
typedef std::pair<Point, Point> Move;
class Board{
  public:
    char board[2][BOARD_H][BOARD_W] = {{
      //white
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {2, 3, 4, 5, 6},
    }, {
      //black
      {6, 5, 4, 3, 2},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    }};
};

enum GameState {
  UNKNOWN = 0,
  WIN,
  DRAW,
  NONE
};

static const double piece_square_table[7][6][5] = {
  {{0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0}},
  {{ 1.0, 1.0, 1.0, 1.0, 1.0},  //pawn
   { 0.6, 0.6, 0.4, 0.2, 0.2},
   { 0.5, 0.5, 0.2, 0.1, 0.1},
   { 0.1,-0.1,-0.2,-0.4,-0.4},
   { 0.1, 0.2, 0.2,-0.4,-0.4},
   {   0,   0,   0,   0,   0}},
  {{-1.0,-0.6,-0.3,-0.6,-1.0},  //knight
   {-0.6,   0, 0.3,   0,-0.6},
   {-0.3, 0.3, 0.4, 0.3,-0.3},
   {-0.3, 0.3, 0.4, 0.3,-0.3},
   {-0.6,   0, 0.3,   0,-0.6},
   {-1.0,-0.6,-0.3,-0.6,-1.0}},
  {{-0.4,-0.2,-0.2,-0.2,-0.4},  //bishop
   {-0.2, 0.2, 0.2, 0.2,-0.2},
   {-0.2, 0.1, 0.4, 0.1,-0.2},
   {-0.2, 0.1, 0.4, 0.1,-0.2},
   {-0.2, 0.2, 0.2, 0.2,-0.2},
   {-0.4,-0.2,-0.2,-0.2,-0.4}},
  {{   0,   0,   0,   0,   0},  //rook
   { 0.1, 0.2, 0.2, 0.2, 0.1},
   {-0.1,   0,   0,   0,-0.1},
   {-0.1,   0,   0,   0,-0.1},
   {-0.1,   0,   0,   0,-0.1},
   { 0.1,   0,   0,   0,   0}},
  {{-0.4,-0.2,-0.2,-0.2,-0.4},  //queen
   {-0.2, 0.1, 0.1, 0.1,-0.2},
   {-0.2, 0.1, 0.1, 0.1,-0.2},
   {-0.2, 0.1, 0.1, 0.1,-0.2},
   {-0.2, 0.1, 0.1, 0.1,-0.2},
   {-0.4,-0.2,-0.2,-0.2,-0.4}},
  {{-1.0,-0.8,-0.8,-0.6,-0.6},  //king
   {-1.0,-0.8,-0.8,-0.6,-0.6},
   {-1.0,-0.8,-0.8,-0.6,-0.5},
   {-1.0,-0.8,-0.8,-0.5,-0.4},
   {   0,   0,   0,   0,   0},
   {   0,   0,   0, 0.5, 0.5}}
};

class State{
  public:
    //You may want to add more property for a state
    GameState game_state = UNKNOWN;
    Board board;
    int player = 0;
    std::vector<Move> legal_actions;
    
    State(){};
    State(int player): player(player){};
    State(Board board): board(board){};
    State(Board board, int player): board(board), player(player){};
    
    double evaluate();
    State* next_state(Move move);
    void get_legal_actions();
    void sort_legal_actions(int is_white);
    std::string encode_output();
    std::string encode_state();
    
};

#endif