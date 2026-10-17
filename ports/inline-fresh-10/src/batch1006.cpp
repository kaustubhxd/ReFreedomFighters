// batch1006.cpp - fresh-10 batch 6: save/hide/list helpers, DOS time packing, draw-array add (slice 10).
#include "ff.h"

typedef u32 (*hookr_t)();
static inline u32 AssertHook() {
  hookr_t h = G(hookr_t, 0x7003b0);
  if (!h) asm volatile("int3");
  return h();
}
static inline void *Scene() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4f0ce0 ZCHAROBJ::Save(ZSaveGame*) (high): ZWINOBJ::Save first (false stops); then dword(+0x93),
// geom id scene.slot4c(+0x9f) (slot 3c), dword(+0xa3), string +0x97 (or "" at 0x677b5a) (slot 5c); true.
extern "C" u8 THISCALL ext_4f0d70(void *, void *);   // bool in AL; tested as a byte
static bool THISCALL CharObjSave(u8 *self, void *sv) {
  u8 ok = ext_4f0d70(self, sv);
  asm volatile("" : "+r"(ok));   // keep the byte test (a bool return would be assumed 0/1)
  if (!ok) return false;
  u32 g = vcall<u32>(Scene(), 0x4c, F32(self, 0x9f));
  vcall<void>(sv, 0x44, F32(self, 0x93));
  vcall<void>(sv, 0x3c, g);
  vcall<void>(sv, 0x44, F32(self, 0xa3));
  u32 s = F32(self, 0x97);
  vcall<void>(sv, 0x5c, s ? s : 0x677b5au);
  return true;
}
PCREG(4f0ce0, CharObjSave);

// 0x5d49e0 GUESS creator (SEH frame in the exe): o = (scene+8).slot44(this); if o: 0x469870(o), flags (+4) |= 0x20,
// +0x44 = 0, vtable 0x6b5304, byte +0x5c = 0, +0x5d = 0; returns o.
extern "C" void THISCALL ext_469870(void *);
static u8 *THISCALL Create5d49e0(u8 *self) {
  u8 *o = vcall<u8 *>(*(void **)((u8 *)Scene() + 8), 0x44, self);
  if (o) {
    ext_469870(o);
    F32(o, 4) |= 0x20;
    F32(o, 0x44) = 0;
    F32(o, 0) = 0x6b5304;
    o[0x5c] = 0;
    F32(o, 0x5d) = 0;
  }
  return o;
}
PCREG(5d49e0, Create5d49e0);

// 0x428560 GUESS constructor (SEH frame): base 0x4359f0(1); vtable 0x678dc0; +0xd, +0x35..+0x41 = 0; the four
// argument dwords copied to +0x25; name "WintelMouse" (0x679334) through 0x4361a0; returns this.
extern "C" void THISCALL ext_4359f0(void *, u32);
extern "C" void THISCALL ext_4361a0(void *, u32);
static u8 *THISCALL Ctor428560(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  ext_4359f0(self, 1);
  F32(self, 0) = 0x678dc0;
  F32(self, 0xd) = 0;
  F32(self, 0x35) = 0;
  F32(self, 0x39) = 0;
  F32(self, 0x3d) = 0;
  F32(self, 0x41) = 0;
  F32(self, 0x25) = a;
  F32(self, 0x29) = b;
  F32(self, 0x2d) = c;
  F32(self, 0x31) = d;
  ext_4361a0(self, 0x679334);
  return self;
}
PCREG(428560, Ctor428560);

// 0x4f3ee0 ZWINDOW::Hide(bool) (medium): ZGEOM::Hide(b); showing: w = slot2e0(), if w: manager (slot2c4).slot2ec(w);
// hiding: first = manager.slot2f0(); walk first, ->slot20() ... ; when this is in the chain: manager.slot2f4(first, 1).
extern "C" void THISCALL ext_45f070(void *, u32);
static void THISCALL WindowHide(u8 *self, u32 b) {
  ext_45f070(self, b);
  if (!(u8)b) {
    void *w = vcall<void *>(self, 0x2e0);
    if (w) vcall<void>(vcall<void *>(self, 0x2c4), 0x2ec, w);
    return;
  }
  void *first = vcall<void *>(vcall<void *>(self, 0x2c4), 0x2f0);
  if (!first) return;
  for (void *p = first; p != self;) {
    p = vcall<void *>(p, 0x20);
    if (!p) return;
  }
  vcall<void>(vcall<void *>(self, 0x2c4), 0x2f4, first, 1u);
}
PCREG(4f3ee0, WindowHide);

