// batch1902.cpp - fresh slice 19, batch 1902 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

typedef void (*logf2_t)(void *, u32, u32);
extern "C" u32 FASTCALL ext_4daf20(u32 a, u32 b);                       // GetBaseGeomListType (hooked)
extern "C" u32 THISCALL ext_496ce0(u8 *lists, u32 id, u8 *g, u32 t);    // ZBaseGeomLists::Exists (hooked)
extern "C" void THISCALL ext_43ea20(u8 *self);                          // ZScrollbar dtor body (hooked)
extern "C" void ext_45c510(void *p);                                    // ZGEOM::operator delete (cdecl, hooked)
extern "C" void ext_4690b0(void *p, u32 n);                             // empty function, here as sized delete (cdecl, hooked)
extern "C" void THISCALL ext_4dbb00(u8 *g, bool b);                     // ZBaseGeom::LightNotifyPotentialDetachment (hooked)
extern "C" u32 THISCALL ext_49c980(u8 *self, u8 *list, u32 n);          // CListUser::PriUnfoldList (hooked)

static inline void assert_hook() {
  void (*hook)() = *(void (**)())0x7003b0u;
  if (hook) hook();
  else __builtin_debugtrap();   // the exe falls into an int3 when no hook is set
}

// 0x54aaf0 (no GC name) (bool on) ret 4: r = vt[0xa8](); byte +0xa273 = on && r->+0xc8; returns that byte.
static bool THISCALL fn_54aaf0(u8 *self, bool on) {
  u8 *r = vcall<u8 *>(self, 0xa8);
  self[0xa273] = 0;
  if (on && r[0xc8]) self[0xa273] = 1;
  return self[0xa273];
}
PCREG(54aaf0, fn_54aaf0);

// 0x5f94b0 Process_t::ProcFactory_t::typeInfoFromSerial(const char*, SerialInfo_t&) ret 8: not implemented in the exe;
// logs (file 0x6b8a64, line 0x2a7, fmt 0x69c6b0, text 0x69c7f0) and calls the assert hook.
static void THISCALL typeInfoFromSerial_5f94b0(u8 *self, u32, u32) {
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x6b8a64u, 0x2a7u);
  (*(logf2_t *)(*(u8 **)log + 0x2c))(log, 0x69c6b0u, 0x69c7f0u);
  assert_hook();
}
PCREG(5f94b0, typeInfoFromSerial_5f94b0);

// 0x603eb0 OpaqueUserType_t::serialSize() (no args): same shape (file 0x6b9750, line 0x26, text 0x6b97ac); returns 0.
static u32 THISCALL serialSize_603eb0(u8 *self) {
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x6b9750u, 0x26u);
  (*(logf2_t *)(*(u8 **)log + 0x2c))(log, 0x69c6b0u, 0x6b97acu);
  assert_hook();
  return 0;
}
PCREG(603eb0, serialSize_603eb0);

// 0x64fc70 ZRender::GetTextSizeX() const: (float)vt[0xd8]() / vt[0xf4]() (x87 divide, stored as float), truncated.
static s32 THISCALL getTextSizeX_64fc70(u8 *self) {
  float a = (float)vcall<s32>(self, 0xd8);
  float b = vcall<float>(self, 0xf4);
  float q = (float)((long double)a / (long double)b);
  return _mm_cvttss_si32(_mm_set_ss(q));
}
PCREG(64fc70, getTextSizeX_64fc70);

// 0x496d70 ZGeomBuffer::Exists(unsigned id, ZBaseGeom *g) ret 8: type = GetBaseGeomListType(g->+0x54 ? g->+0x54->+0xc->+0x23
// : 0x200002, g->+0x3c); returns ZBaseGeomLists::Exists(this->+0x1c; id, g, type).
static u32 THISCALL exists_496d70(u8 *self, u32 id, u8 *g) {
  u8 *m = *(u8 **)(g + 0x54);
  u32 a = m ? *(u32 *)(*(u8 **)(m + 0xc) + 0x23) : 0x200002u;
  u32 t = ext_4daf20(a, *(u32 *)(g + 0x3c));
  return ext_496ce0(*(u8 **)(self + 0x1c), id, g, t);
}
PCREG(496d70, exists_496d70);

// 0x65f170 ZGeometryDecal::Flush(): each of the [+0xcc] entries at +0xd0 gets +0x24 = 2, +0x44 = 0; then +0xc4 = 0x80.
static void THISCALL flush_65f170(u8 *self) {
  u8 **p = (u8 **)(self + 0xd0);
  for (u32 i = 0; i != *(u32 *)(self + 0xcc);) {
    u8 *e = *p++;
    i++;
    *(u32 *)(e + 0x24) = 2;
    *(u32 *)(e + 0x44) = 0;
  }
  *(u32 *)(self + 0xc4) = 0x80;
}
PCREG(65f170, flush_65f170);

