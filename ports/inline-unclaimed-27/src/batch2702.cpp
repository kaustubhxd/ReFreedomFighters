#include "ff.h"
// batch2702.cpp - unclaimed-27 claim 2 (docs/20-unclaimed-27.md). Name from the GC name map (high).

// 0x483420, ZPlayer::EnableControls() (high). Thiscall, no arguments, void.
// Decrements the counter at this+0x606. If it is not zero, returns. Otherwise: clears bit 0x200 of the dword at +0x417,
// sets the byte at +0x600 to 1, and asks the global object (0x70039c, field +0x9b) for an object (vtable slot +0x138); on
// that object, vtable slot +0x88 (args 0x68be98 and &tmp) sets tmp. If tmp is zero, returns. Otherwise calls vtable slot
// +0x114 of the global's +0x9b object (four arguments: RegisterZMsg, ret 0x10) and passes its low 16 bits, with tmp and the
// fifth value the exe pushed (0), to this's vtable slot +0x12c (three arguments, ret 0xc).
static void THISCALL zPlayerEnableControls(u8 *self) {
  typedef u32(THISCALL * noarg_fn)(u8 *);
  typedef void(THISCALL * slot88_fn)(u8 *, u32, u32 *);
  typedef u32(THISCALL * slot114_fn)(u8 *, u32, u32, u32, u32);
  typedef void(THISCALL * slot12c_fn)(u8 *, u32, u32, u32);

  u32 count = *(u32 *)(self + 0x606) - 1u;
  *(u32 *)(self + 0x606) = count;
  if (count != 0) return;

  *(u32 *)(self + 0x417) &= 0xfffffdffu;
  // The second zero check (cmp [edi+0x606], 0) sees the same value and cannot take its jump here.
  self[0x600] = 1;

  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *g9 = *(u8 **)(g + 0x9b);
  u8 *p = (u8 *)(unsigned long)((noarg_fn)(*(u32 *)(*(u32 *)g9 + 0x138)))(g9);

  u32 tmp = 0;
  ((slot88_fn)(*(u32 *)(*(u32 *)p + 0x88)))(p, 0x68be98u, &tmp);
  if (tmp == 0) return;

  g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *obj2 = *(u8 **)(g + 0x9b);
  u32 *vt = *(u32 **)self;
  u32 ax = ((slot114_fn)(*(u32 *)(*(u32 *)obj2 + 0x114)))(obj2, 0x68bea8u, 0u, 0x68bcbcu, 0x1b3u) & 0xffffu;
  ((slot12c_fn)(vt[0x12c / 4]))(self, tmp, ax, 0u);
}
PCREG(483420, zPlayerEnableControls);
