// batch838.cpp - area 50: ZLNKOBJ::UpdateAnimSound (0x464f50). Three sound slots (+0x12a, +0x12e, +0x132) hold sound ids.
// For each non-zero id, the sound manager (the engine object at [0x70039c]+0x9b) gives the sound object (vt +0x58 (id));
// the sound's position is the geometry's matrix/position (geom = sound+8) moved by this object's offset (+0x48 vector,
// multiplied by the matrix (+0x24)), then the sound's vt +0x7c(mat, pos) updates it.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4db2c0(void *geom, float *m, float *p);             // ZBaseGeom::GetMatPos(mat, pos) const
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);  // vmmul (out = v * m)
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);                  // mat = mat * m
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                // PSVECAdd (dst += src)

static void THISCALL UpdateAnimSound(u8 *self) {
  static const u32 slots[3] = {0x12a, 0x12e, 0x132};
  for (int k = 0; k < 3; k++) {
    u32 id = F32(self, slots[k]);
    if (!id) continue;
    void *snd = vcall<void *>(FP(G(void *, 0x70039c), 0x9b), 0x58, id);
    if (!snd) continue;
    // the geometry comes from the result of vt +0x20 (eax is not restored in the exe), so it is read from that result
    void *r20 = vcall<void *>(self, 0x20);
    float mat[9];
    float pos[3];
    ext_4db2c0(FP(r20, 8), mat, pos);
    float t[3];
    ext_441970(t, (const float *)(self + 0x48), mat);
    ext_4de480(mat, (const float *)(self + 0x24));
    ext_441940(pos, t);
    vcall<void>(snd, 0x7c, mat, pos);
  }
}
PCREG(464f50, UpdateAnimSound);