// 0x4b0ef0 CCutSequenceSoundFXAttenuation::Save(ZSaveGame *s) ret 4: clears flag 0x40 at +4; s slot 0x44(+0x48),
// slot 0x54(+0x50), slot 0x60(byte +0x6c); returns 1.
static bool THISCALL save_4b0ef0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(s, 0x44, *(u32 *)(self + 0x48));
  vcall<void>(s, 0x54, *(u32 *)(self + 0x50));
  vcall<void>(s, 0x60, (u32)self[0x6c]);
  return true;
}
PCREG(4b0ef0, save_4b0ef0);

// 0x4f9970 ZScrollbar scalar deleting destructor (flags) ret 4: body 0x43ea20; flag 1 frees (flag 4: 0x4690b0(this, 0xb4),
// else ZGEOM::operator delete(this)); returns this.
static u8 *THISCALL sdtor_4f9970(u8 *self, u32 f) {
  ext_43ea20(self);
  if (f & 1) {
    if (f & 4) ext_4690b0(self, 0xb4);
    else ext_45c510(self);
  }
  return self;
}
PCREG(4f9970, sdtor_4f9970);

// 0x4951f0 ZEngineGeomControl::UpdateChangedLights(ZBaseGeom **g, unsigned n) ret 8: when the engine db (render manager
// +0x9b) has +0x5d35 set, LightNotifyPotentialDetachment(true) on each of the n geoms.
static void THISCALL updateChangedLights_4951f0(u8 *self, u8 **g, u32 n) {
  u8 *db = *(u8 **)(*(u8 **)0x70039cu + 0x9b);
  if (!*(u32 *)(db + 0x5d35)) return;
  for (u32 i = 0; i != n; i++) ext_4dbb00(g[i], true);
}
PCREG(4951f0, updateChangedLights_4951f0);

// 0x560530 CFFMPGameControl_if::registerCallMethod(handler) ret 4: appends to the 50-entry table at 0x7141a0 (count
// 0x714198); when full, vt[0x44](text 0x6a6218) and the assert hook.
static void THISCALL registerCallMethod_560530(u8 *self, u32 h) {
  u32 n = G(u32, 0x714198);
  if (n < 0x32) {
    G(u32, 0x7141a0 + n * 4) = h;
    G(u32, 0x714198) = n + 1;
    return;
  }
  vcall<void>(self, 0x44, 0x6a6218u);
  assert_hook();
}
PCREG(560530, registerCallMethod_560530);

// 0x61a6b0 (no GC name) fastcall (a, list): for each of list->[0] entries e (8 bytes, at list->+8) the device at
// [0x724a00] (re-read per entry) gets slot 0x11c(dev, 5, 0, a, e[1], e[0] - 2), COM style (stdcall, device on the stack).
static void FASTCALL fn_61a6b0(u32 a, u32 *list) {
  for (u32 i = 0; i < list[0]; i++) {
    u32 *e = (u32 *)(list[2] + i * 8);
    u8 *dev = G(u8 *, 0x724a00);
    (*(void(STDCALL **)(u8 *, u32, u32, u32, u32, u32))(*(u8 **)dev + 0x11c))(dev, 5, 0, a, e[1], e[0] - 2);
  }
}
PCREG(61a6b0, fn_61a6b0);

// 0x571bf0 CSoundMenu::BackUpOptionsValues(): o = engine vt[0xbc](); +0x18c/+0x190/+0x194 = o slots 0x7c/0x84/0x8c.
static void THISCALL backUpOptions_571bf0(u8 *self) {
  u8 *o = vcall<u8 *>(*(u8 **)0x70039cu, 0xbc);
  *(u32 *)(self + 0x18c) = vcall<u32>(o, 0x7c);
  *(u32 *)(self + 0x190) = vcall<u32>(o, 0x84);
  *(u32 *)(self + 0x194) = vcall<u32>(o, 0x8c);
}
PCREG(571bf0, backUpOptions_571bf0);

// 0x49c770 CListUser::NotifyAllMembers(void *p) ret 4: r = PriUnfoldList(+0x39, p->+0x68); the (r >> 16) + (r & 0xffff)
// list members get flag 0x1000000 at +0x3c (list re-read per member), then p itself.
static void THISCALL notifyAllMembers_49c770(u8 *self, u8 *p) {
  u32 r = ext_49c980(self, *(u8 **)(self + 0x39), *(u32 *)(p + 0x68));
  u32 n = (r >> 16) + (r & 0xffff);
  for (u32 i = 0; i < n; i++) *(u32 *)((*(u8 ***)(self + 0x39))[i] + 0x3c) |= 0x1000000u;
  *(u32 *)(p + 0x3c) |= 0x1000000u;
}
PCREG(49c770, notifyAllMembers_49c770);
