#!/bin/sh

# DEBIAN
PACKAGEID="strusshadow-0.7"

cd pkg/$PACKAGEID
dpkg-buildpackage

