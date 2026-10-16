// batch0105.cpp - fresh-01 batch 5 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void ext_6322e0(u32 blocks, u8 *strm, u32 c);                  // inflate_blocks_reset (cdecl)
extern "C" u32 THISCALL ext_561cb0(u8 *self, u32 id, u32 data);           // CBaseWindow::Command
extern "C" void THISCALL ext_42d730(u8 *self, u8 *load);                  // ZSysInterface::Load

typedef u32(THISCALL *s20Fn)(void *, u32, u32);
typedef u32 (*log2Fn)(void *, u32);
typedef u32 (*log3Fn)(void *, u32, u32);
typedef u32 (*handlerFn)();
typedef s32(STDCALL *com7Fn)(void *, u32, u32, u32, u32, void *, u32);
typedef s32 (*clockFn)();

static u8 *logObj(u32 file, u32 line) {
  u8 *mgr = G(u8 *, 0x700390);
  return (u8 *)(*(s20Fn *)(*(u8 **)mgr + 0x20))(mgr, file, line);
}

// 0x54f250 (unnamed, DirectInput device setup): when the COM object at this+4 is set: this+0x4c = 7, then its slot 0x10
// (stdcall: obj, 0x6bdf70, 0x80000001, 0, 0, this+8, 0x48); a negative HRESULT is logged ([0x700390] slot 0x20
// (0x6a4168, 0x174), then the cdecl slot 0x2c(obj, 0x6a42e0)).
static void THISCALL comSetup54f250(u8 *self) {
  u8 *o = *(u8 **)(self + 4);
  if (!o) return;
  *(u32 *)(self + 0x4c) = 7;
  s32 hr = (*(com7Fn *)(*(u8 **)o + 0x10))(o, 0x6bdf70, 0x80000001u, 0, 0, self + 8, 0x48);
  if (hr >= 0) return;
  u8 *l = logObj(0x6a4168, 0x174);
  (*(log2Fn *)(*(u8 **)l + 0x2c))(l, 0x6a42e0);
}
PCREG(54f250, comSetup54f250);

// 0x62fad0, zlib inflateReset(z_streamp) (stdcall): -2 when the stream or its state (+0x1c) is null; else total_in
// (+8), total_out (+0x14) and msg (+0x18) = 0, state->mode = (state->nowrap (+0xc) ? 7 : 0) and
// inflate_blocks_reset(state->blocks (+0x14), strm, 0); returns 0.
static s32 STDCALL zInflateReset(u8 *strm) {
  if (!strm) return -2;
  u8 *s = *(u8 **)(strm + 0x1c);
  if (!s) return -2;
  *(u32 *)(strm + 0x14) = 0;
  *(u32 *)(strm + 8) = 0;
  *(u32 *)(strm + 0x18) = 0;
  *(u32 *)s = *(u32 *)(s + 0xc) ? 7 : 0;
  ext_6322e0(*(u32 *)(*(u8 **)(strm + 0x1c) + 0x14), strm, 0);
  return 0;
}
PCREG(62fad0, zInflateReset);

// 0x4fa390, ZCONTROL::OnKeyPress(unsigned int): keys 0x100..0x103 map to 4, 3, 1, 2; o = own slot 0x318(n); when o is
// set, (own slot 0x2c4())->slot 0x2ec(o). Always returns false.
static u8 THISCALL controlOnKeyPress(u8 *self, u32 key) {
  u32 n;
  switch (key - 0x100) {
  case 0: n = 4; break;
  case 1: n = 3; break;
  case 2: n = 1; break;
  case 3: n = 2; break;
  default: return 0;
  }
  u32 o = vcall<u32>(self, 0x318, n);
  if (o) {
    u8 *c = vcall<u8 *>(self, 0x2c4);
    vcall<void>(c, 0x2ec, o);
  }
  return 0;
}
PCREG(4fa390, controlOnKeyPress);

// 0x64ab50, ZDrawArray<ZDrawResource, ...>::Defracment(): for each block in the ring from this+8 (next at +8, stops at
// the start or null): r = (this+4 object) slot 0x10(block) (bool), logged as ([0x700390] slot 0x20(0x6bda58, 0x164))
// cdecl slot 0x2c(obj, 0x6bdaa8, r).
static void THISCALL drawArrayDefrag(u8 *self) {
  u8 *b = *(u8 **)(self + 8);
  if (!b) return;
  do {
    u8 r = vcall<u8>(*(u8 **)(self + 4), 0x10, b);
    u8 *l = logObj(0x6bda58, 0x164);
    (*(log3Fn *)(*(u8 **)l + 0x2c))(l, 0x6bdaa8, (u32)r);
    b = *(u8 **)(b + 8);
  } while (b != *(u8 **)(self + 8) && b);
}
PCREG(64ab50, drawArrayDefrag);

