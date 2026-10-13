// batch 102: residue 6 setter 0x521760
#include "ff.h"

// 0x521760: thiscall, one stack argument (ret 4)
// Sets [this+0x133]=arg and [this+0x24ca]=arg
static void THISCALL guess521760(void *self, u8 arg) {
  *(u8 *)((u8 *)self + 0x133) = arg;
  *(u8 *)((u8 *)self + 0x24ca) = arg;
}
PCREG(521760, guess521760);
