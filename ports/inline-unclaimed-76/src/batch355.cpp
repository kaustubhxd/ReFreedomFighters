// batch355.cpp - area 76 (docs/20-unclaimed-76.md, parked row 0x61b570): thiscall, four stack arguments (a, b, c, d), ret 0x10,
// bool in AL (GUESS). Guards: [this+0xc] != 0 and [[this+4]+0x14] != 0, else false. Lock 0x6bde70 and 0x6bde7c around a cache
// lookup (T = [[b+0xb9a4]+0x13fa], cache = T.vtbl[4](0, 0) once, stored at T+0x30). Two shapes on X = [[a+0x10]+8]:
//   count = [X+0x50] == 1: chunks of up to 32 elements (stride 36) go to a 6-argument helper (0x65bc60/0x65bcc0/0x65bd20, by the
//     two flag bytes of b), then the engine tail (0x1c8, 0x17c with 0x6bde70). Returns false.
//   otherwise: a fractional index from [a+0xc]->+0x48 / +0x4c; per chunk, an engine test (0x1c8, 0x178 with 0x6bde84), an
//     interpolation of nine dwords per element into the global buffer 0x724b80 (colour dword through 0x616e00), the helper, then the
//     cursors advance by chunk*36. Ends with the engine tail. Returns true.
// The SEH frame and the cookie check are not reproduced.
#include "ff.h"

extern "C" void THISCALL ext_441730(u8 *self);
extern "C" void THISCALL ext_440530(u8 *self);
extern "C" void THISCALL ext_65bc60(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern "C" void THISCALL ext_65bcc0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern "C" void THISCALL ext_65bd20(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern "C" void __attribute__((fastcall)) ext_616e00(u32 out, u32 c1p, u32 c2p, float t);

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

#define RU(a) (*(u32 *)(u32)(a))
#define RF(a) (*(float *)(u32)(a))
#define WF(a, v) (*(float *)(u32)(a) = (v))

static s32 cvtt(float f) {
    if (!(f >= -2147483648.0f && f < 2147483648.0f)) return (s32)0x80000000u;
    return (s32)f;
}
// unsigned dword to float through the table at 0x680aa0 (sign bit selects 0.0 or 2^32)
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

// The dispatch of the three six-argument helpers (ECX = this). The flags are the two bytes of b.
static void dispatch6(u32 self, u8 g, u8 f, u32 elem, u32 second, u32 chunk, u32 c, u32 d, u32 x20) {
    if (g != 0u) {
        ext_65bd20((u8 *)self, elem, second, chunk, c, d, x20);
    } else if (f != 0u) {
        ext_65bcc0((u8 *)self, elem, second, chunk, c, d, x20);
    } else {
        ext_65bc60((u8 *)self, elem, second, chunk, c, d, x20);
    }
}

// 61b7f0 / 61b8??: the engine tail with ECX = E and EDX = the cursor (0x6bde70 or 0x6bde84 as the third argument).
static void engineTail(u32 E, u32 edx, u32 tag) {
    if (RF(E + 0x9c7u) != 0.0f && RF(E + 0x9c3u) != 0.0f) {
        u32 r = vc(E, 0x1c8u, 0x67a7f8u, 0x260u);
        vc(E, 0x17cu, r, edx, tag);
    }
}

static u8 THISCALL f61b570(u8 *selfp, u32 a, u32 b, u32 c, u32 d) {
    u32 self = (u32)selfp;
    if (RU(self + 0xcu) == 0u) return 0u;
    if (RU(RU(self + 4u) + 0x14u) == 0u) return 0u;
    ext_441730((u8 *)0x6bde70u);
    u32 rec = RU(a + 0xcu);
    u32 W = RU(a + 0x10u);
    u32 X = RU(W + 8u);
    u32 word = (u32)*(u16 *)(X + 0xeu);
    u32 P = RU(b + 0xb9a4u);
    u8 f = *(u8 *)(P + 0x1295u);
    u8 g = *(u8 *)(P + 0x1296u);
    u32 T = RU(P + 0x13fau);
    ext_441730((u8 *)0x6bde7cu);
    if (RU(T + 0x30u) == 0u) RU(T + 0x30u) = vc(T, 4u, 0u, 0u);
    u32 C = RU(T + 0x30u);
    ext_440530((u8 *)0x6bde7cu);
    u32 E = G(u32, 0x70039cu);
    u32 Q = RU(E + 0x1aa3u);
    u32 cur = RU(Q + 0x20u) + RU(X + 0x14u);
    u32 elem = C + RU(self + 0xcu) * 36u;
    u32 count = RU(X + 0x50u);
    u32 x20 = RU(X + 0x20u);

    if (count == 1u) {
        // path 1: chunks of up to 32 elements, no interpolation
        u32 r = word;
        if (r != 0u) {
            for (;;) {
                u32 chunk = (r > 0x20u) ? 0x20u : r;
                r -= chunk;
                dispatch6(self, g, f, elem, cur, chunk, c, d, x20);
                cur += chunk * 36u;
                elem += chunk * 36u;
                if (r == 0u) break;
            }
        }
        engineTail(E, cur, 0x6bde70u);
        return 0u;
    }

    // path 2
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
    u32 edx = pmin;
    if (word == 0u) {
        engineTail(E, edx, 0x6bde70u);
        return 1u;
    }
    u32 rem = word;
    for (;;) {
        u32 chunk = (rem > 0x20u) ? 0x20u : rem;
        rem -= chunk;
        // 61b7ac: engine test, then the 0x178 call with EDX = pmin
        if (RF(E + 0x9c7u) != 0.0f && RF(E + 0x9c3u) != 0.0f) {
            u32 r = vc(E, 0x1c8u, 0x67a7f8u, 0x259u);
            vc(E, 0x178u, r, edx, 0x6bde84u);
            edx = pmin;
        }
        if (chunk != 0u) {
            // 61b81e: interpolation over the chunk
            u32 pm = pmin;
            edx = pm - p0;                  // delta (kept in EDX across the loop)
            u32 delta = edx;
            u32 buf = 0x724b80u;
            for (u32 i = 0; i < chunk; i++) {
                u32 B = buf + 36u * i;
                u32 P0 = p0 + 36u * i;
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
                edx = delta;
            }
        }
        // 61b950: engine test with 0x260 and the cursor left in EDX
        if (RF(E + 0x9c7u) != 0.0f && RF(E + 0x9c3u) != 0.0f) {
            u32 r = vc(E, 0x1c8u, 0x67a7f8u, 0x260u);
            vc(E, 0x17cu, r, edx, 0x6bde84u);
        }
        dispatch6(self, g, f, elem, 0x724b78u, chunk, c, d, x20);
        // 61b9d9: advance the cursors by chunk * 36
        edx = pmin;
        p0 += chunk * 36u;
        edx += chunk * 36u;
        elem += chunk * 36u;
        pmin = edx;
        if (rem == 0u) break;
    }
    engineTail(E, edx, 0x6bde70u);
    return 1u;
}
PCREG(61b570, f61b570);
