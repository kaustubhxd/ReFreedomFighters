// batch50001.cpp - cascade u3, tier H, batch 50001: 0x41eac0 (subtract an amount from a per-unit counter array between two positions).
#include "ff.h"

// 0x41eac0, thiscall(name, pos, amt) ret 0xc: c = [this+0x20]; null -> return. Starts an iteration (c slot 0x4c(&it)) and fetches elements with slot 0x64(&it) until
// _stricmp (IAT 0x676414)([e], name) == 0; no match -> return. Then u = [e+0x10] (unsigned, divisor), [e+8] -= amt, q1 = pos / u, q2 = (pos + amt) / u, arr = [e+0xc]:
// q1 == q2: arr[q1] -= amt; else arr[q1] += pos - u*(q1+1), r = pos - u*q2 + amt, r != 0: arr[q2] -= r, and arr[i] -= u for q1 < i < q2 (unsigned).
// The exe vectorises the last loop (with an overlap check that falls back to the scalar loop); the scalar form is what this port does.
typedef int (*cmp_fn)(u32 a, u32 b);

static void THISCALL fn41eac0(u8 *self, u32 name, u32 pos, u32 amt) {
  u8 *c = *(u8 **)(self + 0x20);
  if (!c) return;
  u32 it[4];
  vcall<void>(c, 0x4c, (u32)it);
  u8 *e = vcall<u8 *>(c, 0x64, (u32)it);
  if (!e) return;
  while (G(cmp_fn, 0x676414)(*(u32 *)e, name) != 0) {
    e = vcall<u8 *>(c, 0x64, (u32)it);
    if (!e) return;
  }
  u32 *pu = (u32 *)(e + 0x10);
  *(u32 *)(e + 8) -= amt;
  u32 q1 = pos / *pu;
  u32 q2 = (pos + amt) / *pu;
  if (q1 == q2) {
    (*(u32 **)(e + 0xc))[q1] -= amt;
    return;
  }
  (*(u32 **)(e + 0xc))[q1] += pos - *pu * (q1 + 1);
  u32 r = pos - *pu * q2 + amt;
  if (r != 0) (*(u32 **)(e + 0xc))[q2] -= r;
  for (u32 i = q1 + 1; i < q2; i++) (*(u32 **)(e + 0xc))[i] -= *pu;
}
PCREG(41eac0, fn41eac0);
