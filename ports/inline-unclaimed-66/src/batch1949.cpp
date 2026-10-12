// batch1949.cpp - unclaimed-66 batches 50 to 52 (gap band, GUESS names). Three release routines of one shape: STDCALL with one argument it
// does not read (ret 4). memset(buffer, 0, 0xc8) through the CRT at 0x634d10 (cdecl, bound to the exe code); the pointer at the flag word is
// cleared; if the object is set, vtable +0 is called with 1 (a scalar deleting destructor); then the object pointer is cleared.
#include "ff.h"

extern "C" void *ext_634d10(void *dst, int c, u32 n);  // CRT memset (cdecl), bound to the exe code

// 0x50b4d0, GUESS FUN_0050b4d0 (batch 50): buffer 0x701200, flag 0x7011f8, object 0x7011fc.
static void STDCALL gapRel50b4d0(u32 unused) {
  (void)unused;
  ext_634d10((void *)0x701200, 0, 0xc8);
  u8 *g = *(u8 **)0x7011fc;
  *(u32 *)0x7011f8 = 0;
  if (g) vcall<void>(g, 0, (u32)1);
  *(u32 *)0x7011fc = 0;
}
PCREG(50b4d0, gapRel50b4d0);

// 0x510b90, GUESS FUN_00510b90 (batch 51): buffer 0x7013a0, flag 0x701398, object 0x70139c.
static void STDCALL gapRel510b90(u32 unused) {
  (void)unused;
  ext_634d10((void *)0x7013a0, 0, 0xc8);
  u8 *g = *(u8 **)0x70139c;
  *(u32 *)0x701398 = 0;
  if (g) vcall<void>(g, 0, (u32)1);
  *(u32 *)0x70139c = 0;
}
PCREG(510b90, gapRel510b90);

// 0x511720, GUESS FUN_00511720 (batch 52): buffer 0x7014b8, flag 0x7014b0, object 0x7014b4.
static void STDCALL gapRel511720(u32 unused) {
  (void)unused;
  ext_634d10((void *)0x7014b8, 0, 0xc8);
  u8 *g = *(u8 **)0x7014b4;
  *(u32 *)0x7014b0 = 0;
  if (g) vcall<void>(g, 0, (u32)1);
  *(u32 *)0x7014b4 = 0;
}
PCREG(511720, gapRel511720);
