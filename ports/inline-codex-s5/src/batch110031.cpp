// batch1218.cpp - pathfinding tree: doors and gates on a path (CheckLineAgainst*, PostProcessPath).
//
// ZPathfinder3: +0x2d int "doors changed" (rebuild the door list first), +0x36 / +0x3a gate count / array, +0x3e /
// +0x42 additional-door count / array. A door or gate is a 0x34-byte record: four corners (+0, +0xc, +0x18, +0x24)
// forming two triangles (0,1,2) and (2,3,0), and +0x30 a value copied into the path point's int slot.
#include "ff.h"

extern "C" u32 FASTCALL ext_4e2560(const float *start, const float *dir, const float *v0, const float *v1,
                                   const float *v2, float *t, u32 twoSided);   // IntersectTriangleAndLine
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract: dst = a - b
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);       // vaddscalar: dst += v * s (x87)
extern "C" void THISCALL ext_52b9d0(void *self);
extern "C" u8 *THISCALL ext_52a970(void *self, float *a, float *b, float *t);
extern "C" u8 *THISCALL ext_52a850(void *self, float *a, float *b, float *t);
extern "C" void *THISCALL ext_476dc0(void *lst, int n);
extern "C" void ext_41e2c0(void *p);

// Nearest crossing (smallest t in [0, best]) of the segment a -> b with the quads of a list. Returns the quad or NULL;
// *t gets the best parameter (unchanged when the list pointer is NULL).
static inline u8 *crossQuads(u8 *list, int count, float *a, float *b, float *t, float best) {
  if (!list) return 0;
  float d[3];
  ext_43e920(d, b, a);
  u8 *hit = 0;
  u8 *q = list;
  for (int i = 0; i < count; i++, q += 0x34) {
    if ((u8)ext_4e2560(a, d, (float *)q, (float *)(q + 0xc), (float *)(q + 0x18), t, 1) && *t >= 0.0f && best >= *t) {
      best = *t;
      hit = q;
    }
    if ((u8)ext_4e2560(a, d, (float *)(q + 0x18), (float *)(q + 0x24), (float *)q, t, 1) && *t >= 0.0f &&
        best >= *t) {
      best = *t;
      hit = q;
    }
  }
  *t = best;
  return hit;
}

// 0x52a970 ZPathfinder3::CheckLineAgainstGates(float*, float*, float&) [map high; GameCube reference]. Same over the gates,
// best t starts at 1.0 (within the segment only).
static u8 *THISCALL checkLineGates(u8 *self, float *a, float *b, float *t) {
  return crossQuads(*(u8 **)(self + 0x3a), *(int *)(self + 0x36), a, b, t, 1.0f);
}
PCREG(52a970, checkLineGates);

