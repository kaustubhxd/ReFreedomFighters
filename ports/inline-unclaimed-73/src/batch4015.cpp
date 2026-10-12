// batch4015.cpp - area 73 batch 15 (gap band, GUESS names): FUN_4fa710, FUN_4f4e00, FUN_4f9340, FUN_4fa610, FUN_4e6810.
#include "ff.h"

// 0x634273: operator delete (cdecl, pointer and size; original code, hooked in the spec).
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x4fa710 (GUESS FUN_4fa710): dword store of the argument at this+0x8f; ret 4.
static void THISCALL guess4fa710(u8 *self, u32 a) {
  *(u32 *)(self + 0x8f) = a;
}
PCREG(4fa710, guess4fa710);

// 0x4f4e00 (GUESS FUN_4f4e00): byte store of the argument at this+0x88; ret 4.
static void THISCALL guess4f4e00(u8 *self, u32 a) {
  self[0x88] = (u8)a;
}
PCREG(4f4e00, guess4f4e00);

// 0x4f9340 (GUESS FUN_4f9340): dword store of the argument at this+0x1d7; ret 4.
static void THISCALL guess4f9340(u8 *self, u32 a) {
  *(u32 *)(self + 0x1d7) = a;
}
PCREG(4f9340, guess4f9340);

// 0x4fa610 (GUESS FUN_4fa610): when [this+0x70] != 0x20, vtable slot +0x2ec on this with the argument 1; plain ret.
static void THISCALL guess4fa610(u8 *self) {
  if (*(u32 *)(self + 0x70) != 0x20u)
    vcall<void>(self, 0x2ec, 1u);
}
PCREG(4fa610, guess4fa610);

// 0x4e6810 (GUESS FUN_4e6810): sets the vtable word to 0x697510; calls ext_634273(this+4 pointer, 4) (cdecl); plain ret.
static void THISCALL guess4e6810(u8 *self) {
  *(u32 *)self = 0x697510u;
  ext_634273(*(void **)(self + 4), 4u);
}
PCREG(4e6810, guess4e6810);
