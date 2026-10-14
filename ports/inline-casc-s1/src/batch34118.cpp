// batch34118.cpp - cascade tier E, batch 34118: 0x4e9200 (build three local transforms and hand them over).
#include "ff.h"

extern "C" void FASTCALL ext_4de4b0(void *out, u32 a, u8 *m);               // ecx = out, edx = a, stack m, ret 4
extern "C" void FASTCALL ext_43e920(void *out, u32 b, u8 *m);               // ecx = out, edx = b, stack m, ret 4
extern "C" void FASTCALL ext_441a60(void *p, u8 *m);                        // ecx = p, edx = m, plain ret
extern "C" void FASTCALL ext_459fc0(void *out, u32 c, u8 *m);               // ecx = out, edx = c, stack m, ret 4
extern "C" void THISCALL ext_4e9280(void *self, void *p1, void *p2, void *p3);   // thiscall ret 0xc
extern "C" void FASTCALL ext_633654(u32 cookie);                            // /GS check

// 0x4e9200, thiscall(a, b, c) ret 0xc: three local blocks o1 = ext_4de4b0(a, this+0x18), o2 = ext_43e920(b, this+0x3c) refined by ext_441a60(o2, this+0x18), o3 = ext_459fc0(c, this+0x18); then ext_4e9280(this, &o1, &o2, &o3) and the /GS check.
static void THISCALL fn4e9200(u8 *self, u32 a, u32 b, u32 c) {
  u8 o1[0x30], o2[0x10], o3[0x10];
  ext_4de4b0(o1, a, self + 0x18);
  ext_43e920(o2, b, self + 0x3c);
  ext_441a60(o2, self + 0x18);
  ext_459fc0(o3, c, self + 0x18);
  ext_4e9280(self, o1, o2, o3);
  ext_633654(0);
}
PCREG(4e9200, fn4e9200);
