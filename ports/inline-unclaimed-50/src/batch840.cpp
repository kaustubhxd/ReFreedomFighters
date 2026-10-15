// batch840.cpp - area 50: 0x55ad10 (138 instructions, no GC name). Copies a three-component value between two typed
// slot records: it reads the three slots (index 2, 1, 0) of the record object at a+4, asks the object at this+0x1c for
// the vector (vt +0x84), then writes the three values into the slots of the record object at a+8, each with type 2
// (a slot with another type than 0 or 2 is a "RAISE_EXCEPTION NO! WRONG TYPE" report, then the engine assert hook).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *obj, u32 index);   // slot accessor: the record for index (not ported here)

// Reports a wrong-type slot. The message is written through the engine logger; then the assert hook runs (or int3).
static void WrongType() {
  void *sink = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x69c8e0, 0x104u);
  typedef void(__attribute__((cdecl)) * pf)(void *, const char *, const char *);
  (*(pf *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x69c6b0, (const char *)0x69c938);
  typedef void (*hook_t)();
  hook_t fp = G(hook_t, 0x7003b0);
  if (fp) fp();
  else __builtin_debugtrap();
}

// Writes value into the slot record r (type must be 0 or 2 already, else WrongType first).
static void Store(void *obj, u32 index, float value) {
  void *r = ext_5003d0(obj, index);
  u8 t = F8(r, 4);
  if (t != 0 && t != 2) WrongType();
  FF(r, 0) = value;
  F8(r, 4) = 2;
}

// The function: this is ecx (the owner); a is the argument (the record pair). Returns nothing (ret 4).
static void THISCALL CopyVec3(u8 *self, u8 *a) {
  void *src = FP(a, 4);
  // the exe fetches the slots in the order 2, 1, 0; the values are then stored as v[0] = slot 0, v[1] = slot 1, v[2] = slot 2
  void *r2 = ext_5003d0(src, 2);
  void *r1 = ext_5003d0(src, 1);
  void *r0 = ext_5003d0(src, 0);
  float v[3];
  v[0] = FF(r0, 0);
  v[1] = FF(r1, 0);
  v[2] = FF(r2, 0);
  vcall<void>(FP(self, 0x1c), 0x84, v);
  void *dst = FP(a, 8);
  Store(dst, 0, v[0]);
  Store(dst, 1, v[1]);
  Store(dst, 2, v[2]);
}
PCREG(55ad10, CopyVec3);
