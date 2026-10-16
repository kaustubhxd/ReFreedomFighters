// batch828.cpp - gap band constant return functions (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x626a60: cdecl() ret 0 - returns constant 0x6bece8
static u32 __attribute__((cdecl)) const_626a60() {
  return 0x6bece8;
}
PCREG(626a60, const_626a60);

// 0x626a70: cdecl() ret 0 - returns constant 0x6be898
static u32 __attribute__((cdecl)) const_626a70() {
  return 0x6be898;
}
PCREG(626a70, const_626a70);

// 0x626e00: cdecl() ret 0 - returns constant 0x778
static u32 __attribute__((cdecl)) const_626e00() {
  return 0x778;
}
PCREG(626e00, const_626e00);

// 0x634811: cdecl() ret 0 - returns constant 0x4000
static u32 __attribute__((cdecl)) const_634811() {
  return 0x4000;
}
PCREG(634811, const_634811);

// 0x63486d: cdecl() ret 0 - returns constant 0x814248
static u32 __attribute__((cdecl)) const_63486d() {
  return 0x814248;
}
PCREG(63486d, const_63486d);

// 0x634873: cdecl() ret 0 - returns constant 0x814244
static u32 __attribute__((cdecl)) const_634873() {
  return 0x814244;
}
PCREG(634873, const_634873);
