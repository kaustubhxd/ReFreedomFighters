#include "ff.h"
// batch3528.cpp - area 35 claim 28 (docs/20-unclaimed-35.md): 0x55ef10 ZFFHeroIf::BeamToSpawnPoint(...) (residue name).
// Thiscall, one unused stack arg, ret 4. The ebp-relative locals live in FR at the same offsets (FRB is the base).
// The SSE lane-index init is T[i] = i for i < count (the constant at 0x68ecd0 is (0,1,2,3); the SSE part never writes past
// count). rand (IAT 0x67644c) and memcpy (IAT 0x67626c, VCRUNTIME140) are harness stubs; memcpy is GUESS forward copy.
// The cookie check 0x633654 is a no-op. Float: SSE single ops; x87 operations (FPCW 0x27f, 53-bit) are done in double and
// rounded to float where the exe stores a float.
// Labels are the disassembly's branch targets: L000, L117, L0b0, L0c2, L12c, L140, L150, L1dc, L243, L255, L4b2, L331, L36f,
// L47f, L4cb, L4e4, L572, L59b, Lp0, L5cb.

#define FRB 0x140
#define FRW(off) (*(u32 *)(FR + (off) + FRB))
#define FRF(off) (*(float *)(FR + (off) + FRB))
#define FRP(off) (FR + (off) + FRB)

typedef u32(THISCALL *TU0)(u8 *self);
typedef u32(THISCALL *TU1)(u8 *self, u32 a0);
typedef u32(THISCALL *TU2)(u8 *self, u32 a0, u32 a1);
typedef u32(THISCALL *TU3)(u8 *self, u32 a0, u32 a1, u32 a2);
typedef u32(THISCALL *TU4)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3);
typedef float(THISCALL *TF2)(u8 *self, u32 a0, u32 a1);
typedef u32(THISCALL *TU88)(u8 *self, u32 a0, float a1, float a2, u32 a3, u32 a4, u32 a5);
typedef void(*CDECL3)(u32 a0, u32 a1, u32 a2);

static u32 vc0(u8 *o, u32 off) { return ((TU0)*(u32 *)(*(u32 *)o + off))(o); }
static u32 vc1(u8 *o, u32 off, u32 a0) { return ((TU1)*(u32 *)(*(u32 *)o + off))(o, a0); }
static u32 vc2(u8 *o, u32 off, u32 a0, u32 a1) { return ((TU2)*(u32 *)(*(u32 *)o + off))(o, a0, a1); }
static u32 vc3(u8 *o, u32 off, u32 a0, u32 a1, u32 a2) { return ((TU3)*(u32 *)(*(u32 *)o + off))(o, a0, a1, a2); }
static u32 vc4(u8 *o, u32 off, u32 a0, u32 a1, u32 a2, u32 a3) { return ((TU4)*(u32 *)(*(u32 *)o + off))(o, a0, a1, a2, a3); }
static float vcf(u8 *o, u32 off, u32 a0, u32 a1) { return ((TF2)*(u32 *)(*(u32 *)o + off))(o, a0, a1); }
static u32 vc88(u8 *o, u32 a0, float a1, float a2, u32 a3, u32 a4, u32 a5) {
  return ((TU88)*(u32 *)(*(u32 *)o + 0x88))(o, a0, a1, a2, a3, a4, a5);
}

extern "C" u8 *THISCALL ext_5a4720(u8 *self, u32 a0);
extern "C" float FASTCALL ext_4e0830(u32 a0, u32 a1);
extern "C" void FASTCALL ext_451890(u32 a0, u32 a1, float a2);
extern "C" void THISCALL ext_55f900(u8 *self, u32 a0, u32 a1, u32 a2);

static u32 callRand(void) { return ((u32(*)(void))*(u32 *)0x67644c)(); }

// memcpy (forward byte copy; the harness's VCRUNTIME140 memcpy overlap behaviour is a GUESS).
static void copyForward(u8 *dst, u8 *src, u32 n) {
  volatile u8 *d = dst;
  for (u32 i = 0; i < n; i++)
    d[i] = src[i];
}

