// batch6237 - unclaimed-62 claim 30 (short SSE vector helpers): three fastcall functions over the first two floats of two vectors.
//   0x4dfd50  fastcall (dst = ecx, b = edx, a = one stack argument; ret 4): dst[0] = b[0] + a[0]; dst[1] = b[1] + a[1]
//   0x4dfd80  fastcall (dst = ecx, src = edx; no stack arguments): dst[0] = dst[0] + src[0]; dst[1] = src[1] + dst[1]
//   0x4e0010  fastcall (dst = ecx, src = edx; no stack arguments): dst[0] = dst[0] - src[0]; dst[1] = dst[1] - src[1]
#include "ff.h"

static float rdf(const float *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static void wrf(float *p, float v) { __builtin_memcpy(p, &v, 4); }

static void FASTCALL fn4dfd50(float *dst, const float *b, const float *a) {
  wrf(&dst[0], rdf(&b[0]) + rdf(&a[0]));
  wrf(&dst[1], rdf(&b[1]) + rdf(&a[1]));
}

static void FASTCALL fn4dfd80(float *dst, const float *src) {
  wrf(&dst[0], rdf(&dst[0]) + rdf(&src[0]));
  wrf(&dst[1], rdf(&src[1]) + rdf(&dst[1]));
}

static void FASTCALL fn4e0010(float *dst, const float *src) {
  wrf(&dst[0], rdf(&dst[0]) - rdf(&src[0]));
  wrf(&dst[1], rdf(&dst[1]) - rdf(&src[1]));
}

PCREG(4dfd50, fn4dfd50);
PCREG(4dfd80, fn4dfd80);
PCREG(4e0010, fn4e0010);
