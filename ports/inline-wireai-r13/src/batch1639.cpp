// batch1639.cpp - ZItemTemplateAmmo scalar deleting destructor (0x46a990, residue 13, 2026-10-12).
// Sets the item's vtable to the ZItemTemplateAmmo table, frees the 4-byte block at +0x98, sets the base vtable, calls the
// member at +0x70 through its slot 0 with flag 1 (when set), runs the base destructor (0x43ea20), then, when the flag
// (argument) has bit 0: frees the object (ZGEOM operator delete 0x45c510) or, with bit 2, calls 0x4690b0 (name map says
// ZRenderGC::SetState, low confidence; GUESS: a guard thunk) with 0xa4. Returns the object pointer.
// The vtable values 0x68796c and 0x6868e8 are the exe's constants at these two stores.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[];  // __builtin_delete (cdecl: pointer, size)
extern "C" char ext_43ea20[];  // base destructor (thiscall)
extern "C" char ext_45c510[];  // ZGEOM::operator delete (cdecl: object)
extern "C" char ext_4690b0[];  // GUESS: guard/SetState thunk (cdecl: object, 0xa4)
typedef void(__attribute__((cdecl)) *DeleteFn)(void *p, u32 size);
typedef void(__attribute__((cdecl)) *Free1Fn)(void *p);
typedef void(__attribute__((cdecl)) *Guard2Fn)(void *p, u32 n);

u32 THISCALL ZItemTemplateAmmo_DeletingDtor(u8 *self, u32 flag) {
  AT(u32, self, 0) = 0x68796c;
  ((DeleteFn)(void *)ext_634273)(AT(void *, self, 0x98), 4);
  void *member = AT(void *, self, 0x70);
  AT(u32, self, 0) = 0x6868e8;
  if (member) vcall<void>(member, 0, (u32)1);
  ((void(THISCALL *)(void *))(void *)ext_43ea20)(self);
  if (flag & 1) {
    if (flag & 4)
      ((Guard2Fn)(void *)ext_4690b0)(self, 0xa4);
    else
      ((Free1Fn)(void *)ext_45c510)(self);
  }
  return (u32)self;
}
PCREG(46a990, ZItemTemplateAmmo_DeletingDtor);
