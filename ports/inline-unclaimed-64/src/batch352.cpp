// batch352.cpp - decomp area 64 (docs/20-unclaimed-64.md): dedicated pass on the exe function 0x43ec00.
#include "ff.h"

// Exe helpers, stubbed on both sides in the spec (GUESS). 0x441730 and 0x440530: thiscall (ecx = 0x67cd30), no words.
// 0x441890: thiscall (ecx = R), one float stack word (unused by the exe body); the exe body writes R[+0x54] and R[+0x5c]
// when R[+0x88] == 0.
extern "C" void THISCALL ext_441730(u8 *self);
extern "C" void THISCALL ext_440530(u8 *self);
extern "C" void THISCALL ext_441890(u8 *R, float unused);

// Virtual calls. Child (sys[+0x1a9f]): slot 0x11c takes four words and returns eax; slot 0x54 and 0xd8 are used as below.
// Child2 (sys[+0x9b]): slot 0x60 takes one word and returns eax. self: slot 0x84 takes one word.
typedef u32(__attribute__((thiscall)) * Slot4Fn)(u8 *, u32, u32, u32, u32);
typedef u32(__attribute__((thiscall)) * Slot1Fn)(u8 *, u32);
typedef u32(__attribute__((thiscall)) * Slot6Fn)(u8 *, u32, u32, u32, u32, u32, u32);

// 0x43ec00: thiscall (ecx = self, six stack words A, B, C, D, E, F; ret 0x18). Child = sys[+0x1a9f] (sys = 0x70039c).
// If child is null, return 0. If C is 0, return 0. Call 0x441730(0x67cd30); r = child->vtbl[0x11c](child, self, C, A, B);
// call 0x440530(0x67cd30). If r is 0, return 0. R = sys[+0x9b]->vtbl[0x60](.., r); if R is 0, return 0. X = child->vtbl[0x54](child,
// R[+0x7c]); call 0x441890(R, X[+0xc]). If D == 0xc, return r. If D == 0: return r unless X[0] == 2 and (signed byte) X[+0x17] != 0,
// in which case D = that byte. Otherwise (or then): local = B[0..2]; self->vtbl[0x84](self, &local); child->vtbl[0xd8](child, self,
// &local, D, C, E, F); return r. GUESS: a two-phase update of a record through the child, with a helper pair on a fixed object.
static u32 THISCALL callChild_43ec00(u8 *self, u32 A, u32 B, u32 C, u32 D, u32 E, u32 F) {
    u8 *sys = G(u8 *, 0x70039c);
    if (*(u32 *)(sys + 0x1a9f) == 0) return 0;
    if (C == 0) return 0;

    ext_441730((u8 *)0x67cd30u);
    u8 *child = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
    void **vc = *(void ***)child;
    u32 r = ((Slot4Fn)vc[0x11c / 4])(child, (u32)self, C, A, B);
    ext_440530((u8 *)0x67cd30u);
    if (r == 0) return 0;

    u8 *c2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    void **v2 = *(void ***)c2;
    u32 R = ((Slot1Fn)v2[0x60 / 4])(c2, r);
    if (R == 0) return 0;

    u8 *c3 = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
    void **v3 = *(void ***)c3;
    u32 X = ((Slot1Fn)v3[0x54 / 4])(c3, *(u32 *)(R + 0x7c));
    float xf = *(float *)(X + 0xc);
    ext_441890((u8 *)R, xf);

    u32 Dv = D;
    if (Dv != 0xc) {
        bool go = true;
        if (Dv == 0) {
            if (*(u32 *)X != 2) {
                go = false;
            } else {
                Dv = (u32)(s32)(s8)*(u8 *)(X + 0x17);
                if (Dv == 0) go = false;
            }
        }
        if (go) {
            float local[3] = {*(float *)B, *(float *)(B + 4), *(float *)(B + 8)};
            void **vs = *(void ***)self;
            ((Slot1Fn)vs[0x84 / 4])(self, (u32)local);
            u8 *c4 = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
            void **v4 = *(void ***)c4;
            ((Slot6Fn)v4[0xd8 / 4])(c4, (u32)self, (u32)local, Dv, C, E, F);
        }
    }
    return r;
}
PCREG(43ec00, callChild_43ec00);
