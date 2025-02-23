# so_long

so_long is a 2D game project built using MiniLibX, where the player navigates a maze, collects collectibles, and reaches the exit while avoiding enemies.

## Features
- Player movement in four directions (Up, Down, Left, Right)
- Animated player and enemies
- Collectible items to gather before reaching the exit
- Simple 2D graphics using MiniLibX
- Map validation and error handling

## How to Compile
Run the following command in the project directory:
```bash
make
```
This will generate the `so_long` executable.

## How to Execute
Run the game by providing a valid map file:
```bash
./so_long maps/example.ber
```

## Running in Docker (Ubuntu) on macOS
If you're using Docker with an Ubuntu container on macOS, follow these steps to enable X11 forwarding:

### 1️⃣ Start `socat` on macOS (host):
```bash
socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:"$DISPLAY"
```
This forwards X11 connections from a Docker container or remote system to your host’s X server, allowing MiniLibX to work properly.

### 2️⃣ Run Docker container with X11 forwarding:
```bash
docker run -it --rm -e DISPLAY=host.docker.internal:0 ubuntu bash
```

### 3️⃣ Inside Docker, install dependencies:
```bash
apt update && apt install -y x11-apps
```

### 4️⃣ Test GUI app inside Docker:
```bash
xclock  # Should open on your Mac screen
```

### 5️⃣ Run `so_long` inside Docker:
```bash
./so_long maps/example.ber
```

## Controls
- **W / Up Arrow** - Move Up
- **A / Left Arrow** - Move Left
- **S / Down Arrow** - Move Down
- **D / Right Arrow** - Move Right
- **ESC** - Quit the game

## Map Format
Maps must be `.ber` files with the following elements:
- `1` - Wall
- `0` - Empty space
- `P` - Player starting position
- `C` - Collectible
- `E` - Exit
- `X` - Enemy

Example:
```
11111
1P0C1
1C0E1
11111
```

## License
This project follows the [42 School] guidelines and is for educational purposes only.

