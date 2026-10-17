// batch33014.cpp - cascade h3 tier B: four 5-instruction functions with complex logic
#include "ff.h"

extern "C" void THISCALL ext_4639f0(u8 *self);
extern "C" void THISCALL ext_533da0(u8 *self);

// 0x4673d0: read, write, and-clear bit, then tail jump
static void THISCALL fn4673d0(u8 *self) {
  u32 val = *(u32 *)(self + 0x136);
  *(u32 *)(self + 0x159) = val;
  *(u32 *)(self + 0x136) = val & 0xfffdffff;
  ext_4639f0(self);
}
PCREG(4673d0, fn4673d0);

// 0x47fb90: conditional vtable jump (cmp, je, load, jmp)
static void THISCALL fn47fb90(u8 *self) {
  if (*(u32 *)(self + 4) == 0) {
    return;
  }
  u8 *vt = *(u8 **)self;
  typedef void(THISCALL *vfn_t)(void *);
  (*(vfn_t *)(vt + 0x14))(self);
}
PCREG(47fb90, fn47fb90);

// 0x4bb2c0: chained reads and write
static void THISCALL fn4bb2c0(u8 *self) {
  u8 *p1 = *(u8 **)(self + 0x44);
  u8 *p2 = *(u8 **)(p1 + 0x18);
  u32 val = *(u32 *)(p2 + 0x70);
  *(u32 *)(self + 0x4e) = val;
}
PCREG(4bb2c0, fn4bb2c0);

// 0x535490: add offset to ecx, then tail jump
static void THISCALL fn535490(u8 *self) {
  ext_533da0(self + 0x109f);
}
PCREG(535490, fn535490);
