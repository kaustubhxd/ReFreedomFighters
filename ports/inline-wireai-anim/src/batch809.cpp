// batch809.cpp - animation layer thread, batch 809: ZLNKOBJ anim-file and bone lookups.
// ZLNKOBJ (PC): +8 base geom (+0x6c = geometry definition id), +0x5c anim file, +0x60 extra anim file,
// +0x64 delta bones, +0x68 extra delta bones. Geometry definitions: [[0x70039c]+0x1aa3]+0x18 (vt 0xb4 original local
// bones, 0xc4 bone definitions, 0xc8 file-bone-id -> bone index map).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

static inline void *defs() { return FP(FP(G(void *, 0x70039c), 0x1aa3), 0x18); }

// ZLNKOBJ::SetAnimFile / SetExAnimFile(ZAnimFilePack*, ZDeltaBone*) [high, GC 80180cdc / 80180ce8].
static void THISCALL SetAnimFile(void *self, void *f, void *d) { FP(self, 0x64) = d; FP(self, 0x5c) = f; }
PCREG(4643e0, SetAnimFile);
static void THISCALL SetExAnimFile(void *self, void *f, void *d) { FP(self, 0x68) = d; FP(self, 0x60) = f; }
PCREG(4646f0, SetExAnimFile);

// ZLNKOBJ::GetBoneDefinitions / GetOrigLocalBones() const [high, GC 80183a68 / 80183ab0].
static void *THISCALL GetBoneDefinitions(void *self) {
  u32 id = F32(FP(self, 8), 0x6c);
  return vcall<void *>(defs(), 0xc4, id);
}
PCREG(462d60, GetBoneDefinitions);
static void *THISCALL GetOrigLocalBones(void *self) {
  u32 id = F32(FP(self, 8), 0x6c);
  return vcall<void *>(defs(), 0xb4, id);
}
PCREG(463300, GetOrigLocalBones);

// ZLNKOBJ::GetBoneControl(int) const [high, GC 80181bf0]: the running ZBoneAnim's +0x14, or 0.
static void *THISCALL GetBoneControl(void *self, s32 i) {
  u8 *b = (u8 *)FP(self, 0x1c) + i * 0x18;
  void *ba = FP(b, 0x14);
  if (ba && (F8(b, 4) & 3)) return FP(ba, 0x14);
  return 0;
}
PCREG(462d30, GetBoneControl);

// ZLNKOBJ::GetBoneName(int) const [high, GC 80181b70]: SBoneDefinition array (vt 0x2cc), 0x30 bytes each, name +0x1c.
static const char *THISCALL GetBoneName(void *self, s32 i) {
  if (i < 0) return 0;
  return vcall<const char *>(self, 0x2cc) + i * 0x30 + 0x1c;
}
PCREG(462f50, GetBoneName);

// ZLNKOBJ::GetBoneNrFromId(unsigned char) const [high, GC 80181afc]: -1 for id 0 or unmapped (0xff).
static s32 THISCALL GetBoneNrFromId(void *self, u8 id) {
  if (!id) return -1;
  u32 gid = F32(FP(self, 8), 0x6c);
  u8 m = vcall<u8 *>(defs(), 0xc8, gid)[id];
  if (m == 0xff) return -1;
  return m;
}
PCREG(462f80, GetBoneNrFromId);

// ZLNKOBJ::ActivateAnimOnce(const char*, int) [high, GC 80184d48]: start the clip by name (vt 0x22c) unless it is
// already the active one (vt 0x23c CheckActiveAnim(name, 0)); 0 if it was.
static u32 THISCALL ActivateAnimOnce(void *self, const char *name, u32 n) {
  if (vcall<bool>(self, 0x23c, name, 0)) return 0;
  return vcall<u32>(self, 0x22c, name, n);
}
PCREG(461210, ActivateAnimOnce);

// ZLNKOBJ::GetAnim(const char*) const [high, GC 80180c4c]: the extra anim file (+0x60) is searched first, then the
// main one (+0x5c); no main file -> 0. File vt 0x18 = GetAnim(name).
static void *THISCALL GetAnim(void *self, const char *name) {
  if (!FP(self, 0x5c)) return 0;
  void *ex = FP(self, 0x60);
  if (ex) {
    void *a = vcall<void *>(ex, 0x18, name);
    if (a) return a;
  }
  return vcall<void *>(FP(self, 0x5c), 0x18, name);
}
PCREG(462ad0, GetAnim);