// 0x55ef10, ZFFHeroIf::BeamToSpawnPoint(...) (residue name).
void THISCALL beamToSpawnPoint(u8 *self, u32 unusedArg) {
  u8 FR[0x200];
  u8 *edi = self;
  u8 *B = *(u8 **)(*(u8 **)0x7003b8 + 0x2c11);
  (void)unusedArg;
  FRW(-0x20) = 0;
  FRW(-0x24) = 0;
  FRW(-0x28) = 0;
  FRW(-0xfc) = (u32)edi;
  FRW(-0x100) = (u32)B;
  u8 *O = *(u8 **)(edi + 0x18);
  vc1(O, 0x84, (u32)FRP(-0x28));
  O = *(u8 **)(edi + 0x18);
  u8 *Pp = *(u8 **)(O + 0xeee);
  if (Pp == 0)
    goto Lp0;

  FRW(-0x80) = (u32)Pp;
  FRW(-0x7c) = 0x7e967699u;
  FRW(-0xf4) = 1;
  {
    u8 *R = *(u8 **)(O + 0x54);
    u8 *Z = *(u8 **)(*(u8 **)0x7003b8 + 0x2c21);
    u8 *X0 = ext_5a4720(Z, *(u32 *)(R + 4));
    u32 r5;
    FRW(-0xe8) = (u32)X0;
    if (X0 == 0)
      goto L140;
    vc1(X0, 0x4c, (u32)FRP(-0x10));
    r5 = vc1(X0, 0x5c, (u32)FRP(-0x10));
    if (FRW(-0x10) == 0)
      goto L140;

  L000:
    {
      u8 *M = *(u8 **)(*(u8 **)0x70039c + 0x9b);
      u8 *T1 = (u8 *)vc1(M, 0x58, r5);
      u32 r16;
      float f;
      u32 n, idx;
      M = *(u8 **)(*(u8 **)0x70039c + 0x9b);
      r16 = (u16)vc4(M, 0x114, 0x6a619c, 0, 0x6a6148, 0xe1);
      vc3(T1, 0x128, r16, (u32)FRP(-0x1c), 0);
      M = *(u8 **)(*(u8 **)0x70039c + 0x9b);
      r16 = (u16)vc4(M, 0x114, 0x6a61b0, 0, 0x6a6148, 0xe2);
      vc3(T1, 0x128, r16, (u32)FRP(-0xf0), 0);
      f = ext_4e0830((u32)FRP(-0x1c), (u32)FRP(-0x28));
      FRF(-0xe8) = f;
      n = FRW(-0xf4);
      idx = 0;
      if ((s32)n <= 0)
        goto L117;
    L0b0:
      if (FRF(-0x7c + 8 * (s32)idx) > f)
        goto L0c2;
      idx++;
      if (idx < n)
        goto L0b0;
      goto L117;

    L0c2:
      {
        u32 sz = 8 * (n - idx);
        u8 *src = FRP(-0x80 + 8 * (s32)idx);
        u8 *dst = FRP(-0x78 + 8 * (s32)idx);
        copyForward(dst, src, sz);
        M = *(u8 **)(*(u8 **)0x70039c + 0x9b);
        u8 *newp = (u8 *)vc1(M, 0x58, FRW(-0xf0));
        *(u32 *)src = (u32)newp;
        n = FRW(-0xf4);
        FRF(-0x7c + 8 * (s32)idx) = f;
        FRW(-0xf4) = n + 1;
      }

    L117:
      r5 = vc1(X0, 0x5c, (u32)FRP(-0x10));
      if (FRW(-0x10) != 0)
        goto L000;
    }

  L12c:
    if (FRW(-0xf4) == 0)
      goto L5cb;
    edi = (u8 *)FRW(-0xfc);
  }

L140:
  FRW(-0xe8) = 0;
  if ((s32)FRW(-0xf4) <= 0)
    goto L4e4;

L150:
  {
    u32 k = FRW(-0xe8);
    u8 *Ek = (u8 *)FRW(-0x80 + 8 * (s32)k);
    u8 *X = *(u8 **)(Ek + 0x18);
    u32 count2 = vc0(X, 0x14);
    FRW(-0xf0) = count2;
    if ((s32)count2 > 0) {
      for (u32 i = 0; i < count2; i++)
        FRW(-0xc0 + 4 * (s32)i) = i;
    }
  }

  // L1dc
  {
    u32 count2 = FRW(-0xf0);
    u32 m = count2 - 1;
    FRW(-0xec) = m;
    FRW(-0xf8) = 0;
    if ((s32)m > 0) {
      u32 i = 0;
      u32 div = count2;
      do {
        u32 tsave = FRW(-0xc0 + 4 * (s32)i);
        u32 r = callRand();
        s32 rem = (s32)r % (s32)div;
        u32 j;
        div--;
        j = (u32)rem + i;
        FRW(-0xc0 + 4 * (s32)i) = FRW(-0xc0 + 4 * (s32)j);
        i++;
        FRW(-0xc0 + 4 * (s32)j) = tsave;
      } while (i < m);
    }
  }

L243:
  FRW(-0xf8) = 0;
  if ((s32)FRW(-0xf0) <= 0)
    goto L4cb;

L255:
  {
    u8 *Mi;
    u8 *Q;
    u32 r1, r;
    u8 *Ob;
    u8 *R2;
    u8 *Ek;
    u8 al;
    FRW(-0xec) = 0xffffffffu;
    {
      u32 kk = FRW(-0xe8);
      u32 ii = FRW(-0xf8);
      Mi = *(u8 **)(*(u8 **)0x70039c + 0x9b);
      Ek = (u8 *)FRW(-0x80 + 8 * (s32)kk);
      u8 *X = *(u8 **)(Ek + 0x18);
      /* the pushed T[i] is the one argument of X.vt30 (ret 4): it is consumed here */
      r1 = vc1(X, 0x30, FRW(-0xc0 + 4 * (s32)ii));
      Q = (u8 *)vc1(Mi, 0x58, r1);
    }
    if (Q == 0)
      goto L4b2;
    vc2(Q, 0x80, (u32)FRP(-0x58), (u32)FRP(-0x10));
    Ob = *(u8 **)(edi + 0x18);
    R2 = *(u8 **)(Ob + 0x54);
    r = vc88(B, (u32)FRP(-0x10), 1000.0f, 200.0f, (u32)FRP(-0xec), 1, *(u32 *)(R2 + 0xc));
    if (r != 0)
      goto L4b2;
    FRW(-0xec) = 0xffffffffu;
    r = vc88(B, (u32)FRP(-0x10), 50.0f, 50.0f, (u32)FRP(-0xec), 1, *(u32 *)(R2 + 0x10));
    if (r == 0)
      goto L36f;
  L331:
    if (r != (u32)Ob)
      goto L4b2;
    r = vc88(B, (u32)FRP(-0x10), 50.0f, 50.0f, (u32)FRP(-0xec), 1, *(u32 *)(R2 + 0x10));
    if (r != 0)
      goto L331;

  L36f:
    al = (u8)vc1(Q, 0x1e0, 0x2000e1);
    if (al == 0)
      goto L47f;
    {
      u8 *A8 = *(u8 **)(Q + 8);
      u8 *mg = *(u8 **)0x70039c;
      float t1, t2, fl0, fl1, a2, b2;
      double d1, d2;
      FRF(-0x10c) = *(float *)(A8 + 0x40);
      FRF(-0x104) = *(float *)(A8 + 0x48);
      FRF(-0x118) = FRF(-0x40);
      FRF(-0x114) = FRF(-0x3c);
      FRF(-0x110) = FRF(-0x38);
      FRF(-0x1c) = FRF(-0x58);
      FRF(-0x18) = FRF(-0x54);
      FRF(-0x14) = FRF(-0x50);
      t1 = vcf(mg, 0x1c0, 0x6a6148, 0x17d);
      d1 = ((double)t1 - (double)0.5f) * (double)FRF(-0x10c);
      fl0 = (float)d1;
      FRF(-0xf0) = fl0;
      t2 = vcf(mg, 0x1c0, 0x6a6148, 0x17e);
      d2 = ((double)t2 - (double)0.5f) * (double)FRF(-0x104);
      fl1 = (float)d2;
      FRF(-0xfc) = fl1;
      a2 = fl0 + fl0;
      ext_451890((u32)FRP(-0x10), (u32)FRP(-0x118), a2);
      b2 = fl1 + fl1;
      ext_451890((u32)FRP(-0x10), (u32)FRP(-0x1c), b2);
    }

  L47f:
    {
      u8 *Oa = *(u8 **)(edi + 0x18);
      vc2(Oa, 0x370, (u32)FRP(-0x58), (u32)FRP(-0x10));
      vc1(B, 0x90, (u32)Oa);
    }
    goto L5cb;

  L4b2:
    {
      u32 ii = FRW(-0xf8) + 1;
      FRW(-0xf8) = ii;
      if (ii < FRW(-0xf0))
        goto L255;
    }
  }

L4cb:
  {
    u32 kk = FRW(-0xe8) + 1;
    FRW(-0xe8) = kk;
    if (kk < FRW(-0xf4))
      goto L150;
  }

L4e4:
  {
    u8 *Oa = *(u8 **)(edi + 0x18);
    u8 *Pa = *(u8 **)(Oa + 0xeee);
    u8 *Xa = *(u8 **)(Pa + 0x18);
    u32 count3 = vc0(Xa, 0x14);
    u32 rem3 = (u32)((s32)callRand() % (s32)count3);
    {
      u8 *Mg = *(u8 **)(*(u8 **)0x70039c + 0x9b);
      Oa = *(u8 **)(edi + 0x18);
      Pa = *(u8 **)(Oa + 0xeee);
      Xa = *(u8 **)(Pa + 0x18);
      u32 r3 = vc1(Xa, 0x30, rem3);   /* rem3 is consumed as X.vt30's one argument */
      u8 *Q2 = (u8 *)vc1(Mg, 0x58, r3);
      if (Q2 == 0)
        goto L59b;
      u8 al2;
      vc2(Q2, 0x80, (u32)FRP(-0xe4), (u32)FRP(-0x34));
      al2 = (u8)vc1(Q2, 0x1e0, 0x2000e1);
      if (al2 != 0)
        ext_55f900(edi, (u32)Q2, (u32)FRP(-0xe4), (u32)FRP(-0x34));
    }
    {
      u8 *Oz = *(u8 **)(edi + 0x18);
      vc2(Oz, 0x370, (u32)FRP(-0xe4), (u32)FRP(-0x34));
    }
  }
  goto L5cb;

L59b:
  {
    u8 *G = *(u8 **)0x700390;
    u8 *W = (u8 *)vc2(G, 0x20, 0x6a6148, 0x13f);
    u8 *Oa = *(u8 **)(edi + 0x18);
    u8 *Q4 = (u8 *)vc0(Oa, 0x20);
    ((CDECL3)*(u32 *)(*(u32 *)W + 0x30))((u32)W, 0x69d10c, *(u32 *)(Q4 + 4));
  }
  goto L5cb;

Lp0:
  {
    u8 *G = *(u8 **)0x700390;
    u8 *W = (u8 *)vc2(G, 0x20, 0x6a6148, 0xcb);
    u8 *Oa = *(u8 **)(edi + 0x18);
    u8 *Q2 = (u8 *)vc0(Oa, 0x20);
    ((CDECL3)*(u32 *)(*(u32 *)W + 0x30))((u32)W, 0x6a6178, *(u32 *)(Q2 + 4));
  }

L5cb:
  return;
}
PCREG(55ef10, beamToSpawnPoint);
