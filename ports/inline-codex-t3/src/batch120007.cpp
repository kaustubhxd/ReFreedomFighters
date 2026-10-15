#include "ff.h"
extern "C" void FASTCALL ext_4e0d40(float *,const float *,float);
static void THISCALL f45a720(u8 *self, void *buf, void *, const float *m, u32 col) {
  float sx = *(float *)(self + 0x18), sy = *(float *)(self + 0x1c), sz = *(float *)(self + 0x20);
  float len = (float)crt::sqrt((double)(sx * sx + sy * sy + sz * sz));
  float mat[12];
  ext_4e0d40(mat + 9, (float *)(*(u8 **)(self + 8) + 0x30), len);
  ext_4e0d40(mat + 6, m + 6, *(float *)(self + 0x18));
  ext_4e0d40(mat + 3, m + 3, *(float *)(self + 0x1c));
  ext_4e0d40(mat, m, *(float *)(self + 0x20));
  vcall<void>(buf, 0x30, *(u32 *)(self + 8), mat, col, 0xff);
}
PCREG(45a720, f45a720);
