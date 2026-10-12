#include "ff.h"
// batch8006.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x4831c0 (GUESS): stores the low byte of its stack argument at this+0x601.
static void THISCALL f_4831c0(u8 *self, u8 a) { *(u8 *)(self + 0x601) = a; }
PCREG(4831c0, f_4831c0);

// 0x484fe0 (GUESS): stores the low byte of its stack argument at this+0x42c.
static void THISCALL f_484fe0(u8 *self, u8 a) { *(u8 *)(self + 0x42c) = a; }
PCREG(484fe0, f_484fe0);

// 0x4850b0 (GUESS): stores its stack argument (dword) at this+0x60e.
static void THISCALL f_4850b0(u8 *self, u32 a) { *(u32 *)(self + 0x60e) = a; }
PCREG(4850b0, f_4850b0);

// 0x4870b0 (GUESS): stores its stack argument (dword) at this+0x8.
static void THISCALL f_4870b0(u8 *self, u32 a) { *(u32 *)(self + 0x8) = a; }
PCREG(4870b0, f_4870b0);

// 0x493190 (GUESS): stores the low byte of its stack argument at this+0xbb1.
static void THISCALL f_493190(u8 *self, u8 a) { *(u8 *)(self + 0xbb1) = a; }
PCREG(493190, f_493190);

// 0x494690 (GUESS): stores its stack argument (dword) at this+0x5d45.
static void THISCALL f_494690(u8 *self, u32 a) { *(u32 *)(self + 0x5d45) = a; }
PCREG(494690, f_494690);

// 0x4946a0 (GUESS): stores its stack argument (dword) at this+0x4.
static void THISCALL f_4946a0(u8 *self, u32 a) { *(u32 *)(self + 0x4) = a; }
PCREG(4946a0, f_4946a0);

