// batch215.cpp - unclaimed area 21 (docs/20-unclaimed-21.md). A guarded struct copy that calls the original 0x4de420
// (fastcall copy, runs as exe code). Name GUESS. (0x45c680 is parked in parked/batch215_45c680.cpp.txt.)
#include "ff.h"

extern "C" void FASTCALL ext_4de420(u8 *dst, u8 *src);   // original struct copy, fastcall (ecx = dst, edx = src)

typedef void(THISCALL *SlotArgVoid)(u8 *, u32);          // vtable slot, one stack word, no result used
typedef u32(THISCALL *SlotArgRet)(u8 *, u32);            // vtable slot, one stack word, eax result

static u32 vslot3(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x483780, thiscall(a, b) (ret 8): r = vtable[0x324](this, 0) (al); if (byte)r == 0: return r. Else
// ext_4de420(ecx = a, edx = this+0x24); b[0..2] = [this+0x48], [this+0x4c], [this+0x50]; returns ([this+0x50] & ~0xff) | 1
// (the exe sets al = 1 after loading [this+0x50] into eax). Name GUESS.
static u32 THISCALL copyIfReady_483780(u8 *self, u32 a, u32 *b) {
  u32 r = ((SlotArgRet)vslot3(self, 0x324))(self, 0);
  if ((u8)r == 0) return r;
  ext_4de420((u8 *)a, self + 0x24);
  b[0] = *(u32 *)(self + 0x48);
  b[1] = *(u32 *)(self + 0x4c);
  b[2] = *(u32 *)(self + 0x50);
  return (*(u32 *)(self + 0x50) & 0xffffff00u) | 1u;
}
PCREG(483780, copyIfReady_483780);
