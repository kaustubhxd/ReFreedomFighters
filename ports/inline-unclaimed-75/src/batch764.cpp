// batch764.cpp - residue 17 big entries (docs/20-unclaimed-78b.md), built in the area 75 folder.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 w);   // original accessor, one stack word, ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);  // original setter, one stack word, ret 4 (stores a)

typedef u32(THISCALL *VNone)(u8 *);   // vt[0x358]: no stack words

// 0x519610, thiscall(arg) ret 4 (GUESS name). r = [this+0x14]->vt[0x358]() ; p = 5003d0(ecx = [arg+8], 0) ;
// 5002f0(ecx = p, r). Name GUESS.
static void THISCALL setFromVtResult_519610(u8 *self, u8 *arg) {
  u8 *obj = *(u8 **)(self + 0x14);
  VNone f = (VNone)(*(u32 *)(*(u32 *)obj + 0x358));
  u32 r = f(obj);
  u8 *p = ext_5003d0(*(u8 **)(arg + 8), 0u);
  ext_5002f0(p, r);
}
PCREG(519610, setFromVtResult_519610);
