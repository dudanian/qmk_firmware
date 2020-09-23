#!/bin/bash

# exit when any command fails
set -e

# config for qmk
KEYBOARD=ergodox_infinity
KEYMAP=dudanian
DFU_ARGS="-d 1c11:b007"

# config for docker
# XXX very much assumes this is working dir
QMK_SRC=$(pwd)
WORKDIR=/qmk_firmware
USER="$(id -u):$(id -g)"

# stolen from tmk_core/chibios.mk
ERROR_COLOR=$'\033[31;01m'
NO_COLOR=$'\033[0m'
ERROR_MESSAGE="${ERROR_COLOR}ERROR:${NO_COLOR} Bootloader not found."


# helper functions
wait_for_bootloader() {
	until dfu-util -l | grep -q "Found DFU"; do
		echo "$ERROR_MESSAGE"
		sleep 5
	done
}

docker_make() {
	docker run -u $USER --rm -it -v $QMK_SRC:$WORKDIR qmkfm/base_container \
		make -C $WORKDIR $@
}

flash_image() {
	dfu-util $DFU_ARGS -D $1
}


# begin script
TARGET=${KEYBOARD}:${KEYMAP}
IMAGE=${KEYBOARD}_${KEYMAP}.bin

docker_make git-submodule
docker_make $TARGET
wait_for_bootloader
flash_image $IMAGE
docker_make $TARGET MASTER=right
wait_for_bootloader
flash_image $IMAGE
