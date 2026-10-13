// f16b026.cpp - fresh slice 16, batch 26 (2026-10-12).
// 0x4bde40 ctor: 0x469870(this); +4 |= 0x20; +0x44 = 0; vtable 0x6937c4; clears +0x48..+0x64, b+0x68, +0x69, +0x6d, +0x71;
//           +0x75 = 2; word +0x81 = RegisterZMsg(0x685860, 0, 0x693c40, 0x833). SEH not reproduced.
// 0x4e29c0 MakeInclusivePolygon (fastcall poly, ring; n, in, m, nrm): n == 0 or m == 0 -> 0. For each edge of ring (n
//           points, wrapping): plane = vcross(nrm, ring[k] - ring[k+1]) (PSVECSubtract 0x43e920 and vcross 0x446ee0 run
//           as exe code); m = ClipFace 0x4e1c90(dst, ring[k]; plane, src, m) with dst walking down poly from poly[n-1]
//           (first src = in, then the previous dst). Stops early when m becomes 0. Returns m. Ret 0x10.
// 0x551500 Signature_fffiiiif_EventTranslator_t::handleEventTranslation(factory, id, data): t = factory slot 0x18(id); none
//           -> 0. a = t slot 0x4c(); for i = 0..7: e = 0x5003d0(a; i); floats (i = 0, 1, 2, 7) -> 0x500360(e; data[i]), ints
//           (3..6) -> 0x5002f0(e; data[i]) (each value word is pushed before i: stack-word sharing). Returns t. Ret 0xc.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469870[], ext_43e920[], ext_446ee0[], ext_4e1c90[], ext_5003d0[], ext_500360[], ext_5002f0[];

extern "C" void *THISCALL f16_4bde40(u8 *self) {
  ((void(THISCALL *)(void *))(void *)ext_469870)(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0) = 0x6937c4u;
  for (u32 o = 0x48; o <= 0x64; o += 4) AT(u32, self, o) = 0;
  AT(u8, self, 0x68) = 0;
  AT(u32, self, 0x69) = 0;
  AT(u32, self, 0x6d) = 0;
  AT(u32, self, 0x71) = 0;
  AT(u32, self, 0x75) = 2;
  AT(u16, self, 0x81) = (u16)vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x685860u, 0u, 0x693c40u, 0x833u);
  return self;
}

typedef void(FASTCALL *Vec3Op)(float *, const float *, const float *);
typedef int(FASTCALL *ClipFn)(float *, const float *, const float *, const float *, int);

extern "C" int FASTCALL f16_4e29c0(float *poly, float *ring, int n, float *in, int m, float *nrm) {
  if (!n) return 0;
  if (!m) return 0;
  volatile float d[3], pl[3];
  float *cur = ring + 3;
  float *dst = poly + (n - 1) * 3;
  ((Vec3Op)(void *)ext_43e920)((float *)d, ring, cur);
  ((Vec3Op)(void *)ext_446ee0)((float *)pl, nrm, (float *)d);
  int r = ((ClipFn)(void *)ext_4e1c90)(dst, ring, (float *)pl, in, m);
  for (int k = 1; k != n && r; k++) {
    float *nx = cur + 3;
    ((Vec3Op)(void *)ext_43e920)((float *)d, cur, k == n - 1 ? ring : nx);
    ((Vec3Op)(void *)ext_446ee0)((float *)pl, nrm, (float *)d);
    r = ((ClipFn)(void *)ext_4e1c90)(dst - 3, cur, (float *)pl, dst, r);
    dst -= 3;
    cur = nx;
  }
  return r;
}

typedef u8 *(THISCALL *Get)(void *, u32);
typedef void(THISCALL *Set)(void *, u32);

extern "C" void *THISCALL f16_551500(void *self, void *factory, u32 id, u32 *data) {
  (void)self;
  void *t = vcall<void *>(factory, 0x18, id);
  if (!t) return 0;
  void *a = vcall<void *>(t, 0x4c);
  for (u32 i = 0; i < 8; i++) {
    u8 *e = ((Get)(void *)ext_5003d0)(a, i);
    if (i < 3 || i == 7)
      ((Set)(void *)ext_500360)(e, data[i]);
    else
      ((Set)(void *)ext_5002f0)(e, data[i]);
  }
  return t;
}

PCREG(4bde40, f16_4bde40);
PCREG(4e29c0, f16_4e29c0);
PCREG(551500, f16_551500);
