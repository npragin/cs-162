# Basketball Team Catalog

A C++ program that manages and displays basketball team and player statistics through an interactive menu system.

## Features

- Read team and player data from input files
- Search teams by name
- Display top scorers for each team
- Search players by nationality
- Display teams sorted by points per game
- Output results to console or file
- Dynamic memory management for teams and players

## Data Structure

The program uses two main structures:
- `team`: Stores team information (name, owner, market value, number of players, total PPG)
- `player`: Stores player information (name, age, nationality, PPG, field goal percentage)

## Usage

1. Compile the program using the provided makefile:
```bash
make
```

2. Run the program:
```bash
./hooping_catalog
```

3. Follow the interactive menu to:
   - Enter input filename containing team/player data
     - An input file already exists called `teams.txt`.
   - Choose search criteria
   - Select output destination (console or file)
