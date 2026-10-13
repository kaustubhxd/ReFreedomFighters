// batch341.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe table lookup 0x5003d0 (thiscall, one stack word = index, ret 4). See batch326.cpp.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// Virtual call on the child: slot 0x8c, thiscall with one stack word (a pointer to a float[3]; the callee pops 4).
typedef void(__attribute__((thiscall)) * Slot8cFn)(u8 *, u32);

// Round-to-nearest double square root, the same result as the exe's sqrt (see batch304.cpp).
static inline double sqrtDouble341(double x) {
    double r;
    __asm__("sqrtsd %1, %0" : "=x"(r) : "x"(x));
    return r;
}

// 0x501430: thiscall (ecx = self, one stack pointer p, ret 4). T = p[+4]: e2 = lookup(T, 2), e1 = lookup(T, 1),
// e0 = lookup(T, 0); v = (*e0, *e1, *e2) as floats. self[+0xc]->vtbl[0x8c](child, v) may update v. len = sqrt(v1*v1 + v0*v0 +
// v2*v2) (sums in that order, float; sqrt in double; rounded to float). e = lookup(p[+8], 0): *e = len (float) and e[+4] = 2
// (byte). The exe's error path, reached only when e[+4] is not 0 or 2, is not modelled; the spec keeps the tag in range.
// GUESS: a length of a vector read from a table, kept in a second table entry.
static void THISCALL setLength_501430(u8 *self, u8 *p) {
    u8 *T = *(u8 **)(p + 0x4);
    u8 *e2 = (u8 *)ext_5003d0(T, 2u);
    u8 *e1 = (u8 *)ext_5003d0(T, 1u);
    u8 *e0 = (u8 *)ext_5003d0(T, 0u);
    float v[3] = {*(float *)e0, *(float *)e1, *(float *)e2};

    u8 *child = *(u8 **)(self + 0xc);
    void **vt = *(void ***)child;
    ((Slot8cFn)vt[0x8c / 4])(child, (u32)v);

    float s = v[1] * v[1];
    s = s + v[0] * v[0];
    s = s + v[2] * v[2];
    float len = (float)sqrtDouble341((double)s);

    u8 *e = (u8 *)ext_5003d0(*(u8 **)(p + 0x8), 0u);
    *(float *)e = len;
    *(u8 *)(e + 4) = 2;
}
PCREG(501430, setLength_501430);
