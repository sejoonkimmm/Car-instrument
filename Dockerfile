FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    sudo \
    build-essential \
    cmake \
    git \
    rsync \
    gcc-aarch64-linux-gnu \
    g++-aarch64-linux-gnu \
    make \
    libclang-dev \
    clang \
    ninja-build \
    bison \
    python3 \
    gperf \
    pkg-config \
    libfontconfig1-dev \
    libfreetype6-dev \
    libx11-dev \
    libx11-xcb-dev \
    libxext-dev \
    libxfixes-dev \
    libxi-dev \
    libxrender-dev \
    libxcb1-dev \
    libxcb-glx0-dev \
    libxcb-keysyms1-dev \
    libxcb-image0-dev \
    libxcb-shm0-dev \
    libxcb-icccm4-dev \
    libxcb-sync-dev \
    libxcb-xfixes0-dev \
    libxcb-shape0-dev \
    libxcb-randr0-dev \
    libxcb-render-util0-dev \
    libxcb-util-dev \
    libxcb-xinerama0-dev \
    libxcb-xkb-dev \
    libxkbcommon-dev \
    libxkbcommon-x11-dev \
    libatspi2.0-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    freeglut3-dev

# Set up directories for Qt cross-compilation
RUN mkdir -p /opt/rpi-sysroot /opt/qt-host /opt/qt-raspi /opt/qt-hostbuild /opt/qtpi-build

# Clone Qt source code
RUN cd /opt && git clone https://codereview.qt-project.org/qt/qt5 && \
    cd qt5 && \
    git checkout 6.4.0 && \
    perl init-repository -f

# Copy the toolchain file
COPY toolchain.cmake /opt/toolchain.cmake

WORKDIR /opt/qtpi-build
