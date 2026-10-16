// batch936.cpp - vehicles thread, batch 936: ZVehicle::ClassCommand(unsigned short cmd, void* msg), 0x5153e0, callee
// pops 8, returns the result of the base class call (or 0). The vehicle's command words are matched first:
//  +0x2ca VehicleTempStop: with the path flagged (+0x46) and started more than 7 s ago (1024 ticks/s), the stop timer
//         +0x2c4 = now + 0x800 and +0x233 = 0 (return 0). Otherwise, if the timer has run out, the message's object
//         (render manager slot 0x58 of msg[0]) is checked against a box (+0x21b / +0x22b / +0x223 on its position
//         from slot 0x84 / 0x8c); when it is outside the box, the path is driven by msg[1] (0x523ec0) and +0x233 =
//         msg[2], or the "none" value -1e38 when msg[2] == -1.0. Then the base class runs when +0x2c3 is set.
//  +0x2cc VehicleContinue: +0x233 = 0, the path continues (0x523180), then the base class runs.
//  +0x207 forwarded to slot 0x368 (msg); returns 0.
//  +0x2d0 SE_RocketHit: returns 0 when msg[0] is the vehicle itself; otherwise the base class runs.
// Anything else: the base class (0x5122f0, ZMoveOnSpline::ClassCommand).
// Stood in (both runs): 0x523ec0 (path drive), 0x5122f0 (base). 0x523180 is the lifted Continue (batch 931).
#include "ff.h"

extern "C" void THISCALL ext_523ec0(void *path, float v);
extern "C" u32 THISCALL ext_5122f0(void *self, u32 cmd, u32 *msg);
extern "C" void THISCALL ext_523180(void *path);

#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline float absf(float x) { return bitsf(fbits(x) & 0x7fffffffu); }
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x5153e0 ZVehicle::ClassCommand(unsigned short cmd, void* msg).
static u32 THISCALL vehClassCommand(u8 *s, u32 cmdw, u32 *msg) {
  u16 cmd = (u16)cmdw;
  if (cmd == *(u16 *)(s + 0x2ca)) {
    u8 *p = *(u8 **)(s + 0x5c);
    s32 now = *(s32 *)(sysp() + 0x40);
    if (p[0x46]) {
      s32 start = _mm_cvttss_si32(_mm_mul_ss(_mm_load_ss((float *)(p + 0x47)), _mm_set_ss(1024.0f)));
      float el = _mm_cvtss_f32(_mm_mul_ss(_mm_set_ss((float)(now - start)), _mm_set_ss(0.0009765625f)));
      if (!(el <= 7.0f)) {
        *(s32 *)(s + 0x2c4) = now + 0x800;
        *(u32 *)(s + 0x233) = 0;
        return 0;
      }
    }
    if (*(s32 *)(s + 0x2c4) > now)
      return 0;
    u32 g = vcall<u32>(*(void **)(sysp() + 0x9b), 0x58, msg[0]);
    if (!g)
      return 0;
    float L[3];
    vcall<void>((void *)g, 0x84, L);
    vcall<void>(s, 0x8c, L);
    bool outside = absf(L[0]) > F(s, 0x21b) || absf(L[1]) > F(s, 0x22b) || absf(L[2]) > F(s, 0x223);
    if (outside) {
      ext_523ec0(*(void **)(s + 0x5c), F(msg, 4));
      float v = F(msg, 8);
      *(float *)(s + 0x233) = v;
      if (v == -1.0f)
        *(u32 *)(s + 0x233) = 0x7e967699;
    }
    if (s[0x2c3] == 0)
      return 0;
    return ext_5122f0(s, cmdw, msg);
  }
  if (cmd == *(u16 *)(s + 0x2cc)) {
    *(u32 *)(s + 0x233) = 0;
    ext_523180(*(void **)(s + 0x5c));
    return ext_5122f0(s, cmdw, msg);
  }
  if (cmd == *(u16 *)(s + 0x207)) {
    vcall<void>(s, 0x368, msg);
    return 0;
  }
  if (cmd == *(u16 *)(s + 0x2d0)) {
    u32 g = vcall<u32>(*(void **)(sysp() + 0x9b), 0x58, msg[0]);
    if (g == (u32)s)
      return 0;
  }
  return ext_5122f0(s, cmdw, msg);
}
PCREG(5153e0, vehClassCommand);
