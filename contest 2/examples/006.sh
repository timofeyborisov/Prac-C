#!/bin/bash -e
../a.out < 006.fsm > 006.fsm.c
gcc 006.fsm.c -o 006.fsm.a.out -Wformat -Werror -std=gnu11 -fsanitize=address -fno-sanitize-recover -ftrapv -fsanitize=undefined -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -lm
./006.fsm.a.out < 006-0.input | diff -Z - <(echo NO)
./006.fsm.a.out < 006-1.input | diff -Z - <(echo YES)
./006.fsm.a.out < 006-2.input | diff -Z - <(echo NO)
./006.fsm.a.out < 006-3.input | diff -Z - <(echo NO)
./006.fsm.a.out < 006-4.input | diff -Z - <(echo NO)
./006.fsm.a.out < 006-5.input | diff -Z - <(echo NO)
./006.fsm.a.out < 006-6.input | diff -Z - <(echo YES)
./006.fsm.a.out < 006-7.input | diff -Z - <(echo NO)
./006.fsm.a.out < 006-8.input | diff -Z - <(echo NO)
