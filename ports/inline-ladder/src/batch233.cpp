// batch233.cpp - ZLNKWHANDS class functions (inline-ladder thread, 2026-10-11): ClassInit2, Load2 and two thunks.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_465fd0(void *self);                    // ZIKLNKOBJ::ClassInit2 (batch 225)
extern "C" void THISCALL ext_466d90(void *self);                    // ZIKLNKOBJ::Load2 (batch 223)
extern "C" void THISCALL ext_466040(void *self);                    // ZIKLNKOBJ::ClassInit (batch 229)
extern "C" u32 THISCALL ext_465870(void *self, u32 id);             // ZIKLNKOBJ::BoneAnimIdToCallBack (batch 222)

// 0x472fd0 ZLNKWHANDS::ClassInit2() [GameCube reference, high; vtable slot 0x158], thiscall, plain ret: the base ClassInit2,
// then the hands' inventory list is looked up by name "Inventory" (own slot 0x104) and stored at +0x2e3.
static void THISCALL handsClassInit2(u8 *self) {
  ext_465fd0(self);
  U32(self, 0x2e3) = vcall<u32>(self, 0x104, (const char *)0x689770);
}
PCREG(472fd0, handsClassInit2);

// 0x474710 ZLNKWHANDS::Load2() [GameCube reference, high], thiscall, plain ret: the base Load2, then the same "Inventory" lookup.
static void THISCALL handsLoad2(u8 *self) {
  ext_466d90(self);
  U32(self, 0x2e3) = vcall<u32>(self, 0x104, (const char *)0x689770);
}
PCREG(474710, handsLoad2);

// 0x472ff0: jmp 0x466040, so ZLNKWHANDS::ClassInit is the base ZIKLNKOBJ::ClassInit (batch 229).
static void THISCALL handsClassInit(u8 *self) { ext_466040(self); }
PCREG(472ff0, handsClassInit);

// 0x472450: push ebp / mov / pop ebp / jmp 0x465870, so ZLNKWHANDS::BoneAnimIdToCallBack is the base one (batch 222).
static u32 THISCALL handsBoneAnimIdToCallBack(u8 *self, u32 id) { return ext_465870(self, id); }
PCREG(472450, handsBoneAnimIdToCallBack);
