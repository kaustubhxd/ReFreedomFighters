// batch802.cpp - animation layer thread, batch 802: ZBoneModifyBase::GetBoneAnims.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// fmod through the exe's import slot for _CIfmod (x87 arguments, result in ST0); same helper as batch58.
static double crtFmod(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// ZBoneModifyBase::GetBoneAnims(ZLNKOBJ* obj, ZActiveBone* ab) [low map confidence, GC 80223314; the body fits the
// name: it fills one ZActiveBone per bone from the object's per-bone animation table]. thiscall, ret 8.
//   obj+0x1c -> per-bone table, 0x18 bytes per bone: +0 frame (float, used when the bone is not running),
//               +4 flags (bits 0..1 = bone anim running), +0xc extra offset ptr, +0x10 anim id, +0x14 ZBoneAnim*.
//   ZBoneAnim used: +8 time, +0xc frame count (int), +0x18 clip length?, +0x20 scale, +0x2c blend-in time.
// obj->vt[0x2cc]() is called first and its result ignored (it runs before the table is read; the table pointer
// is read before the call).
// Bone 0 gets only the extra pointer. For bones 1..count-1 (count at this+0x11, re-read each pass):
//   running: frame = len > t ? t - (float)(int)(scale*t) * n : (len == n ? len : fmod(len, n)); flag byte = 1,
//            blend time = ZBoneAnim+0x2c, anim = table id;
//   idle:    flag 0, blend time 0, anim = id (frame copied from the table) or 0;
//   second anim (+0xc) always cleared.
static void THISCALL GetBoneAnims(void *self, void *obj, u8 *ab) {
  if (F32(self, 0x291) != 0 || F8(self, 0x295) != 0) return;
  u8 *t = (u8 *)FP(obj, 0x1c);
  vcall<void *>(obj, 0x2cc);
  F32(ab, 0x18) = F32(t, 0xc);
  for (u32 i = 1; i != F32(self, 0x11); i++) {
    u8 *b = t + 0x18 * i;
    u8 *a = ab + 0x1d * i;
    F32(a, 0x18) = F32(b, 0xc);
    if (F8(b, 4) & 3) {
      u8 *ba = (u8 *)FP(b, 0x14);
      float len = FF(ba, 0x18), tm = FF(ba, 8);
      float n = (float)*(s32 *)(ba + 0xc);
      float fr;
      if (len > tm) fr = tm - (float)(s32)(FF(ba, 0x20) * tm) * n;
      else if (len == n) fr = len;
      else fr = (float)crtFmod((double)len, (double)n);
      F8(a, 0x1c) = 1;
      F32(a, 8) = F32(ba, 0x2c);
      FF(a, 4) = fr;
      F32(a, 0) = F32(b, 0x10);
    } else {
      F8(a, 0x1c) = 0;
      F32(a, 8) = 0;
      u32 id = F32(b, 0x10);
      if (id) {
        F32(a, 0) = id;
        F32(a, 4) = F32(b, 0);
      } else {
        F32(a, 0) = 0;
      }
    }
    F32(a, 0xc) = 0;
  }
}
PCREG(646220, GetBoneAnims);
