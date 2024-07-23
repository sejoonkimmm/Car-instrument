#!/bin/bash

# 시스템 패키지 업데이트
sudo apt-get update -y
sudo apt-get upgrade -y

# 필요한 패키지 설치 확인 및 설치 함수
install_if_missing() {
    if ! dpkg -s "$1" >/dev/null 2>&1; then
        echo "Installing $1..."
        sudo apt-get install -y "$1"
    else
        echo "$1 is already installed."
    fi
}

# 필수 패키지 설치
install_if_missing git
install_if_missing qt6-default
install_if_missing qt6-qmake
install_if_missing qt6-base-dev
install_if_missing qt6-tools-dev
install_if_missing qt6-tools-dev-tools
install_if_missing cmake
install_if_missing prometheus
install_if_missing grafana

# Prometheus 설정
sudo systemctl enable prometheus
sudo systemctl start prometheus

# Grafana 설정
sudo systemctl enable grafana-server
sudo systemctl start grafana-server

# 설치 완료 메시지
echo "Installation and setup complete."