// 0x57bc10, ZFFLoadError::Command(unsigned short, void*): id = render RegisterZMsg (slot 0x114)(0x6aa4bc, 0, 0x6aa490,
// 0x50); for that message the dword at data (when data is set) goes to this+0xcb2 and returns 0; else
// CBaseWindow::Command(id, data).
static u32 THISCALL loadErrorCommand(u8 *self, u32 msg, u32 *data) {
  u16 id = vcall<u16>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x114, 0x6aa4bcu, 0u, 0x6aa490u, 0x50u);
  if ((u16)msg == id) {
    if (data) *(u32 *)(self + 0xcb2) = *data;
    return 0;
  }
  return ext_561cb0(self, msg, (u32)data);
}
PCREG(57bc10, loadErrorCommand);

// 0x5f4110 (unnamed, script float value): when the type byte (this+4) is 2, value (this+0) /= *arg and EAX = arg; else
// logs ([0x700390] slot 0x20(0x69c8e0, 0xb4), cdecl slot 0x2c(obj, 0x69c6b0, 0x69c938)) and calls the handler at
// [0x7003b0] (int3 when unset), returning its EAX.
static u32 THISCALL scriptFloatDiv(u8 *self, const float *a) {
  if (self[4] == 2) {
    *(float *)self = *(float *)self / *a;
    return (u32)a;
  }
  u8 *l = logObj(0x69c8e0, 0xb4);
  (*(log3Fn *)(*(u8 **)l + 0x2c))(l, 0x69c6b0, 0x69c938);
  handlerFn h = G(handlerFn, 0x7003b0);
  if (h) return h();
  __builtin_debugtrap();
  return 0;
}
PCREG(5f4110, scriptFloatDiv);

// 0x6511d0 (unnamed): false when the engine's slot 0x1b0 object exists and its slot 0xc says true; else true only when
// the engine floats +0x9c7 and +0x9c3 are both nonzero (NaN counts as nonzero) and this+0x74 is set.
static u8 THISCALL check6511d0(u8 *self) {
  u8 *o = vcall<u8 *>(G(u8 *, 0x70039c), 0x1b0);
  if (o && vcall<u8>(o, 0xc)) return 0;
  u8 *g = G(u8 *, 0x70039c);
  if (*(float *)(g + 0x9c7) == 0.0f) return 0;
  if (*(u32 *)(self + 0x74) == 0) return 0;
  if (*(float *)(g + 0x9c3) == 0.0f) return 0;
  return 1;
}
PCREG(6511d0, check6511d0);

// 0x421810, ZSysInterfaceGC::Load(ZLoadGame*): ZSysInterface::Load(load); load slots 0x54(this+0x23c6) and
// 0x5c(this+0x23ce); this+0xc = (double)(float)(clock() * 0.001 [0x6785e8]); returns own slot 0x170().
static u32 THISCALL sysInterfaceGcLoad(u8 *self, u8 *load) {
  ext_42d730(self, load);
  vcall<void>(load, 0x54, self + 0x23c6);
  vcall<void>(load, 0x5c, self + 0x23ce);
  s32 t = (*(clockFn *)0x676434)();
  *(double *)(self + 0xc) = (double)(float)((double)t * G(double, 0x6785e8));
  return vcall<u32>(self, 0x170);
}
PCREG(421810, sysInterfaceGcLoad);

// 0x4496d0, ZSPOTLIGHT::SetDiffuseColor(unsigned int): own slot 0x238; dev = engine+0x1aa3 object +0x18; light =
// [this+8]+0x6c; dev slot 0x84(light, &l) reads the 0x38-byte light into a local, l+0x10 = color, dev slot 0xa0(light,
// &l) writes it back. dev is re-read before the second call.
static void THISCALL spotSetDiffuseColor(u8 *self, u32 color) {
  u8 l[0x38];
  vcall<void>(self, 0x238);
  u8 *dev = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  vcall<void>(dev, 0x84, *(u32 *)(*(u8 **)(self + 8) + 0x6c), (u8 *)l);
  *(u32 *)(l + 0x10) = color;
  dev = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  vcall<void>(dev, 0xa0, *(u32 *)(*(u8 **)(self + 8) + 0x6c), (u8 *)l);
}
PCREG(4496d0, spotSetDiffuseColor);
