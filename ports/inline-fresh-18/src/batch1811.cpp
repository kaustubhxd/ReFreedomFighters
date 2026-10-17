// batch1811.cpp - fresh-18 batch 11 (slice 18): string/value record constructor, briefing commands, look-at matrix,
// input buffer grow, map clear, edit control keys, a window destructor.
// SEH frames and stack cookies of the exe are not reproduced (they leave no state behind on return).
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

extern "C" void *ext_41e290(u32 size);                                            // operator new, cdecl
extern "C" void ext_634273(void *p, u32 size);                                    // operator delete, cdecl
extern "C" void *ext_634d22(void *d, const void *s, u32 n);                       // memcpy
extern "C" void *THISCALL ext_6014a0(void *self, u32 n);                          // CHostInterface::alloc
extern "C" void *THISCALL ext_5f2d60(void *self, const char *b, const char *e);   // string assign(range)
extern "C" void *THISCALL ext_42b390(void *self, u32 s, void *al);                // string ctor(const char*, alloc)
extern "C" void THISCALL ext_59a5b0(void *osd, u32 text, u32 a, u32 b);           // ZGameOSD::MessageDialog
extern "C" void THISCALL ext_566820(void *self);                                  // CBriefing::MusicLow
extern "C" void THISCALL ext_566a10(void *self);                                  // CBriefing::StopBriefing
extern "C" u32 THISCALL ext_4f1520(void *self, u32 cmd, void *data);              // CWinEvent<ZWINGROUP>::Command
extern "C" void STDCALL ext_4110c2(float *d, const float *s);                     // normalize
extern "C" void ext_411076(float *d, const float *a, const float *b);             // cross, cdecl
extern "C" void THISCALL ext_54f870(void *self, void *p, u32 n);                  // block deallocate
extern "C" void THISCALL ext_5fdb70(void *self);
extern "C" void THISCALL ext_5fae50(void *self);
extern "C" void THISCALL ext_5fb370(void *self, void *node);                      // erase subtree
extern "C" u32 THISCALL ext_4cc5f0(void *self);                                   // MYSTR::Length
extern "C" char *THISCALL ext_4cc1d0(void *self);                                 // MYSTR::c_str
extern "C" char *FASTCALL ext_4cc4d0(char *p, s32 back);                          // step back to a UTF-8 lead byte
extern "C" void THISCALL ext_4ccfe0(void *self);                                  // REFTAB::~REFTAB
extern "C" void THISCALL ext_4ccee0(void *self);

// 0x600f20 GUESS record ctor(const char *name, u32 b, u32 c): [self] = new 0x18 {type, b, value, string name},
// type 3, value = new 0xc string built from c.
static u32 *THISCALL f600f20(u32 *self, const char *s, u32 b, u32 c) {
  u8 *n = (u8 *)ext_41e290(0x18);
  if (n) {
    u32 *v = (u32 *)(n + 0xc);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    char *p = (char *)ext_6014a0(v, 8);
    v[0] = (u32)p;
    v[1] = (u32)p;
    v[2] = (u32)(p + 8);
    if (p) *p = 0;
    *p = 0;
  } else
    n = 0;
  self[0] = (u32)n;
  u32 len = 0;
  while (s[len]) len++;
  ext_5f2d60(n + 0xc, s, s + len);
  *(u32 *)self[0] = 3;
  void *q = ext_41e290(0xc);
  void *r = q ? ext_42b390(q, c, (u8 *)&s + 3) : 0;
  *(u32 *)(self[0] + 8) = (u32)r;
  *(u32 *)(self[0] + 4) = b;
  return self;
}
PCREG(600f20, f600f20);

// 0x565f20 CBriefing::Command(unsigned short, void*) [high]: message dialog text (+0x184; the text object's slot 0
// takes the format 0x6a6de4 and data[2]; data[1], data[0] go on to MessageDialog through the shared stack words),
// music low and fade timer (+0x186), pause on/off (+0x188/+0x18a), stop (+0x196), else the group's Command.
static u32 THISCALL f565f20(u8 *self, u32 cmd, u32 *d) {
  u16 c = (u16)cmd;
  if (c == *(u16 *)(self + 0x184)) {
    void *t = *(void **)(engineObj9b() + 0xae4);
    u32 text = vcall<u32>(t, 0, 0x6a6de4u, d[2]);
    ext_59a5b0(*(void **)(self + 0xa17), text, d[1], d[0]);
    return 1;
  }
  if (c == *(u16 *)(self + 0x186)) {
    if ((self[0xa0a] || self[0xa0b]) && !self[0xa0d]) {
      ext_566820(self);
      self[0xa0d] = 1;
      *(float *)(self + 0x1e6) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4);
    }
    return 0;
  }
  if (c == *(u16 *)(self + 0x188)) {
    self[0xa08] = 1;
    return 0;
  }
  if (c == *(u16 *)(self + 0x18a)) {
    self[0xa08] = 0;
    return 0;
  }
  if (c == *(u16 *)(self + 0x196)) {
    ext_566a10(self);
    return 0;
  }
  ext_4f1520(self, cmd, d);
  return 0;
}
PCREG(565f20, f565f20);

