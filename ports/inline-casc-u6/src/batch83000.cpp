#include "ff.h"

// COMISS condition codes: JB includes unordered; JA is ordered greater.
static inline bool comiss_b(float a, float b) {
  unsigned char r;
  asm volatile("comiss %1, %2; setb %0" : "=qm"(r) : "x"(b), "x"(a) : "cc");
  return r != 0;
}
static inline bool comiss_a(float a, float b) {
  unsigned char r;
  asm volatile("comiss %1, %2; seta %0" : "=qm"(r) : "x"(b), "x"(a) : "cc");
  return r != 0;
}
static inline bool comiss_be(float a, float b) {
  unsigned char r;
  asm volatile("comiss %1, %2; setbe %0" : "=qm"(r) : "x"(b), "x"(a) : "cc");
  return r != 0;
}

static u8 THISCALL fn4e2800(u8 *out, float a, float b, float c, float d,
                            float e, float f, float g, float h,
                            float i, float j, float k, float l) {
  const float z = 0.0f;
  if (!comiss_b(g,a) && !comiss_b(d,g) && !comiss_b(h,b) && !comiss_b(e,h) &&
      !comiss_b(i,c) && !comiss_b(f,i) && !comiss_b(k,c) && !comiss_b(f,k) &&
      !comiss_b(l,d) && !comiss_b(h,l)) {
    *(float *)out = 0.0f;
    return 1;
  }
  {
    float r1 = (j > 0.0f ? a : d) - g;
    float r2 = (k > 0.0f ? b : e) - h;
    float r3 = (l > 0.0f ? f : c) - i;
    r1 /= j;
    r2 /= k;
    r3 /= l;

    if (!comiss_b(r1,r2) && !comiss_b(r1,r3)) {
      float x = r1*k + h;
      float y = r1*l + i;
      if (comiss_a(b,x) || comiss_a(x,e) || comiss_a(c,y) || comiss_a(y,f)) return 0;
      *(float *)out = r1;
      if (comiss_b(r1,z) || comiss_b(G(float, 0x678858),r1)) return 0;
      return 1;
    }
    if (!comiss_b(r2,r3)) {
      float x = r2*l + i;
      float y = r2*j + g;
      if (comiss_a(c,x) || comiss_a(x,k) || comiss_a(a,y) || comiss_a(y,d)) return 0;
      *(float *)out = r2;
      if (comiss_b(r2,z) || comiss_b(G(float, 0x678858),r2)) return 0;
      return 1;
    }
    float x = r3*j + g;
    float y = r3*k + h;
    if (comiss_a(a,x) || comiss_a(x,d) || comiss_a(b,y) || comiss_a(y,e)) return 0;
    *(float *)out = r3;
    if (comiss_b(r3,z) || comiss_b(G(float, 0x678858),r3)) return 0;
    return 1;
  }
}
PCREG(4e2800, fn4e2800);
