// batch5793.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 93: 0x5d3f70 (GUESS name unnamed_5d3f70), thiscall, one stack argument obj
// (ret 4), returns al = 1. Order: tmp = 0; 0x6352f0(this, &tmp) (hooked: writes tmp); this+0x4c = 0x4e5e60(&tmp) (hooked dword reader);
// this+0x50 = 0x4e5e80(&tmp) (hooked float reader); obj->vt[+0x48](this+0x80), (+0x58), (+0x5c), (+0x60), (+0x64); obj->vt[+0x40](this+0x68),
// (+0x6c), (+0x70), (+0x74). The pointers are into this. The callees run as hooked stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotP)(u8 *self, u32 p);

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);  // writes *out, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)
extern "C" float THISCALL ext_4e5e80(u8 *db);  // float reader, original code (hooked in the spec)

// 0x5d3f70, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5d3f70(u8 *self, u8 *obj) {
  u32 tmp = 0;
  ext_6352f0(self, &tmp);
  *(u32 *)(self + 0x4c) = ext_4e5e60((u8 *)&tmp);
  *(float *)(self + 0x50) = ext_4e5e80((u8 *)&tmp);
  ((SlotP)VT(obj)[0x48 / 4])(obj, (u32)(unsigned long)(self + 0x80));
  ((SlotP)VT(obj)[0x48 / 4])(obj, (u32)(unsigned long)(self + 0x58));
  ((SlotP)VT(obj)[0x48 / 4])(obj, (u32)(unsigned long)(self + 0x5c));
  ((SlotP)VT(obj)[0x48 / 4])(obj, (u32)(unsigned long)(self + 0x60));
  ((SlotP)VT(obj)[0x48 / 4])(obj, (u32)(unsigned long)(self + 0x64));
  ((SlotP)VT(obj)[0x40 / 4])(obj, (u32)(unsigned long)(self + 0x68));
  ((SlotP)VT(obj)[0x40 / 4])(obj, (u32)(unsigned long)(self + 0x6c));
  ((SlotP)VT(obj)[0x40 / 4])(obj, (u32)(unsigned long)(self + 0x70));
  ((SlotP)VT(obj)[0x40 / 4])(obj, (u32)(unsigned long)(self + 0x74));
  return 1;
}
PCREG(5d3f70, unnamed5d3f70);
