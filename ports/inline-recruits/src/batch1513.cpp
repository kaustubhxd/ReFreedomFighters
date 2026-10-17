// batch1513.cpp - recruits thread, batch 1513: CFormationControl constructor, InitWrapper, AddToFormationRef.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void(__attribute__((cdecl)) * logPrintf)(void *log, const char *fmt, ...);
typedef void *(__attribute__((cdecl)) * memsetFn)(void *, s32, u32);
#define CRT_MEMSET (*(memsetFn *)0x676260)

extern "C" u8 *THISCALL ext_469870(u8 *self);                  // base (event object) constructor
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);   // operator new
extern "C" u32 *THISCALL ext_4ccbe0(void *t, s32 a, s32 b);    // REFTAB::REFTAB(int, int)

// 0x5b5930 CFormationControl::CFormationControl(), thiscall, returns this. Base constructor, flag 0x20 at +4,
// +0x44 = 0, vtable 0x6b2158, message ids +0x4c "Msg_FormationControl_UpdatePos" and +0x4e
// "Msg_FormationControl_Regroup" (table slot 0x114 (name, 0, file, line)), formation table +0x48 = null.
// The SEH frame of the original is not ported.
static u8 *THISCALL formCtor(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b2158;
  *(u16 *)(self + 0x4c) = vcall<u16>(objTable(), 0x114, (const char *)0x6a5438, 0u, (const char *)0x6b21ec, 0x68u);
  *(u16 *)(self + 0x4e) = vcall<u16>(objTable(), 0x114, (const char *)0x6a5458, 0u, (const char *)0x6b21ec, 0x69u);
  *(u32 *)(self + 0x48) = 0;
  return self;
}
PCREG(5b5930, formCtor);

// 0x5b6d00 CFormationControl::InitWrapper(), thiscall, plain ret. Registers the object's id under the name
// "ObjectFormationControl" (name table slot 0x60 (name, id, 0x10)), registers its rout handle under
// "FormationControlRout" (handle from the object manager 0x70038c: slot 0x20 says whether it is a managed
// object; else its fast path +8 when the pointer is in [+0xc, +0x10), else the handle stored at this-4, created with
// slot 0xac when missing), and creates the formation table (REFTAB(10, 0x8d)).
static void THISCALL formInitWrapper(u8 *self) {
  void *names = vcall<void *>(objTable(), 0x138);
  void **nvt = *(void ***)names;
  // (the original pushes the 0x10 for the next call before this one-argument call)
  u32 id = vcall<u32>(objTable(), 0x4c, *(void **)(self + 0x44));
  typedef void(THISCALL * f60)(void *, const char *, u32, u32);
  ((f60)nvt[0x60 / 4])(names, (const char *)0x6a5c04, id, 0x10u);
  void *names2 = vcall<void *>(objTable(), 0x138);
  u8 *om = G(u8 *, 0x70038c);
  u32 h;
  if (vcall<u32>(om, 0x20, self)) {
    h = 0;
  } else {
    om = G(u8 *, 0x70038c);
    typedef u32(THISCALL * fFast)(void *);
    fFast fast = *(fFast *)(om + 8);
    if (fast && *(u8 **)(om + 0xc) <= self && self < *(u8 **)(om + 0x10)) {
      h = fast(self);
    } else {
      if (*(u32 *)(self - 4) == 0)
        vcall<void>(om, 0xac, self);
      h = *(u32 *)(self - 4);
    }
  }
  vcall<void>(names2, 0x60, (const char *)0x6ac8cc, h, 4u);
  void *t = ext_41e290(0x1c);
  *(u32 **)(self + 0x48) = t ? ext_4ccbe0(t, 10, 0x8d) : 0;
}
PCREG(5b6d00, formInitWrapper);

extern "C" u32 THISCALL ext_5b6ab0(u8 *self, u8 *grp);     // formation key of a group
extern "C" u8 THISCALL ext_4db9a0(void *geom, u32 cls);    // ZBaseGeom::IsDerivedFrom
extern "C" char *THISCALL ext_4cc1d0(void *str);           // MYSTR -> const char*
extern "C" void THISCALL ext_4cbec0(void *str);            // MYSTR::~MYSTR
extern "C" void THISCALL ext_4de7a0(float *m);             // mreset

