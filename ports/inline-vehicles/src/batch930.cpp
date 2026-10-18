// batch930.cpp - vehicles thread, batch 930: ZCar::UpdateSound.
#include "ff.h"

extern "C" float THISCALL ext_522f60(void *path, float t, float dist);  // CMoveAlongPath::CalcTurnAngle (923)
extern "C" void THISCALL ext_441890(void *node, float v);               // sound node range (name unknown)
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }

static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline void *sndMgr() { return *(void **)(sysp() + 0x1a9f); }
static inline u32 lookup(u8 *s, u32 pattern) { return vcall<u32>(sndMgr(), 0x60, *(u32 *)(s + 0x12f), pattern); }
static inline u32 play(u8 *s, u32 pattern) { return vcall<u32>(s, 0x2e8, lookup(s, pattern)); }
static inline u8 *node(u32 h) { return vcall<u8 *>(*(void **)(sysp() + 0x9b), 0x60, h); }
typedef long double(THISCALL *rfn)(void *, const char *, u32);
static inline long double rndl(u32 line) {
  u8 *sy = sysp();
  return (*(rfn *)(*(u8 **)sy + 0x1c0))(sy, (const char *)0x69eff8, line);
}
static inline void stop(u8 *s, u32 off) {
  if (*(u32 *)(s + off)) {
    vcall<void>(s, 0x2ec, *(u32 *)(s + off));
    *(u32 *)(s + off) = 0;
  }
}
static inline void speedUp(u8 *s, u32 pattern, u32 l1, u32 l2) {
  u8 *n = node(play(s, pattern));
  if (n) {
    s32 v = _mm_cvttss_si32(_mm_set_ss(smul(smul(F(s, 0x1e1), 0.5f), F(*(u8 **)(s + 0x5c), 0x24))));
    *(s32 *)(n + 0x60) = v - *(s32 *)(n + 0x64);
    *(s32 *)(n + 0x64) = v;
  }
  volatile float r = (float)rndl(l1);
  if (r > 0.5f) {
    u8 *a = node(play(s, 0x69f124));
    if (a) {
      volatile float r2 = (float)rndl(l2);
      F(a, 0x78) = smul(sadd(smul(r2, 1000.0f), 500.0f), 0.0010000000474974513f);
    }
  }
  s[0x1649] = 0;
}
static inline void skidNode(u8 *s, u32 h, u32 delay, float k) {
  u8 *n = node(h);
  if (!n)
    return;
  *(u32 *)(n + 0x78) = delay;
  s32 p = *(s32 *)(s + 0x1635);
  *(s32 *)(n + 0x60) = p - *(s32 *)(n + 0x64);
  *(s32 *)(n + 0x64) = p;
  F(n, 0x84) = smul(F(s, 0x1f1), k);
}

// 0x518bc0 ZCar::UpdateSound() (needs the sound manager, engine +0x1a9f).
//  - Path state 3 (path +0x35): "*Turn*" (+0x1621) while the turn angle 50 units ahead is over 10, else stopped.
//  - Speed-up as the tank's but with car thresholds: after a moment of no acceleration, > 200 plays
//    "*Engine_SpeedUp*", > 100 "*Engine_SpeedUp_Low*" (pitch (int)(+0x1e1 * 0.5 * speed), 50% "*Air*" 0.5-1.5 s
//    later); arming flag +0x1649.
//  - Horn: closer than 900 (+0x2bf) and moving, 25% of frames "*Horn*".
//  - Scramble (radio chatter): with +0x160b set and a volume factor +0x163d, up to +0x1645 times (count +0x1639)
//    "*Scramble*" (id kept at +0x1631) at volume +0x1f1 * factor - rand * 0.25, pitch (rand - 0.75) * 100, range
//    +0x1641.
//  - Skid state +0x1603: 0 = all skid loops off; 1 = "*Spinning*" (+0x1625) only; 2 = "*Skid*" (+0x1629, delay 0.3)
//    and "*_Break*" (+0x162d, delay 0.05) with the skid pitch +0x1635 and volume +0x1f1 * min(1, speed / 1000).
static void THISCALL carUpdateSound(u8 *s) {
  if (!sndMgr())
    return;
  u8 *p = *(u8 **)(s + 0x5c);
  if (*(u32 *)(p + 0x35) == 3) {
    volatile float a = ext_522f60(p, F(p, 4), 50.0f);
    if (a > 10.0f)
      *(u32 *)(s + 0x1621) = play(s, 0x69f108);
    else
      stop(s, 0x1621);
  }
  float acc = F(*(u8 **)(s + 0x5c), 0x28);
  if (!(0.0f < acc))
    s[0x1649] = 1;
  if (s[0x1649]) {
    if (acc > 200.0f)
      speedUp(s, 0x69f110, 0x2a9, 0x2ae);
    else if (acc > 100.0f)
      speedUp(s, 0x69f12c, 0x2bb, 0x2c0);
  }
  if (900.0f > F(s, 0x2bf) && F(*(u8 **)(s + 0x5c), 0x24) != 0.0f) {
    volatile float r = (float)rndl(0x2c8);
    if (r > 0.75f)
      play(s, 0x69f144);
  }
  if (s[0x160b] && F(s, 0x163d) != 0.0f && *(s32 *)(s + 0x1639) <= *(s32 *)(s + 0x1645)) {
    u32 id = lookup(s, 0x69f14c);
    *(u32 *)(s + 0x1631) = id;
    u8 *n = node(vcall<u32>(s, 0x2e8, id));
    if (n) {
      volatile float base = smul(F(s, 0x1f1), F(s, 0x163d));
      long double r1 = rndl(0x2d9);
      F(n, 0x84) = (float)((long double)base - r1 * (long double)0.25f);
      long double r2 = rndl(0x2da);
      volatile float pf = (float)((r2 - (long double)0.75f) * (long double)100.0f);
      s32 pi = _mm_cvttss_si32(_mm_set_ss(pf));
      s32 old = *(s32 *)(n + 0x64);
      *(s32 *)(n + 0x64) = pi;
      *(s32 *)(n + 0x60) = pi - old;
      ext_441890(n, F(s, 0x1641));
    }
    ++*(s32 *)(s + 0x1639);
  }
  u32 st = *(u32 *)(s + 0x1603);
  if (st == 0) {
    stop(s, 0x1625);
    stop(s, 0x1629);
    stop(s, 0x162d);
  } else if (st == 1) {
    stop(s, 0x1629);
    stop(s, 0x162d);
    if (!*(u32 *)(s + 0x1625))
      *(u32 *)(s + 0x1625) = play(s, 0x69f158);
  } else if (st == 2) {
    stop(s, 0x1625);
    if (!*(u32 *)(s + 0x1629))
      *(u32 *)(s + 0x1629) = play(s, 0x69f164);
    if (!*(u32 *)(s + 0x162d))
      *(u32 *)(s + 0x162d) = play(s, 0x69f16c);
    float k = _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f),
                                       _mm_set_ss(smul(F(*(u8 **)(s + 0x5c), 0x24), 0.0010000000474974513f))));
    skidNode(s, *(u32 *)(s + 0x1629), 0x3e99999a, k);
    skidNode(s, *(u32 *)(s + 0x162d), 0x3d4ccccd, k);
  }
}
PCREG(518bc0, carUpdateSound);
