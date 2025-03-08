#!/bin/bash -e
../a.out < 002.fsm > 002.fsm.c
gcc 002.fsm.c -o 002.fsm.a.out -Wformat -Werror -std=gnu11 -fsanitize=address -fno-sanitize-recover -ftrapv -fsanitize=undefined -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -lm
./002.fsm.a.out < 002-0.input | diff -Z - <(echo YES)
./002.fsm.a.out < 002-1.input | diff -Z - <(echo NO)
./002.fsm.a.out < 002-2.input | diff -Z - <(echo NO)
