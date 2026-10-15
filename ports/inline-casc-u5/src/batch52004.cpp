// batch52004.cpp - cascade tier H, batch 52004: 0x50eb20 (copy a looked-up three-float vector into three entries).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);          // thiscall ret 4: entry lookup
typedef u32 (*hook_t)();

// Log through the object at 0x700390: r = slot 0x20(file, line) and r's slot 0x2c (caller-cleans, ECX = r's vtable) with (r, a, b).
static inline u8 *log_get(u32 file, u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  return vcall<u8 *>(lg, 0x20, file, line);
}
static inline void log_call3(u8 *r, u32 a, u32 b) {
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[b]\n\tpush %[a]\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"((u32)r), [a] "r"(a), [b] "r"(b), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}

// Entry slot i of the list [X+8] receives float v and kind 2; a kind other than 0 / 2 logs (0x69c8e0, 0x104; 0x69c6b0, 0x69c938) and calls the assert hook (int3 when null).
static inline void set_entry(u8 *X, u32 i, float v) {
  u8 *ent = (u8 *)ext_5003d0(*(u8 **)(X + 8), i);
  u8 k = ent[4];
  if (k != 0 && k != 2) {
    u8 *r = log_get(0x69c8e0, 0x104);
    log_call3(r, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  ent[4] = 2;
  *(float *)ent = v;
}

// 0x50eb20, stdcall(X) ret 4 (ECX unused): key = [ext_5003d0([X+4], 0)]; o = (*[0x70039c + 0x9b])->slot0x58(key); globals 0x701468/6c/70 = 0;
// o: o->slot0x84(0x701468); else log (0x69db34, 0x297; slot 0x2c with (r, 0x69dec0, [ext_5003d0([X+4], 0)])).
// Then entries 0, 1, 2 of the list [X+8] get the three globals as floats (each read just before its lookup).
static void STDCALL fn50eb20(u8 *X) {
  u32 *e0 = (u32 *)ext_5003d0(*(u8 **)(X + 4), 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tab, 0x58, *e0);
  G(float, 0x701468) = 0; G(float, 0x70146c) = 0; G(float, 0x701470) = 0;
  if (o) {
    vcall<void>(o, 0x84, 0x701468u);
  } else {
    u8 *r = log_get(0x69db34, 0x297);
    u32 *e1 = (u32 *)ext_5003d0(*(u8 **)(X + 4), 0);
    log_call3(r, 0x69dec0, *e1);
  }
  float v = G(float, 0x701468);
  set_entry(X, 0, v);
  v = G(float, 0x70146c);
  set_entry(X, 1, v);
  v = G(float, 0x701470);
  set_entry(X, 2, v);
}
PCREG(50eb20, fn50eb20);
