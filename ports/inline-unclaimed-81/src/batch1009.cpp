// batch1009.cpp - area 81 (residue 11 remainder), batch 1009: ZCarIf::addMethodDefinitions(list), 0x51b270, thiscall, one stack argument, ret 4.
// Ten blocks: while list+0xc is set, append function pointer FP[i] to the table at 0x701808 (count at 0x701800, limit 0x32); at the limit the exe
// calls this->vslot 0x44 with the string at 0x69f48c and then the hook at 0x7003b0 (the port mirrors that call; not exercised by the harness).
// End: list+0xc = 0, then 0x51aba0(this, list) (GUESS, stood in; claimed by area 23 as ZVehicleIf::addMethodDefinitions).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_51aba0(void *self, u32 list);   // GUESS (stood in; area 23)

static const u32 kFp[10] = {0x51b0b0, 0x51b060, 0x51b1b0, 0x51b1e0, 0x51b240, 0x51b180, 0x51b210, 0x51b110, 0x51b0e0, 0x51b120};

// 0x51b270 ZCarIf::addMethodDefinitions(list).
static void THISCALL carAddMethodDefinitions(u8 *self, u32 listArg) {
  u8 *list = (u8 *)listArg;
  for (u32 i = 0; i < 10; ++i) {
    if (!list[0xc])
      break;
    u32 n = *(u32 *)0x701800;
    if (n < 0x32) {
      ((u32 *)0x701808)[n] = kFp[i];
      *(u32 *)0x701800 = n + 1;
    } else {
      vcall<void>(self, 0x44, 0x69f48c);
      void (*hook)() = (void (*)())*(u32 *)0x7003b0;
      if (hook)
        hook();
    }
  }
  list[0xc] = 0;
  ext_51aba0(self, listArg);
}
PCREG(51b270, carAddMethodDefinitions);
