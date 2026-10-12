// batch425.cpp - unclaimed-42 batch 5 (claim 5, residue 1). Names from the GC name map (naming only, never committed).
#include "ff.h"

// Virtual slots (thiscall; the callee pops its own arguments as in the original).
typedef u8 *(THISCALL *VEngine58)(u8 *self, u32 arg);         // engine object slot +0x58, one argument
typedef u8 (THISCALL *VFlag1e0)(u8 *self, u32 arg);            // slot +0x1e0, one argument, bool in AL
typedef void (THISCALL *VList4c)(u8 *self, u32 *out);          // list slot +0x4c: writes the validity flag
typedef u8 *(THISCALL *VList5c)(u8 *self, u32 *out);           // list slot +0x5c: next item, writes the flag
typedef void (THISCALL *VMsg128)(u8 *self, u32 word, u32 zero1, u32 zero2);  // message slot +0x128: (word, 0, 0)

// 0x5c5810, CTargetObtained::SendNotiFyMesssageToGeomsList() (medium): asks the engine for the object at this+0x14e; if it
// accepts flag 0x800001a (slot +0x1e0) it walks the list at +0x18 and, for each item, takes a message object from the
// engine (slot +0x58 with the item) and sends it the word at this+0x14a (slot +0x128 with 0, 0). If the flag is false it
// sends the word to the object itself instead. Thiscall, ret 0.
static void THISCALL targetObtainedSendNotify(u8 *self) {
  u8 *en = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = ((VEngine58)*(u32 *)(*(u8 **)en + 0x58))(en, *(u32 *)(self + 0x14e));
  if (!x) return;
  if (!((VFlag1e0)*(u32 *)(*(u8 **)x + 0x1e0))(x, 0x800001a)) {
    u16 word0 = *(u16 *)(self + 0x14a);
    ((VMsg128)*(u32 *)(*(u8 **)x + 0x128))(x, word0, 0, 0);
    return;
  }
  u8 *list = *(u8 **)(x + 0x18);
  if (!list) return;
  u32 flag = 0;
  ((VList4c)*(u32 *)(*(u8 **)list + 0x4c))(list, &flag);
  u8 *item = ((VList5c)*(u32 *)(*(u8 **)list + 0x5c))(list, &flag);
  while (flag) {
    en = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *msg = ((VEngine58)*(u32 *)(*(u8 **)en + 0x58))(en, (u32)item);
    u16 word = *(u16 *)(self + 0x14a);
    ((VMsg128)*(u32 *)(*(u8 **)msg + 0x128))(msg, word, 0, 0);
    item = ((VList5c)*(u32 *)(*(u8 **)list + 0x5c))(list, &flag);
  }
}
PCREG(5c5810, targetObtainedSendNotify);
