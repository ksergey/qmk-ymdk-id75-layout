#!/bin/bash

# Keymap destination dir inside qmk firmare
keymapsDir="qmk_firmware/keyboards/idobo/keymaps"

# Available keymaps
keymaps=("fake")

set -e

if [ ! -d "qmk_firmware" ]; then
  echo "downloading qmk firmware"
  git clone --depth 1 --recurse-submodules --quiet https://github.com/qmk/qmk_firmware.git
fi

for index in ${!keymaps[*]}; do
  keymap=${keymaps[$index]}
  # Keymap path
  path="${keymapsDir}/${keymap}"

  if [ ! -h "${path}" ]; then
    ln -s "$(pwd)/${keymap}" "${path}"
    echo "layout ${keymap} ready (make idobo:${keymap}:flash)"
  fi
done
