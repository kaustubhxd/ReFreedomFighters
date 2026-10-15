// batch32142.cpp - cascade h2 (Sonnet): two tier H (float / SSE) functions.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
typedef u32 (*hook_t)();

extern "C" void FASTCALL ext_633654(u32 cookie);                             // /GS check
extern "C" void THISCALL ext_4db7c0(u8 *self, float *out);                   // thiscall ret 4: out[0..2] = this[0x40..0x48]
extern "C" void FASTCALL ext_451890(u8 *a, u8 *b, float x);                  // ecx = a, edx = b, stack float, ret 4
extern "C" u32 THISCALL ext_6107e0(u8 *self, float *m);                      // thiscall ret 4

// 0x5b9050, thiscall(arg) ret 4 (/GS frame): c = [this+0x4c] != 0: slot 0x4c of c with (&it[3]); e = slot 0x5c of [this+0x4c] with (&it); while it[0] != 0: s = slot 0x58 of [[0x70039c]+0x9b] with e; slot 0x78 of s with arg;
// 0x4db7c0([s+8], &v[3]); 0x451890(ecx = arg, edx = this+0xa2, float v[2] * -2.0f); e = slot 0x5c of [this+0x4c] with (&it).
static void THISCALL fn5b9050(u8 *self, u8 *arg) {
  void *c = *(void **)(self + 0x4c);
  if (c) {
    u32 it[3];
    vcall<void>(c, 0x4c, (u32)it);
    u32 e = vcall<u32>(*(void **)(self + 0x4c), 0x5c, (u32)it);
    if (it[0] != 0) {
      do {
        u8 *s = vcall<u8 *>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x58, e);
        vcall<void>(s, 0x78, (u32)arg);
        float v[3];
        ext_4db7c0(*(u8 **)(s + 8), v);
        float x = v[2] * -2.0f;
        ext_451890(arg, self + 0xa2, x);
        e = vcall<u32>(*(void **)(self + 0x4c), 0x5c, (u32)it);
      } while (it[0] != 0);
    }
  }
  ext_633654(0);
}
PCREG(5b9050, fn5b9050);

// 0x6106e0, thiscall(l, r, b, t, n, f, flag byte) ret 0x1c (/GS frame), returns 0x6107e0's result: flag low byte != 0 -> assert hook [0x7003b0] (int3 when null) and the 16-dword matrix stays uninitialised;
// otherwise m[0] = 2n/(r-l), m[5] = 2n/(t-b), m[8] = (l+r)/(r-l), m[9] = (b+t)/(t-b), m[10] = f/(f-n), m[11] = 1.0f, m[14] = (f * -1.0f * n)/(f-n), all other entries 0.
// Then 0x6107e0(this, &m); /GS check.
static u32 THISCALL fn6106e0(u8 *self, float l, float r, float b, float t, float n, float f, u32 flag) {
  float m[16];
  if ((u8)flag) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  } else {
    float n2 = n + n;
    float rl = r - l;
    float tb = t - b;
    float sumbt = b + t;
    float suml = l + r;
    for (int i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = n2 / rl;
    m[9] = sumbt / tb;
    m[11] = 1.0f;
    float fn = f - n;
    float k = f * bitsf(0xbf800000);
    k = k * n;
    m[5] = n2 / tb;
    m[10] = f / fn;
    m[14] = k / fn;
    m[8] = suml / rl;
  }
  u32 res = ext_6107e0(self, m);
  ext_633654(0);
  return res;
}
PCREG(6106e0, fn6106e0);
