// batch283.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch283"): CMAINCAMERACONTROL::
// FreeCam, the debug free camera toggle and fly step (keyboard and mouse steering, then a ground probe that draws a line
// to the floor below the camera). Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_4fca70(u8 *geom);                                  // KeyControlGeom1 (GUESS: hooked)
extern "C" void FASTCALL ext_4fd2a0(float *v, float *a, float *b, float sx, float sy); // MouseConVect1 (GUESS: hooked)
extern "C" void FASTCALL ext_4de040(float *m, const float *a, const float *b);  // createmat (inline-batch45)
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);           // vdist2 (inline-batch45)
extern "C" void THISCALL ext_4e1b60(u8 *coli);                                  // COLI::COLI (inline-batch45)
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b); // dst = a + b (inline-batch45)

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))
#define G(a) (*(float *)(a##u))

// 0x4fc190 CMAINCAMERACONTROL::FreeCam() (thiscall, returns bool). A pending toggle (byte +0x69) or the free-cam key
// (input manager rm+0x1907 vt 0x38(0x69c360, 0)) flips +0x68: turning on
// sends ZGEOM command word +0x64 to the attached object db vt 0x58(+0x74) (vt 0x128(cmd, 0, 0)), saves +0x6a in
// 0x700e64, clears +0x74, calls this->vt 0x84(1, 0) and stores the camera position rm+0x9e7 in 0x700e40; turning off
// calls this->vt 0x84([0x700e64], 0). While on: KeyControlGeom1 on the camera geom +0x44; when the camera moved more than
// 0x679540 since the stored position the mouse turns the view (MouseConVect1 with 0.004, createmat) and the geom gets
// the new matrix (vt 0x7c); the position is stored again; when rm vt 0xe8(0x20) a COLI probe from the geom position
// 200 down (collision db+0xadc vt 0x2e0(coli, 0, 5, -1, 1, 0)) draws a line (vt 0x218(coli, hit or end, 0xff)); true.
// Stack cookie not reproduced.
u8 THISCALL freeCam_4fc190(u8 *self) {
  bool toggle = self[0x69] != 0;
  if (!toggle) toggle = (u8)vcall<u32>(*(u8 **)(RM + 0x1907), 0x38, 0x69c360u, 0u) != 0;
  if (toggle) {
    self[0x69] = 0;
    u8 on = self[0x68] == 0;
    self[0x68] = on;
    if (on) {
      u8 *o = (u8 *)vcall<u32>(DB, 0x58, *(u32 *)(self + 0x74));
      if (o) vcall<void>(o, 0x128, (u32) * (u16 *)(self + 0x64), 0u, 0u);
      *(u32 *)0x700e64u = *(u32 *)(self + 0x6a);
      *(u32 *)(self + 0x74) = 0;
      vcall<void>(self, 0x84, 1u, 0u);
      u8 *rm = RM;
      G(0x700e40) = *(float *)(rm + 0x9e7);
      G(0x700e44) = *(float *)(rm + 0x9eb);
      G(0x700e48) = *(float *)(rm + 0x9ef);
    } else {
      vcall<void>(self, 0x84, *(u32 *)0x700e64u, 0u);
    }
  }
  if (!self[0x68]) return 0;   // off: false
  ext_4fca70(*(u8 **)(self + 0x44));
  float m[12], p[3];
  vcall<void>(*(u8 **)(self + 0x44), 0x80, (u32)m, (u32)p);
  float d = ext_4e0830((const float *)0x700e40u, (const float *)(RM + 0x9e7));
  if (d > *(float *)0x679540u) {
    float v[3] = {m[0], m[1], m[2]};
    ext_4fd2a0(v, (float *)0x700e40u, (float *)(RM + 0x9e7), 0.004f, 0.004f);
    ext_4de040(m, v, 0);
    vcall<void>(*(u8 **)(self + 0x44), 0x7c, (u32)m, (u32)p);
  }
  u8 *rm = RM;
  G(0x700e40) = *(float *)(rm + 0x9e7);
  G(0x700e44) = *(float *)(rm + 0x9eb);
  G(0x700e48) = *(float *)(rm + 0x9ef);
  if ((u8)vcall<u32>(rm, 0xe8, 0x20u)) {
    float coli[0x94 / 4];
    ext_4e1b60((u8 *)coli);
    coli[0] = p[0];
    coli[1] = p[1];
    coli[2] = p[2];
    *(u32 *)&coli[3] = 0;
    *(u32 *)&coli[4] = 0xc3480000u;
    *(u32 *)&coli[5] = 0;
    float t[3];
    const float *hit;
    if ((u8)vcall<u32>(*(u8 **)(DB + 0xadc), 0x2e0, (u32)coli, 0u, 5u, 0xffffffffu, 1u, 0u)) {
      hit = coli + 10;
    } else {
      ext_43e8e0(t, coli, coli + 3);
      hit = t;
    }
    vcall<void>(*(u8 **)(DB + 0xadc), 0x218, (u32)coli, (u32)hit, 0xffu);
  }
  return 1;
}
PCREG(4fc190, freeCam_4fc190);
#undef G
#undef DB
#undef RM
