#!/bin/sh
AFL_HARDEN=1  CC=afl-gcc make
afl-fuzz -i tc -o fi ./new
