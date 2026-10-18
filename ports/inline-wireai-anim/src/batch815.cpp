// batch815.cpp - animation layer thread, batch 815: ZAnimFilePack (the loaded .ANM clip pack) accessors.
// ZAnimFilePack (PC): +0 vtable, +4 pack chunk header, +8 bone-name table base (entry: id byte, then the name),
// +0xc clip data base (AnimHeader, bone anims), +0x24 event data base.
// Chunk header h: h[1] bit 31 set = has a data block, at h + 0x14 + 4*h[4] when bit 30 is also set, else at h + 0x10.
// A block starts with a count; its offset table starts at block + (block[1] top bits != 0 ? block[2] : 8).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// The exe reads through a null block pointer when bit 31 is clear (it would fault in the game); the port keeps the
// read so the emulator sees the same access.
static inline u8 *chunkData(u8 *h) {
  u32 w = F32(h, 4);
  if ((s32)w >= 0) return 0;
  if (w & 0x40000000) return h + F32(h, 0x10) * 4 + 0x14;
  return h + 0x10;
}
static inline u32 chunkOff(u8 *L) { return (F32(L, 4) & 0xc0000000) ? F32(L, 8) : 8; }
static inline u32 rd32(u8 *p) { return *(volatile u32 *)p; }

// ZAnimFilePack::ZAnimFilePack() / ~ZAnimFilePack() [medium, GC 8028d4c0 / 8028d4d4] (vtables 0x6973a4 / base 0x697360).
static void *THISCALL Pack_ctor(u8 *self) { F32(self, 0) = 0x6973a4; return self; }
PCREG(4e5000, Pack_ctor);
extern "C" void ext_634273(void *p, u32 size);   // operator delete (sized, cdecl)
static void *THISCALL Pack_dtor(u8 *self, u32 flags) {
  F32(self, 0) = 0x697360;
  if (flags & 1) ext_634273(self, 0x2c);
  return self;
}
PCREG(4e5050, Pack_dtor);

// ZAnimFilePack::CountAnimBones(AnimHeader*) [medium, GC 8028f140]: bone table at data + hdr+0x80, count first.
static u32 THISCALL CountAnimBones(u8 *self, u8 *hdr) { return F32(F32(hdr, 0x80) + (u8 *)FP(self, 0xc), 0); }
PCREG(4e5080, CountAnimBones);

// ZAnimFilePack::CountAnims() [low, GC 8028f150; body fits]: count word of the pack's data block.
static u32 THISCALL CountAnims(u8 *self) { return rd32(chunkData((u8 *)FP(self, 4))); }
PCREG(4e50a0, CountAnims);

// ZAnimFilePack::DoesAnimBelongTo(AnimHeader*) [medium, GC 8028ec7c]: hdr+0x44 is its index; the offset table entry
// must point at it.
static bool THISCALL DoesAnimBelongTo(u8 *self, u8 *hdr) {
  u8 *L = chunkData((u8 *)FP(self, 4));
  u32 i = F32(hdr, 0x44);
  if (!(i < rd32(L))) return false;
  return F32(L + chunkOff(L) + i * 4, 0) == (u32)(hdr - (u8 *)FP(self, 0xc));
}
PCREG(4e50c0, DoesAnimBelongTo);

// ZAnimFilePack::GetAnim(const char* name) [medium, GC 8028edb8]: first a case-insensitive match (_stricmp) of the
// name with every '*' removed, then a wildcard match (striwcmp, 0x4cc850) of the original name. Clip names are the
// first field of each AnimHeader. Empty name -> 0.
extern "C" s32 FASTCALL ext_4cc850(const char *a, const char *b);   // striwcmp
static void *THISCALL GetAnimByName(u8 *self, const char *name) {
  char c = name[0];
  if (!c) return 0;
  char buf[0x84];
  char *w = buf;
  buf[0] = c;
  const char *s = name;
  do {
    if (c != '*') w++;
    c = *++s;
    *w = c;
  } while (c);
  u8 *L = chunkData((u8 *)FP(self, 4));
  u32 n = rd32(L);
  u32 *tab = (u32 *)(L + chunkOff(L));
  typedef int(__attribute__((cdecl)) * cmp_t)(const char *, const char *);
  for (u32 i = 0; i != n; i++) {
    u8 *a = (u8 *)FP(self, 0xc) + tab[i];
    if ((*(cmp_t *)0x676414)((const char *)a, buf) == 0) return a;
  }
  tab = (u32 *)(L + chunkOff(L));
  for (u32 i = 0; i != n; i++) {
    u8 *a = (u8 *)FP(self, 0xc) + tab[i];
    if (ext_4cc850((const char *)a, name) == 0) return a;
  }
  return 0;
}
PCREG(4e5160, GetAnimByName);

