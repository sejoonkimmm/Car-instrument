# Stage 1: Setup QEMU and dependencies
FROM multiarch/qemu-user-static as qemu

# Stage 2: Build stage
FROM balenalib/raspberrypi4-64:latest

# Copy QEMU from the first stage
COPY --from=qemu /usr/bin/qemu-aarch64-static /usr/bin/

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    qt5-qmake \
    qtbase5-dev \
    qtbase5-dev-tools \
    qtdeclarative5-dev \
    qttools5-dev-tools \
    qtchooser \
    libqt5opengl5-dev \
    libqt5svg5-dev \
    libqt5multimedia5-plugins \
    libqt5multimedia5 \
    libqt5multimediawidgets5 \
    libqt5x11extras5-dev \
    libegl1-mesa-dev \
    libgles2-mesa-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    qtmultimedia5-dev \
    qtbase5-private-dev \
    cmake \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set up work directory
WORKDIR /workspace

# Copy the source code into the container
COPY . .

# Run the build commands with verbose output
RUN mkdir -p /build && cd /build && cmake -DCMAKE_VERBOSE_MAKEFILE=ON /workspace && make VERBOSE=1

# Debug: List files in the build directory after bundling
RUN ls -l /build && ls -l /build/qtlibs
