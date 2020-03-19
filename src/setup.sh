#!/bin/bash
mkdir /readall /restricted
echo "readall, this is world readable file" > /data/all.txt
echo "restricted, this is readable only by root" > /restricted/r.txt

chown root:root -R /data /restricted
chmod 700 -R /restricted
chmod 755 -R /data
