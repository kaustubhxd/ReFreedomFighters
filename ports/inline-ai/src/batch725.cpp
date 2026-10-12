// batch725.cpp - soldier AI, batch 725 (2026-10-12): ZFFActorIf::GetCoverStandPos (0x5595f0), the cover stand-position script
// native. Argument: OpaqueCallParameters_t& (pr): in-accessor at pr+4 (index 0 = spot index, 1 and 2 = flags), out-accessor at
// pr+8 (six float outputs, or the default block when the index is negative). Index >= 0: the spot record is
// innerList(cl+0x5f) + index*0x48 (cl = gl+0x2c1d). Position A = rec+0x10, facing B = rec+0x28, type from the rec+0x34 bits
// (bit0 -> 0, bit1 -> 1, bit2 -> 2, none -> hook and 0). Height h = actor->stance ? 65 : 50, with stance = *(actor+0x54)+4.
//   type 0: nothing moves.
//   type 1: A += B*h; unless flagA, B = -B.
//   type 2: A += B*h; B = -B; if flagA: M = createmat(B, 0), A += M[6..8]*(flagB ? -49.268 : 49.268), A += M[0..2]*22.386,
//           B = vrot(B, (0, flagB ? -2.4988 : 2.4988, 0)).
// Outputs: out0..2 = A, out3..5 = B. Negative index: out2 = 1e6, out1 = out2, out0 = out1, out3 = 1.0, out5 = 0, out4 = out5
// (variant copies with release/clone for type-4 items). The wrong-type log path for in0 runs as in the exe.
#include "ff.h"

struct Item { u32 v; u8 t; u8 pad[3]; };   // accessor item: value at +0, type byte at +4

extern "C" Item *THISCALL ext_5003d0(void *acc, u32 idx);                         // accessor (ecx = object, idx on stack)
extern "C" Item *THISCALL ext_500360(Item *it, float v);                          // setter: value -> type 2, returns the item
extern "C" void FASTCALL ext_451890(float *out, const float *a, float s);         // vaddscalar: out += a * s
extern "C" void THISCALL ext_4e09b0(float *v);                                    // vneg
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, u32 zero);        // createmat (12 floats)
extern "C" void FASTCALL ext_4e0be0(float *facing, const float *axis);            // vrot

static inline void copy3(float *d, const float *s) {
  d[0] = s[0];
  d[1] = s[1];
  d[2] = s[2];
}

static void hook_or_trap() {
  void (*h)() = *(void (**)())0x7003b0;
  if (h)
    h();
  else
    __builtin_debugtrap();
}

static void wrong_type() {
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x69c8e0, 0x104);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x69c6b0, (const char *)0x69c938);   // "RAISE_EXCEPTION %s", "NO! WRONG TYPE"
  hook_or_trap();
}

// the assignment used for the default outputs: release the destination object if it is type 4, then take the source value
// (cloned when the source is type 4) and its type.
static void copy_item(Item *dst, Item *src) {
  if (dst->t == 4)
    vcall<void>((void *)dst->v, 0x28);
  u32 val = (src->t == 4) ? vcall<u32>((void *)src->v, 0x24) : src->v;
  dst->v = val;
  dst->t = src->t;
}

// 0x5595f0 ZFFActorIf::GetCoverStandPos(OpaqueCallParameters_t&) [medium].
static void THISCALL cover_GetCoverStandPos(u8 *self, u8 *pr) {
  void *inAcc = *(void **)(pr + 4);
  void *outAcc = *(void **)(pr + 8);

  Item *i0 = ext_5003d0(inAcc, 0);
  if (i0->t != 0 && i0->t != 1)
    wrong_type();
  s32 idx = (s32)i0->v;
  u32 flagA = ext_5003d0(inAcc, 1)->v;
  u32 flagB = ext_5003d0(inAcc, 2)->v;

  if (idx < 0) {
    Item *o2 = ext_500360(ext_5003d0(outAcc, 2), bitsf(0x49742400u));   // 1000000.0
    Item *o1 = ext_5003d0(outAcc, 1);
    if (o1 != o2)
      copy_item(o1, o2);
    Item *o0 = ext_5003d0(outAcc, 0);
    if (o0 != o1)
      copy_item(o0, o1);
    ext_500360(ext_5003d0(outAcc, 3), 1.0f);
    Item *o5 = ext_500360(ext_5003d0(outAcc, 5), 0.0f);
    Item *o4 = ext_5003d0(outAcc, 4);
    if (o4 != o5)
      copy_item(o4, o5);
    return;
  }

  u8 *gl = *(u8 **)0x7003b8;
  u8 *cl = *(u8 **)(gl + 0x2c1d);
  u8 *rec = *(u8 **)(cl + 0x5f) + (u32)idx * 0x48;
  float A[3], B[3];
  copy3(A, (float *)(rec + 0x10));
  copy3(B, (float *)(rec + 0x28));
  u8 *actor = *(u8 **)(self + 0x1c);
  u32 stance = *(u32 *)(*(u8 **)(actor + 0x54) + 4);
  u32 f = *(u32 *)(rec + 0x34);
  u32 t;
  if (f & 1)
    t = 0;
  else if (f & 2)
    t = 1;
  else if (f & 4)
    t = 2;
  else {
    hook_or_trap();
    t = 0;
  }

  float h = stance ? bitsf(0x42820000u) : bitsf(0x42480000u);   // 65 : 50
  if (t == 1) {
    ext_451890(A, B, h);
    if (!flagA)
      ext_4e09b0(B);
  } else if (t == 2) {
    ext_451890(A, B, h);
    ext_4e09b0(B);
    if (flagA) {
      float M[12];
      ext_4de040(M, B, 0);
      float s1 = (float)(flagB ? -49.268 : 49.268);
      ext_451890(A, M + 6, s1);                       // M + 0x18
      ext_451890(A, M, bitsf(0x41b31687u));           // 22.386
      float s2 = (float)(flagB ? -2.498792741012573 : 2.498792741012573);
      float C[3] = {0.0f, s2, 0.0f};
      ext_4e0be0(B, C);
    }
  }

  float vals[6] = {A[0], A[1], A[2], B[0], B[1], B[2]};
  for (int i = 0; i < 6; i++)
    ext_500360(ext_5003d0(outAcc, i), vals[i]);
}
PCREG(5595f0, cover_GetCoverStandPos);
