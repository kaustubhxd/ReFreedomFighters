// batch200005.cpp - Sonnet-w2, SEH-framed ctor / deleting-dtor shapes (second set).
#include "ff.h"

extern "C" u32 THISCALL ext_469870(void *self);
extern "C" u32 THISCALL ext_4ccba0(void *self);
extern "C" u32 THISCALL ext_6132a0(void *self);
extern "C" u32 THISCALL ext_659c00(void *self);
extern "C" u32 THISCALL ext_434fb0(void *self);
extern "C" u32 THISCALL ext_4cbec0(void *self);
extern "C" u32 ext_634273(void *p, u32 size);

// 0x4fb930 GUESS ctor_flagged: thiscall, EH frame (handler 0x66c468). 0x469870(this) at state -1; [this+4] |= 0x20; [this+0x44]=0; state 0;
// [this]=0x69c4b0; 0x4ccba0(this+0x98); byte [this+0x69]=0; returns this.
extern "C" u8 *THISCALL ctor_flagged(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x66c468;
  reg.state = -1;
  seh_set_head(&reg);
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  reg.state = 0;
  *(u32 *)self = 0x69c4b0;
  ext_4ccba0(self + 0x98);
  self[0x69] = 0;
  seh_set_head(reg.next);
  return self;
}
PCREG(4fb930, ctor_flagged);

// 0x6125f0 GUESS deleting_dtor_2216c: thiscall(flags), ret 4, handler 0x665fd6, state 0. [this]=0x6bd5a0; 0x6132a0(this); [this]=0x6bd594;
// if flags&1: cdecl free 0x634273(this, 0x2216c). Returns this.
extern "C" u8 *THISCALL deleting_dtor_2216c(u8 *self, u32 flags) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x665fd6;
  reg.state = -1;
  seh_set_head(&reg);
  reg.state = 0;
  *(u32 *)self = 0x6bd5a0;
  ext_6132a0(self);
  *(u32 *)self = 0x6bd594;
  if (flags & 1) ext_634273(self, 0x2216c);
  seh_set_head(reg.next);
  return self;
}
PCREG(6125f0, deleting_dtor_2216c);

// 0x616b70 GUESS deleting_dtor_14: thiscall(flags), ret 4, handler 0x665fd6, state 0. [this]=0x6bdcf4; 0x659c00(this+8); [this]=0x6bdc38;
// if flags&1: cdecl free 0x634273(this, 0x14). Returns this.
extern "C" u8 *THISCALL deleting_dtor_14(u8 *self, u32 flags) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x665fd6;
  reg.state = -1;
  seh_set_head(&reg);
  reg.state = 0;
  *(u32 *)self = 0x6bdcf4;
  ext_659c00(self + 8);
  *(u32 *)self = 0x6bdc38;
  if (flags & 1) ext_634273(self, 0x14);
  seh_set_head(reg.next);
  return self;
}
PCREG(616b70, deleting_dtor_14);

// 0x433f30 GUESS dtor_with_owned: thiscall, handler 0x6656a0, state stays -1. [this]=0x67a3b0; 0x434fb0(this); m=[this+8]; if m: vtable slot 0 of m
// (thiscall, arg 1 = delete flag); 0x4cbec0(this+0x8c); 0x4cbec0(this+0xc). Returns the last eax.
extern "C" u32 THISCALL dtor_with_owned(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x6656a0;
  reg.state = -1;
  seh_set_head(&reg);
  *(u32 *)self = 0x67a3b0;
  ext_434fb0(self);
  void *m = *(void **)(self + 8);
  if (m) vcall<u32>(m, 0, 1);
  ext_4cbec0(self + 0x8c);
  u32 r = ext_4cbec0(self + 0xc);
  seh_set_head(reg.next);
  return r;
}
PCREG(433f30, dtor_with_owned);
