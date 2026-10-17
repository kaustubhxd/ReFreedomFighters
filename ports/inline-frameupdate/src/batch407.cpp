// batch407.cpp - per-frame update chain: ZPlayer::MovementControl (slot 0x61c, called every frame by
// ZPlayer::ClassFrameUpdate between GetCenterMatPos and CalcBonesFromMotion).
#include "ff.h"

extern "C" u8 *THISCALL ext_4dafb0(u8 *geom);                        // ZBaseGeom::GetDynamicParent [high]
extern "C" void THISCALL ext_4db6c0(u8 *geom, float *mat, float *pos);  // ZBaseGeom::GetRootTM [high]
extern "C" u8 THISCALL ext_4db9a0(u8 *geom, u32 cls);                  // ZBaseGeom::IsDerivedFrom [high]
extern "C" void FASTCALL ext_43e960(float *v, const float *b);         // (no name; vector op on v, run as exe code)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);         // vmtmul [high]
extern "C" void FASTCALL ext_4de4f0(float *mat, const float *m);       // (no name; vmtmul on the rows)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);         // vmmul (batch 48)
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);       // mmul in place (batch 48)
extern "C" void FASTCALL ext_441940(float *a, const float *b);         // PSVECAdd [medium]
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);     // mcpy [low]
extern "C" void FASTCALL ext_4de520(float *out, const float *a, const float *b, float t);  // mpul [high]
extern "C" void THISCALL ext_484b10(u8 *self, u8 *box, u8 *geom, const float *pos, const float *a, const float *b);
// ZPlayer::PositionCollisionBox [high]
extern "C" void THISCALL ext_4eb080(u8 *box, const float *mat, const float *pos, const float *c);  // (no name)
extern "C" void THISCALL ext_4ea300(u8 *box, u32 mask);           // ZCollisionBox::GetStrips [low]
extern "C" void THISCALL ext_4895c0(u8 *ctl, float t, float dt);  // (no name) movement controller time step
extern "C" void THISCALL ext_4ea8e0(u8 *box, float t, float dt);  // (no name) collision box time step
extern "C" u8 *THISCALL ext_4ea260(u8 *box, u8 *ignore);          // (no name) ground geom under the box

// Inline profiler marks (the same code as profiler begin/end, batch 48, written out in this function).
static inline void prof(u32 slot, u32 line, const char *tag) {
  u8 *sys = G(u8 *, 0x70039c);
  if (*(float *)(sys + 0x9c7) == 0.0f || *(float *)(sys + 0x9c3) == 0.0f)
    return;
  u64 st = vcall<u64>(sys, 0x1c8, (const char *)0x67a7f8u, line);  // sysinterface.h
  sys = G(u8 *, 0x70039c);
  vcall<void>(sys, slot, st, tag);
}

