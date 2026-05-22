# Use the latest Ubuntu image as the base
FROM ubuntu:latest

# Set non-interactive mode for installation to avoid prompts
ENV DEBIAN_FRONTEND=noninteractive

# Update and install essential tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    git \
    valgrind \
    clang \
    python3 \
    python3-pip \
    lsb-release \
    wget \
    ca-certificates

# Manually install Python (to include distutils and venv)
RUN wget https://www.python.org/ftp/python/3.12.0/Python-3.12.0.tgz && \
    tar -xvf Python-3.12.0.tgz && \
    cd Python-3.12.0 && \
    ./configure --enable-optimizations && \
    make altinstall && \
    cd .. && \
    rm -rf Python-3.12.0 Python-3.12.0.tgz

# Install python3-venv
RUN apt-get install -y python3-venv

# Create Python and Pip symlinks only if they don't already exist
RUN [ ! -e /usr/bin/python ] && ln -s /usr/bin/python3 /usr/bin/python || true && \
    [ ! -e /usr/bin/pip ] && ln -s /usr/bin/pip3 /usr/bin/pip || true

# Clean up apt cache to reduce image size
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# Set the default command to start a shell
CMD ["/bin/bash"]
