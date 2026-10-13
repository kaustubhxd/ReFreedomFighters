// batch4126.cpp - unclaimed-41 batch 26 (slice 13): 0x59f6d0 ZFFActor::DropWeapons() (thiscall, no arguments, ret 0, void).
// One file: part A (entry), part P (the 0x500 call, which leads into part B), part B. The /GS cookie check is not reproduced.
// The SEH-free function has no fs:[0] access.
#include "ff.h"

extern "C" void THISCALL ext_475ac0(u8 *self);                      // ecx = this, no arguments (stub, GUESS)
extern "C" void THISCALL ext_475aa0(u8 *self);                      // ecx = this, no arguments (stub, GUESS)
extern "C" void THISCALL ext_46abf0(u8 *self, u8 *e);               // ecx = [0x7003b8], one argument (stub, GUESS)

typedef u32(THISCALL * f0_t)(u8 *);
typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
typedef u32(THISCALL * f3_t)(u8 *, u32, u32, u32);
typedef float(THISCALL * fl_t)(u8 *, u32, u32);    // returns a float in st0

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

// the list at 0x7003b8: count at +0x8b4, entries from +0x8b8 up to (count + 0x22e) dwords; append E unless it is already there
static void listAddIfAbsent(u8 *e) {
  u8 *L = G(u8 *, 0x7003b8);
  u32 cnt = *(u32 *)(L + 0x8b4);
  u8 *base = L + 0x8b8;
  u8 *end = L + (cnt + 0x22e) * 4;
  for (u8 *p = base; p != end; p += 4) {
    if (*(u8 **)p == e)
      return;
  }
  u32 idx = *(u32 *)(L + 0x8b4);
  *(u8 **)(L + 0x8b8 + idx * 4) = e;
  *(u32 *)(L + 0x8b4) = idx + 1;
}

// the float term for the 0x360 argument: max(trunc(r * (float)(N - 5)), 0) + 5, with r the st0 result of rm.vt[0x1c0](a, b)
static u32 weightArg(u8 *rm, u32 a, u32 b, u32 N) {
  float r = ((fl_t)vslot(rm, 0x1c0))(rm, a, b);
  float v = r * (float)(s32)(N - 5);
  s32 c = (s32)v;
  u32 cc = (c > 0) ? (u32)c : 0u;
  return cc + 5;
}

// part B (after the 0x500 call): R is the object, self is the actor
static void partB(u8 *self, u8 *E) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u32 L34[4];
  u32 L10[4];

  if (*(u32 *)(rm + 0x1b5d) != 0) {
    *(u32 *)(self + 0x78e) = 0;
  } else {
    ext_475aa0(self);
    ((f2_t)vslot(E, 0x80))(E, (u32)L34, (u32)L10);
    ((f2_t)vslot(E, 0x2d0))(E, 1u, 0u);
    u8 *G2 = (u8 *)((f0_t)vslot(E, 0x2e8))(E);
    u8 *H2 = (u8 *)((f2_t)vslot(G2, 0x2c4))(G2, *(u32 *)(o + 0xadc), 0x4954454du);
    if (H2 == 0)
      return;
    E = H2;
    u32 V = ((f3_t)vslot(o, 0x4c))(o, (u32)self, *(u32 *)(o + 0xadc), 1u);
    ((f1_t)vslot(E, 0x2f0))(E, V);
    ((f2_t)vslot(E, 0x7c))(E, (u32)L34, (u32)L10);
  }
  ext_475aa0(self);

  ((f2_t)vslot(E, 0x2d0))(E, 0u, 0u);
  u32 al = ((f1_t)vslot(E, 0x1e0))(E, 0x1007d2u) & 0xff;
  if (al == 0) {
    if (*(u32 *)(rm + 0x1b5d) == 1)
      listAddIfAbsent(E);
    ((f1_t)vslot(self, 0x4f4))(self, (u32)E);
    return;
  }
  u8 *K = (u8 *)((f0_t)vslot(E, 0x2e8))(E);
  if (K == 0) {
    ((f0_t)vslot(E, 0x320))(E);
    return;
  }
  u8 *K2 = (u8 *)((f0_t)vslot(E, 0x2e8))(E);
  if (((f0_t)vslot(K2, 0x300))(K2) == 0) {
    ((f0_t)vslot(E, 0x320))(E);
    return;
  }
  if (*(u32 *)(rm + 0x1b5d) == 1)
    ext_46abf0(G(u8 *, 0x7003b8), E);
  ((f1_t)vslot(self, 0x4f4))(self, (u32)E);
  ((f2_t)vslot(E, 0x2d0))(E, 0u, 0u);
  u32 N2 = ((f0_t)vslot(E, 0x364))(E);
  u32 val = weightArg(G(u8 *, 0x70039c), 0x6ae6a0u, 0x4b3u, N2);
  ((f1_t)vslot(E, 0x360))(E, val);
}

