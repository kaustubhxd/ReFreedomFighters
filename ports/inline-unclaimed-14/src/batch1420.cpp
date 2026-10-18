// batch1420.cpp - unclaimed-14 batch 20 (residue 13): ZActionPushButton::CallBack().
#include "ff.h"

// 0x467410, a large helper (ret 0x18: six stack arguments); a checksum stub in the spec.
extern "C" void THISCALL ext_467410(u8 *self, u32 a1, u32 a2, u32 s0, u32 s1, u32 s2, u32 s3);

// 0x486190, ZActionPushButton::CallBack() (high): thiscall, no arguments, plain ret, returns al = 0. Calls the object at
// this+8's vtable slot +0x2d0 with (3, 0), then 0x467410 with this = [this+0x10]+4, arguments ([this+0xc], 0.3f, and the
// four dwords 0, 0, 0, -1 from a local). The PC pushes an unused register value and then overwrites it with 0.3f.
static u8 THISCALL actionPushButtonCallBack(u8 *self) {
  typedef u32(THISCALL * vt_t)(u8 *, u32, u32);
  u8 *obj = *(u8 **)(self + 8);
  (void)(*(vt_t *)(*(u32 *)obj + 0x2d0))(obj, 3u, 0u);
  u8 *m = *(u8 **)(self + 0x10);
  ext_467410(m + 4, *(u32 *)(self + 0xc), 0x3e99999au, 0u, 0u, 0u, 0xffffffffu);
  return 0;
}
PCREG(486190, actionPushButtonCallBack);
