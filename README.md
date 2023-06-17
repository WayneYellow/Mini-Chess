# Mini-Chess AI
## version
Minimax 2.0
new features:
- move ordering
- piece-square tables
- IDDFS that controled by processing time 

## introduction
This is a mini-chess AI that plays the game of mini-chess.
## Features
- Minimax (negamax)
- Alpha-beta pruning
- move ordering
- piece-square tables
- iterative deepening depth-first search (IDDFS)
- transposition table (in progress)
- monte carlo tree search (in progress)

## How to run

To run the AI, simply run the following command:

```
make
./build/main ./build/[player1_execution_file] ./build/[player2_execution_file]
```

note that there are three player execution files available:

- player_random: a player that makes random moves
- player_minimax: a player that uses minimax 
- player_alpha-beta-pruning: a player that uses minimax with alpha-beta pruning
- player_IDDFS: a player that uses iterative deepening depth-first search (IDDFS)

your environment must support make and g++ to run the AI.

## some results
### deepest depth reached
``` player_random: 0```    

``` player_minimax: 4```    

``` player_alpha-beta-pruning: 7```    

``` player_IDDFS: 6~8```(adjustable by processing time)
### player_random vs player_minimax(depth 3)
```minimax wins: 100.00%```
### player_random vs player_alpha-beta-pruning(depth 5)
```alpha-beta-pruning wins: 100.00%```
### player_minimax(depth 3) vs player_alpha-beta-pruning(depth 5)
```alpha-beta-pruning wins: 100.00%```
### player_IDDFS(1000ms) vs player_alpha-beta-pruning(depth 5)
```alpha-beta-pruning wins: 100.00%```
### player_IDDFS(1000ms) vs player_minimax(depth 3)
```minimax wins: 100.00%```
### player_IDDFS(1000ms) vs player_alpha-beta-pruning(depth 6)
```alpha-beta-pruning wins: 50.00%```
