// batch200001.cpp - Sonnet-w2, SEH-framed small functions (/GS cookie frames, handler thunk 0x669740 or 0x6684b6).
#include "ff.h"

// 0x48aa80 GUESS assert_hook_call: cdecl, no args. Calls the assert hook at 0x7003b0 inside an EH frame (state -1); a NULL hook hits int3.
typedef u32(__attribute__((cdecl)) * VoidHook)();
extern "C" u32 call_assert_hook() {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x669740;
  reg.state = -1;
  seh_set_head(&reg);
  VoidHook h = G(VoidHook, 0x7003b0);
  if (!h) __builtin_trap();
  u32 r = h();
  seh_set_head(reg.next);
  return r;
}
PCREG(48aa80, call_assert_hook);

// 0x45c510 GUESS engine_table_obj_slot14: cdecl(arg). t = engine+0x9b; u = *(t+8); thiscall slot 0x14 of u with arg; returns its eax.
extern "C" u32 engine_table_forward(u32 arg) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x669740;
  reg.state = -1;
  seh_set_head(&reg);
  u8 *t = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  void *u = *(void **)(t + 8);
  u32 r = vcall<u32>(u, 0x14, arg);
  seh_set_head(reg.next);
  return r;
}
PCREG(45c510, engine_table_forward);

// 0x4f6b20 GUESS init_and_register: thiscall. Clears +0x44 and +0x30, sets vtable 0x686874, then calls slot 0x34 of engine+0x9b with this
// inside an EH frame (state 0, set before the call and never reset).
extern "C" u32 THISCALL init_and_register(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x6684b6;
  reg.state = -1;
  seh_set_head(&reg);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  void *t = *(void **)((u8 *)g_pSysInterface + 0x9b);
  reg.state = 0;
  u32 r = vcall<u32>(t, 0x34, self);
  seh_set_head(reg.next);
  return r;
}
PCREG(4f6b20, init_and_register);
