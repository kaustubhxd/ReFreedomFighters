// batch350.cpp - residue-15 (docs/20-unclaimed-76.md): 0x468570 (ret 8; GUESS; one piece).
// Shape: __fastcall-style: ECX = this (T), EDX = input (read on the 0x1c8/0x178 path and the 0x17c tail), stack a1 (unused), a2 = A.
// Helpers are exe code and hooked by address in the fixture: 0x4db2f0 (1 arg), 0x4dc630 (2), 0x4da340 (4), 0x4db2c0 (2 out-pointers).
// The stack cookie check (0x633654) and the SEH frame are not reproduced.
#include "ff.h"

extern "C" u32 THISCALL ext_4db2f0(u8 *self, u32 p);
extern "C" void THISCALL ext_4dc630(u8 *self, u32 p1, u32 p2);
extern "C" void THISCALL ext_4da340(u8 *self, u32 p1, u32 p2, u32 p3, u32 p4);
extern "C" void THISCALL ext_4db2c0(u8 *self, u32 p1, u32 p2);

// thiscall vtable calls: the first argument is the callee's first parameter (the last value the exe pushes).
template <class... P>
static u32 vc(u32 obj, u32 off, P... p) {
    typedef u32(THISCALL * fn)(u32, P...);
    return ((fn)(*(u32 *)(*(u32 *)obj + off)))(obj, p...);
}
template <class... P>
static void vcv(u32 obj, u32 off, P... p) {
    typedef void(THISCALL * fn)(u32, P...);
    ((fn)(*(u32 *)(*(u32 *)obj + off)))(obj, p...);
}

// cvttss2si: out of range or NaN gives the x86 "indefinite" value 0x80000000
static s32 cvtt(float f) {
    if (!(f >= -2147483648.0f && f < 2147483648.0f)) return (s32)0x80000000u;
    return (s32)f;
}
static u32 bitsOf(float f) {
    u32 r;
    __builtin_memcpy(&r, &f, 4);
    return r;
}

