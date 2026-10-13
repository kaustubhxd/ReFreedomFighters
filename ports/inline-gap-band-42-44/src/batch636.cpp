// batch636.cpp - band 0x421000-0x441000, batch 636: one function.
//   0x43e700 (thiscall, three args ret 0xc): tests byte [this+0x18] & 0x8;
//     if set: calls vtable[0x74] with (arg1, arg2), then copies three dwords from *arg3
//     to this+0x28/+0x2c/+0x30, then calls exe 0x4690b0([this+0x8]). Returns void.
#include "ff.h"

typedef void(THISCALL *vslot74_t)(void *self, u32 arg1, u32 arg2);
typedef void(*ext_4690b0_t)(void *arg);

static void THISCALL modifyBox(u8 *self, u32 arg1, u32 arg2, u32 *arg3, u32 arg4) {
  if ((self[0x18] & 0x8) == 0)
    return;

  void **vtable = *(void ***)self;
  ((vslot74_t)vtable[0x74 / 4])(self, arg1, arg2);

  // Copy three dwords from arg3 to self+0x28/+0x2c/+0x30
  *(u32 *)(self + 0x28) = arg3[0];
  *(u32 *)(self + 0x2c) = arg3[1];
  *(u32 *)(self + 0x30) = arg3[2];

  // Call exe function with [this+0x8]
  void *member = *(void **)(self + 0x8);
  ext_4690b0_t ext_fn = (ext_4690b0_t)G(void *, 0x4690b0);
  ext_fn(member);
}
PCREG(43e700, modifyBox);
