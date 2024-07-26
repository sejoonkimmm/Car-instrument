FROM debian:bookworm

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-declarative-dev \
    qtcreator \
    libqt6serialport6-dev \
    libqt6widgets6 \
    libqt6gui6 \
    libqt6core6 \
    qtbase6-dev-tools \
    qt6-qmake \
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

# Set environment variables for cross-compilation
ENV PATH /usr/bin:$PATH
ENV CROSS_COMPILE arm-none-eabi-

# Run the build commands
CMD ["bash", "-c", "mkdir -p build && cd build && cmake .. && make"]
