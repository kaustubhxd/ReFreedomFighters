// batch1035.cpp - ZCamHelper::InitRecruitWayPoints() (0x5d0310): collects the level's waypoint objects (named
// "*waypoint*", case-insensitive) into this+0x4c (20-byte entries: zero, x, y, z, object pointer) and, when
// "ShowWayPoints" is set, draws a debug marker for each one. Camera thread, 2026-10-11.
#include "ff.h"
template<class T>static T&at(void*p,u32 o){return *(T*)((u8*)p+o);}
static u8*ptr(void*p,u32 o){return at<u8*>(p,o);}
#define SYS9B ptr(G(void*,0x70039c),0x9b)

extern "C" FASTCALL int ext_4cc850(const char *a, const char *b);  // striwcmp (exe)
extern "C" FASTCALL void ext_4de7a0(float *m);                     // mreset (exe)
static inline u32 wayFtoi(float v){u32 out;asm volatile("call *%[f]" : "=a"(out), "+Yz"(v) : [f] "S"(0x633910u) : "ecx","edx","xmm1","xmm2","xmm3","xmm4","xmm5","xmm6","xmm7","memory","cc");return out;}
#define CRT_FTOI wayFtoi

// 0x5d0310
static THISCALL void ZCamHelper_InitRecruitWayPoints(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  float dummy_out = 0.0f;
  bool show = vcall<bool>(sys, 0x5c, (const char *)0x6b4f88, &dummy_out);  // "ShowWayPoints"
  at<u32>(self, 0x48) = 0;
  u8 *world = ptr(SYS9B, 0xadc);  // manager +0xadc is the world object
  u8 *cur = ptr(world, 8);        // world +8: first geometry
  while (cur) {
    u8 *obj = (u8 *)at<u32>(cur, 0x54);
    const char *name = (const char *)0x67c8e8;  // "<NONAME>"
    if (at<u32>(obj, 4)) name = (const char *)at<u32>(obj, 4);
    if (ext_4cc850(name, (const char *)0x6b4f98) == 0) {  // "*waypoint*"
      float pos[3] = {0.0f, 0.0f, 0.0f};
      vcall<void>(obj, 0x84, pos);
      u32 n = at<u32>(self, 0x48);
      u32 *e = (u32 *)(self + 0x4c + n * 20);
      e[0] = 0;
      e[1] = fbits(pos[0]);
      e[2] = fbits(pos[1]);
      e[3] = fbits(pos[2]);
      e[4] = (u32)obj;
      at<u32>(self, 0x48) = n + 1;
      if (show) {
        long double r = vcall<long double>(sys, 0x1c0, (const char *)0x6b4e78, 0xaeeu);  // CamHelper.cpp:0xaee
        float rf = (float)r;
        float v = (rf * 0.5f + 0.5f) * G(float, 0x6b4fd4);
        u32 col = CRT_FTOI(v);
        float m[9];
        ext_4de7a0(m);
        float size[3] = {50.0f, 10.0f, 50.0f};
        vcall<void>(world, 0x238, m, pos, size, col, 1u);  // debug marker (matrix, pos, size, colour, filled)
      }
    }
    vcall<void>(world, 0x50, &cur);  // next geometry
  }
}
PCREG(5d0310, ZCamHelper_InitRecruitWayPoints);
