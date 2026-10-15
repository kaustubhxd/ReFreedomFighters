// batch200003.cpp - Sonnet-w2, SEH-framed destructor-shaped functions (vtable stores, member destruct calls, storage free).
#include "ff.h"

extern "C" u32 THISCALL ext_4f0c10(void *self);
extern "C" u32 THISCALL ext_43de70(void *self);
extern "C" u32 THISCALL ext_603900(void *self);
extern "C" u32 ext_41e2c0(void *p);
extern "C" u32 THISCALL ext_4dbb00(void *self, u32 arg);
extern "C" u32 THISCALL ext_45c3e0(void *self);
extern "C" u32 THISCALL ext_5fb5b0(void *self);
extern "C" u32 STDCALL ext_54f870(void *p, u32 bytes);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x4ee4e0 GUESS Derived_dtor_a: thiscall. [this] = 0x697e9c; 0x4f0c10(this); 0x43de70(this) (base dtor). EH frame (handler 0x6656a0, state -1).
extern "C" u32 THISCALL derived_dtor_a(u8 *self) {
  SEH_ENTER(0x6656a0);
  *(u32 *)self = 0x697e9c;
  ext_4f0c10(self);
  u32 r = ext_43de70(self);
  SEH_LEAVE();
  return r;
}
PCREG(4ee4e0, derived_dtor_a);

// 0x6035a0 GUESS Derived_dtor_b: thiscall. [this] = 0x6b9a24; 0x603900(this); frees [this+0xc] (cdecl 0x41e2c0); [this] = 0x69c968.
extern "C" u32 THISCALL derived_dtor_b(u8 *self) {
  SEH_ENTER(0x6656a0);
  *(u32 *)self = 0x6b9a24;
  ext_603900(self);
  u32 r = ext_41e2c0(*(void **)(self + 0xc));
  *(u32 *)self = 0x69c968;
  SEH_LEAVE();
  return r;
}
PCREG(6035a0, derived_dtor_b);

// 0x4478d0 GUESS Derived_dtor_c: thiscall. [this] = 0x67dc30; 0x4dbb00 on [this+8] with 0 (thiscall, ret 4); then 0x45c3e0(this). Returns the last eax? (void)
extern "C" u32 THISCALL derived_dtor_c(u8 *self) {
  SEH_ENTER(0x6656a0);
  void *m = *(void **)(self + 8);
  *(u32 *)self = 0x67dc30;
  ext_4dbb00(m, 0);
  u32 r = ext_45c3e0(self);
  SEH_LEAVE();
  return r;
}
PCREG(4478d0, derived_dtor_c);

// 0x5facc0 GUESS clear_and_free_19: thiscall. Frame handler 0x66d9ec; state 0 around 0x5fb5b0(this); state 1 around 0x54f870([this], 0x13). Returns eax of the last call.
extern "C" u32 THISCALL clear_and_free_19(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x66d9ec;
  reg.state = -1;
  seh_set_head(&reg);
  reg.state = 0;
  ext_5fb5b0(self);
  reg.state = 1;
  u32 r = ext_54f870(*(void **)self, 0x13);
  SEH_LEAVE();
  return r;
}
PCREG(5facc0, clear_and_free_19);

// 0x5ab460 GUESS vector16b_free: n = (end-begin)>>4 (arithmetic); frees begin with 16n bytes unless n==0. EH frame (handler 0x6684b6, state 0 around the call).
extern "C" u32 THISCALL vector16b_free(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x6684b6;
  reg.state = -1;
  seh_set_head(&reg);
  u8 *begin = *(u8 **)self;
  s32 n = (s32)(*(u32 *)(self + 8) - (u32)begin) >> 4;
  reg.state = 0;
  u32 r = (u32)n;
  if (n != 0) r = ext_54f870(begin, (u32)n << 4);
  SEH_LEAVE();
  return r;
}
PCREG(5ab460, vector16b_free);
