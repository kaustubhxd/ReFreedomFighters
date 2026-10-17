// batch1011.cpp - fresh-10 batch 11: geom create, saves, spin update, controller menu, config dtor, MD5 final,
// char-ref number, EAX reset, vertex-anim commands (slice 10).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SCENE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)
extern "C" void THISCALL ext_4cbec0(void *);  // MYSTR::~MYSTR

// 0x448220 GUESS (fastcall cls, name; stack info, geom; SEH frame): geom ? 0x4472a0(geom, info, cls, name) :
// o = 0x45c4b0(0x1c); ZGEOM(o, info, cls, name); +0x18 = 0; +0x14 |= 1 when scene byte +0xbad; vtable 0x67e0c0.
extern "C" u32 FASTCALL ext_4472a0(u32, u32, u32, u32);
extern "C" u8 *ext_45c4b0(u32);
extern "C" void THISCALL ext_45c3a0(void *, u32, u32, u32);
static u32 FASTCALL Create448220(u32 a, u32 b, u32 info, u32 geom) {
  if (geom) return ext_4472a0(geom, info, a, b);
  u8 *o = ext_45c4b0(0x1c);
  if (!o) return 0;
  ext_45c3a0(o, info, a, b);
  F32(o, 0) = 0x67dc30;
  F32(o, 0x18) = 0;
  if (SCENE[0xbad]) F32(o, 0x14) |= 1;
  F32(o, 0) = 0x67e0c0;
  return (u32)o;
}
PCREG(448220, Create448220);

// 0x4c28e0 ZSoundSegmentPitch::Save(ZSaveGame*) (high): +4 &= ~0x40; g writes: slot40 words +0x48, +0x4a; slot60 bytes
// +0x4c, +0x4d; slot4c floats +0x4e, +0x52, +0x56, +0x5a; slot44 dword +0x5e; slot4c floats +0x62, +0x66. True (AL).
static u8 THISCALL SegmentPitchSave(u8 *self, void *g) {
  F32(self, 4) &= ~0x40u;
  vcall<void>(g, 0x40, (u32) * (u16 *)(self + 0x48));
  vcall<void>(g, 0x40, (u32) * (u16 *)(self + 0x4a));
  vcall<void>(g, 0x60, (u32)self[0x4c]);
  vcall<void>(g, 0x60, (u32)self[0x4d]);
  vcall<void>(g, 0x4c, F32(self, 0x4e));   // floats go as their bits (movss copy in the exe)
  vcall<void>(g, 0x4c, F32(self, 0x52));
  vcall<void>(g, 0x4c, F32(self, 0x56));
  vcall<void>(g, 0x4c, F32(self, 0x5a));
  vcall<void>(g, 0x44, F32(self, 0x5e));
  vcall<void>(g, 0x4c, F32(self, 0x62));
  vcall<void>(g, 0x4c, F32(self, 0x66));
  return 1;
}
PCREG(4c28e0, SegmentPitchSave);

// 0x4c95a0 ZSpin::FrameUpdate() (high; /GS): dt = frame time (rm+0x48) * [0x67885c]; flag +0x58 clears after 0x800
// clock ticks since +0x5b (then slot68(0x10, 0)), else flag +0x59 clears after 0x400. v = vscalar(+0x4c, dt);
// m = geom(+0x44 -> +8).GetMat(); 0x4de7e0(m, v) (GUESS rotate); slot84(m); (+0x44).slot6c(m).
extern "C" void FASTCALL ext_4e0d40(float *, const void *, u32);
extern "C" void THISCALL ext_4db2a0(void *, float *);
extern "C" void FASTCALL ext_4de7e0(float *, float *);
static void THISCALL SpinFrameUpdate(u8 *self) {
  u8 *rm = *(u8 **)0x70039c;
  float dt = *(float *)(rm + 0x48) * G(float, 0x67885c);
  if (self[0x58]) {
    if ((s32)(F32(rm, 0x40) - F32(self, 0x5b)) > 0x800) {
      self[0x58] = 0;
      vcall<void>(self, 0x68, 0x10u, 0u);
    }
  } else if (self[0x59] && (s32)(F32(rm, 0x40) - F32(self, 0x5b)) > 0x400) {
    self[0x59] = 0;
  }
  float v[3], m[9];
  ext_4e0d40(v, self + 0x4c, fbits(dt));
  ext_4db2a0(*(void **)(*(u8 **)(self + 0x44) + 8), m);
  ext_4de7e0(m, v);
  vcall<void>(self, 0x84, m);
  vcall<void>(*(void **)(self + 0x44), 0x6c, m);
}
PCREG(4c95a0, SpinFrameUpdate);

