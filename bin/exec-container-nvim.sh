#!/usr/bin/env bash

# このファイルは `devcontainer-cli` を用いてコンテナを立ち上げるためのスクリプトです。
# もしNeovim でこのプロジェクトを開発する際は使用してください

function checkCommand(cmd) {
    return command -v $cmd >/dev/null 2>&1
}

if checkCommand devcontainer; then
    devcontainer up
fi

