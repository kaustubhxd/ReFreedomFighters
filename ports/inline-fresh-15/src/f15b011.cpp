// f15b011.cpp - fresh slice 15, batch 11 (2026-10-12).
// 0x624530 little2_isPublicId(enc, ptr, end, badPtr) (expat xmltok, UTF-16LE): byte type from enc+0x4c[lo] (hi == 0)
//          or 0x62c640(hi, lo); BT_S (21) bad only for TAB; BT_NMSTRT/BT_NAME (22/26) fine when ASCII; types 11, 12,
//          20, 28, 29 and anything outside 9..35 fine only for '$' / '@'; bad -> *badPtr = ptr, return 0; else 1.
// 0x455330 (ZSTDOBJ-derived ctor)(cls, name, geom): ZSTDOBJ ctor, vt 0x6828c4, +0xdd/+0x55/+0xed/+0x4d = 0;
//          ZParticleTemplate::GetTemplateList()->slot 4(db slot 0x4c(this)); return this.
// 0x601670 CSdlDataExchange::getExportSymbolFloat(name): first export [[+4]+4i] with type 1 and _stricmp(+0xc, name)
//          == 0 -> its float +4; else 0.0f. Index checks call [0x7003b0] (int3 when unset) like the exe.
// 0x5f2670 ZScriptDll::PlotScripts(filter): for each status line (getStatusString(i, proc)) whose process host name
//          matches filter (striwcmp == 0) or has no process: console ([0x70039c] slot 0x190) slot 0x184(10, y++, s);
//          return the number printed.
// 0x64d930 ZDrawArray<ZRoomViewEntry,...>::Remove(e): --count; block = slot 0x2c(e); push e on the block free list
//          (index (e - block - 16) / 36); empty block -> unlink, slot 0x34(block); else move it to the ring head +8.
// 0x64fd70 ZRenderBaseDll::InitBoneModifier: +0x38 set -> report (0x6c3180 line 0x7a6, 0x6c3660) + [0x7003b0]();
//          +0x38 = new ZRagdollContainer(6) (0x31 bytes) or 0.
// 0x572e70 CZoneMenu::~CZoneMenu (deleting): +0x44 = +0x30 = 0, vt 0x686874, db slot 0x34(this); flags&1: flags&4 ->
//          ZOctreeFuskeBaseKlasse::lort(this, 0x181), else [0x7003b0]() (int3 when unset).
// 0x5dbfb0 (ctor, vt 0x6b6ab8): base 0x469870, +4 |= 0x20, +0x44 = 0, +0x48 = new REFTAB(1, 0) or 0;
//          [0x714388] = (u16)db slot 0x114(0x692ae4, 0, 0x6b6b3c, 0x23).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_62c640[], ext_43de40[], ext_456bf0[], ext_5fc030[], ext_4cc1d0[], ext_5f49e0[], ext_4cc850[],
    ext_41e290[], ext_640d40[], ext_4690b0[], ext_469870[], ext_4ccbe0[];

static inline void *db() { return AT(void *, G(u8 *, 0x70039c), 0x9b); }
typedef u32 (*Fail)();
static inline u32 fail() {
  Fail f = G(Fail, 0x7003b0);
  if (!f) __builtin_trap();
  return f();
}

extern "C" s32 f15_624530(u8 *enc, u8 *p, u8 *end, u8 **bad) {
  p += 2;
  end -= 2;
  for (; p != end; p += 2) {
    u8 lo = p[0], hi = p[1];
    u32 t = hi ? ((u32(*)(u32, u32))X(62c640))(hi, lo) : enc[0x4c + lo];
    switch (t) {
    case 21:
      if (!hi && lo == 9) goto out;
      continue;
    case 22:
    case 26: {
      s32 v = hi ? -1 : (s8)lo;
      if (!(v & 0xffffff80)) continue;
      goto other;
    }
    case 11:
    case 12:
    case 20:
    case 28:
    case 29:
      goto other;
    default:
      if (t - 9 > 26) goto other;
      continue;
    }
  other:
    if (hi) goto out;
    if ((s8)lo == 0x24 || (s8)lo == 0x40) continue;
    goto out;
  }
  return 1;
out:
  *bad = p;
  return 0;
}

extern "C" void *THISCALL f15_455330(u8 *self, u32 cls, u32 name, u32 geom) {
  ((void(THISCALL *)(void *, u32, u32, u32))X(43de40))(self, cls, name, geom);
  AT(u32, self, 0) = 0x6828c4u;
  AT(u32, self, 0xdd) = 0;
  AT(u32, self, 0x55) = 0;
  AT(u32, self, 0xed) = 0;
  AT(u32, self, 0x4d) = 0;
  void *l = ((void *(*)())X(456bf0))();
  void *slot = AT(void *, AT(void *, l, 0), 4);
  u32 v = vcall<u32>(db(), 0x4c, self);
  ((void(THISCALL *)(void *, u32))slot)(l, v);
  return self;
}

