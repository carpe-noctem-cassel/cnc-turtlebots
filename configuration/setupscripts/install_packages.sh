#!/bin/bash

## Wenn es einen Fehler gibt, breche das Skript ab
set -e
source ./funcs.sh

## System gegebenenfalls updaten
if askSure "Update system?"
then
    if [ -z "$1" ]
    then
      msg "Ubuntu package sources will be updated..."
      sudo apt-get update
      msg "Ubuntu packages will be upgraded if necessary..."
      sudo apt-get upgrade
    else
      msg "Ubuntu packages sources will be updated..."
      sudo apt-get "${1}" update
      msg "Ubuntu packages will be upgraded if necessary..."
      sudo apt-get "${1}" upgrade
    fi
fi

## Installiere allgemeine Pakete fuer Entwicklung
msg "Common development packages will be installed..."

packages='git mr vim gitk meld bison re2c libtbb-dev'


echo $packages
if [ -z "$1" ]
then
  eval sudo apt-get install $packages
else
  eval sudo apt-get "${1}" install $packages
fi
