#include "ff.h"

// 0x5272d0: thiscall(this), plain ret, float result in x87 ST0.
float THISCALL fn_5272d0(u8 *self) {
  return *(float *)(self + 0x10); // m0
}
PCREG(5272d0, fn_5272d0);
