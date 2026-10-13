// f16b017.cpp - fresh slice 16, batch 17 (2026-10-12).
// 0x607d00 (thiscall dev, len*, usage) index-buffer holder ctor: fills the D3D8 index-buffer desc at +0xc (format 0x65 =
//           D3DFMT_INDEX16, type 7, usage | 0x208, size = [len] * 2), then IDirect3DDevice8::CreateIndexBuffer (slot 0x60,
//           stdcall this + 5) into +0 and, if created, IDirect3DIndexBuffer8::GetDesc (slot 0x34) into a stack buffer that is
//           never read. Returns this; ret 0xc. Stack cookie not reproduced. (D3D8 slot names are inferred from the slot
//           numbers and arguments: a GUESS.)
// 0x454f80 ZMaterialDesc::Load(ZLoadGame*): ZGEOM::Load, then ZLoadGame slots 0x40 x5, 0x50, 0x48, 0x40 x4 into fixed
//           fields. Returns true.
// 0x4811c0 ZPlayerTest scalar deleting destructor: vtable 0x68c0bc; [[0x70039c]+0x1907] slot 0x14(0x68c708) when set;
//           0x480ff0(this); flags & 1: flags & 4 -> 0x4690b0(this, 0x64b) (cdecl), else operator delete. SEH not reproduced.
// 0x5c3740 ctor: null -> 0; 0x469870(this); +4 |= 0x20; +0x44 = 0; vtable 0x6b3de4; word [0x714338] = RegisterZMsg
//           (db slot 0x114)(0x6ad080, 0, 0x6b3e68, 0x1b). SEH not reproduced.
// 0x442380 / 0x442ec0 ZTreeGroup::Attach/DetachTreeGroupChilds(ZBaseGeom* g): when g's class flags have 0x100000:
//           tg = [this+8]->GetTreeGroup(); tg && g->IsDerivedFrom(0x100020): c = [g+0x54]; !c slot 0x310() -> tg slot
//           0x2c8/0x2cc(c). Not derived: walk n = [[g+0x54]+0x50] via +0x60 while n's flags have 0x100000, calling this
//           slot 0x2f8/0x2fc(n). Flags = [[[n+0x54]+0xc]+0x23], or 0x200002 when +0x54 is null.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45f3c0[], ext_480ff0[], ext_4690b0[], ext_45c510[], ext_469870[], ext_4db7e0[], ext_4db9a0[];

extern "C" u8 *THISCALL f16_607d00(u8 *self, void **dev, u32 *len, u32 usage) {
  AT(u32, self, 0) = 0;
  AT(u32, self, 8) = 0;
  AT(u16, self, 0xc) = 0x100;
  AT(u32, self, 4) = *len;
  AT(u32, self, 0xe) = 0;
  AT(u32, self, 0x12) = 0;
  AT(u32, self, 0x16) = 0;
  AT(u32, self, 0x1a) = 0;
  AT(u32, self, 0x1e) = 0;
  AT(u32, self, 0xe) = 0x65;
  AT(u32, self, 0x12) = 7;
  AT(u32, self, 0x1e) = *len * 2;
  AT(u32, self, 0x1a) = 0;
  u32 u = usage | 0x208;
  AT(u32, self, 0x16) = u;
  void **vt = *(void ***)dev;
  ((u32(STDCALL *)(void *, u32, u32, u32, u32, void *))vt[0x60 / 4])(dev, AT(u32, self, 4) * 2, u, 0x65, 0, self);
  void *ib = AT(void *, self, 0);
  if (ib) {
    u32 desc[6];
    ((u32(STDCALL *)(void *, void *))(*(void ***)ib)[0x34 / 4])(ib, desc);
  }
  return self;
}

extern "C" bool THISCALL f16_454f80(u8 *self, void *lg) {
  ((u32(THISCALL *)(void *, void *))(void *)ext_45f3c0)(self, lg);
  static const u8 offs[] = {0x18, 0x1c, 0x20, 0x34, 0x28};
  for (u8 o : offs) vcall<u32>(lg, 0x40, self + o);
  vcall<u32>(lg, 0x50, self + 0x30);
  vcall<u32>(lg, 0x48, self + 0x2c);
  static const u8 offs2[] = {0x24, 0x3c, 0x40, 0x44, 0x48};
  for (u8 o : offs2) vcall<u32>(lg, 0x40, self + o);
  return true;
}

extern "C" void *THISCALL f16_4811c0(u32 *self, u32 flags) {
  self[0] = 0x68c0bcu;
  void *m = AT(void *, G(u8 *, 0x70039c), 0x1907);
  if (m) vcall<void>(m, 0x14, 0x68c708u);
  ((void(THISCALL *)(void *))(void *)ext_480ff0)(self);
  if (flags & 1) {
    if (flags & 4)
      ((void (*)(void *, u32))(void *)ext_4690b0)(self, 0x64b);
    else
      ((void (*)(void *))(void *)ext_45c510)(self);
  }
  return self;
}

extern "C" void *THISCALL f16_5c3740(u8 *self) {
  if (!self) return 0;
  ((void(THISCALL *)(void *))(void *)ext_469870)(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0) = 0x6b3de4u;
  u32 id = vcall<u32>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x114, 0x6ad080u, 0u, 0x6b3e68u, 0x1bu);
  G(u16, 0x714338) = (u16)id;
  return self;
}

static inline u32 tgflags(u8 *n) {
  u8 *c = AT(u8 *, n, 0x54);
  return c ? AT(u32, AT(u8 *, c, 0xc), 0x23) : 0x200002u;
}

static inline void tgchilds(u8 *self, u8 *g, u32 slot_tg, u32 slot_me) {
  if (!(tgflags(g) & 0x100000)) return;
  void *tg = ((void *(THISCALL *)(void *))(void *)ext_4db7e0)(AT(void *, self, 8));
  if (!tg) return;
  if (((bool(THISCALL *)(void *, u32))(void *)ext_4db9a0)(g, 0x100020u)) {
    void *c = AT(void *, g, 0x54);
    if (!vcall<bool>(c, 0x310)) vcall<void>(tg, slot_tg, c);
    return;
  }
  for (u8 *n = AT(u8 *, AT(u8 *, g, 0x54), 0x50); n; n = AT(u8 *, n, 0x60)) {
    if (!(tgflags(n) & 0x100000)) return;
    vcall<void>(self, slot_me, n);
  }
}

extern "C" void THISCALL f16_442380(u8 *self, u8 *g) { tgchilds(self, g, 0x2c8, 0x2f8); }
extern "C" void THISCALL f16_442ec0(u8 *self, u8 *g) { tgchilds(self, g, 0x2cc, 0x2fc); }

PCREG(607d00, f16_607d00);
PCREG(454f80, f16_454f80);
PCREG(4811c0, f16_4811c0);
PCREG(5c3740, f16_5c3740);
PCREG(442380, f16_442380);
PCREG(442ec0, f16_442ec0);
