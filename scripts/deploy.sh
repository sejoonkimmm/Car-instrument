#!/bin/bash

REPO_URL="https://github.com/sejoonkimmm/Car-instrument"
TARGET_DIR="/home/pi/PiRacerInstrumentCluster"

# Verify network connection (PiRacer)
while ! ping -c 1 -W 1 google.com; do
    echo "Waiting for network connection..."
    sleep 5
done

# 프로젝트 디렉토리가 없으면 생성
if [ ! -d "$TARGET_DIR" ]; then
    mkdir -p "$TARGET_DIR"
fi

# 기존 프로젝트 디렉토리로 이동
cd "$TARGET_DIR"

# git 리포지토리 초기화 및 업데이트
if [ ! -d ".git" ]; then
    git init
    git remote add origin $REPO_URL
fi

# 최신 코드 가져오기
git fetch origin
git reset --hard origin/main

# 빌드 및 실행
mkdir -p build
cd build
cmake ../src
make

# 실행 파일을 백그라운드에서 실행 (필요에 맞게 조정)
if [ -f ./PiRacerInstrumentCluster ]; then
    ./PiRacerInstrumentCluster &
else
    echo "Build failed or executable not found"
    exit 1
fi
