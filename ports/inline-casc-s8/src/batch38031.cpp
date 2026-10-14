// batch38031.cpp - cascade s8 batch 38031: 0x610ba0 (push the cached render settings to the device).
#include "ff.h"

typedef u32(STDCALL *d3_t)(void *, u32, u32);
typedef u32(STDCALL *d4_t)(void *, u32, u32, u32);
typedef u32(STDCALL *d2_t)(void *, u32);
#define DEV (*(u8 **)(self + 0x1377))
#define SL(off, T) ((T)(*(u8 **)(*(u8 **)DEV + (off))))
#define GV(a) G(u32, a)

// 0x610ba0, thiscall, no args, plain ret. The device pointer (unaligned dword at this+0x1377, re-read before every call) gets the cached state from the global tables: twelve render states
// through slot 0xc8 (state, value), the multi-sample / fill-mode state 0x16 (2 when 0x72494c is set, else 1), then for each of the 0x724a08 stages slot 0xf4 and six slot 0xfc calls
// (types 1..6), and finally slots 0x14c, 0x154, 0x130 and 0x160 with the viewport / clip globals. All device methods are stdcall (device pointer first).
static void THISCALL fn610ba0(u8 *self) {
  static const u32 states[12][2] = {{0x13, 0x724928}, {0x14, 0x72492c}, {0x1b, 0x724934}, {0xe, 0x72493c}, {0x17, 0x724968}, {0x19, 0x72496c},
                                    {0xf, 0x724938}, {0x1c, 0x724930}, {0x22, 0x724950}, {0x24, 0x724960}, {0x25, 0x724964}, {0x89, 0x724948}};
  for (int i = 0; i < 12; i++) SL(0xc8, d3_t)(DEV, states[i][0], GV(states[i][1]));
  SL(0xc8, d3_t)(DEV, 0x16, GV(0x72494c) ? 2 : 1);
  if (GV(0x724a08) != 0) {
    u32 i = 0;
    do {
      SL(0xf4, d3_t)(DEV, i, GV(0x724848 + 4 * i));
      SL(0xfc, d4_t)(DEV, i, 1, GV(0x724868 + 4 * i));
      SL(0xfc, d4_t)(DEV, i, 2, GV(0x724888 + 4 * i));
      SL(0xfc, d4_t)(DEV, i, 3, GV(0x7248a8 + 4 * i));
      SL(0xfc, d4_t)(DEV, i, 4, GV(0x7248c8 + 4 * i));
      SL(0xfc, d4_t)(DEV, i, 5, GV(0x7248e8 + 4 * i));
      SL(0xfc, d4_t)(DEV, i, 6, GV(0x724908 + 4 * i));
      i++;
    } while (i < GV(0x724a08));
  }
  SL(0x14c, d4_t)(DEV, 0, GV(0x724970), GV(0x7249b0));
  SL(0x154, d3_t)(DEV, GV(0x7249f0), GV(0x7249f4));
  SL(0x130, d2_t)(DEV, GV(0x7249f8));
  SL(0x160, d2_t)(DEV, GV(0x7249fc));
}
PCREG(610ba0, fn610ba0);
