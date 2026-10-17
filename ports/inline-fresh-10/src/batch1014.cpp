// batch1014.cpp - fresh-10 batch 14: console flags, opaque user type, entity names, state batch walk, slider events.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FL(p, o) (*(float *)((u8 *)(p) + (o)))
static inline s32 Cvtt(float f) {
  s32 r;
  asm("cvttss2si %1, %0" : "=r"(r) : "x"(f));
  return r;
}
typedef void (*hook_t)();
static inline void Assert() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}

// 0x578aa0 ZControllerA::CheckConsoleCommands() (high): for the console values +0x1a8 (SetIV), +0x1ac (SetIH) and
// +0x1b0 (SetA): when not -1.0 ([0x67af2c]), call the setter with (int)value != 0 while +0x194 is 0 (restored after),
// reset the value to -1.0 and UpdateButtons().
extern "C" void THISCALL ext_579bd0(void *, u32);
extern "C" void THISCALL ext_579b20(void *, u32);
extern "C" void THISCALL ext_579a60(void *, u32);
extern "C" void THISCALL ext_579d20(void *);
typedef void(THISCALL *setb_t)(void *, u32);
static inline void Console(u8 *self, u32 off, setb_t set) {
  float v = FL(self, off);
  if (v == G(float, 0x67af2c)) return;
  u32 keep = F32(self, 0x194);
  F32(self, 0x194) = 0;
  set(self, Cvtt(v) != 0);
  F32(self, off) = 0xbf800000;
  F32(self, 0x194) = keep;
  ext_579d20(self);
}
static void THISCALL CheckConsoleCommands(u8 *self) {
  Console(self, 0x1a8, ext_579bd0);
  Console(self, 0x1ac, ext_579b20);
  Console(self, 0x1b0, ext_579a60);
}
PCREG(578aa0, CheckConsoleCommands);

// 0x6041e0 GUESS OpaqueUserType constructor (vtable 0x6b97b4; SEH frame): OpaqueUserType_t(info, buf); +0x18 = this+0xc,
// +0x1c/+0x20/+0x26 = 0; a temporary byte vector of 8 (CHostInterface::alloc), first byte 0, filled by info.slot6c;
// more than 0x20 bytes asserts; +0x24 = [[0x724278]+0x3c].slot0(text); the vector is freed (0x54f870).
extern "C" void THISCALL ext_603430(void *, void *, u32);
extern "C" u8 *THISCALL ext_6014a0(void *, u32);
extern "C" void THISCALL ext_54f870(void *, void *, u32);
static u8 *THISCALL OpaqueUserCtor(u8 *self, void *info, u32 buf) {
  ext_603430(self, info, buf);
  F32(self, 0) = 0x6b97b4;
  *(u8 **)(self + 0x18) = self + 0xc;
  F32(self, 0x1c) = 0;
  F32(self, 0x20) = 0;
  F32(self, 0x26) = 0;
  u8 *v[3] = {0, 0, 0};
  u8 *p = ext_6014a0(v, 8);
  v[0] = p;
  v[1] = p;
  v[2] = p + 8;
  *(volatile u8 *)p = 0;
  vcall<void>(info, 0x6c, v);
  if ((u32)(v[1] - v[0]) > 0x20) Assert();
  void *t = *(void **)(G(u8 *, 0x724278) + 0x3c);
  *(u16 *)(self + 0x24) = (u16)vcall<u32>(t, 0, v[0]);
  u32 n = v[2] - v[0];
  if (v[0] && n) ext_54f870(v, v[0], n);
  return self;
}
PCREG(6041e0, OpaqueUserCtor);

// 0x6252a0 expat little2_predefinedEntityName(enc, start, end) (GUESS name; cdecl): UTF-16LE "lt", "gt", "amp",
// "apos", "quot" give '<', '>', '&', '\'', '"'; anything else 0. Length = (end - start) / 2 (signed).
static u32 PredefinedEntityName(void *, const u8 *p, const u8 *end) {
  s32 n = (s32)(end - p) / 2;
  if (n == 2) {
    if (p[3] || p[2] != 't' || p[1]) return 0;
    if (p[0] == 'g') return '>';
    if (p[0] == 'l') return '<';
    return 0;
  }
  if (n == 3) {
    if (!p[1] && p[0] == 'a' && !p[3] && p[2] == 'm' && !p[5] && p[4] == 'p') return '&';
    return 0;
  }
  if (n == 4 && !p[1]) {
    if (p[0] == 'a') {
      if (!p[3] && p[2] == 'p' && !p[5] && p[4] == 'o' && !p[7] && p[6] == 's') return '\'';
    } else if (p[0] == 'q') {
      if (!p[3] && p[2] == 'u' && !p[5] && p[4] == 'o' && !p[7] && p[6] == 't') return '"';
    }
  }
  return 0;
}
PCREG(6252a0, PredefinedEntityName);

