// batch200002.cpp - Sonnet-w2, SEH-framed small functions: vector-storage destructors and a double member-destruct.
#include "ff.h"

extern "C" u32 STDCALL ext_54f870(void *p, u32 bytes);
extern "C" u32 THISCALL ext_4e6b40(void *self);

// 0x606c90 GUESS vector16_free: thiscall. begin=[this], end=[this+8]; n = (end-begin)>>1 (arithmetic); frees begin with 2n bytes unless n==0.
// EH frame state 0 around the call. Returns eax (n when nothing was freed, else the callee's eax).
extern "C" u32 THISCALL vector16_free(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x6684b6;
  reg.state = -1;
  seh_set_head(&reg);
  u8 *begin = *(u8 **)self;
  s32 n = (s32)(*(u32 *)(self + 8) - (u32)begin) >> 1;
  reg.state = 0;
  u32 r = (u32)n;
  if (n != 0) r = ext_54f870(begin, (u32)n + (u32)n);
  seh_set_head(reg.next);
  return r;
}
PCREG(606c90, vector16_free);

// 0x42ba10 GUESS vector_free_bytes: thiscall. begin=[this], diff = [this+8]-begin; frees begin with diff bytes when begin != 0 and diff != 0.
extern "C" u32 THISCALL vector_free_bytes(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x6684b6;
  reg.state = -1;
  seh_set_head(&reg);
  u8 *begin = *(u8 **)self;
  u32 diff = *(u32 *)(self + 8) - (u32)begin;
  reg.state = 0;
  u32 r = diff;
  if (begin != 0 && diff != 0) r = ext_54f870(begin, diff);
  seh_set_head(reg.next);
  return r;
}
PCREG(42ba10, vector_free_bytes);

// 0x5a5440 GUESS vector32_free: thiscall. n = (end-begin)>>2 (arithmetic); frees begin with 4n bytes unless n==0.
extern "C" u32 THISCALL vector32_free(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x6684b6;
  reg.state = -1;
  seh_set_head(&reg);
  u8 *begin = *(u8 **)self;
  s32 n = (s32)(*(u32 *)(self + 8) - (u32)begin) >> 2;
  reg.state = 0;
  u32 r = (u32)n;
  if (n != 0) r = ext_54f870(begin, (u32)n << 2);
  seh_set_head(reg.next);
  return r;
}
PCREG(5a5440, vector32_free);

// 0x4e3f00 GUESS destroy_member_twice: thiscall. Calls 0x4e6b40 on this+4 twice inside an EH frame (state stays -1); returns the second eax. esi is saved.
extern "C" u32 THISCALL destroy_member_twice(u8 *self) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x6656a0;
  reg.state = -1;
  seh_set_head(&reg);
  ext_4e6b40(self + 4);
  u32 r = ext_4e6b40(self + 4);
  seh_set_head(reg.next);
  return r;
}
PCREG(4e3f00, destroy_member_twice);
