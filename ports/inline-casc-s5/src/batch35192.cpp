// batch35192.cpp - cascade s5 batch 35192 (tier H): 0x4c75a0 (GUESS poll the debug key bindings and run the matching toggles).
#include "ff.h"

extern "C" void THISCALL ext_4c8760(u8 *self);
extern "C" void THISCALL ext_4c85f0(u8 *self);
extern "C" void THISCALL ext_4c8560(u8 *self);
extern "C" void THISCALL ext_4c86d0(u8 *self);
extern "C" void THISCALL ext_4c7bb0(u8 *self);
extern "C" void THISCALL ext_4c7330(u8 *self);
extern "C" void THISCALL ext_4c8360(u8 *self);
extern "C" void THISCALL ext_4c6cf0(u8 *self);
typedef u8(THISCALL *k_t)(void *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// key(s): the input object I = unaligned dword [engine+0x1907], slot 0x38(s, 0) (al). 0x4c75a0, thiscall, no args, no return value: key(0x694684): 0x4c8760; key(0x6946b4): [+0x50] = ([+0x50] == 0) and bit 0x20000 of [mgr+0x30]
// (mgr = [[engine+0x9b]+0xadc]) set or cleared; key(0x6946d4): 0x4c85f0; key(0x6946f4): 0x4c8560; key(0x694694): 0x4c86d0; key(0x694714): [+0x54] = ([+0x54] == 0), [+0x44] slot 0xb4(flag) (the original pushes edx whose upper bytes are
// leftovers, only the low byte matters); key(0x694730), key(0x69474c): 0x4c7bb0; key(0x69476c), key(0x694784): 0x4c7330; key(0x6947a0): 0x4c8360. Finally float [+0x48] != the constant at 0x6785d0 (or NaN): tail call 0x4c6cf0.
static bool key(u32 s) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *I = (u8 *)rd32u(eng + 0x1907);
  return (*(k_t **)I)[0x38 / 4](I, s, 0) & 0xff;
}
static void THISCALL fn4c75a0(u8 *self) {
  if (key(0x694684)) ext_4c8760(self);
  if (key(0x6946b4)) {
    u8 f = (self[0x50] == 0);
    self[0x50] = f;
    u8 *eng = G(u8 *, 0x70039c);
    u8 *mgr = *(u8 **)(*(u8 **)(eng + 0x9b) + 0xadc);
    if (f) *(u32 *)(mgr + 0x30) |= 0x20000;
    else *(u32 *)(mgr + 0x30) &= 0xfffdffffu;
  }
  if (key(0x6946d4)) ext_4c85f0(self);
  if (key(0x6946f4)) ext_4c8560(self);
  if (key(0x694694)) ext_4c86d0(self);
  if (key(0x694714)) {
    u8 f = (self[0x54] == 0);
    u8 *c = (u8 *)*(u32 *)(self + 0x44);
    self[0x54] = f;
    (*(v1_t **)c)[0xb4 / 4](c, f);
  }
  if (key(0x694730)) ext_4c7bb0(self);
  if (key(0x69474c)) ext_4c7bb0(self);
  if (key(0x69476c)) ext_4c7330(self);
  if (key(0x694784)) ext_4c7330(self);
  if (key(0x6947a0)) ext_4c8360(self);
  float v = *(float *)(self + 0x48);
  if (!(v == G(float, 0x6785d0))) ext_4c6cf0(self);
}
PCREG(4c75a0, fn4c75a0);
