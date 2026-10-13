// fb1111.cpp - fresh slice 17, batch 11.
#include "ff.h"

extern "C" s32 ext_62c640(u32 hi, u32 lo);                                    // expat unicode_byte_type(hi, lo)
extern "C" u32 ext_4050f0(u32 a, u32 b);
extern "C" float *ext_405460(u32 *m);
extern "C" s32 ext_42ab0d(const char *s, const char *fmt, ...);               // sscanf
extern "C" u32 THISCALL ext_570cb0(void *self);                               // CSewerMenu::NextLevel
extern "C" u32 THISCALL ext_561be0(void *self);                               // CBaseWindow::AutoSaveEnabled
extern "C" u32 THISCALL ext_5ae710(void *prof, u32 flag);                     // CPlayerProfile::SaveRaw(bool)
extern "C" u32 THISCALL ext_59c620(void *lc);                                 // ZFFLevelController::SceneChange

typedef void (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

static inline void *engineDb() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x621c10 big2_isPublicId(enc, ptr, end, badPtr) (expat xmltok_impl.c, UTF-16BE: high byte first): checks the characters
// between the quotes. Byte type: high byte 0 -> enc->type[low] (+0x4c), else unicode_byte_type(hi, lo). BT_S (21) fails
// only on TAB; BT_NMSTRT / BT_NAME (22, 26) pass when ASCII; BT_GT, BT_QUOT, BT_LSQB, BT_OTHER, BT_NONASCII (11, 12, 20,
// 28, 29) and anything outside 9..35 pass only for '$' and '@'; the rest pass. Failure stores ptr in *badPtr and returns 0.
static s32 isPublicId621c10(u8 *enc, u8 *ptr, u8 *end, u8 **bad) {
  ptr += 2;
  end -= 2;
  for (; ptr != end; ptr += 2) {
    u8 hi = ptr[0], lo = ptr[1];
    s32 t = hi == 0 ? enc[0x4c + lo] : ext_62c640(hi, lo);
    switch (t) {
    case 21:
      if (hi == 0 && lo == 9)
        goto fail;
      continue;
    case 22:
    case 26:
      if (!((hi ? -1 : (s32)(s8)lo) & ~0x7f))
        continue;
      break;
    case 11:
    case 12:
    case 20:
    case 28:
    case 29:
      break;
    case 9:
    case 10:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 23:
    case 24:
    case 25:
    case 27:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
      continue;
    default:
      break;
    }
    if (hi == 0 && ((s8)lo == 0x24 || (s8)lo == 0x40))
      continue;
  fail:
    *bad = ptr;
    return 0;
  }
  return 1;
}
PCREG(621c10, isPublicId621c10);

// 0x405710 (GUESS matrix-info init, cdecl (info, m)): clears 7 words of info, info[2] = m, info[1] = m->rows (+4), info[0] =
// m->cols (+0), info[4] = 0x4050f0(m+8 word, rows), info[3] = data = 0x405460(m), info[6] = -1; with data, info[6] = the
// last row whose entries all have |x| <= 1e-12 (0x6be0b0). Returns 0.
static u32 matInfo405710(u32 *info, u32 *m) {
  for (int i = 0; i < 7; i++)
    info[i] = 0;
  info[2] = (u32)m;
  info[1] = m[1];
  info[0] = m[0];
  info[4] = ext_4050f0(m[2], m[1]);
  float *d = ext_405460(m);
  info[3] = (u32)d;
  info[6] = 0xffffffffu;
  if (!d)
    return 0;
  for (s32 r = 0; r < (s32)m[1]; r++) {
    s32 cols = (s32)m[0];
    s32 j = 0;
    for (; j < cols; j++)
      if ((double)__builtin_fabsf(d[cols * r + j]) > G(double, 0x6be0b0))
        break;
    if (j >= cols)
      info[6] = (u32)r;
  }
  return 0;
}
PCREG(405710, matInfo405710);

// 0x4834d0 (GUESS SetPosition(const char* "x,y,z")): sscanf(s, "%f,%f,%f") with 3 fields -> the object at this+0x104,
// slot +0x20, reads its matrix and position (slot +0x80(&m, &v)), the position is replaced and written back with slot
// +0x7c(&m, &v). /GS cookie not reproduced.
static void THISCALL setPos4834d0(u8 *self, const char *s) {
  if (!s)
    return;
  u32 x, y, z;
  if (ext_42ab0d(s, (const char *)0x68bcb0, &x, &y, &z) != 3)
    return;
  u32 m[9], v[3];
  void *o = vcall<void *>(*(void **)(self + 0x104), 0x20);
  vcall<u32>(o, 0x80, m, v);
  v[0] = x;
  v[1] = y;
  v[2] = z;
  o = vcall<void *>(*(void **)(self + 0x104), 0x20);
  vcall<u32>(o, 0x7c, m, v);
}
PCREG(4834d0, setPos4834d0);

// 0x49a6d0 ZLoadGame::GetRefTabRaw(LINKREFTAB*): reads kind and value (slot +0x14(&word) twice). Kind 1 -> 0; 2 -> engine
// db GetStaticBuffer (slot +0x17c) + value; 3 -> db slot +0x180 + value; 4 -> (engine +0x1aa3)->+0x18 slot +0xc(value);
// anything else -> assert hook (int3 when none), 0.
static u32 THISCALL getRefTabRaw49a6d0(void *self) {
  u32 kind = 0, val = 0;
  vcall<u32>(self, 0x14, &kind);
  vcall<u32>(self, 0x14, &val);
  switch (kind) {
  case 1:
    return 0;
  case 2:
    return vcall<u32>(engineDb(), 0x17c) + val;
  case 3:
    return vcall<u32>(engineDb(), 0x180) + val;
  case 4:
    return vcall<u32>(*(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18), 0xc, val);
  }
  if (!g_pAssertHook)
    __builtin_debugtrap();
  g_pAssertHook();
  return 0;
}
PCREG(49a6d0, getRefTabRaw49a6d0);

// 0x5707d0 CSewerMenu::EnterRebelBase(): NextLevel; with auto-save the menu owner (slot +0x84) +0xcb object is asked (slot
// +0x14): 0 -> owner slot +0x2f8(this+0x194), else this slot +0xd0(this+0x194). Without auto-save the profile (+0x94, +0x57)
// is saved (SaveRaw(false)) and, when the level name (+0x48) is "C01A" (0x6a7808), ZFFLevelController::SceneChange runs.
static void THISCALL enterRebelBase5707d0(u8 *self) {
  ext_570cb0(self);
  if (ext_561be0(self) & 0xff) {
    u8 *o = vcall<u8 *>(self, 0x84);
    if (vcall<u32>(o + 0xcb, 0x14) == 0) {
      u8 *o2 = vcall<u8 *>(self, 0x84);
      vcall<u32>(o2, 0x2f8, *(u32 *)(self + 0x194));
    } else {
      vcall<u32>(self, 0xd0, *(u32 *)(self + 0x194));
    }
    return;
  }
  ext_5ae710(*(u8 **)(self + 0x94) + 0x57, 0);
  u8 *p = *(u8 **)(self + 0x94);
  const u8 *a = p + 0x48, *b = (const u8 *)0x6a7808;
  for (;; a++, b++) {
    if (*a != *b)
      return;
    if (!*a)
      break;
  }
  ext_59c620(p);
}
PCREG(5707d0, enterRebelBase5707d0);

// 0x4b7190 CCutSequenceSoundStartStop::RemoveText(): when text is shown (+0x223): looks up 0x68c070 in the db object
// (db slot +0x138, then its slot +0x88(name, &ref)), +0x11b = db GeomRefToPtr(ref) (slot +0x58), +0x119 (word) =
// RegisterZMsg(0x692668, 0, 0x691edc, 0xc8b); the geom (when found) gets slot +0x130(itself, msg, 0). Clears +0x223.
static void THISCALL removeText4b7190(u8 *self) {
  if (!self[0x223])
    return;
  void *o = vcall<void *>(engineDb(), 0x138);
  u32 ref = 0;
  vcall<u32>(o, 0x88, 0x68c070u, &ref);
  *(u32 *)(self + 0x11b) = vcall<u32>(engineDb(), 0x58, ref);
  u32 msg = vcall<u32>(engineDb(), 0x114, 0x692668u, 0u, 0x691edcu, 0xc8bu);
  *(u16 *)(self + 0x119) = (u16)msg;
  void *g = *(void **)(self + 0x11b);
  if (g)
    vcall<u32>(g, 0x130, g, msg, 0u);
  self[0x223] = 0;
}
PCREG(4b7190, removeText4b7190);
