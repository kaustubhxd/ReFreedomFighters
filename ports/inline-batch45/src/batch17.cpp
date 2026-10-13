// batch17.cpp - first-level functions, inline session batch 17 (Haiku, overnight).
#include "ff.h"

static inline u32 rd32(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline void wr32(u32 p, u32 off, u32 v) { *(u32 *)(unsigned long)(p + off) = v; }

// 0x430910, fastcall (node in ECX, head slot in EDX, plain ret): moves node to the front of the list whose head is the
// u32 at *headSlot. Nodes link through u32 fields at +1, +5 and +9. Name unknown.
static void FASTCALL moveNode(u8 *nodeP, u8 *headP) {
  u32 node = (u32)(unsigned long)nodeP;
  u32 *headSlot = (u32 *)headP;
  u32 esi = rd32(node, 9);
  u32 eax = rd32(esi, 5);
  wr32(node, 9, eax);
  eax = rd32(esi, 5);
  if (eax != 0)
    wr32(eax, 1, node);
  eax = rd32(node, 1);
  wr32(esi, 1, eax);
  if (node == *headSlot) {
    *headSlot = esi;
    wr32(esi, 5, node);
    wr32(node, 1, esi);
    return;
  }
  eax = rd32(node, 1);
  if (node == rd32(eax, 5)) {
    wr32(eax, 5, esi);
    wr32(esi, 5, node);
    wr32(node, 1, esi);
    return;
  }
  wr32(eax, 9, esi);
  wr32(esi, 5, node);
  wr32(node, 1, esi);
}
PCREG(430910, moveNode);

// 0x44c230, thiscall (ret 4), one float argument: p = this->+0x18. When the float at p+0x88 is 0.0 it stores 1.0 and 2.0
// at p+0x54 and p+0x5c. Otherwise it stores arg * 100 at p+0x54 and (p+0x88 / 0.78125) * (arg * 100) at p+0x5c.
// Name unknown. Note: the original branches on ucomiss with jp, so NaN takes the scale path.
static void THISCALL setScales(u8 *self, float arg) {
  u8 *p = *(u8 **)(self + 0x18);
  float v = *(float *)(p + 0x88);
  if (v == 0.0f) {
    *(float *)(p + 0x54) = 1.0f;
    *(float *)(p + 0x5c) = 2.0f;
    return;
  }
  float x0 = arg * G(float, 0x67cd40);
  float x1 = v / G(float, 0x67cd3c);
  x1 = x1 * x0;
  *(float *)(p + 0x54) = x0;
  *(float *)(p + 0x5c) = x1;
}
PCREG(44c230, setScales);

// 0x446430, thiscall (ret 8), two stack pointers: out and in, each two floats (out[2] is also read). When bit 0 of
// this+0x48 is set, out[0] = in[0] / this+0x3c and out[1] = -(in[1] / this+0x40), where the minus is an xor with the
// sign bit (xorps with 0x67af40). Otherwise d = this+0x58 / out[2], out[0] = in[0] / d, out[1] = -((in[1] / d) / this+0x40).
// Name unknown.
static void THISCALL scalePair(u8 *self, float *out, const float *in) {
  u32 sign = G(u32, 0x67af40);
  if (self[0x48] & 1) {
    out[0] = in[0] / *(float *)(self + 0x3c);
    float y = in[1] / *(float *)(self + 0x40);
    out[1] = bitsf(fbits(y) ^ sign);
    return;
  }
  float d = *(float *)(self + 0x58) / out[2];
  out[0] = in[0] / d;
  float y = in[1] / d;
  y = y / *(float *)(self + 0x40);
  out[1] = bitsf(fbits(y) ^ sign);
}
PCREG(446430, scalePair);
