FROM mcr.microsoft.com/devcontainers/base:ubuntu

ENV LANG=C.UTF-8 \
    TERM=xterm-256color

RUN sudo apt-get update && sudo apt-get -y install --no-install-recommends \
    gcc \
    g++ \
    python3 \
    vim \
    gdb \
    meson \
    ninja-build \
    libreadline-dev
