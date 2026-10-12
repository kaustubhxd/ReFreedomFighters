// batch223.cpp - core residue 5 (decomp-pilot/core-todo/residue-05.txt). ZFFWindowCoordinator::StartPressed(int) (map name).
// A flag dispatcher on the object's bytes and dwords; calls the original helpers 0x5f0db0, 0x5f0d80, 0x5f0d30, 0x5f0ff0,
// 0x5f0c70, 0x5f0cd0 (stubbed) and two render-manager vtable calls. Names from the map where present.
#include "ff.h"

extern "C" void FASTCALL ext_5f0db0(u8 *ecx, u32 edx);   // stubbed: stores ecx, edx
extern "C" void FASTCALL ext_5f0d80(u8 *ecx, u32 edx);   // stubbed
extern "C" void THISCALL ext_5f0d30(u8 *self);            // stubbed: stores ecx
extern "C" u8 THISCALL ext_5f0ff0(u8 *self);              // stubbed: stores ecx, returns al
extern "C" u8 THISCALL ext_5f0c70(u8 *self);              // stubbed: stores ecx, returns al
extern "C" void FASTCALL ext_5f0cd0(u8 *ecx, u32 edx);   // stubbed

typedef void(THISCALL *SlotArgVoid)(u8 *, u32);

static u32 vslot8(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x5f0e10, thiscall(arg) (ret 4). self = this.
static void THISCALL dispatch_5f0e10(u8 *self, u32 arg) {
  if (self[0]) return;
  if (self[1]) return;
  if (self[2]) {
    if (*(u32 *)(self + 3) != *(u32 *)(self + 0x13)) return;
  }
  u8 *rm = G(u8 *, 0x70039c);
  u8 *o1 = *(u8 **)(rm + 0x9b);
  ((SlotArgVoid)vslot8(o1, 0xb4))(o1, 1);
  u8 *o2 = *(u8 **)(rm + 0x1a9f);
  if (o2) ((SlotArgVoid)vslot8(o2, 0x138))(o2, 1);
  u8 *h = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c15);
  u8 flag = h[0x103f];
  u32 ecx = *(u32 *)(self + 3);
  if (ecx == 0) {
    if (flag) {
      ext_5f0db0(*(u8 **)(self + 0x17), arg - 1);
      ext_5f0db0(*(u8 **)(self + 0x1b), arg - 1);
      ext_5f0d80((u8 *)arg, *(u32 *)(self + 7));
    }
  } else {
    bool skip = (ecx == *(u32 *)(self + 0x13)) || (arg == *(u32 *)(self + 0x1f)) || (ecx == *(u32 *)(self + 0xb));
    if (!skip && flag) return;
    if (ext_5f0ff0((u8 *)ecx)) return;
    if (!ext_5f0c70((u8 *)*(u32 *)(self + 3))) return;
    ext_5f0cd0((u8 *)*(u32 *)(self + 3), arg);
    return;
  }
  *(u32 *)(self + 0x1f) = arg;
  ext_5f0d30((u8 *)*(u32 *)(self + 7));
}
PCREG(5f0e10, dispatch_5f0e10);
