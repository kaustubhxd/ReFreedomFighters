// f16log.h - the engine's error-report pattern used by several slice 16 functions:
//   t = [0x700390] slot 0x20(file, line) (thiscall, ret 8); t slot 0x2c(t, msg) (cdecl, caller pops 8).
#pragma once
#include "ff.h"
static inline void f16_report(u32 file, u32 line, u32 msg) {
  void *o = G(void *, 0x700390);
  void *t = vcall<void *>(o, 0x20, file, line);
  typedef void (*Rep)(void *, u32);
  (*(Rep *)(*(u8 **)t + 0x2c))(t, msg);
}
static inline void f16_report2(u32 file, u32 line, u32 a, u32 b) {
  void *o = G(void *, 0x700390);
  void *t = vcall<void *>(o, 0x20, file, line);
  typedef void (*Rep)(void *, u32, u32);
  (*(Rep *)(*(u8 **)t + 0x2c))(t, a, b);
}
