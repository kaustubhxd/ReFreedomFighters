// batch6227.cpp - unclaimed-62 claim 20 (larger, 111 instructions): 0x501860 [thiscall, one argument, ret 4]. The globals 0x700f68,
// 0x700f6c and 0x700f70 are zeroed; slot 0x84 of this+0xc's object takes &0x700f68 and fills the three words. Then each word goes into
// element 0, 1 and 2 of the vector at arg+8 (exe 0x5003d0) with the element's state set to 2. An element whose state is neither 0 nor 2
// gets the debug report (line 0x104, format 0x69c938, text 0x69c6b0) and the assert hook (trap when none) before it is written.
// The exe reads each global only after the previous element is written; the same order is kept.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void bad501860() {
  void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x104);
  (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c938);
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h();
  else __builtin_debugtrap();
}

static void put(u8 *e, u32 v) {
  u8 st = e[4];
  if (st != 0 && st != 2) bad501860();
  wr32u(e, v);
  e[4] = 2;
}

static void THISCALL fn501860(u8 *self, u8 *arg) {
  G(u32, 0x700f68) = 0;
  G(u32, 0x700f6c) = 0;
  G(u32, 0x700f70) = 0;
  vcall<void>(rdp(self + 0xc), 0x84, (u32)0x700f68);
  u32 f0 = G(u32, 0x700f68);
  put(ext_5003d0(rdp(arg + 8), 0), f0);
  u32 f1 = G(u32, 0x700f6c);
  put(ext_5003d0(rdp(arg + 8), 1), f1);
  u32 f2 = G(u32, 0x700f70);
  put(ext_5003d0(rdp(arg + 8), 2), f2);
}
PCREG(501860, fn501860);
