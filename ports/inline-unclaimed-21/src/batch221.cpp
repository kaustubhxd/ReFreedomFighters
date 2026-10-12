// batch221.cpp - core residue 0. CHitpointControl::Init (map name, GUESS). Appends this to a global list when [this+0x63]
// is set; stores the render-manager child's vt[0x4c](this+0x44) result into the list's buffer (or calls the original
// 0x4301c0 when the buffer is full); copies [this+0x48] to [this+0x64]; calls vt[0xbc](obj, 1) of [this+0x44] when
// [this+0x56] is set. Names GUESS.
#include "ff.h"

extern "C" void STDCALL ext_4301c0(u32 edx, u32 *local);   // original, stdcall two words (stubbed in the harness)

typedef u32(THISCALL *SlotArgRet)(u8 *, u32);   // vtable slot, one stack word, eax result
typedef void(THISCALL *SlotArgVoid)(u8 *, u32); // vtable slot, one stack word, no result used

static u32 vslot7(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void THISCALL hitpointInit_584580(u8 *self) {
  if (self[0x63]) {
    u8 *list = G(u8 *, 0x7003b8);
    u32 cnt = *(u32 *)(list + 0xb61);
    *(u32 *)(list + cnt * 4 + 0xb65) = (u32)self;
    *(u32 *)(list + 0xb61) = cnt + 1;
  }
  u8 *rm = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(rm + 0x9b);
  u32 v = ((SlotArgRet)vslot7(obj, 0x4c))(obj, *(u32 *)(self + 0x44));
  u8 *ctr = G(u8 *, 0x7003b8) + 0x4a0;
  u32 local = v;
  u32 buf = *(u32 *)(ctr + 4);
  if (buf == *(u32 *)(ctr + 8)) {
    ext_4301c0(buf, &local);
  } else {
    if (buf) *(u32 *)buf = v;
    *(u32 *)(ctr + 4) = buf + 4;
  }
  *(u32 *)(self + 0x64) = *(u32 *)(self + 0x48);
  if (self[0x56]) {
    u8 *o = *(u8 **)(self + 0x44);
    ((SlotArgVoid)vslot7(o, 0xbc))(o, 1);
  }
}
PCREG(584580, hitpointInit_584580);
