// batch72.cpp - unclaimed-68 batch 72 (slice 7): small forwarders and setters (names GUESS, FUN_addr).
#include "ff.h"

typedef u32(THISCALL *VSlot54)(u8 *self, u32 a);
typedef u32(THISCALL *VSlot1e8)(u8 *self, u32 a);
typedef u32(THISCALL *VSlot4)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *VSlot44)(u8 *self, u32 a);
extern "C" void THISCALL ext_5b9250(u8 *self);   // ret 0 (stubbed in the spec)

// 0x537a70: mov eax,[esp+4]; mov [ecx+0x5302],eax; mov al,1; ret 4
static u8 THISCALL g537a70(u8 *self, u32 a) {
  *(u32 *)(self + 0x5302) = a;
  return 1;
}
PCREG(537a70, g537a70);

// 0x64fbb0: copies the dwords this+0xb5 and this+0xb9 to the out pointer argument; ret 4
static void THISCALL g64fbb0(u8 *self, u32 *out) {
  out[0] = *(u32 *)(self + 0xb5);
  out[1] = *(u32 *)(self + 0xb9);
}
PCREG(64fbb0, g64fbb0);

// 0x4b0570: clears bit 0x40 of [this+4]; calls the argument object's slot +0x44 with [this+0x48]; returns 1 (AL); ret 4
static u8 THISCALL g4b0570(u8 *self, u8 *obj) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((VSlot44)*(u32 *)(*(u8 **)obj + 0x44))(obj, *(u32 *)(self + 0x48));
  return 1;
}
PCREG(4b0570, g4b0570);

// 0x64fcf0: returns [[this+0x14]] slot +4 called with (arg, 0); ret 4
static u32 THISCALL g64fcf0(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 0x14);
  return ((VSlot4)*(u32 *)(*(u8 **)o + 4))(o, a, 0u);
}
PCREG(64fcf0, g64fcf0);

// 0x5372f0: r = this.slot+0x54(arg); return this.slot+0x1e8(r); ret 4
static u32 THISCALL g5372f0(u8 *self, u32 a) {
  u32 r = ((VSlot54)*(u32 *)(*(u8 **)self + 0x54))(self, a);
  return ((VSlot1e8)*(u32 *)(*(u8 **)self + 0x1e8))(self, r);
}
PCREG(5372f0, g5372f0);

// 0x5b8530: if the word argument equals the word at this+0xdb, call 0x5b9250 (ecx = this); returns 0; ret 8 (a second, unused stack argument)
static u32 THISCALL g5b8530(u8 *self, u32 w, u32 extra) {
  (void)extra;
  if ((u16)w == *(u16 *)(self + 0xdb)) ext_5b9250(self);
  return 0;
}
PCREG(5b8530, g5b8530);
