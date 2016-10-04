#!/bin/bash

set -e
source ./funcs.sh

## Add .bashrc source command for workspace

msg ".bashrc entries will be entered..."

add_to "source ~/ttbws/devel/setup.bash" ~/.bashrc

# Add configs for ALICA bash prompt

add_to "# The next 2 lines determine the application domain for ALICA (Team-Modelling software)" ~/.bashrc
add_to "export DOMAIN_FOLDER=\"$HOME/ttbws/src/cnc-turtlebots\"" ~/.bashrc
add_to "export DOMAIN_CONFIG_FOLDER=\"$HOME/ttbws/src/cnc-turtlebots/etc\"" ~/.bashrc

# Add fancy bash prompt

add_to "#fancy prompt that also shows the current branch" ~/.bashrc
add_to "export PS1='\[\033[01;32m\]\u@\h\[\033[01;34m\] \w \[\033[01;31m\]\$(__git_ps1 \"[%s]\")\[\033[01;34m\]\$\[\033[00m\] '" ~/.bashrc

source ~/.bashrc