// 0x601ee0 CSdlDataExchange::setExportSymbol(const char*, const char*) (medium; SEH frame): sym = new(4) constructed
// by 0x600c70(a, b) (0 when new fails); push_back onto the vector at +4 (data, cap +8, count +0xc; grow 0x5f4630).
extern "C" void *ext_41e290(u32);
extern "C" u32 THISCALL ext_600c70(void *, u32, u32);
extern "C" void THISCALL ext_5f4630(void *);
static void THISCALL SetExportSymbol(u8 *self, u32 a, u32 b) {
  void *m = ext_41e290(4);
  u32 s = m ? ext_600c70(m, a, b) : 0;
  if (F32(self, 0xc) >= F32(self, 8)) ext_5f4630(self + 4);
  (*(u32 **)(self + 4))[F32(self, 0xc)] = s;
  F32(self, 0xc)++;
}
PCREG(601ee0, SetExportSymbol);

// 0x44a160 ZLIST::CheckPointInside(const float*, float) const (high): true when any member geom (scene.slot58 of
// each element of the list +0x18) answers slot180(p, radius).
typedef bool(THISCALL *inside_t)(void *, const float *, float);
static bool THISCALL ListCheckPointInside(u8 *self, const float *p, float r) {
  void *l = *(void **)(self + 0x18);
  if (!l) return false;
  u32 it[3];
  vcall<void>(l, 0x4c, it);
  u32 e = vcall<u32>(*(void **)(self + 0x18), 0x5c, it);
  while (it[0]) {
    void *g = vcall<void *>(Scene(), 0x58, e);
    if (g && (*(inside_t *)(*(u8 **)g + 0x180))(g, p, r)) return true;
    e = vcall<u32>(*(void **)(self + 0x18), 0x5c, it);
  }
  return false;
}
PCREG(44a160, ListCheckPointInside);

// 0x5b7660 ZFFHintBox::FrameUpdate() (high): v = centre of the hero's geom (+0x50)->(+8); hero.slot84(v);
// box (+0x44).slot8c(v); if box.slot180(v, -10.0): OSD (hero+0x852) HintMessage(+0x4c, true), this.slot68(0x10, 0).
extern "C" void THISCALL ext_4daf90(void *, float *);
extern "C" void THISCALL ext_597fc0(void *, u32, u32);
static void THISCALL HintBoxFrameUpdate(u8 *self) {
  float v[3];
  u8 *h = *(u8 **)(self + 0x50);
  ext_4daf90(*(void **)(h + 8), v);
  vcall<void>(h, 0x84, v);
  vcall<void>(*(void **)(self + 0x44), 0x8c, v);
  void *bx = *(void **)(self + 0x44);
  if ((*(inside_t *)(*(u8 **)bx + 0x180))(bx, v, -10.0f)) {
    ext_597fc0(*(void **)(*(u8 **)(self + 0x50) + 0x852), F32(self, 0x4c), 1);
    vcall<void>(self, 0x68, 0x10u, 0u);
  }
}
PCREG(5b7660, HintBoxFrameUpdate);

// 0x454ca0 GUESS: for each element of the list +0x5c: g = scene.slot58(+0x20); if g: (type 0x2000ee expected, else the
// assert hook) element+0x38 = 0x45be60(g, +0x34).
extern "C" u32 THISCALL ext_45be60(void *, u32);
static void THISCALL Resolve454ca0(u8 *self) {
  if (!*(void **)(self + 0x5c)) return;
  u32 it[3];
  vcall<void>(*(void **)(self + 0x5c), 0x4c, it);
  u8 *e = vcall<u8 *>(*(void **)(self + 0x5c), 0x5c, it);
  while (it[0]) {
    u8 *g = vcall<u8 *>(Scene(), 0x58, F32(e, 0x20));
    if (g) {
      if (F32(*(u8 **)(g + 0xc), 0x23) != 0x2000ee) AssertHook();
      F32(e, 0x38) = ext_45be60(g, F32(e, 0x34));
    }
    e = vcall<u8 *>(*(void **)(self + 0x5c), 0x5c, it);
  }
}
PCREG(454ca0, Resolve454ca0);

// 0x4d68e0 GUESS: DOS-packed local time: date (when the pointer is set) = mday | (mon+1)<<5 | (year+0x30)*0x200;
// time (when the word it points at is non-zero) = sec/2 | min<<5 | hour<<11 (CRT _time32/_localtime32).
typedef u32 (*time32_t)(u32 *);
typedef u32 *(*localtime32_t)(u32 *);
static void THISCALL DosNow(u8 *, u16 *date, u16 *tim) {
  u32 t;
  G(time32_t, 0x676438)(&t);
  u32 *tm = G(localtime32_t, 0x67643c)(&t);
  if (date) {
    u16 d = (u16)tm[3];
    *date = d;
    u16 x = (u16)((u16)((u16)tm[4] + 1) << 5) | d;
    *date = x;
    *date = (u16)((u32)(u16)((u16)tm[5] + 0x30) * 0x200) | x;
  }
  if (*tim) {
    u16 s = (u16)((s32)tm[0] / 2);
    *tim = s;
    u16 x = (u16)((u16)tm[1] << 5) | s;
    *tim = x;
    *tim = (u16)((u16)tm[2] << 11) | x;
  }
}
PCREG(4d68e0, DosNow);

