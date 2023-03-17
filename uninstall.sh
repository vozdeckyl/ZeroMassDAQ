#!/bin/bash

if [ "$EUID" -ne 0 ]
  then echo "Please run as root. Aborting."
  exit
fi

rm -r /usr/share/ZeroMassDAQ
rm /usr/share/applications/zeromassdaq.desktop
