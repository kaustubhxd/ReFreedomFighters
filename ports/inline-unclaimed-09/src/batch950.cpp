// batch950.cpp - area 56, claim A9: ZItemTemplate::GetAvailableStates() const (0x46e470). thiscall, no arguments, returns a pointer.
// SEH frame and stack cookie not reproduced (compiler boilerplate). All calls are GUESS recording stubs in the spec.
#include "ff.h"

extern "C" void THISCALL ext_4cbeb0(u8 *l);
extern "C" void THISCALL ext_4cbec0(u8 *l);
extern "C" u8 *ext_41e290(u32 n);                       // cdecl, one argument (allocator)
extern "C" u8 *THISCALL ext_4ccbe0(u8 *self, u32 a, u32 b);

typedef u32(THISCALL *ListCall)(u8 *self, u32 *flag);  // vt+0x4c (begin) and vt+0x5c (next id); the result is the id
typedef void(THISCALL *Call1)(u8 *self, u32 a);        // vt+4 of the result object

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x46e470 (high). Returns the object from 0x4ccbe0 (or 0). The bitmask keeps each id's first use only.
static u8 *THISCALL itemTemplateGetAvailableStates(u8 *self) {
  u8 local[0x90];
  ext_4cbeb0(local);
  u32 mask = 0;
  u8 *p = ext_41e290(0x1c);
  u8 *e = p ? ext_4ccbe0(p, 0x20, 0) : (u8 *)0;
  u8 *list = *(u8 **)(self + 0x70);
  if (list) {
    u32 flag = 0;
    ((ListCall)slot(list, 0x4c))(list, &flag);
    u32 id = ((ListCall)slot(list, 0x5c))(list, &flag);
    while (flag != 0) {
      u32 bit = 1u << (id & 31);
      if (!(mask & bit)) {
        mask |= bit;
        ((Call1)slot(e, 4))(e, id);
      }
      list = *(u8 **)(self + 0x70);
      id = ((ListCall)slot(list, 0x5c))(list, &flag);
    }
  }
  ext_4cbec0(local);
  return e;
}
PCREG(46e470, itemTemplateGetAvailableStates);
