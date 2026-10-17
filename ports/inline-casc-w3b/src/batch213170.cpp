#include "ff.h"

extern "C" void THISCALL ext_4690b0(void *self);
extern "C" void FASTCALL ext_441970(void *out, void *in, void *mat);
extern "C" void FASTCALL ext_441940(void *a, void *b);
extern "C" void FASTCALL ext_43e960(void *a, void *b);
extern "C" void FASTCALL ext_4de420(void *dst, void *src);
extern "C" void FASTCALL ext_4e2d60(void *m);
extern "C" void FASTCALL ext_4de520(void *m1, void *m2, void *ptr, float t);
extern "C" void THISCALL ext_4eb020(void *self, void *m, void *v1, void *v2);
extern "C" void THISCALL ext_4ea300(void *self, u32 a);
extern "C" u32 THISCALL ext_4db2f0(void *self, u32 a);
extern "C" void FASTCALL ext_4e0a10(void *v);
extern "C" void FASTCALL ext_4deb20(void *out, u32 dummy, float ang, float x, float y, float z);
extern "C" void FASTCALL ext_4de480(void *a, void *b);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

#define EBP (fr + 0xc938)
#define P(off) (EBP - (off))

// 0x4748b0: thiscall(proj) ret 4, /GS (51 KB frame, __chkstk), void. Casts a swept ray for the projectile object proj from its last point (proj slot 0x2c4 gives the start / matrix) along its
// movement: the matrix is permuted (rows 2, 0, 1) and normalised (0x4e2d60), the query object is allocated by the engine (engine slot 0x48 of [[eng+0x1aa3]+0x1c]), filled (0x4eb020) with the
// interpolated segment at fraction t (0x4de520) and run (0x4ea300); t grows by [0x67a284] until a hit is stored at query+8 or t exceeds 1.0. The query is released (slot 0x4c), the hit point is placed at
// the last fraction, proj slots 0x2f0 / 0x7c / 0x2e8 / 0x318 update it and the effect entity proj slot 0x10c(0x689880, 1) gets three 0x5c messages (names via engine table slot 0x114) with a random
// rotation (0x4e0a10 -> 0x4deb20, angle 5.0) combined into the matrix handed over.
static void body_4748b0(u8 *ebx, u8 *edi) {
  u8 fr[0xc940];
  { void *d = fr; u32 n = sizeof fr; asm volatile("rep stosb" : "+D"(d), "+c"(n) : "a"(0xcc) : "memory"); }
  vcall<u32>(edi, 0x2d0, 0u, 0u);
  ext_4690b0((u8 *)R32(edi + 8));
  vcall<u32>(edi, 0x2c4, (u32)P(0xc87c), (u32)P(0xc81c));
  ext_441970(P(0xc810), (u8 *)R32(edi + 8) + 0x30, P(0xc87c));
  ext_441940(P(0xc81c), P(0xc810));
  vcall<u32>(ebx, 0x384, (u32)P(0xc840), (u32)P(0xc810));
  {
    float m[9];
    for (int i = 0; i < 9; i++) m[i] = RF(P(0xc840) + 4 * i);
    // rows (r0 r1 r2) -> (r2 r0 r1), stored at -0xc840 / -0xc834 / -0xc828
    WF(P(0xc834), m[0]);
    WF(P(0xc830), m[1]);
    WF(P(0xc82c), m[2]);
    WF(P(0xc828), m[3]);
    WF(P(0xc824), m[4]);
    WF(P(0xc820), m[5]);
    WF(P(0xc840), m[6]);
    WF(P(0xc83c), m[7]);
    WF(P(0xc838), m[8]);
  }
  ext_4e2d60(P(0xc840));
  ext_4de420(P(0xc8a0), P(0xc840));
  W32(P(0xc844), R32(P(0xc808)));
  __builtin_memcpy(P(0xc84c), P(0xc810), 8);
  u8 *eng = G(u8 *, 0x70039c);
  WF(P(0xc930), 0.0f);
  u8 *qm = (u8 *)R32((u8 *)R32(eng + 0x1aa3) + 0x1c);
  u8 *esi = (u8 *)vcall<u32>(qm, 0x48, (u32)P(0xc804), 0xc800u);
  float t = G(float, 0x67a284);
  WF(P(0xc92c), t);
  for (;;) {
    ext_4de520(P(0xc8a0), P(0xc840), P(0xc87c), t);
    float t0 = RF(P(0xc92c));
    float x = (RF(P(0xc81c)) - RF(P(0xc810))) * t0 + RF(P(0xc810));
    WF(P(0xc84c), x);
    float y = (RF(P(0xc818)) - RF(P(0xc80c))) * t0 + RF(P(0xc80c));
    WF(P(0xc848), y);
    float z = (RF(P(0xc814)) - RF(P(0xc808))) * t0 + RF(P(0xc808));
    WF(P(0xc844), z);
    ext_4eb020(esi, P(0xc8a0), P(0xc84c), (u8 *)R32(edi + 8) + 0x40);
    ext_4ea300(esi, 1);
    if (R32(esi + 8) != 0) break;
    WF(P(0xc930), RF(P(0xc92c)));
    float nt = RF(P(0xc92c)) + G(float, 0x67a284);
    WF(P(0xc92c), nt);
    t = nt;
    if (!(G(float, 0x678858) >= nt)) break;
  }
  eng = G(u8 *, 0x70039c);
  qm = (u8 *)R32((u8 *)R32(eng + 0x1aa3) + 0x1c);
  vcall<u32>(qm, 0x4c, (u32)esi);
  float tt = RF(P(0xc930));
  ext_4de520(P(0xc87c), P(0xc840), P(0xc87c), tt);
  {
    float t2 = RF(P(0xc930));
    WF(P(0xc81c), (RF(P(0xc81c)) - RF(P(0xc810))) * t2 + RF(P(0xc810)));
    WF(P(0xc818), (RF(P(0xc818)) - RF(P(0xc80c))) * t2 + RF(P(0xc80c)));
    WF(P(0xc814), (RF(P(0xc814)) - RF(P(0xc808))) * t2 + RF(P(0xc808)));
  }
  u32 r4 = ext_4db2f0((u8 *)R32(ebx + 8), 0);
  vcall<u32>(edi, 0x2f0, 0u, r4, 1u);
  ext_441970(P(0xc810), (u8 *)R32(edi + 8) + 0x30, P(0xc87c));
  ext_43e960(P(0xc81c), P(0xc810));
  vcall<u32>(edi, 0x7c, (u32)P(0xc87c), (u32)P(0xc81c));
  u8 *o2e8 = (u8 *)vcall<u32>(edi, 0x2e8);
  W32(P(0xc934), vcall<u32>(o2e8, 0x318));
  u8 *fx = (u8 *)vcall<u32>(edi, 0x10c, 0x689880u, 1u);
  if (!fx) return;
  vcall<u32>(fx, 0x5c, 1u, 0u, 0u);
  vcall<u32>(fx, 0x5c, 2u, 0u, 0u);
  {
    u8 *esiv = fx;
    u8 *T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
    u32 w = (u16)vcall<u32>(T, 0x114, 0x682e18u, 0u, 0x68961cu, 0x6c4u);
    vcall<u32>(esiv, 0x5c, 0x20u, 0u, w);
    T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
    w = (u16)vcall<u32>(T, 0x114, 0x689894u, 0u, 0x68961cu, 0x6c5u);
    vcall<u32>(esiv, 0x5c, 0x20u, (u32)P(0xc934), w);
  }
  vcall<u32>(edi, 0x80, (u32)P(0xc928), (u32)P(0xc8e0));
  ext_4de420(P(0xc904), P(0xc928));
  ext_4e0a10(P(0xc858));
  ext_4deb20(P(0xc8c4), 0, 5.0f, RF(P(0xc858)), RF(P(0xc854)), RF(P(0xc850)));
  ext_4de480(P(0xc904), P(0xc8c4));
  WF(P(0xc8d4), RF(P(0xc8e0)));
  WF(P(0xc8d0), RF(P(0xc8dc)));
  WF(P(0xc8cc), RF(P(0xc8d8)));
  W32(P(0xc8c8), 0x3c9374bc);
  {
    u8 *T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
    u32 w = (u16)vcall<u32>(T, 0x114, 0x6898a0u, 0u, 0x68961cu, 0x6d3u);
    vcall<u32>(fx, 0x5c, 0x20u, (u32)P(0xc928), w);
  }
}
extern "C" void THISCALL fn_4748b0(u8 *self, u8 *proj);
extern "C" void THISCALL fn_4748b0(u8 *self, u8 *proj) {
  body_4748b0(self, proj);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4748b0, fn_4748b0);
