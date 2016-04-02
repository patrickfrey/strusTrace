#!/bin/sh

# DEBIAN
PACKAGEID="strustrace-0.7"

cd pkg/$PACKAGEID
dpkg-buildpackage

