// batch6207.cpp - unclaimed-62 claim 4 (slice 1): two functions (0x4c4f10 is blocked: see docs/20-unclaimed-62.md).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)

typedef void (*reportVarFn)(void *, const char *, ...);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static void wrf(u8 *p, float f) { __builtin_memcpy(p, &f, 4); }

// 0x507e50 (ret 4, argument x): the element of x's array (x+4 via 0x5003d0, index 0) gives a value by its tag byte +4: 3 -> the dword
// at the element; 4 -> slot 0x34 of the object the element points to; anything else reports line 0x111 (format 0x69c6b0, text 0x69c9b0),
// calls the assert hook and gives 0. The value goes to this+0x18's slot 0x5c0 (with 0), and that result to slot 0x5ac.
static void THISCALL fn507e50(u8 *self, u8 *x) {
  u8 *elem = ext_5003d0(rdp(x + 4), 0);
  u8 tag = elem[4];
  u32 v;
  if (tag == 3) {
    v = rd32u(elem);
  } else if (tag == 4) {
    u8 *obj = rdp(elem);
    v = vcall<u32>(obj, 0x34);
  } else {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x111);
    (*(reportVarFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c9b0);
    typedef void (*hookfn)();
    hookfn h = G(hookfn, 0x7003b0);
    if (h) h();
    else __builtin_debugtrap();
    v = 0;
  }
  u8 *sub = rdp(self + 0x18);
  u32 r0 = vcall<u32>(sub, 0x5c0, v, (u32)0);
  vcall<void>(sub, 0x5ac, r0);
}
PCREG(507e50, fn507e50);

// 0x523650 CMoveAlongPath::InitSplineVal(float f) (ret 4): stores f at +4; 0 sets +0x42 = 1.0f and +0x20 = 1.0f; 1 sets +0x42 = 0 and
// +0x20 = -1.0f; any other value reports line 0xaa (format 0x6a07b0 with f as a double). Then slot 0x20 of this gets f, and +0x24, +0x28,
// +0x35, +0x39 (dwords) and +0x46, +0x34 (bytes) are cleared.
static void THISCALL fn523650(u8 *self, float f) {
  wrf(self + 4, f);
  if (f == 0.0f) {
    wr32u(self + 0x42, 0x3f800000u);
    wr32u(self + 0x20, 0x3f800000u);
  } else if (f == 1.0f) {
    wr32u(self + 0x42, 0);
    wr32u(self + 0x20, 0xbf800000u);
  } else {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x6a0778, 0xaa);
    typedef void (*reportDblFn)(void *, const char *, double);
    ((reportDblFn)(*(void **)(*(u8 **)r + 0x2c)))(r, (const char *)0x6a07b0, (double)f);
  }
  vcall<void>(self, 0x20, f);
  wr32u(self + 0x24, 0);
  wr32u(self + 0x28, 0);
  wr32u(self + 0x35, 0);
  wr32u(self + 0x39, 0);
  self[0x46] = 0;
  self[0x34] = 0;
}
PCREG(523650, fn523650);
