// batch812.cpp - animation layer thread, batch 812: ZLNKOBJ::EndMatBoneMotion.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4d2280(void *com);                               // CCom::CCom
extern "C" void THISCALL ext_4d39a0(void *com, const char *k, const char *v);  // CSharedCom::SetVal(str)
extern "C" void THISCALL ext_4d3ab0(void *com, const char *k, u32 v);          // CSharedCom::SetVal(int)
extern "C" void THISCALL ext_4d2330(void *com);                               // CCom::~CCom (no GC name)

// ZLNKOBJ::EndMatBoneMotion(int bone, bool handOver) [high, GC 80181c98]. thiscall ret 8.
// Stops the bone anim on one bone. Bone definitions (vt 0x2cc, 0x30 bytes each): +0xc next bone in the chain,
// +0x2f type (3 = no hand-over). With handOver (and byte +0x70 clear), the first later bone in the chain that runs a
// different ZBoneAnim gets the matching clip for this bone (anim file vt 0x30(its clip, vt 0x2bc(bone))) through
// vt 0x350(clip, boneClip, bone, its ZBoneAnim); on success that ZBoneAnim's user count (+0x44) goes up.
// The ending ZBoneAnim's user count drops; at 0 it is finished (+0x44 = -1): an "anim done" message (CCom with
// strAnimName / lAnimID) goes to vt 0x130 when the geom flag 0x800000 is set, vt 0x344(name, control) is called,
// and the first pooled ZBoneAnim waiting to start (+0x44 == -2) is started (vt 0x34c).
// The exe's SEH frame and the 16 KB CCom on the stack are kept as a stack buffer; CCom's own code is not part of
// this function.
static void THISCALL EndMatBoneMotion(u8 *self, s32 bone, u8 handOver) {
  u8 *b = (u8 *)FP(self, 0x1c) + bone * 0x18;
  u32 fl = F32(b, 4);
  if (!(fl & 1)) return;
  u8 *ba = (u8 *)FP(b, 0x14);
  F32(b, 4) = fl & ~3u;
  u32 ctl = F32(ba, 0x14);
  u8 *defs = vcall<u8 *>(self, 0x2cc);
  if (F8(defs + bone * 0x30, 0x2f) != 3 && handOver && !F8(self, 0x70)) {
    s32 j = *(s32 *)(vcall<u8 *>(self, 0x2cc) + bone * 0x30 + 0xc);
    while (j >= 0) {
      u8 *bj = (u8 *)FP(self, 0x1c) + j * 0x18;
      u8 *baj = (u8 *)FP(bj, 0x14);
      if ((F8(bj, 4) & 1) && baj != ba) {
        u32 x = vcall<u32>(self, 0x2bc, bone);
        void *h = vcall<void *>(FP(self, 0x5c), 0x30, FP(baj, 0x70), x);
        if (h && vcall<bool>(self, 0x350, FP(baj, 0x70), h, bone, baj)) F32(FP(bj, 0x14), 0x44) += 1;
        break;
      }
      j = *(s32 *)(vcall<u8 *>(self, 0x2cc) + j * 0x30 + 0xc);
    }
  }
  if (--*(s32 *)(ba + 0x44) != 0) return;
  F32(ba, 0x44) = 0xffffffff;
  u8 com[0x40c4];
  ext_4d2280(com);
  ext_4d39a0(com, (const char *)0x685918, (const char *)(ba + 0x4c));   // "strAnimName"
  ext_4d3ab0(com, (const char *)0x685924, F32(ba, 0x48));               // "lAnimID"
  if (F32(FP(self, 8), 0x3c) & 0x800000) vcall<void>(self, 0x130, self, (u32)F16(self, 0x128), com);
  vcall<void>(self, 0x344, ba + 0x4c, ctl);
  u8 started = 0;
  if (FP(self, 0x18)) {
    u8 it[12];
    vcall<void>(FP(self, 0x18), 0x4c, it);
    u32 *n = vcall<u32 *>(FP(self, 0x18), 0x64, it);
    while (n) {
      u8 *o = (u8 *)(n + 1);
      if (!started && *(s32 *)(o + 0x44) == -2) {
        F32(o, 0x44) = 0;
        started = 1;
        vcall<void>(self, 0x34c, o, n[0]);
      }
      n = vcall<u32 *>(FP(self, 0x18), 0x64, it);
    }
  }
  ext_4d2330(com);
}
PCREG(4627d0, EndMatBoneMotion);
