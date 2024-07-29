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
    qtdeclarative5-dev \
    qttools5-dev-tools \
    curl \
    git \
    patchelf

# Install linuxdeployqt
RUN curl -sSL -o /usr/local/bin/linuxdeployqt https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-6-x86_64.AppImage && \
    chmod +x /usr/local/bin/linuxdeployqt

# Set up work directory
WORKDIR /workspace

# Copy the source code into the container
COPY . .

# Run the build commands with verbose output
RUN mkdir -p /build && cd /build && cmake -DCMAKE_VERBOSE_MAKEFILE=ON /workspace && make VERBOSE=1

# Use linuxdeployqt to bundle the Qt application
RUN /usr/local/bin/linuxdeployqt /build/InstrumentCluster -appimage

# Debug: List files in the build directory after bundling
RUN ls -l /build
