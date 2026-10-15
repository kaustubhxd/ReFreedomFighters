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

