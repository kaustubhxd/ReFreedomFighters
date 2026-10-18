// batch810.cpp - animation layer thread, batch 810: starting clips on a ZLNKOBJ.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void FASTCALL ext_4de7a0(float *m);                     // mreset
extern "C" void FASTCALL ext_4df1e0(float *m, const float *q);     // quattomat

// ZLNKOBJ::StartMatBoneMotion(AnimHeader*, int animId, int bone, ZBoneAnim* ba) [high, GC 80181f84]. thiscall
// ret 0x10, bool. The AnimHeader argument is not used in the PC build. A bone whose running ZBoneAnim has flag 0x800
// refuses a new one with flag 0x400 (priority). Otherwise the old motion is ended (vt 0x340), and the bone table
// entry gets: extra = ba's delta bones (+0x10) + bone * 0x1c (or 0), flag bit 0, ZBoneAnim, anim id. For the root
// bone (0) the object's root transform (+0x82 matrix, +0xa6 position) is set from the clip at time ba+4 (identity
// and zero when the time is 0). vt[0x2cc]() is called first and its result ignored.
static bool THISCALL StartMatBoneMotion(u8 *self, void *, u32 animId, s32 bone, u8 *ba) {
  vcall<void *>(self, 0x2cc);
  u8 *tab = (u8 *)FP(self, 0x1c);
  u8 *b = tab + bone * 0x18;
  if ((F8(b, 4) & 3) && (F32(ba, 0x14) & 0x400) && (F32(FP(b, 0x14), 0x14) & 0x800)) return false;
  vcall<void>(self, 0x340, bone, 0);
  u8 *d = (u8 *)FP(ba, 0x10);
  FP(b, 0xc) = d ? d + bone * 0x1c : 0;
  F32(b, 4) |= 1;
  FP(b, 0x14) = ba;
  F32(b, 0x10) = animId;
  if (bone == 0) {
    float t = FF(ba, 4);
    if (t == 0.0f) {
      ext_4de7a0((float *)(self + 0x82));
      F32(self, 0xa6) = 0;
      F32(self, 0xaa) = 0;
      F32(self, 0xae) = 0;
    } else {
      float q[4];
      vcall<void>(FP(self, 0x5c), 0xc, animId, 1, (float *)(self + 0xa6), q, t);
      ext_4df1e0((float *)(self + 0x82), q);
    }
  }
  return true;
}
PCREG(464bd0, StartMatBoneMotion);

// ZLNKOBJ::ActivateAnimSegment(AnimHeader* hdr, int flags, float a, float b, float c) [high, GC 80184a4c].
// Makes the ZBoneAnim pool on first use (+0x18: LINKREFTAB(8, 0x1e) in a 0x28-byte block), takes a ZBoneAnim from
// it (vt 4), ZBoneAnim::Create(this, hdr), segment +0x30 = a, +0x34 = b, clip +0x70, +0x28 = c, +0x2c = 0, delta
// bones +0x10 = vt[0x288](hdr). Flag bit 0: vt[0x34c](ba, flags) must accept it, else it goes back to the pool
// (vt 0x20, block = ba - 4) and 0 is returned; without bit 0, +0x44 = 0xfffffffe. If the anim file chains a
// follow-up clip to hdr (file vt 0x20), that one is started too: vt[0x228](next, flags, a, b, 1.0). Returns ba.
// The exe's SEH frame (for the new/constructor pair) has no effect here and is not reproduced.
extern "C" void *ext_41e290(u32 size);                                 // operator new (cdecl)
extern "C" void *THISCALL ext_4cca60(void *p, u32 a, u32 b);           // LINKREFTAB::LINKREFTAB
extern "C" void THISCALL ext_462460(void *ba, void *obj, void *hdr);   // ZBoneAnim::Create
static void *THISCALL ActivateAnimSegment(u8 *self, void *hdr, u32 flags, float a, float b, float c) {
  if (!hdr) return 0;
  if (!FP(self, 0x18)) {
    void *p = ext_41e290(0x28);
    FP(self, 0x18) = p ? ext_4cca60(p, 8, 0x1e) : 0;
  }
  u8 *ba = vcall<u8 *>(FP(self, 0x18), 4, flags);
  ext_462460(ba, self, hdr);
  FF(ba, 0x30) = a;
  FF(ba, 0x34) = b;
  FP(ba, 0x70) = hdr;
  FF(ba, 0x28) = c;
  F32(ba, 0x2c) = 0;
  FP(ba, 0x10) = vcall<void *>(self, 0x288, hdr);
  if (flags & 1) {
    if (!vcall<bool>(self, 0x34c, ba, flags)) {
      vcall<void>(FP(self, 0x18), 0x20, ba - 4);
      return 0;
    }
  } else {
    F32(ba, 0x44) = 0xfffffffe;
  }
  void *next = vcall<void *>(FP(self, 0x5c), 0x20, hdr);
  if (next) vcall<void>(self, 0x228, next, flags, a, b, 1.0f);
  return ba;
}
PCREG(461250, ActivateAnimSegment);
