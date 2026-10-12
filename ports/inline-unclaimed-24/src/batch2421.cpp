// batch2421.cpp - decomp area 24, batch 2421: GUESS unique-append array (0x5fa440) and its forwarder (0x5f9db0).
// Array struct: data (+0), capacity (+4), count (+8). Search for v: a hit returns its index. A miss with room stores
// v at data[count] and returns the old count. A full array doubles its capacity: operator new (0x41e290) of
// 4*newcap bytes (all ones when the product overflows), copy of the old capacity elements, operator delete (0x41e2c0)
// of the old block, then the store. Both helpers are cdecl.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);  // operator new (cdecl)
extern "C" void ext_41e2c0(void *p);    // operator delete (cdecl)

// 0x5fa440, thiscall, ret 4.
static u32 THISCALL uniqueAppend(u8 *self, u32 v) {
  u32 count = *(u32 *)(self + 8);
  u32 *data = *(u32 **)self;
  for (u32 i = 0; i < count; ++i)
    if (data[i] == v)
      return i;
  u32 cap = *(u32 *)(self + 4);
  if (count >= cap) {
    u32 newcap = cap + cap;
    u64 prod = (u64)newcap * 4u;
    u32 size = (prod >> 32) ? 0xffffffffu : (u32)prod;
    u32 *old = data;
    u32 *nd = (u32 *)ext_41e290(size);
    *(u32 **)self = nd;
    for (u32 k = 0; k < cap; ++k)
      nd[k] = old[k];
    ext_41e2c0(old);
    *(u32 *)(self + 4) = newcap;
    data = nd;
  }
  data[count] = v;
  *(u32 *)(self + 8) = count + 1;
  return count;
}
PCREG(5fa440, uniqueAppend);

// 0x5f9db0 (GUESS owner), thiscall, ret 4: forwards to the array at +4 (the argument is kept).
extern "C" u32 THISCALL ext_5fa440(void *self, u32 v);
static u32 THISCALL uniqueAppendForward(u8 *self, u32 v) {
  return ext_5fa440(*(void **)(self + 4), v);
}
PCREG(5f9db0, uniqueAppendForward);
