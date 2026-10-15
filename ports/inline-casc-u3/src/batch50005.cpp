// batch50005.cpp - cascade u3, tier H, batch 50005: 0x56b030 (recentre a 640x448-based overlay for the current screen size).
#include "ff.h"

extern "C" void THISCALL ext_4db500(u8 *self, u8 *v);   // ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);        // /GS check

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wf(u8 *p, float f) { u32 v = fbits(f); p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static u8 *sysobj() { return G(u8 *, 0x70039c); }
static u8 *tab() { return (u8 *)rd32(sysobj() + 0x9b); }

// 0x56b030, thiscall() void, /GS: tab = unaligned pointer [sys+0x9b]; tab slot 0xb4(0); optional object [sys+0x1a9f] (unaligned) slot 0x138(0); R = tab slot 0x138(); local = 0; R slot 0x88(0x6a78dc, &local);
// S = tab slot 0x58(local); screen w = [sys+0x6f], h = [sys+0x73] (unaligned ints); S slot 0x70(&{(float)((w - 0x280) / 2), (float)((h - 0x1c0) / 2), 0}); S slot 0x288([this+0x44], 0, 1);
// r = [this+0x44] slot 0x25c(0x6a6acc, 0); (x, y) = (F 0x681dcc, F 0x6a7900), r != 0: ext_4db500([r+8], &{x, y, 0}) rewrites them; x += 0x67da1c; y = F 0x6a688c - y - F 0x681dc8 - 0x67da1c;
// unaligned float stores [this+0x51] = ((float)((w - 0x280) / 2) + x) / (float)w, [this+0x55] = ((float)((h - 0x1c0) / 2) + y) / (float)h, [this+0x59] = F 0x6a6ad8 / (float)w, [this+0x5d] = F 0x681dc8 / (float)h.
static void THISCALL fn56b030(u8 *self) {
  vcall<void>(tab(), 0xb4, 0);
  u8 *o = (u8 *)rd32(sysobj() + 0x1a9f);
  if (o) vcall<void>(o, 0x138, 0);
  u8 *R = vcall<u8 *>(tab(), 0x138);
  u32 local = 0;
  vcall<void>(R, 0x88, 0x6a78dc, (u32)&local);
  u8 *S = vcall<u8 *>(tab(), 0x58, local);
  s32 w = (s32)rd32(sysobj() + 0x6f);
  s32 h = (s32)rd32(sysobj() + 0x73);
  float vec[3];
  vec[0] = (float)((w - 0x280) / 2);
  vec[1] = (float)((h - 0x1c0) / 2);
  vec[2] = bitsf(0);
  vcall<void>(S, 0x70, (u32)vec);
  vcall<void>(S, 0x288, *(u32 *)(self + 0x44), 0, 1);
  u8 *r = vcall<u8 *>(*(u8 **)(self + 0x44), 0x25c, 0x6a6acc, 0);
  float v[3];
  v[0] = G(float, 0x681dcc);
  v[1] = G(float, 0x6a7900);
  v[2] = bitsf(0);
  if (r) ext_4db500(*(u8 **)(r + 8), (u8 *)v);
  float x = v[0];
  float y = v[1];
  float k4 = G(float, 0x681dc8);
  float y2 = G(float, 0x6a688c) - y;
  x = x + G(float, 0x67da1c);
  y2 = y2 - k4;
  y2 = y2 - G(float, 0x67da1c);
  w = (s32)rd32(sysobj() + 0x6f);
  wf(self + 0x51, ((float)((w - 0x280) / 2) + x) / (float)w);
  h = (s32)rd32(sysobj() + 0x73);
  wf(self + 0x55, ((float)((h - 0x1c0) / 2) + y2) / (float)h);
  w = (s32)rd32(sysobj() + 0x6f);
  wf(self + 0x59, G(float, 0x6a6ad8) / (float)w);
  h = (s32)rd32(sysobj() + 0x73);
  wf(self + 0x5d, k4 / (float)h);
  ext_633654(0);
}
PCREG(56b030, fn56b030);
