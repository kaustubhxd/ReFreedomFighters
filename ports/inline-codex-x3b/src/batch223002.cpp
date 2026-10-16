#include "ff.h"

extern "C" float FASTCALL ext_4e0830(u8 *a, u8 *b);
extern "C" float FASTCALL ext_4e0030(u8 *a, u8 *b);
extern "C" void THISCALL ext_662ab0(u8 *self, float value);
extern "C" void THISCALL ext_662b00(u8 *self, float value);

// 0x662fd0: thiscall(this, source_vec), ret 4.  A vector update is accepted
// only when the fastcall distance helper returns an ordered value above the
// engine tolerance; then the copied vector becomes both the current and
// previous matrix state and primes the embedded easing object.
void THISCALL fn_662fd0(u8 *self, u8 *source_vec) {
  float distance = ext_4e0830(source_vec, self + 4);
  if (!(distance > G(float, 0x67a284))) return; // m4

  *(u32 *)(self + 4) = *(u32 *)(source_vec + 0); // m0
  *(u32 *)(self + 8) = *(u32 *)(source_vec + 4);
  *(u32 *)(self + 0xc) = *(u32 *)(source_vec + 8);
  *(u32 *)(self + 0x1c) = *(u32 *)(self + 4); // m1
  *(u32 *)(self + 0x20) = *(u32 *)(self + 8);
  *(u32 *)(self + 0x24) = *(u32 *)(self + 0xc);
  float blend = ext_4e0030(self + 4, self + 0x10);
  *(u32 *)(self + 0x3c) = 0; // m2
  ext_662ab0(self + 0x34, 0.0f); // m3
  ext_662b00(self + 0x34, blend); // m5
}
PCREG(662fd0, fn_662fd0);
