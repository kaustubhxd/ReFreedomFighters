// batch33008.cpp - cascade h3: one small 2-instruction setter function
#include "ff.h"

// 0x655a70: set dword at offset 0 (vtable write)
static void THISCALL fn655a70(u8 *self) {
  *(u32 *)self = 0x6c3be4;
}
PCREG(655a70, fn655a70);
