// batch803.cpp - animation layer thread, batch 803: ZBoneModifyBase::GetBonesFrames (the layer stack + head look).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void ext_634d10(void *d, int v, u32 n);                                       // memset (cdecl)
extern "C" void THISCALL ext_646220(void *self, void *obj, void *ab);                    // GetBoneAnims (batch 802)
extern "C" void THISCALL ext_645c90(void *self, void *q, void *bb, void *file, void *ab); // DepackBone (batch 801)
extern "C" void FASTCALL ext_4de7a0(float *m);                                           // mreset
extern "C" void FASTCALL ext_4df1e0(float *m, const float *q);                           // quattomat
extern "C" void FASTCALL ext_4dfd10(float *d, const float *s);                           // tmat (transpose)
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);                         // mat = mat * m
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                           // vmmul
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                       // PSVECAdd
extern "C" void FASTCALL ext_4e0d40(float *d, const float *a, float s);                  // vscalar
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);           // PSVECSubtract d = a - b
extern "C" float FASTCALL ext_44c840(float *v);                                          // vnorm (old length in ST0)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                           // vmtmul
extern "C" float STDCALL ext_4dda90(float a, float b);                                   // GetAngle

// Layer list in ZBoneModifyBase (filled by AddFrame, batch 800): 4 entries of 20 bytes at +0x15, count +0x65:
//   +0 AnimHeader*, +4 ZDeltaBone* (per-bone extra offsets, 0x1c bytes per bone), +8 frame, +0xc blend-in time,
//   +0x10 flags: bit 0 = head-look slot (stop; head look is applied here, the rest after it), bit 2 = the next
//   entry is a second clip blended into this one (ZActiveBone +0xc/+0x10/+0x14).
// ZAnimFileBase vtable used: +0x24 CountAnimBones(hdr), +0x2c GetBoneAnim(hdr, i), +0x3c GetBoneId(boneAnim) (u8).
// boneMap maps a file bone id to the object's bone index (0 and 0xff = none).

static inline void *sub18() { return FP(FP(G(void *, 0x70039c), 0x1aa3), 0x18); }

