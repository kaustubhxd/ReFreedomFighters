// batch38046.cpp - cascade s8 batch 38046: 0x5d95a0 (event handler: set / report a numbered value of a control).
#include "ff.h"

extern "C" int ext_42ac56(char *buf, const char *fmt, ...);   // sprintf-like, cdecl varargs
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define TABLE (*(u8 **)(G(u8 *, 0x70039c) + 0x9b))
#define U16F(off) (*(u16 *)(self + (off)))
#define U32F(off) (*(u32 *)(self + (off)))

static u8 *lookup(u32 id) {
  u8 *t = TABLE;
  return (u8 *)SLOT(t, 0x58, v1_t)(t, id);
}

// 0x5d95a0, thiscall(id, v) ret 8, returns 0. Dispatches on the u16 id against four ids at this+0x80 / +0x86 / +0x82 / +0x84: +0x80 sets the state +0x88 (v 0 -> 0, v 1 -> 0xfe, other values
// ignored); +0x86 looks up +0x60 and +0x5c (unused) and +0x58, picks the string id for v <= 7 from the table 0x6ef80c into +0x98 and sends it with the text 0x6b5f0c to the +0x58 object (slot 0x288) and
// then slot 0xbc(0); +0x82 formats v (<= 99) with 0x6b64dc / 0x6b64e4 and sends the two texts to the +0x60 / +0x5c objects, clearing +0x8c and setting +0x88 = 0xfe (v == -1 only sets +0x88 = 0);
// +0x84 formats (v, i) for the three ids at +0x74 / +0x78 / +0x7c with 0x6b64f4 and sends each to its object, then +0x94 = 0 and +0x90 = 0xfe (v == -1 sets +0x90 = 0).
static u32 THISCALL fn5d95a0(u8 *self, u32 idarg, u32 v) {
  u16 id = (u16)idarg;
  if (id == U16F(0x80)) {
    if (v == 0) U32F(0x88) = 0;
    else if (v == 1) U32F(0x88) = 0xfe;
    return 0;
  }
  if (id == U16F(0x86)) {
    lookup(U32F(0x60));
    lookup(U32F(0x5c));
    if (v <= 7) U32F(0x98) = G(u32, 0x6ef80c + v * 4);
    u8 *o = lookup(U32F(0x58));
    if (o) {
      SLOT(o, 0x288, v2_t)(o, U32F(0x98), 0x6b5f0c);
      SLOT(o, 0xbc, v1_t)(o, 0);
    }
    return 0;
  }
  if (id == U16F(0x82)) {
    u8 *p = lookup(U32F(0x60));
    u8 *q = lookup(U32F(0x5c));
    if (v <= 99) {
      char b24[12], b18[12];
      ext_42ac56(b24, (const char *)0x6b64dc, v);
      ext_42ac56(b18, (const char *)0x6b64e4, v);
      if (p) SLOT(p, 0x288, v2_t)(p, U32F(0x98), (u32)b24);
      if (q) SLOT(q, 0x288, v2_t)(q, U32F(0x98), (u32)b18);
      U32F(0x8c) = 0;
      U32F(0x88) = 0xfe;
    } else if (v == 0xffffffff) {
      U32F(0x88) = 0;
    }
    return 0;
  }
  if (id == U16F(0x84)) {
    u32 ids[3] = {U32F(0x74), U32F(0x78), U32F(0x7c)};
    if (v <= 2) {
      for (u32 i = 0; i < 3; i++) {
        u8 *o = lookup(ids[i]);
        if (o) {
          char b[12];
          ext_42ac56(b, (const char *)0x6b64f4, v, i);
          SLOT(o, 0x288, v2_t)(o, U32F(0x98), (u32)b);
        }
      }
      U32F(0x94) = 0;
      U32F(0x90) = 0xfe;
    } else if (v == 0xffffffff) {
      U32F(0x90) = 0;
    }
  }
  return 0;
}
PCREG(5d95a0, fn5d95a0);
