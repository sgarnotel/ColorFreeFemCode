#!/bin/sh

SRC_DIR=$(pwd)
BUILD_DIR='../build'
QMAKE=qmake

mkdir $BUILD_DIR
cd $BUILD_DIR
$QMAKE $SRC_DIR
make
cp -R $SRC_DIR/img $BUILD_DIR/img
cp -R $SRC_DIR/system $BUILD_DIR/system
cp -R $SRC_DIR/example $BUILD_DIR/example



