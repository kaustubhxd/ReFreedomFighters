// batch2612.cpp - wider batch 2612: seven small unclaimed functions (GUESS names; none has an entry in the GC name map checked here).
#include "ff.h"

extern "C" void THISCALL ext_49a3e0(u8 *self);               // base step, plain ret
extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);     // thiscall, ret 4
extern "C" void THISCALL ext_4cd0e0(u8 *self);               // base destructor body (SEH frame), plain ret
extern "C" void THISCALL ext_4d1530(u8 *self);               // base destructor body (SEH frame), plain ret
extern "C" void ext_634273(u8 *p, u32 n);                    // CRT free-style, cdecl
typedef void(THISCALL *v1p_t)(void *, void *);
typedef void(STDCALL *v3_t)(void *, u32, u32, u32);

// 0x499980, thiscall, no args, SEH frame (the frame pushes no ESI/ECX copies; plain). Sets the vtable to 0x68e948, then the base step 0x49a3e0.
static void THISCALL fn499980(u8 *self) {
  *(u32 *)self = 0x68e948;
  ext_49a3e0(self);
}
PCREG(499980, fn499980);

// 0x4b5940, thiscall, no args: local = 0, byte +0x4c = 0, 0x6352f0(this, &local) (ret 4), then slot 0x88 of this with &local.
static void THISCALL fn4b5940(u8 *self) {
  u32 local = 0;
  self[0x4c] = 0;
  ext_6352f0(self, &local);
  (*(v1p_t **)self)[0x88 / 4](self, &local);
}
PCREG(4b5940, fn4b5940);

// 0x4c7a60, thiscall, no args: clear +0x48, +0x50 (dwords) and +0x54 (byte); when [engine+0x1907] is non-null, its slot 0xc is called with
// (0x6e75f0, 0x694c38, 0) (thiscall, callee pops 12).
typedef void(THISCALL *v3t_t)(void *, u32, u32, u32);
static void THISCALL fn4c7a60(u8 *self) {
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x50) = 0;
  self[0x54] = 0;
  u8 *eng = *(u8 **)0x70039c;
  void *o = *(void **)(eng + 0x1907);
  if (o) (*(v3t_t **)o)[0xc / 4](o, 0x6e75f0, 0x694c38, 0);
}
PCREG(4c7a60, fn4c7a60);

// 0x4cd3c0 / 0x4d1600: scalar deleting destructors, thiscall(flags) ret 4, return this: base body, then free(this, size) when bit 0 of flags.
static u8 *THISCALL fn4cd3c0(u8 *self, u32 flags) {
  ext_4cd0e0(self);
  if (flags & 1) ext_634273(self, 0x1c);
  return self;
}
PCREG(4cd3c0, fn4cd3c0);
static u8 *THISCALL fn4d1600(u8 *self, u32 flags) {
  ext_4d1530(self);
  if (flags & 1) ext_634273(self, 0x38);
  return self;
}
PCREG(4d1600, fn4d1600);

// 0x4d53e0, thiscall(p) ret 4: p == this+4 gives [this+8]; otherwise the assert hook at 0x7003b0 is called (int3 when null) and EAX is what the hook leaves.
typedef u32 (*hook_t)();
static u32 THISCALL fn4d53e0(u8 *self, u8 *p) {
  if (p == self + 4) return *(u32 *)(self + 8);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(4d53e0, fn4d53e0);

// 0x4d5700, thiscall(flags) ret 4, returns this: vtable 0x6967bc; free(this, 4) when bit 0 of flags.
static u8 *THISCALL fn4d5700(u8 *self, u32 flags) {
  *(u32 *)self = 0x6967bc;
  if (flags & 1) ext_634273(self, 4);
  return self;
}
PCREG(4d5700, fn4d5700);
