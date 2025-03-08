#!/bin/bash -e
../a.out < 007.fsm > 007.fsm.c
gcc 007.fsm.c -o 007.fsm.a.out -Wformat -Werror -std=gnu11 -fsanitize=address -fno-sanitize-recover -ftrapv -fsanitize=undefined -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -lm
./007.fsm.a.out < 007-0.input | diff -Z - <(echo NO)
./007.fsm.a.out < 007-1.input | diff -Z - <(echo YES)
./007.fsm.a.out < 007-2.input | diff -Z - <(echo NO)
./007.fsm.a.out < 007-3.input | diff -Z - <(echo NO)
./007.fsm.a.out < 007-4.input | diff -Z - <(echo NO)
./007.fsm.a.out < 007-5.input | diff -Z - <(echo NO)
./007.fsm.a.out < 007-6.input | diff -Z - <(echo YES)
./007.fsm.a.out < 007-7.input | diff -Z - <(echo NO)
./007.fsm.a.out < 007-8.input | diff -Z - <(echo NO)
