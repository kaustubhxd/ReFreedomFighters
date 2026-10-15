// batch200008.cpp - Sonnet-w2, SEH-framed ctor / dtor / factory shapes (fifth set).
#include "ff.h"

extern "C" u32 THISCALL ext_51a9f0(void *self, u32 a);
extern "C" u32 THISCALL ext_51b530(void *self);
extern "C" u32 THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_4dcdf0(void *self, u32 a);
extern "C" u32 THISCALL ext_49f2d0(void *self);
extern "C" u32 THISCALL ext_4a3b40(void *self);
extern "C" u32 THISCALL ext_4bde40(void *self);
extern "C" u32 ext_41e2c0(void *p);
extern "C" u32 STDCALL ext_54f870(void *p, u32 bytes);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x51afb0 GUESS ctor_guarded: thiscall(a), ret 4, handler 0x66a238. 0x51a9f0(this, a) at state -1; state 0; [this]=0x69f43c; [this+0x1c]=a;
// if global [0x701800]==0: 0x51b530(this). Returns this.
extern "C" u8 *THISCALL ctor_guarded(u8 *self, u32 a) {
  SEH_ENTER(0x66a238);
  ext_51a9f0(self, a);
  u32 g = G(u32, 0x701800);
  reg.state = 0;
  *(u32 *)self = 0x69f43c;
  *(u32 *)(self + 0x1c) = a;
  if (g == 0) ext_51b530(self);
  SEH_LEAVE();
  return self;
}
PCREG(51afb0, ctor_guarded);

// 0x5f98d0 GUESS dtor_vector_buf: thiscall, handler 0x665fd6, state 0. begin=[this+0xc], diff=[this+0x14]-begin; if begin and diff non-zero: stdcall
// 0x54f870(begin, diff); then cdecl 0x41e2c0([this]). Returns the last eax.
extern "C" u32 THISCALL dtor_vector_buf(u8 *self) {
  SEH_ENTER(0x665fd6);
  u8 *begin = *(u8 **)(self + 0xc);
  u32 diff = *(u32 *)(self + 0x14) - (u32)begin;
  reg.state = 0;
  if (begin != 0 && diff != 0) ext_54f870(begin, diff);
  u32 r = ext_41e2c0(*(void **)self);
  SEH_LEAVE();
  return r;
}
PCREG(5f98d0, dtor_vector_buf);

// 0x45ad90 GUESS ctor_three_floats: thiscall(a, b, c), ret 0xc, handler 0x666568. 0x43de40(this, a, b, c) at state -1; [this]=0x683e50; [this+0x18/0x1c/0x20]=10.0f;
// state 0; 0x4dcdf0([this+8], 0) (thiscall, ret 4). Returns this.
extern "C" u8 *THISCALL ctor_three_floats(u8 *self, u32 a, u32 b, u32 c) {
  SEH_ENTER(0x666568);
  ext_43de40(self, a, b, c);
  *(u32 *)self = 0x683e50;
  *(u32 *)(self + 0x18) = 0x41200000;
  *(u32 *)(self + 0x1c) = 0x41200000;
  *(u32 *)(self + 0x20) = 0x41200000;
  void *m = *(void **)(self + 8);
  reg.state = 0;
  ext_4dcdf0(m, 0);
  SEH_LEAVE();
  return self;
}
PCREG(45ad90, ctor_three_floats);

// 0x49fb90 / 0x4a3cf0 / 0x4beaa0 GUESS factory_init_a/b/c: thiscall(this), handler 0x66c831. o = [[engine+0x9b]+8]; p = slot 0x44 of o (thiscall, one stack arg = this, callee pops) at state -1; state 0; if p: thiscall init(p) (0x49f2d0 / 0x4a3b40 / 0x4bde40). Returns p.
extern "C" u32 THISCALL factory_init_a(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_49f2d0(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(49fb90, factory_init_a);

extern "C" u32 THISCALL factory_init_b(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_4a3b40(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(4a3cf0, factory_init_b);

extern "C" u32 THISCALL factory_init_c(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_4bde40(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(4beaa0, factory_init_c);
