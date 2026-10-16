// batch1637.cpp - BasicShape::Save (0x460c10) and ZItemAmmo::Save (0x470610) (residue 13, 2026-10-12).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[];   // __builtin_delete (cdecl: pointer, size)
extern "C" char ext_4705a0[];   // ZItem::Save (thiscall: ECX = item, one stack argument: the save game)
typedef void(__attribute__((cdecl)) *DeleteFn)(void *p, u32 size);
typedef u8(THISCALL *ItemSaveFn)(void *self, void *save);

// 0x460c10 BasicShape::Save(ZSaveGame*) [medium]: frees the shape's 0x38-byte sub-object at +0xc (when set) and returns 1.
u8 THISCALL BasicShape_Save(u8 *self, void *save) {
  (void)save;
  void *p = AT(void *, self, 0xc);
  if (p) ((DeleteFn)(void *)ext_634273)(p, 0x38);
  return 1;
}
PCREG(460c10, BasicShape_Save);

// 0x470610 ZItemAmmo::Save(ZSaveGame*) [high]: ZItem::Save first; when it succeeds, the save game's +0x44 slot gets the
// ammo count (the dword at +0x8e). Returns 1 on success, 0 when ZItem::Save failed (nothing more is written).
u8 THISCALL ZItemAmmo_Save(u8 *self, void *save) {
  if (!((ItemSaveFn)(void *)ext_4705a0)(self, save)) return 0;
  vcall<void>(save, 0x44, AT(u32, self, 0x8e));
  return 1;
}
PCREG(470610, ZItemAmmo_Save);
