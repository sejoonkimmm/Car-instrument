FROM debian:bookworm

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-declarative-dev \
    qtcreator \
    qt6-base-dev-tools \
    qt6-base \
    gcc-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    can-utils \
    python3 \
    python3-pip \
    curl \
    git

# Set up work directory
WORKDIR /workspace

# Copy the source code into the container
COPY . .

# Run the build commands
CMD ["bash", "-c", "mkdir -p build && cd build && cmake .. && make"]
