// batch35003.cpp - cascade s5 batch 35003: 0x51fbe0 (GUESS refresh cached state then forward it to 0x514890).
#include "ff.h"

extern "C" void THISCALL ext_51f930(u8 *self);                     // thiscall, plain ret
extern "C" void FASTCALL ext_4de040(u8 *out, u8 *src, u32 a);      // fastcall (ecx = out, edx = src), ret 4
extern "C" void THISCALL ext_514890(u8 *self, u32 a, u8 *b, u8 *c, u8 *d, u32 e, u32 f);  // thiscall, ret 0x18
typedef void(THISCALL *v1_t)(void *, void *);
typedef void(THISCALL *v2_t)(void *, void *, void *);
typedef u8(THISCALL *v0b_t)(void *);

// 0x51fbe0, thiscall, no args. 0x51f930(this); then the embedded object at +0x1684 (vtable [ebx]): slot 8(+0x166c); when slot 0xc() returns non-zero
// slot 4(+0x166c, +0x1678). Then 0x4de040(local(0x24), this+0x166c, 0) and, when [this+0x1658] is set,
// 0x514890(this, [+0x1658], this+0x16d9, local, this+0x1660, (dword at unaligned +0x16d5 != 0), 1).
static void THISCALL fn51fbe0(u8 *self) {
  u8 local[0x24];
  ext_51f930(self);
  u8 *o = self + 0x1684;
  (*(v1_t **)o)[8 / 4](o, self + 0x166c);
  if ((*(v0b_t **)o)[0xc / 4](o)) (*(v2_t **)o)[4 / 4](o, self + 0x166c, self + 0x1678);
  ext_4de040(local, self + 0x166c, 0);
  u32 c = *(u32 *)(self + 0x1658);
  if (c) {
    u32 flag = *(u32 *)(self + 0x16d5) != 0;
    ext_514890(self, c, self + 0x16d9, local, self + 0x1660, flag, 1);
  }
}
PCREG(51fbe0, fn51fbe0);
