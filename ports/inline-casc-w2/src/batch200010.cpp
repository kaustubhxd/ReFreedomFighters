// batch200010.cpp - Sonnet-w2, SEH-framed factory family (second set) and a refcounted deleting dtor.
#include "ff.h"

extern "C" u32 THISCALL ext_659c00(void *self);
extern "C" u32 ext_634273(void *p, u32 size);
extern "C" u32 THISCALL ext_469c00(void *self);
extern "C" u32 THISCALL ext_469cc0(void *self);
extern "C" u32 THISCALL ext_4a6270(void *self);
extern "C" u32 THISCALL ext_4a86c0(void *self);
extern "C" u32 THISCALL ext_4b1ca0(void *self);
extern "C" u32 THISCALL ext_4bdaf0(void *self);
extern "C" u32 THISCALL ext_4c32a0(void *self);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x616be0 GUESS deleting_dtor_refcounted: thiscall(flags), ret 4, handler 0x665fd6, state 0. c=[this+4]; [this]=0x6bdcc0; [c+0x30] -= 1; if it reached 0: 0x659c00(c+0x24);
// [this]=0x6bdc38; if flags&1 cdecl free 0x634273(this, 0xc). Returns this.
extern "C" u8 *THISCALL deleting_dtor_refcounted(u8 *self, u32 flags) {
  SEH_ENTER(0x665fd6);
  u8 *c = *(u8 **)(self + 4);
  *(u32 *)self = 0x6bdcc0;
  reg.state = 0;
  u32 v = *(u32 *)(c + 0x30) - 1;
  *(u32 *)(c + 0x30) = v;
  if (v == 0) ext_659c00(c + 0x24);
  *(u32 *)self = 0x6bdc38;
  if (flags & 1) ext_634273(self, 0xc);
  SEH_LEAVE();
  return self;
}
PCREG(616be0, deleting_dtor_refcounted);

// factory_<addr>: thiscall(this), handler 0x66c831. o = [[engine+0x9b]+8]; p = slot 0x44 of o (thiscall, this as the stack arg, callee pops) at state -1; state 0;
// if p call init(p) (callee in the body). Returns p.
extern "C" u32 THISCALL factory_46b200(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_469c00(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(46b200, factory_46b200);

extern "C" u32 THISCALL factory_46b270(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_469cc0(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(46b270, factory_46b270);

extern "C" u32 THISCALL factory_4a63d0(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_4a6270(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(4a63d0, factory_4a63d0);

extern "C" u32 THISCALL factory_4a8850(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_4a86c0(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(4a8850, factory_4a8850);

extern "C" u32 THISCALL factory_4b2950(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_4b1ca0(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(4b2950, factory_4b2950);

extern "C" u32 THISCALL factory_4be8e0(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_4bdaf0(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(4be8e0, factory_4be8e0);

extern "C" u32 THISCALL factory_4c3420(void *self) {
  SEH_ENTER(0x66c831);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *o = *(void **)(t + 8);
  void *p = vcall<void *>(o, 0x44, self);
  reg.state = 0;
  if (p) ext_4c32a0(p);
  SEH_LEAVE();
  return (u32)p;
}
PCREG(4c3420, factory_4c3420);