// 0x5799a0 ZControllerA::OnWindowOpen(unsigned, bool) (high; /GS): ZVideoSelector::OnWindowOpen; UpdateButtons();
// w = (+0x54).slot25c(0x6a674c, 0); if w: o = sys.slot190(); f = [scene+0xae4].slot0(0x6a6fc0, 0x6a9b14);
// o.slot198(o, buf, f, +0x194 + 1) (cdecl; the count is pushed before the slot0 call); w.slot284(buf). False (AL).
extern "C" void THISCALL ext_563110(void *, u32, u32);
extern "C" void THISCALL ext_579d20(void *);
typedef void (*fmt198_t)(void *, char *, u32, u32);
static u8 THISCALL ControllerAOnWindowOpen(u8 *self, u32 a, u32 b) {
  ext_563110(self, a, b);
  ext_579d20(self);
  void *w = vcall<void *>(*(void **)(self + 0x54), 0x25c, 0x6a674cu, 0u);
  if (w) {
    void *o = vcall<void *>(G(void *, 0x70039c), 0x190);
    u32 n = F32(self, 0x194) + 1;
    u32 f = vcall<u32>(*(void **)(SCENE + 0xae4), 0, 0x6a6fc0u, 0x6a9b14u);
    char buf[0x100];
    (*(fmt198_t *)(*(u8 **)o + 0x198))(o, buf, f, n);
    vcall<void>(w, 0x284, buf);
  }
  return 0;
}
PCREG(5799a0, ControllerAOnWindowOpen);

// 0x4317a0 CConfiguration::~CConfiguration() (medium; SEH frame): vtable 0x679e94; RemoveAllKeyMappings(); every
// entry of the table +0xac: its MYSTR (+4) is destroyed and deleted (0x80); ~STRREFTAB(+0xc8), ~STRREFTAB(+0xac),
// 0x4cce40(+0x84), ~MYSTR(+4).
extern "C" void THISCALL ext_432be0(void *);
extern "C" void THISCALL ext_4cd0e0(void *);
extern "C" void THISCALL ext_4cce40(void *);
static void THISCALL ConfigurationDtor(u8 *self) {
  F32(self, 0) = 0x679e94;
  ext_432be0(self);
  u8 *l = self + 0xac;
  u32 it[3];
  vcall<void>(l, 0x4c, it);
  for (u8 *e = vcall<u8 *>(l, 0x64, it); e; e = vcall<u8 *>(l, 0x64, it)) {
    void *s = *(void **)(e + 4);
    if (s) {
      ext_4cbec0(s);
      ext_634273(s, 0x80);
    }
  }
  ext_4cd0e0(self + 0xc8);
  ext_4cd0e0(l);
  ext_4cce40(self + 0x84);
  ext_4cbec0(self + 4);
}
PCREG(4317a0, ConfigurationDtor);

// 0x4bcc60 ZSoundVolumetricSource::Plot() (high): debug text through sys.slot190() (o.slot184, cdecl (o, 0, colour,
// fmt, ...)): +0x60 == 0: (8, 0x693c94); +0x60 == 1: (8, 0x693cac); then (0xb, 0x693cc4, double +0xd1) and
// (0xc, 0x693ccc, double +0xd5).
typedef void (*plot_t)(void *, u32, u32, u32, ...);
static inline void *Printer() { return vcall<void *>(G(void *, 0x70039c), 0x190); }
static void THISCALL VolumetricPlot(u8 *self) {
  if (F32(self, 0x60) == 0) {
    void *o = Printer();
    (*(plot_t *)(*(u8 **)o + 0x184))(o, 0, 8, 0x693c94);
  }
  if (F32(self, 0x60) == 1) {
    void *o = Printer();
    (*(plot_t *)(*(u8 **)o + 0x184))(o, 0, 8, 0x693cac);
  }
  void *o = Printer();
  (*(plot_t *)(*(u8 **)o + 0x184))(o, 0, 0xb, 0x693cc4, (double)*(float *)(self + 0xd1));
  o = Printer();
  (*(plot_t *)(*(u8 **)o + 0x184))(o, 0, 0xc, 0x693ccc, (double)*(float *)(self + 0xd5));
}
PCREG(4bcc60, VolumetricPlot);

// 0x606120 MD5Engine_t::final(MD5_t&) (medium; /GS): bits = the 8 count bytes (+0x10); pad to 56 mod 64 with the
// 0x6efc30 block (update), update(bits, 8), then the 16 state bytes (+0) go to out.
extern "C" void THISCALL ext_606940(void *, const u8 *, u32);
static void THISCALL MD5Final(u8 *self, u8 *out) {
  u8 bits[8];
  for (int i = 0; i < 8; i++) bits[i] = self[0x10 + i];
  u32 idx = (F32(self, 0x10) >> 3) & 0x3f;
  u32 pad = idx < 0x38 ? 0x38 - idx : 0x78 - idx;
  ext_606940(self, (const u8 *)0x6efc30, pad);
  ext_606940(self, bits, 8);
  for (int i = 0; i < 16; i++) out[i] = self[i];
}
PCREG(606120, MD5Final);

