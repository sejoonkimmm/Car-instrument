# Stage 1: Setup QEMU and dependencies
FROM multiarch/qemu-user-static as qemu

# Stage 2: Build stage
FROM arm64v8/debian:bookworm

# Copy QEMU from the first stage
COPY --from=qemu /usr/bin/qemu-aarch64-static /usr/bin/

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libgl1-mesa-dev \
    cmake \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-declarative-dev \
    qt6-base-dev-tools \
    curl \
    git

# Set up work directory
WORKDIR /workspace

# Copy only CMakeLists.txt first to leverage Docker layer caching
COPY CMakeLists.txt .

# Run cmake to configure and download dependencies, cache this layer
RUN mkdir -p /build && cd /build && cmake /workspace

# Copy the rest of the source code
COPY . .

# Build the project
RUN cd /build && make

# Debug: List files in the build directory after build
RUN ls -l /build