// batch267.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

typedef void (THISCALL *V1)(u8 *self, u32 a);
typedef void (THISCALL *V2)(u8 *self, u32 a, u32 b);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline void wrw(u32 p, u32 off, u32 v) { *(u32 *)(unsigned long)(p + off) = v; }

// 0x4f3360, thiscall, ret 4 (argument a): if the object at +0x1db is set, its slot 0x210 is called with 1; then +0x1db = a.
static void THISCALL replaceAt1db(u8 *selfP, u32 a) {
  u32 self = (u32)(unsigned long)selfP;
  u32 obj = rdw(self, 0x1db);
  if (obj)
    ((V1)rdw(rdw(obj, 0), 0x210))((u8 *)(unsigned long)obj, 1);
  wrw(self, 0x1db, a);
}
PCREG(4f3360, replaceAt1db);

// 0x600820, thiscall, ret 4 (argument obj): obj->slot 0x48(this+0x18, 0x10); obj->slot 0x2c([this+8]); obj->slot 0x2c([this+0xc]).
static void THISCALL callTwoSlots(u8 *selfP, u32 objIn) {
  u32 self = (u32)(unsigned long)selfP;
  u8 *obj = (u8 *)(unsigned long)objIn;
  ((V2)rdw(rdw(objIn, 0), 0x48))(obj, self + 0x18, 0x10);
  ((V1)rdw(rdw(objIn, 0), 0x2c))(obj, rdw(self, 8));
  ((V1)rdw(rdw(objIn, 0), 0x2c))(obj, rdw(self, 0xc));
}
PCREG(600820, callTwoSlots);