// 0x411169 GUESS look-at view matrix (out, eye, target, up), D3DX-style rows: f = norm(target - eye),
// s = norm(cross(up, f)), u = cross(f, s); translation = -(axis . eye) in x87 (double) precision.
static inline float ndot(const float *a, const float *e) {
  return (float)-(((double)a[1] * e[1] + (double)a[0] * e[0]) + (double)a[2] * e[2]);
}
static void STDCALL f411169(float *m, const float *eye, const float *tg, const float *up) {
  float f[3], s[3], u[3];
  f[0] = tg[0] - eye[0];
  f[1] = tg[1] - eye[1];
  f[2] = tg[2] - eye[2];
  ext_4110c2(f, f);
  ext_411076(s, up, f);
  ext_4110c2(s, s);
  ext_411076(u, f, s);
  m[0] = s[0];
  m[4] = s[1];
  m[8] = s[2];
  m[1] = u[0];
  m[5] = u[1];
  m[9] = u[2];
  m[2] = f[0];
  m[6] = f[1];
  m[10] = f[2];
  m[12] = ndot(s, eye);
  m[13] = ndot(u, eye);
  m[14] = ndot(f, eye);
  m[3] = 0.0f;
  m[7] = 0.0f;
  m[11] = 0.0f;
  m[15] = 1.0f;
}
PCREG(411169, f411169);

// 0x61bd20 GUESS buffer make-room(state, n): keeps up to 0x400 bytes behind the read pointer (+0x18); slides the
// data down (memmove, IAT 0x676278) when that frees enough, else doubles the capacity through the alloc callback
// (+0xc; failure sets +0x114) and frees the old block (+0x14). Returns the write pointer (+0x1c).
typedef void *(*memmoveFn)(void *, const void *, u32);
typedef void *(*allocCb)(u32);
typedef void (*freeCb)(void *);
static u32 f61bd20(u8 *s, s32 n) {
  s32 cap = *(s32 *)(s + 0x20);
  s32 w = *(s32 *)(s + 0x1c);
  if (n <= cap - w) return *(u32 *)(s + 0x1c);
  s32 rd = *(s32 *)(s + 0x18);
  s32 off = w - rd;
  s32 need = off + n;
  s32 back = rd - *(s32 *)(s + 8);
  s32 keep = back > 0x400 ? 0x400 : back;
  need += keep;
  if (need <= cap - *(s32 *)(s + 8)) {
    if (keep >= back) return *(u32 *)(s + 0x1c);
    u8 *b = *(u8 **)(s + 8);
    s32 k = back - keep;
    (*(memmoveFn *)0x676278)(b, b + k, off + keep);
    *(s32 *)(s + 0x1c) -= k;
    *(s32 *)(s + 0x18) -= k;
    return *(u32 *)(s + 0x1c);
  }
  s32 sz = cap - rd;
  if (sz == 0) sz = 0x400;
  do sz += sz;
  while (sz < need);
  u8 *p = (u8 *)(*(allocCb *)(s + 0xc))(sz);
  if (!p) {
    *(u32 *)(s + 0x114) = 1;
    return 0;
  }
  *(u32 *)(s + 0x20) = (u32)(p + sz);
  s32 r = *(s32 *)(s + 0x18);
  if (!r) {
    *(u32 *)(s + 0x1c) += (u32)p;
    *(u32 *)(s + 0x18) = (u32)p;
    *(u32 *)(s + 8) = (u32)p;
    return *(u32 *)(s + 0x1c);
  }
  s32 kp = r - *(s32 *)(s + 8);
  if (kp > 0x400) kp = 0x400;
  ext_634d22(p, (void *)(r - kp), *(s32 *)(s + 0x1c) - r + kp);
  (*(freeCb *)(s + 0x14))(*(void **)(s + 8));
  u32 d = kp - *(u32 *)(s + 0x18) + (u32)p;
  *(u32 *)(s + 8) = (u32)p;
  *(u32 *)(s + 0x1c) += d;
  *(u32 *)(s + 0x18) = kp + (u32)p;
  return *(u32 *)(s + 0x1c);
}
PCREG(61bd20, f61bd20);

