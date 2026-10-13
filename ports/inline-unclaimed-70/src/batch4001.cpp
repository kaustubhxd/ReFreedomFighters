// batch4001.cpp - area 70 (residue 9), batch 4001: five plain leaves (getters, setters, one conditional add).
#include "ff.h"

// 0x562010 (no name in residue lists; getter): thiscall, plain ret, al = byte at +0x85.
static u8 THISCALL getByte85(const u8 *self) { return self[0x85]; }
PCREG(562010, getByte85);

// 0x49e250 (setter, stack arg 4 bytes): thiscall, ret 4: dword at +0 of the object = the argument.
static void THISCALL setDword0(u32 *self, u32 v) { *self = v; }
PCREG(49e250, setDword0);

// 0x514450 (two-field setter): thiscall, ret 8: dword at +0x1e5 = first arg, float at +0x1e9 = second arg.
static void THISCALL setFields1e5(u8 *self, u32 a, float b) {
  *(u32 *)(self + 0x1e5) = a;
  *(float *)(self + 0x1e9) = b;
}
PCREG(514450, setFields1e5);

// 0x53c590 (two-dword setter): thiscall, ret 8: dwords at +4 and +8 = the two arguments.
static void THISCALL setDwords4and8(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 4) = a;
  *(u32 *)(self + 8) = b;
}
PCREG(53c590, setDwords4and8);

// 0x5ab0d0 (conditional add): thiscall, ret 4: unless the dword at +0x300 equals 0x10000000, the argument is added to
// the dword at +0x8c3 (unaligned).
static void THISCALL addUnlessFlag(u8 *self, u32 v) {
  if (*(u32 *)(self + 0x300) != 0x10000000u)
    *(u32 *)(self + 0x8c3) += v;
}
PCREG(5ab0d0, addUnlessFlag);
