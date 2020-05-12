#!/bin/sh
# sudo early to cache the auth so I can unplug
sudo echo "building ergodox_infinity:dudanian" && \
  make ergodox_infinity:dudanian && \
  sudo make ergodox_infinity:dudanian:dfu-util && \
  make ergodox_infinity:dudanian MASTER=right && \
  sudo make ergodox_infinity:dudanian:dfu-util MASTER=right