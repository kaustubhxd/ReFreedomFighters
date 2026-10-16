// batch962.cpp - 0x512940 (no name in the map), read in full (2026-10-13). Thiscall (ECX = this), three stack args
// (a, b, c), ret 12, returns eax. Global object at 0x70039c. Main flow: get object's virtual slot [+0x9b], call
// [+0x58] on it (passing a), call [+0x2c4] on result (passing c), store in ebx, call [+0x2c] on ebx, test b
// (conditional move edx from b or ecx), call global's [+0x4c] (passing saved_self, edx), call [+0x2f0] on ebx with
// result, call [+0xbc] on ebx with 0, return ebx.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x512940 (no name in the map).
static void *THISCALL Apply512940(u8 *self, u32 a, u32 b, u32 c) {
  u32 saved_self = (u32)(unsigned long)self;
  
  // Get global at 0x70039c, offset +0x9b
  u32 global_ptr = U32((void *)0x70039c, 0);
  void *global = FP((u8 *)global_ptr, 0x9b);
  
  // Call [+0x58] on global with arg a
  void *result1 = vcall<void *>(global, 0x58, a);
  
  // Call [+0x2c4] on result with arg c
  void *ebx = vcall<void *>(result1, 0x2c4, c);
  
  // Call [+0x2c] on ebx
  vcall<void>(ebx, 0x2c);
  
  // Conditional move: edx = b ? b : saved_self
  u32 edx = b ? b : saved_self;
  
  // Call global's [+0x4c] with (saved_self, edx)
  void *res_4c = vcall<void *>(global, 0x4c, saved_self, edx);
  
  // Call [+0x2f0] on ebx with res_4c
  vcall<void>(ebx, 0x2f0, res_4c);
  
  // Call [+0xbc] on ebx with 0
  vcall<void>(ebx, 0xbc, 0u);
  
  return ebx;
}
PCREG(512940, Apply512940);
