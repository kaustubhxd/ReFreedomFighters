// batch343.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe helpers, stubbed on both sides in the spec (the port calls the same addresses).
// 0x4d9d20 and 0x4da770: thiscall (ecx = self), one stack word (0). 0x4dbb00: thiscall, one stack word (0).
// 0x4da360: thiscall (ecx = node), two stack words (first = cl, second = 0). 0x4db840: thiscall (ecx = self), no words;
// returns eax (the spec chooses it per case).
extern "C" void THISCALL ext_4d9d20(u8 *self, u32 zero);
extern "C" void THISCALL ext_4da770(u8 *self, u32 zero);
extern "C" void THISCALL ext_4da360(u8 *node, u32 first, u32 second);
extern "C" u32 THISCALL ext_4dbb00(u8 *self, u32 zero);
extern "C" u32 THISCALL ext_4db840(u8 *self);

// Virtual calls. Global child (sys[+0x9b]): slot 0x178 and 0x40 take no words and return al. X = child[+0x5d35]:
// slot 0x24 and 0x28 take one word (self) and return eax.
typedef u8(__attribute__((thiscall)) * Slot0Fn)(u8 *);
typedef u32(__attribute__((thiscall)) * Slot1Fn)(u8 *, u32);

// 0x4dc630: thiscall (ecx = self, two stack words a and b, ret 8). The flag word is self[+0x3c], the list head self[+0x50],
// the result self[+0x68]. Part 1 clears bit 0x2000 of b (after a call on self) when a lacks it and self[+0x3c] has it.
// Part 2 sets bit 0x2000 of self[+0x3c] (after a call) when a has it and self lacks it, and clears it from a. Part 3, if
// (a | b) low byte is nonzero: self[+0x3c] low byte = low byte of ((~b & flags) | a&0xff); if a&0xff != 0 and the list is
// not empty, each node gets 4da360(node, a&0xff, 0). Part 4: a and b lose their low byte. If (a | b) has 0x8000, the global
// child's slot 0x178 is called (nonzero: done), then slot 0x40 (zero: done); with a's 0x8000 the flag and list and 4db840
// checks decide a call to X slot 0x24, and flags |= 0x1000000, result self[+0x68] = that value; without it (the other
// branch), 4dbb00 may run and X slot 0x28 is called, and self[+0x68] = 0. Every path that does not return early ends
// with self[+0x3c] = (~b & flags) | a. GUESS: a flag-merge with two callbacks.
static void THISCALL setControl_4dc630(u8 *self, u32 A, u32 B) {
    u32 *flags = (u32 *)(self + 0x3c);
    u32 a = A, b = B;
    u8 *sys = G(u8 *, 0x70039c);
    u8 *child = *(u8 **)(sys + 0x9b);

    // Part 1.
    if (b & 0x2000u) {
        if (!(a & 0x2000u)) {
            if (*flags & 0x2000u) {
                *flags &= ~0x2000u;
                ext_4d9d20(self, 0u);
                b &= ~0x2000u;
            }
        }
    }
    // Part 2.
    if (a & 0x2000u) {
        if (!(*flags & 0x2000u)) {
            ext_4da770(self, 0u);
            *flags |= 0x2000u;
            a &= ~0x2000u;
        }
    }
    // Part 3.
    if (((a | b) & 0xffu) != 0) {
        u32 cl = a & 0xffu;
        u32 t = (~b & *flags) | cl;
        *flags = (*flags & ~0xffu) | (t & 0xffu);
        if (cl != 0) {
            u8 *node = *(u8 **)(self + 0x50);
            while (node) {
                ext_4da360(node, cl, 0u);
                node = *(u8 **)(node + 0x50);
            }
        }
    }
    // Part 4.
    a &= ~0xffu;
    b &= ~0xffu;
    if (((a | b) & 0x8000u) == 0) goto G;

    // The global child: slot 0x178 nonzero ends with G.
    {
        void **vt = *(void ***)child;
        if (((Slot0Fn)vt[0x178 / 4])(child)) goto G;
    }
    {
        void **vt = *(void ***)child;
        if (!((Slot0Fn)vt[0x40 / 4])(child)) goto H;
    }
    if (!(a & 0x8000u)) goto I;

    // F: a has 0x8000.
    if (*flags & 0x8008000u) goto H;
    if (*(u32 *)(self + 0x6c) == 0) goto H;
    {
        u32 r = ext_4db840(self);
        if (!(r & 0xa00000u)) goto H;
        u8 *X = *(u8 **)(child + 0x5d35);
        if (!X) goto H;
        void **vx = *(void ***)X;
        u32 r24 = ((Slot1Fn)vx[0x24 / 4])(X, (u32)self);
        *flags |= 0x1000000u;
        u32 res = (~b & *flags) | a;
        *(u32 *)(self + 0x68) = r24;
        *flags = res;
        return;
    }

I:
    // I: a lacks 0x8000; b must have 0x8000 for the next test.
    if (!(b & 0x8000u)) goto H;
    if ((*flags & 0x8008000u) != 0x8000u) goto H;
    if (*(u32 *)(self + 0x6c) == 0) goto H;
    {
        u32 r = ext_4db840(self);
        if (!(r & 0xa00000u)) goto H;
        u8 *X = *(u8 **)(child + 0x5d35);
        if (!X) goto H;
        if (r & 0x800000u) ext_4dbb00(self, 0u);
        void **vx = *(void ***)X;
        ((Slot1Fn)vx[0x28 / 4])(X, (u32)self);
        *flags |= 0x1000000u;
        u32 res = (~b & *flags) | a;
        *(u32 *)(self + 0x68) = 0;
        *flags = res;
        return;
    }

G:
H:
    *flags = (~b & *flags) | a;
}
PCREG(4dc630, setControl_4dc630);
