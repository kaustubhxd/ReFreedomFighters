// batch277.cpp - unclaimed area 67, gap band 0x5e1000-0x601000.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f33d0, thiscall, ret 8 (args a, b): [this+4] = a; [this+8] = a; [this+0xc] = a + b; [this+0x10] = b; byte [this+0x14] = 1.
static void THISCALL setPair33(u8 *selfP, u32 a, u32 b) {
  *(u32 *)(selfP + 4) = a;
  *(u32 *)(selfP + 8) = a;
  *(u32 *)(selfP + 0xc) = a + b;
  *(u32 *)(selfP + 0x10) = b;
  *(u8 *)(selfP + 0x14) = 1;
}
PCREG(5f33d0, setPair33);

// 0x600240, thiscall, ret 4 (argument src): copies three dwords from src into this.
static void THISCALL copyTriple240(u8 *selfP, u32 src) {
  *(u32 *)(selfP + 4) = rdw(src, 4);
  *(u32 *)(selfP + 8) = rdw(src, 8);
  *(u32 *)(selfP + 0) = rdw(src, 0);
}
PCREG(600240, copyTriple240);
