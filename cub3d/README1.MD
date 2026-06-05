# Docker GUI (X11) Setup on macOS with XQuartz

Run GUI applications inside Docker containers on macOS using X11 forwarding through XQuartz.

## Prerequisites

* Docker Desktop
* XQuartz

Download XQuartz: https://www.xquartz.org/

## 1. Start XQuartz

Launch XQuartz and allow local connections:

```bash
xhost +localhost
```

> **Note:** Avoid using `xhost +` except for temporary debugging, as it disables access control.

## 2. Configure DISPLAY

Set the DISPLAY environment variable on your host:

```bash
export DISPLAY=host.docker.internal:0
```

## 3. Start the Container

```bash
docker-compose up -d
```

Docker Compose configuration:

https://github.com/ctthanhthao/42cursus/blob/main/42%20Prague%20env%20simulation/docker-compose.yml

## 4. Verify the Setup

Open a shell inside the container and run a GUI application:

```bash
xclock
```

If `xclock` is not installed, run any GUI application available in the container.

## Troubleshooting

### Cannot open display

Verify that XQuartz is running:

```bash
echo $DISPLAY
```

Expected value:

```text
host.docker.internal:0
```

### Permission denied

Re-enable local X11 access:

```bash
xhost +localhost
```

### GUI still not working

Restart:

* XQuartz
* Docker Desktop

Then recreate the container:

```bash
docker-compose down
docker-compose up -d
```
