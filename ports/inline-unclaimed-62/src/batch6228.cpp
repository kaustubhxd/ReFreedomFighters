// batch6228.cpp - unclaimed-62 claim 21 (larger, 115 instructions): 0x502cc0 [thiscall, one argument, ret 4]. SEH-free (the exe's security
// cookie check is not reproduced). v0 = dword of element 0. edi = element 1: tag 3 -> its dword; tag 4 -> slot 0x34 of the object its dword
// points to; otherwise report line 0x111 (format 0x69c6b0, text 0x69c9b0), the assert hook (trap when none), 0. The vector v of eight words is
// the dwords of elements 2..8 and the float of element 9's dword (cvtdq2ps). The message table's slot 0x114 gets (edi, 0, 0x69ca10, 0x13b, &v)
// and returns a word w; this+0xc's slot 0x12c gets (v0, w).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void bad502cc0() {
  void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x111);
  (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c9b0);
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h();
  else __builtin_debugtrap();
}

static u32 tagValue502cc0(u8 *e) {
  u8 tag = e[4];
  if (tag == 3) return rd32u(e);
  if (tag == 4) return vcall<u32>(rdp(e), 0x34);
  bad502cc0();
  return 0;
}

static void THISCALL fn502cc0(u8 *self, u8 *x) {
  u8 *arr = rdp(x + 4);
  u32 v0 = rd32u(ext_5003d0(arr, 0));
  u32 edi = tagValue502cc0(ext_5003d0(arr, 1));
  u32 v[8];
  v[0] = rd32u(ext_5003d0(arr, 2));
  v[1] = rd32u(ext_5003d0(arr, 3));
  v[2] = rd32u(ext_5003d0(arr, 4));
  v[3] = rd32u(ext_5003d0(arr, 5));
  v[4] = rd32u(ext_5003d0(arr, 6));
  v[5] = rd32u(ext_5003d0(arr, 7));
  v[6] = rd32u(ext_5003d0(arr, 8));
  float f = (float)(s32)rd32u(ext_5003d0(arr, 9));
  __builtin_memcpy(&v[7], &f, 4);
  u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = vcall<u32>(msg, 0x114, edi, (u32)0, (u32)0x69ca10, (u32)0x13b, (void *)v) & 0xffff;
  vcall<void>(rdp(self + 0xc), 0x12c, v0, w);
}
PCREG(502cc0, fn502cc0);
