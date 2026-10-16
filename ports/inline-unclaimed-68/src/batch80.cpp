// batch80.cpp - unclaimed-68 batch 80 (slice 7). Names GUESS (FUN_addr). Exe callees are hooked by address in the spec.
#include "ff.h"

typedef void(THISCALL *VSlot)(u8 *self, u32 arg);
typedef u32(THISCALL *VSlot2)(u8 *self, u32 arg1, u32 arg2);

// 0x57bc70: conditional vtable call based on state field and argument.
// Reads this+0xc82; if (state == 0xa || state == 0x11) and arg == 0xd05, or state == 0x20, call vtable slot +0xd0 with arg at +0xcae.
static void THISCALL g57bc70(u8 *self, u32 arg) {
  u32 state = *(u32 *)(self + 0xc82);
  if (((state == 0xa || state == 0x11) && arg == 0xd05) || state == 0x20) {
    u8 *vt = *(u8 **)self;
    u32 slot_arg = *(u32 *)(self + 0xcae);
    ((VSlot)*(u32 *)(vt + 0xd0))(self, slot_arg);
  }
}
PCREG(57bc70, g57bc70);

// 0x48b4f0: stdcall, two stack arguments, ret 8.
// Gets engine vtable from [0x700390]; calls slot +0x20 with args 0x68d798, 0x1420 (thiscall).
// Treats result as object, calls its slot +0x2c with args result, 0x68e17c (thiscall, ret 8).
// Then checks hook at [0x7003b0]; calls it if non-null. Always returns 0.
static u32 STDCALL g48b4f0(u32 arg1, u32 arg2) {
  u8 *eng_vt = G(u8 *, 0x700390);
  // Call engine vtable slot +0x20 with this=eng_vt, args 0x68d798, 0x1420
  u32 result = ((VSlot2)*(u32 *)(eng_vt + 0x20))(eng_vt, 0x68d798, 0x1420);

  // The result is an object with a vtable. Call its slot +0x2c with args result, 0x68e17c.
  u8 *obj = (u8 *)result;
  u8 *obj_vt = *(u8 **)obj;
  ((VSlot)*(u32 *)(obj_vt + 0x2c))(obj, 0x68e17c);

  // Check hook at [0x7003b0] and call if non-null
  u32 hook = G(u32, 0x7003b0);
  if (hook) {
    ((void (STDCALL *)())hook)();
  }
  return 0;
}
PCREG(48b4f0, g48b4f0);
