// batch6308.cpp - unclaimed-63 batch 8 (docs/20-unclaimed-63.md): unnamed function at 0x508220 (GUESS, no GC name).
// Body: f = 0x5003d0(ECX = [P+4], one stack argument 0) returns a pointer; v = [f] * the float at 0x67cd40; obj = [this+0x18];
// obj->vtbl[+0x604](v) (thiscall, one float argument, callee pops 4). Returns with ret 4. 0x5003d0 is original code.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);   // original code, stubbed by the spec

typedef void(THISCALL * callf_fn)(void *, float);

// 0x508220 (GUESS).
static void THISCALL unnamed508220(u8 *self, u8 *p) {
  u32 f = ext_5003d0((void *)*(u32 *)(p + 4), 0);
  float v = *(float *)f * G(float, 0x67cd40);
  void *obj = (void *)*(u32 *)(self + 0x18);
  ((callf_fn)(*(u32 *)(*(u32 *)obj + 0x604)))(obj, v);
}
PCREG(508220, unnamed508220);
