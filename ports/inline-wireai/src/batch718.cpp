// batch718.cpp - soldier AI, batch 718 (2026-10-11): CFFCoverList::CreateSpotsAroundBox, cover spots around a geom's
// box. The geom's base (g+8) gives the box half-size (GetSize, +0x40..+0x48), a tilt value at +0x10 and an offset at
// +0x30. Corners: (-sx, 30-sy, -sz), (sx, 30-sy, -sz), (sx, 30-sy, sz), (-sx, 30-sy, sz) at the geom's root point (the
// geom's slot 0x84 transforms each point in place). Height = sy + 50. Edges of the quad each get CreateSpotsAlong.
// Tilt above the limit (0.717 > tilt at base+0x10): warns "Cover %s is too tilted" and stops after the flag call.
#include "ff.h"

extern "C" void THISCALL ext_4db7c0(void *base, float *out);                                  // ZBaseGeom::GetSize
extern "C" void FASTCALL ext_441940(float *v, const float *b);                                // v += b
extern "C" s32 FASTCALL ext_4cc850(const char *name, const char *pattern);                     // striwcmp
extern "C" void THISCALL ext_4cbec0(void *mystr);                                             // MYSTR::~MYSTR
extern "C" const char *THISCALL ext_4cc1d0(void *mystr);                                      // MYSTR::c_str
extern "C" void THISCALL ext_585f90(void *self, float *a, float *b, u32 flag, float height, u32 type, void *parent);

struct MYSTR_buf { u8 b[0x80]; };
static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x5868e0 CFFCoverList::CreateSpotsAroundBox(ZGEOM* g, CCoverSpot::eType type, bool flag) [high].
static void THISCALL cover_CreateSpotsAroundBox(u8 *self, u8 *g, u32 type, u32 flag) {
  u8 *base = *(u8 **)(g + 8);
  float S[3];
  ext_4db7c0(base, S);
  if (0.717f > *(float *)(base + 0x10)) {       // 0x6abb94
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ab8a0, 0x106);
    MYSTR_buf nm;
    vcall<void *>(g, 0x1d8, &nm, 1);
    const char *s = ext_4cc1d0(&nm);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6ab900, s);   // "Cover %s is too tilted. Discarding."
    ext_4cbec0(&nm);
    if ((u8)flag)
      vcall<void>(g, 0x210, 1);
    return;
  }
  float sx = S[0], sy = S[1], sz = S[2];
  float ry = 30.0f - sy;                         // 0x67da24
  float P1[3] = {-sx, ry, -sz};
  float P2[3] = {sx, ry, -sz};
  float P3[3] = {sx, ry, sz};
  float P4[3] = {-sx, ry, sz};
  float *pts[4] = {P1, P2, P3, P4};
  for (int k = 0; k < 4; k++) {
    ext_441940(pts[k], (float *)(base + 0x30));   // point += offset
    vcall<void>(g, 0x84, pts[k]);                  // to the geom's root frame
  }
  float h = sy + 50.0f;                          // 0x680a84
  u32 notParent = 0;
  ((u8 *)&notParent)[0] = (type != 2);
  const char *nm = (*(u32 *)(g + 4)) ? (const char *)(*(u32 *)(g + 4)) : (const char *)0x67c8e8;   // "<NONAME>"
  void *parent = 0;
  if (ext_4cc850(nm, (const char *)0x6ab930) == 0) {   // "*_depend_on_parent"
    u32 ref = vcall<u32>(g, 0x20);
    parent = vcall<void *>(db(), 0x4c, ref);
  }
  if ((u8)flag)
    vcall<void>(g, 0x210, 1);
  ext_585f90(self, P1, P2, notParent, h, type, parent);
  ext_585f90(self, P2, P3, notParent, h, type, parent);
  ext_585f90(self, P3, P4, notParent, h, type, parent);
  ext_585f90(self, P4, P1, notParent, h, type, parent);
}
PCREG(5868e0, cover_CreateSpotsAroundBox);
