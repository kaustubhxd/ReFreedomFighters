// batch32080.cpp - cascade h2 (): eight tier C thunks (vtable slots, imports, assert-hook stubs, a global object release).
#include "ff.h"

extern "C" void THISCALL ext_461c40(u8 *self);   // thiscall, plain ret (tail jump target)
typedef u32 (*hook_t)();
typedef u32 (STDCALL *imp1_t)(u32);
typedef u32 (STDCALL *imp2_t)(u32, u32);

// 0x46ed30, thiscall no args: tbl = engine->[0x9b]; slot 0x58 of tbl with [this+0x90]; returns its result.
static u32 THISCALL fn46ed30(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tbl = *(u8 **)(eng + 0x9b);
  return vcall<u32>(tbl, 0x58, *(u32 *)(self + 0x90));
}
PCREG(46ed30, fn46ed30);

// 0x54ab50, no args: import 0x676144([0x701b68], 0) == 0.
static bool fn54ab50() {
  return G(imp2_t, 0x676144)(G(u32, 0x701b68), 0) == 0;
}
PCREG(54ab50, fn54ab50);

// 0x5da650, thiscall no args: [this+0x4c] = 0; slot 0xbc of [this+0x44] with 1; returns its result.
static u32 THISCALL fn5da650(u8 *self) {
  *(u32 *)(self + 0x4c) = 0;
  return vcall<u32>(*(void **)(self + 0x44), 0xbc, 1u);
}
PCREG(5da650, fn5da650);

// 0x465fb0, thiscall no args: slot 0x410 of this; then tail jump to 0x461c40(this) (its eax is what comes back).
static void THISCALL fn465fb0(u8 *self) {
  vcall<void>(self, 0x410);
  ext_461c40(self);
}
PCREG(465fb0, fn465fb0);

// 0x4ced80, stdcall(ignored) ret 4: assert hook at 0x7003b0 (int3 when null); AL = 0, the upper bytes of EAX stay as the hook left them.
static u32 STDCALL fn4ced80(u32) {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h() & 0xffffff00u;
}
PCREG(4ced80, fn4ced80);

// 0x6044c0, cdecl no args: assert hook at 0x7003b0 (int3 when null); returns 0.
static u32 fn6044c0() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(6044c0, fn6044c0);

// 0x426ad0, stdcall(a) ret 4: import 0x676100(a) != 0.
static bool STDCALL fn426ad0(u32 a) {
  return G(imp1_t, 0x676100)(a) != 0;
}
PCREG(426ad0, fn426ad0);

// 0x50d750, cdecl no args: o = [0x7012cc]; when set, slot 4 of o with 0; [0x7012cc] = 0.
static void fn50d750() {
  void *o = G(void *, 0x7012cc);
  if (o) vcall<void>(o, 4, 0u);
  G(u32, 0x7012cc) = 0;
}
PCREG(50d750, fn50d750);
