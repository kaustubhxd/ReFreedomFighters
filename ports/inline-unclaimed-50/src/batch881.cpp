// batch881.cpp - area 50 (residue-09 file row): 0x505090 [43 instr, thiscall, one stack arg (a record), ret 4; GUESS
// "read a key from the record, then call this method's slot 0x50 with the engine's table offset (positive key), or log (key <= 0);
// then pass the result to 0x5002f0 on the object of the record's +8 accessor"]. The exe's stack layout is kept: the slot 0x50 method
// takes six words (ret 0x18), the log call takes (fmt, key) (ret 8). SEH frame not used here (no fs: access).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_5003d0(void *obj, u32 idx);            // accessor (stood in by the harness)
extern "C" void STDCALL ext_5057e0(u32 fmt, u32 v);                // log (stood in); exe pushes v then fmt, callee cleans
extern "C" u32 THISCALL ext_5002f0(void *obj, u32 v);              // method (stood in); ret 4

// 0x505090 (name GUESS).
static u32 THISCALL Fn505090(u8 *self, u8 *a) {
  u32 key = *(u32 *)ext_5003d0(FP(a, 4), 0);
  u32 v;
  if ((s32)key > 0) {
    u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
    u32 idx = U32(mgr, 0x44) + key;
    v = vcall<u32>(self, 0x50, idx, 0u, 0u, 0xbf800000u, 0u, 0x3f800000u);
  } else {
    ext_5057e0(0x69ce38u, key);
    v = 0;
  }
  u8 *w = ext_5003d0(FP(a, 8), 0);
  return ext_5002f0(w, v);
}
PCREG(505090, Fn505090);
