// batch1103.cpp - fresh-11 batch 3: slice-11 functions of 93 to 106 bytes. Names from the GC name map; GUESS otherwise.
// SEH frames (fs:[0] push/restore) and /GS cookies are not reproduced: they only touch the stack and fs:[0], which
// each function restores before it returns.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // __builtin_delete (sized), cdecl
static inline u8 *Eng9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x45b970 ZBloodStains::ClassInit() [medium]: o = eng9b->slot +0x138(); o->slot +0x60(0x684cd4, eng9b->slot +0x4c(this), 4)
// (the 4 is pushed before the +0x4c call, which takes one argument); slot +0x110(0x10, 0); ZSTDOBJ::ClassInit; tail
// slot +0x214().
extern "C" void THISCALL ext_43e0f0(void *self);
static u32 THISCALL BloodStains_ClassInit(u8 *self) {
  void *o = vcall<void *>(Eng9b(), 0x138);
  u32 r = vcall<u32>(Eng9b(), 0x4c, self);
  vcall<void>(o, 0x60, 0x684cd4u, r, 4u);
  vcall<void>(self, 0x110, 0x10u, 0u);
  ext_43e0f0(self);
  return vcall<u32>(self, 0x214);
}
PCREG(45b970, BloodStains_ClassInit);

// 0x53b7f0 ZSoundGraph::CopyChain(SPath*, SPath*) [low] (ECX unused, ret 8): count +0x25, byte +0, dword +1; per
// entry i < src count (re-read): dwords +0x29/+0x2d/+0x31 + 12i, then dword +5 + 4i.
static void STDCALL SoundGraph_CopyChain(u8 *dst, u8 *src) {
  *(u32 *)(dst + 0x25) = *(u32 *)(src + 0x25);
  dst[0] = src[0];
  *(u32 *)(dst + 1) = *(u32 *)(src + 1);
  for (s32 i = 0; i < *(s32 *)(src + 0x25); i++) {
    *(u32 *)(dst + 0x29 + 12 * i) = *(u32 *)(src + 0x29 + 12 * i);
    *(u32 *)(dst + 0x2d + 12 * i) = *(u32 *)(src + 0x2d + 12 * i);
    *(u32 *)(dst + 0x31 + 12 * i) = *(u32 *)(src + 0x31 + 12 * i);
    *(u32 *)(dst + 5 + 4 * i) = *(u32 *)(src + 5 + 4 * i);
  }
}
PCREG(53b7f0, SoundGraph_CopyChain);

// 0x616b70 GUESS scalar deleting dtor: vtable 0x6bdcf4, member dtor 0x659c00(this+8), base vtable 0x6bdc38,
// delete(this, 0x14).
extern "C" void THISCALL ext_659c00(void *self);
static u8 *THISCALL DelDtor616b70(u8 *self, u32 flags) {
  *(u32 *)self = 0x6bdcf4;
  ext_659c00(self + 8);
  *(u32 *)self = 0x6bdc38;
  if (flags & 1) ext_634273(self, 0x14);
  return self;
}
PCREG(616b70, DelDtor616b70);

// 0x620670 GUESS clear two node lists (cdecl): free every node of +0 and of +4 through the allocator at +0x14 (slot
// +8, cdecl; next = node[0]); then +0, +4, +8, +0xc, +0x10 = 0.
typedef void (*freefn_t)(void *);
static void Clear620670(u32 *p) {
  for (u32 *n = (u32 *)p[0]; n;) {
    u32 *next = (u32 *)n[0];
    (*(freefn_t *)((u8 *)p[5] + 8))(n);
    n = next;
  }
  p[0] = 0;
  for (u32 *n = (u32 *)p[1]; n;) {
    u32 *next = (u32 *)n[0];
    (*(freefn_t *)((u8 *)p[5] + 8))(n);
    n = next;
  }
  p[1] = 0;
  p[3] = 0;
  p[4] = 0;
  p[2] = 0;
}
PCREG(620670, Clear620670);

// 0x636330 GUESS constructor: vtable 0x6c2080, +4 = 'OLAP' (0x50414c4f), the rest cleared.
static u8 *THISCALL Ctor636330(u8 *self) {
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 4) = 0x50414c4f;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  self[0x28] = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)(self + 0x2d) = 0;
  self[0x31] = 0;
  *(u32 *)self = 0x6c2080;
  *(u32 *)(self + 0x36) = 0;
  self[0x3a] = 0;
  return self;
}
PCREG(636330, Ctor636330);

