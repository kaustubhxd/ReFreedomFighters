#include "ff.h"

extern "C" float FASTCALL ext_4e0870(void *a, void *b);
extern "C" u32 THISCALL ext_478a80(void *self);
extern "C" u32 THISCALL ext_466f60(void *self, u32 a);
extern "C" u32 ext_633910(void);
extern "C" long double ext_634dca(double x);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

#define EBP (fr + 0x68)
#define P(off) (EBP - (off))

// 0x47ce80: thiscall() plain ret, /GS, void. Pickup / spark effect updater for the target id this[0x492]: the table object's slot 0x80 / this slot 0x94 give a vector whose length
// to this[8]+0x24 must be below [0x686098]; with the engine object [0x1a9f] present and this[0x64c] == 3 the active entry (this slot 0x5a8, helper 0x478a80) supplies a frame
// span (+0x60 / +0x64); the ratio of this[0x755] and the cell this[0x77b] (floor thunk 0x634dca on doubles, mode this slot 0x5b0 == 2 changes the limits) decides whether
// a new effect entity is created through 0x466f60 (when this[0x157] and this[0x5c2] are set and the two floors differ) or fetched with this slot 0x3f8(1 / 0); the entity (table slot 0x60)
// gets a random age (engine slot 0x1c0 with the x87 control word: sub / mul in 53-bit double precision) and a random strength (CRT rand scaled by this[0x777] / 100).
static void body_47ce80(u8 *edi) {
  u8 fr[0x70];
  __builtin_memset(fr, 0xcc, sizeof fr);
  u32 id = R32(edi + 0x492);
  if (id == 0) return;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *T = (u8 *)R32(eng + 0x9b);
  u8 *O = vcall<u8 *>(T, 0x58, id);
  W32(P(8), 0);
  W32(P(0xc), 0);
  W32(P(0x10), 0);
  vcall<u32>(O, 0x80, (u32)P(0x34), (u32)P(0x10));
  vcall<u32>(edi, 0x94, (u32)P(0x34), (u32)P(0x10));
  float d = ext_4e0870(P(0x10), (u8 *)R32(edi + 8) + 0x24);
  WF(P(0x44), d);
  if (!(G(float, 0x686098) > RF(P(0x44)))) return;
  eng = G(u8 *, 0x70039c);
  if (R32(eng + 0x1a9f) == 0) return;
  if (R32(edi + 0x64c) != 3) return;
  u8 *ent = (u8 *)vcall<u32>(edi, 0x5a8, R32(edi + 0x650));
  if (!ent) return;
  u8 *esi = (u8 *)ext_478a80(ent);
  WF(P(0x40), G(float, 0x681dc8));
  WF(P(0x50), G(float, 0x67da20));
  u32 k = vcall<u32>(edi, 0x5b0);
  float c44 = G(float, 0x68af04);
  WF(P(0x44), c44);
  if (k == 2) {
    WF(P(0x40), G(float, 0x685280));
    WF(P(0x50), c44);
  }
  float span = (float)(s32)R32(esi + 0x64);
  float lo = (float)(s32)R32(esi + 0x60);
  float one = G(float, 0x678858);
  span = span + one;
  span = span - lo;
  float xm = RF(edi + 0x755);
  float inv = one / span;
  xm = xm * span;
  WF(P(0x38), inv);
  WF(P(0x3c), xm);
  float a = RF(edi + 0x77b) - RF(P(0x40));
  a = a * inv;
  long double t1 = ext_634dca((double)a);
  float b = RF(P(0x3c)) - RF(P(0x40));
  WF(P(0x68), (float)t1);
  b = b * RF(P(0x38));
  long double t2 = ext_634dca((double)b);
  float cc = RF(edi + 0x77b) - RF(P(0x50));
  WF(P(0x40), (float)t2);
  cc = cc * RF(P(0x38));
  long double t3 = ext_634dca((double)cc);
  float dd = RF(P(0x3c)) - RF(P(0x50));
  WF(P(0x6c), (float)t3);
  dd = dd * RF(P(0x38));
  long double t4 = ext_634dca((double)dd);
  u32 res = 0;
  WF(P(0x48), (float)t4);
  if (edi[0x157] != 0) {
    u32 k2 = vcall<u32>(edi, 0x5b0);
    if (k2 == 2) WF(P(0x44), G(float, 0x680a70));
    float e = RF(edi + 0x77b) - RF(P(0x44));
    e = e * RF(P(0x38));
    long double t5 = ext_634dca((double)e);
    u32 ebx = R32(edi + 0x5c2);
    WF(P(0x50), (float)t5);
    if (ebx != 0) {
      float f = RF(edi + 0x77b);
      f = f * RF(P(0x38));
      double t6 = (double)ext_634dca((double)f);
      float g = RF(P(0x3c)) * RF(P(0x38));
      double t7 = (double)ext_634dca((double)g);
      float x7 = (float)t7, x6 = (float)t6;
      bool different = !(x6 == x7);
      if (!different) {
        float h = RF(P(0x3c)) - RF(P(0x44));
        h = h * RF(P(0x38));
        double t8 = (double)ext_634dca((double)h);
        float x8 = (float)t8;
        different = !(RF(P(0x50)) == x8);
      }
      if (different) {
        u8 *eng2 = G(u8 *, 0x70039c);
        u8 *TT = (u8 *)R32(eng2 + 0x1a9f);
        u32 obj = vcall<u32>(TT, 0x60, ebx, 0x68abfcu);
        res = ext_466f60(edi, obj);
      }
    }
  }
  if (!(RF(P(0x68)) == RF(P(0x40)))) {
    res = vcall<u32>(edi, 0x3f8, 1u);
  } else if (!(RF(P(0x6c)) == RF(P(0x48)))) {
    res = vcall<u32>(edi, 0x3f8, 0u);
  }
  if (res != 0) {
    eng = G(u8 *, 0x70039c);
    T = (u8 *)R32(eng + 0x9b);
    u8 *node = (u8 *)vcall<u32>(T, 0x60, res);
    if (node) {
      typedef long double(THISCALL * RndFn)(void *, u32, u32);
      u8 *e1 = G(u8 *, 0x70039c);
      long double rv = (*(RndFn *)(*(u8 **)e1 + 0x1c0))(e1, 0x68a7c4, 0x934);
      rv = rv - (long double)G(float, 0x67a6ac);
      rv = rv * (long double)G(float, 0x680a84);
      WF(P(0x48), (float)rv);
      s32 iv = (s32)RF(P(0x48));
      W32(node + 0x60, (u32)(iv - (s32)R32(node + 0x64)));
      W32(node + 0x64, (u32)iv);
      u32 r = ext_633910();
      u32 ecx = R32(edi + 0x777) * r;
      u32 q = (u32)(((u64)ecx * 0x51eb851fu) >> 32) >> 5;
      u32 sum = q + r;
      double dv = (double)(s32)sum;
      dv += G(double, 0x680aa0 + 8 * (sum >> 31));
      WF(node + 0x88, (float)dv);
    }
  }
  WF(edi + 0x77b, RF(P(0x3c)));
}
extern "C" void THISCALL fn_47ce80(u8 *self);
extern "C" void THISCALL fn_47ce80(u8 *self) {
  body_47ce80(self);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(47ce80, fn_47ce80);
