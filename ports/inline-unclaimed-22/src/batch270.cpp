// batch270.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch270"):
// ZActorIf::MoveToSceneLocationWithForceToGroundLevel, the script call that teleports an actor to a scene location and drops
// it onto the floor below. Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u8 *params, u32 i);                        // OpaqueCallParameters entry (unclaimed-64)
extern "C" void THISCALL ext_5094c0(u8 *self, u8 *geom, float *m, float *p);    // random spot in a location (unclaimed-35)
extern "C" u8 *THISCALL ext_4e1b60(u8 *coli);                                   // COLI::COLI (inline-batch45)
extern "C" void THISCALL ext_4e09b0(float *v);                                  // negate a vector (inline-batch45)

typedef void(__attribute__((cdecl)) * logs_t)(void *, const char *, const char *);
typedef void(THISCALL *setf_t)(u8 *, float);

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))

// 0x507810 ZActorIf::MoveToSceneLocationWithForceToGroundLevel(OpaqueCallParameters_t &) ret 4. The first parameter is a
// geom id; none logs "%s..." (actorif.cpp line 0x1e6, log slot 0x2c, actor name from +0x18 vt 0x20). The location's matrix
// and position (vt 0x80); a location of kind 0x2000e1 (vt 0x1e0) picks a random spot in it (0x5094c0). A COLI line from
// the spot straight down (0, -10000, 0) through the rooms object (db+0xadc vt 0x2e0(coli, 0, 5, -1, 1, 0)) gives the floor
// point (coli +0x28). The actor (+0x18) gets vt 0x624(1.0), the matrix's first row is negated, and vt 0x634(point, matrix).
void THISCALL moveToSceneLocationGround_507810(u8 *self, u8 *params) {
  u32 *e = ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *g = (u8 *)vcall<u32>(DB, 0x58, *e);
  if (!g) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x69cff0u, 0x1e6u);
    u8 *n = (u8 *)vcall<u32>(*(u8 **)(self + 0x18), 0x20);
    (*(logs_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x69d0c8u, *(const char **)(n + 4));
    return;
  }
  float m[9], p[3];
  vcall<void>(g, 0x80, (u32)m, (u32)p);
  if ((u8)vcall<u32>(g, 0x1e0, 0x2000e1u)) ext_5094c0(self, g, m, p);
  u8 coli[0x70];
  ext_4e1b60(coli);
  ((float *)coli)[0] = p[0];
  ((float *)coli)[1] = p[1];
  ((float *)coli)[2] = p[2];
  *(u32 *)(coli + 0xc) = 0;
  *(u32 *)(coli + 0x10) = 0xc61c4000u;  // -10000.0f
  *(u32 *)(coli + 0x14) = 0;
  vcall<void>(*(u8 **)(DB + 0xadc), 0x2e0, (u32)coli, 0u, 5u, 0xffffffffu, 1u, 0u);
  p[0] = *(float *)(coli + 0x28);
  p[1] = *(float *)(coli + 0x2c);
  p[2] = *(float *)(coli + 0x30);
  u8 *a = *(u8 **)(self + 0x18);
  (*(setf_t *)(*(u8 **)a + 0x624))(a, 1.0f);
  ext_4e09b0(m);
  vcall<void>(*(u8 **)(self + 0x18), 0x634, (u32)p, (u32)m);
}
PCREG(507810, moveToSceneLocationGround_507810);
#undef DB
#undef RM
