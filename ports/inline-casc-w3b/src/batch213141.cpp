#include "ff.h"

typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef u32(THISCALL *V6)(void *, u32, u32, u32, u32, u32, u32);

extern "C" void THISCALL ext_4db1f0(void *n, void *p);
extern "C" void THISCALL ext_4db270(void *n, void *p);
extern "C" void FASTCALL ext_43e920(void *out, void *a, void *b);
extern "C" u32 THISCALL ext_4e2800(void *out, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u32 a10, u32 a11);
extern "C" u32 THISCALL ext_4db9a0(void *n, u32 mask);
extern "C" void FASTCALL ext_443ef0(void *ecx, void *edx, void *b, u32 fbits);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32(const u8 *p) { return *(const u32 *)p; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x442420: fastcall(ecx = R (result: R[0] = best distance), edx = N (tree node), A, B, m1, m2, m3) ret 0x14 -> bool. Segment A..B (two 3-float points copied locally, transformed
// into the node's space by 0x4db1f0 / 0x4db270) against the node's box (0x4e2800: 12 float args, N[0x40..0x48] and its negation, d = A' - N[0x30], B'); on a hit nearer than
// R[0] the node is either a group (flag 0x100000 in [[N[0x54]+0xc]+0x23], default 0x200002), in which case the children N[0x50] -> N[0x60] -> ... are tested recursively when
// their flags allow it, or a leaf where the owner slot 0x27c (when it is of kind 0x200006) or the engine object slot 0x64 decides; R[0x3c / 0x44 / 0x10] describe the hit.
extern "C" u32 FASTCALL fn_442420(u8 *R, u8 *N, u32 A, u32 B, u32 m1, u32 m2, u32 m3);
static u32 FASTCALL body_442420(u8 *R, u8 *N, u32 A, u32 B, u32 m1, u32 m2, u32 m3) {
  u32 a[3], b[3];
  const u32 *pa = (const u32 *)A;
  const u32 *pb = (const u32 *)B;
  a[0] = pa[0]; a[1] = pa[1]; a[2] = pa[2];
  b[0] = pb[0]; b[1] = pb[1]; b[2] = pb[2];
  ext_4db1f0(N, a);
  ext_4db270(N, b);
  u32 d[3];
  ext_43e920(d, a, N + 0x30);
  u32 n40 = rd32(N + 0x40), n44 = rd32(N + 0x44), n48 = rd32(N + 0x48);
  u32 mask = G(u32, 0x67af40);
  float t;
  u32 ok = ext_4e2800(&t, n40 ^ mask, n44 ^ mask, n48 ^ mask, n40, n44, n48, d[0], d[1], d[2], b[0], b[1], b[2]);
  if ((u8)ok == 0) return 0;
  if (!(*(float *)R > t)) return 0;
  u8 *edx = (u8 *)rd32(N + 0x54);
  u32 flags = edx ? rd32((u8 *)rd32(edx + 0xc) + 0x23) : 0x200002;
  if (flags & 0x100000) {
    u8 acc = 0;
    u8 *c = (u8 *)rd32(edx + 0x50);
    while (c != 0) {
      u32 f = rd32(c + 0x3c);
      if ((f & 0xc00) == 0 && (u8)f != 0) acc |= (u8)fn_442420(R, c, A, B, m1, m2, m3);
      c = (u8 *)rd32(c + 0x60);
    }
    return acc;
  }
  if ((rd32(N + 0x3c) & m1) == 0) return 0;
  if ((m2 & (edx ? rd32((u8 *)rd32(edx + 0xc) + 0x23) : 0x200002)) == 0) return 0;
  if ((u8)ext_4db9a0(N, 0x200006) != 0) {
    u8 *X = (u8 *)rd32(N + 0x54);
    u32 r = (*(V3 *)(vt(X) + 0x27c))(X, (u32)R, (u32)a, (u32)b);
    if (r == 0) return 0;
    *(u32 *)(R + 0x3c) = r;
    ext_443ef0(R + 4, a, b, rd32(R));
    *(u32 *)(R + 0x44) = rd32(N + 0x6c);
    *(u8 **)(R + 0x10) = N;
    return 1;
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *O = (u8 *)rd32((u8 *)rd32(eng + 0x1aa3) + 0x1c);
  u8 ok2 = (u8)(*(V6 *)(vt(O) + 0x64))(O, (u32)R, (u32)N, (u32)a, (u32)b, m3, m1);
  if (!ok2) return 0;
  *(u32 *)(R + 0x44) = rd32(N + 0x6c);
  *(u8 **)(R + 0x10) = N;
  return 1;
}
extern "C" u32 FASTCALL fn_442420(u8 *R, u8 *N, u32 A, u32 B, u32 m1, u32 m2, u32 m3) {
  u32 r = body_442420(R, N, A, B, m1, m2, m3);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(442420, fn_442420);
