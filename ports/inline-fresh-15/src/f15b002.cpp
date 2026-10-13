// f15b002.cpp - fresh slice 15, batch 2 (2026-10-12): next 16 smallest of residue 15.
// 0x54a6f0: [this+0x8061] slot 8 (if set), then tail call ZSynth::Render 0x54dd00(this).
// 0x57c1f0 ZFFAutoSave::DiscardChanges: 0x561f50(byte this+0x184) (stdcall 1, forwards to sys slot 0xbc -> slot 0xa4), this slot 0xd0(0).
// 0x60fdb0: ecx = state value; cached at 0x724938; on change device [0x724a00] slot 0xc8(dev, 0xf, v) (COM stdcall).
// 0x658fb0 ZGeomDrawEntry::SetEnvironment: this+0x44 = p; byte this+0x3c bit 3 = (p != 0).
// 0x659af0: stdcall(p): [p+0x18] slot 0(1) if set, then [p+0x18] = 0.
// 0x6526b0: for o = [[0x70039c]+0x190f]; o; o = [o+8]: o slot 8.
// 0x4cbdf0 ZTextureAnim::Save(ZSaveGame*): this+4 &= ~0x40; save slot 0x4c(float this+0x4c); returns true.
// 0x577830 / 0x4b1c70 / 0x4baeb0: ctors over a base ctor (0x573590 / 0x469870), vtable 0x6a9768 / 0x691c70 / 0x692b7c.
// 0x6567b0 ZPrimControlBase::GetSpotLightSquareData(i, out): this slot 0x154(out, this slot 0xc(i)); returns true.
// 0x573af0 ZBaseMap::EnableCam(u32): db = [[0x70039c]+0x9b]; db slot 0x58(a) -> r; returns r slot 0x250().
// 0x5726f0 CSubtitle::CopyEventDataBlock(DBREAD&): +0x87a = (u32)rd, +0x87e = (bool)rd.
// 0x5734b0 CZoneMenu::OnWindowOpen(u32, bool): ZVideoSelector::OnWindowOpen, EnableLastLevel(byte +0x180); returns false.
// 0x49cd70 CListUser::UnfoldList(u32 *out, u32 n): r = PriUnfoldList([this+0x39], n); *out = hi16(r) + lo16(r); returns [this+0x39].
// 0x54fd30 CFFScriptInterfaceDll::End: clear byte +0xc; [0x7003a4] slot 0xc8(1); t = 0x557930(0); tail t slot 0x28().
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_54dd00[], ext_561f50[], ext_573590[], ext_469870[], ext_4e5e60[], ext_4e5ef0[], ext_563110[],
    ext_573000[], ext_49c980[], ext_557930[];

extern "C" u32 THISCALL f15_54a6f0(void *self) {
  void *o = AT(void *, self, 0x8061);
  if (o) vcall<void>(o, 8);
  return ((u32(THISCALL *)(void *))X(54dd00))(self);
}

extern "C" void THISCALL f15_57c1f0(void *self) {
  ((void(STDCALL *)(u32))X(561f50))(AT(u8, self, 0x184));
  vcall<void>(self, 0xd0, 0u);
}

extern "C" void THISCALL f15_60fdb0(u32 v) {
  if (G(u32, 0x724938) == v) return;
  void *dev = G(void *, 0x724a00);
  G(u32, 0x724938) = v;
  (*(void(STDCALL **)(void *, u32, u32))(*(u8 **)dev + 0xc8))(dev, 0xf, v);
}

extern "C" void THISCALL f15_658fb0(void *self, void *p) {
  AT(void *, self, 0x44) = p;
  if (p) AT(u8, self, 0x3c) |= 8;
  else AT(u8, self, 0x3c) &= 0xf7;
}

extern "C" void STDCALL f15_659af0(void *p) {
  void *o = AT(void *, p, 0x18);
  if (o) vcall<void>(o, 0, 1u);
  AT(u32, p, 0x18) = 0;
}

extern "C" void f15_6526b0() {
  for (void *o = AT(void *, G(u8 *, 0x70039c), 0x190f); o; o = AT(void *, o, 8)) vcall<void>(o, 8);
}

extern "C" u8 THISCALL f15_4cbdf0(void *self, void *save) {
  AT(u32, self, 4) &= ~0x40u;
  vcall<void>(save, 0x4c, AT(float, self, 0x4c));
  return 1;
}

extern "C" void *THISCALL f15_577830(void *self) {
  ((void(THISCALL *)(void *))X(573590))(self);
  AT(u32, self, 0) = 0x6a9768u;
  AT(u8, self, 0x20f) = 0;
  return self;
}

extern "C" void *THISCALL f15_4b1c70(void *self) {
  ((void(THISCALL *)(void *))X(469870))(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0) = 0x691c70u;
  return self;
}

extern "C" void *THISCALL f15_4baeb0(void *self) {
  ((void(THISCALL *)(void *))X(469870))(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0) = 0x692b7cu;
  return self;
}

extern "C" u8 THISCALL f15_6567b0(void *self, u32 i, void *out) {
  u32 d = vcall<u32>(self, 0xc, i);
  vcall<void>(self, 0x154, out, d);
  return 1;
}

extern "C" u32 THISCALL f15_573af0(void *self, u32 a) {
  void *db = AT(void *, G(u8 *, 0x70039c), 0x9b);
  void *r = vcall<void *>(db, 0x58, a);
  return vcall<u32>(r, 0x250);
}

extern "C" u8 THISCALL f15_5726f0(void *self, void *rd) {
  AT(u32, self, 0x87a) = ((u32(THISCALL *)(void *))X(4e5e60))(rd);
  u8 b = ((u8(THISCALL *)(void *))X(4e5ef0))(rd);
  AT(u8, self, 0x87e) = b;
  return b;
}

extern "C" u8 THISCALL f15_5734b0(void *self, u32 a, u32 b) {
  ((void(THISCALL *)(void *, u32, u32))X(563110))(self, a, b);
  ((void(THISCALL *)(void *, u32))X(573000))(self, AT(u8, self, 0x180));
  return 0;
}

extern "C" u32 THISCALL f15_49cd70(void *self, u32 *out, u32 n) {
  u32 r = ((u32(THISCALL *)(void *, u32, u32))X(49c980))(self, AT(u32, self, 0x39), n);
  *out = (r >> 16) + (r & 0xffff);
  return AT(u32, self, 0x39);
}

extern "C" u32 THISCALL f15_54fd30(void *self) {
  if (AT(u8, self, 0xc)) AT(u8, self, 0xc) = 0;
  vcall<void>(G(void *, 0x7003a4), 0xc8, 1u);
  void *t = ((void *(THISCALL *)(void *))X(557930))(nullptr);
  return vcall<u32>(t, 0x28);
}

PCREG(54a6f0, f15_54a6f0);
PCREG(57c1f0, f15_57c1f0);
PCREG(60fdb0, f15_60fdb0);
PCREG(658fb0, f15_658fb0);
PCREG(659af0, f15_659af0);
PCREG(6526b0, f15_6526b0);
PCREG(4cbdf0, f15_4cbdf0);
PCREG(577830, f15_577830);
PCREG(6567b0, f15_6567b0);
PCREG(573af0, f15_573af0);
PCREG(4b1c70, f15_4b1c70);
PCREG(4baeb0, f15_4baeb0);
PCREG(5726f0, f15_5726f0);
PCREG(5734b0, f15_5734b0);
PCREG(49cd70, f15_49cd70);
PCREG(54fd30, f15_54fd30);
