#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);

extern "C" void FASTCALL ext_4419f0(void *p, void *m);
extern "C" void FASTCALL ext_441940(void *p, void *m);

static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x49b9a0: fastcall(M, N, r, list) ret 8 -> bool in AL: does any triangle of the list lie within distance r of the origin after two transforms? The list object's slot 0x4c(&it)
// restarts the iteration and slot 0x64(&it) returns the next item (0 at the end); an item holds three vertices (+4, +0x10, +0x1c as float triples). A triangle with two equal vertices
// (compared component by component, NaN counts as different) is skipped; otherwise the vertices are transformed in place by 0x4419f0(vertex, M) and 0x441940(vertex, N) and the item
// is taken (return 1) as soon as one of them has squared length below r * r (strict, float operations in the order y^2 + x^2, + z^2).
extern "C" u32 FASTCALL fn_49b9a0(void *M, void *N, float r, void *list) {
  float P[9];
  u32 it[3];
  float r2 = r * r;
  u8 bl = 0;
  if (!list) return 0;
  (*(V1 *)(vt(list) + 0x4c))(list, (u32)it);
  u8 *item = (u8 *)(*(V1 *)(vt(list) + 0x64))(list, (u32)it);
  while (item) {
    const u8 *v1 = item + 4, *v2 = item + 0x10, *v3 = item + 0x1c;
    bool d12 = !(rdf(v1) == rdf(v2) && rdf(v1 + 4) == rdf(v2 + 4) && rdf(v1 + 8) == rdf(v2 + 8));
    bool skip = false;
    if (!d12) skip = true;
    else if (rdf(v2) == rdf(v3) && rdf(v2 + 4) == rdf(v3 + 4) && rdf(v2 + 8) == rdf(v3 + 8)) skip = true;
    else if (rdf(v3) == rdf(v1) && rdf(v3 + 4) == rdf(v1 + 4) && rdf(v3 + 8) == rdf(v1 + 8)) skip = true;
    if (!skip) {
      for (int i = 0; i < 9; i++) P[i] = rdf(item + 4 + 4 * i);
      ext_4419f0(&P[0], M);
      ext_4419f0(&P[3], M);
      ext_4419f0(&P[6], M);
      ext_441940(&P[0], N);
      ext_441940(&P[3], N);
      ext_441940(&P[6], N);
      float a = P[7] * P[7];
      float b = P[6] * P[6];
      a = a + b;
      float c = P[8] * P[8];
      a = a + c;
      bl = r2 > a;
      float d = P[4] * P[4];
      float e = P[3] * P[3];
      d = d + e;
      float f = P[5] * P[5];
      d = d + f;
      bl |= (r2 > d);
      float g = P[1] * P[1];
      float h = P[0] * P[0];
      g = g + h;
      float k = P[2] * P[2];
      g = g + k;
      bl |= (r2 > g);
      if (bl) break;
    }
    item = (u8 *)(*(V1 *)(vt(list) + 0x64))(list, (u32)it);
  }
  return bl;
}
PCREG(49b9a0, fn_49b9a0);
