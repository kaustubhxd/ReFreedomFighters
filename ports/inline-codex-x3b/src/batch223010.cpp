#include "ff.h"

// 0x526fe0: thiscall(this), plain ret, float result in x87 ST0.
float THISCALL fn_526fe0(u8 *self) {
  return *(float *)(self + 8); // m0
}
PCREG(526fe0, fn_526fe0);
