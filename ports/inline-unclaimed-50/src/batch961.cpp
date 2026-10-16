// batch961.cpp - 0x508560 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one arg (a),
// ret 4, void. Has stack-cookie prologue and epilogue (NOT reproduced, tagged). Main flow: accessor 0x5003d0 on
// [a+4], test dword at [accessor result]; write flag to [this+0x18] + 0x6fe. If dword != 0, call three virtual
// methods on [this+0x18] with stack-allocated buffers.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);   // stood in (one arg, returns a pointer)

// 0x508560 (no name in the map).
static void THISCALL Apply508560(u8 *self, u8 *a) {
  void *res = ext_5003d0(FP(a, 4), 0u);
  u32 dval = U32(res, 0);
  void *obj_18 = FP(self, 0x18);
  ((u8 *)obj_18)[0x6fe] = (dval != 0) ? 1 : 0;

  if (dval != 0) {
    u8 buf1[0x34];
    u8 buf2[0x10];
    void *vt = FP(obj_18, 0);
    void (THISCALL *fn57c)(void *, u8 *, u8 *) = (void (THISCALL *)(void *, u8 *, u8 *))FP(vt, 0x57c);
    fn57c(obj_18, buf2, buf1);

    void (THISCALL *fn620)(void *, u8 *, u32, u32) = (void (THISCALL *)(void *, u8 *, u32, u32))FP(vt, 0x620);
    fn620(obj_18, buf2, 1u, 1u);

    void (THISCALL *fn578)(void *, u8 *, u8 *) = (void (THISCALL *)(void *, u8 *, u8 *))FP(vt, 0x578);
    fn578(obj_18, buf2, buf1);
  }
}
PCREG(508560, Apply508560);
