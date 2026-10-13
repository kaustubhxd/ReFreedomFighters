// batch76.cpp - unclaimed-68 batch 76 (slice 7). Names GUESS (FUN_addr). Exe helpers run as they are (exact ABIs noted).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);   // CRT sized delete, cdecl
extern "C" void THISCALL ext_4ba310(u8 *self);                          // initScales (exe), thiscall, plain ret
extern "C" void THISCALL ext_4cbec0(u8 *self);                          // exe, thiscall, plain ret (deletes [this] unless it points at this+4)
extern "C" u32 THISCALL ext_4e5f10(u8 *self);                           // exe, thiscall, plain ret
extern "C" void THISCALL ext_4e6420(u8 *self);                          // exe, thiscall, plain ret
extern "C" void THISCALL ext_5fd670(u8 *self, u32 a, u32 b, u32 c, u32 d);   // exe, thiscall, ret 0x10

// 0x4b9530: copies from the argument object: [this+0x4c] = [arg+0x4c]; [this+0x48] = [arg+0x48]; byte [this+0x50] = [arg+0x50];
// dword [this+0x91] = [arg+0x91]; dword [this+0x89] = [arg+0x89]; then calls 0x4ba310 on this. Plain ret after the argument (ret 4).
static void THISCALL g4b9530(u8 *self, u8 *src) {
  *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
  *(u32 *)(self + 0x48) = *(u32 *)(src + 0x48);
  self[0x50] = src[0x50];
  *(u32 *)(self + 0x91) = *(u32 *)(src + 0x91);
  *(u32 *)(self + 0x89) = *(u32 *)(src + 0x89);
  ext_4ba310(self);
}
PCREG(4b9530, g4b9530);

// 0x4cbec0: if [this] != this+4 then delete([this], 1) (cdecl). Plain ret.
static void THISCALL g4cbec0(u8 *self) {
  u32 p = *(u32 *)self;
  if (p != (u32)(self + 4)) ext_634273((void *)p, 1u);
}
PCREG(4cbec0, g4cbec0);

// 0x4d8430: vt = 0x696c14; ext_4cbec0(this+0x84); then tail-jump ext_4cbec0(this+4) (plain ret). Plain ret.
static void THISCALL g4d8430(u8 *self) {
  *(u32 *)self = 0x696c14u;
  ext_4cbec0(self + 0x84);
  ext_4cbec0(self + 4);
}
PCREG(4d8430, g4d8430);

// 0x4e5ef0: bl = (ext_4e5f10(this) != 0); ext_4e6420(this); return bl. (Both exe helpers are run as they are.)
static u8 THISCALL g4e5ef0(u8 *self) {
  u32 r = ext_4e5f10(self);
  u8 bl = (r != 0);
  ext_4e6420(self);
  return bl;
}
PCREG(4e5ef0, g4e5ef0);

// 0x5fd630 is NOT ported in this batch: the exe faults on every harness input (see docs/20-unclaimed-68.md, batch 76).
