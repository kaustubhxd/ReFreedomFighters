// batch6229.cpp - unclaimed-62 claim 22 (larger, 110 instructions): 0x5058a0 [thiscall, one argument, ret 4]. First element 0 of the vector at
// arg+4 (exe 0x5003d0): tag 3 -> its dword; tag 4 -> slot 0x34 of the object its dword points to; otherwise report line 0x111 and the assert
// hook (value 0). Element 0 of the vector at arg+8 is set to 0 (exe 0x5002f0). If the engine's helper object (eng+0x1a9f) is set: the value is
// compared as a string with the exe constant at 0x677b5c (byte pairs, as the exe loop). Equal -> this+0x14's object gets +0x14f = 0 and the
// function returns. Otherwise slot 0x5c of the helper takes the value and returns esi; esi zero -> report line 0x160 (format 0x69ce70, file
// 0x69cd2c, argument the value); the object gets +0x14f = esi when non-zero; element 0 of the vector at arg+8 is set to esi (exe 0x5002f0).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)
extern "C" u8 *THISCALL ext_5002f0(u8 *elem, u32 value);  // exe: element setter, state = 1 (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);
typedef void (*reportArgFn)(void *, const char *, u32);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void bad5058a0() {
  void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x111);
  (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c9b0);
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h();
  else __builtin_debugtrap();
}

// the exe's byte-pair loop: equal iff both strings are the same up to their terminating zero
static bool eqPairs(const u8 *a, const u8 *b) {
  for (;;) {
    if (a[0] != b[0]) return false;
    if (a[0] == 0) return true;
    if (a[1] != b[1]) return false;
    if (a[1] == 0) return true;
    a += 2;
    b += 2;
  }
}

static void THISCALL fn5058a0(u8 *self, u8 *x) {
  u8 *e0 = ext_5003d0(rdp(x + 4), 0);
  u32 edi;
  if (e0[4] == 3) {
    edi = rd32u(e0);
  } else if (e0[4] == 4) {
    edi = vcall<u32>(rdp(e0), 0x34);
  } else {
    bad5058a0();
    edi = 0;
  }
  ext_5002f0(ext_5003d0(rdp(x + 8), 0), 0);
  u8 *A = rdp(G(u8 *, 0x70039c) + 0x1a9f);
  if (A == 0) return;
  if (eqPairs((const u8 *)edi, (const u8 *)0x677b5c)) {
    wr32u(rdp(self + 0x14) + 0x14f, 0);
    return;
  }
  u32 esi = vcall<u32>(A, 0x5c, edi);
  if (esi == 0) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69cd2c, 0x160);
    (*(reportArgFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69ce70, edi);
  } else {
    wr32u(rdp(self + 0x14) + 0x14f, esi);
  }
  ext_5002f0(ext_5003d0(rdp(x + 8), 0), esi);
}
PCREG(5058a0, fn5058a0);
