// batch268.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch268"): ZFFItemBomb::FrameUpdate,
// the planted bomb's per-frame tick (bobbing, colour pulse, OSD countdown, beep each second, explosion after 10 s).
// Name from the GameCube name map (high, ZFFItemBomb vtable slot 15); behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_5ea840(u8 *osd, float t);  // ZGameOSD::SetBombTime (inline-unclaimed-57 b5712)
extern "C" u8 *THISCALL ext_4db3b0(u8 *geom);           // ZBaseGeom::GetOwnerRoom (audit/inline-frameupdate)

// CRT sin/cos thunk 0x634d70 (SSE2 convention: double in xmm0, double out in xmm0).
static double crt634d70(double d) {
  double out;
  asm volatile("movsd %[d], %%xmm0\n\t"
               "call *%[t]\n\t"
               "movsd %%xmm0, %[o]\n\t"
               : [o] "=m"(out)
               : [d] "m"(d), [t] "r"(0x634d70)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return out;
}

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))

// Sends the bomb's script message (word at +off) with {name of the bomb geom +0x44, its handle} to geom id +0x56.
static void notifyTarget(u8 *self, u32 off) {
  u8 *g = (u8 *)vcall<u32>(DB, 0x58, *(u32 *)(self + 0x56));
  u8 *n = (u8 *)vcall<u32>(*(u8 **)(self + 0x44), 0x20);
  u32 msg[2];
  u32 nm = *(u32 *)(n + 4);
  msg[0] = nm ? nm : 0x67c8e8u;  // "<NONAME>"
  msg[1] = vcall<u32>(DB, 0x4c, *(u32 *)(self + 0x44));
  vcall<void>(g, 0x128, (u32) * (u16 *)(self + off), (u32)msg, 0u);
}

// 0x5d42d0 ZFFItemBomb::FrameUpdate() (thiscall, no args). t = +0x5b += frame ms (rm+0x40 - rm+0x44) / 1024. With a
// display geom (+0x48): the item geom (+0x44) is moved up by sin/cos(t) + 100 (vt 0x80 get, +0x48 vt 0x7c set) and the
// display colour pulses ((f(8t) + 1) * 0.5 * 255, red byte, vt 0x234). The OSD (+0x5f) shows 10 - t; each whole second
// plays sound +0x67 (rm+0x1a9f vt 0x120(id, 4)). Past 10 s: damage list "rFF_C4_BombDmgList" is looked up and sent with
// message +0x4e; an explosion effect (+0x63) is spawned in the owner room at the bomb's matrix and started (message
// +0x52); the display is hidden, the target (+0x56) gets message +0x50, the bomb removes itself (vt 0x68(0x10, 0)) and the
// item geom is hidden. Before that, a pending "armed" flag (+0x5a) sends message +0x54 to the target once.
void THISCALL bombFrameUpdate_5d42d0(u8 *self) {
  float dt = (float)(int)(*(int *)(RM + 0x40) - *(int *)(RM + 0x44)) * *(float *)0x6785e4u;
  *(float *)(self + 0x5b) = *(float *)(self + 0x5b) + dt;
  if (*(u32 *)(self + 0x48)) {
    float m[9], p[3];
    vcall<void>(*(u8 **)(self + 0x44), 0x80, (u32)m, (u32)p);
    float s = (float)crt634d70((double)*(float *)(self + 0x5b));
    p[1] = (s + *(float *)0x67cd40u) + p[1];
    vcall<void>(*(u8 **)(self + 0x48), 0x7c, (u32)m, (u32)p);
  }
  u8 *disp = *(u8 **)(self + 0x48);
  if (disp) {
    double v = crt634d70((double)(*(float *)(self + 0x5b) * *(float *)0x680a6cu));
    int c = (int)(((v + *(double *)0x678610u) * *(double *)0x68c740u) * *(double *)0x6b52e0u);
    vcall<void>(disp, 0x234, (u32)(u8)c << 16);
  }
  ext_5ea840(*(u8 **)(self + 0x5f), *(float *)0x680a70u - *(float *)(self + 0x5b));
  float t = *(float *)(self + 0x5b);
  if ((int)t != (int)(t - dt)) {
    u8 *snd = *(u8 **)(RM + 0x1a9f);
    if (snd && *(u32 *)(self + 0x67)) vcall<void>(snd, 0x120, *(u32 *)(self + 0x67), 4u);
  }
  if (*(float *)(self + 0x5b) > *(float *)0x680a70u) {
    u8 *scene = (u8 *)vcall<u32>(DB, 0x138);
    u32 h = 0;
    vcall<void>(scene, 0x88, 0x6b52ccu, (u32)&h);  // "rFF_C4_BombDmgList"
    u32 dmg = vcall<u32>(*(u8 **)0x70038cu, 0xcc, h);
    u32 data[2] = {0, dmg};
    vcall<void>(*(u8 **)(self + 0x44), 0x128, (u32) * (u16 *)(self + 0x4e), (u32)data, 0u);
    if (*(u32 *)(self + 0x63)) {
      u8 *room = ext_4db3b0(*(u8 **)(*(u8 **)(self + 0x44) + 8));
      float m[9], p[3];
      vcall<void>(*(u8 **)(self + 0x44), 0x80, (u32)m, (u32)p);
      vcall<void>(room, 0x94, (u32)m, (u32)p);
      u8 *fx = (u8 *)vcall<u32>(*(u8 **)(self + 0x63), 0x1bc, (u32)room, (u32)m, (u32)p, 0u, 0u, 0u, 0u);
      *(u8 **)(self + 0x63) = fx;
      vcall<void>(fx, 0x2c);
      vcall<void>(*(u8 **)(self + 0x63), 0x138, (u32) * (u16 *)(self + 0x52), dmg, 0u);
      vcall<void>(*(u8 **)(self + 0x48), 0x28);
    }
    if (*(u32 *)(self + 0x56)) {
      if (*(u8 **)(self + 0x48)) vcall<void>(*(u8 **)(self + 0x48), 0x210, 1u);
      *(u32 *)(self + 0x48) = 0;
      notifyTarget(self, 0x50);
    }
    vcall<void>(self, 0x68, 0x10u, 0u);
    if (*(u8 **)(self + 0x44)) vcall<void>(*(u8 **)(self + 0x44), 0x210, 1u);
    return;
  }
  if (self[0x5a] && *(u32 *)(self + 0x56)) {
    self[0x5a] = 0;
    notifyTarget(self, 0x54);
  }
}
PCREG(5d42d0, bombFrameUpdate_5d42d0);
#undef DB
#undef RM
