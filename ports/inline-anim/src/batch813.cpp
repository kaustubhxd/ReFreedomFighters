// batch813.cpp - animation layer thread, batch 813: ZLNKOBJ::StartAnim and StopAllAnims.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

static double crtFmod(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// ZLNKOBJ::StartAnim(ZBoneAnim* ba, int flags) [high, GC 80184dc4]. thiscall ret 8, bool = some bone took the clip.
// AnimHeader fields used: +0x5c/+0x6c (start fraction num/den, frames per second?), +0x60/+0x64 first/last frame,
// +0x70..+0x78 copied to ba+0x38..+0x40, +0x7c clip flags (bit 0 -> flag 4 with call flag 0x10, bit 1 -> 8 (sync to
// root), bit 3 -> 0x200, bit 4 -> 0x800, negative -> random-ish start fraction +0x5c/+0x6c unless call flag 2).
// With flag 8 and a root bone clip that also has 8, the new clip starts in phase with the root clip
// (fmod of its elapsed frames by its length). Sets ba: +0xc frames, +0x20 1/frames, +4/+8 start frame, +0x1c start
// time (clock ticks / 1024), +0x18 end frame (+0x34, or frames, or 1e38 when looping flag 4), +0x14 flags. Then
// every bone of the clip (file vt 0x24 count, 0x2c bone anim, 0x3c bone id) mapped by vt 0x2b4 is offered to
// vt 0x350(hdr, boneAnim, bone, ba); +0x44 counts the bones that took it.
// Note: the bone id is pushed as a dword whose upper 24 bits are left over from the flags (the exe stores the id
// byte into the flags argument slot); this is reproduced.
static bool THISCALL StartAnim(u8 *self, u8 *ba, u32 flags) {
  u8 *hdr = (u8 *)FP(ba, 0x70);
  F32(self, 0x122) = 1;
  vcall<void>(self, 0x268, hdr, F32(hdr, 0x7c));
  float start = 0.0f;
  if (!(flags & 2) && *(s32 *)(hdr + 0x7c) < 0) start = (float)*(s32 *)(hdr + 0x5c) / (float)*(s32 *)(hdr + 0x6c);
  if ((flags & 0x10) && (F8(hdr, 0x7c) & 1)) flags |= 4;
  u32 h = F32(hdr, 0x7c);
  u32 f1 = (h & 2) ? flags | 8 : flags;
  u32 f2 = (h & 8) ? f1 | 0x200 : f1;
  u32 fin = (h & 0x10) ? f2 | 0x800 : f2;
  if (FF(ba, 0x2c) == 0.0f) FF(ba, 0x2c) = start;
  float sync = 0.0f;
  F32(ba, 0xc) = F32(hdr, 0x64) - F32(hdr, 0x60);
  u8 *b0 = (u8 *)FP(self, 0x1c);
  u8 *rb = (u8 *)FP(b0, 0x14);
  if (rb && ((F32(rb, 0x14) & fin) & 8) && (F8(FP(self, 0x1c), 4) & 1)) {
    u8 *rh = (u8 *)FP(rb, 0x70);
    s32 n = *(s32 *)(rb + 0xc);
    s32 clk = *(s32 *)((u8 *)G(void *, 0x70039c) + 0x40);
    s32 a = (s32)((float)*(s32 *)(rh + 0x6c) * FF(rb, 0x28) * 1024.0f);
    s32 d = (s32)(FF(rb, 0x1c) * 1024.0f);
    s32 v = (s32)(((long long)a * (long long)(s32)((u32)clk - (u32)d)) >> 10);
    float x = (float)v * bitsf(0x3a800000);
    sync = (float)(crtFmod((double)x, (double)(float)n) / (double)n);
  }
  u32 nb = vcall<u32>(FP(self, 0x5c), 0x24, hdr);
  float frames = (float)*(s32 *)(ba + 0xc);
  FF(ba, 0x20) = 1.0f / frames;
  if (sync == 0.0f) F32(ba, 4) = F32(ba, 0x30);
  else FF(ba, 4) = frames * sync;
  float s = FF(ba, 4);
  FF(ba, 8) = s;
  s32 clk2 = *(s32 *)((u8 *)G(void *, 0x70039c) + 0x40);
  s32 k = (s32)(s / ((float)*(s32 *)(hdr + 0x6c) * FF(ba, 0x28)) * 1024.0f);
  FF(ba, 0x1c) = (float)(s32)((u32)clk2 - (u32)k) * bitsf(0x3a800000);
  float e34 = FF(ba, 0x34);
  if (e34 == -1.0f) {
    if (fin & 4) F32(ba, 0x18) = 0x7e967699;
    else FF(ba, 0x18) = frames;
  } else {
    FF(ba, 0x18) = e34;
  }
  F32(ba, 0x14) = fin;
  F32(ba, 0x38) = F32(hdr, 0x70);
  F32(ba, 0x3c) = F32(hdr, 0x74);
  F32(ba, 0x40) = F32(hdr, 0x78);
  u32 slot = fin;
  for (u32 j = 0; j != nb; j++) {
    void *bA = vcall<void *>(FP(self, 0x5c), 0x2c, hdr, j);
    u8 id = vcall<u8>(FP(self, 0x5c), 0x3c, bA);
    slot = (slot & ~0xffu) | id;
    s32 bone = vcall<s32>(self, 0x2b4, slot);
    if (bone != -1 && vcall<bool>(self, 0x350, hdr, bA, bone, ba)) F32(ba, 0x44) += 1;
  }
  return F32(ba, 0x44) != 0;
}
PCREG(464760, StartAnim);

// ZLNKOBJ::StopAllAnims(bool keepLooping) [high, GC 80184674]: vt 0x274 first; every bone with a running bone anim
// gets its frame back from the ZBoneAnim (+4) and is ended (vt 0x340(i, 0)); every pooled ZBoneAnim is destroyed
// (callbacks fired) and removed. With keepLooping, clips whose header flags +0x7c have 0x30 are left alone.
extern "C" void THISCALL ext_462510(void *ba, u32 fire);   // ZBoneAnim::Destroy (batch 811)
static void THISCALL StopAllAnims(u8 *self, u8 keep) {
  if (!FP(self, 0x18)) return;
  vcall<void>(self, 0x274);
  for (u32 i = 0; i != F32(self, 0x20); i++) {
    u8 *b = (u8 *)FP(self, 0x1c) + i * 0x18;
    if (!(F8(b, 4) & 1)) continue;
    u8 *ba = (u8 *)FP(b, 0x14);
    if (keep && (F8(FP(ba, 0x70), 0x7c) & 0x30)) continue;
    F32(b, 0) = F32(ba, 4);
    vcall<void>(self, 0x340, i, 0);
  }
  if (!FP(self, 0x18)) return;
  u8 it[12];
  vcall<void>(FP(self, 0x18), 0x4c, it);
  u32 *n = vcall<u32 *>(FP(self, 0x18), 0x64, it);
  while (n) {
    u8 *o = (u8 *)(n + 1);
    if (!keep || !(F8(FP(o, 0x70), 0x7c) & 0x30)) {
      ext_462510(o, 1);
      vcall<void>(FP(self, 0x18), 0x44, it);
    }
    n = vcall<u32 *>(FP(self, 0x18), 0x64, it);
  }
}
PCREG(464d00, StopAllAnims);
