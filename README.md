### [EN]

## Project Overview

`so_long` is a project given by Ecole 42 and aims to create a simple 2D game. This project will help you understand and implement the fundamentals of game programming, graphical interfaces, and event handling. The project involves creating a game where the player navigates a maze to collect specific objectives.

## Requirements

- **Language**: C
- **Libraries**: Minilibx (42's graphics library)
- **Standard**: POSIX compliant
- **Dependencies**: Minilibx library must be used; other external libraries are prohibited.

## Features

The key features to be implemented in this project include:

- **Game Area**:
  - Creating the maze structure.
  - The game area must include walls, paths, and objectives.

- **Character Management**:
  - Moving the player’s character using the keyboard (up, down, left, right).
  - Collecting objectives with the character and completing the game.

- **Graphics and Interface**:
  - Rendering graphics and interfaces using Minilibx.
  - Providing appropriate graphics for the game area, character, and objectives.

- **Game State and Outcome**:
  - Managing the game's start and end states.
  - Displaying a message when the game is successfully completed.

## Installation and Usage

### Installation

1. Clone the repository:

   git clone https://github.com/huseyinnatess/so_long.git

2. Navigate to the project directory:

   cd so_long

3. Ensure Minilibx library is installed. You can find more information on how to install Minilibx [here](https://github.com/42Paris/minilibx).

4. Build the project:

   make

### Usage

1. Launch the game:

   ./so_long map.ber

   Here, `map.ber` is a map file defining the game area. This file specifies the structure of the game field.

2. While playing, you can move your character using the arrow keys and collect objectives on the map.

3. The game will end when all objectives are collected or another termination condition is met.
