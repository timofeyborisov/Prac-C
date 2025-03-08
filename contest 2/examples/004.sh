#!/bin/bash -e
../a.out < 004.fsm > 004.fsm.c
gcc 004.fsm.c -o 004.fsm.a.out -Wformat -Werror -std=gnu11 -fsanitize=address -fno-sanitize-recover -ftrapv -fsanitize=undefined -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wstrict-prototypes -Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign -lm
./004.fsm.a.out < 004-0.input | diff -Z - <(echo NO)
./004.fsm.a.out < 004-1.input | diff -Z - <(echo NO)
./004.fsm.a.out < 004-2.input | diff -Z - <(echo YES)
./004.fsm.a.out < 004-3.input | diff -Z - <(echo YES)
./004.fsm.a.out < 004-4.input | diff -Z - <(echo NO)
