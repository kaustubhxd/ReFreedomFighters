// batch48004.cpp - cascade tier H, batch 48004: 0x522520 (per-frame update of an actor's timed object and its draw data).
#include "ff.h"

extern "C" void THISCALL ext_5216a0(void *self);                        // plain thiscall
extern "C" void FASTCALL ext_4de040(void *out, void *src, u32 z);      // fastcall, 1 stack arg: fills a 9-dword block from src
extern "C" void THISCALL ext_4dcb90(void *self, void *p);               // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                        // /GS check

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float ldf(u8 *p) { return bitsf(rd32(p)); }
static inline u8 *mgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x522520, thiscall, no args, /GS check. (Unaligned fields: +0x26fa timer object id, +0x26fe and +0x2702 float timers, +0x26ee/+0x26f2/+0x26f6 ids, +0x25d1 pointer.)
// [this+0x2610] -> this->slot0x308(this+0x25fd, it); ext_5216a0(this); e = this+0x263c, e->slot8(this+0x2624);
// when id = [+0x26fa]: o = mgr->slot0x60(id): [o+0x84] = min(c0x678858, (float)(this+0x2664 slot0x18() + c0x67a288)).
// when e->slot0xc(): [+0x26fe] += [sys+0x20]; e->slot4(this+0x2624, this+0x2630); when [+0x26fe] > c0x67c194 and [+0x26fa]: this->slot0x2ec(id), this->slot0x2e8([+0x26f2]), [+0x26fa] = 0; [+0x2702] = 0.
// otherwise: when [+0x26fa] == 0: [+0x2702] += [sys+0x20] and when that is > c0x67c194: f = mgr->slot0x60(this->slot0x2e8([+0x26ee]))[+0x70] (0 when missing); [+0x26fa] = this->slot0x2e8([+0x26f6]),
// o = mgr->slot0x60(that) -> [o+0x78] = f * c0x67d164 * c0x684ce4 * c0x67d9fc; then [+0x26fe] = 0 (also when [+0x26fa] was set). Finally ext_4de040(&v, this+0x2624, 0), ext_4dcb90([[+0x25d1]+8], &v).
static void THISCALL fn522520(u8 *self) {
  u32 v28[9];
  u32 a = rd32(self + 0x2610);
  if (a) vcall<void>(self, 0x308, (u32)(self + 0x25fd), a);
  ext_5216a0(self);
  u8 *e = self + 0x263c;
  u8 *b = self + 0x2624;
  vcall<void>(e, 8, (u32)b);
  u32 id = rd32(self + 0x26fa);
  if (id) {
    u8 *o = vcall<u8 *>(mgr(), 0x60, id);
    if (o) {
      float f = vcall<float>(self + 0x2664, 0x18);
      float x = (float)((long double)f + (long double)G(float, 0x67a288));
      float c = G(float, 0x678858);
      wr32(o + 0x84, fbits(c < x ? c : x));
    }
  }
  if (vcall<u8>(e, 0xc)) {
    float t = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss(ldf(G(u8 *, 0x70039c) + 0x20)), _mm_set_ss(ldf(self + 0x26fe))));
    wr32(self + 0x26fe, fbits(t));
    vcall<void>(e, 4, (u32)b, (u32)(self + 0x2630));
    if (ldf(self + 0x26fe) > G(float, 0x67c194)) {
      u32 cur = rd32(self + 0x26fa);
      if (cur) {
        vcall<void>(self, 0x2ec, cur);
        vcall<void>(self, 0x2e8, rd32(self + 0x26f2));
        wr32(self + 0x26fa, 0);
      }
    }
    wr32(self + 0x2702, 0);
  } else {
    float f = 0.0f;
    bool zero_it = true;
    if (rd32(self + 0x26fa) == 0) {
      float t = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss(ldf(G(u8 *, 0x70039c) + 0x20)), _mm_set_ss(ldf(self + 0x2702))));
      wr32(self + 0x2702, fbits(t));
      if (t > G(float, 0x67c194)) {
        u32 r1 = vcall<u32>(self, 0x2e8, rd32(self + 0x26ee));
        u8 *o1 = vcall<u8 *>(mgr(), 0x60, r1);
        if (o1) f = ldf(o1 + 0x70);
        u32 n = vcall<u32>(self, 0x2e8, rd32(self + 0x26f6));
        wr32(self + 0x26fa, n);
        u8 *o2 = vcall<u8 *>(mgr(), 0x60, n);
        if (o2) {
          float p = f * G(float, 0x67d164);
          p = p * G(float, 0x684ce4);
          p = p * G(float, 0x67d9fc);
          wr32(o2 + 0x78, fbits(p));
        }
      }
    }
    (void)zero_it;
    wr32(self + 0x26fe, 0);
  }
  ext_4de040(v28, b, 0);
  u8 *q = (u8 *)rd32(self + 0x25d1);
  ext_4dcb90(*(u8 **)(q + 8), v28);
  ext_633654(0);
}
PCREG(522520, fn522520);