// ZAnimFilePack::GetAnimEvent(const AnimHeader*) const [medium, GC 8028f2fc]: event base + hdr+0x4c - 1, 0 if none.
static void *THISCALL GetAnimEvent(u8 *self, u8 *hdr) {
  u32 e = F32(hdr, 0x4c);
  if (!e) return 0;
  return (u8 *)FP(self, 0x24) - 1 + e;
}
PCREG(4e5310, GetAnimEvent);

// ZAnimFilePack::GetAnimFileName() const [medium, GC 8028df3c]: name string inside the chunk header.
static const char *THISCALL GetAnimFileName(u8 *self) {
  u8 *h = (u8 *)FP(self, 4);
  return (const char *)(h + chunkOff(h));
}
PCREG(4e5330, GetAnimFileName);

// ZAnimFilePack::GetAnimNr(int i) [medium, GC 8028f014]: i-th AnimHeader, 0 when i >= count (signed compare).
static void *THISCALL GetAnimNr(u8 *self, s32 i) {
  u8 *L = chunkData((u8 *)FP(self, 4));
  if (!((s32)rd32(L) > i)) return 0;
  return (u8 *)FP(self, 0xc) + F32(L + chunkOff(L) + i * 4, 0);
}
PCREG(4e5360, GetAnimNr);

// ZAnimFilePack::GetBoneAnim(AnimHeader*, int) [medium, GC 8028f2b0].
static void *THISCALL GetBoneAnimI(u8 *self, u8 *hdr, s32 i) {
  u8 *d = (u8 *)FP(self, 0xc);
  return d + F32(d + F32(hdr, 0x80) + i * 4, 4);
}
PCREG(4e53d0, GetBoneAnimI);

// ZAnimFilePack::GetBoneAnim(AnimHeader*, const char* bone) [medium, GC 8028f218]: wildcard match on bone names.
static void *THISCALL GetBoneAnimN(u8 *self, u8 *hdr, const char *bone) {
  u32 *tab = (u32 *)(F32(hdr, 0x80) + (u8 *)FP(self, 0xc));
  for (u32 i = 0; i != tab[0]; i++) {
    u8 *a = (u8 *)FP(self, 0xc) + tab[1 + i];
    if (ext_4cc850((const char *)FP(self, 8) + 1 + F32(a, 0), bone) == 0) return a;
  }
  return 0;
}
PCREG(4e53f0, GetBoneAnimN);

// ZAnimFilePack::GetBoneAnimName / GetBoneAnimNrFrames / GetBoneId (bone anim) [medium, GC 8028f2d8/2d0/2ec].
static const char *THISCALL GetBoneAnimName(u8 *self, u8 *ba) { return (const char *)FP(self, 8) + F32(ba, 0) + 1; }
PCREG(4e5450, GetBoneAnimName);
static u32 THISCALL GetBoneAnimNrFrames(void *, u8 *ba) { return F16(ba, 8); }
PCREG(4e5470, GetBoneAnimNrFrames);
static u8 THISCALL GetBoneId(u8 *self, u8 *ba) { return F8(FP(self, 8), F32(ba, 0)); }
PCREG(4e5480, GetBoneId);

// ZAnimFilePack::GetFacialAnim(AnimHeader*) [medium, GC 8028f1f8]: data + hdr+0x48, 0 when negative.
static void *THISCALL GetFacialAnim(u8 *self, u8 *hdr) {
  s32 f = *(s32 *)(hdr + 0x48);
  if (f < 0) return 0;
  return (u8 *)FP(self, 0xc) + f;
}
PCREG(4e54a0, GetFacialAnim);
