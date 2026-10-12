// batch1916.cpp - unclaimed-66 batch 16: GUESS FUN_00628e50, the wrapper of the BOM dispatcher (batch 1915). cdecl(R, pos, end,
// out): returns the dispatcher with T = 0x6f4408 (a table in the exe's data), mode = 1.
#include "ff.h"

u32 bomDispatch(u32 *T, u8 *R, u32 mode, u8 *pos, u8 *end, u8 **out);

// 0x628e50, GUESS FUN_00628e50.
static u32 bomWrapper(u8 *R, u8 *pos, u8 *end, u8 **out) {
  return bomDispatch((u32 *)0x6f4408, R, 1, pos, end, out);
}
PCREG(628e50, bomWrapper);
