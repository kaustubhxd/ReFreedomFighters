// batch306.cpp - mounted gun tree, batch 306: the nest's life cycle: ZEventBase constructor (shared base of 241 event
// classes), CMachinegunControlGroup constructor, allocator wrapper, deleting destructor, Save and Load.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallP0)(void *self);
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVF)(void *self, float a);
typedef u32(THISCALL *regMsg)(void *self, const char *name, u32 z, const char *file, u32 line);
typedef void (*assertHook)();

extern "C" void THISCALL ext_469870(void *self);    // ZEventBase::ZEventBase (this batch)
extern "C" void *THISCALL ext_5c7f50(void *self);   // CMachinegunControlGroup ctor (this batch)
extern "C" void ext_4690b0(void *p, u32 size);      // sized operator delete stand-in (a bare ret in this build)

static inline u8 *db() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x469870 ZEventBase::ZEventBase() (no map name; 241 callers, all event-class constructors; name inferred from the
// vtable 0x686874 it installs, which the nest's destructor restores). thiscall, no args, returns this.
// Zeroes the base fields, sets +0xc = 0.1 (timer interval), gives +0x10 a staggered start time: clock -
// (int)(db+0xae0 * 0.1 * -1024), and advances the database's stagger counter db+0xae0 by 0.1, wrapping at 1.0.
// Finally registers the event with the database (slot 0x30). The original skips the +0x10 store when &this->+0x10
// equals the address of one of its own stack slots, which never happens for a real object (not reproduced).
static u8 *THISCALL zEventBaseCtor(u8 *self) {
  *(u32 *)self = 0x686874u;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0xc) = 0x3dcccccdu;   // 0.1f
  {
    u8 *eng = G(u8 *, 0x70039c);
    float st = *(float *)(*(u8 **)(eng + 0x9b) + 0xae0) * 0.1f * -1024.0f;   // 0x67a284, 0x67862c
    *(u32 *)(self + 0x10) = *(u32 *)(eng + 0x40) - (u32)(s32)st;
  }
  *(float *)(db() + 0xae0) = *(float *)(db() + 0xae0) + 0.1f;
  u8 *d = db();
  if (*(float *)(d + 0xae0) >= 1.0f)   // comiss / jb: a NaN does not reset
    *(u32 *)(d + 0xae0) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0;
  ((vcallVP)VT(db(), 0x30))(db(), self);
  return self;
}
PCREG(469870, zEventBaseCtor);

// The 13 message names, their source lines (0x23..0x2f) and the globals the ids go to (see batch 304).
static const u32 kMsgName[13] = {0x6a584c, 0x6b49f8, 0x6b4a04, 0x6a5874, 0x6b4a14, 0x6a5830, 0x6a585c,
                                 0x6b4a20, 0x6a5868, 0x6a5884, 0x694c6c, 0x6a583c, 0x6a5190};

// 0x5c7f50 CMachinegunControlGroup::CMachinegunControlGroup(), GC map [high]; thiscall, no args, returns this.
// ZEventBase base, flag 0x20 in +4, vtable 0x6b4934, cleared fields, the 13 message registrations (database slot 0x114,
// name, 0, file, line 0x23 + i) into the u16 globals 0x714350 + 4*i, then owner 0 and default half-arcs
// +0x48 = pi/4 (45 deg), +0x4c = 0.5236 (30 deg: the vertical default; level data only overrides +0x48).
static u8 *THISCALL ctor(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b4934u;
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x70) = 0;
  *(u32 *)(self + 0x84) = 0;
  *(u32 *)(self + 0x88) = 0;
  for (int i = 0; i < 13; i++) {
    u8 *d = db();
    u32 id = ((regMsg)VT(d, 0x114))(d, (const char *)kMsgName[i], 0, (const char *)0x6b49b8, 0x23 + i);
    *(u16 *)(0x714350 + 4 * i) = (u16)id;
  }
  *(u32 *)(self + 0x80) = 0;
  *(u32 *)(self + 0x48) = 0x3f490fdbu;
  *(u32 *)(self + 0x4c) = 0x3f060a92u;
  return self;
}
PCREG(5c7f50, ctor);

