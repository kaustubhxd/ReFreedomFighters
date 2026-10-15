// batch349.cpp - residue-15 (docs/20-unclaimed-76.md): 0x46d070 (thiscall, one argument obj, ret 4; GUESS). A serializer over the object:
// 0x46cee0(this, obj); then on obj: 0x4e11e0(this+0x98, 1), 0x4e11e0(this+0x9c, 1), 0x4e0fd0([this+0xa0]), 0x4e1600() (returns al; if al == 3:
// 0x4e11e0(this+0xa4, 1)), 0x4e12f0 for this+0xa8, 0xac, 0xb0, 0xb4, 0xb8, 0xbc, 0xc0 (each with 1), 0x4e14a0 for this+0xc4, 0xc5, 0xc6,
// 0x4e0fd0([this+0xc7]), 0x4e12e0(this+0xcb, 1), 0x4e11e0(this+0xcf, 1), 0x4e11e0(this+0xd3, 1), 0x4e12e0(this+0xd7, 1), 0x4e1b30().
// Then *(this+0xc0) = K / *(this+0xc0) (K = [0x67885c]); this+0xa8, this+0xb0, this+0xb4 are multiplied by [0x67cd40].
// Helpers are exe code; the fixture hooks them by address (recorded).
#include "ff.h"

extern "C" void THISCALL ext_46cee0(u8 *self, u32 obj);
extern "C" void THISCALL ext_4e11e0(u8 *self, u32 ptr, u32 flag);
extern "C" void THISCALL ext_4e12f0(u8 *self, u32 ptr, u32 flag);
extern "C" void THISCALL ext_4e12e0(u8 *self, u32 ptr, u32 flag);
extern "C" void THISCALL ext_4e14a0(u8 *self, u32 ptr, u32 flag);
extern "C" void THISCALL ext_4e0fd0(u8 *self, u32 value);
extern "C" u8 THISCALL ext_4e1600(u8 *self);
extern "C" void THISCALL ext_4e1b30(u8 *self);

static void THISCALL serialize_46d070(u8 *self, u32 obj) {
    u8 *arg = (u8 *)obj;
    u8 *t = self;
    ext_46cee0(self, obj);
    ext_4e11e0(arg, (u32)(t + 0x98u), 1u);
    ext_4e11e0(arg, (u32)(t + 0x9cu), 1u);
    ext_4e0fd0(arg, *(u32 *)(t + 0xa0u));
    if (ext_4e1600(arg) == 3u) ext_4e11e0(arg, (u32)(t + 0xa4u), 1u);
    ext_4e12f0(arg, (u32)(t + 0xa8u), 1u);
    ext_4e12f0(arg, (u32)(t + 0xacu), 1u);
    ext_4e12f0(arg, (u32)(t + 0xb0u), 1u);
    ext_4e12f0(arg, (u32)(t + 0xb4u), 1u);
    ext_4e12f0(arg, (u32)(t + 0xb8u), 1u);
    ext_4e12f0(arg, (u32)(t + 0xbcu), 1u);
    ext_4e12f0(arg, (u32)(t + 0xc0u), 1u);
    ext_4e14a0(arg, (u32)(t + 0xc4u), 1u);
    ext_4e14a0(arg, (u32)(t + 0xc5u), 1u);
    ext_4e14a0(arg, (u32)(t + 0xc6u), 1u);
    ext_4e0fd0(arg, *(u32 *)(t + 0xc7u));
    ext_4e12e0(arg, (u32)(t + 0xcbu), 1u);
    ext_4e11e0(arg, (u32)(t + 0xcfu), 1u);
    ext_4e11e0(arg, (u32)(t + 0xd3u), 1u);
    ext_4e12e0(arg, (u32)(t + 0xd7u), 1u);
    ext_4e1b30(arg);
    float *pc0 = (float *)(t + 0xc0u);
    *pc0 = G(float, 0x67885cu) / *pc0;
    float k = G(float, 0x67cd40u);
    *(float *)(t + 0xa8u) = *(float *)(t + 0xa8u) * k;
    *(float *)(t + 0xb0u) = *(float *)(t + 0xb0u) * k;
    *(float *)(t + 0xb4u) = *(float *)(t + 0xb4u) * k;
}
PCREG(46d070, serialize_46d070);
