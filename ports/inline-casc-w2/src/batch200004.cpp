// batch200004.cpp - Sonnet-w2, SEH-framed constructor / deleting-destructor shaped functions.
#include "ff.h"

extern "C" u32 THISCALL ext_49a3e0(void *self);
extern "C" u32 ext_634273(void *p, u32 size);
extern "C" u32 THISCALL ext_4d8e60(void *self);
extern "C" u32 THISCALL ext_4e7e80(void *self);
extern "C" u32 THISCALL ext_4cbe80(void *self, u32 arg);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x565870 GUESS init_and_register_b: thiscall. As 0x4f6b20 plus [this+0x180] = 0x6a6c0c: clears +0x44, +0x30, [this]=0x686874,
// then (state 0) calls slot 0x34 of [engine+0x9b] with this. Handler 0x6684b6. Returns its eax.
extern "C" u32 THISCALL init_and_register_b(u8 *self) {
  SEH_ENTER(0x6684b6);
  *(u32 *)(self + 0x180) = 0x6a6c0c;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  void *t = *(void **)((u8 *)g_pSysInterface + 0x9b);
  reg.state = 0;
  u32 r = vcall<u32>(t, 0x34, self);
  SEH_LEAVE();
  return r;
}
PCREG(565870, init_and_register_b);

// 0x499d50 GUESS deleting_dtor_13c: thiscall, 1 stack arg (flags, ret 4). State 0 for the whole body; [this]=0x68e948; 0x49a3e0(this);
// if flags&1: cdecl 0x634273(this, 0x13c) (free). Returns this. Handler 0x665fd6.
extern "C" u8 *THISCALL deleting_dtor_13c(u8 *self, u32 flags) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x665fd6;
  reg.state = -1;
  seh_set_head(&reg);
  reg.state = 0;
  *(u32 *)self = 0x68e948;
  ext_49a3e0(self);
  if (flags & 1) ext_634273(self, 0x13c);
  SEH_LEAVE();
  return self;
}
PCREG(499d50, deleting_dtor_13c);

// 0x4d8d50 GUESS release_owned: thiscall. 0x4d8e60(this); p = [this]; if p: 0x4e7e80(p) (thiscall) and cdecl free 0x634273(p, 0x21).
// State stays -1 (handler 0x6656a0). Returns the last eax.
extern "C" u32 THISCALL release_owned(u8 *self) {
  SEH_ENTER(0x6656a0);
  u32 r = ext_4d8e60(self);
  u8 *p = *(u8 **)self;
  if (p) {
    ext_4e7e80(p);
    r = ext_634273(p, 0x21);
  }
  SEH_LEAVE();
  return r;
}
PCREG(4d8d50, release_owned);

// 0x4d8180 GUESS ctor_two_members: thiscall, 2 stack args (ret 8). [this]=0x696c14; 0x4cbe80(this+4, a) at state -1; state 0; 0x4cbe80(this+0x84, b). Returns this.
extern "C" u8 *THISCALL ctor_two_members(u8 *self, u32 a, u32 b) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x66966b;
  reg.state = -1;
  seh_set_head(&reg);
  *(u32 *)self = 0x696c14;
  ext_4cbe80(self + 4, a);
  reg.state = 0;
  ext_4cbe80(self + 0x84, b);
  SEH_LEAVE();
  return self;
}
PCREG(4d8180, ctor_two_members);
