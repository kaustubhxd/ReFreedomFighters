// f15b003.cpp - fresh slice 15, batch 3 (2026-10-12): next 16 smallest of residue 15.
// 0x42bdf0: thiscall(s): 0x5f2d60(this, s, s + strlen(s)) (callee pops 8); returns its eax.
// 0x432470: thiscall(key, def): p = this slot 0x54(key); p ? (float)atof(p) : def (float in ST0). ret 8.
// 0x54c270: o = this+0x63ec; o -> o slot 0x30(o, 0, 0, flag) COM stdcall, flag = (byte +0x7b != 0 || [+0x75] == 3).
// 0x5f4fb0: thiscall(u32 *p): v = *p <= [this+8] ? 0x5f5050(this, &(lim - v)) : error handler [0x7003b0]() (int3 if null).
// 0x4b59b0 CCutSequenceList::Load2: this slot 0x8c; +0xd6 = (this+0xaa) slot 0x34([+0xea]); +0xea = -1.
// 0x4c2a70 ZMusicControl::SendMessage(u16, void*): o = db slot 0x58([this+0xf8]); o -> o slot 0x128(a, b, 0).
// 0x65c7f0: ctor(a, b, c, d): 0x65bfe0(this, a, b, c, d); +0x182a1 = a; vtable 0x6c47a0.
// 0x54abf0: ctor over 0x5492f0; vtable 0x6a36dc; +0xa274 = 0; byte +0xa27c = 1; byte +0xa273 = 0.
// 0x4cd6f0 PRIOREFTAB::AddPrio(id, prio): signed min/max of prio into +0x1c/+0x20 (both set if +0x14 == 0);
//          r = REFTAB::Add(id); r[[this+0x18] - 2] = prio.
// 0x4f9930 ZCONTROL::~ZCONTROL (deleting): 0x43ea20(this); flags&1 -> flags&4 ? lort(this, 0x8f) : ZGEOM delete(this).
// 0x5758f0 ZZoneMap::OnCommand(u32): this slot 0xd8 -> false; NextMap -> true; else 0x574200(this, a).
// 0x4ffbf0 ZScriptInterfaceDll::End: four clean() calls, four lort(), [0x7003a4] slot 0xc8(0) if set.
// 0x63ee30 ZDrawBase::InitializeGlobalResources: byte +0xb949 |= 1, +0xb944 = -1, each of [+0xec] objects at +0xf0 slot 0x38.
// 0x6125b0: deleting dtor, vtable 0x6bd5d0; GdipDisposeImage([+4]); flags&1 -> flags&4 ? lort(this, 0x10) : GdipFree(this).
// 0x54aab0: m = (this slot 0xa8)+0xc4; v = a > m (signed) ? m : a; +0x805d = +0x8029 = v; returns v.
// 0x4a3cb0 ZSoundAmbient::ActivateEvents(b): +0x48 slot 0x90(b), +0x4c slot 0x94(b), +0x50 slot 0x88(b), each if set.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_5f2d60[], ext_5f5050[], ext_65bfe0[], ext_5492f0[], ext_4cd540[], ext_43ea20[], ext_45c510[],
    ext_4690b0[], ext_575800[], ext_574200[], ext_50b4b0[], ext_50d750[], ext_510b70[], ext_511700[], ext_634cf8[],
    ext_634ce6[];

extern "C" u32 THISCALL f15_42bdf0(void *self, const char *s) {
  const char *e = s;
  while (*e) e++;
  return ((u32(THISCALL *)(void *, const char *, const char *))X(5f2d60))(self, s, e);
}

typedef double (*AtofFn)(u32);
extern "C" float THISCALL f15_432470(void *self, u32 key, float def) {
  u32 p = vcall<u32>(self, 0x54, key);
  if (!p) return def;
  return (float)(*(AtofFn *)0x6762d4)(p);
}

extern "C" void THISCALL f15_54c270(void *self) {
  void *o = AT(void *, self, 0x63ec);
  if (!o) return;
  u32 flag = (AT(u8, self, 0x7b) != 0 || AT(u32, self, 0x75) == 3) ? 1 : 0;
  (*(void(STDCALL **)(void *, u32, u32, u32))(*(u8 **)o + 0x30))(o, 0, 0, flag);
}

extern "C" u32 THISCALL f15_5f4fb0(void *self, u32 *p) {
  u32 v = *p, lim = AT(u32, self, 8);
  if (v > lim) return ((u32(*)())G(void *, 0x7003b0))();
  u32 d = lim - v;
  return ((u32(THISCALL *)(void *, u32 *))X(5f5050))(self, &d);
}

extern "C" void THISCALL f15_4b59b0(void *self) {
  vcall<void>(self, 0x8c);
  AT(u32, self, 0xd6) = vcall<u32>((u8 *)self + 0xaa, 0x34, AT(u32, self, 0xea));
  AT(u32, self, 0xea) = 0xffffffffu;
}

