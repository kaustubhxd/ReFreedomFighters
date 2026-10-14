// batch3016.cpp - unclaimed-30: batch 16 (docs/20-unclaimed-30.md, claim 1). Unnamed in the name map: 0x558b50 [stdcall, ret 4].
// The argument's array (+4, exe 0x5003d0) gives elements 2, 1 and 0; their first floats form a vector (x0, x1, x2) = (e0, e1, e2).
// The exe builds a second vector with 0x4de7a0 (exe), then the message table's collision object gets slot 0x238 with
// (that vector, the first vector, (10, 10, 10), 0x7f7f8f, 0).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe code: element pointer (ret 4)
extern "C" void THISCALL ext_4de7a0(float *v);            // exe code: vector set-up (ret 0)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

STDCALL static void unnamed558b50(u8 *arg) {
  u8 *e2 = ext_5003d0(rdp(arg + 4), 2);
  u8 *e1 = ext_5003d0(rdp(arg + 4), 1);
  u8 *e0 = ext_5003d0(rdp(arg + 4), 0);
  // the exe's temporary is 0x24 bytes (0x4de7a0 writes nine dwords at +0..+0x20) and the vector follows it on the stack
  float buf[12];
  float *v40 = buf;
  float *v1 = buf + 9;
  v1[0] = *(const float *)e0;
  v1[1] = *(const float *)e1;
  v1[2] = *(const float *)e2;
  ext_4de7a0(v40);
  float ten[3] = {10.0f, 10.0f, 10.0f};
  u8 *eng = G(u8 *, 0x70039c);
  u8 *msg = *(u8 **)(eng + 0x9b);
  u8 *coll = *(u8 **)(msg + 0xadc);
  vcall<void>(coll, 0x238, v40, v1, ten, (u32)0x7f7f8f, (u32)0);
}
PCREG(558b50, unnamed558b50);
