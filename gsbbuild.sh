#! /usr/bin/env bash

rm -rf ./*.hex ./build
qmk clean

qmk compile --parallel 0 -kb crkbd/rev1 -km default &
qmk compile --parallel 0 -kb planck/rev3 -km klathmon &
qmk compile --parallel 0 -kb planck/rev3 -km steno &
qmk compile --parallel 0 -kb keebio/iris/rev2 -km klathmon &
qmk compile --parallel 0 -kb keebio/bdn9/rev1 -km klathmon &
qmk compile --parallel 0 -kb keebio/bdn9/rev1 -km default &
qmk compile --parallel 0 -kb qkf4 -km klathmon &
qmk compile --parallel 0 -kb lily58/light -km klathmon &
qmk compile --parallel 0 -kb lily58/rev1 -km klathmon &
qmk compile --parallel 0 -kb peej/lumberjack/klathmon -km klathmon &

mkdir -p ./build

wait

mv ./*.hex ./build
