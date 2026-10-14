// batch37106.cpp - cascade s6 batch 37106: 0x60d990.
#include "ff.h"

typedef s32(STDCALL *probe_t)(void *, u32, u32, u32, u32, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd2_t)(void *, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void logIfVerbose(u32 line, u32 msg) {
  u8 *g = *(u8 **)(*(u8 **)0x70039c + 0x1aa3);
  if (g[0x76]) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6bcb80, line);
    (*(cd2_t **)L)[0x2c / 4](L, msg);
  }
}

// 0x60d990, thiscall(out) ret 4, returns out: probes which of 14 channels (2..15) the device at 0x724b38 accepts for this object's two ids (+0x13e3, +0x1383), building
// out[1] as a bit mask (bit n-1 per accepted channel n) and out[0] with bit 1 set when any was accepted; then adds feature bits 1 / 8 / 4 / 0x10 for the +0x12c7 flag, the
// state object's slots 0x28 / 0x20 and the +0x12e3 flag, each logging a line (0x510 / 0x515 / 0x519 / 0x51e) when the engine's verbose byte is set.
static u32 *THISCALL fn60d990(u8 *self, u32 *out) {
  u32 edi = 0, ebx = 0;
  for (u32 n = 2; n < 0x10; n++) {
    u8 *dev = *(u8 **)0x724b38;
    s32 r = (*(probe_t *)(*(u8 **)dev + 0x2c))(dev, D32(self, 0x13e3), 1, D32(self, 0x1383), 0, n);
    if (r >= 0) {
      edi |= 2;
      ebx |= 1u << (n - 1);
    }
  }
  if (D32(self, 0x12c7) & 0x20000) {
    logIfVerbose(0x510, 0x6bd358);
    edi |= 1;
  }
  if ((u8)vcall<u32>(*(void **)(self + 0x13e7), 0x28)) {
    logIfVerbose(0x515, 0x6bd36c);
    edi |= 8;
  }
  if ((u8)vcall<u32>(*(void **)(self + 0x13e7), 0x20)) {
    logIfVerbose(0x519, 0x6bd37c);
    edi |= 4;
  }
  if (D32(self, 0x12e3) & 0x20000) {
    logIfVerbose(0x51e, 0x6bd38c);
    edi |= 0x10;
  }
  out[0] = edi;
  out[1] = ebx;
  return out;
}
PCREG(60d990, fn60d990);
