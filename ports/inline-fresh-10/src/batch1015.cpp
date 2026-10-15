// batch1015.cpp - fresh-10 batch 15: zlib adler32, DXT palette and block indices, script AttachItem (slice 10).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SCENE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef void (*log2c_t)(void *, u32, ...);
static inline void *Logger(u32 file, u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, file, line); }

// 0x6316e0 zlib adler32(adler, buf, len) (high; stdcall): null buf gives 1; NMAX 5552 blocks, 16 bytes unrolled, each
// block reduced mod 65521.
static u32 STDCALL Adler32(u32 adler, const u8 *buf, u32 len) {
  u32 s1 = adler & 0xffff, s2 = adler >> 16;
  if (!buf) return 1;
  while (len) {
    u32 n = len < 0x15b0 ? len : 0x15b0;
    len -= n;
    for (; (s32)n >= 16; n -= 16)
      for (int k = 0; k < 16; k++) {
        s1 += *buf++;
        s2 += s1;
      }
    for (; n; n--) {
      s1 += *buf++;
      s2 += s1;
    }
    s1 %= 65521;
    s2 %= 65521;
  }
  return (s2 << 16) | s1;
}
PCREG(6316e0, Adler32);

// 0x6383a0 GUESS DXT1 palette (fastcall three_colour, out; stack c0, c1; ints r, g, b): four colours {r, g, b, 0xff}.
// Four-colour: (3*c0 + 1)/3, (2*c0 + 1 + c1)/3, (2*c1 + 1 + c0)/3, (3*c1 + 1)/3 (signed, truncating, 32-bit wrap).
// Three-colour: c0, (c0 + c1)/2, c1, and {0, 0, 0, 0}.
static inline s32 Div3(u32 x) { return (s32)x / 3; }
static void FASTCALL DxtPalette(u32 three, s32 *out, s32 *c0, s32 *c1) {
  if (!three) {
    for (int k = 0; k < 3; k++) out[k] = Div3((u32)c0[k] * 3 + 1);
    out[3] = 0xff;
    for (int k = 0; k < 3; k++) out[4 + k] = Div3((u32)c0[k] * 2 + 1 + (u32)c1[k]);
    out[7] = 0xff;
    for (int k = 0; k < 3; k++) out[8 + k] = Div3((u32)c1[k] * 2 + 1 + (u32)c0[k]);
    out[0xb] = 0xff;
    for (int k = 0; k < 3; k++) out[0xc + k] = Div3((u32)c1[k] * 3 + 1);
    out[0xf] = 0xff;
    return;
  }
  for (int k = 0; k < 3; k++) out[k] = c0[k];
  out[3] = 0xff;
  for (int k = 0; k < 3; k++) out[4 + k] = (s32)((u32)c0[k] + (u32)c1[k]) / 2;
  out[7] = 0xff;
  for (int k = 0; k < 3; k++) out[8 + k] = c1[k];
  out[0xb] = 0xff;
  out[0xc] = out[0xd] = out[0xe] = out[0xf] = 0;
}
PCREG(6383a0, DxtPalette);

// 0x63a1a0 GUESS DXT1 block indices for one channel (fastcall three_colour, ch; stack c0, c1 (5:6:5 ints), pixels
// (16 x {r, g, b, a} ints), out[16]; /GS): colours widened (x >> 5 | x; green >> 6 for c1, and for c0 unless
// three-colour), palette 0x6383a0; pixels with a == 0 get 3, others the nearest palette entry on channel ch
// (squared difference, first minimum).
extern "C" void FASTCALL ext_6383a0(u32, s32 *, s32 *, s32 *);
static void FASTCALL DxtIndices(u32 three, u32 ch, s32 *p0, s32 *p1, s32 *px, s32 *out) {
  s32 c1[3], c0[3];
  c0[0] = (p0[0] >> 5) | p0[0];
  c1[0] = (p1[0] >> 5) | p1[0];
  c0[1] = three ? (p0[1] >> 5) | p0[1] : (p0[1] >> 6) | p0[1];
  c1[1] = (p1[1] >> 6) | p1[1];
  c0[2] = (p0[2] >> 5) | p0[2];
  c1[2] = (p1[2] >> 5) | p1[2];
  s32 pal[16];
  ext_6383a0(three, pal, c0, c1);
  for (int i = 0; i < 16; i++) {
    s32 *q = px + 4 * i;
    if (!q[3]) {
      out[i] = 3;
      continue;
    }
    out[i] = -1;
    s32 best = 0x7fffffff;
    for (int k = 0; k < 4; k++) {
      u32 d = (u32)q[ch] - (u32)pal[4 * k + ch];
      s32 d2 = (s32)(d * d);
      if (d2 < best) {
        best = d2;
        out[i] = k;
      }
    }
  }
}
PCREG(63a1a0, DxtIndices);

// 0x50b860 ZScriptItemInterface_t::AttachItem(OpaqueCallParameters_t&) (low): result (p+8) arg 0 set to 0 (0x5002f0);
// item = scene.slot58(*arg1 of p+4) (log line 0x3c0 if none); item.slot1e0(0x1007d1) must accept (else log 0x3c5 with
// item+4); target = scene.slot58(*arg0) (log 0x3cb if none); under the lock 0x69d8f0: target.SendCommand(target,
// RegisterZMsg(0x688dd8, 0, 0x69d420, 0x3dd), *arg1).
extern "C" void *THISCALL ext_5003d0(void *, u32);
extern "C" void THISCALL ext_5002f0(void *, u32);
extern "C" void THISCALL ext_441730(void *);
extern "C" void THISCALL ext_440530(void *);
static void THISCALL AttachItem(void *, u8 *p) {
  ext_5002f0(ext_5003d0(*(void **)(p + 8), 0), 0);
  u8 *item = vcall<u8 *>(SCENE, 0x58, *(u32 *)ext_5003d0(*(void **)(p + 4), 1));
  if (!item) {
    void *pr = Logger(0x69d420, 0x3c0);
    (*(log2c_t *)(*(u8 **)pr + 0x2c))(pr, 0x69d780);
    return;
  }
  if (!vcall<u8>(item, 0x1e0, 0x1007d1u)) {
    void *pr = Logger(0x69d420, 0x3c5);
    (*(log2c_t *)(*(u8 **)pr + 0x2c))(pr, 0x69d5fc, F32(item, 4));
    return;
  }
  u8 *tgt = vcall<u8 *>(SCENE, 0x58, *(u32 *)ext_5003d0(*(void **)(p + 4), 0));
  if (!tgt) {
    void *pr = Logger(0x69d420, 0x3cb);
    (*(log2c_t *)(*(u8 **)pr + 0x2c))(pr, 0x69d8a8);
    return;
  }
  ext_441730((void *)0x69d8f0);
  u32 id = vcall<u32>(SCENE, 0x114, 0x688dd8u, 0u, 0x69d420u, 0x3ddu) & 0xffff;
  u32 data = *(u32 *)ext_5003d0(*(void **)(p + 4), 1);
  vcall<void>(tgt, 0x130, tgt, id, data);
  ext_440530((void *)0x69d8f0);
}
PCREG(50b860, AttachItem);
