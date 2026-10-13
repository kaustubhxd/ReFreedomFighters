// batch2618.cpp - wider batch 2618: nine unclaimed functions (GUESS names); callee arities from their `ret` immediates.
#include "ff.h"

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])
typedef u32(THISCALL *vf0_t)(void *);
typedef u32(THISCALL *vf1_t)(void *, u32);
typedef u32(THISCALL *vf2_t)(void *, u32, u32);
typedef u32(THISCALL *vf4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *vfp_t)(void *, void *);
typedef u32(THISCALL *vfp2_t)(void *, void *, u32);
typedef u32(THISCALL *vfp3_t)(void *, u32, void *);
static inline u8 *sysp() { return *(u8 **)0x70039c; }

extern "C" u8 THISCALL ext_4db9a0(void *self, u32 flags);              // ret 4
extern "C" u32 ext_41e290(u32 n);
extern "C" u32 THISCALL ext_49cbb0(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" u32 THISCALL ext_49ccc0(void *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_4e6330(void *self, void *p);              // ret 4
extern "C" u32 THISCALL ext_4e5e60(void *self);

// 0x48b690, no args (plain): obj = ([[engine+0x9b]+8]) slot 8 (0x67cd1c, 0x67d1c4, 0, 0); esi = [obj+0x54]; null -> log ([0x700390] slot 0x20 (0x68d798, 0x4f3), slot 0x2c cdecl (log, 0x68d86c)) and 0;
// else esi slot 0x10c (0x68d8ac, -1) -> r; r slot 8; returns esi.
typedef u32(THISCALL *vlg_t)(void *, u32, u32);
typedef void(__attribute__((cdecl)) * vlog_t)(void *, u32);
static u32 fn48b690() {
  u8 *t = *(u8 **)(sysp() + 0x9b);
  void *m = *(void **)(t + 8);
  u8 *o = (u8 *)((vf4_t)(*(u32 **)m)[8 / 4])(m, 0x67cd1c, 0x67d1c4, 0, 0);
  u8 *esi = *(u8 **)(o + 0x54);
  if (!esi) {
    void *lg = *(void **)0x700390;
    void *l = (void *)VT(lg, vlg_t, 0x20)(lg, 0x68d798, 0x4f3);
    ((vlog_t)(*(u32 **)l)[0x2c / 4])(l, 0x68d86c);
    return 0;
  }
  void *r = (void *)VT(esi, vf2_t, 0x10c)(esi, 0x68d8ac, (u32)-1);
  VT(r, vf0_t, 8)(r);
  return (u32)esi;
}
PCREG(48b690, fn48b690);

// 0x48d0e0, no args (plain): cur = [[[engine+0x9b]+0xadc]+8]; while cur: when 0x4db9a0(cur, 0x200015): slot 0x21c of the object at cur+0x54; then slot 0x50 of the list object (+0xadc) with &cur.
static void fn48d0e0() {
  u8 *t = *(u8 **)(sysp() + 0x9b);
  u8 *l = *(u8 **)(t + 0xadc);
  u8 *cur = *(u8 **)(l + 8);
  while (cur) {
    if (ext_4db9a0(cur, 0x200015)) {
      void *x = *(void **)(cur + 0x54);
      VT(x, vf0_t, 0x21c)(x);
    }
    t = *(u8 **)(sysp() + 0x9b);
    l = *(u8 **)(t + 0xadc);
    VT(l, vfp_t, 0x50)(l, &cur);
  }
}
PCREG(48d0e0, fn48d0e0);

// 0x48dea0, no args (plain): walk the list at [0x7003bc] (next at +0x14); each node: +8 = 0; when +4 == 0 and +0x2b != 0, search the list again for a node with +4 == 0 whose name [node] compares equal
// (IAT cdecl test 0x676414 (name2, name1) == 0) and store it at +0xc.
typedef s32(__attribute__((cdecl)) * cmp_t)(u32, u32);
static void fn48dea0() {
  u8 *edi = *(u8 **)0x7003bc;
  if (!edi) return;
  cmp_t f = *(cmp_t *)0x676414;
  do {
    *(u32 *)(edi + 8) = 0;
    if (*(u32 *)(edi + 4) == 0 && *(u32 *)(edi + 0x2b) != 0) {
      u8 *esi = *(u8 **)0x7003bc;
      while (esi) {
        if (*(u32 *)(esi + 4) == 0) {
          if (f(*(u32 *)(edi + 0x2b), *(u32 *)esi) == 0) {
            *(u8 **)(edi + 0xc) = esi;
            break;
          }
        }
        esi = *(u8 **)(esi + 0x14);
      }
    }
    edi = *(u8 **)(edi + 0x14);
  } while (edi);
}
PCREG(48dea0, fn48dea0);

// 0x4908c0, thiscall(key) ret 4, returns the first element of the list at this+0xb00 (reftab slots 0x4c begin / 0x5c next with a valid flag) whose +0x34 == key, else 0.
static u32 THISCALL fn4908c0(u8 *self, u32 key) {
  void *T = self + 0xb00;
  u32 it[3];
  VT(T, vfp_t, 0x4c)(T, it);
  u8 *e = (u8 *)VT(T, vfp_t, 0x5c)(T, it);
  if (it[0] == 0) return 0;
  for (;;) {
    if (*(u32 *)(e + 0x34) == key) return (u32)e;
    e = (u8 *)VT(T, vfp_t, 0x5c)(T, it);
    if (it[0] == 0) return 0;
  }
}
PCREG(4908c0, fn4908c0);

// 0x499ac0, thiscall(out) ret 4, returns this: slot 0x18 (&n, 4) reads a size; with n: slot 0x18 (out, n); else byte out[0] = 0.
static u8 *THISCALL fn499ac0(u8 *self, u8 *out) {
  u32 n;
  VT(self, vfp2_t, 0x18)(self, &n, 4);
  if (n) {
    VT(self, vfp2_t, 0x18)(self, out, n);
    return self;
  }
  out[0] = 0;
  return self;
}
PCREG(499ac0, fn499ac0);

// 0x499b00, thiscall(out) ret 4, returns this: as 0x499ac0 but with n: block = alloc(n), *out = block, slot 0x18 (block, n); else *out = 0 (dword).
static u8 *THISCALL fn499b00(u8 *self, u32 *out) {
  u32 n;
  VT(self, vfp2_t, 0x18)(self, &n, 4);
  if (n) {
    u32 p = ext_41e290(n);
    *out = p;
    VT(self, vfp2_t, 0x18)(self, (void *)p, n);
    return self;
  }
  *out = 0;
  return self;
}
PCREG(499b00, fn499b00);

// 0x49a510, thiscall(obj) ret 4: obj slot 0xc; this slot 0x14 (&n); then n times: this slot 0x14 (&v), obj slot 4 (v). (n shares the argument slot, initially obj.)
static void THISCALL fn49a510(u8 *self, u8 *obj) {
  u32 n = (u32)obj;
  VT(obj, vf0_t, 0xc)(obj);
  VT(self, vfp_t, 0x14)(self, &n);
  for (u32 i = 0; n != 0 && i != n; i++) {
    u32 v;
    VT(self, vfp_t, 0x14)(self, &v);
    VT(obj, vf1_t, 4)(obj, v);
  }
}
PCREG(49a510, fn49a510);

// 0x49c680, thiscall(a, b) ret 8, returns bool (AL): !(0x49cbb0(this, a, b, 0) & 1)... see the body: first test true gives 1; else the same with 0x49ccc0.
static u8 THISCALL fn49c680(u8 *self, u32 a, u32 b) {
  u8 r1 = (u8)ext_49cbb0(self, a, b, 0);
  if (((u8)~r1) & 1) return 1;
  u8 r2 = (u8)ext_49ccc0(self, a, b, 0);
  return (((u8)~r2) & 1) ? 1 : 0;
}
PCREG(49c680, fn49c680);

// 0x4a37a0, thiscall(r) ret 4: 0x4e6330(r, this + 0x78); +0x70 = 0x4e5e60(r); the embedded object at +0x78 slot 0x14: a zero result calls the assert hook 0x7003b0 (int3 when null).
typedef u32 (*hook_t)();
static void THISCALL fn4a37a0(u8 *self, void *r) {
  ext_4e6330(r, self + 0x78);
  *(u32 *)(self + 0x70) = ext_4e5e60(r);
  void *o = self + 0x78;
  if (VT(o, vf0_t, 0x14)(o) == 0) {
    hook_t h = *(hook_t *)0x7003b0;
    if (!h) __asm__ volatile("int3");
    h();
  }
}
PCREG(4a37a0, fn4a37a0);