// 0x65c3e0 GUESS state-sorted batch walk (thiscall, one unread stack word): from cursor +0x24 to the end of the
// (+0x20 + 5) * 8 table, entries {key, item}: a key equal to the last runs only slot80(item, group); a key with low
// nibble 9 stops (after it); a change in bits 0x78000000 calls slot44(item +0x14 -> +0x20) unless all four are set
// (then the entry is skipped); a new group (low nibble) closes the old one (slot7c) and opens it (slot78); a change
// in bits 0x7ff0 with an item +8 calls slot74(it, group); then slot80(item, group). Cursor saved; an open group is
// closed (slot7c). Returns cursor != end. The group goes as a byte (the exe pushes a dword whose upper bytes are
// stale stack).
static u8 THISCALL BatchWalk(u8 *self, u32) {
  u32 *end = (u32 *)(self + (F32(self, 0x20) + 5) * 8);
  u32 *e = *(u32 **)(self + 0x24);
  if (e == end) return 0;
  u32 last = 0xffffffff;
  u8 grp = 0xff;
  for (;;) {
    u32 k = e[0];
    u8 *it = (u8 *)e[1];
    if (last != k) {
      if ((k & 0xf) == 9) {
        e += 2;
        break;
      }
      if ((k ^ last) & 0x78000000) {
        if ((k & 0x78000000) == 0x78000000) goto next;
        vcall<void>(self, 0x44, F32(*(u8 **)(it + 0x14), 0x20));
      }
      if (grp != (u8)(e[0] & 0xf)) {
        if (grp != 0xff) vcall<void>(self, 0x7c, (u32)grp);
        grp = e[0] & 0xf;
        vcall<void>(self, 0x78, (u32)grp);
      }
      if (((e[0] ^ last) & 0x7ff0) && *(void **)(it + 8)) vcall<void>(self, 0x74, *(u32 *)(it + 8), (u32)grp);
      last = e[0];
    }
    vcall<void>(self, 0x80, (u32)it, (u32)grp);
  next:
    e += 2;
    if (e == end) break;
  }
  *(u32 **)(self + 0x24) = e;
  if (grp != 0xff) vcall<void>(self, 0x7c, (u32)grp);
  return e != end;
}
PCREG(65c3e0, BatchWalk);

// 0x4f8120 ZSlider::OnStateChanged(unsigned, unsigned) (high): only for its own id (+0xab). State 2: +0xcf = the
// system's (slot2c4) slot308 position x, +0xd3 = 1, then as 8: system.slot34c(0xc, 0x102 / 0x103, this, 10.0f, 1).
// State 1: system.slot350(0xc, 0x102 / 0x103, this); a pending +0xd3 is cleared with slot358(). False (AL).
static u8 THISCALL SliderOnStateChanged(u8 *self, u32 id, u32 st) {
  if (id != F32(self, 0xab)) return 0;
  if (st == 1) {
    vcall<void>(vcall<void *>(self, 0x2c4), 0x350, 0xcu, 0x102u, self);
    vcall<void>(vcall<void *>(self, 0x2c4), 0x350, 0xcu, 0x103u, self);
    if (self[0xd3]) {
      self[0xd3] = 0;
      vcall<void>(self, 0x358);
    }
    return 0;
  }
  if (st == 2) {
    float t[2];
    vcall<void>(vcall<void *>(self, 0x2c4), 0x308, t);
    FL(self, 0xcf) = t[0];
    self[0xd3] = 1;
  } else if (st != 8) {
    return 0;
  }
  vcall<void>(vcall<void *>(self, 0x2c4), 0x34c, 0xcu, 0x102u, self, 0x41200000u, 1u);
  vcall<void>(vcall<void *>(self, 0x2c4), 0x34c, 0xcu, 0x103u, self, 0x41200000u, 1u);
  return 0;
}
PCREG(4f8120, SliderOnStateChanged);
