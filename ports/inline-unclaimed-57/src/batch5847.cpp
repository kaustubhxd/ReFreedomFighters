// batch5847.cpp - 0x5d42d0 (FUN_005d42d0, ZFF bomb/fuse-like frame update: a timer at this+0x5b drives a bob, a colour pulse and a detonation), thiscall, no args,
// plain ret. Engine 0x70039c: frame counters +0x40/+0x44, sub-object +0x9b, sound-ish object +0x1a9f; 0x70038c: a table object (slot +0xcc).
// Members: +0x44 owner (slots 0x80 GetMatrix(m, v), 0x128, 0x20, 0x210; field +8 handed to 0x4db3b0), +0x48 visual (slots 0x7c SetMatrix(m, v), 0x234 colour,
// 0x28, 0x210), +0x4e/+0x50/+0x52/+0x54 words (ids), +0x56 dword, +0x5a byte, +0x5b float timer, +0x5f object for 0x5ea840, +0x63 effect, +0x67 sound id.
// Calls: cos through the IAT (0x634d70 jumps through 0x676320), 0x5ea840 (thiscall, one float, ret 4, hooked), 0x4db3b0 (thiscall, no args, hooked).
#include "ff.h"

extern "C" void THISCALL ext_5ea840(void *o, float t);  // original code (hooked in the spec)
extern "C" void *THISCALL ext_4db3b0(void *o);          // original code (hooked in the spec)

// The {name, id} pair handed to slot 0x128 (name falls back to "<NONAME>" at 0x67c8e8).
static inline void pair_name_id(u8 *self, u32 *pair) {
  void *e = vcall<void *>(*(void **)(self + 0x44), 0x20);
  u32 nm = *(u32 *)((u8 *)e + 4);
  pair[0] = nm ? nm : 0x67c8e8u;
  pair[1] = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, *(u32 *)(self + 0x44));
}

// 0x5d42d0, thiscall, no args
static void THISCALL unnamed5d42d0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  float m[12], v[3], w[3];
  float dt = (float)(int)(*(u32 *)(eng + 0x40) - *(u32 *)(eng + 0x44)) * 0.0009765625f;  // 0x6785e4
  *(float *)(self + 0x5b) = *(float *)(self + 0x5b) + dt;
  if (*(u32 *)(self + 0x48)) {
    vcall<void>(*(void **)(self + 0x44), 0x80, m, v);
    float c = (float)crt::cos((double)*(float *)(self + 0x5b));
    v[1] = (c + 100.0f) + v[1];  // 0x67cd40
    vcall<void>(*(void **)(self + 0x48), 0x7c, m, v);
  }
  if (void *vis = *(void **)(self + 0x48)) {
    double r = crt::cos((double)(*(float *)(self + 0x5b) * 8.0f));  // 0x680a6c
    r = (r + 1.0) * 0.5 * 255.0;                                      // 0x678610, 0x68c740, 0x6b52e0
    vcall<void>(vis, 0x234, (u32)(u8)_mm_cvttsd_si32(_mm_set_sd(r)) << 16);
  }
  ext_5ea840(*(void **)(self + 0x5f), 10.0f - *(float *)(self + 0x5b));  // 0x680a70
  float t = *(float *)(self + 0x5b);
  if (_mm_cvttss_si32(_mm_set_ss(t)) != _mm_cvttss_si32(_mm_set_ss(t - dt))) {
    void *snd = *(void **)(G(u8 *, 0x70039c) + 0x1a9f);
    u32 id = *(u32 *)(self + 0x67);
    if (snd && id) vcall<void>(snd, 0x120, id, 4u);
  }
  if (*(float *)(self + 0x5b) > 10.0f) {
    void *tbl = vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x138);
    u32 key = 0;
    vcall<void>(tbl, 0x88, 0x6b52ccu, &key);  // "rFF_C4_BombDmgList"
    u32 dmg = vcall<u32>(G(void *, 0x70038c), 0xcc, key);
    u32 pr[2] = {0, dmg};
    vcall<void>(*(void **)(self + 0x44), 0x128, (u32) * (u16 *)(self + 0x4e), pr, 0u);
    if (*(u32 *)(self + 0x63)) {
      void *bone = ext_4db3b0(*(void **)(*(u8 **)(self + 0x44) + 8));
      vcall<void>(*(void **)(self + 0x44), 0x80, m, w);
      vcall<void>(bone, 0x94, m, w);
      void *fx = vcall<void *>(*(void **)(self + 0x63), 0x1bc, bone, m, w, 0u, 0u, 0u, 0u);
      *(void **)(self + 0x63) = fx;
      vcall<void>(fx, 0x2c);
      vcall<void>(*(void **)(self + 0x63), 0x138, (u32) * (u16 *)(self + 0x52), dmg, 0u);
      vcall<void>(*(void **)(self + 0x48), 0x28);
    }
    if (u32 s = *(u32 *)(self + 0x56)) {
      if (void *vis = *(void **)(self + 0x48)) vcall<void>(vis, 0x210, 1u);
      *(u32 *)(self + 0x48) = 0;
      void *o = vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x58, s);
      u32 pn[2];
      pair_name_id(self, pn);
      vcall<void>(o, 0x128, (u32) * (u16 *)(self + 0x50), pn, 0u);
    }
    vcall<void>(self, 0x68, 0x10u, 0u);
    if (void *own = *(void **)(self + 0x44)) vcall<void>(own, 0x210, 1u);
    return;
  }
  if (*(u8 *)(self + 0x5a)) {
    if (u32 s = *(u32 *)(self + 0x56)) {
      *(u8 *)(self + 0x5a) = 0;
      void *o = vcall<void *>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x58, s);
      u32 pn[2];
      pair_name_id(self, pn);
      vcall<void>(o, 0x128, (u32) * (u16 *)(self + 0x54), pn, 0u);
    }
  }
}
PCREG(5d42d0, unnamed5d42d0);
