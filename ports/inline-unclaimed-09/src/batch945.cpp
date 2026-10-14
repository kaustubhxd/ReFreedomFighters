// batch945.cpp - area 56 residue 15, claim A4: ZItemAmmo::CopyDataBlock(DBLK*) (0x46cdf0). thiscall, one stack argument (the
// block), ret 4. The helper calls are unverified (GUESS recording stubs in the spec).
#include "ff.h"

extern "C" void THISCALL ext_43f900(u8 *self, u8 *d);
extern "C" void THISCALL ext_4e12e0(u8 *d, u32 p, u32 n);
extern "C" void THISCALL ext_4e1b30(u8 *d);
extern "C" void THISCALL ext_4e11e0(u8 *d, u32 p, u32 n);

// 0x46cdf0, ZItemAmmo::CopyDataBlock(DBLK*) (high): base copy; 0x4e12e0(d, this+0x60, 1); 0x4e1b30(d); 0x4e11e0(d, this+0x8e, 1); 0x4e1b30(d).
static void THISCALL itemAmmoCopyDataBlock(u8 *self, u8 *d) {
  ext_43f900(self, d);
  ext_4e12e0(d, (u32)(self + 0x60), 1);
  ext_4e1b30(d);
  ext_4e11e0(d, (u32)(self + 0x8e), 1);
  ext_4e1b30(d);
}
PCREG(46cdf0, itemAmmoCopyDataBlock);
