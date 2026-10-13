// batch81.cpp - save, load and ReadInput of CCheckInside and ZShotActivate, inline session batch 81:
// CCheckInside::ReadInput (0x4afa50), CopyEventDataBlock (0x4af6c0, a tail jump to ReadInput), Save (0x4afb00),
// Load (0x4af9f0), ZShotActivate::Load (0x4c8e00) and Save (0x4c9080). The DBREAD operators, GetRefTab, REFTAB::Count
// and GetInput are exe code patched by the shared serialisation stubs (decomp-pilot/shared-harness).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8(THISCALL *vcallBS)(void *self, u32 a);          // not used: kept for the bool-returning slots
typedef void(THISCALL *vcallVU)(void *self, u32 a);        // save slot: one value
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);
typedef u8 *(THISCALL *vcallP0)(void *self);
typedef void(THISCALL *vcallVUP)(void *self, u32 name, u32 *out);

extern "C" u32 THISCALL ext_4e5e60(u8 *db);                // DBREAD::operator unsigned int()
extern "C" u16 THISCALL ext_4e5e40(u8 *db);                // DBREAD::operator unsigned short()
extern "C" void THISCALL ext_6352f0(u8 *self, u8 *db);     // ZEventBase::GetInput(DBREAD&)

// 0x4afa50 CCheckInside::ReadInput(DBREAD &db), thiscall, ret 4: two dwords, two words, four flags (non-zero),
// then the render manager's +0x9b object's slot 0x138 object's slot 0x88(0x685a0c, &out) and out to +0x58.
static void THISCALL ciReadInput(u8 *self, u8 *db) {
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  *(u32 *)(self + 0x4c) = ext_4e5e60(db);
  *(u16 *)(self + 0x50) = ext_4e5e40(db);
  *(u16 *)(self + 0x52) = ext_4e5e40(db);
  *(u8 *)(self + 0x54) = ext_4e5e60(db) != 0;
  *(u8 *)(self + 0x55) = ext_4e5e60(db) != 0;
  *(u8 *)(self + 0x56) = ext_4e5e60(db) != 0;
  *(u8 *)(self + 0x57) = ext_4e5e60(db) != 0;
  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u8 *obj = ((vcallP0)VT(o, 0x138))(o);
  u32 out = 0;
  ((vcallVUP)VT(obj, 0x88))(obj, 0x685a0cu, &out);
  *(u32 *)(self + 0x58) = out;
}
PCREG(4afa50, ciReadInput);

// 0x4af6c0 CCheckInside::CopyEventDataBlock(DBREAD&): a tail jump to ReadInput (same arguments and ret 4).
PCREG(4af6c0, ciReadInput);

// 0x4afb00 CCheckInside::Save(ZSaveGame *s), thiscall, ret 4, returns true: clears flag 0x40 in +4, then
// s->slot 0x60(byte +0x5e), s->slot 0x60(byte +0x5f), s->slot 0x3c(dword +0x4c), s->slot 0x3c(dword +0x48).
static u8 THISCALL ciSave(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((vcallVU)VT(s, 0x60))(s, *(u8 *)(self + 0x5e));
  ((vcallVU)VT(s, 0x60))(s, *(u8 *)(self + 0x5f));
  ((vcallVU)VT(s, 0x3c))(s, *(u32 *)(self + 0x4c));
  ((vcallVU)VT(s, 0x3c))(s, *(u32 *)(self + 0x48));
  return 1;
}
PCREG(4afb00, ciSave);

// 0x4af9f0 CCheckInside::Load(ZLoadGame *s), thiscall, ret 4, returns true: clears flag 0x40, reads a DBREAD through
// GetInput into a local and ReadInput, then s->slot 0x68(self+0x5e), s->slot 0x68(self+0x5f), s->slot 0x40(self+0x4c),
// s->slot 0x40(self+0x48).
static u8 THISCALL ciLoad(u8 *self, u8 *s) {
  u32 db = 0;
  *(u32 *)(self + 4) &= ~0x40u;
  ext_6352f0(self, (u8 *)&db);
  ciReadInput(self, (u8 *)&db);
  ((vcallVU)VT(s, 0x68))(s, (u32)(self + 0x5e));
  ((vcallVU)VT(s, 0x68))(s, (u32)(self + 0x5f));
  ((vcallVU)VT(s, 0x40))(s, (u32)(self + 0x4c));
  ((vcallVU)VT(s, 0x40))(s, (u32)(self + 0x48));
  return 1;
}
PCREG(4af9f0, ciLoad);

// 0x4c8e00 ZShotActivate::Load(ZLoadGame *s), thiscall, ret 4, returns true: clears flag 0x40, then s->slot 0x68(+0x58).
static u8 THISCALL saLoad(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((vcallVU)VT(s, 0x68))(s, (u32)(self + 0x58));
  return 1;
}
PCREG(4c8e00, saLoad);

// 0x4c9080 ZShotActivate::Save(ZSaveGame *s), thiscall, ret 4, returns true: clears flag 0x40, then s->slot 0x60(byte +0x58).
static u8 THISCALL saSave(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((vcallVU)VT(s, 0x60))(s, *(u8 *)(self + 0x58));
  return 1;
}
PCREG(4c9080, saSave);
