// batch18.cpp - first-level functions, inline session batch 18 (Haiku, overnight).
#include "ff.h"

static inline u32 rd32(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline void wr32(u32 p, u32 off, u32 v) { *(u32 *)(unsigned long)(p + off) = v; }

// 0x430960, fastcall (node in ECX, head slot in EDX, plain ret): a second list move like batch 17's moveNode, with
// the links at +1, +5 and +9 used in a different order. Name unknown.
static void FASTCALL moveNodeAlt(u8 *nodeP, u8 *headP) {
  u32 node = (u32)(unsigned long)nodeP;
  u32 *headSlot = (u32 *)headP;
  u32 esi = rd32(node, 5);
  u32 eax = rd32(esi, 9);
  wr32(node, 5, eax);
  eax = rd32(esi, 9);
  if (eax != 0)
    wr32(eax, 1, node);
  eax = rd32(node, 1);
  wr32(esi, 1, eax);
  if (node == *headSlot) {
    *headSlot = esi;
    wr32(esi, 9, node);
    wr32(node, 1, esi);
    return;
  }
  eax = rd32(node, 1);
  if (node == rd32(eax, 9)) {
    wr32(eax, 9, esi);
    wr32(esi, 9, node);
    wr32(node, 1, esi);
    return;
  }
  wr32(eax, 5, esi);
  wr32(esi, 9, node);
  wr32(node, 1, esi);
}
PCREG(430960, moveNodeAlt);

// 0x4463b0, thiscall (ret 8), stack pointers out (2 floats) and in (2 floats). Bit 0 of this+0x48 picks the path.
// Path 1 is the same as batch 17's scalePair. Path 2 multiplies the second lane by this+0x181 before the sign flip.
// Name unknown.
static void THISCALL scalePairAlt(u8 *self, float *out, const float *in) {
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
  y = y * *(float *)(self + 0x181);
  out[1] = bitsf(fbits(y) ^ sign);
}
PCREG(4463b0, scalePairAlt);

// 0x446320, thiscall (ret 8), stack pointers out (2 floats) and in (3 floats; in[2] is read in path 2). Bit 0 of this+0x48
// picks the path. Path 1 multiplies: out[0] = this+0x3c * in[0] and out[1] = -(this+0x40 * in[1]). Path 2 clamps in[2]
// from below by 0.001 with maxss (dst first: the result is dst > src ? dst : src), then k = this+0x58 / that, and
// out[0] = in[0] * k, out[1] = -(in[1] * k * this+0x40). Name unknown.
static void THISCALL scaleMul(u8 *self, float *out, const float *in) {
  u32 sign = G(u32, 0x67af40);
  if (self[0x48] & 1) {
    out[0] = *(float *)(self + 0x3c) * in[0];
    float y = *(float *)(self + 0x40) * in[1];
    out[1] = bitsf(fbits(y) ^ sign);
    return;
  }
  float t = G(float, 0x67d9fc);
  float mx = t > in[2] ? t : in[2];
  float k = *(float *)(self + 0x58) / mx;
  out[0] = in[0] * k;
  float y = in[1] * k;
  y = y * *(float *)(self + 0x40);
  out[1] = bitsf(fbits(y) ^ sign);
}
PCREG(446320, scaleMul);
