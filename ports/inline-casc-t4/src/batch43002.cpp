// batch43002.cpp - t4 () batch 43002: tier H float/SSE functions
#include "ff.h"

extern "C" void ext_42abee(u8 *buf, u32 fmt, u32 *va);   // cdecl: format into buf

#define SYS (*(u8 **)0x70039c)

// 0x585350, fastcall(first, last, a, b) ret 8, returns a pointer: lower bound over records of 0x48 bytes with the float key at +0x10:
// count = (last - first) / 0x48 (signed); while count > 0: half = count >> 1, mid = first + half * 0x48;
// key(a) > key(mid) (ordered) -> first = mid + 0x48, count -= half + 1; otherwise count = half
static u8 *__attribute__((fastcall)) fn585350(u8 *first, u8 *last, u8 *a, u32 b) {
  (void)b;
  s32 count = (s32)((u32)last - (u32)first) / 0x48;
  while (count > 0) {
    s32 half = count >> 1;
    u8 *mid = first + half * 0x48;
    if (*(float *)(a + 0x10) > *(float *)(mid + 0x10)) {
      first = mid + 0x48;
      count -= half + 1;
    } else {
      count = half;
    }
  }
  return first;
}
PCREG(585350, fn585350);

// 0x6511d0, thiscall bool, no args: o = sys->slot 0x1b0(); o != 0 and o->slot 0xc() (al) != 0 -> false; [sys+0x9c7] (float, unaligned) == 0 -> false;
// [this+0x74] == 0 -> false; true when [sys+0x9c3] (float, unaligned) != 0 (NaN counts as not zero)
static bool THISCALL fn6511d0(u8 *self) {
  u8 *o = vcall<u8 *>(SYS, 0x1b0);
  if (o && (u8)vcall<u32>(o, 0xc)) return false;
  if (*(float *)(SYS + 0x9c7) == 0.0f) return false;
  if (!*(u32 *)(self + 0x74)) return false;
  return *(float *)(SYS + 0x9c3) != 0.0f;
}
PCREG(6511d0, fn6511d0);

// 0x4246e0, cdecl(unused, obj, a, b, fmt, ...): when [sys+0x9c7] != float at 0x6785d0 (NaN counts): vsprintf-style 0x42abee(buf[0x400], fmt, &args),
// then obj->slot 0x124 (cdecl, obj passed on the stack, caller pops): (obj, a, b, buf)
typedef void(*slot124_t)(u8 *, u32, u32, u8 *);
static void fn4246e0(u32 unused, u8 *obj, u32 a, u32 b, u32 fmt, u32 va1) {
  (void)unused;
  if (*(float *)(SYS + 0x9c7) != G(float, 0x6785d0)) {
    u8 buf[0x400];
    ext_42abee(buf, fmt, &va1);
    (*(slot124_t *)(*(u8 **)obj + 0x124))(obj, a, b, buf);
  }
}
PCREG(4246e0, fn4246e0);
