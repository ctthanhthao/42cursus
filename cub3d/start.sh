#!/bin/bash
xhost +local:docker
docker run -it \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  --network=host \
  ubuntu-dev-franc-ruby-feb.25:latest
