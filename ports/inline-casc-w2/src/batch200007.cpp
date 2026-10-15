// batch200007.cpp - Sonnet-w2, SEH-framed ctor / deleting-dtor shapes (fourth set).
#include "ff.h"

extern "C" u32 THISCALL ext_469870(void *self);
extern "C" u32 THISCALL ext_4de7a0(void *self);
extern "C" u32 THISCALL ext_659c00(void *self);
extern "C" u32 THISCALL ext_659bb0(void *self);
extern "C" u32 THISCALL ext_4cbe80(void *self, u32 arg);
extern "C" u32 ext_634273(void *p, u32 size);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x4be090 GUESS ctor_flagged_b: thiscall, handler 0x66c468. 0x469870(this) at state -1; [this+4]|=0x20; [this+0x44]=0; state 0; [this]=0x693858;
// unaligned dwords +0x6d, +0x69, +0x91, +0x89 = 0; 0x4de7a0(this+0xad). Returns this.
extern "C" u8 *THISCALL ctor_flagged_b(u8 *self) {
  SEH_ENTER(0x66c468);
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  reg.state = 0;
  *(u32 *)self = 0x693858;
  u32 z = 0;
  __builtin_memcpy(self + 0x6d, &z, 4);
  __builtin_memcpy(self + 0x69, &z, 4);
  __builtin_memcpy(self + 0x91, &z, 4);
  __builtin_memcpy(self + 0x89, &z, 4);
  ext_4de7a0(self + 0xad);
  SEH_LEAVE();
  return self;
}
PCREG(4be090, ctor_flagged_b);

// 0x616aa0 GUESS deleting_dtor_30: thiscall(flags), ret 4, handler 0x665fd6, state 0. [this]=0x6bdd28; 0x659c00(this+0x24); 0x659bb0(this+0xc);
// [this]=0x6bdc40; if flags&1 cdecl free 0x634273(this, 0x30). Returns this.
extern "C" u8 *THISCALL deleting_dtor_30(u8 *self, u32 flags) {
  SEH_ENTER(0x665fd6);
  reg.state = 0;
  *(u32 *)self = 0x6bdd28;
  ext_659c00(self + 0x24);
  ext_659bb0(self + 0xc);
  *(u32 *)self = 0x6bdc40;
  if (flags & 1) ext_634273(self, 0x30);
  SEH_LEAVE();
  return self;
}
PCREG(616aa0, deleting_dtor_30);

// 0x4d8330 / 0x4d83b0 GUESS ctor_three_args_a/b: thiscall(a, b, c), ret 0xc, handler 0x66966b. [this]=0x696c14; 0x4cbe80(this+4, a) at state -1; state 0;
// 0x4cbe80(this+0x84, b); [this+0x104]=c; [this]=final vtable (0x696c2c / 0x696c44). Returns this.
extern "C" u8 *THISCALL ctor_three_args_a(u8 *self, u32 a, u32 b, u32 c) {
  SEH_ENTER(0x66966b);
  *(u32 *)self = 0x696c14;
  ext_4cbe80(self + 4, a);
  reg.state = 0;
  ext_4cbe80(self + 0x84, b);
  *(u32 *)(self + 0x104) = c;
  *(u32 *)self = 0x696c2c;
  SEH_LEAVE();
  return self;
}
PCREG(4d8330, ctor_three_args_a);

extern "C" u8 *THISCALL ctor_three_args_b(u8 *self, u32 a, u32 b, u32 c) {
  SEH_ENTER(0x66966b);
  *(u32 *)self = 0x696c14;
  ext_4cbe80(self + 4, a);
  reg.state = 0;
  ext_4cbe80(self + 0x84, b);
  *(u32 *)(self + 0x104) = c;
  *(u32 *)self = 0x696c44;
  SEH_LEAVE();
  return self;
}
PCREG(4d83b0, ctor_three_args_b);

// 0x4a3360 GUESS dtor_register_b: thiscall, handler 0x665fd6. [this]=0x68fadc; cdecl free 0x634273([this+0x48], 0xa) at state -1; clears +0x44, +0x30;
// [this]=0x686874; state 0; slot 0x34 of [engine+0x9b] with this; returns its eax.
extern "C" u32 THISCALL dtor_register_b(u8 *self) {
  SEH_ENTER(0x665fd6);
  *(u32 *)self = 0x68fadc;
  ext_634273(*(void **)(self + 0x48), 0xa);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  void *t = *(void **)((u8 *)g_pSysInterface + 0x9b);
  reg.state = 0;
  u32 r = vcall<u32>(t, 0x34, self);
  SEH_LEAVE();
  return r;
}
PCREG(4a3360, dtor_register_b);

// 0x608220 / 0x608290 GUESS deleting_dtor_peer_a/b: thiscall(flags), ret 4, handler 0x665fd6, state 0. [this]=vt1; o=[this+off]; calls slot 8 of o's vtable
// with ECX = this (not o) and o as the one stack argument (callee pops it); [this]=vt2; if flags&1 cdecl free 0x634273(this, size). Returns this.
typedef u32(THISCALL *SelfFn)(void *, void *);
extern "C" u8 *THISCALL deleting_dtor_peer_a(u8 *self, u32 flags) {
  SEH_ENTER(0x665fd6);
  u8 *o = *(u8 **)(self + 0x14);
  *(u32 *)self = 0x6bc8ac;
  reg.state = 0;
  SelfFn f = *(SelfFn *)(*(u8 **)o + 8);
  f(self, o);
  *(u32 *)self = 0x6bc88c;
  if (flags & 1) ext_634273(self, 0x1c);
  SEH_LEAVE();
  return self;
}
PCREG(608220, deleting_dtor_peer_a);

extern "C" u8 *THISCALL deleting_dtor_peer_b(u8 *self, u32 flags) {
  SEH_ENTER(0x665fd6);
  u8 *o = *(u8 **)(self + 0x2c);
  *(u32 *)self = 0x6bc89c;
  reg.state = 0;
  SelfFn f = *(SelfFn *)(*(u8 **)o + 8);
  f(self, o);
  *(u32 *)self = 0x6bc884;
  if (flags & 1) ext_634273(self, 0x34);
  SEH_LEAVE();
  return self;
}
PCREG(608290, deleting_dtor_peer_b);
