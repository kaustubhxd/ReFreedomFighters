#include "ff.h"
// batch8011.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x499a00 (GUESS): calls slot +0x24 of this with its argument, returns this.
static u8 *THISCALL f_499a00(u8 *self, u32 a) { vcall<void, u32>(self, 0x24, a); return self; }
PCREG(499a00, f_499a00);

// 0x499b50 (GUESS): calls slot +0x1c of this with its argument, returns this.
static u8 *THISCALL f_499b50(u8 *self, u32 a) { vcall<void, u32>(self, 0x1c, a); return self; }
PCREG(499b50, f_499b50);

// 0x499b70 (GUESS): calls slot +0x18 of this with its argument, returns this.
static u8 *THISCALL f_499b70(u8 *self, u32 a) { vcall<void, u32>(self, 0x18, a); return self; }
PCREG(499b70, f_499b70);

// 0x499b90 (GUESS): calls slot +0x14 of this with its argument, returns this.
static u8 *THISCALL f_499b90(u8 *self, u32 a) { vcall<void, u32>(self, 0x14, a); return self; }
PCREG(499b90, f_499b90);

// 0x499bb0 (GUESS): calls slot +0x20 of this with its argument, returns this.
static u8 *THISCALL f_499bb0(u8 *self, u32 a) { vcall<void, u32>(self, 0x20, a); return self; }
PCREG(499bb0, f_499bb0);

// 0x4999c0 (GUESS): calls slot +0x18 of this with (argument, 2), returns this.
static u8 *THISCALL f_4999c0(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x18, a, 2u); return self; }
PCREG(4999c0, f_4999c0);

// 0x4999e0 (GUESS): calls slot +0x18 of this with (argument, 4), returns this.
static u8 *THISCALL f_4999e0(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x18, a, 4u); return self; }
PCREG(4999e0, f_4999e0);

// 0x499a40 (GUESS): calls slot +0x18 of this with (argument, 0xc), returns this.
static u8 *THISCALL f_499a40(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x18, a, 12u); return self; }
PCREG(499a40, f_499a40);

// 0x499a60 (GUESS): calls slot +0x18 of this with (argument, 0x24), returns this.
static u8 *THISCALL f_499a60(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x18, a, 36u); return self; }
PCREG(499a60, f_499a60);

// 0x499a80 (GUESS): calls slot +0x18 of this with (argument, 8), returns this.
static u8 *THISCALL f_499a80(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x18, a, 8u); return self; }
PCREG(499a80, f_499a80);

// 0x499aa0 (GUESS): calls slot +0x18 of this with (argument, 1), returns this.
static u8 *THISCALL f_499aa0(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x18, a, 1u); return self; }
PCREG(499aa0, f_499aa0);

// 0x499bd0 (GUESS): calls slot +0x10 of this with (argument, 0xc), returns this.
static u8 *THISCALL f_499bd0(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x10, a, 12u); return self; }
PCREG(499bd0, f_499bd0);
