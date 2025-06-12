# NBA 3-Point Shooting Contest Simulation

A C++ program that simulates the NBA 3-Point Shooting Contest, allowing multiple players to compete in a virtual shooting competition.

## Features

- Support for multiple players
- Interactive gameplay with user input
- Money ball rack placement strategy
- Starry ball bonus shots
- Visual shot tracking with score display
- Winner determination with tie handling

## Game Rules

1. Each player shoots 5 racks of 5 balls each
2. Regular shots are worth 1 point
3. Money balls (last ball in each rack) are worth 2 points
4. Starry balls (bonus shots) are worth 3 points
5. Players can choose which rack (1-5) will contain their money balls
6. The player with the highest total score wins

## How to Play

1. Enter the number of players
2. For each player:
   - Choose which rack (1-5) will contain your money balls
   - Watch your shots
3. After all players complete their rounds, the winner will be announced
4. Choose whether to play another game

## Usage

1. Compile the program:
```bash
g++ main.cpp -o go_hooping
```

2. Run the program:
```bash
./go_hooping
```
