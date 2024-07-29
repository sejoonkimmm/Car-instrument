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

# Set up work directory
WORKDIR /workspace

# Copy the source code into the container
COPY . .

# Run the build commands with verbose output
RUN mkdir -p /build && cd /build && cmake -DCMAKE_VERBOSE_MAKEFILE=ON /workspace && make VERBOSE=1

# Manually copy Qt libraries
RUN cd /build && \
    mkdir -p qtlibs && \
    for lib in $(ldd InstrumentCluster | grep "=> /" | awk '{print $3}'); do cp -v $lib qtlibs; done

# Set RPATH for the binary
RUN patchelf --set-rpath '$ORIGIN/qtlibs' /build/InstrumentCluster

# Debug: List files in the build directory after bundling
RUN ls -l /build && ls -l /build/qtlibs
