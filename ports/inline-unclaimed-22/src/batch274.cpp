// batch274.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch274"): ZPlayer::ClassCommand,
// the player's message handler (pick up / drop items, the move-object (push and carry) messages, aim toggles).
// Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" u32 THISCALL ext_472ae0(u8 *self, u32 cmd, u8 *data);                   // ZLNKWHANDS::ClassCommand (hooked)
extern "C" void THISCALL ext_484b10(u8 *self, u8 *box, u32 g, float *pos, u32 a, u32 b); // PositionCollisionBox (unclaimed-41; hooked)
extern "C" void THISCALL ext_4eb080(u8 *box, const float *m, const float *p, const float *ext); // box setup (GUESS: hooked)
extern "C" u32 THISCALL ext_4eaea0(u8 *box, float *pt, float *out);                // box point test (unclaimed-63; hooked)
extern "C" float THISCALL ext_481990(u8 *self, float *pos, float *mat, u8 *g, const float *m0, const float *p0,
                                     const float *m1, const float *p1, const float *refMat, const float *refPos); // batch273
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);    // PSVECSubtract (inline-batch45)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                      // vmtmul (unclaimed-24)
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);    // vmmul (unclaimed-24)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                      // PSVECAdd (inline-batch45)
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);               // vdist (inline-batch45)
extern "C" void FASTCALL ext_4de420(float *out, const float *m);                    // mcpy (inline-batch45)

typedef void(__attribute__((cdecl)) * log0_t)(void *, const char *);

static double sqrtExe(double d) {
  double out;
  asm volatile("movsd %[d], %%xmm0\n\t"
               "call *%[t]\n\t"
               "movsd %%xmm0, %[o]\n\t"
               : [o] "=m"(out)
               : [d] "m"(d), [t] "r"(0x634d7c)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return out;
}

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))
#define COLI (*(u8 **)(*(u8 **)(RM + 0x1aa3) + 0x1c))
#define W(o) (*(u16 *)(self + (o)))

// The move-object message (word +0x628). data: +0 done byte, +1 object geom, +5 mode, +9 extent, +0x15 m0, +0x39 p0,
// +0x45 m1, +0x69 p1, +0x75 reached fraction. Mode <= 1: sweep the object (CheckMoveObjectTorso) from (m0, p0) to
// (m1, p1) against the torso pose (vt 0x5a0) and write the reached pose back. Mode > 1 (pushing): unless the object is the
// one already held (vt 0x428), a collision box is placed at the torso and the object's box tested; along the push axis
// (largest component of p1 - p0 in the object's frame, when the move is longer than 1/8192 and +0x5ff is set) the box is
// moved in and retested and a free box hands the object over (vt 0x618); then a hero who moved more than 50 drops it
// (vt 0x424), else the move is stored in +0x525.. and +0x591 set ("ERROR: MoveModify must be updated before zplayer"
// when the frame counter is ahead).
static void moveObject(u8 *self, u8 *data) {
  if (*(u32 *)(self + 0x417) & 0x40000) return;
  float tm[9], tp[3], tx[3];
  vcall<void>(self, 0x5a0, (u32)tm, (u32)tp, (u32)tx);
  if (*(float *)(data + 5) > *(float *)0x678858u) {
    u8 *held = (u8 *)vcall<u32>(DB, 0x58, vcall<u32>(self, 0x428));
    if (held == *(u8 **)(data + 1)) return;
    u8 *box = (u8 *)vcall<u32>(COLI, 0x48, 0u, 0u);
    ext_484b10(self, box, 0, tp, 0, 0);
    ext_4eb080(box, (float *)(data + 0x45), (float *)(data + 0x69), (float *)(data + 9));
    float saved[3] = {tp[0], tp[1], tp[2]};
    if (!(u8)ext_4eaea0(box, tp, tx)) goto done;
    {
      float d[3];
      ext_43e920(d, (float *)(data + 0x69), (float *)(data + 0x39));
      if (self[0x5ff]) {
        float len = (float)sqrtExe((double)((d[0] * d[0] + d[1] * d[1]) + d[2] * d[2]));
        if (len > *(float *)0x679540u) {
          ext_441a60(d, (float *)(data + 0x15));
          u32 i = d[1] > d[0] ? 1 : 0;
          float z[3] = {0, 0, 0};
          if (d[2] > d[i]) i = 2;
          float v[3];
          v[0] = *(float *)(data + 9);
          v[1] = *(float *)(data + 0xd);
          v[2] = *(float *)(data + 0x11);
          if (d[i] > 0.0f) z[i] = z[i] + v[i];
          else z[i] = z[i] - v[i];
          v[i] = 20.0f;
          float om[9], op[3];
          vcall<void>(*(u8 **)(data + 1), 0x80, (u32)om, (u32)op);
          ext_441970(d, z, om);
          ext_441940(op, d);
          ext_4eb080(box, om, op, v);
          op[0] = saved[0];
          op[1] = saved[1];
          op[2] = saved[2];
          if ((u8)ext_4eaea0(box, op, v)) goto done;
          vcall<void>(self, 0x618, (u32)data);
        }
      }
      float dist = ext_4e0870(saved, tp);
      if (dist > *(float *)0x680a84u) {
        vcall<void>(self, 0x424, vcall<u32>(DB, 0x4c, *(u32 *)(data + 1)));
        goto done;
      }
      if (*(int *)(RM + 0x40) > (int)(*(float *)(self + 0x592) * *(float *)0x678620u)) {
        void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x68bcbcu, 0x3a1u);
        (*(log0_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x68bf44u);
      }
      ext_4de420((float *)(self + 0x525), (float *)(data + 0x15));
      *(u32 *)(self + 0x549) = *(u32 *)(data + 0x39);
      *(u32 *)(self + 0x54d) = *(u32 *)(data + 0x3d);
      *(u32 *)(self + 0x551) = *(u32 *)(data + 0x41);
      ext_4de420((float *)(self + 0x555), (float *)(data + 0x45));
      *(u32 *)(self + 0x579) = *(u32 *)(data + 0x69);
      *(u32 *)(self + 0x57d) = *(u32 *)(data + 0x6d);
      *(u32 *)(self + 0x581) = *(u32 *)(data + 0x71);
      *(u32 *)(self + 0x585) = *(u32 *)(data + 9);
      *(u32 *)(self + 0x589) = *(u32 *)(data + 0xd);
      *(u32 *)(self + 0x58d) = *(u32 *)(data + 0x11);
      self[0x591] = 1;
    }
  done:
    vcall<void>(COLI, 0x4c, (u32)box);
    return;
  }
  float pos[3], mat[9];
  float r = ext_481990(self, pos, mat, *(u8 **)(data + 1), (float *)(data + 0x15), (float *)(data + 0x39),
                       (float *)(data + 0x45), (float *)(data + 0x69), tm, tp);
  *(float *)(data + 0x75) = r;
  *(float *)(data + 0x69) = pos[0];
  *(float *)(data + 0x6d) = pos[1];
  *(float *)(data + 0x71) = pos[2];
  ext_4de420((float *)(data + 0x45), mat);
  data[0] = 1;
}