typedef s32 (*Cmp)(u32, u32);
#define STRICMP (*(Cmp *)0x676414)
#define EXP(i) (**(u32 ***)(AT(u8 *, self, 4) + 4 * (i)))
extern "C" float THISCALL f15_601670(u8 *self, u32 name) {
  u32 i = 0;
  if (!AT(u32, self, 0xc)) return 0.0f;
  if (i >= AT(u32, self, 0xc)) fail();
  for (;;) {
    if (EXP(i)[0] == 1) {
      if (i >= AT(u32, self, 0xc)) fail();
      if (!STRICMP(EXP(i)[3], name)) {
        if (i >= AT(u32, self, 0xc)) fail();
        return *(float *)&EXP(i)[1];
      }
    }
    if (++i >= AT(u32, self, 0xc)) return 0.0f;
  }
}

typedef u32(THISCALL *Status)(void *, u32, void **);
extern "C" u32 THISCALL f15_5f2670(u8 *self, void *filter) {
  u32 y = 4, n = 0, i = 0;
  void *proc;
  u32 s = ((Status)X(5fc030))(AT(void *, AT(u8 *, self, 0xc), 4), 0, &proc);
  while (s) {
    i++;
    bool show = true;
    if (proc) {
      u32 f = ((u32(THISCALL *)(void *))X(4cc1d0))(filter);
      u32 h = ((u32(THISCALL *)(void *))X(5f49e0))(proc);
      show = ((s32(FASTCALL *)(u32, u32))X(4cc850))(h, f) == 0;
    }
    if (show) {
      void *con = vcall<void *>(G(void *, 0x70039c), 0x190);
      ((void (*)(void *, u32, u32, u32))AT(void *, AT(void *, con, 0), 0x184))(con, 10, y, s);
      y++;
      n++;
    }
    s = ((Status)X(5fc030))(AT(void *, AT(u8 *, self, 0xc), 4), i, &proc);
  }
  return n;
}

extern "C" void THISCALL f15_64d930(u8 *self, u8 *e) {
  AT(u32, self, 0xc)--;
  u8 *b = vcall<u8 *>(self, 0x2c, e);
  e[5] &= 0xfd;
  u16 nx = AT(u16, b, 2);
  b[0]--;
  AT(u16, e, 0) = nx;
  s32 ix = (s32)(e - b - 0x10) / 36;
  u8 empty = b[0] == 0;
  AT(u16, b, 2) = (u16)ix;
  if (empty) {
    if (AT(u8 *, self, 8) == b) {
      u8 *n = AT(u8 *, b, 8);
      AT(u8 *, self, 8) = n == b ? 0 : n;
    }
    AT(u8 *, AT(u8 *, b, 8), 0xc) = AT(u8 *, b, 0xc);
    AT(u8 *, AT(u8 *, b, 0xc), 8) = AT(u8 *, b, 8);
    vcall<void>(self, 0x34, b);
    return;
  }
  if (b == AT(u8 *, self, 8)) return;
  AT(u8 *, AT(u8 *, b, 8), 0xc) = AT(u8 *, b, 0xc);
  AT(u8 *, AT(u8 *, b, 0xc), 8) = AT(u8 *, b, 8);
  u8 *c = AT(u8 *, self, 8);
  AT(u8 *, b, 8) = c;
  u8 *p = AT(u8 *, c, 0xc);
  AT(u8 *, b, 0xc) = p;
  AT(u8 *, p, 8) = b;
  AT(u8 *, c, 0xc) = b;
  AT(u8 *, self, 8) = b;
}

typedef void (*Rep2)(void *, u32, ...);
extern "C" void THISCALL f15_64fd70(u8 *self) {
  if (AT(u32, self, 0x38)) {
    void *t = vcall<void *>(G(void *, 0x700390), 0x20, 0x6c3180u, 0x7a6u);
    ((Rep2)AT(void *, AT(void *, t, 0), 0x2c))(t, 0x6c3660u);
    fail();
  }
  void *p = ((void *(*)(u32))X(41e290))(0x31);
  AT(void *, self, 0x38) = p ? ((void *(THISCALL *)(void *, u32))X(640d40))(p, 6) : 0;
}

extern "C" void *THISCALL f15_572e70(u8 *self, u32 flags) {
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0x30) = 0;
  AT(u32, self, 0) = 0x686874u;
  vcall<void>(db(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) ((void (*)(void *, u32))X(4690b0))(self, 0x181);
    else fail();
  }
  return self;
}

extern "C" void *THISCALL f15_5dbfb0(u8 *self) {
  ((void(THISCALL *)(void *))X(469870))(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0) = 0x6b6ab8u;
  void *p = ((void *(*)(u32))X(41e290))(0x1c);
  AT(void *, self, 0x48) = p ? ((void *(THISCALL *)(void *, u32, u32))X(4ccbe0))(p, 1, 0) : 0;
  G(u16, 0x714388) = (u16)vcall<u32>(db(), 0x114, 0x692ae4u, 0u, 0x6b6b3cu, 0x23u);
  return self;
}

PCREG(624530, f15_624530);
PCREG(455330, f15_455330);
PCREG(601670, f15_601670);
PCREG(5f2670, f15_5f2670);
PCREG(64d930, f15_64d930);
PCREG(64fd70, f15_64fd70);
PCREG(572e70, f15_572e70);
PCREG(5dbfb0, f15_5dbfb0);
