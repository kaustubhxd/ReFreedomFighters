// batch66037.cpp - cascade s4 batch 66037: 0x496530 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *ext_41e290(u32 n);                              // cdecl
extern "C" void *ext_634d10(void *d, u32 v, u32 n);            // cdecl memset thunk
extern "C" void THISCALL ext_496380(void *self, u8 *bits);     // ret 4
extern "C" void THISCALL ext_4d9430(void *self);               // plain ret
extern "C" void ext_4d9590(void *self);                        // cdecl

// 0x496530, thiscall() plain ret (this = t): n = t[0x14][0xc] / 0x70 elements; bytes = (n + 7) >> 3; bits = alloc(bytes) filled with 0xff, the last byte masked to the (n & 7) valid bits; 0x496380(t, bits) (may clear bits).
// For byte i < bytes (offset i * 0x380 into the element array t[0x14][4]) with a non-zero snapshot: for bit b = 1, 2, 4, ..., 0x80 and element p (0x70 apart): bit set in the snapshot -> bits[i >> 3] &= ~b; p[0x3c] & 0xc000000 clear -> 0x4d9430(p), 0x4d9590(p).
static void THISCALL fn496530(u8 *t) {
  u32 n = rd(*(u8 **)(t + 0x14) + 0xc) / 0x70;
  u32 bytes = (n + 7) >> 3;
  u8 *bits = ext_41e290(bytes);
  ext_634d10(bits, 0xff, bytes);
  if (n & 7) bits[bytes - 1] = (u8)((1 << (n & 7)) - 1);
  ext_496380(t, bits);
  u32 off = 0;
  for (u32 i = 0; i != bytes; i++) {
    u32 snap = bits[i];
    if (snap) {
      u8 *p = *(u8 **)(*(u8 **)(t + 0x14) + 4) + off;
      for (u32 b = 1; b <= 0x80; b += b) {
        if (snap & b) {
          bits[i >> 3] &= (u8)~b;
          if (!(rd(p + 0x3c) & 0xc000000)) {
            ext_4d9430(p);
            ext_4d9590(p);
          }
        }
        p += 0x70;
      }
    }
    off += 0x380;
  }
}
PCREG(496530, fn496530);
