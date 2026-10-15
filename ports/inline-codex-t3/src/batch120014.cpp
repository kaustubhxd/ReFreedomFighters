#include "ff.h"
static void THISCALL f572720(u8 *self) {
  s32 cnt = *(s32 *)(self + 0x85c);
  if (*(s32 *)(self + 0x860) >= cnt) {
    vcall<void>(*(void **)(self + 0x872), 0xbc, 1u);
    void *w = *(void **)(self + 0x876);
    if (w) vcall<void>(w, 0xbc, 1u);
    self[0x86c] = 0;
    if (*(u32 *)(self + 0x86e))
      vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)(self + 0x86e), (u32) * (u16 *)(self + 0x4c), 0u);
    return;
  }
  if (self[*(s32 *)(self + 0x860) + 0x5c]) {
    while (*(s32 *)(self + 0x860) < cnt) {
      s32 i = ++*(s32 *)(self + 0x860);
      if (!self[i + 0x5c]) break;
    }
  }
  if (*(s32 *)(self + 0x860) >= cnt) return;
  s32 i = ++*(s32 *)(self + 0x860);
  vcall<void>(*(void **)(self + 0x872), 0x284, self + 0x5c + i);
  vcall<void>(*(void **)(self + 0x872), 0xbc, 0u);
  void *w = *(void **)(self + 0x876);
  if (w) {
    vcall<void>(w, 0x284, self + 0x5c + *(s32 *)(self + 0x860));
    vcall<void>(*(void **)(self + 0x876), 0xbc, 0u);
  }
  s32 t = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x54) * G(float, 0x67862c)));
  s32 now = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  self[0x86c] = 1;
  *(float *)(self + 0x50) = (float)(s32)((u32)now - (u32)t) * G(float, 0x6785e4);
}
PCREG(572720, f572720);
