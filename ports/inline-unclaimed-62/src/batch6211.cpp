// batch6211.cpp - unclaimed-62 claim 5 (slice 1): 0x502590 (no name in the name map) [thiscall, ret 4]. From the array at x+4 (exe 0x5003d0):
// v[0] = dword of element 2, v[1] = dword of element 3, and element 1 gives a value by its tag byte +4: 3 -> its dword; 4 -> slot 0x34 of the
// object its dword points to; otherwise report line 0x111 (format 0x69c6b0, text 0x69c9b0), the assert hook (trap when none), 0.
// The message table's slot 0x114 gets (value, 0, 0x69ca10, 0x24a) and returns a word w. Element 0's dword, w and &v go to this+0xc's slot
// 0x12c (three arguments).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn502590(u8 *self, u8 *x) {
  u32 v[2];
  v[0] = rd32u(ext_5003d0(rdp(x + 4), 2));
  v[1] = rd32u(ext_5003d0(rdp(x + 4), 3));
  u8 *e1 = ext_5003d0(rdp(x + 4), 1);
  u8 tag = e1[4];
  u32 val;
  if (tag == 3) {
    val = rd32u(e1);
  } else if (tag == 4) {
    u8 *obj = rdp(e1);
    val = vcall<u32>(obj, 0x34);
  } else {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x111);
    (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c9b0);
    typedef void (*hookfn)();
    hookfn h = G(hookfn, 0x7003b0);
    if (h) h();
    else __builtin_debugtrap();
    val = 0;
  }
  u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = vcall<u32>(msg, 0x114, val, (u32)0, (u32)0x69ca10, (u32)0x24a) & 0xffff;
  u8 *e0 = ext_5003d0(rdp(x + 4), 0);
  vcall<void>(rdp(self + 0xc), 0x12c, rd32u(e0), w, (void *)v);
}
PCREG(502590, fn502590);
