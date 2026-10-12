// batch317.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x61ce20, a cdecl state machine (5 args: A, B, P, C, Dv; ret
// plain, GUESS). All object calls go through function pointers stored in the objects: B+8 (state step, 4 args), B+0x3c (5 args),
// A+0x3c (3 args), A+0x4c (1 arg). The exe helper 0x620cb0 (cdecl, 4 args) is called by address. The jump table at 0x61d040 and the
// byte map at 0x61d05c (45 entries) select the case: 0 and 1 store v through Dv (or return 0x14 / 6), 2 stores S and returns 4,
// 3 is a loop over A+0x3c, 4 calls A+0x3c with a byte 0xa, 5 calls A+0x4c, 6 (and any index above 0x2c) is the default exit (returns 0x17).
#include "ff.h"

typedef u32(__attribute__((cdecl)) * fnStep_t)(u32, u32, u32, u32);
typedef u32(__attribute__((cdecl)) * fnB_t)(u32, u32, u32, u32, u32);
typedef u32(__attribute__((cdecl)) * fnC_t)(u32, u32, u32);
typedef u32(__attribute__((cdecl)) * fnD_t)(u32);
extern "C" u32 __attribute__((cdecl)) ext_620cb0(u32 a, u32 b, u32 v, u32 s);

static const u8 kCaseOf_61ce20[45] = {0, 6, 1, 0, 2, 6, 6, 6, 6, 6, 3, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5};

static u32 __attribute__((cdecl)) state_61ce20(u32 A, u32 B, u32 P, u32 C, u32 Dv) {
    u32 S = A;
    u32 v = *(u32 *)P;
    u32 X, W;
    if (B == *(u32 *)(A + 0x8cu)) {
        X = A + 0x118u;
        W = A + 0x11cu;
    } else {
        X = *(u32 *)(A + 0x124u);
        W = X + 4u;
    }
    *(u32 *)X = v;
    *(u32 *)P = 0u;
    u32 r = ((fnStep_t)*(u32 *)(B + 8u))(B, v, C, (u32)&S);
    *(u32 *)W = S;
    u32 k = r + 4u;
    u32 code = 0u;
    for (;;) {
        if (k > 0x2cu) goto default_exit;
        code = kCaseOf_61ce20[k];
        if (code == 0u) {
            if (Dv != 0u) {
                *(u32 *)Dv = v;
                return 0u;
            }
            return 0x14u;
        }
        if (code == 1u) {
            if (Dv != 0u) {
                *(u32 *)Dv = v;
                return 0u;
            }
            return 6u;
        }
        if (code == 2u) {
            *(u32 *)X = S;
            return 4u;
        }
        if (code == 3u) {
            if (*(u32 *)(A + 0x3cu) == 0u) goto cf68;
            if (*(u8 *)(B + 0x48u) != 0u) goto cf57;
            for (;;) {
                u32 L12 = *(u32 *)(A + 0x2cu);
                ((fnB_t)*(u32 *)(B + 0x3cu))(B, (u32)&v, S, (u32)&L12, *(u32 *)(A + 0x30u));
                *(u32 *)W = S;
                u32 c2 = *(u32 *)(A + 0x2cu);
                ((fnC_t)*(u32 *)(A + 0x3cu))(*(u32 *)(A + 4u), c2, L12 - c2);
                u32 r2 = v;
                if (r2 == S) break;
                *(u32 *)X = r2;
            }
            goto tail;
        }
        if (code == 4u) {
            if (*(u32 *)(A + 0x3cu) == 0u) goto cf68;
            u8 bb = 0xau;
            ((fnC_t)*(u32 *)(A + 0x3cu))(*(u32 *)(A + 4u), (u32)&bb, 1u);
            goto tail;
        }
        if (code == 5u) {
            if (*(u32 *)(A + 0x4cu) != 0u) {
                ((fnD_t)*(u32 *)(A + 0x4cu))(*(u32 *)(A + 4u));
            } else if (*(u32 *)(A + 0x50u) != 0u) {
                ext_620cb0(A, B, v, S);
            }
            *(u32 *)P = S;
            return 0u;
        }
    default_exit:
        *(u32 *)X = S;
        return 0x17u;
    cf57:
        ((fnC_t)*(u32 *)(A + 0x3cu))(*(u32 *)(A + 4u), v, S - v);
        goto tail;
    cf68:
        if (*(u32 *)(A + 0x50u) != 0u) ext_620cb0(A, B, v, S);
    tail:
        v = S;
        *(u32 *)X = S;
        r = ((fnStep_t)*(u32 *)(B + 8u))(B, v, C, (u32)&S);
        *(u32 *)W = S;
        k = r + 4u;
    }
}
PCREG(61ce20, state_61ce20);
