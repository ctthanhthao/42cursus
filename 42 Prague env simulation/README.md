# 42 Dev Environment (Docker)

Docker environment for 42 school projects (example: `cub3d`). This repository provides a containerized Ubuntu development image with common Linux tools and MiniLibX/X11 support for graphical projects.

## Using the Prebuilt Image

Pull the prebuilt image:

```bash
docker pull ctthanhthao/42_working_environment:ubuntu-dev-23.01.25
```

Run the image interactively:

```bash
docker run -it ctthanhthao/42_working_environment:ubuntu-dev-23.01.25
```

## Quick Start (Docker Compose)

Start the environment in the foreground:

```bash
docker compose up
```

Start the environment in the background (detached):

```bash
docker compose up -d
```

### Enter the running container

```bash
docker exec -it dev-container bash
```

## Project Folder

Your project is mounted inside the container at:

```
/git_repo
```

Edit files on macOS and build inside the container.

## Build (example: `cub3d`)

Inside the container:

```bash
cd /git_repo/cub3d
make
```

## Run

```bash
./cub3d maps/your_map.cub
```

## X11 (macOS) — GUI support via MiniLibX

On macOS, install XQuartz to show graphical output from the container:

```bash
brew install --cask xquartz
```

Allow the container to connect to your X server:

```bash
xhost +host.docker.internal
```

If graphics do not appear, open XQuartz → Preferences → Security and enable "Allow connections from network clients", then restart XQuartz.

## Stop the container

```bash
docker compose down
```

## Notes

- Code runs inside Docker.
- Files are shared with your macOS host via the mounted `/git_repo` folder.
- X11/XQuartz is required for MiniLibX graphical output on macOS.
- Rebuild the image if you change the `Dockerfile`.
- Prebuilt image: `ctthanhthao/42_working_environment:ubuntu-dev-23.01.25`.

## Recommended workflow

```bash
docker compose up -d
docker exec -it dev-container bash
cd /git_repo/cub3d
make
./cub3d maps/test.cub
```

## Troubleshooting

- If the display is blank, ensure XQuartz is running before starting the container.
- If `docker exec` fails, confirm the container name with `docker ps` and use the correct name.
- If you change the `Dockerfile`, rebuild the image with `docker compose build` or `docker build`.

---

For more details, inspect the `docker-compose.yml` and `Dockerfile` in this repository.
