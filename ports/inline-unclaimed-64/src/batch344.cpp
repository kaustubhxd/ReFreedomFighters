// batch344.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe helpers, stubbed on both sides in the spec. 0x4dc630: thiscall (ecx = object), two stack words (a, b), ret 8
// (verified in batch343.cpp; the spec stubs it here). 0x4da3a0: thiscall (ecx = object), no words; returns al.
extern "C" void THISCALL ext_4dc630(u8 *obj, u32 a, u32 b);
extern "C" u32 THISCALL ext_4da3a0(u8 *obj);

// Virtual calls. Node N (self[+0x10][+8]): slot 0x4c and 0x5c take one word (a pointer to the local, which the callee
// writes). Global G2 (0x70038c): slot 0xcc takes one word and returns eax (a pointer or 0).
typedef void(__attribute__((thiscall)) * Slot1VFn)(u8 *, u32);
typedef u32(__attribute__((thiscall)) * Slot1RFn)(u8 *, u32);

// 0x45d1f0: thiscall (ecx = self, plain ret). O = self[+8]; ext 0x4dc630(O, 0, 0x800000); al = ext 0x4da3a0(O).
// If al != 0 and N = self[+0x10][+8] is not null: local = 0; N->vtbl[0x4c](N, &local); eax = N2->vtbl[0x5c](N2, &local)
// (N2 = self[+0x10][+8] again); if local != 0, loop: p = G2->vtbl[0xcc](G2, eax); eax = p; if p != 0 and (p[+0x14] & 1)
// and not (p[+4] & 4): exit without the final call; otherwise eax = N2->vtbl[0x5c](N2, &local) and repeat while local != 0.
// If not exited: ext 0x4dc630(O, 0x800000, 0). GUESS: a per-object update loop that ends with a second flag update.
static void THISCALL refreshLoop_45d1f0(u8 *self) {
    u8 *O = *(u8 **)(self + 0x8);
    ext_4dc630(O, 0u, 0x800000u);
    u32 al = ext_4da3a0(O) & 0xffu;
    if (al != 0) {
        u8 *hold = *(u8 **)(self + 0x10);
        u8 *N = *(u8 **)(hold + 0x8);
        if (N != 0) {
            u32 local = 0;
            void **vn = *(void ***)N;
            ((Slot1VFn)vn[0x4c / 4])(N, (u32)&local);
            u8 *N2 = *(u8 **)(*(u8 **)(self + 0x10) + 0x8);
            void **vn2 = *(void ***)N2;
            u32 eaxv = ((Slot1RFn)vn2[0x5c / 4])(N2, (u32)&local);
            bool exited = false;
            while (local != 0) {
                u8 *g2 = G(u8 *, 0x70038c);
                void **vg = *(void ***)g2;
                u32 p = ((Slot1RFn)vg[0xcc / 4])(g2, eaxv);
                eaxv = p;
                if (p != 0 && (*(u8 *)(p + 0x14) & 1) && !(*(u8 *)(p + 0x4) & 4)) {
                    exited = true;
                    break;
                }
                N2 = *(u8 **)(*(u8 **)(self + 0x10) + 0x8);
                vn2 = *(void ***)N2;
                eaxv = ((Slot1RFn)vn2[0x5c / 4])(N2, (u32)&local);
            }
            if (!exited) ext_4dc630(O, 0x800000u, 0u);
            return;
        }
    }
    ext_4dc630(O, 0x800000u, 0u);
}
PCREG(45d1f0, refreshLoop_45d1f0);
