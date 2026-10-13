// batch4026.cpp - area 70 (slice 4/5), batch 4026: 0x4d9590 (name GUESS). SEH frame not reproduced: the exe pushes an
// exception frame (fs:[0], handler 0x669740, cookie check against 0x6f5630) around the body; the port has the same calls
// without that frame. The body: obj = render manager (engine global 0x70039c, +0x9b) +8; if byte [arg+0x59] is zero call
// slot 0x18 of obj with arg, else slot 0x20.
#include "ff.h"

// 0x4d9590 (name GUESS): plain ret, one argument at [ebp+8] (cdecl; the callee pushes it again for the virtual call and the
// virtual callee pops it).
static void cdecl4d9590(void *arg) {
  u8 *sys = G(u8 *, 0x70039c);
  void *rm = *(void **)(sys + 0x9b);
  void *obj = *(void **)((u8 *)rm + 8);
  if (((u8 *)arg)[0x59] == 0) vcall<void>(obj, 0x18, arg);
  else vcall<void>(obj, 0x20, arg);
}
PCREG(4d9590, cdecl4d9590);
