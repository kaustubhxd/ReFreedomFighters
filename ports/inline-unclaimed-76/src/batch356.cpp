// batch356.cpp - area 76 (docs/20-unclaimed-76.md, parked row 0x61b1e0): thiscall, four stack arguments (a, b, c, d), ret 0x10,
// bool in AL (GUESS). Guards as 0x61b570. Lock 0x6bde70. Two caches: T = [[b+0xb9a4]+0x13fa] and U = [[b+0xb9a4]+0x13fe] (each
// vtbl[4](0, 0) once, stored at +0x30). The element pointer is U.cache + 4 * [this+0xc] (stride 4). X = [[a+0x10]+8].
//   count == 1 (path 1): chunks of up to 32 through 0x65bc00 (elem, cur, chunk, c, d, X+0x20); cur advances by chunk * 36; the element
//     pointer does not move. Tail: engine 0x1c8 (0x67a7f8, 0x260), 0x17c (r, EDX = X, 0x6bde70). Returns false.
//   otherwise (path 2): frac from [a+0xc]+0x48 and X+0x48/+0x4c, p0 = cur + idx * word * 36, pmin = cur + min(idx+1, count-1) * word * 36;
//     per chunk: nine dwords per element into the buffer 0x725000 (colour dword through 0x616e00), then 0x65bc00 with the buffer
//     base 0x724ff8; cursors advance by chunk * 36. Tail as path 1 with EDX = the buffer end. Returns true.
// The SEH frame and the cookie check are not reproduced.
#include "ff.h"

extern "C" void THISCALL ext_441730(u8 *self);
extern "C" void THISCALL ext_65bc00(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern "C" void __attribute__((fastcall)) ext_616e00(u32 out, u32 c1p, u32 c2p, float t);

template <class... P>
static u32 vc(u32 obj, u32 off, P... p) {
    typedef u32(THISCALL * fn)(u32, P...);
    return ((fn)(*(u32 *)(*(u32 *)obj + off)))(obj, p...);
}

#define RU(a) (*(u32 *)(u32)(a))
#define RF(a) (*(float *)(u32)(a))
#define WF(a, v) (*(float *)(u32)(a) = (v))

static s32 cvtt(float f) {
    if (!(f >= -2147483648.0f && f < 2147483648.0f)) return (s32)0x80000000u;
    return (s32)f;
}
static float u2f(u32 x) {
    double d = (double)(s32)x;
    if ((x & 0x80000000u) != 0u) d += 4294967296.0;
    return (float)d;
}
static float lerpF(float p, float q, float t) {
    float d = q - p;
    float m = d * t;
    return m + p;
}

static void engineTail(u32 E, u32 edx) {
    if (RF(E + 0x9c7u) != 0.0f && RF(E + 0x9c3u) != 0.0f) {
        u32 r = vc(E, 0x1c8u, 0x67a7f8u, 0x260u);
        vc(E, 0x17cu, r, edx, 0x6bde70u);
    }
}

static u8 THISCALL f61b1e0(u8 *selfp, u32 a, u32 b, u32 c, u32 d) {
    u32 self = (u32)selfp;
    if (RU(self + 0xcu) == 0u) return 0u;
    if (RU(RU(self + 4u) + 0x14u) == 0u) return 0u;
    ext_441730((u8 *)0x6bde70u);
    u32 rec = RU(a + 0xcu);
    u32 W = RU(a + 0x10u);
    u32 X = RU(W + 8u);
    u32 P = RU(b + 0xb9a4u);
    u32 T = RU(P + 0x13fau);
    u32 U = RU(P + 0x13feu);
    if (RU(T + 0x30u) == 0u) RU(T + 0x30u) = vc(T, 4u, 0u, 0u);
    if (RU(U + 0x30u) == 0u) RU(U + 0x30u) = vc(U, 4u, 0u, 0u);
    u32 E = G(u32, 0x70039cu);
    u32 x = RU(self + 0xcu);
    u32 Q = RU(E + 0x1aa3u);
    u32 cur = RU(Q + 0x20u) + RU(X + 0x14u);
    u32 count = RU(X + 0x50u);
    u32 elem = RU(U + 0x30u) + 4u * x;
    u32 word = (u32)*(u16 *)(X + 0xeu);
    u32 xp20 = RU(X + 0x20u);
    u8 flag = 0u;
    u32 edx = X;

    if (count == 1u) {
        u32 rem = word;
        if (rem != 0u) {
            for (;;) {
                u32 chunk = (rem > 0x20u) ? 0x20u : rem;
                ext_65bc00((u8 *)self, elem, cur, chunk, c, d, xp20);
                cur += chunk * 36u;
                rem -= chunk;
                edx = X;
                if (rem == 0u) break;
            }
        }
        engineTail(E, edx);
        return flag;
    }

    // path 2
    flag = 1u;
    float F1 = RF(rec + 0x48u);
    float frac = 0.0f;
    if (F1 != 0.0f) {
        float V1 = u2f(RU(X + 0x48u));
        float V2 = u2f(RU(X + 0x4cu));
        frac = (F1 - V1) / V2;
    }
    s32 idx = cvtt(frac);
    u32 cm1 = count - 1u;
    u32 mn = ((u32)idx + 1u <= cm1) ? (u32)idx + 1u : cm1;
    float fracS = frac - (float)idx;
    u32 p0 = cur + (u32)idx * word * 36u;
    u32 pmin = cur + mn * word * 36u;
    edx = mn * word;
    if (word == 0u) {
        engineTail(E, edx);
        return flag;
    }
    u32 rem = word;
    u32 cursor = p0;
    u32 pm = pmin;
    for (;;) {
        u32 chunk;
        if (rem > 0x20u) {
            chunk = 0x20u;
            rem -= 0x20u;
        } else {
            chunk = rem;
            rem = 0u;
        }
        if (chunk != 0u) {
            u32 p0c = cursor;
            for (u32 i = 0; i < chunk; i++) {
                u32 B = 0x725000u + 36u * i;
                u32 P0 = p0c + 36u * i;
                u32 PM = pm + 36u * i;
                float t = fracS;
                WF(B - 8u, lerpF(RF(P0 + 0u), RF(PM + 0u), t));
                WF(B - 4u, lerpF(RF(P0 + 4u), RF(PM + 4u), t));
                WF(B + 0u, lerpF(RF(P0 + 8u), RF(PM + 8u), t));
                WF(B + 4u, lerpF(RF(P0 + 0xcu), RF(PM + 0xcu), t));
                WF(B + 8u, lerpF(RF(P0 + 0x10u), RF(PM + 0x10u), t));
                WF(B + 0xcu, lerpF(RF(P0 + 0x14u), RF(PM + 0x14u), t));
                ext_616e00(B + 0x10u, P0 + 0x18u, PM + 0x18u, t);
                WF(B + 0x14u, lerpF(RF(P0 + 0x1cu), RF(PM + 0x1cu), t));
                WF(B + 0x18u, lerpF(RF(P0 + 0x20u), RF(PM + 0x20u), t));
                edx = B + 36u;
            }
        }
        // 61b4d0: dispatch with the buffer base 0x724ff8 as the second argument
        ext_65bc00((u8 *)self, elem, 0x724ff8u, chunk, c, d, xp20);
        cursor += chunk * 36u;
        pm += chunk * 36u;
        if (rem == 0u) break;
    }
    engineTail(E, edx);
    return flag;
}
PCREG(61b1e0, f61b1e0);
