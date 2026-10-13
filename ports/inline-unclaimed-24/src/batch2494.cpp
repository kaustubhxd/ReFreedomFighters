// batch2494.cpp - decomp area 24, batch 2494 (residue 3, smallest first).
#include "ff.h"

typedef u32(STDCALL *queryFn)(void *self, void *iid, void *out);  // COM-style slot 0, this pushed as the first stack argument

// 0x54e370 (GUESS name). Clears a block of fields (the loop writes the dwords at +0x1e + 4k and +0x26 + 4k with k < count, reading the
// count at +0x37 on every pass); copies +0x47 to +0x14 and +0x33 to +0x43; clears the rest. Ends with bytes +0x1c and +0x5a = 0.
static void THISCALL resetFields(u8 *self) {
  *(u32 *)(self + 0x14) = *(u32 *)(self + 0x47);
  *(u32 *)(self + 0x18) = 0;
  *(u8 *)(self + 0x59) = 0;
  u32 e = *(u32 *)(self + 0x33);
  *(u32 *)(self + 0x43) = e;
  *(u32 *)(self + 0x5b) = 0;
  *(u32 *)(self + 0x63) = 0;
  *(u32 *)(self + 0x5f) = 0;
  *(u32 *)(self + 0x2e) = 0;
  *(u32 *)(self + 0x67) = 0;
  *(u8 *)(self + 0x32) = 0;
  u8 *p = self + 0x1e;
  for (int i = 0; i < *(int *)(self + 0x37); i++) {
    *(u32 *)(p + 8) = 0;
    p += 4;
    *(u32 *)(p - 4) = 0;
  }
  *(u8 *)(self + 0x1c) = 0;
  *(u8 *)(self + 0x5a) = 0;
}
PCREG(54e370, resetFields);

// 0x4c2730 (GUESS name). Clears bit 0x40 of +4; on the argument object: slot 0x40 with the word at +0x48, slot 0x3c with the dword at
// +0x4a, slot 0x3c with the dword at +0x52, slot 0x4c with the float at +0x56. Returns 1.
static u8 THISCALL guessArgCalls(u8 *self, u8 *obj) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(obj, 0x40, (u32)*(u16 *)(self + 0x48));
  vcall<void>(obj, 0x3c, *(u32 *)(self + 0x4a));
  vcall<void>(obj, 0x3c, *(u32 *)(self + 0x52));
  vcall<void>(obj, 0x4c, *(float *)(self + 0x56));
  return 1;
}
PCREG(4c2730, guessArgCalls);

// 0x54ed70 (GUESS name). Calls slot 0 of the argument (COM-style, this pushed, IID 0x6be1b0, out = this+4). A negative HRESULT returns 0;
// otherwise, when the flag's low byte is set, slot 0x10 of this runs; returns 1.
static u32 THISCALL queryAndNotify(u8 *self, u8 *arg, u32 flag) {
  void **vt = *(void ***)arg;
  u32 hr = ((queryFn)vt[0])(arg, (void *)0x6be1b0u, self + 4);
  if ((int)hr < 0)
    return 0;
  if ((u8)flag)
    vcall<void>(self, 0x10);
  return 1;
}
PCREG(54ed70, queryAndNotify);
