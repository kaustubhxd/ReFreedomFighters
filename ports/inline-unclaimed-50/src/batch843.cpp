// batch843.cpp - area 50 (residue-10 list): ZDamageBox::Init2() [high, vt 3]. The damage box owner (+0x48) has a manager
// (+0x18) that lists entries: vt +0x4c starts the list, vt +0x5c(&valid) gives the next entry (valid = 0 at the end). For
// each entry the global manager ([0x70039c]+0x9b, vt +0x58) gives its object; objects with +0x54 set get their centre
// (ZBaseGeom::GetCen of +8) passed to vt +0x84, and a 13-byte record (entry, object, a flag from vt +0x1e0(0x2003e8)) is
// queued into this->+0x84 (vt +4). Allocation is operator new(0xd) (cdecl).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *ext_41e290(u32 size);                                  // operator new (cdecl)
extern "C" void THISCALL ext_4daf90(void *geom, float *centre);         // ZBaseGeom::GetCen (not ported here)

static void THISCALL Init2(u8 *self) {
  void *mgr = FP(FP(self, 0x48), 0x18);
  if (!mgr) return;
  u32 valid = 0;
  vcall<void>(mgr, 0x4c, &valid);
  void *ebx = vcall<void *>(FP(FP(self, 0x48), 0x18), 0x5c, &valid);
  if (!valid) return;
  do {
    u8 *edi = (u8 *)vcall<void *>(FP(G(void *, 0x70039c), 0x9b), 0x58, ebx);
    if (F32(edi, 0x54) != 0) {
      float c[3];
      ext_4daf90(FP(edi, 8), c);
      vcall<void>(edi, 0x84, c);
      u8 *rec = (u8 *)ext_41e290(0xd);
      F32(rec, 9) = 0;
      FP(rec, 0) = ebx;
      FP(rec, 4) = vcall<void *>(FP(G(void *, 0x70039c), 0x9b), 0x58, ebx);
      F8(rec, 8) = (vcall<u32>(edi, 0x1e0, 0x2003e8u) != 0) ? 1 : 0;
      vcall<void>(FP(self, 0x84), 4, rec);
    }
    ebx = vcall<void *>(FP(FP(self, 0x48), 0x18), 0x5c, &valid);
  } while (valid);
}
PCREG(5db2e0, Init2);
