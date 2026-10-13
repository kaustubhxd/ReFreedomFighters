// f15b006.cpp - fresh slice 15, batch 6 (2026-10-12).
// 0x4bee70 / 0x5bdbf0: factories as batch 5 (allocator [[0x70039c]+0x9b]+8 slot 0x44(ecx), base 0x469870), vt 0x6934dc / 0x6b34b4.
// 0x4a3a30 ZSoundMove::Load(lg): +4 &= ~0x40; lg slot 0x40(&id); +0x48 = db slot 0x58(id); lg slot 0x6c(+0x4c, +0x58, +0x64),
//          slot 0x50(+0x74), slot 0x40(+0x124, +0x128); returns true.
// 0x4c26b0 ZMusicSegment::Save(sg): +4 &= ~0x40; sg slots 0x44 +0x48, 0x44 +0x4c, 0x3c +0x50, 0x44 +0x54, 0x60 byte +0x58,
//          0x4c floats +0x59 +0x5d +0x61; returns true.
// 0x5efe70 CMessageHint::Save(sg): CMessageTextBox::Save, sg slot 0x4c floats +0x84..+0x90, 0x3c +0x94, 0x60 byte +0x98.
// 0x569730: dtor body: vt 0x6a7600, delete(+0x1bd, 1), delete(+0x1c1, 1), +0x44 = +0x30 = 0, vt 0x686874, db slot 0x34(this).
// 0x6503b0 ZRenderBaseDll::PopScene: free scene +0x38 (0x640ea0 + delete 0x31); byte +0x88 -> [0x70039c]+0x190f slot 0x44(f +0x84, +0x80);
//          that object +0x5c = 1 if set; byte +0x88 = 0; this slot 0x9c(+0x3c - 1).
// 0x452b30 ZENVIRONMENT::ClassInit: unless +0x18 & 0xc000: walk manager slot 0x25c(0x681b04, prev) objects of the same
//          manager (slot 0x20); flag 0x4000 -> +0x1c, 0x8000 -> +0x20.
// 0x64faf0 ZRender::GetCamera(i): iterate +0x8c (slot 0x4c init, 0x5c next until it[0] == 0), items unknown to db slot 0x58
//          get slot 0x44(&it); returns +0x8c slot 0x30(i).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_469870[], ext_5ee970[], ext_634273[], ext_640ea0[];

static inline void *make469(u32 ecx, u32 vt) {
  void *a = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 8);
  void *o = vcall<void *>(a, 0x44, ecx);
  if (o) {
    ((void(THISCALL *)(void *))X(469870))(o);
    AT(u32, o, 4) |= 0x20;
    AT(u32, o, 0x44) = 0;
    AT(u32, o, 0) = vt;
  }
  return o;
}
extern "C" void *THISCALL f15_4bee70(u32 ecx) { return make469(ecx, 0x6934dcu); }
extern "C" void *THISCALL f15_5bdbf0(u32 ecx) { return make469(ecx, 0x6b34b4u); }

static inline void *db() { return AT(void *, G(u8 *, 0x70039c), 0x9b); }

extern "C" u8 THISCALL f15_4a3a30(u8 *self, void *lg) {
  u32 id;
  AT(u32, self, 4) &= ~0x40u;
  vcall<void>(lg, 0x40, (void *)&id);
  AT(u32, self, 0x48) = vcall<u32>(db(), 0x58, id);
  vcall<void>(lg, 0x6c, (void *)(self + 0x4c));
  vcall<void>(lg, 0x6c, (void *)(self + 0x58));
  vcall<void>(lg, 0x6c, (void *)(self + 0x64));
  vcall<void>(lg, 0x50, (void *)(self + 0x74));
  vcall<void>(lg, 0x40, (void *)(self + 0x124));
  vcall<void>(lg, 0x40, (void *)(self + 0x128));
  return 1;
}