// ---------------------------------------------------------------- 0x484380 ZPlayer::MovementControl(4 x float*) [high]
// thiscall, ret 0x10: (mat, pos) in, (newMat, newPos) out. Picks the movement controller, moves the collision box
// over the frame in sub-steps of 2 / [0x70039c]+0x54 seconds, lets the controller move the player each sub-step and
// picks up the ground under the box at the end.
static void THISCALL playerMovementControl(u8 *self, float *mat, float *pos, float *newMat, float *newPos) {
  u8 *ctl;
  if (vcall<u8>(self, 0x324, 0u) && !(vcall<u8>(self, 0x320, 0u) & 0x20)) {
    ctl = vcall<u8 *>(self, 0x640, 1u);
  } else {
    u32 n = *(u32 *)(self + 0x459);
    if (n) {
      for (; n; n--) {  // controllers +0x45d[1..n], last first: the first one whose slot 0xc accepts the move
        u8 *c = *(u8 **)(self + 0x45d + 4 * n);
        if (c && vcall<u8>(c, 0xc, mat, pos, self + 0x445))
          break;
      }
      if (n) {
        u8 *cur = *(u8 **)(self + 0x455);
        if (*(u8 **)(self + 0x45d + 4 * n) != cur && vcall<u8>(cur, 0x8, 0u)) {
          vcall<void>(self, 0x644, n);
          vcall<void>(*(u8 **)(self + 0x455), 0x10);
        }
      }
    }
    ctl = *(u8 **)(self + 0x455);
  }
  u8 strips[0x10000];
  u8 *box = vcall<u8 *>(*(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c), 0x48, strips, 0x10000u);
  *(u8 **)(ctl + 8) = box;
  float step = 2.0f / *(float *)(G(u8 *, 0x70039c) + 0x54);  // 2.0 at [0x680a60]
  float dt = *(float *)(G(u8 *, 0x70039c) + 0x48);
  float t = 0.0f, tprev = 0.0f;
  void **rmvt = **(void ****)(G(u8 *, 0x70039c) + 0x9b);
  u32 h = vcall<u32>(self, 0x428);
  u8 *ground = ((u8 * (THISCALL *)(u8 *, u32)) rmvt[0x58 / 4])(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), h);
  if (ground) {
    u8 *dp = ext_4dafb0(*(u8 **)(ground + 8));
    if (dp) {  // standing on a moving parent: carry the start position and matrix along with it
      float pm[9], pp[3];
      ext_4db6c0(dp, pm, pp);
      ext_43e960(pos, (const float *)(self + 0x519));
      ext_441a60(pos, (const float *)(self + 0x4f5));
      ext_4de4f0(mat, (const float *)(self + 0x4f5));
      ext_4419f0(pos, pm);
      ext_4de480(mat, pm);
      ext_441940(pos, pp);
    }
  }
  float curMat[9], curPos[3];
  ext_4de420(curMat, mat);
  curPos[0] = pos[0];
  curPos[1] = pos[1];
  curPos[2] = pos[2];
  float lim = dt - step * 0.1f;  // [0x67a284]
  for (;;) {
    t = t + step;
    if (t > lim)
      t = dt;
    ext_484b10(self, box, 0, curPos, 0, 0);
    if (self[0x591]) {  // the box follows an animated offset: interpolate it to this sub-step
      float sdt = *(float *)(G(u8 *, 0x70039c) + 0x48);
      float f = (t - (dt - sdt)) / sdt;
      float m[9], p[3];
      ext_4de520(m, (const float *)(self + 0x525), (const float *)(self + 0x555), f);
      p[0] = (*(float *)(self + 0x579) - *(float *)(self + 0x549)) * f + *(float *)(self + 0x549);
      p[1] = (*(float *)(self + 0x57d) - *(float *)(self + 0x54d)) * f + *(float *)(self + 0x54d);
      p[2] = (*(float *)(self + 0x581) - *(float *)(self + 0x551)) * f + *(float *)(self + 0x551);
      ext_4eb080(box, m, p, (const float *)(self + 0x585));
    }
    prof(0x178, 0x259, (const char *)0x68c024u);  // "GetStrips"
    if (self[0x5ff])
      ext_4ea300(box, 0x20);
    prof(0x17c, 0x260, (const char *)0x68c024u);
    float d = t - tprev;
    ext_4895c0(ctl, t, d);
    ext_4ea8e0(box, t, d);
    prof(0x178, 0x259, (const char *)0x68c030u);  // "MovementMove"
    vcall<void>(ctl, 0x14, curMat, curPos, (const float *)newMat, (const float *)newPos, self + 0x445);
    prof(0x17c, 0x260, (const char *)0x68c030u);
    if (t == dt)
      break;
    ext_4de420(curMat, newMat);
    curPos[0] = newPos[0];
    curPos[1] = newPos[1];
    curPos[2] = newPos[2];
    tprev = t;
  }
  u8 *hit = ext_4ea260(box, ground ? *(u8 **)(ground + 8) : 0);
  if (hit) {
    u8 *gdp = ground ? ext_4dafb0(*(u8 **)(ground + 8)) : 0;
    u8 *hdp = ext_4dafb0(hit);
    if (!hdp || hdp == gdp || !ext_4db9a0(hdp, 0x100bbfu)) {
      void **vt = *(void ***)self;
      u32 hh = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, *(u32 *)(hit + 0x54));
      ((void(THISCALL *)(u8 *, u32))vt[0x424 / 4])(self, hh);
    }
  }
  ext_4ea8e0(box, 0.0f, 0.0f);
  ext_4895c0(ctl, 0.0f, 0.0f);
  vcall<void>(*(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c), 0x4c, box);
  vcall<void>(ctl, 0x18);
}
PCREG(484380, playerMovementControl);
