// batch200006.cpp - Sonnet-w2, SEH-framed ctor / deleting-dtor shapes (third set).
#include "ff.h"

extern "C" u32 THISCALL ext_659c00(void *self);
extern "C" u32 THISCALL ext_659bb0(void *self);
extern "C" u32 ext_634273(void *p, u32 size);
extern "C" u32 ext_41e2c0(void *p);
extern "C" u32 THISCALL ext_603900(void *self);
extern "C" u32 THISCALL ext_5044c0(void *self);
extern "C" u32 THISCALL ext_5fb600(void *self);
extern "C" u32 STDCALL ext_54f870(void *p, u32 bytes);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x616c50 GUESS deleting_dtor_14b: thiscall(flags), ret 4, handler 0x665fd6, state 0: [this]=0x6bdc58; 0x659c00(this+8); [this]=0x6bdc38;
// if flags&1 cdecl free 0x634273(this, 0x14). Returns this.
extern "C" u8 *THISCALL deleting_dtor_14b(u8 *self, u32 flags) {
  SEH_ENTER(0x665fd6);
  reg.state = 0;
  *(u32 *)self = 0x6bdc58;
  ext_659c00(self + 8);
  *(u32 *)self = 0x6bdc38;
  if (flags & 1) ext_634273(self, 0x14);
  SEH_LEAVE();
  return self;
}
PCREG(616c50, deleting_dtor_14b);

// 0x616d60 GUESS deleting_dtor_34: [this]=0x6bdc4c; 0x659bb0(this+0xc); [this]=0x6bdc40; if flags&1 free 0x634273(this, 0x34). Returns this.
extern "C" u8 *THISCALL deleting_dtor_34(u8 *self, u32 flags) {
  SEH_ENTER(0x665fd6);
  reg.state = 0;
  *(u32 *)self = 0x6bdc4c;
  ext_659bb0(self + 0xc);
  *(u32 *)self = 0x6bdc40;
  if (flags & 1) ext_634273(self, 0x34);
  SEH_LEAVE();
  return self;
}
PCREG(616d60, deleting_dtor_34);

// 0x603600 GUESS deleting_dtor_18: thiscall(flags), ret 4, state 0: [this]=0x6b9a24; 0x603900(this); cdecl 0x41e2c0([this+0xc]); [this]=0x69c968;
// if flags&1 free 0x634273(this, 0x18). Returns this.
extern "C" u8 *THISCALL deleting_dtor_18(u8 *self, u32 flags) {
  SEH_ENTER(0x665fd6);
  reg.state = 0;
  *(u32 *)self = 0x6b9a24;
  ext_603900(self);
  ext_41e2c0(*(void **)(self + 0xc));
  *(u32 *)self = 0x69c968;
  if (flags & 1) ext_634273(self, 0x18);
  SEH_LEAVE();
  return self;
}
PCREG(603600, deleting_dtor_18);

// 0x5c4580 GUESS dtor_register: thiscall, handler 0x665fd6. [this]=0x6b4088; cdecl 0x41e2c0([this+0x4c]) at state -1; [this+0x44]=0;
// [this+0x30]=0; [this]=0x686874; state 0; slot 0x34 of [engine+0x9b] with this; returns its eax.
extern "C" u32 THISCALL dtor_register(u8 *self) {
  SEH_ENTER(0x665fd6);
  *(u32 *)self = 0x6b4088;
  ext_41e2c0(*(void **)(self + 0x4c));
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  void *t = *(void **)((u8 *)g_pSysInterface + 0x9b);
  reg.state = 0;
  u32 r = vcall<u32>(t, 0x34, self);
  SEH_LEAVE();
  return r;
}
PCREG(5c4580, dtor_register);

// 0x500990 GUESS ctor_refcounted: thiscall(a), ret 4, handler 0x669c28. [this+4]=1; [this+8]=0; state 0; [this]=0x69c9c0; [this+0xc]=a; [this+0x10]=0;
// if global [0x700e70]==0: 0x5044c0(this). Returns this.
extern "C" u8 *THISCALL ctor_refcounted(u8 *self, u32 a) {
  SEH_ENTER(0x669c28);
  *(u32 *)(self + 4) = 1;
  *(u32 *)(self + 8) = 0;
  reg.state = 0;
  *(u32 *)self = 0x69c9c0;
  *(u32 *)(self + 0xc) = a;
  *(u32 *)(self + 0x10) = 0;
  if (G(u32, 0x700e70) == 0) ext_5044c0(self);
  SEH_LEAVE();
  return self;
}
PCREG(500990, ctor_refcounted);

// 0x606ce0 GUESS dtor_vector_member: thiscall, handler 0x66d9ec. State 0: 0x5fb600(this); v = this+3 (unaligned begin at +3, end at +0xb);
// n = (end-begin)>>2; state 1; if n: stdcall 0x54f870(begin, 4n). Returns eax (n when skipped).
extern "C" u32 THISCALL dtor_vector_member(u8 *self) {
  SEH_ENTER(0x66d9ec);
  reg.state = 0;
  ext_5fb600(self);
  u32 begin, end;
  __builtin_memcpy(&begin, self + 3, 4);
  __builtin_memcpy(&end, self + 3 + 8, 4);
  s32 n = (s32)(end - begin) >> 2;
  reg.state = 1;
  u32 r = (u32)n;
  if (n != 0) r = ext_54f870((void *)begin, (u32)n << 2);
  SEH_LEAVE();
  return r;
}
PCREG(606ce0, dtor_vector_member);
