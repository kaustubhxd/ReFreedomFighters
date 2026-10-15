// batch49004.cpp - cascade u2 batch 49004: 0x527d10 (camera/view update: set the pose from the arguments, then run the update steps).
#include "ff.h"

typedef float __attribute__((aligned(1))) uf;
typedef u32 __attribute__((aligned(1))) uu;
#define FL(p, o) (*(uf *)((u8 *)(p) + (o)))
#define U32(p, o) (*(uu *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_527bd0(u8 *self);
extern "C" void THISCALL ext_529660(u8 *self);
extern "C" void THISCALL ext_5279f0(u8 *self);
extern "C" void THISCALL ext_529130(u8 *self);
extern "C" void THISCALL ext_529450(u8 *self);
extern "C" void THISCALL ext_529020(u8 *self);
extern "C" void THISCALL ext_528b60(u8 *self);
extern "C" void THISCALL ext_528ae0(u8 *self);
extern "C" void THISCALL ext_5292c0(u8 *self);
extern "C" void THISCALL ext_5295d0(u8 *self);
extern "C" void FASTCALL ext_4de420(u8 *dst, u8 *src);                   // 36-byte copy
extern "C" float FASTCALL ext_4e0030(u8 *p58, u8 *p4c);                  // float in st0
extern "C" void FASTCALL ext_446ee0(float *out, u8 *p58, u8 *p4c);       // ret 4

typedef void(THISCALL *v2_t)(void *, void *, void *);

static inline void cp3(u8 *d, const u8 *s) {
  U32(d, 0) = U32(s, 0);
  U32(d, 4) = U32(s, 4);
  U32(d, 8) = U32(s, 8);
}

// 0x527d10, thiscall(a, b, c, d, e, f, g) ret 0x1c.
static void THISCALL fn527d10(u8 *self, u8 *a, u8 *b, u8 *c, u8 *d, float e, float f, float g) {
  if (self[0x84] == 0) return;
  if (self[0x21cd] != 0) {
    u8 *eng = G(u8 *, 0x70039c);
    if (*(s32 *)(eng + 0x40) < (s32)U32(self, 0x85)) {
      ext_527bd0(self);
      ext_529660(self);
      void *o = (void *)U32(self, 0x89);
      (*(v2_t **)o)[0x7c / 4](o, self + 0xc, self);
      ext_5279f0(self);
      ext_4de420(a, self + 0xc);
      cp3(b, self);
      return;
    }
    void *o = (void *)U32(self, 0x89);
    (*(v2_t **)o)[0x80 / 4](o, a, b);
    return;
  }
  cp3(self, c);
  FL(self, 0x64) = FL(c, 4) + G(float, 0x680a84);
  u8 *p58 = self + 0x58;
  u8 *p4c = self + 0x4c;
  cp3(p58, p4c);
  cp3(p4c, d);
  U32(self, 0x50) = 0;
  FL(self, 0x68) = e;
  FL(self, 0x6c) = f;
  FL(self, 0x78) = g;
  FL(self, 0x70) = ext_4e0030(p58, p4c);
  float out[4];
  ext_446ee0(out, p58, p4c);
  if (0.0f > out[1]) U32(self, 0x70) = U32(self, 0x70) ^ G(u32, 0x67af40);
  FL(self, 0x74) = FL(self, 0x70) / FL(G(u8 *, 0x70039c), 0x48);
  ext_529130(self);
  ext_529450(self);
  ext_529020(self);
  ext_527bd0(self);
  ext_529660(self);
  ext_528b60(self);
  ext_528ae0(self);
  ext_5292c0(self);
  ext_5295d0(self);
  ext_5279f0(self);
  ext_4de420(a, self + 0xc);
  cp3(b, self);
}
PCREG(527d10, fn527d10);
