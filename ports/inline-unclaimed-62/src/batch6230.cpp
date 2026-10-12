// batch6230.cpp - unclaimed-62 claim 23 (larger, 108 instructions): 0x55afe0 [thiscall, one argument, ret 4].
// The first element of the vector at arg+8 (exe 0x5003d0) is set to 0 (exe 0x5002f0). If the list at this+0x1c+0x921 is set: its dword count c
// is followed by c objects; the count of those whose slot 0x438 returns false (no argument) is ebx. The element picked from the vector at arg+8
// by an inlined accessor (offset of the vector, with the assert hook when the offset or the count is out of range, as the exe does) gets ebx,
// state 1; a state other than 0 or 1 gets the debug report (line 0x104, format 0x69c938, text 0x69c6b0) and the assert hook first.
// The exe's stack-cookie check is not reproduced.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)
extern "C" u8 *THISCALL ext_5002f0(u8 *elem, u32 value);  // exe: element setter, state = 1 (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void assertHook55() {
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h();
  else __builtin_debugtrap();
}

static void THISCALL fn55afe0(u8 *self, u8 *x) {
  ext_5002f0(ext_5003d0(rdp(x + 8), 0), 0);
  u8 *list = rdp(rdp(self + 0x1c) + 0x921);
  u32 ebx = 0;
  if (list != 0) {
    u32 count = rd32u(list);
    for (u8 *p = list + 4; p != list + (count + 1) * 4; p += 4) {
      u8 *obj = rdp(p);
      if ((vcall<u32>(obj, 0x438) & 0xff) == 0) ebx++;
    }
  }
  // the element: the vector's offset into its header (the exe's inline accessor)
  u8 *V = rdp(x + 8);
  u8 *elem;
  if (rd32u(V + 8) != 0) {
    u32 off = rd32u(V + 4);
    u8 *hdr = rdp(V);
    if (off >= rd32u(hdr + 8)) assertHook55();
    elem = rdp(hdr) + off * 8;
  } else {
    assertHook55();
    u8 *hdr = rdp(V);
    if (rd32u(hdr + 8) == 0) assertHook55();
    elem = rdp(hdr);
  }
  u8 st = elem[4];
  if (st != 0 && st != 1) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x104);
    (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c938);
    assertHook55();
  }
  wr32u(elem, ebx);
  elem[4] = 1;
}
PCREG(55afe0, fn55afe0);