// 0x5fb660 GUESS map<key, obj*> clear (packed tree nodes: parent +1, left +5, right +9, value +0x19): destroys
// every 0x17e-byte value in order (block +0x172..+0x17a, member +0x3c, own dtor), then erases the nodes and resets
// the header; clears the flag byte at +0.
static inline u8 *P(u8 *n, u32 o) { return *(u8 **)(n + o); }
static void THISCALL f5fb660(u8 *self) {
  u8 **hp = (u8 **)(self + 1);
  u8 *head = *hp;
  u8 *it = P(head, 5);
  if (it != head) {
    do {
      u8 *o = P(it, 0x19);
      if (o) {
        u8 *b = P(o, 0x172);
        u32 n = *(u32 *)(o + 0x17a) - (u32)b;
        if (b && n) ext_54f870(o + 0x172, b, n);
        ext_5fdb70(o + 0x3c);
        ext_5fae50(o);
        ext_634273(o, 0x17e);
      }
      u8 *r = P(it, 9);
      if (r) {
        it = r;
        while (P(it, 5)) it = P(it, 5);
      } else {
        u8 *pa = P(it, 1);
        while (it == P(pa, 9)) {
          it = pa;
          pa = P(pa, 1);
        }
        if (P(it, 9) != pa) it = pa;
      }
    } while (it != *hp);
  }
  if (*(u32 *)(self + 5)) {
    ext_5fb370(hp, P(*hp, 1));
    *(u8 **)(*hp + 5) = *hp;
    *(u32 *)(*hp + 1) = 0;
    *(u8 **)(*hp + 9) = *hp;
    *(u32 *)(self + 5) = 0;
  }
  self[0] = 0;
}
PCREG(5fb660, f5fb660);

// 0x4f8e20 ZEditControl::KeyPress(unsigned int) [high]: ignored (0) unless the focus object (+0x10f) slot 0x14 says
// active; backspace removes the last UTF-8 character of the text (+0x8f) and reports it (slot 0x360); tab and enter
// do nothing; escape closes through the parent (slot 0x2c4 -> 0x2f4(self, 1)); arrow keys 37..40 set flags
// +0x1db/+0x1dd/+0x1dc/+0x1de; any other key goes to slot 0x358.
static u8 THISCALL f4f8e20(u8 *self, u32 key) {
  if (!vcall<u32>(self + 0x10f, 0x14)) return 0;
  switch (key) {
  case 8: {
    void *t = self + 0x8f;
    if (!ext_4cc5f0(t)) break;
    char *e = ext_4cc1d0(t) - 1;
    e += ext_4cc5f0(t);
    char *b = ext_4cc1d0(t);
    *ext_4cc4d0(e, e - b) = 0;
    vcall<void>(self, 0x360, ext_4cc1d0(t));
    break;
  }
  case 9:
  case 13: break;
  case 27: {
    void *pa = vcall<void *>(self, 0x2c4);
    vcall<void>(pa, 0x2f4, self, 1u);
    break;
  }
  case 37: self[0x1db] = 1; break;
  case 38: self[0x1dd] = 1; break;
  case 39: self[0x1dc] = 1; break;
  case 40: self[0x1de] = 1; break;
  default: vcall<void>(self, 0x358, key); break;
  }
  return 1;
}
PCREG(4f8e20, f4f8e20);

// 0x4b2060 GUESS window dtor (vtable 0x691cfc): releases the global helper 0x700334 (slot 0x40 with the engine's
// handle for +0x44, slot 0x14 busy check, slot 0 delete(1)), gives back a counted slot of the engine block +0x190f
// when +0x9e and +0x98 are set, destroys two REFTABs and a member, then the window base tail.
static void THISCALL f4b2060(u32 *self) {
  u8 *s = (u8 *)self;
  self[0] = 0x691cfc;
  if (G(void *, 0x700334)) {
    u32 h = vcall<u32>(engineObj9b(), 0x4c, *(u32 *)(s + 0x44));
    vcall<void>(G(void *, 0x700334), 0x40, h);
    if (!vcall<u32>(G(void *, 0x700334), 0x14)) {
      void *g = G(void *, 0x700334);
      if (g) vcall<void>(g, 0, 1u);
    }
    G(void *, 0x700334) = 0;
  }
  if (s[0x9e] && s[0x98]) {
    u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
    if (*(u32 *)(t + 0xfd)) {
      (*(u32 *)(t + 0xfd))--;
      (*(u8 **)(G(u8 *, 0x70039c) + 0x190f))[0x101] = 0;
    }
  }
  ext_4ccfe0(s + 0x10e);
  ext_4ccfe0(s + 0xf2);
  ext_4ccee0(s + 0xaa);
  *(u32 *)(s + 0x44) = 0;
  *(u32 *)(s + 0x30) = 0;
  self[0] = 0x686874;
  vcall<void>(engineObj9b(), 0x34, self);
}
PCREG(4b2060, f4b2060);
