# Stage 1: Setup QEMU and dependencies
FROM multiarch/qemu-user-static as qemu

# Stage 2: Build stage
FROM balenalib/raspberrypi4-64:latest

# Copy QEMU from the first stage
COPY --from=qemu /usr/bin/qemu-aarch64-static /usr/bin/

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libgl1-mesa-dev \
    cmake \
    qtbase5-dev \
    curl \
    git

# Set up work directory
WORKDIR /workspace

# Copy the source code into the container
COPY . .

# Run the build commands
RUN mkdir -p /build && cd /build && cmake -DCMAKE_VERBOSE_MAKEFILE=ON /workspace && make VERBOSE=1

# Debug: List files in the build directory after build
RUN ls -l /build && cat /build/CMakeFiles/CMakeOutput.log