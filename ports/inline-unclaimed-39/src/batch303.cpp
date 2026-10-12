// batch303.cpp - decomp area 39 (docs/20-unclaimed-39.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helpers, run as original code. All three are fastcall (first in ECX, second in EDX, no stack arguments).
// 0x4e2c60: m = ECX (3x3 matrix), v = EDX (float[3], in/out) - the abs transform.
// 0x4419f0: ECX = vector (in/out), EDX = matrix; x87 matrix-vector product.
// 0x441940: ECX += EDX (vector add).
extern "C" void FASTCALL ext_4e2c60(u8 *m, u8 *v);
extern "C" void FASTCALL ext_4419f0(u8 *v, u8 *m);
extern "C" void FASTCALL ext_441940(u8 *v, u8 *w);

// Virtual call on the global object's child (sys->[0x9b]): thiscall with no stack arguments, returns al.
typedef u8(__attribute__((thiscall)) * Slot70Fn)(u8 *);

// 0x4db460: thiscall (ecx = self, two stack arguments a and b, ret 8), returns bool in al.
// Returns false if obj->vtbl[0x70](obj) is nonzero, if self.flags(+0x3c) has 0x40000, if self.f(+0x4c) == 0.0
// (an ordered compare; NaN passes), or if self[+0x50] == 0. Then, if a is null, returns true with no writes.
// Otherwise a[0..2] = self[+0x30..+0x38]; b[0..2] = self[+0x40..+0x48] (b is not null-checked); 0x4e2c60(self, b);
// 0x4419f0(a, self); 0x441940(a, self+0x24); returns true. GUESS: a gated copy-and-transform of a record.
static u8 THISCALL gateCopy_4db460(u8 *self, u8 *a, u8 *b) {
    u8 *sys = G(u8 *, 0x70039c);
    u8 *obj = *(u8 **)(sys + 0x9b);
    void **vt = *(void ***)obj;
    if (((Slot70Fn)vt[0x70 / 4])(obj) != 0) return 0;
    if (*(u32 *)(self + 0x3c) & 0x40000u) return 0;
    float f = *(float *)(self + 0x4c);
    if (f == 0.0f) return 0;
    if (*(u32 *)(self + 0x50) == 0) return 0;
    if (a == 0) return 1;
    *(u32 *)(a + 0) = *(u32 *)(self + 0x30);
    *(u32 *)(a + 4) = *(u32 *)(self + 0x34);
    *(u32 *)(a + 8) = *(u32 *)(self + 0x38);
    *(u32 *)(b + 0) = *(u32 *)(self + 0x40);
    *(u32 *)(b + 4) = *(u32 *)(self + 0x44);
    *(u32 *)(b + 8) = *(u32 *)(self + 0x48);
    ext_4e2c60(self, b);
    ext_4419f0(a, self);
    ext_441940(a, self + 0x24);
    return 1;
}
PCREG(4db460, gateCopy_4db460);