// 0x481e10 ZPlayer::ClassCommand(unsigned short cmd, void *data) ret 8, returns 0. Nothing unless byte +0x412 is set.
// Five global messages (0x6ff9a4, 0x6ff9a8, 0x6ff9ac, 0x6ff9bc, 0x6ff9a0) release the held object (vt 0x594(0)); +0x61e
// holds (vt 0x594) and +0x620 (vt 0x598) the geom whose id is data; +0x628 is the move-object message above (no base call);
// +0x622 releases and hides the item +0x413 (vt 0x594(0), item vt 0x20()->vt 0x210(1)); +0x624 calls vt 0x36c, +0x626
// vt 0x368. Every case but the move-object one ends in ZLNKWHANDS::ClassCommand (0x472ae0).
u32 THISCALL zplayerClassCommand_481e10(u8 *self, u32 cmd, u8 *data) {
  if (!self[0x412]) return 0;
  u16 c = (u16)cmd;
  if (c == *(u16 *)0x6ff9a4u || c == *(u16 *)0x6ff9a8u || c == *(u16 *)0x6ff9acu || c == *(u16 *)0x6ff9bcu ||
      c == *(u16 *)0x6ff9a0u) {
    vcall<void>(self, 0x594, 0u);
  } else if (c == W(0x61e)) {
    vcall<void>(self, 0x594, vcall<u32>(DB, 0x58, (u32)data));
  } else if (c == W(0x620)) {
    vcall<void>(self, 0x598, vcall<u32>(DB, 0x58, (u32)data));
  } else if (c == W(0x628)) {
    moveObject(self, data);
    return 0;
  } else if (c == W(0x622)) {
    u8 *it = (u8 *)vcall<u32>(DB, 0x58, *(u32 *)(self + 0x413));
    vcall<void>(self, 0x594, 0u);
    if (it) {
      u8 *g = (u8 *)vcall<u32>(it, 0x20);
      if (g) vcall<void>(g, 0x210, 1u);
    }
  } else if (c == W(0x624)) {
    vcall<void>(self, 0x36c);
  } else if (c == W(0x626)) {
    vcall<void>(self, 0x368);
  }
  ext_472ae0(self, cmd, data);
  return 0;
}
PCREG(481e10, zplayerClassCommand_481e10);
#undef W
#undef COLI
#undef DB
#undef RM
