#!/bin/bash

# Define variables
DOCKER_IMAGE_NAME="arm64v8/debian:bookworm"
BUILD_DIR=$(pwd)/build
PI_USER="nexgen"
PI_HOST="192.168.86.48"
PI_KEY_PATH="~/.ssh/joon"
PI_TARGET_DIR="/home/nexgen"

# Build Docker image
docker build -t $DOCKER_IMAGE_NAME .

# Create and start the Docker container
docker create --name cross_compiler_container $DOCKER_IMAGE_NAME
docker start cross_compiler_container

# Copy build artifacts from the container
mkdir -p $BUILD_DIR
docker cp cross_compiler_container:/build $BUILD_DIR

# Remove the Docker container
docker rm cross_compiler_container

# List files in build directory
echo "Files in build directory:"
ls -l $BUILD_DIR

# Deploy the binary to Raspberry Pi
echo "Deploying binary to Raspberry Pi..."
scp -i $PI_KEY_PATH -r $BUILD_DIR/* $PI_USER@$PI_HOST:$PI_TARGET_DIR

echo "Deployment complete."