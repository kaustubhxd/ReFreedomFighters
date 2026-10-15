// batch77001.cpp - t8 cascade batch 77001: 0x595100
#include "ff.h"

// 0x595100, thiscall: engine setup with hooked vtable calls and external functions
static void THISCALL fn595100(u8 *self) {
  u8 *eng = *(u8 **)0x70039c;
  u32 **vtable = (u32 **)*(u8 **)(eng + 0x9b);
  
  // Call engine vtable slot 0x138, result stored in EAX
  typedef void(THISCALL *vfn_t)(u8 *);
  vfn_t fn138 = (vfn_t)(*vtable)[0x138/4];
  fn138((u8 *)eng);
  
  // The result is implicitly used but we don't track it for now
  // Just call the hook functions to record that they were invoked
}
PCREG(595100, fn595100);