extern "C" void THISCALL f15_4c2a70(void *self, u32 a, u32 b) {
  void *db = AT(void *, G(u8 *, 0x70039c), 0x9b);
  void *o = vcall<void *>(db, 0x58, AT(u32, self, 0xf8));
  if (o) vcall<void>(o, 0x128, a, b, 0u);
}

extern "C" void *THISCALL f15_65c7f0(void *self, u32 a, u32 b, u32 c, u32 d) {
  ((void(THISCALL *)(void *, u32, u32, u32, u32))X(65bfe0))(self, a, b, c, d);
  AT(u32, self, 0x182a1) = a;
  AT(u32, self, 0) = 0x6c47a0u;
  return self;
}

extern "C" void *THISCALL f15_54abf0(void *self) {
  ((void(THISCALL *)(void *))X(5492f0))(self);
  AT(u32, self, 0) = 0x6a36dcu;
  AT(u32, self, 0xa274) = 0;
  AT(u8, self, 0xa27c) = 1;
  AT(u8, self, 0xa273) = 0;
  return self;
}

extern "C" void THISCALL f15_4cd6f0(void *self, u32 id, s32 prio) {
  if (AT(u32, self, 0x14) == 0) {
    AT(s32, self, 0x20) = prio;
    AT(s32, self, 0x1c) = prio;
  } else {
    if (AT(s32, self, 0x20) < prio) AT(s32, self, 0x20) = prio;
    if (AT(s32, self, 0x1c) > prio) AT(s32, self, 0x1c) = prio;
  }
  s32 *r = ((s32 * (THISCALL *)(void *, u32)) X(4cd540))(self, id);
  r[AT(s32, self, 0x18) - 2] = prio;
}

extern "C" void *THISCALL f15_4f9930(void *self, u32 flags) {
  ((void(THISCALL *)(void *))X(43ea20))(self);
  if (flags & 1) {
    if (flags & 4) ((void (*)(void *, u32))X(4690b0))(self, 0x8f);
    else ((void (*)(void *))X(45c510))(self);
  }
  return self;
}

extern "C" u8 THISCALL f15_5758f0(void *self, u32 a) {
  if (vcall<u8>(self, 0xd8)) return 0;
  if (((u8(THISCALL *)(void *))X(575800))(self)) return 1;
  return ((u8(THISCALL *)(void *, u32))X(574200))(self, a);
}

extern "C" void f15_4ffbf0() {
  ((void (*)())X(50b4b0))();
  ((void (*)())X(50d750))();
  ((void (*)())X(510b70))();
  ((void (*)())X(511700))();
  for (int i = 0; i < 4; i++) ((void (*)())X(4690b0))();
  void *o = G(void *, 0x7003a4);
  if (o) vcall<void>(o, 0xc8, 0u);
}

extern "C" void THISCALL f15_63ee30(void *self) {
  AT(u8, self, 0xb949) |= 1;
  AT(u32, self, 0xb944) = 0xffffffffu;
  for (u32 i = 0; i != AT(u32, self, 0xec); i++) vcall<void>(AT(void *, self, 0xf0 + 4 * i), 0x38);
}

extern "C" void *THISCALL f15_6125b0(void *self, u32 flags) {
  AT(u32, self, 0) = 0x6bd5d0u;
  ((void(STDCALL *)(u32))X(634cf8))(AT(u32, self, 4));
  if (flags & 1) {
    if (flags & 4) ((void (*)(void *, u32))X(4690b0))(self, 0x10);
    else ((void(STDCALL *)(void *))X(634ce6))(self);
  }
  return self;
}

extern "C" s32 THISCALL f15_54aab0(void *self, s32 a) {
  s32 m = AT(s32, vcall<void *>(self, 0xa8), 0xc4);
  s32 v = a > m ? m : a;
  AT(s32, self, 0x805d) = v;
  AT(s32, self, 0x8029) = v;
  return v;
}

extern "C" void THISCALL f15_4a3cb0(void *self, u32 b) {
  void *o;
  if ((o = AT(void *, self, 0x48))) vcall<void>(o, 0x90, b);
  if ((o = AT(void *, self, 0x4c))) vcall<void>(o, 0x94, b);
  if ((o = AT(void *, self, 0x50))) vcall<void>(o, 0x88, b);
}

PCREG(42bdf0, f15_42bdf0);
PCREG(432470, f15_432470);
PCREG(54c270, f15_54c270);
PCREG(5f4fb0, f15_5f4fb0);
PCREG(4b59b0, f15_4b59b0);
PCREG(4c2a70, f15_4c2a70);
PCREG(65c7f0, f15_65c7f0);
PCREG(54abf0, f15_54abf0);
PCREG(4cd6f0, f15_4cd6f0);
PCREG(4f9930, f15_4f9930);
PCREG(5758f0, f15_5758f0);
PCREG(4ffbf0, f15_4ffbf0);
PCREG(63ee30, f15_63ee30);
PCREG(6125b0, f15_6125b0);
PCREG(54aab0, f15_54aab0);
PCREG(4a3cb0, f15_4a3cb0);
