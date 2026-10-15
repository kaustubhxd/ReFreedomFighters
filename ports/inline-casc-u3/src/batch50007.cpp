// batch50007.cpp - cascade u3, tier H, batch 50007: 0x56f590 (look up the panel's widgets by stored ids and set up the panel).
#include "ff.h"

extern "C" void THISCALL ext_562440(u8 *self);
extern "C" void THISCALL ext_563510(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_563610(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_56f2d0(u8 *self);

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static u8 *tab() { return (u8 *)rd32(G(u8 *, 0x70039c) + 0x9b); }
static u8 *lookup(u32 id) { return vcall<u8 *>(tab(), 0x58, id); }

// 0x56f590, thiscall() void (all fields unaligned): ext_562440(this); table = [[0x70039c]+0x9b], widget(id) = table slot 0x58(id): [this+0x5ce] = widget([+0x1a1]), [+0x5d2] = widget([+0x1a9]),
// [+0x4ba] = widget([+0x199]), [+0x4be] = widget([+0x1ad]), [+0x5da] = widget([+0x1b1]), [+0x5de] = widget([+0x1b5]), [+0x5d6] = widget([+0x1bd]), [+0x5e2] = widget([+0x1c5]);
// R = table slot 0x138(); R slot 0x60(0x6a84e0, table slot 0x4c([this+0x44], 0x10)); [+0x4b6] = 1; [+0x5ca] = widget([+0x1b9]) and its slot 0x248(0xffffff); [+0x5da] non-null: its slot 0x258(&{5.0f, 0.5f}, 0);
// [+0x184] = 200, [+0x180] = 0, word [+0x194] = 0x100; [+0x5da] slot 0xbc(0); widget([+0x1a5]) when set: slot 0x258(&{(float)[+0x184] * 0.5 (0x67a6ac) - 2.0 (0x680a60), 0.5f}, 0);
// byte [+0x196] = 0; ext_563510(this, 0x6a6850); ext_563610(this, 0x6a7704); ext_56f2d0(this).
static void THISCALL fn56f590(u8 *self) {
  ext_562440(self);
  wr32(self + 0x5ce, (u32)lookup(rd32(self + 0x1a1)));
  wr32(self + 0x5d2, (u32)lookup(rd32(self + 0x1a9)));
  wr32(self + 0x4ba, (u32)lookup(rd32(self + 0x199)));
  wr32(self + 0x4be, (u32)lookup(rd32(self + 0x1ad)));
  wr32(self + 0x5da, (u32)lookup(rd32(self + 0x1b1)));
  wr32(self + 0x5de, (u32)lookup(rd32(self + 0x1b5)));
  wr32(self + 0x5d6, (u32)lookup(rd32(self + 0x1bd)));
  wr32(self + 0x5e2, (u32)lookup(rd32(self + 0x1c5)));
  u8 *R = vcall<u8 *>(tab(), 0x138);
  u8 *t = tab();
  u32 h = vcall<u32>(t, 0x4c, rd32(self + 0x44), 0x10);
  vcall<void>(R, 0x60, 0x6a84e0, h);
  wr32(self + 0x4b6, 1);
  u8 *o = lookup(rd32(self + 0x1b9));
  wr32(self + 0x5ca, (u32)o);
  vcall<void>(o, 0x248, 0xffffff);
  float v[2];
  u8 *w = (u8 *)rd32(self + 0x5da);
  if (w) {
    v[0] = 5.0f;
    v[1] = 0.5f;
    vcall<void>(w, 0x258, (u32)v, 0);
  }
  w = (u8 *)rd32(self + 0x5da);
  wr32(self + 0x184, 0xc8);
  wr32(self + 0x180, 0);
  self[0x194] = 0;
  self[0x195] = 1;
  vcall<void>(w, 0xbc, 0);
  u8 *p = lookup(rd32(self + 0x1a5));
  if (p) {
    v[1] = 0.5f;
    v[0] = (float)(s32)rd32(self + 0x184) * G(float, 0x67a6ac) - G(float, 0x680a60);
    vcall<void>(p, 0x258, (u32)v, 0);
  }
  self[0x196] = 0;
  ext_563510(self, 0x6a6850);
  ext_563610(self, 0x6a7704);
  ext_56f2d0(self);
}
PCREG(56f590, fn56f590);
