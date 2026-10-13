// batch6256 - ragdoll side (claim 49): ZRagdollContainer::ZRagdollContainer(int count) [0x640d40; thiscall, one stack argument, ret 4, returns this].
// The exe's try frame (fs:[0]) is not reproduced. this[0] = vtable 0x6c2810; this[4] = 1.0; this[8] = 0.2; this[0xc] = 0; byte this[0x10] = 0; this[0x11] = 0;
// this[0x15] = 0; this[0x1d] = 0; this[0x21] = count. An array cookie block of count*0x1df + 4 bytes (new, with overflow -> 0xffffffff): the cookie is count,
// the array at +4 is built by 0x634123 (GUESS stub, five stack arguments: array, 0x1df, count, the element constructor 0x640cc0, the destructor 0x640e80);
// this[0x25] = the array (or 0 when the allocation fails). this[0x29] = 0x640cc0 applied to one new(0x1df) block (or 0). this[0x2d] = a count*4 flag block
// (new, overflow -> 0xffffffff) with every dword zeroed. Finally 0x641a40 (thiscall, this; GUESS stub) runs.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                                                       // operator new (cdecl; exe)
extern "C" void STDCALL ext_634123(void *arr, u32 size, u32 count, u32 ctor, u32 dtor);       // array construction (GUESS stub)
extern "C" u32 THISCALL ext_640cc0(void *obj);                                               // element constructor (GUESS stub)
extern "C" void THISCALL ext_641a40(void *self);                                             // init (GUESS stub)

static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u8 *THISCALL fn640d40(u8 *self, s32 count) {
  wr32u(self, 0x6c2810);
  wr32u(self + 4, 0x3f800000u);
  wr32u(self + 0xc, 0);
  wr32u(self + 8, 0x3e4ccccdu);
  self[0x10] = 0;
  wr32u(self + 0x11, 0);
  wr32u(self + 0x15, 0);
  wr32u(self + 0x1d, 0);
  wr32u(self + 0x21, (u32)count);

  u32 n = (u32)count;
  unsigned long long big = (unsigned long long)n * 0x1df;
  u32 bytes = (big >> 32) ? 0xffffffffu : (u32)big;
  bytes = bytes + 4;
  u8 *arr = 0;
  u8 *blk = (u8 *)ext_41e290(bytes);
  if (blk) {
    wr32u(blk, n);
    arr = blk + 4;
    ext_634123(arr, 0x1df, n, 0x640cc0, 0x640e80);
  }
  wr32u(self + 0x25, (u32)arr);

  u8 *one = (u8 *)ext_41e290(0x1df);
  if (one) wr32u(self + 0x29, ext_640cc0(one));
  else wr32u(self + 0x29, 0);

  unsigned long long fbig = (unsigned long long)n * 4;
  u32 fbytes = (fbig >> 32) ? 0xffffffffu : (u32)fbig;
  u8 *flags = (u8 *)ext_41e290(fbytes);
  wr32u(self + 0x2d, (u32)flags);
  for (s32 i = 0; i < count; i++) wr32u(flags + 4 * (u32)i, 0);

  ext_641a40(self);
  return self;
}
PCREG(640d40, fn640d40);
