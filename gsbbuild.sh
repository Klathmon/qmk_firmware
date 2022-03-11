#! /usr/bin/env bash

rm -rf ./*.hex
qmk clean
qmk compile --parallel 0 -kb planck/rev3 -km klathmon
qmk compile --parallel 0 -kb keebio/iris/rev2 -km klathmon
qmk compile --parallel 0 -kb keebio/bdn9/rev1 -km klathmon
qmk compile --parallel 0 -kb qkf4 -km klathmon
qmk compile --parallel 0 -kb lily58/light -km klathmon
qmk compile --parallel 0 -kb lily58/rev1 -km klathmon