// ZBoneModifyBase::GetBonesFrames(ZAnimFileBase* file, const u8* boneMap, ZBlendBone* bb, ZActiveBone* ab,
//                                 ZLNKOBJ* obj, ZBone* bones) [high, GC 80222920]. thiscall, ret 0x18.
static void THISCALL GetBonesFrames(u8 *self, void *file, const u8 *map, u8 *bb, u8 *ab, void *obj, float *bones) {
  if (F32(self, 0x291) != 0 || F8(self, 0x295) != 0) return;
  ext_634d10(ab, 0, F32(self, 0x11) * 0x1d);
  ext_646220(self, obj, ab);
  if (vcall<bool>(obj, 0x2fc)) {
    F32(self, 0x65) = 0;
    F32(self, 0x251) = 0;
    F32(self, 0x22d) = 0;
    return;
  }
  if (vcall<bool>(FP(G(void *, 0x70039c), 0x9b), 0xb8)) {
    F32(self, 0x22d) = F32(self, 0x23d);
    F32(self, 0x251) = F32(self, 0x24d);
  }
  // 1. Layers below the head-look slot. A bone already driven by a running bone anim (ZActiveBone +0x1c) keeps it.
  u8 *p = self + 0x15;
  u32 k = 0;
  if (F32(self, 0x65) != 0) {
    for (;;) {
      if (F8(p, 0x10) & 1) break;
      u32 nb = vcall<u32>(file, 0x24, FP(p, 0));
      for (u32 j = 0; j != nb; j++) {
        void *ba = vcall<void *>(file, 0x2c, FP(p, 0), j);
        u8 m = map[vcall<u8>(file, 0x3c, ba)];
        if (m == 0xff || m == 0) continue;
        u8 *a = ab + m * 0x1d;
        if (F8(a, 0x1c)) continue;
        F32(a, 0x18) = 0;
        if (FP(p, 4)) F32(a, 0x18) = F32(p, 4) + m * 0x1c;
        FP(a, 0) = ba;
        F32(a, 4) = F32(p, 8);
        F32(a, 8) = F32(p, 0xc);
        F32((u8 *)FP(obj, 0x1c) + m * 0x18, 0x10) = 0;
      }
      if (F8(p, 0x10) & 4) {
        p += 0x14;
        k++;
        nb = vcall<u32>(file, 0x24, FP(p, 0));
        for (u32 j = 0; j != nb; j++) {
          void *ba = vcall<void *>(file, 0x2c, FP(p, 0), j);
          u8 m = map[vcall<u8>(file, 0x3c, ba)];
          if (m == 0xff || m == 0) continue;
          u8 *a = ab + m * 0x1d;
          FP(a, 0xc) = ba;
          F32(a, 0x14) = F32(p, 8);
          F32(a, 0x10) = F32(p, 0xc);
        }
      }
      k++;
      p += 0x14;
      if (k == F32(self, 0x65)) break;
    }
  }
  // 2. Head look (weight +0x251 != 0 and obj->vt[0x498] gives the head-look clip). The clip is a grid: 64 frames
  // (+1) per full turn of yaw, rows of 65 frames by pitch band; or, when obj->vt[0x49c] is true, one row indexed by
  // pitch * 32/pi.
  float pitch = 0.0f;
  if (!(FF(self, 0x251) == 0.0f)) {
    void *hl = vcall<void *>(obj, 0x498);
    if (hl) {
      bool single = vcall<bool>(obj, 0x49c);
      u8 *r1 = vcall<u8 *>(sub18(), 0xc0, FP(FP(obj, 8), 0x6c));
      u8 *map2 = vcall<u8 *>(sub18(), 0xc8, FP(FP(obj, 8), 0x6c));
      u8 *r3 = vcall<u8 *>(sub18(), 0xb8, FP(FP(obj, 8), 0x6c));
      float ang, f = 1.0f;
      if (F8(hl, 0x7c) & 0x10) {
        // Aim from the head bone (bone 1): its pose (or r3's rotation in single mode) through r1's matrix and the
        // root bone, a point 55 units along the bone, then the direction to the target at +0x259 in bone space.
        float q[12];
        ext_645c90(self, q, bb + 0x24, file, ab + 0x1d);
        float P[3] = {q[9], q[10], q[11]};
        if (single) {
          ext_4de7a0(bones);
          bones[11] = 0.0f;
          bones[10] = 0.0f;
          bones[9] = 0.0f;
          q[0] = FF(r3, 0x1c);
          q[1] = FF(r3, 0x20);
          q[2] = FF(r3, 0x24);
          q[3] = FF(r3, 0x28);
        }
        float M1[9], M2[9], V[3];
        ext_4df1e0(M1, q);
        ext_4dfd10(M2, M1);
        ext_4de480(M2, (float *)(r1 + 0x24));
        ext_4dfd10(M1, M2);
        ext_4de480(M1, bones);
        ext_4419f0(P, bones);
        ext_441940(P, bones + 9);
        ext_4e0d40(V, M1, 55.0f);
        ext_441940(P, V);
        ext_43e920(V, (float *)(self + 0x259), P);
        ext_44c840(V);
        ext_441a60(V, M1);
        ang = ext_4dda90(-V[0], V[1]);
        float z = V[2];
        if (!(z > 1.0f)) {
          if (-1.0f > z) pitch = bitsf(0x40490fdb);
          else pitch = (float)crt::acos((double)z);
        }
      } else {
        float V[3];
        V[0] = -FF(self, 0x261);
        V[1] = -FF(self, 0x259);
        V[2] = FF(self, 0x25d) - G(float, 0x6c2ac0);   // 113.0
        ext_44c840(V);
        ang = ext_4dda90(-V[0], V[1]);
        float z = V[2];
        if (z > 1.0f) pitch = 0.0f;
        else if (-1.0f > z) pitch = bitsf(0x40490fdb);
        else pitch = (float)crt::acos((double)z);
      }
      float A = ang / G(float, 0x68aef8) * G(float, 0x681dcc);   // / 2pi * 64
      float B = A;
      u32 nb = vcall<u32>(file, 0x24, hl);
      float wt = FF(self, 0x255);
      if (F8(self, 0x265)) wt = G(float, 0x67c198);   // 0.3
      u8 *delta = vcall<u8 *>(obj, 0x288, hl);
      if (single) {
        pitch = pitch * G(float, 0x6c2ab8);   // 32/pi
        for (u32 j = 0; j != nb; j++) {
          void *ba = vcall<void *>(file, 0x2c, hl, j);
          u8 m = map2[vcall<u8>(file, 0x3c, ba)];
          if (m == 0xff || m == 0) continue;
          u8 *a = ab + m * 0x1d;
          if (!F8(self, 0x265)) {
            FP(a, 0x18) = delta ? delta + m * 0x1c : 0;
            FP(a, 0) = ba;
            FF(a, 4) = pitch;
            F32(a, 0xc) = 0;
          }
          FF(a, 8) = wt;
        }
      } else {
        // Pitch bands (radians): 15, 45, 90, 135, 165 degrees. A = frame of the second clip, B = frame of the first,
        // f = weight of the second.
        const float c1 = G(float, 0x683770), c2 = G(float, 0x69f1a0), c3 = G(float, 0x6c2ab4),
                    c4 = G(float, 0x6c2ab0), c5 = G(float, 0x69f9d4), c6 = G(float, 0x6a0bc8);
        float x;
        if (pitch > c3) {
          x = c3;
          goto band3;
        }
        x = c5 > pitch ? c5 : pitch;
        if (x >= c1 && c4 >= x) {
          B = A + G(float, 0x6a60a8);           // 65
          f = 1.0f - (x - c1) / c2;
        } else if (x >= c2 && c1 >= x) {
          B = A + G(float, 0x6ad214);           // 130
          f = (x - c2) / c2;
        } else if (x >= c4 && c3 >= x) {
        band3:
          A = A + G(float, 0x6a60a8);           // 65
          f = 1.0f - (x - c4) / c6;
          B = B + G(float, 0x6c2ac8);           // 260
        } else if (x >= c5 && c2 >= x) {
          A = A + G(float, 0x6ad214);           // 130
          B = B + G(float, 0x6c2ac4);           // 195
          f = (x - c5) / c6;
        }
        for (u32 j = 0; j != nb; j++) {
          void *ba = vcall<void *>(file, 0x2c, hl, j);
          u8 m = map2[vcall<u8>(file, 0x3c, ba)];
          if (m == 0xff || m == 0) continue;
          u8 *a = ab + m * 0x1d;
          if (!F8(self, 0x265)) {
            FP(a, 0x18) = delta ? delta + m * 0x1c : 0;
            FF(a, 4) = B;
            FF(a, 0x14) = A;
            FP(a, 0) = ba;
            FP(a, 0xc) = ba;
            FF(a, 0x10) = f;
          }
          FF(a, 8) = wt;
        }
      }
    }
  }
  // 3. Layers above the head-look slot override everything below (no running-bone-anim check).
  if (k == F32(self, 0x65)) return;
  do {
    u32 nb = vcall<u32>(file, 0x24, FP(p, 0));
    for (u32 j = 0; j != nb; j++) {
      void *ba = vcall<void *>(file, 0x2c, FP(p, 0), j);
      u8 m = map[vcall<u8>(file, 0x3c, ba)];
      if (m == 0xff || m == 0) continue;
      u8 *a = ab + m * 0x1d;
      F32(a, 0x18) = 0;
      if (FP(p, 4)) F32(a, 0x18) = F32(p, 4) + m * 0x1c;
      FP(a, 0) = ba;
      F32(a, 0xc) = 0;
      F32(a, 4) = F32(p, 8);
      F32(a, 8) = F32(p, 0xc);
    }
    k++;
    p += 0x14;
  } while (k != F32(self, 0x65));
}
PCREG(646430, GetBonesFrames);
