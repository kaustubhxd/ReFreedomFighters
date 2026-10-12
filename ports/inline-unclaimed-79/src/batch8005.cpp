#include "ff.h"
// batch8005.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).
// Arity rule: each forwarder takes the same stack arguments as its target (target ret imm / 4) and passes them through.

// 0x48cf40 (GUESS): tail jump to 0x496350 (ret 4) with this+0x8; passes its 1 stack argument(s) through.
extern "C" u32 THISCALL ext_496350(u8 *self, u32 a0);
static u32 THISCALL f_48cf40(u8 *self, u32 a0) { return ext_496350((u8 *)(unsigned long)*(u32 *)(self + 0x8), a0); }
PCREG(48cf40, f_48cf40);

// 0x48ff80 (GUESS): tail jump to 0x497320 (ret 4) with this+0x8; passes its 1 stack argument(s) through.
extern "C" u32 THISCALL ext_497320(u8 *self, u32 a0);
static u32 THISCALL f_48ff80(u8 *self, u32 a0) { return ext_497320((u8 *)(unsigned long)*(u32 *)(self + 0x8), a0); }
PCREG(48ff80, f_48ff80);

// 0x48ff90 (GUESS): tail jump to 0x497390 (ret 4) with this+0x8; passes its 1 stack argument(s) through.
extern "C" u32 THISCALL ext_497390(u8 *self, u32 a0);
static u32 THISCALL f_48ff90(u8 *self, u32 a0) { return ext_497390((u8 *)(unsigned long)*(u32 *)(self + 0x8), a0); }
PCREG(48ff90, f_48ff90);

// 0x48ffa0 (GUESS): tail jump to 0x4973b0 (ret 4) with this+0x8; passes its 1 stack argument(s) through.
extern "C" u32 THISCALL ext_4973b0(u8 *self, u32 a0);
static u32 THISCALL f_48ffa0(u8 *self, u32 a0) { return ext_4973b0((u8 *)(unsigned long)*(u32 *)(self + 0x8), a0); }
PCREG(48ffa0, f_48ffa0);

// 0x48ffb0 (GUESS): tail jump to 0x497450 (ret 4) with this+0x8; passes its 1 stack argument(s) through.
extern "C" u32 THISCALL ext_497450(u8 *self, u32 a0);
static u32 THISCALL f_48ffb0(u8 *self, u32 a0) { return ext_497450((u8 *)(unsigned long)*(u32 *)(self + 0x8), a0); }
PCREG(48ffb0, f_48ffb0);

// 0x499dd0 (GUESS): tail jump to 0x499de0 (ret 8) with this+0xc; passes its 2 stack argument(s) through. 0x499de0 also has a ret 0xc path (0x499f4c); this port takes its first ret (ret 8) as arity.
extern "C" u32 THISCALL ext_499de0(u8 *self, u32 a0, u32 a1);
static u32 THISCALL f_499dd0(u8 *self, u32 a0, u32 a1) { return ext_499de0((u8 *)(unsigned long)*(u32 *)(self + 0xc), a0, a1); }
PCREG(499dd0, f_499dd0);
