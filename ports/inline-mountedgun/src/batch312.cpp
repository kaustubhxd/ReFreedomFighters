// batch312.cpp - mounted gun tree, batch 312: the small object with vtable 0x6b48f0 that sits in the nest's compilation
// unit (between the FFBackGroundLink registrations and the nest constructor). The namemap calls its two methods
// FFPointer::Save/Load [medium]; both pass the string field at +0x1d to the save/load object (slot 0x68 / 0x6c). Its
// constructor and the vtable-only destructor body are called from FFBackGroundLink (0x580000). Class name: inference.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *vcallVP)(void *self, void *a);

// 0x5c7ed0 constructor (no map name), thiscall, returns this: vtable 0x6b48f0 and five cleared dwords (+4, +9, +0x29,
// +0x2d, +0x31; the PC build is byte-packed).
static u8 *THISCALL ctor(u8 *self) {
  *(u32 *)self = 0x6b48f0u;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 9) = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)(self + 0x2d) = 0;
  *(u32 *)(self + 0x31) = 0;
  return self;
}
PCREG(5c7ed0, ctor);

// 0x5c7f00 destructor body (no map name): only restores vtable 0x6b48f0. thiscall.
static void THISCALL dtor(u8 *self) { *(u32 *)self = 0x6b48f0u; }
PCREG(5c7f00, dtor);

// 0x5c7f10 FFPointer::Load(ZLoadGame*) [medium], vtable slot 1; thiscall, ret 4, al = 1: lg->slot 0x6c(this + 0x1d).
static u8 THISCALL load(u8 *self, u8 *lg) {
  ((vcallVP)VT(lg, 0x6c))(lg, self + 0x1d);
  return 1;
}
PCREG(5c7f10, load);

// 0x5c7f30 FFPointer::Save(ZSaveGame*) [medium], vtable slot 0; thiscall, ret 4, al = 1: sg->slot 0x68(this + 0x1d).
static u8 THISCALL save(u8 *self, u8 *sg) {
  ((vcallVP)VT(sg, 0x68))(sg, self + 0x1d);
  return 1;
}
PCREG(5c7f30, save);
