#Mini-Chess AI

## Introduction

This is a mini-chess AI. It uses the minimax algorithm with alpha-beta pruning to search the game tree. The evaluation function is a linear combination of several features. The AI is able to beat the random player 100% of the time and the greedy player 90% of the time.

## How to run

To run the AI, simply run the following command:

```
make
./build/main ./build/[player1_execution_file] ./build/[player2_execution_file]
```

note that there three player execution files available:

- player_random: a player that makes random moves
- player_minimax: a player that uses minimax 
- player_alpha-beta-pruning: a player that uses minimax with alpha-beta pruning

your environment must support make and g++ to run the AI.
