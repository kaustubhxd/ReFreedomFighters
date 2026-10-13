// batch344.cpp - 0x41e110 (gap band). No arguments, no return value. Calls the import at IAT slot 0x6763ec (tmpfile; no
// arguments; cdecl) and stores its eax to the global dword 0x6fd1a4.
#include "ff.h"

static void tmpfileToGlobal(void) {
  u32 r = ((u32(*)(void))(unsigned long)(*(u32 *)0x6763ecu))();
  *(u32 *)0x6fd1a4u = r;
}
PCREG(41e110, tmpfileToGlobal);
