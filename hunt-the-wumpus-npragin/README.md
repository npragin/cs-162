# Hunt the Wumpus

A C++ implementation of the classic text-based adventure game "Hunt the Wumpus". Navigate through a cave system, avoid dangers, and escape with the Wumpus's gold!

## Game Overview

In this game, you are an adventurer exploring a cave system. Your goal is to escape with the Wumpus's gold or find and shoot the Wumpus while avoiding various hazards. The game features:

- A grid-based cave system
- Player movement in four directions (WASD controls)
- Arrow shooting mechanics
- Various hazards and events
- Percept system to detect nearby dangers

## Technical Requirements
- Object-oriented design with inheritance
- Polymorphic event handling
- Memory-safe implementation
- Modular file structure

## Building and Running

### Prerequisites
- C++11
- Make

### Usage

1. Compile the program:
```bash
make
```

2. Run the program:
```bash
./wumpus
```

## Game Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **F**: Fire an arrow

**Note:** To escape with the Wumpus's gold, you must find it, then make it back to the escape rope, which is where you spawn.

## Project Structure

- `game.hpp/cpp`: Main game logic and mechanics
- `room.hpp/cpp`: Room class implementation
- `player.hpp/cpp`: Player class and movement logic
- `moveable.hpp/cpp`: Base class for movable entities
- `events/`: Contains event-related classes (Wumpus, etc.) inheriting from `event.h/cpp`

### Events

- `event.h/cpp`: Abstract base class for all events
- `wumpus.h/cpp`: Wumpus class, kills the player
- `bat.h/cpp`: Bat class, confuses the player causing them to move to a random adjacent room
- `stalactites.h/cpp`: Stalactites class, 50% chance to kill the player if they enter the same room
- `gold.h/cpp`: Gold class, the player must make it back to the escape rope with the gold to win
- `escape_rope.h/cpp`: Escape rope class, the player must make it back to the escape rope with the gold to win
- `arrow.h/cpp`: Arrow class, the player can shoot arrows to kill the wumpus after picking one up

## Gameplay Features

### Percept Messages
When adjacent to events, you'll receive these warnings:
- Wumpus: "You smell a terrible stench."
- Super bats: "You hear wings flapping."
- Stalactites: "You hear water dripping."
- Gold: "You see something shimmer nearby."
- Arrow: "You see an arrow on the ground in an adjacent room"

### Lives and Death
- Start with 3 lives
- Death causes respawn at escape rope with -1 life
- Gold and arrows scatter to random empty rooms on death
- Game ends when all lives are lost

### Setup Options
- Cave dimensions: 4x4 to 30x30
- Debug mode: Shows all events (1) or player only (0)