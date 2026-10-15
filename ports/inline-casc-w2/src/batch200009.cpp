// batch200009.cpp - Sonnet-w2, SEH-framed ctor / dtor / factory / allocator shapes (sixth set).
#include "ff.h"

extern "C" u32 THISCALL ext_500990(void *self, u32 a);
extern "C" u32 THISCALL ext_51a700(void *self);
extern "C" u32 ext_41e2c0(void *p);
extern "C" u32 ext_41e290(u32 size);
extern "C" u32 THISCALL ext_603500(void *self, u32 a);
extern "C" u32 THISCALL ext_56c810(void *self);
extern "C" u32 THISCALL ext_5a3710(void *self);
extern "C" u32 THISCALL ext_5b2550(void *self);
extern "C" u32 THISCALL ext_5b9380(void *self);
extern "C" u32 THISCALL ext_5bcab0(void *self);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x5193c0 GUESS ctor_guarded_b: thiscall(a), ret 4, handler 0x669bf8. 0x500990(this, a) at state -1; state 0; [this]=0x69f224; [this+0x14]=a;
// if global [0x701660]==0: 0x51a700(this). Returns this.
extern "C" u8 *THISCALL ctor_guarded_b(u8 *self, u32 a) {
  SEH_ENTER(0x669bf8);
  ext_500990(self, a);
  u32 g = G(u32, 0x701660);
  reg.state = 0;
  *(u32 *)self = 0x69f224;
  *(u32 *)(self + 0x14) = a;
  if (g == 0) ext_51a700(self);
  SEH_LEAVE();
  return self;
}
PCREG(5193c0, ctor_guarded_b);

// factory_init_*: thiscall(this), handler 0x66c831. o = [[engine+0x9b]+8]; p = slot 0x44 of o (thiscall, this as the stack arg, callee pops) at state -1;
// state 0; if p call init(p) (callee in the name). Returns p.
extern "C" u32 THISCALL factory_56ca20(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_56c810(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(56ca20, factory_56ca20);

extern "C" u32 THISCALL factory_5a3ee0(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_5a3710(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(5a3ee0, factory_5a3ee0);

extern "C" u32 THISCALL factory_5b2b60(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_5b2550(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(5b2b60, factory_5b2b60);

extern "C" u32 THISCALL factory_5b94f0(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_5b9380(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(5b94f0, factory_5b94f0);

extern "C" u32 THISCALL factory_5bcba0(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_5bcab0(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(5bcba0, factory_5bcba0);

// 0x5bfc00 GUESS dtor_register_c: thiscall, handler 0x665fd6. [this]=0x6b38b4; cdecl 0x41e2c0([this+0x50]) then ([this+0x4c]) at state -1; clears +0x44, +0x30;
// [this]=0x686874; state 0; slot 0x34 of [engine+0x9b] with this; returns its eax.
extern "C" u32 THISCALL dtor_register_c(u8 *self) {
  SEH_ENTER(0x665fd6);
  *(u32 *)self = 0x6b38b4;
  ext_41e2c0(*(void **)(self + 0x50));
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
PCREG(5bfc00, dtor_register_c);

// 0x5f30d0 GUESS new_and_init: stdcall(unused, b), ret 8, handler 0x66d07f. p = cdecl 0x41e290(0x18) (allocate); state 0; if p: r = 0x603500(p, b) (thiscall, ret 4),
// else 0. Returns r.
extern "C" u32 STDCALL new_and_init(u32 unused, u32 b) {
  SEH_ENTER(0x66d07f);
  u32 p = ext_41e290(0x18);
  reg.state = 0;
  u32 r = 0;
  if (p) r = ext_603500((void *)p, b);
  SEH_LEAVE();
  return r;
}
PCREG(5f30d0, new_and_init);
