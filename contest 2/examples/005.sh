#!/bin/bash -e
../a.out < 005.fsm > 005.fsm.c
gcc 005.fsm.c -o 005.fsm.a.out -Wformat -Werror -std=gnu11 -fsanitize=address -fno-sanitize-recover -ftrapv -fsanitize=undefined -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -lm
./005.fsm.a.out < 005-0.input | diff -Z - <(echo YES)
./005.fsm.a.out < 005-1.input | diff -Z - <(echo NO)
./005.fsm.a.out < 005-2.input | diff -Z - <(echo NO)