// 0x59f6d0
static void THISCALL fn59f6d0(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u32 L34[4];
  u32 L10[4];

  // part A
  u8 *E = (u8 *)((f0_t)vslot(self, 0x504))(self);
  if (E != 0) {
    if (*(u32 *)(rm + 0x1b5d) == 0) {
      ext_475ac0(self);
      ((f2_t)vslot(E, 0x80))(E, (u32)L34, (u32)L10);
      ((f2_t)vslot(E, 0x2d0))(E, 1u, 0u);
      u8 *G2 = (u8 *)((f0_t)vslot(E, 0x2e8))(E);
      u8 *H = (u8 *)((f2_t)vslot(G2, 0x2c4))(G2, *(u32 *)(o + 0xadc), 0x4954454du);
      if (H != 0) {
        E = H;
        u32 V = ((f3_t)vslot(o, 0x4c))(o, (u32)self, *(u32 *)(o + 0xadc), 1u);
        ((f1_t)vslot(E, 0x2f0))(E, V);
        ((f2_t)vslot(E, 0x7c))(E, (u32)L34, (u32)L10);
        ext_475ac0(self);
        goto afterA;
      }
      E = 0;   // H == 0: the exe jumps to 59f909 (part P) without the second 0x475ac0
    } else {
      *(u32 *)(self + 0x78a) = 0;
      ext_475ac0(self);
    }
afterA:
    if (E != 0) {
      ((f2_t)vslot(E, 0x2d0))(E, 0u, 0u);
      u32 al = ((f1_t)vslot(E, 0x1e0))(E, 0x1007d2u) & 0xff;
      if (al == 0) {
        if (*(u32 *)(rm + 0x1b5d) == 1)
          listAddIfAbsent(E);
        ((f1_t)vslot(self, 0x4f4))(self, (u32)E);
      } else {
        u8 *K = (u8 *)((f0_t)vslot(E, 0x2e8))(E);
        bool done = (K == 0);
        if (!done) {
          u8 *K2 = (u8 *)((f0_t)vslot(E, 0x2e8))(E);
          done = (((f0_t)vslot(K2, 0x300))(K2) == 0);
        }
        if (done) {
          ((f0_t)vslot(E, 0x320))(E);
        } else {
          if (*(u32 *)(rm + 0x1b5d) == 1)
            ext_46abf0(G(u8 *, 0x7003b8), E);
          ((f1_t)vslot(self, 0x4f4))(self, (u32)E);
          ((f2_t)vslot(E, 0x2d0))(E, 0u, 0u);
          u32 N = ((f0_t)vslot(E, 0x364))(E);
          u32 val = weightArg(G(u8 *, 0x70039c), 0x6ae6a0u, 0x47fu, N);
          // the 0x788 override: a non-negative signed 16-bit value replaces the weight
          s16 w = *(s16 *)(self + 0x788);
          if (w > -1)
            val = (u32)(s32)w;
          ((f1_t)vslot(E, 0x360))(E, val);
        }
      }
    } else {
      // E == 0 or H == 0: fall through to part P
    }
  }

  // part P: R = this.vt[0x500](); R == 0 leaves
  u8 *R = (u8 *)((f0_t)vslot(self, 0x500))(self);
  if (R != 0)
    partB(self, R);
}
PCREG(59f6d0, fn59f6d0);
