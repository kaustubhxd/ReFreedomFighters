// batch50013.cpp - cascade u3, tier H, batch 50013: 0x520450 (describe a ray / sweep for the object-level query slot 0x130).
#include "ff.h"

extern "C" float FASTCALL ext_4e0870(u8 *v, u8 *p);            // float in st0
extern "C" void FASTCALL ext_4e2c60(u8 *m, u8 *v);
extern "C" void FASTCALL ext_4de040(u8 *out, u8 *v, u32 z);    // ret 4: builds a 3x3 (0x24 bytes) from a vector
extern "C" void FASTCALL ext_633654(u32 cookie);               // /GS check

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static float rdf(const u8 *p) { return bitsf(rd32(p)); }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x520450, thiscall(a, b, c, d) ret 0x10, /GS, void: v = (0,0,0); [this+0x2707] slot 0x84(&v); this slot 0x8c(&v); p = [this+8]; r = ext_4e0870(&v, p+0x30);
// only when [p+0x4c] + 200.0 (0x67da2c) > r: w = table slot 0x58([this+0x123]) (table = unaligned [[sys]+0x9b]); w slot 0x80(&m, &t) and this slot 0x94(&m, &t); (x, y, z) = [w+8]+0x40..; ext_4e2c60(&m, &(x, y, z));
// request struct (0x79 bytes): byte 0 = 0, +1 = w, +5 = 100.0f, +9 = (x, y + 50.0 (0x680a84), z), +0x15 = 0x4de040((a.x, 0, a.z)), +0x39 = *b, +0x45 = 0x4de040((c.x, 0, c.z)), +0x69 = *d, +0x75 = 1.0f;
// this slot 0x130([this+0x2707], word [this+0x2ce], &request).
static void THISCALL fn520450(u8 *self, u8 *a, u8 *b, u8 *c, u8 *d) {
  float v[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>((void *)rd32(self + 0x2707), 0x84, (u32)v);
  vcall<void>(self, 0x8c, (u32)v);
  u8 *p = *(u8 **)(self + 8);
  float k = rdf(p + 0x4c);
  float r = ext_4e0870((u8 *)v, p + 0x30);
  if (k + G(float, 0x67da2c) > r) {
    u8 *sys = G(u8 *, 0x70039c);
    u8 *tab = (u8 *)rd32(sys + 0x9b);
    u8 *w = vcall<u8 *>(tab, 0x58, rd32(self + 0x123));
    u32 m[9];
    u32 t[3];
    vcall<void>(w, 0x80, (u32)m, (u32)t);
    vcall<void>(self, 0x94, (u32)m, (u32)t);
    u8 *wp = *(u8 **)(w + 8);
    u32 l[3] = {rd32(wp + 0x40), rd32(wp + 0x44), rd32(wp + 0x48)};
    ext_4e2c60((u8 *)m, (u8 *)l);
    u8 st[0x79];
    float y = bitsf(l[1]) + G(float, 0x680a84);
    wr32(st + 9, l[0]);
    wr32(st + 0x11, l[2]);
    wr32(st + 0xd, fbits(y));
    st[0] = 0;
    wr32(st + 0x75, 0x3f800000);
    wr32(st + 1, (u32)w);
    wr32(st + 5, 0x42c80000);
    t[0] = rd32(a);
    t[2] = rd32(a + 8);
    t[1] = 0;
    ext_4de040(st + 0x15, (u8 *)t, 0);
    t[1] = 0;
    t[0] = rd32(c);
    t[2] = rd32(c + 8);
    ext_4de040(st + 0x45, (u8 *)t, 0);
    st[0] = 0;
    wr32(st + 0x39, rd32(b));
    wr32(st + 0x3d, rd32(b + 4));
    wr32(st + 0x41, rd32(b + 8));
    wr32(st + 0x69, rd32(d));
    wr32(st + 0x6d, rd32(d + 4));
    wr32(st + 0x71, rd32(d + 8));
    vcall<void>(self, 0x130, rd32(self + 0x2707), (u32)*(u16 *)(self + 0x2ce), (u32)st);
  }
  ext_633654(0);
}
PCREG(520450, fn520450);
