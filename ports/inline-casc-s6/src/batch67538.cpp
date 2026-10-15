// batch67538.cpp - cascade s6 batch 67538: 0x64d030.
#include "ff.h"

extern "C" void THISCALL ext_63e850(u8 *mgr, u8 *obj);               // ret 4
extern "C" u8 *THISCALL ext_63f0e0(u8 *mgr, u8 *owner, u8 *rec);     // ret 8
extern "C" void THISCALL ext_64c040(u8 *self, u8 *s);                // ret 4
extern "C" void THISCALL ext_64c090(u8 *self, u8 *s);                // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define D16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// 0x64d030, thiscall(owner, rec, forceAlloc, mark) ret 0x10, returns the slot record (0 on failure): finds or creates the slot record for rec in the 4096-entry table at this[0x10071] (key = word
// rec[0x5a] & 0xfff). An existing record only gets its object (record[8]) registered with the manager this[0x1005d] (0x63e850) when its flag bit 1 (+5) is clear. Otherwise a record comes from the
// factory this[0x10159] (slot 8); when forceAlloc is zero and rec[0x54]'s slot 0xe4 says no it skips the manager's allocation (slot 8 of mgr[0x234] -> record[0xc]); the manager (0x63f0e0) then builds the object; on failure everything is
// released again (mgr[0x234] slot 0xc, factory slot 0xc) and 0 is returned. Success stores the owner's +0x20, the object, the flags (+5 |= 4 for mark, |= 0x40 propagated to owner) and registers it (0x64c040 + table entry).
// The record is finally stamped (+0x10 = sys[0x3c]) and linked into the owner's list (+0x18), and unless flag bit 1 is set 0x64c090 is called.
static u8 *THISCALL fn64d030(u8 *self, u8 *owner, u8 *rec, u32 forceAlloc, u32 mark) {
  u8 *mgr = *(u8 **)(self + 0x1005d);
  u8 *s = *(u8 **)(*(u8 **)(self + 0x10071) + (D16(rec, 0x5a) & 0xfff) * 4);
  if (s) {
    u8 *o = *(u8 **)(s + 8);
    if (!(o[5] & 1)) ext_63e850(mgr, o);
  } else {
    u8 *fac = *(u8 **)(self + 0x10159);
    s = vcall<u8 *>(fac, 8);
    if (!s) return 0;
    bool alloc = true;
    if (!(u8)forceAlloc) alloc = (u8)vcall<u32>(*(u8 **)(rec + 0x54), 0xe4) != 0;
    bool ok = true;
    if (alloc) {
      u8 *x = vcall<u8 *>(*(u8 **)(mgr + 0x234), 8);
      D32(s, 0xc) = (u32)x;
      if (!x) ok = false;
    }
    u8 *e = 0;
    if (ok) {
      e = ext_63f0e0(*(u8 **)(self + 0x1005d), *(u8 **)(owner + 8), rec);
      if (!e) {
        u32 y = D32(s, 0xc);
        if (y) vcall<void>(*(u8 **)(*(u8 **)(self + 0x1005d) + 0x234), 0xc, y);
        ok = false;
      }
    }
    if (!ok) {
      vcall<void>(*(u8 **)(self + 0x10159), 0xc, (u32)s);
      return 0;
    }
    D32(s, 0x20) = D32(owner, 0x20);
    D32(s, 8) = (u32)e;
    if ((u8)mark) s[5] |= 4;
    if (e[5] & 0x40) {
      s[5] |= 0x40;
      owner[5] |= 0x40;
    }
    ext_64c040(self, s);
    D32(*(u8 **)(self + 0x10071), (D16(rec, 0x5a) & 0xfff) * 4) = (u32)s;
  }
  D32(s, 0x10) = D32(*(u8 **)0x70039c, 0x3c);
  D32(s, 0x18) = D32(owner, 0x18);
  D32(owner, 0x18) = (u32)s;
  if (!(s[5] & 1)) ext_64c090(self, s);
  return s;
}
PCREG(64d030, fn64d030);
