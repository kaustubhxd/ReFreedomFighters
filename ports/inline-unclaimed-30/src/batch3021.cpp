// batch3021.cpp - unclaimed-30 claim 2 (residue 10): CActionController::Command(unsigned short id, void *arg) [map 0x49ff20; thiscall,
// ret 8, returns 0]. The id is compared with the word at +0x8b0 (0x49fa80 gets arg) and then with the word at +0x8b2 (0x4a1850 gets arg).
// Both callees are exe code (thiscall, one argument).
#include "ff.h"

extern "C" void THISCALL ext_49fa80(u8 *self, void *arg);   // exe code (ret 4)
extern "C" void THISCALL ext_4a1850(u8 *self, void *arg);   // exe code (ret 4)

static u32 THISCALL actionControllerCommand(u8 *self, u32 id, void *arg) {
  u16 w = (u16)id;
  if (w == *(u16 *)(self + 0x8b0)) {
    ext_49fa80(self, arg);
  } else if (w == *(u16 *)(self + 0x8b2)) {
    ext_4a1850(self, arg);
  }
  return 0;
}
PCREG(49ff20, actionControllerCommand);
