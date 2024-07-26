# Stage 1: Setup QEMU and dependencies
FROM multiarch/qemu-user-static as qemu

# Stage 2: Build stage
FROM balenalib/raspberrypi4-64-debian:latest

# Copy QEMU from the first stage
COPY --from=qemu /usr/bin/qemu-aarch64-static /usr/bin/

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libgl1-mesa-dev \
    cmake \
    qt5-base-dev \
    qt5-tools-dev \
    qt5-declarative-dev \
    qt5-base-dev-tools \
    curl \
    git

# Set up work directory
WORKDIR /workspace

RUN ls -l /workspace

# Copy the source code into the container
COPY . .

RUN mkdir -p build && cd build && cmake ../ && make

# Debug: List files in the build directory after build
RUN ls -l /workspace/build