extern "C" u8 THISCALL f15_4c26b0(u8 *self, void *sg) {
  AT(u32, self, 4) &= ~0x40u;
  vcall<void>(sg, 0x44, AT(u32, self, 0x48));
  vcall<void>(sg, 0x44, AT(u32, self, 0x4c));
  vcall<void>(sg, 0x3c, AT(u32, self, 0x50));
  vcall<void>(sg, 0x44, AT(u32, self, 0x54));
  vcall<void>(sg, 0x60, (u32)AT(u8, self, 0x58));
  vcall<void>(sg, 0x4c, AT(float, self, 0x59));
  vcall<void>(sg, 0x4c, AT(float, self, 0x5d));
  vcall<void>(sg, 0x4c, AT(float, self, 0x61));
  return 1;
}

extern "C" void THISCALL f15_5efe70(u8 *self, void *sg) {
  ((void(THISCALL *)(void *, void *))X(5ee970))(self, sg);
  vcall<void>(sg, 0x4c, AT(float, self, 0x84));
  vcall<void>(sg, 0x4c, AT(float, self, 0x88));
  vcall<void>(sg, 0x4c, AT(float, self, 0x8c));
  vcall<void>(sg, 0x4c, AT(float, self, 0x90));
  vcall<void>(sg, 0x3c, AT(u32, self, 0x94));
  vcall<void>(sg, 0x60, (u32)AT(u8, self, 0x98));
}

typedef void (*Del)(void *, u32);
extern "C" void THISCALL f15_569730(u8 *self) {
  AT(u32, self, 0) = 0x6a7600u;
  ((Del)X(634273))(AT(void *, self, 0x1bd), 1);
  ((Del)X(634273))(AT(void *, self, 0x1c1), 1);
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0x30) = 0;
  AT(u32, self, 0) = 0x686874u;
  vcall<void>(db(), 0x34, (void *)self);
}

extern "C" void THISCALL f15_6503b0(u8 *self) {
  void *s = AT(void *, self, 0x38);
  if (s) {
    ((void(THISCALL *)(void *))X(640ea0))(s);
    ((Del)X(634273))(s, 0x31);
  }
  AT(u32, self, 0x38) = 0;
  if (AT(u8, self, 0x88))
    vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x190f), 0x44, AT(float, self, 0x84), AT(u32, self, 0x80));
  u8 *o = AT(u8 *, G(u8 *, 0x70039c), 0x190f);
  if (o) AT(u32, o, 0x5c) = 1;
  u32 n = AT(u32, self, 0x3c) - 1;
  AT(u8, self, 0x88) = 0;
  vcall<void>(self, 0x9c, n);
}

extern "C" void THISCALL f15_452b30(u8 *self) {
  if (AT(u32, self, 0x18) & 0xc000) return;
  void *m = vcall<void *>(self, 0x20);
  u8 *s = vcall<u8 *>(m, 0x25c, 0x681b04u, 0u);
  while (s) {
    u32 a = vcall<u32>(s, 0x20);
    if (a == vcall<u32>(self, 0x20)) {
      if (AT(u32, s, 0x18) & 0x4000) AT(u8 *, self, 0x1c) = s;
      if (AT(u32, s, 0x18) & 0x8000) AT(u8 *, self, 0x20) = s;
    }
    u32 nx = AT(u32, s, 8);
    m = vcall<void *>(self, 0x20);
    s = vcall<u8 *>(m, 0x25c, 0x681b04u, nx);
  }
}

extern "C" u32 THISCALL f15_64faf0(u8 *self, u32 i) {
  if (AT(void *, self, 0x8c)) {
    u32 it[3];
    vcall<void>(AT(void *, self, 0x8c), 0x4c, (void *)it);
    u32 x = vcall<u32>(AT(void *, self, 0x8c), 0x5c, (void *)it);
    while (it[0]) {
      if (!vcall<u32>(db(), 0x58, x)) vcall<void>(AT(void *, self, 0x8c), 0x44, (void *)it);
      x = vcall<u32>(AT(void *, self, 0x8c), 0x5c, (void *)it);
    }
  }
  return vcall<u32>(AT(void *, self, 0x8c), 0x30, i);
}

PCREG(4bee70, f15_4bee70);
PCREG(5bdbf0, f15_5bdbf0);
PCREG(4a3a30, f15_4a3a30);
PCREG(4c26b0, f15_4c26b0);
PCREG(5efe70, f15_5efe70);
PCREG(569730, f15_569730);
PCREG(6503b0, f15_6503b0);
PCREG(452b30, f15_452b30);
PCREG(64faf0, f15_64faf0);