// 0x4c8560 GUESS: toggles the flag +0x52; ZBaseGeom::Display(flag) on every geom of the scene list (+0xadc, from +8,
// slot50 advances) whose type (+0x54 -> +0xc -> +0x23, 0x200002 without) has bit 0x400000; scene+0xbae = flag.
extern "C" void THISCALL ext_4daa20(void *, u32);
static void THISCALL ToggleDisplay(u8 *self) {
  self[0x52] = self[0x52] == 0;
  u8 *cur = *(u8 **)(*(u8 **)((u8 *)Scene() + 0xadc) + 8);
  while (cur) {
    u8 *x = *(u8 **)(cur + 0x54);
    u32 t = x ? F32(*(u8 **)(x + 0xc), 0x23) : 0x200002;
    if (t & 0x400000) ext_4daa20(cur, self[0x52]);
    vcall<void>(*(void **)((u8 *)Scene() + 0xadc), 0x50, &cur);
  }
  ((u8 *)Scene())[0xbae] = self[0x52];
}
PCREG(4c8560, ToggleDisplay);

// 0x63ace0 ZDrawArray<ZCameraDrawEntry,...>::Add() (medium): find a block with a free slot as in 0x6482a0 (grow
// 0x63b240), count++, then take its free slot inline: 16-byte slots after a 16-byte header, slot = blk + (idx+1)*16.
static u8 *THISCALL CameraDrawAdd(u8 *self) {
  typedef bool(THISCALL * grow_t)(void *);
  u8 *blk = 0;
  u8 *start = *(u8 **)(self + 8);
  if (start) {
    u8 *e = start;
    for (;;) {
      if (*(u16 *)(e + 2) != 0xffff) { blk = e; break; }
      e = *(u8 **)(e + 8);
      *(u8 **)(self + 8) = e;
      if (e == start || !e) break;
    }
  }
  if (!blk) {
    if (!((grow_t)0x63b240)(self)) return 0;
    blk = *(u8 **)(self + 8);
  }
  F32(self, 0xc)++;
  u16 i = *(u16 *)(blk + 2);
  if (i == 0xffff) return 0;
  u8 *s = blk + ((u32)i + 1) * 16;
  *(u16 *)(blk + 2) = *(u16 *)s;
  F32(s, 0) = 0;
  F32(s, 4) = 0xffff1201;
  s[8] = 0;
  F32(s, 0xc) = 0;
  blk[0]++;
  return s;
}
PCREG(63ace0, CameraDrawAdd);

// 0x57d460 GUESS: up to four ids at +0xac (-1 ends); an id below 0x10000 is mapped through the range table
// [rm+0x190b] (16-byte rows {base, -, -, len}: id - base + (row << 16); no table -> -1); each mapped id goes to
// 0x57dde0 (id in ECX); a zero result stops; results go to out[]; returns the count.
extern "C" u32 THISCALL ext_57dde0(void *);
static u32 THISCALL MapIds57d460(u8 *self, u32 *out) {
  u32 n = 0;
  s32 *p = (s32 *)(self + 0xac);
  do {
    s32 id = *p;
    if (id == -1) break;
    if (!((u32)id & 0xffff0000)) {
      s32 *t = *(s32 **)(G(u8 *, 0x70039c) + 0x190b);
      s32 mapped = -1;
      if (t) {
        u32 row = 0;
        for (s32 *q = t; q; q += 4, row++) {
          s32 b = q[0];
          if (b <= id && q[3] + b > id) { mapped = id + (s32)((row << 16) - (u32)b); break; }
        }
      }
      id = mapped;
    }
    u32 r = ext_57dde0((void *)id);
    if (!r) break;
    out[n++] = r;
    p++;
  } while (n < 4);
  return n;
}
PCREG(57d460, MapIds57d460);

// 0x454b60 GUESS (fastcall c, d; stack a, b): x = b ? 0x45c4f0(0x4c, b) : 0x45c4b0(0x4c) (cdecl allocators);
// returns x ? 0x454980(x, a, c, d) : 0.
extern "C" void *ext_45c4f0(u32, u32);
extern "C" void *ext_45c4b0(u32);
extern "C" u32 THISCALL ext_454980(void *, u32, u32, u32);
static u32 FASTCALL Alloc454b60(u32 c, u32 d, u32 a, u32 b) {
  void *x = b ? ext_45c4f0(0x4c, b) : ext_45c4b0(0x4c);
  return x ? ext_454980(x, a, c, d) : 0;
}
PCREG(454b60, Alloc454b60);
