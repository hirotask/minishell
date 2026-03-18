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

# Install neovim
RUN curl -o /tmp/nvim -L https://github.com/neovim/neovim/releases/latest/download/nvim-linux-x86_64.appimage \
    && chmod a+x /tmp/nvim \
    && cd /tmp \
    && ./nvim --appimage-extract \
    && cd /tmp/squashfs-root/usr \
    && rsync -rv . /usr/ \
    && rm -rf /tmp/nvim \
    && rm -rf /tmp/squashfs-root/usr


# Install Lazygit
RUN LAZYGIT_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | \grep -Po '"tag_name": *"v\K[^"]*') \
    && curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/download/v${LAZYGIT_VERSION}/lazygit_${LAZYGIT_VERSION}_Linux_x86_64.tar.gz" \
    && tar xf lazygit.tar.gz lazygit \
    && sudo install lazygit -D -t /usr/local/bin/

