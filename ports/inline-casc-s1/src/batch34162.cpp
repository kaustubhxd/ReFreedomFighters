// batch34162.cpp - cascade tier H, batch 34162: 0x484ff0 (build a vector and hand it to a slot), 0x48f7e0 (react when a value equals 2.0).
#include "ff.h"

extern "C" void THISCALL ext_443ef0(void *out, u32 p, u32 f);      // ret 8
extern "C" void THISCALL ext_494b40(void *self, u32 a);            // ret 4
extern "C" void THISCALL ext_494ac0(void *self, u32 a);            // ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                    // /GS check

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x484ff0, thiscall(a, b) ret 8, /GS: v (16 bytes on the stack) = ext_443ef0(&v, a + 0xc, -[this+0x451]) (sign flip with the mask at 0x67af40); o = this->slot0x20(); o->slot0x7c(a, &v).
static void THISCALL fn484ff0(u8 *self, u8 *a, u32 b) {
  u32 v[4];
  u32 f = rd32(self + 0x451) ^ G(u32, 0x67af40);
  ext_443ef0(v, (u32)(a + 0xc), f);
  u8 *o = vcall<u8 *>(self, 0x20);
  vcall<void>(o, 0x7c, (u32)a, (u32)v);
  ext_633654(0);
}
PCREG(484ff0, fn484ff0);

// 0x48f7e0, thiscall(p) ret 4: when the float at [this+0x10] equals the constant at 0x680a60 (2.0): ext_494b40(this, 0x68e274), p->slot0x5c(0x10, 0, 0) and ext_494ac0(this, p->slot0x14()); otherwise only p->slot0x5c(0x10, 0, 0).
static void THISCALL fn48f7e0(u8 *self, u8 *p) {
  if (*(float *)(self + 0x10) == G(float, 0x680a60)) {
    ext_494b40(self, 0x68e274);
    vcall<void>(p, 0x5c, 0x10u, 0u, 0u);
    u32 r = vcall<u32>(p, 0x14);
    ext_494ac0(self, r);
    return;
  }
  vcall<void>(p, 0x5c, 0x10u, 0u, 0u);
}
PCREG(48f7e0, fn48f7e0);
