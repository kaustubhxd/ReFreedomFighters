// batch6312.cpp - unclaimed-63 batch 12 (docs/20-unclaimed-63.md): ZGEOM::ChkFaceLineColi(const COLI*, const STempStripsUniqueId*)
// at 0x45d320 (GC name, high). Stdcall (ret 8; ECX is not used). A local float L = 1.0 is passed by address to the render-
// manager collision object M = [[[0x70039c]+0x1aa3]+0x1c] through M->vtbl[+0x60] with six stack arguments, caller-pushed in the
// order -1, byte [coli+0x6c], coli+0xc, coli, ids, &L (so &L is the first argument); the callee pops 24. The result of the
// call is returned. The PC's /GS cookie check (0x633654) is not reproduced: it only aborts on a corrupted frame.
#include "ff.h"

typedef u32(THISCALL * call6_fn)(void *, u32, u32, u32, u32, u32, u32);

// 0x45d320, ZGEOM::ChkFaceLineColi(const COLI*, const STempStripsUniqueId*) (high).
static u32 STDCALL geomChkFaceLineColi(u8 *coli, u8 *ids) {
  float L = 1.0f;
  u32 rm = G(u32, 0x70039c);
  u32 obj = *(u32 *)(rm + 0x1aa3);
  u32 m = *(u32 *)(obj + 0x1c);
  u32 flag = coli[0x6c];
  return ((call6_fn)(*(u32 *)(*(u32 *)m + 0x60)))((void *)m, (u32)&L, (u32)ids, (u32)coli, (u32)(coli + 0xc), flag, 0xffffffffu);
}
PCREG(45d320, geomChkFaceLineColi);
