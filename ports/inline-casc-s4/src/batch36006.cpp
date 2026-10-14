// batch36006.cpp - cascade s4 batch 36006: 0x54f010, 0x631620, 0x63d840 (tier F rows).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef s32(STDCALL *q4_t)(void *, u32, u32, u32 *);
typedef void(THISCALL *v0_t)(void *);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline u32 rh(u8 *p) { return *(u16 *)p; }

// log call through [0x700390]: o = db->slot 0x20(file, line) (thiscall, pops 8); o->slot 0x2c(o, fmt) cdecl with ecx = o->vtbl, caller pops 8.
static inline void logCall(u32 file, u32 line, u32 fmt) {
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, file, line);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[f2]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                   : "+c"(vt2)
                   : [f2] "r"(fmt), [o] "r"(o), [f] "r"(fn)
                   : "eax", "edx", "memory", "cc");
}

extern "C" u8 THISCALL ext_54ef60(void *self);

// 0x54f010, thiscall(no args) returns bool: p = this[4]; null: logs (0x6a4168, 0x79, 0x6a41d8), returns 0. Otherwise ok = 0x54ef60(p); logs
// (0x7d, 0x6a41f8) when ok else (0x7f, 0x6a4204); r = p->slot 0x14(p, 0x6bdf60, 1, &x) (stdcall, 16 bytes) with x = 0; returns r >= 0 && (x & 3) == 3.
static u8 THISCALL fn54f010(u8 *self) {
  u8 *p = *(u8 **)(self + 4);
  if (!p) {
    logCall(0x6a4168, 0x79, 0x6a41d8);
    return 0;
  }
  u8 ok = ext_54ef60(p);
  if (ok) logCall(0x6a4168, 0x7d, 0x6a41f8);
  else logCall(0x6a4168, 0x7f, 0x6a4204);
  u32 x = 0;
  s32 r = (*(q4_t **)p)[0x14 / 4](p, 0x6bdf60, 1, &x);
  if (r < 0) return 0;
  return (x & 3) == 3;
}
PCREG(54f010, fn54f010);

// 0x631620, cdecl(p): ebx = sum of u16 at p+0x8c,0x90,0x94,0x98,0x9c,0xa0,0xa4 plus (p+0x28c+8k, p+0x290+8k) for k < 0x40;
// edi = u16 p+0x288 + sum of (p+0xa8+8k, p+0xac+8k) for k < 0x3c; p[0x1c] = (ebx <= edi >> 2) (unsigned).
static void fn631620(u8 *p) {
  u32 ebx = rh(p + 0xa0) + rh(p + 0xa4) + rh(p + 0x9c) + rh(p + 0x98) + rh(p + 0x94) + rh(p + 0x90) + rh(p + 0x8c);
  u32 edx = 0, esi = 0;
  for (u32 k = 0; k < 0x3c; k++) {
    edx += rh(p + 0xa8 + 8 * k);
    esi += rh(p + 0xac + 8 * k);
  }
  u32 edi = rh(p + 0x288) + (esi + edx);
  edx = 0;
  esi = 0;
  for (u32 k = 0; k < 0x40; k++) {
    edx += rh(p + 0x28c + 8 * k);
    esi += rh(p + 0x290 + 8 * k);
  }
  ebx += esi + edx;
  p[0x1c] = ebx <= (edi >> 2);
}
PCREG(631620, fn631620);

extern "C" void THISCALL ext_64b070(void *self);
extern "C" void THISCALL ext_648280(void *self);
extern "C" void ext_634273(void *p, u32 n);  // cdecl
extern "C" void *memset_634d10(void *, int, u32) asm("ext_634d10");
extern "C" void THISCALL ext_63fc20(void *self);
extern "C" void THISCALL ext_65f0f0(void *self);

// 0x63d840, thiscall(no args) void: when this[5]: this->slot 0x64(); for each of this[0xec] pointers at this+0xf0: 0x64b070(o); when o: 0x648280(o), 0x634273(o, 0x182a1);
// then this[0xec] = 0, memset(this+0x6c, 0, 0x80), 0x63fc20(this), 0x634273(this[0x60], 0x340c), this[0x60] = 0, 0x634273(this[0x64], 1), this[0x64] = 0, 0x65f0f0(this+0x8270), this[5] = 0.
static void THISCALL fn63d840(u8 *self) {
  if (!self[5]) return;
  (*(v0_t **)self)[0x64 / 4](self);
  if (rd(self + 0xec) != 0) {
    u32 i = 0;
    do {
      u8 *o = *(u8 **)(self + 0xf0 + 4 * i);
      ext_64b070(o);
      if (o) {
        ext_648280(o);
        ext_634273(o, 0x182a1);
      }
      i++;
    } while (i != rd(self + 0xec));
  }
  *(u32 *)(self + 0xec) = 0;
  memset_634d10(self + 0x6c, 0, 0x80);
  ext_63fc20(self);
  ext_634273(*(void **)(self + 0x60), 0x340c);
  *(u32 *)(self + 0x60) = 0;
  ext_634273(*(void **)(self + 0x64), 1);
  *(u32 *)(self + 0x64) = 0;
  ext_65f0f0(self + 0x8270);
  self[5] = 0;
}
PCREG(63d840, fn63d840);
