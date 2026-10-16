// batch0111.cpp - fresh-01 batch 11 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" u8 THISCALL ext_4fa630(u8 *self, u8 *save);               // ZCONTROL::Save
extern "C" void THISCALL ext_469870(u8 *p);                          // shared base constructor
extern "C" void THISCALL ext_61ba30(u8 *self, u32 a);                // base constructor (1)
extern "C" void THISCALL ext_4cbeb0(u8 *s);                          // MYSTR::MYSTR()
extern "C" void THISCALL ext_4cbe80(u8 *s, u32 text);                // MYSTR::MYSTR(const char*)
extern "C" u32 THISCALL ext_4ccc30(u8 *p, u32 a, u32 b);             // table constructor
extern "C" void *ext_41e290(u32 size);                               // operator new
extern "C" void ext_4690b0(void *p, u32 size);                       // empty cdecl body (sized delete)

typedef void (*handlerFn)();
typedef void (*fmtFn)(void *, u32, u32, u32);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x4f7410, ZScrollArea::Save(ZSaveGame*): ZCONTROL::Save first (false ends it); then save slot 0x3c with the render ids
// (render slot 0x4c) of +0x8f and +0x93, slot 0x3c(+0x97), slot 0x10(this+0x9b, 8), slot 0x4c(float +0xa3) and slot
// 0x60(byte +0xa7). The save's vtable is read before each render call. Returns true.
static u8 THISCALL scrollAreaSave(u8 *self, u8 *save) {
  if (!ext_4fa630(self, save)) return 0;
  typedef void(THISCALL * f1)(void *, u32);
  u8 *vt = *(u8 **)save;
  u32 id = vcall<u32>(render(), 0x4c, *(u32 *)(self + 0x8f));
  (*(f1 *)(vt + 0x3c))(save, id);
  vt = *(u8 **)save;
  id = vcall<u32>(render(), 0x4c, *(u32 *)(self + 0x93));
  (*(f1 *)(vt + 0x3c))(save, id);
  vcall<void>(save, 0x3c, *(u32 *)(self + 0x97));
  vcall<void>(save, 0x10, self + 0x9b, 8u);
  vcall<void>(save, 0x4c, *(u32 *)(self + 0xa3));
  vcall<void>(save, 0x60, (u32)self[0xa7]);
  return 1;
}
PCREG(4f7410, scrollAreaSave);

// 0x4af390 (unnamed constructor, null-safe): base 0x469870, +4 |= 0x20, +0x44 = 0, vtable 0x690e10, word +0x5e = 0x100,
// word +0x5c = render RegisterZMsg (slot 0x114)(0x690ec8, 0, 0x690e98, 0x11). Returns this (0 for null).
static u8 *THISCALL ctor4af390(u8 *self) {
  if (!self) return 0;
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x690e10;
  *(u16 *)(self + 0x5e) = 0x100;
  *(u16 *)(self + 0x5c) = vcall<u16>(render(), 0x114, 0x690ec8u, 0u, 0x690e98u, 0x11u);
  return self;
}
PCREG(4af390, ctor4af390);

// 0x565190, CFileWindow::SetStringInBuffer(char* dst, const char* key, const int* num, const char* str) (ECX not used):
// nothing for a null key; fmt = (render+0xae4) slot 0(0x6a6a1c, key) (text lookup); with num: o = engine slot 0x190()
// and o's cdecl slot 0x198(o, dst, fmt, *num); else with str: the same with str; else strcpy(dst, fmt).
static void THISCALL fileWindowSetString(u8 *self, char *dst, u32 key, const u32 *num, u32 str) {
  if (!key) return;
  const char *fmt = vcall<const char *>(*(u8 **)(render() + 0xae4), 0, 0x6a6a1cu, key);
  if (num) {
    u8 *o = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
    (*(fmtFn *)(*(u8 **)o + 0x198))(o, (u32)dst, (u32)fmt, *num);
    return;
  }
  if (str) {
    u8 *o = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
    (*(fmtFn *)(*(u8 **)o + 0x198))(o, (u32)dst, (u32)fmt, str);
    return;
  }
  char ch;
  do {
    ch = *fmt++;
    *dst++ = ch;
  } while (ch);
}
PCREG(565190, fileWindowSetString);

// 0x43b710, ZInputActionSequence::ParseActionSequenceString (name map; body is a constructor (a, text)): base
// 0x61ba30(1), vtable 0x67bd4c, +8 = a, MYSTR() at +0x10 and +0xc3, MYSTR(text) at +0x143, MYSTR() at +0x1c3,
// +0x247 = +0x243 = 0. Returns this.
static u8 *THISCALL inputActionSeqCtor(u8 *self, u32 a, u32 text) {
  ext_61ba30(self, 1);
  *(u32 *)self = 0x67bd4c;
  *(u32 *)(self + 8) = a;
  ext_4cbeb0(self + 0x10);
  ext_4cbeb0(self + 0xc3);
  ext_4cbe80(self + 0x143, text);
  ext_4cbeb0(self + 0x1c3);
  *(u32 *)(self + 0x247) = 0;
  *(u32 *)(self + 0x243) = 0;
  return self;
}
PCREG(43b710, inputActionSeqCtor);

// 0x4e7dd0 (unnamed constructor (a)): byte +0x1c = 0; +0x18, +0x10, +0x14, +0xc = 0; +8 = +4 = this+0xc (empty list
// head); vtable 0x697614; +0x1d = 0x4ccc30(new(0x20); a, 5), or 0 when new fails. Returns this.
static u8 *THISCALL ctor4e7dd0(u8 *self, u32 a) {
  self[0x1c] = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u8 **)(self + 8) = self + 0xc;
  *(u8 **)(self + 4) = self + 0xc;
  *(u32 *)self = 0x697614;
  u8 *p = (u8 *)ext_41e290(0x20);
  *(u32 *)(self + 0x1d) = p ? ext_4ccc30(p, a, 5) : 0;
  return self;
}
PCREG(4e7dd0, ctor4e7dd0);

// 0x57bad0, ZFFLoadError scalar deleting destructor: +0x44 = +0x30 = 0, vtable 0x686874, render slot 0x34(this); with
// flag 1: flag 4 calls 0x4690b0(this, 0xcb6) (empty here), else the handler at [0x7003b0] (int3 when unset).
// Returns this.
static u8 *THISCALL loadErrorScalarDelete(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(render(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0xcb6);
    } else {
      handlerFn h = G(handlerFn, 0x7003b0);
      if (!h) __builtin_debugtrap();
      h();
    }
  }
  return self;
}
PCREG(57bad0, loadErrorScalarDelete);