static void FASTCALL f468570(u32 thisp, u32 edxIn, u32 a1, u32 a2) {
    (void)a1;
    u32 ebx = thisp;       // T (this)
    u32 edx = edxIn;       // EDX is read before it is written on the 0x1c8/0x178 path
    u32 c38 = a2;          // A: [ebp-0x38]
    u32 edi = 0u, esi = 0u, eax = 0u;
    u32 c40 = 0u, c44 = 0u, c3c = 0u;
    u32 l10 = 0u, l34 = 0u;

    if (*(u8 *)(ebx + 0xe5u) != 0u) {
        eax = *(u32 *)(c38 + 8u);
        if ((*(u32 *)(eax + 0x3cu) & 0x1000u) == 0u) return;
    }
    // 4685a3: engine float gates (x == 0.0 skips; NaN does not)
    {
        u32 ecx = G(u32, 0x70039cu);
        if (*(float *)(ecx + 0x9c7u) != 0.0f && *(float *)(ecx + 0x9c3u) != 0.0f) {
            eax = vc(ecx, 0x1c8u, 0x67a7f8u, 0x259u);
            ecx = G(u32, 0x70039cu);
            vc(ecx, 0x178u, eax, edx, 0x688fa0u);
        }
    }
    vcv(c38, 0x2f4u);
    c44 = 0u;
    esi = vc(ebx, 0x8cu, c38);      // T.0x8c(A)
    c40 = esi;
    if (esi == 0u) {
        esi = *(u32 *)(ebx + 0x44u);
        c40 = esi;
    } else {
        c44 = *(u32 *)(ebx + 0x44u);
    }
    // 468629
    edi = 0u;
    if ((vc(esi, 0x1e0u, 0x1007d3u) & 0xffu) != 0u) {
        edx = *(u32 *)esi;
        edi = vc(esi, 0x2c4u, *(u32 *)(*(u32 *)(G(u32, 0x70039cu) + 0x9bu) + 0xadcu), 0x4954454du);
    } else {
        eax = *(u32 *)(ebx + 0x53u);
        if (eax == 0u) {
            eax = *(u32 *)(esi + 4u);
            u32 name = 0x67c8e8u;
            if (eax != 0u) name = eax;
            edx = c38;
            edi = vc(edx, 0x30cu, name);     // A.0x30c(name)
            eax = *(u32 *)(esi + 0xcu);
            if ((*(u32 *)(eax + 0x23u) & 0x100000u) != 0u) {
                if (edi != 0u) vcv(edi, 0x210u, 1u);
                eax = vc(esi, 0x1b8u, c38, 0u, 0u, 0u, 1u);
                edi = eax;
                vcv(edi, 0x2cu);
            } else if (edi != 0u) {
                vc(edi, 0xfcu, esi);
            } else {
                eax = vc(esi, 0x1b8u, c38, 0u, 0u, 0u, 1u);
                edi = eax;
                vcv(edi, 0x2cu);
            }
        } else if (eax == 1u) {
            u32 r20 = vc(c38, 0x20u, 0u, 0u, 0u, 1u);
            edi = vc(c40, 0x1b8u, r20);
        } else if (eax == 2u) {
            u32 r = ext_4db2f0((u8 *)*(u32 *)(c38 + 8u), 0u);
            edx = *(u32 *)esi;    // 468736: the shared tail of paths 2 and 3 loads the vtable into EDX
            edi = vc(c40, 0x1b8u, r, 0u, 0u, 0u, 1u);
        } else if (eax == 3u) {
            u32 x = *(u32 *)(*(u32 *)(G(u32, 0x70039cu) + 0x9bu) + 0xadcu);
            edx = *(u32 *)esi;    // 468736
            edi = vc(c40, 0x1b8u, x, 0u, 0u, 0u, 1u);
        }
    }
    // 468742 (edi is the result object: [edi+8] is the first list entry)
    ext_4dc630((u8 *)*(u32 *)(edi + 8u), 0u, 0x800000u);
    if (*(u32 *)(ebx + 0x53u) != 0u) vcv(edi, 0x2cu);
    eax = vc(edi, 0x100u, 0x688854u);
    if (eax != 0u) {
        edx = *(u32 *)eax;
        vcv(eax, 0x54u, edi);
    }
    // 468779: out-pointers l34 (arg 1) and l10 (arg 2)
    if (c44 != 0u) {
        ext_4db2c0((u8 *)*(u32 *)(c44 + 8u), (u32)&l34, (u32)&l10);
    } else {
        ext_4db2c0((u8 *)*(u32 *)(edi + 8u), (u32)&l34, (u32)&l10);
    }
    if (*(u8 *)(ebx + 0x52u) != 0u) {
        esi = *(u32 *)c38;
        u32 ecx = *(u32 *)(G(u32, 0x70039cu) + 0x9bu);
        eax = vc(ecx, 0x4cu, edi);
        vc(c38, 0x2d8u, eax);
    }
    // 4687c3: the two out-pointers are pushed here for the next calls (0x74, or 0x98 + 0x7c)
    if (*(u32 *)(ebx + 0x53u) == 0u) {
        vcv(edi, 0x74u, (u32)&l34, (u32)&l10);
    } else {
        vcv(c38, 0x98u, (u32)&l34, (u32)&l10);
        vcv(edi, 0x7cu, (u32)&l34, (u32)&l10);
    }
    // 4687f9
    if (*(u8 *)(ebx + 0x60u) != 0u) {
        u32 o = *(u32 *)(c38 + 0x6cu);
        u32 ecx = *(u32 *)(G(u32, 0x70039cu) + 0x9bu);
        u32 r = vc(ecx, 0x4cu, edi);
        vcv(o, 0x4u, r);
    }
    if (*(u8 *)(ebx + 0x5fu) != 0u) {
        u32 o = *(u32 *)(c38 + 0x70u);
        u32 ecx = *(u32 *)(G(u32, 0x70039cu) + 0x9bu);
        u32 r = vc(ecx, 0x4cu, edi);
        vcv(o, 0x4u, r);
    }
    // 468848: walk the list from [edi+8]
    c3c = *(u32 *)(edi + 8u);
    while (c3c != 0u) {
        if ((*(u32 *)(c3c + 0x3cu) & 0x800000u) == 0u) {
            edx = *(u32 *)(c3c + 0x54u);
            if (edx != 0u) vcv(edx, 0x154u);
            ext_4dc630((u8 *)c3c, 0x800000u, 0u);
            ext_4da340((u8 *)c3c, 1u, 0u, 0u, 0u);
            ext_4da340((u8 *)c3c, 2u, 0u, 0u, 0u);
            edx = *(u32 *)(c3c + 0x54u);
            if (edx != 0u) vcv(edx, 0x158u);
            edx = *(u32 *)(c3c + 0x54u);
            if (edx != 0u) eax = *(u32 *)(*(u32 *)(edx + 0xcu) + 0x23u);
            else eax = 0x200002u;
            if ((eax & 0x400000u) != 0u) vcv(ebx, 0x94u, edx);
        }
        // 4688ed
        {
            u32 ecx = *(u32 *)(c3c + 0x54u);
            if (ecx != 0u) {
                edx = *(u32 *)ecx;
                vc(ecx, 0x128u, (u32)*(u16 *)(ebx + 0x48u), c38, 0u);
            }
        }
        vcv(edi, 0x50u, (u32)&c3c);     // iterator: advances c3c
    }
    // 46891c: float scale when [T+0x5b] != 0 (NaN counts as nonzero, as in the exe)
    {
        float x = *(float *)(ebx + 0x5bu);
        if (x != 0.0f) {
            float t = x * G(float, 0x67862cu);
            s32 c = cvtt(t);
            edx = G(u32, 0x70039cu);
            ebx = c38;
            eax = *(u32 *)(edx + 0x40u) - (u32)c;
            u32 ecx = *(u32 *)(edx + 0x9bu);
            float f = (float)(s32)eax * G(float, 0x6785e4u);
            u32 r = vc(ecx, 0x4cu, edi, bitsOf(f));
            vc(ebx, 0x314u, r);
        }
    }
    // 468976: tail call with the EDX value the exe left
    {
        u32 ecx = G(u32, 0x70039cu);
        if (*(float *)(ecx + 0x9c7u) != 0.0f && *(float *)(ecx + 0x9c3u) != 0.0f) {
            eax = vc(ecx, 0x1c8u, 0x67a7f8u, 0x260u);
            ecx = G(u32, 0x70039cu);
            vc(ecx, 0x17cu, eax, edx, 0x688fa0u);
        }
    }
}
PCREG(468570, f468570);