// 0x621f60 expat normal_charRefNumber(enc, ptr) (GUESS name, cdecl): parse "&#x<hex>;" or "&#<dec>;" from ptr+2
// (x: 0-9 a-f A-F, other characters ignored); >= 0x110000 gives -1; checkCharRefNumber: 0xd800-0xdfff, 0xfffe,
// 0xffff and bytes whose latin1 type (0x6bf2f4) is 0 give -1.
static s32 CharRefNumber(void *, const char *p) {
  p += 2;
  u32 r = 0;
  if (*p == 'x') {
    for (p++; *p != ';'; p++) {
      s32 c = *p;
      u32 k = (u32)(c - 0x30);
      if (k <= 9) r = (r << 4) | k;
      else if (k >= 0x11 && k <= 0x16) r = (r << 4) - 0x37 + c;
      else if (k >= 0x31 && k <= 0x36) r = (r << 4) - 0x57 + c;
      if ((s32)r >= 0x110000) return -1;
    }
  } else {
    for (; *p != ';'; p++) {
      r = r * 10 - 0x30 + (s32)*p;
      if ((s32)r >= 0x110000) return -1;
    }
  }
  s32 hi = (s32)r >> 8;
  if (hi > 0xdf) {
    if (hi != 0xff) return r;
    if (r == 0xfffe || r == 0xffff) return -1;
    return r;
  }
  if (hi >= 0xd8) return -1;
  if (hi != 0) return r;
  return G(u8, 0x6bf2f4 + r) ? (s32)r : -1;
}
PCREG(621f60, CharRefNumber);

// 0x54eca0 GUESS EAX listener reset: with the property set +4: fields +8..+0x4c = EAX 2 listener defaults (0.25, 1.5,
// 1.0, 1.0, 1.0 at +0x24/+0x28/+0x2c/+0x34/+0x48, 7 at +0x4c, rest 0); set.Set(0x6bdf70, 0x80000001, 0, 0, +8, 0x48)
// (COM stdcall); a negative result is logged (file 0x6a4168, line 0x168, text 0x6a42c4).
typedef s32(STDCALL *kset_t)(void *, u32, u32, u32, u32, void *, u32);
typedef void (*log2c_t)(void *, u32);
static void THISCALL EaxListenerReset(u8 *self) {
  void *ps = *(void **)(self + 4);
  if (!ps) return;
  static const u32 init[0x12] = {0, 0, 0, 0, 0, 0, 0, 0x3e800000, 0x3fc00000, 0x3f800000, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 7};
  for (int i = 0; i < 0x12; i++) F32(self, 8 + 4 * i) = init[i];
  s32 r = (*(kset_t *)(*(u8 **)ps + 0x10))(ps, 0x6bdf70, 0x80000001, 0, 0, self + 8, 0x48);
  if (r < 0) {
    void *pr = vcall<void *>(G(void *, 0x700390), 0x20, 0x6a4168u, 0x168u);
    (*(log2c_t *)(*(u8 **)pr + 0x2c))(pr, 0x6a42c4);
  }
}
PCREG(54eca0, EaxListenerReset);

// 0x4a48e0 ZVertAnim::Command(unsigned short, void*) (high): 0x401: unless +0x5e, slot64(0x10); anim table
// ([rm+0x1aa3]+0x18).slotd8(geom (+0x44 -> +8), +0x4a). 0x400: unless +0x5e, slot68(0x10, 0). The anim's own end id
// (+0x48): (+0x44).slot2c(); slot64(0x10); +0x56 = clock; +0x4a = 0; slot3c(). The global id [0x7002f8]: +0x65 = 1,
// slot64(0x100). Returns 0.
static u32 THISCALL VertAnimCommand(u8 *self, u32 cmd, void *) {
  u16 c = (u16)cmd;
  if (c == 0x401) {
    if (!self[0x5e]) vcall<void>(self, 0x64, 0x10u);
    void *t = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x18);
    vcall<void>(t, 0xd8, F32(*(u8 **)(self + 0x44), 8), F32(self, 0x4a));
    return 0;
  }
  if (c == 0x400) {
    if (!self[0x5e]) vcall<void>(self, 0x68, 0x10u, 0u);
    return 0;
  }
  if (c == *(u16 *)(self + 0x48)) {
    vcall<void>(*(void **)(self + 0x44), 0x2c);
    vcall<void>(self, 0x64, 0x10u);
    u8 *clk = *(u8 **)0x70039c + 0x40;
    if (self + 0x56 != clk) F32(self, 0x56) = *(u32 *)clk;
    F32(self, 0x4a) = 0;
    vcall<void>(self, 0x3c);
    return 0;
  }
  if (c == G(u16, 0x7002f8)) {
    self[0x65] = 1;
    vcall<void>(self, 0x64, 0x100u);
  }
  return 0;
}
PCREG(4a48e0, VertAnimCommand);
