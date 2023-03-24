#!/bin/bash

if [ "$EUID" -ne 0 ]
  then echo "Please run as root. Aborting."
  exit
fi

function uninstall()
{
    echo "Uninstalling Zero Mass DAQ"

    echo "- rm -r /usr/share/ZeroMassDAQ"
    rm -r /usr/share/ZeroMassDAQ

    echo "- rm /usr/share/applications/zeromassdaq.desktop"
    rm /usr/share/applications/zeromassdaq.desktop

    echo "Done"
}

while true; do
    read -p "Do you really want it uninstall Zero Mass DAQ? [Y/n]: " yn
    case $yn in
	[Y]*) uninstall; break  ;;
	[Nn]*) echo "Aborted"; break ;;
    esac
done


