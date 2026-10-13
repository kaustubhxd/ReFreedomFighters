// u18_02.cpp - area 18, group 2: one-line accessors and constants (unclaimed-18 thread).
#include "ff.h"

// 0x428fd0, unnamed getter (GUESS: a byte flag at +0x78). thiscall; returns the byte in AL.
static u8 THISCALL getByte78(u8 *self) { return self[0x78]; }
PCREG(428fd0, getByte78);

// 0x638cd0, unnamed getter (GUESS: a dword at +0x32, unaligned). thiscall; returns the dword in EAX.
static u32 THISCALL getDword32(u8 *self) { return *(u32 *)(self + 0x32); }
PCREG(638cd0, getDword32);

// 0x5c39d0, unnamed (GUESS: an empty method). thiscall with two stack args (ret 8); returns 0.
static u32 THISCALL retZeroTwo(u8 *self, u32 a, u32 b) {
  (void)self; (void)a; (void)b;
  return 0;
}
PCREG(5c39d0, retZeroTwo);

// 0x604390, unnamed getter (GUESS: a word at +0x24). thiscall; returns the word in AX.
static u16 THISCALL getWord24(u8 *self) { return *(u16 *)(self + 0x24); }
PCREG(604390, getWord24);

// 0x443010, unnamed constant. thiscall; returns 4.
static u32 THISCALL const4(u8 *self) { (void)self; return 4; }
PCREG(443010, const4);

// 0x4c6190, unnamed global read. thiscall; returns the dword at 0x6e73b8.
static u32 THISCALL readGlobal6e73b8(u8 *self) { (void)self; return G(u32, 0x6e73b8); }
PCREG(4c6190, readGlobal6e73b8);

// 0x64b150, unnamed constant. thiscall; returns 0x24.
static u32 THISCALL const24(u8 *self) { (void)self; return 0x24; }
PCREG(64b150, const24);
