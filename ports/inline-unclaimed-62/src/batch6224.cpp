// batch6224.cpp - unclaimed-62 claim 17 (larger, 102 instructions): 0x5027b0 [thiscall, one argument, ret 4]. The record's array at +4
// (exe 0x5003d0): v[0] = dword of element 2; element 3's tag selects v[1]: 3 -> its dword, 4 -> slot 0x34 of the object its dword points
// to, otherwise report line 0x111 (format 0x69c6b0, text 0x69c9b0), the assert hook (trap when none), 0. Element 1's tag selects the value
// given to the message table's slot 0x114 as (value, 0, 0x69ca10, 0x274) (the same tag rules; the error path gives 0); the returned word w
// and element 0's dword and &v go to this+0xc's slot 0x12c (three arguments).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void bad5027() {
  void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x111);
  (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c9b0);
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h();
  else __builtin_debugtrap();
}

static u32 tagValue(u8 *e) {
  u8 tag = e[4];
  if (tag == 3) return rd32u(e);
  if (tag == 4) return vcall<u32>(rdp(e), 0x34);
  bad5027();
  return 0;
}

static void THISCALL fn5027b0(u8 *self, u8 *x) {
  u8 *arr = rdp(x + 4);
  u32 v[2];
  v[0] = rd32u(ext_5003d0(arr, 2));
  v[1] = tagValue(ext_5003d0(arr, 3));
  u32 val = tagValue(ext_5003d0(arr, 1));
  u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = vcall<u32>(msg, 0x114, val, (u32)0, (u32)0x69ca10, (u32)0x274) & 0xffff;
  u8 *e0 = ext_5003d0(arr, 0);
  vcall<void>(rdp(self + 0xc), 0x12c, rd32u(e0), w, (void *)v);
}
PCREG(5027b0, fn5027b0);
