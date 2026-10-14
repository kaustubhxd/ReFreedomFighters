// batch357.cpp - area 76 (docs/20-unclaimed-76.md, parked row 0x61f5a0): cdecl, four arguments (this, p1, p2, p3), plain ret, eax
// result (GUESS). A string emitter over the cursor buffer B = this+0x1a8 (B+8 = end, B+0xc = cursor (this+0x1b4), B+0x10 = start
// (this+0x1b8)). Each step writes the NUL, calls 0x620180(B, p1, p2, p3), and copies the prefix before the first ':' of the string
// at start+1 into the buffer, growing with 0x6206e0(B) when the cursor reaches the end. The result object comes from 0x61fd60
// (cdecl, three arguments; hooked in the fixture); its first dword is compared with the key, and the "xmlns" prefix is checked
// (the second lookup on this+0x194 with the tail after "xmlns:"). The SEH frame is not reproduced.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_620180(u32 buf, u32 p1, u32 p2, u32 p3);
extern "C" u32 __attribute__((cdecl)) ext_6206e0(u32 buf);
extern "C" u32 __attribute__((cdecl)) ext_61fd60(u32 obj, u32 key, u32 size);

#define RU(a) (*(u32 *)(u32)(a))

static u32 __attribute__((cdecl)) f61f5a0(u32 O, u32 p1, u32 p2, u32 p3) {
    u32 B = O + 0x1a8u;
    if (RU(O + 0x1b4u) == RU(O + 0x1b0u)) {
        if (ext_6206e0(B) == 0u) return 0u;
    }
    *(u8 *)RU(O + 0x1b4u) = 0u;
    RU(O + 0x1b4u) += 1u;
    u32 r = ext_620180(B, p1, p2, p3);
    if (r == 0u) return 0u;
    if (RU(B + 0xcu) == RU(B + 8u)) {
        if (ext_6206e0(B) == 0u) return 0u;
    }
    *(u8 *)RU(B + 0xcu) = 0u;
    RU(B + 0xcu) += 1u;
    u32 edi = RU(B + 0x10u);
    if (edi == 0u) return 0u;
    edi += 1u;
    u32 res = ext_61fd60(O + 0x180u, edi, 0xcu);
    if (res == 0u) return 0u;
    if (RU(res) == edi) {
        RU(O + 0x1b8u) = RU(O + 0x1b4u);
        if (RU(O + 0xe8u) == 0u) return res;
        u8 c0 = *(u8 *)edi;
        if (c0 == 'x' && *(u8 *)(edi + 1) == 'm' && *(u8 *)(edi + 2) == 'l' && *(u8 *)(edi + 3) == 'n' &&
            *(u8 *)(edi + 4) == 's') {
            u8 c5 = *(u8 *)(edi + 5);
            if (c5 == 0u) {
                RU(res + 4u) = O + 0x1dcu;
                *(u8 *)(res + 9u) = 1u;
                return res;
            }
            if (c5 == ':') {
                u32 r2 = ext_61fd60(O + 0x194u, edi + 6u, 8u);
                RU(res + 4u) = r2;
                *(u8 *)(res + 9u) = 1u;
                return res;
            }
        }
        // 61f6ea: find the first ':' in the string at edi
        if (*(u8 *)edi == 0u) return res;
        u32 k = 0u;
        u8 al = c0;
        for (;;) {
            if (al == ':') break;
            k++;
            al = *(u8 *)(edi + k);
            if (al == 0u) return res;
        }
        // 61f70d: copy the k bytes of the prefix into the buffer
        for (u32 j = 0u; j < k; j++) {
            if (RU(O + 0x1b4u) == RU(O + 0x1b0u)) {
                if (ext_6206e0(B) == 0u) return 0u;
            }
            *(u8 *)RU(O + 0x1b4u) = *(u8 *)(edi + j);
            RU(O + 0x1b4u) += 1u;
        }
    } else {
        RU(O + 0x1b4u) = RU(O + 0x1b8u);    // 61f64a: not the key, reset the cursor to the start
        return res;
    }
    // 61f761 / 61f782: NUL, then the second lookup on this+0x194 with the saved start
    if (RU(O + 0x1b4u) == RU(O + 0x1b0u)) {
        if (ext_6206e0(B) == 0u) return 0u;
    }
    *(u8 *)RU(O + 0x1b4u) = 0u;
    u32 start = RU(O + 0x1b8u);
    RU(O + 0x1b4u) += 1u;
    u32 r2 = ext_61fd60(O + 0x194u, start, 8u);
    RU(res + 4u) = r2;
    if (RU(r2) == RU(O + 0x1b8u)) {
        RU(O + 0x1b8u) = RU(O + 0x1b4u);
    } else {
        RU(O + 0x1b4u) = RU(O + 0x1b8u);
    }
    return res;
}
PCREG(61f5a0, f61f5a0);
