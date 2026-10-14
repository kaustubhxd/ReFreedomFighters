// batch1018.cpp - unclaimed-10, batch 14 (docs/20-unclaimed-10.md): ZDamageBox2::CopyData(ZEventBase*) (0x5db910), thiscall,
// one argument (the source), ret 4. If the source's child (+0x48) is set: its slot +0x4c is called with the address of a local
// dword (tmp), then its slot +0x5c with the same address (returns r); while tmp is non-zero, this's child slot +4 is called
// with r and the source child's slot +0x5c is called again. Then the fields are copied (dword +0x4c, +0x50, byte +0x54, word
// +0x55, dwords +0x87, +0x8b, +0x8f, +0x93, +0x97, +0x9b), and this+0x63 is set from this+0x4c: 1 when it is 0, 0 when it is 1,
// unchanged otherwise. The child slots are unverified virtual callees and are stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotOut)(u8 *self, u32 *out);            // vt[+0x4c](&tmp)
typedef u32(THISCALL *SlotOutRet)(u8 *self, u32 *out);          // vt[+0x5c](&tmp), returns eax
typedef void(THISCALL *Slot4)(u8 *self, u32 a);                 // vt[+4](r)

// 0x5db910, ZDamageBox2::CopyData(ZEventBase*) (high)
static void THISCALL damageBox2CopyData(u8 *self, u8 *src) {
  u32 tmp = 0;
  if (*(u8 **)(src + 0x48)) {
    ((SlotOut)VT(*(u8 **)(src + 0x48))[0x4c / 4])(*(u8 **)(src + 0x48), &tmp);
    u32 r = ((SlotOutRet)VT(*(u8 **)(src + 0x48))[0x5c / 4])(*(u8 **)(src + 0x48), &tmp);
    if (tmp) {
      do {
        u8 *child = *(u8 **)(self + 0x48);
        ((Slot4)VT(child)[0x4 / 4])(child, r);
        r = ((SlotOutRet)VT(*(u8 **)(src + 0x48))[0x5c / 4])(*(u8 **)(src + 0x48), &tmp);
      } while (tmp);
    }
  }
  *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
  *(u32 *)(self + 0x50) = *(u32 *)(src + 0x50);
  self[0x54] = src[0x54];
  *(u16 *)(self + 0x55) = *(u16 *)(src + 0x55);
  *(u32 *)(self + 0x87) = *(u32 *)(src + 0x87);
  *(u32 *)(self + 0x8b) = *(u32 *)(src + 0x8b);
  *(u32 *)(self + 0x8f) = *(u32 *)(src + 0x8f);
  *(u32 *)(self + 0x93) = *(u32 *)(src + 0x93);
  *(u32 *)(self + 0x97) = *(u32 *)(src + 0x97);
  *(u32 *)(self + 0x9b) = *(u32 *)(src + 0x9b);
  u32 kind = *(u32 *)(self + 0x4c);
  if (kind == 0) *(u32 *)(self + 0x63) = 1;
  else if (kind == 1) *(u32 *)(self + 0x63) = 0;
}
PCREG(5db910, damageBox2CopyData);
