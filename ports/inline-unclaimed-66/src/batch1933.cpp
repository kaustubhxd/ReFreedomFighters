// batch1933.cpp - unclaimed-66 batch 33 (gap band, GUESS name). Stdcall(X), ret 4. p = 0x5003d0(ECX = [X+4], arg 0) (another area's
// helper, hooked in the spec); then vtable +0x7c of the global object at 0x7003a4 with the dword at p as its argument.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);

// 0x50b540, GUESS FUN_0050b540.
static void STDCALL gapFnM(u8 *x) {
  u8 *p = ext_5003d0(*(u8 **)(x + 4), 0);
  u8 *obj = *(u8 **)0x7003a4;
  vcall<void>(obj, 0x7c, *(u32 *)p);
}
PCREG(50b540, gapFnM);
