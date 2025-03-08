#!/bin/bash -e
../a.out < 003.fsm > 003.fsm.c
gcc 003.fsm.c -o 003.fsm.a.out -Wformat -Werror -std=gnu11 -fsanitize=address -fno-sanitize-recover -ftrapv -fsanitize=undefined -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -lm
./003.fsm.a.out < 003-0.input | diff -Z - <(echo NO)
./003.fsm.a.out < 003-1.input | diff -Z - <(echo NO)
./003.fsm.a.out < 003-2.input | diff -Z - <(echo NO)
