// batch932.cpp - vehicles thread, batch 932: ZVehicle constructor and deleting destructor.
// The MSVC exception-frame setup (fs:[0] writes) is not reproduced: it is not game state.
#include "ff.h"

extern "C" void THISCALL ext_511cd0(void *base, u32 a, u32 b, u32 c);  // ZMoveOnSpline base ctor (pops 12)
extern "C" void THISCALL ext_512070(void *base);                        // ZMoveOnSpline base dtor
extern "C" void THISCALL ext_4301c0(void *list, u32 end, u32 *item);  // list grow-and-push (pops 8)
extern "C" void __attribute__((cdecl)) ext_45c510(void *obj);            // dealloc (cdecl)
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size);    // operator delete stub (cdecl)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// The message registration: rm->vtbl[0x114](name, 0, file, line) returns a 16-bit id.
static inline u16 regMsg(void *rm, const char *name, u32 line) {
  return vcall<u16>(rm, 0x114, (u32)name, 0u, (u32)0x69ea24, line);
}

// 0x514940 ZVehicle::ZVehicle(ZGEOMCLASSINFO*, const char*, ZBaseGeom*), callee pops 12, returns this.
static u8 *THISCALL vehCtor(u8 *s, u32 info, u32 name, u32 geom) {
  ext_511cd0(s, info, name, geom);
  *(u32 *)s = 0x69e6b8;
  *(u32 *)(s + 0x2c4) = 0;
  *(u32 *)(s + 0x216) = 0;
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  *(u16 *)(s + 0x2ca) = regMsg(rm, (const char *)0x69ea54, 0x18);
  *(u16 *)(s + 0x2cc) = regMsg(rm, (const char *)0x69ea64, 0x19);
  *(u16 *)(s + 0x2ce) = regMsg(rm, (const char *)0x68bd40, 0x1a);
  *(u16 *)(s + 0x2d2) = regMsg(rm, (const char *)0x69ea74, 0x1b);
  *(u16 *)(s + 0x2d4) = regMsg(rm, (const char *)0x69ea80, 0x1c);
  *(u16 *)(s + 0x2d6) = regMsg(rm, (const char *)0x69ea90, 0x1d);
  s[0x21a] = 1;
  *(u32 *)(s + 0x233) = 0;
  *(float *)(s + 0x267) = 3.5f;
  *(u32 *)(s + 0x2af) = 0;
  s[0x2c3] = 0;
  *(u16 *)(s + 0x2c8) = regMsg(rm, (const char *)0x69ea9c, 0x27);
  *(u16 *)(s + 0x2d0) = regMsg(rm, (const char *)0x69eaac, 0x28);
  *(u32 *)(s + 0x2ab) = 0;
  *(u32 *)(s + 0x2a7) = 0;
  u8 *path = *(u8 **)(s + 0x5c);
  if (path)
    *(float *)(path + 0x63) = 4.0f;
  void *rm2 = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 item = vcall<u32>(rm2, 0x4c, (u32)s);
  u32 *lst = (u32 *)(*(u8 **)0x7003b8 + 0x4a0);
  if (lst[1] == lst[2]) {
    ext_4301c0(lst, lst[1], &item);
  } else {
    if (lst[1])
      *(u32 *)lst[1] = item;
    lst[1] += 4;
  }
  return s;
}
PCREG(514940, vehCtor);

// 0x514b90 ZVehicle::~ZVehicle(): base dtor; flag bit 1 deletes the object (no bit 4: dealloc 0x45c510, bit 4:
// the 0x2d8-byte operator delete stub 0x4690b0). Returns this (callee pops 4).
static u8 *THISCALL vehDtor(u8 *s, u32 flags) {
  ext_512070(s);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(s, 0x2d8);
    } else {
      ext_45c510(s);
    }
  }
  return s;
}
PCREG(514b90, vehDtor);
