// batch32124.cpp - cascade h2 (): two tier H functions.
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);                         // /GS check
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);             // thiscall ret 8
extern "C" void THISCALL ext_4690b0(u8 *self);                           // thiscall, plain ret

// 0x43ed70, thiscall(v, a, b, c) ret 0x10, returns r (/GS frame): r = slot 0x294 of this with (c, 0x67c5b8, 1, 1); buf = v[0..2]; slot 0x220 of r with (&buf, a, b); 0x4dc630([r+8], 0, 3);
// slot 0x224 of r with 1; 0x4690b0([r+8]); /GS check; returns r.
static u8 *THISCALL fn43ed70(u8 *self, float *v, u32 a, u32 b, u32 c) {
  float buf[3];
  u8 *r = vcall<u8 *>(self, 0x294, c, 0x67c5b8u, 1u, 1u);
  buf[0] = v[0]; buf[1] = v[1]; buf[2] = v[2];
  vcall<void>(r, 0x220, (u32)buf, a, b);
  ext_4dc630(*(u8 **)(r + 8), 0, 3);
  vcall<void>(r, 0x224, 1u);
  ext_4690b0(*(u8 **)(r + 8));
  ext_633654(0);
  return r;
}
PCREG(43ed70, fn43ed70);

// 0x63eca0, thiscall(out) ret 4, returns the count: it = slot 0xc of the object embedded at this+0x1c8 with a scratch pointer (an iterator record {node, index, chunk});
// node == 0 -> 0; otherwise a walk over chunked pointer arrays: out[n++] = [[node] + 0x38]; the index is incremented first, when it equals the chunk's count [chunk] the walk moves to the next chunk [chunk+8]
// (done when it is 0, else index = 0 and node = chunk + 0x10), otherwise node += 4.
static u32 THISCALL fn63eca0(u8 *self, u32 *out) {
  u32 scratch[6];
  u32 *it = vcall<u32 *>(self + 0x1c8, 0xc, (u32)scratch);
  u32 node = it[0];
  u32 idx = it[1];
  u32 chunk = it[2];
  u32 n = 0;
  if (!node) return 0;
  u32 e = idx;
  do {
    e++;
    u32 obj = *(u32 *)node;
    out[n++] = *(u32 *)(obj + 0x38);
    if (e == *(u32 *)chunk) {
      chunk = *(u32 *)(chunk + 8);
      if (!chunk) break;
      e = 0;
      node = chunk + 0x10;
    } else {
      node += 4;
    }
  } while (node);
  return n;
}
PCREG(63eca0, fn63eca0);