// 0x5c85e0 (no map name; the class factory: GC ZRoutAllocator<CMachinegunControlGroup>::AllocOne(unsigned int) /
// ConstructorCall). Takes one value in ECX (MSVC passes it like a this pointer; inferred: the allocation id) and
// forwards it to the allocator at database+8, slot 0x44(id), which returns the memory or 0; then the constructor runs.
static u8 *THISCALL allocOne(u32 id) {
  u8 *a = *(u8 **)(db() + 8);
  u8 *p = ((vcallPU)VT(a, 0x44))(a, id);
  if (p)
    ext_5c7f50(p);
  return p;
}
PCREG(5c85e0, allocOne);

// 0x5c81e0 CMachinegunControlGroup scalar deleting destructor (map says ZNoise::~ZNoise [low]; it is vtable slot 0 of
// both). thiscall, ret 4, returns this. Clears +0x44 and +0x30, restores the ZEventBase vtable, unregisters the
// event (database slot 0x34). With flag bit 0: flag bit 2 frees through 0x4690b0(this, 0x90); otherwise the assert
// hook at 0x7003b0 is called (int3 when there is none): these objects come from a pool and must not be deleted.
static u8 *THISCALL dtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874u;
  ((vcallVP)VT(db(), 0x34))(db(), self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x90);
    } else {
      assertHook h = G(assertHook, 0x7003b0);
      if (!h)
        asm volatile("int3");
      h();
    }
  }
  return self;
}
PCREG(5c81e0, dtor);

// 0x5c9180 CMachinegunControlGroup::Save(ZSaveGame*), GC map [high]; thiscall, ret 4, returns 1. Clears flag 0x40 in +4,
// writes floats +0x48..+0x64 (save slot 0x4c), dwords +0x68..+0x78 (slot 0x3c), the list geom +0x7c (slot 0x64),
// +0x80 and +0x88 (slot 0x3c), +0x8c (slot 0x4c). The aim error +0x84 is not saved.
static u8 THISCALL save(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= ~0x40u;
  for (int o = 0x48; o <= 0x64; o += 4)
    ((vcallVF)VT(sg, 0x4c))(sg, *(float *)(self + o));
  for (int o = 0x68; o <= 0x78; o += 4)
    ((vcallVU)VT(sg, 0x3c))(sg, *(u32 *)(self + o));
  ((vcallVU)VT(sg, 0x64))(sg, *(u32 *)(self + 0x7c));
  ((vcallVU)VT(sg, 0x3c))(sg, *(u32 *)(self + 0x80));
  ((vcallVU)VT(sg, 0x3c))(sg, *(u32 *)(self + 0x88));
  ((vcallVF)VT(sg, 0x4c))(sg, *(float *)(self + 0x8c));
  return 1;
}
PCREG(5c9180, save);

// 0x5c8fc0 CMachinegunControlGroup::Load(ZLoadGame*), GC map [high]; thiscall, ret 4, returns 1. The mirror of Save:
// load slot 0x50 reads a float into a pointer, slot 0x40 a dword; the list is read as a reference and turned back
// into a geom pointer (database slot 0x58).
static u8 THISCALL load(u8 *self, u8 *lg) {
  *(u32 *)(self + 4) &= ~0x40u;
  for (int o = 0x48; o <= 0x64; o += 4)
    ((vcallVP)VT(lg, 0x50))(lg, self + o);
  for (int o = 0x68; o <= 0x78; o += 4)
    ((vcallVP)VT(lg, 0x40))(lg, self + o);
  u32 ref;
  ((vcallVP)VT(lg, 0x40))(lg, &ref);
  *(u8 **)(self + 0x7c) = ((vcallPU)VT(db(), 0x58))(db(), ref);
  ((vcallVP)VT(lg, 0x40))(lg, self + 0x80);
  ((vcallVP)VT(lg, 0x40))(lg, self + 0x88);
  ((vcallVP)VT(lg, 0x50))(lg, self + 0x8c);
  return 1;
}
PCREG(5c8fc0, load);
