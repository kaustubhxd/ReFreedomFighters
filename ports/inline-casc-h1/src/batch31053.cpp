#include "ff.h"

// 0x64fb70: 2 insns, thiscall: read dword from offset 0x8c and return
u32 THISCALL fn_64fb70(u8 *self) {
  return *(u32 *)(self + 0x8c);
}
PCREG(64fb70, fn_64fb70);
