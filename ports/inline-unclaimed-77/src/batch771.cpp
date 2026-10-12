// batch771.cpp - unclaimed-77 claim 1 (docs/20-unclaimed-77.md): CMAINCAMERACONTROL::SetCrossHairMode(int, float*). Thiscall,
// two arguments, ret 8. Name from the GC name map (medium). The vtable slot 0x12c of this+0x44 is a stand-in in the harness (GUESS).
#include "ff.h"

// 0x4fda40, CMAINCAMERACONTROL::SetCrossHairMode(int, float*) (medium): a local {mode, x, y, z} from the arguments (zeros when the
// pointer is null), then the vtable slot 0x12c of the object at this+0x44 is called with ([this+0x6e] dword, [this+0x66] word
// zero-extended, &local). Thiscall, three arguments for the callee.
static void THISCALL crossHairSetMode(u8 *self, u32 mode, float *p) {
  u32 local[4];
  local[0] = mode;
  if (p) {
    local[1] = *(u32 *)&p[0];
    local[2] = *(u32 *)&p[1];
    local[3] = *(u32 *)&p[2];
  } else {
    local[1] = 0;
    local[2] = 0;
    local[3] = 0;
  }
  u8 *obj = *(u8 **)(self + 0x44);
  void **vt = *(void ***)obj;
  ((void (THISCALL *)(void *, u32, u32, u32 *))(*(void **)((u8 *)vt + 0x12c)))(obj, *(u32 *)(self + 0x6e), (u32)*(u16 *)(self + 0x66), local);
}
PCREG(4fda40, crossHairSetMode);
