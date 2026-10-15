// batch32139.cpp - cascade h2 (Sonnet): three tier H (float / SSE / x87) functions.
#include "ff.h"
#include <xmmintrin.h>

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

extern "C" void THISCALL ext_523520(u8 *self, u8 *p, float x, float k);   // thiscall ret 0xc
extern "C" void THISCALL ext_51db60(u8 *self);                            // thiscall, plain ret
extern "C" void THISCALL ext_51cf10(u8 *self);                            // thiscall, plain ret (tail-jumped to)
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                      // thiscall ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);                     // thiscall ret 4
extern "C" void THISCALL ext_500360(u8 *self, float a);                   // thiscall ret 4

// 0x51d000, thiscall no args: c = [this+0x5c]; this+0x24a/0x24e/0x252 (unaligned) = [c+8], [c+0xc], [c+0x10]; x = slot 0xc of c with 500.0f (callee leaves the argument on the stack, float on x87);
// 0x523520(c, this+0x256, x, 500.0f) (the pushed 500.0f is its third stack argument, ret 0xc); if [this+0x499]: o = slot 0x60 of [[0x70039c]+0x9b] with that value; if o: t = (int)trunc([[this+0x5c]+0x24] * float [this+0x4a9]) + [this+0x4a5];
// [o+0x60] = t - [o+0x64]; [o+0x64] = t. Then slot 0x58 of the table with [this+0x123]; slots 0x390, 0x374, 0x364 of this (no args); 0x51db60(this); tail jump 0x51cf10(this).
static void THISCALL fn51d000(u8 *self) {
  u8 *c = *(u8 **)(self + 0x5c);
  wr32(self + 0x24a, rd32(c + 8));
  wr32(self + 0x24e, rd32(c + 0xc));
  wr32(self + 0x252, rd32(c + 0x10));
  void *fn = *(void **)(*(u8 **)c + 0xc);
  float x;
  u8 *cc = c;
  __asm__ volatile("pushl $0x43fa0000\n\tcalll *%%ebx\n\taddl $4, %%esp" : "=t"(x), "+c"(cc) : "b"(fn) : "eax", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "memory", "cc");
  ext_523520(*(u8 **)(self + 0x5c), self + 0x256, x, 500.0f);
  u32 edx = rd32(self + 0x499);
  if (edx) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *o = vcall<u8 *>(*(void **)(eng + 0x9b), 0x60, edx);
    if (o) {
      u8 *c2 = *(u8 **)(self + 0x5c);
      float p = rdf(c2 + 0x24) * rdf(self + 0x4a9);
      s32 t = _mm_cvttss_si32(_mm_set_ss(p));
      t += (s32)rd32(self + 0x4a5);
      wr32(o + 0x60, (u32)t - rd32(o + 0x64));
      wr32(o + 0x64, (u32)t);
    }
  }
  u8 *eng2 = G(u8 *, 0x70039c);
  vcall<u32>(*(void **)(eng2 + 0x9b), 0x58, rd32(self + 0x123));
  vcall<void>(self, 0x390);
  vcall<void>(self, 0x374);
  vcall<void>(self, 0x364);
  ext_51db60(self);
  ext_51cf10(self);
}
PCREG(51d000, fn51d000);

// 0x551830, stdcall(obj, b, p) ret 0xc, returns ebx: ebx = slot 0x18 of obj with b; 0 -> return 0. edi = slot 0x4c of ebx; 0x5002f0(0x5003d0(edi, 0), [p]); 0x5002f0(0x5003d0(edi, 1), [p+4]);
// 0x500360(0x5003d0(edi, 2), float [p+8]); 0x500360(0x5003d0(edi, 3), float [p+0xc]); 0x500360(0x5003d0(edi, 4), float [p+0x10]); returns ebx.
static u32 STDCALL fn551830(u8 *obj, u32 b, u8 *p) {
  u8 *ebx = vcall<u8 *>(obj, 0x18, b);
  if (!ebx) return 0;
  u8 *edi = vcall<u8 *>(ebx, 0x4c);
  ext_5002f0((u8 *)ext_5003d0(edi, 0), rd32(p));
  ext_5002f0((u8 *)ext_5003d0(edi, 1), rd32(p + 4));
  ext_500360((u8 *)ext_5003d0(edi, 2), rdf(p + 8));
  ext_500360((u8 *)ext_5003d0(edi, 3), rdf(p + 0xc));
  ext_500360((u8 *)ext_5003d0(edi, 4), rdf(p + 0x10));
  return (u32)ebx;
}
PCREG(551830, fn551830);

// 0x462510, thiscall(flag byte) ret 4: [this+0x6c] == 0 -> return. flag != 0: slot 0x4c of it with (&iter[3]); e = slot 0x64 with (&iter); while e: x = slot 0x9c with (e) (float on x87);
// if [e+4] != 0: ([e+8])(ecx = [this+0x74], this, x, -1.0f, 0) (callee pops 16); e = slot 0x64 with (&iter). Then (always): slot 0 (scalar deleting destructor) of [this+0x6c] with 1 if it is non-null; [this+0x6c] = 0.
static void THISCALL fn462510(u8 *self, u32 flag) {
  if (!*(void **)(self + 0x6c)) return;
  if ((u8)flag) {
    u32 it[3];
    vcall<void>(*(void **)(self + 0x6c), 0x4c, (u32)it);
    u8 *e = vcall<u8 *>(*(void **)(self + 0x6c), 0x64, (u32)it);
    while (e) {
      float x = vcall<float>(*(void **)(self + 0x6c), 0x9c, (u32)e);
      if (rd32(e + 4) != 0) {
        typedef void(THISCALL * cb_t)(void *, u8 *, float, float, u32);
        (*(cb_t *)(e + 8))(*(void **)(self + 0x74), self, x, -1.0f, 0u);
      }
      e = vcall<u8 *>(*(void **)(self + 0x6c), 0x64, (u32)it);
    }
  }
  if (*(void **)(self + 0x6c)) vcall<void>(*(void **)(self + 0x6c), 0, 1u);
  *(u32 *)(self + 0x6c) = 0;
}
PCREG(462510, fn462510);