// 0x53d0f0 / 0x565eb0 GUESS factories: p = ([eng9b+8])->slot +0x44(ECX as passed); p ? ctor(p) : 0; returns p.
extern "C" void THISCALL ext_53ccd0(void *self);   // CRigidBody::CRigidBody()
extern "C" void THISCALL ext_565b90(void *self);   // CBriefing::CBriefing()
static u8 *THISCALL NewRigidBody(u32 arg) {
  u8 *p = vcall<u8 *>(*(void **)(Eng9b() + 8), 0x44, arg);
  if (p) ext_53ccd0(p);
  return p;
}
PCREG(53d0f0, NewRigidBody);
static u8 *THISCALL NewBriefing(u32 arg) {
  u8 *p = vcall<u8 *>(*(void **)(Eng9b() + 8), 0x44, arg);
  if (p) ext_565b90(p);
  return p;
}
PCREG(565eb0, NewBriefing);

// 0x424e70 ZSysComGC::Free() [medium] (scalar deleting): vtable 0x67864c; IAT 0x6761d4(h or 0xffff, +4, (+8 << 8) + 0xa,
// 0); [0x700390] = 0; IAT 0x6762ac(); [0x6fd930] = 0; 0x42ace0(); delete(this, 0x2c).
typedef u32(STDCALL *iat4_t)(u32, u32, u32, u32);
typedef u32(STDCALL *iat0_t)();
extern "C" void THISCALL ext_42ace0(void *self);
static u8 *THISCALL SysComGC_Free(u8 *self, u32 flags) {
  u32 h = *(u32 *)(self + 0x24);
  *(u32 *)self = 0x67864c;
  if (!h) h = 0xffff;
  G(iat4_t, 0x6761d4)(h, *(u32 *)(self + 4), (*(u32 *)(self + 8) << 8) + 0xa, 0);
  G(u32, 0x700390) = 0;
  G(iat0_t, 0x6762ac)();
  G(u32, 0x6fd930) = 0;
  ext_42ace0(self);
  if (flags & 1) ext_634273(self, 0x2c);
  return self;
}
PCREG(424e70, SysComGC_Free);

// 0x5060f0 GUESS factory: new(0x18) then ZLinkIf::ZLinkIf(this); 0 when new fails.
extern "C" void *ext_41e290(u32 n);
extern "C" u32 THISCALL ext_5047c0(void *self, void *obj);
static u32 THISCALL NewLinkIf(u8 *self) {
  void *p = ext_41e290(0x18);
  if (!p) return 0;
  return ext_5047c0(p, self);
}
PCREG(5060f0, NewLinkIf);

// 0x565870 GUESS constructor tail: +0x180 = 0x6a6c0c, +0x44 = +0x30 = 0, vtable 0x686874, eng9b->slot +0x34(this).
static u32 THISCALL Ctor565870(u8 *self) {
  *(u32 *)(self + 0x180) = 0x6a6c0c;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  return vcall<u32>(Eng9b(), 0x34, self);
}
PCREG(565870, Ctor565870);

// 0x4f6ab0 GUESS constructor (a, b, c): base 0x4f97f0(a, b, c); vtable 0x69aaf0; fields cleared, +0x97 = 3000.
extern "C" void THISCALL ext_4f97f0(void *self, u32 a, u32 b, u32 c);
static u8 *THISCALL Ctor4f6ab0(u8 *self, u32 a, u32 b, u32 c) {
  ext_4f97f0(self, a, b, c);
  *(u32 *)self = 0x69aaf0;
  *(u32 *)(self + 0x93) = 0;
  *(u32 *)(self + 0x8f) = 0;
  *(u32 *)(self + 0xa3) = 0;
  *(u32 *)(self + 0x9b) = 0;
  *(u32 *)(self + 0x9f) = 0;
  self[0xa7] = 0;
  *(u32 *)(self + 0x97) = 0xbb8;
  return self;
}
PCREG(4f6ab0, Ctor4f6ab0);

// 0x64dcb0 GUESS reset: while count +0x10089: slot +0xc([[first entry +0x1008d]+0xc]+0xc); o = +0x1005d: slot +0x60(),
// slot +0x64(); then entry[i]+0x70 = i + 1 for every entry.
static void THISCALL Reset64dcb0(u8 *self) {
  while (*(u32 *)(self + 0x10089)) {
    u8 *e = *(u8 **)(self + 0x1008d);
    vcall<void>(self, 0xc, *(u32 *)(*(u8 **)(e + 0xc) + 0xc));
  }
  vcall<void>(*(void **)(self + 0x1005d), 0x60);
  vcall<void>(*(void **)(self + 0x1005d), 0x64);
  for (u32 i = 0; i != *(u32 *)(self + 0x10089); i++)
    (*(u8 **)(self + 0x1008d + 4 * i))[0x70] = (u8)(i + 1);
}
PCREG(64dcb0, Reset64dcb0);