// SAddToFormationParams: +0 formation key (in/out), +4 member id, +8 wanted slot (1-based; <= 0 = first free).
// 0x5b59e0 CFormationControl::AddToFormationRef(SAddToFormationParams* p), thiscall, ret 4, returns 0.
// Without a key: the member's group (member slot 0x20 twice) is looked up (0x5b6ab0); if no formation exists for
// the group, every recruitable member of the group with an AI (+0x54) is sent "regroup" (+0x4e) with the member id,
// and nothing else happens. With a key: the formation is found or created (leader = the key's object; member and
// event tables REFTAB(12, 0x1d) / (12, 0x20); anchor and matrix from the leader; slots, heading, timers cleared);
// the member takes the wanted slot or the first free one and the formation is forced to update. No slot: the log
// gets "FormationControl: Failed to add member (%s) at %d" (and the update is still forced).
static u32 THISCALL formAddToFormationRef(u8 *self, u32 *p) {
  if (p[0] == 0) {
    void *o = vcall<void *>(objTable(), 0x58, p[1]);
    void *g1 = vcall<void *>(o, 0x20);
    u8 *grp = vcall<u8 *>(g1, 0x20);
    p[0] = ext_5b6ab0(self, grp);
    if (p[0])
      goto haveKey;
    {
      u32 member = p[1];
      u32 c = *(u32 *)(grp + 8);
      while (c) {
        if (ext_4db9a0((void *)c, 0x2007f9)) {
          void *ai = *(void **)(c + 0x54);
          if (ai)
            vcall<void>(ai, 0x128, (u32) * (u16 *)(self + 0x4e), &member, 0u);
        }
        vcall<void>(grp, 0x50, &c);
      }
    }
    return 0;
  }
haveKey : {
  u8 *f;
  u8 *e = vcall<u8 *>(*(void **)(self + 0x48), 0x2c, p[0]);
  if (e) {
    f = e + 4;
  } else {
    void *L = vcall<void *>(objTable(), 0x58, p[0]);
    f = vcall<u8 *>(*(void **)(self + 0x48), 4, p[0]);
    void *t1 = ext_41e290(0x1c);
    *(u32 **)f = t1 ? ext_4ccbe0(t1, 0xc, 0x1d) : 0;
    void *t2 = ext_41e290(0x1c);
    *(u32 **)(f + 4) = t2 ? ext_4ccbe0(t2, 0xc, 0x20) : 0;
    float *pos = (float *)(f + 0x48);
    float *mat = (float *)(f + 0x60);
    ((u32 *)pos)[0] = 0;
    ((u32 *)pos)[1] = 0;
    ((u32 *)pos)[2] = 0;
    ext_4de7a0(mat);
    vcall<void>(L, 0x80, mat, pos);
    *(u32 *)(f + 0x5c) = 0;
    *(u32 *)(f + 0x58) = 0;
    *(u32 *)(f + 0x54) = 0;
    CRT_MEMSET(f + 8, 0, 0x30);
    *(u32 *)(f + 0x38) = 0;
    *(u32 *)(f + 0x84) = 0;
    *(u32 *)(f + 0x88) = 0;
  }
  s32 *used = (s32 *)(f + 8);
  s32 slot = (s32)p[2];
  bool ok;
  if (slot > 0) {
    ok = used[slot - 1] == 0;
    --slot;
  } else {
    slot = 0;
    while (slot < 12 && used[slot] != 0)
      ++slot;
    ok = slot < 12;
  }
  if (ok && slot >= 0) {
    u8 *m = vcall<u8 *>(*(void **)f, 4, p[1]);
    *(s32 *)m = slot;
    *(u32 *)(m + 8) = 0;
    *(u32 *)(m + 4) = 0;
    m[0xc] = 0;
    *(u32 *)(m + 0xd) = 0xbf800000u;
    used[slot] = 1;
  } else {
    void *o = vcall<void *>(objTable(), 0x58, p[1]);
    void *a = vcall<void *>(o, 0x20);
    void *lo = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6b21ec, 0x22cu);
    u8 str[0x80];
    void *s = vcall<void *>(a, 0x1d8, str, 1u);
    char *cs = ext_4cc1d0(s);
    ((logPrintf)(*(void ***)lo)[0x30 / 4])(lo, (const char *)0x6b2224, cs, p[2]);
    ext_4cbec0(str);
  }
  f[0x8c] = 1;
}
  return 0;
}
PCREG(5b59e0, formAddToFormationRef);
