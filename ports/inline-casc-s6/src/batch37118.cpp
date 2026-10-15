// batch37118.cpp - cascade s6 batch 37118: 0x54be40.
#include "ff.h"

extern "C" void FASTCALL ext_54f2b0(u32 a, u32 b);
typedef u32(STDCALL *query_t)(void *, void *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

static void logField(u32 line, u32 fmt, u32 v) {
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6a38e0, line);
  (*(cd3_t **)L)[0x2c / 4](L, fmt, v);
}

// 0x54be40, thiscall(), plain ret: asks the device object at +0xa274 (slot 0x10, called with itself and a 0x60-byte descriptor whose first dword is its size) for something; a
// non-zero answer is handed to 0x54f2b0 (with the string 0x6a3984) and nothing more happens, otherwise eight descriptor fields (+0x50, +0x44, +0x48, +0x4c, +0x24, +0x3c, +0x28,
// +0x34) are logged with their format strings, lines 0x2c2 .. 0x2c9.
static void THISCALL fn54be40(u8 *self) {
  u32 desc[24];
  void *dev = *(void **)(self + 0xa274);
  desc[0] = 0x60;
  u32 r = (*(query_t *)(*(u8 **)dev + 0x10))(dev, desc);
  if (r) {
    ext_54f2b0(r, 0x6a3984);
    return;
  }
  logField(0x2c2, 0x6a3a60, desc[20]);
  logField(0x2c3, 0x6a3a6c, desc[17]);
  logField(0x2c4, 0x6a3a84, desc[18]);
  logField(0x2c5, 0x6a3a90, desc[19]);
  logField(0x2c6, 0x6a3aa4, desc[9]);
  logField(0x2c7, 0x6a3ab0, desc[15]);
  logField(0x2c8, 0x6a3ac0, desc[10]);
  logField(0x2c9, 0x6a3ae0, desc[13]);
}
PCREG(54be40, fn54be40);
