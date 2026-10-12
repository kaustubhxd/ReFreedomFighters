// batch263.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

typedef u32 (THISCALL *F1)(u8 *self, u32 a);
typedef void (THISCALL *V1)(u8 *self, u32 a);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f2c20, thiscall, ret 4: this+8 += arg.
static void THISCALL addToPlus8(u8 *self, u32 a) { *(u32 *)(self + 8) += a; }
PCREG(5f2c20, addToPlus8);

// 0x4f3fe0, thiscall, ret 8 (two stack arguments, callee-cleaned): calls slot 0xbc of this with argument 0 (ECX = this),
// ignores the result and returns 0 (al).
static u8 THISCALL callSlotBc(u8 *self, u32 a, u32 b) {
  (void)a; (void)b;
  ((V1)rdw(rdw((u32)(unsigned long)self, 0), 0xbc))(self, 0);
  return 0;
}
PCREG(4f3fe0, callSlotBc);

// 0x4bcc20, thiscall, ret 4: stores the byte argument at this+0xd0.
static void THISCALL setByteD0(u8 *self, u32 a) { self[0xd0] = (u8)a; }
PCREG(4bcc20, setByteD0);

// 0x460e20, fastcall (ECX = destination, EDX = source), plain ret: copies three dwords.
static void FASTCALL copy12(u8 *dst, u8 *src) {
  *(u32 *)(dst + 0) = *(u32 *)(src + 0);
  *(u32 *)(dst + 4) = *(u32 *)(src + 4);
  *(u32 *)(dst + 8) = *(u32 *)(src + 8);
}
PCREG(460e20, copy12);

// 0x61bc60, cdecl (plain ret, the caller removes both arguments): ECX = first argument, calls slot 0x28 of it with the
// second argument.
static void __attribute__((cdecl)) callSlot28(u32 obj, u32 a) {
  ((V1)rdw(rdw(obj, 0), 0x28))((u8 *)(unsigned long)obj, a);
}
PCREG(61bc60, callSlot28);
