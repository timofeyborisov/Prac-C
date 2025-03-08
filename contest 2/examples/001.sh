#!/bin/bash -e
../a.out < 001.fsm > 001.fsm.c
gcc 001.fsm.c -o 001.fsm.a.out -Wformat -Werror -std=gnu11 -fsanitize=address -fno-sanitize-recover -ftrapv -fsanitize=undefined -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -lm
./001.fsm.a.out < 001-0.input | diff -Z - <(echo NO)
./001.fsm.a.out < 001-1.input | diff -Z - <(echo NO)
