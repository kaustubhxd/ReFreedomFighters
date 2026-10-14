// batch2902.cpp - unclaimed-29: batch 2 (docs/20-unclaimed-29.md, claim 2, slice 8). Thiscall with no stack arguments (ret).
// 0x5bef80 and the virtual slots are original code or fakes in the harness; the port calls them through ext_/function pointers.
#include "ff.h"

// 0x5bef80: thiscall on the object with six stack arguments (ret 0x18); its name is not in the name map (original code here).
extern "C" void THISCALL ext_5bef80(u8 *self, u32 a0, u32 a1, float a2, u32 a3, u32 a4, u32 a5);

typedef u8 *(THISCALL *ObjFn)(u8 *self, u32 a);

// 0x5bdcc0, CCivilianPath::Init2() (high): obj = [global 0x70039c]+0x9b; o = obj's slot +0x58 with the dword at +0x59; when o is
// not null, r = o's slot +0x100 with 0x6b3538; when r is not null, 0x5bef80 is called on r with: dword +0x44, dword +0x48, float
// +0x54, (dword +0x4c != 0), (dword +0x50 != 0) and the byte +0x58.
static void THISCALL civilianPathInit2(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(rm + 0x9b);
  const u32 vtA = *(const u32 *)obj;
  u8 *o = ((ObjFn)(*(const u32 *)(vtA + 0x58)))(obj, *(const u32 *)(self + 0x59));
  if (!o) return;
  const u32 vtO = *(const u32 *)o;
  u8 *r = ((ObjFn)(*(const u32 *)(vtO + 0x100)))(o, 0x6b3538);
  if (!r) return;
  ext_5bef80(r, *(const u32 *)(self + 0x44), *(const u32 *)(self + 0x48), *(const float *)(self + 0x54),
             *(const u32 *)(self + 0x4c) != 0, *(const u32 *)(self + 0x50) != 0, self[0x58]);
}
PCREG(5bdcc0, civilianPathInit2);
