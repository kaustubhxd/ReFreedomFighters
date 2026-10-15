// batch5704.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 4: CExplode::Load(ZLoadGame*) (0x584680), thiscall, one argument
// (the ZLoadGame), returns al = 1, ret 4. Order: clear bit 0x40 of this+4; 0x6352f0(this, &tmp) (writes tmp); 0x584b40(this,
// &tmp) (reads through the DBREAD readers, which store fields of this); load->vt[+0x40](this+0x5e). The two unverified callees
// 0x6352f0 and 0x584b40 run as ORIGINAL code through ext_; the spec hooks 0x6352f0 and the three readers below 0x584b40.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotLoad)(u8 *self, u32 a);

extern "C" u32 THISCALL ext_6352f0(u8 *self, u32 *out);  // writes *out, original code (hooked in the spec)
extern "C" void THISCALL ext_584b40(u8 *self, u32 *dbread);  // reader sequence, original code (its readers hooked)

// 0x584680, CExplode::Load(ZLoadGame*) (high)
static u8 THISCALL explodeLoad(u8 *self, u8 *load) {
  u32 tmp = 0;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ext_6352f0(self, &tmp);
  ext_584b40(self, &tmp);
  ((SlotLoad)VT(load)[0x40 / 4])(load, (u32)(unsigned long)(self + 0x5e));
  return 1;
}
PCREG(584680, explodeLoad);
