// batch421.cpp - unclaimed-42 batch 1 (claim 1, slice floor(addr/16) mod 20 = 1). Names from the GC name map (naming
// only, never committed).
#include "ff.h"

// Base destructor (tail-jumps to a shared base destructor), original code: thiscall, void.
extern "C" void THISCALL ext_43de70(u8 *self);
// CRT-side delete wrapper, cdecl (one stack argument), original code; the harness hooks and logs it.
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);
// Sized delete wrapper, cdecl (pointer, size), original code; the harness hooks and logs it.
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size);

// 0x5a5650, ZFFPRIVATESTDOBJ::~ZFFPRIVATESTDOBJ() scalar deleting destructor (high): runs the base destructor; then, if
// bit 0 of the stack argument is set, deletes this: with bit 2 set it calls the sized delete (size 0x20), otherwise the
// wrapper 0x45c510. Returns this in EAX, ret 4.
static u8 *THISCALL privStdObjDtor(u8 *self, u32 flags) {
  ext_43de70(self);
  u8 f = (u8)flags;
  if (f & 1) {
    if (f & 4) ext_4690b0(self, 0x20);
    else ext_45c510(self);
  }
  return self;
}
PCREG(5a5650, privStdObjDtor);
