*This project has been created as part of the 42 curriculum by phofer and thchau.*

# cub3D — Our first RayCaster with miniLibX

## Description

cub3D is a graphical project inspired by the world-famous **Wolfenstein 3D** (Id Software, 1992), widely considered the first true First-Person Shooter in the history of video games. The goal is to build a "realistic" 3D rendering engine from scratch in C, producing a dynamic first-person view inside a maze using the **ray-casting** technique.

The program reads a scene description file (`.cub`) that defines the map layout, wall textures for each cardinal direction (North, South, East, West), and floor/ceiling colors. From that description, it renders an interactive 3D view in a window via the **miniLibX** library, allowing the player to navigate the maze in real time.

### Features

**Mandatory**
- Ray-casting engine rendering walls in pseudo-3D from a first-person perspective
- Distinct textures for each wall direction (N, S, E, W)
- Configurable floor and ceiling colors
- WASD movement and left/right arrow key camera rotation
- Clean exit on `ESC` or clicking the window's close button
- Robust `.cub` map parsing with error handling (invalid characters, unclosed maps, missing elements, etc.)

**Bonus**
- **Wall collision** — the player cannot walk through walls
- **Minimap** — an overhead 2D map overlay showing the player's position and orientation in real time
- **Rotate the point of view with the mouse** - use mouse movement for camera rotation

## Instructions

### Dependencies

- A C compiler (`cc`) with `make`
- **miniLibX** — either the system version or the bundled sources (included in the repository)
- X11 development libraries (Linux): `libx11-dev`, `libxext-dev`

On Ubuntu/Debian:
```bash
sudo apt-get install gcc make libx11-dev libxext-dev libbsd-dev
```

### Compilation

Clone the repository and build the mandatory part:

```bash
git clone <repository-url> cub3D
cd cub3D
make
```

To compile with the bonus features (wall collision + minimap):

```bash
make bonus
```

Other Makefile rules:

```bash
make clean    # Remove object files
make fclean   # Remove object files and the binary
make re       # Full recompile
```

### Usage

```bash
./cub3D <path/to/map.cub>
```

**Example:**
```bash
./cub3D maps/default.cub
```

### Map format (`.cub`)

A valid scene description file must contain the following elements (order is free, except the map which must be last):

| Identifier | Value |
|---|---|
| `NO` | Path to the North wall texture |
| `SO` | Path to the South wall texture |
| `WE` | Path to the West wall texture |
| `EA` | Path to the East wall texture |
| `F` | Floor color as `R,G,B` |
| `C` | Ceiling color as `R,G,B` |

Followed by the map itself, composed only of:
- `1` — wall
- `0` — empty space
- `N`, `S`, `E`, `W` — player start position and facing direction

The map must be fully enclosed by walls. Example of a valid map:

```
111111
100101
101001
1100N1
111111
```

### Controls

| Key | Action |
|---|---|
| `W` / `A` / `S` / `D` | Move forward / left / backward / right |
| `←` / `→` | Rotate camera left / right |
| `ESC` | Quit |
| Window ✕ button | Quit |

## Resources

### Ray-Casting & Game Engine

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — The definitive step-by-step guide to building a Wolfenstein-style raycaster in C/C++
- [Permadi's Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) — Classic 1996 walkthrough explaining the maths behind the technique
- [3DSage YouTube — Make Your Own Raycaster](https://www.youtube.com/watch?v=gYRrGTC7GtA) — Visual, beginner-friendly video series

### miniLibX

- [miniLibX documentation (42 unofficial)](https://harm-smits.github.io/42docs/libs/minilibx) — Covers window creation, hooks, image manipulation, and pixel drawing
- [miniLibX GitHub (macOS)](https://github.com/dannywillems/minilibx) — Official sources

### Reference

- [Wolfenstein 3D source code](https://github.com/id-Software/wolf3d) — John Carmack's original 1992 release, open-sourced by id Software

### AI Usage

AI (Claude) was used in this project for the following tasks:

- **Debugging** — Identifying subtle logic errors in the DDA (Digital Differential Analysis) algorithm and wall-hit detection
- **Math clarification** — Explaining the relationship between ray direction vectors, camera planes, and field of view to ensure the perspective projection was correct
- **Map parser edge cases** — Helping reason through edge cases in map validation (spaces inside the map, non-rectangular maps, missing player spawn)
- **Minimap rendering** — Advising on how to overlay a scaled 2D tile grid onto the 3D view without disrupting the main rendering loop

All code was written and reviewed by the project authors; AI was used strictly as a reference and debugging aid.
