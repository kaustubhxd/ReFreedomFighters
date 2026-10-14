// u69_01.cpp - area 69, group 1 (residue 8, unclaimed-69 thread). Names are GUESS (no GC match); each is one line of code.

#include "ff.h"

// 0x4d0690, unnamed (GUESS: address of an inline field at +0x217). thiscall; returns this+0x217 in EAX.
static u8 *THISCALL addrOfField217(u8 *self) { return self + 0x217; }
PCREG(4d0690, addrOfField217);

// 0x492b10, unnamed setter (GUESS): sets the byte at +0xbc3 to 1. thiscall, void.
static void THISCALL setByteBc3One(u8 *self) { self[0xbc3] = 1; }
PCREG(492b10, setByteBc3One);

// 0x4951d0, unnamed setter (GUESS): clears the byte at +0xbc3. thiscall, void.
static void THISCALL clearByteBc3(u8 *self) { self[0xbc3] = 0; }
PCREG(4951d0, clearByteBc3);

// 0x48f7d0, unnamed getter (GUESS): returns the byte at +0xbc3 in AL. thiscall.
static u8 THISCALL getByteBc3(u8 *self) { return self[0xbc3]; }
PCREG(48f7d0, getByteBc3);
