// batch34076.cpp - cascade tier E, batch 34076: 0x5ae680.
#include "ff.h"

extern "C" u32 THISCALL ext_5b1440(void *m, void *a);          // thiscall ret 4, bool in al
extern "C" void THISCALL ext_5ad2b0(void *m, void *a);         // thiscall ret 4
extern "C" void THISCALL ext_5c2c80(void *m);                  // thiscall, plain ret
extern "C" void THISCALL ext_5b1150(void *m, u32 a, u32 b);    // thiscall ret 8
extern "C" void THISCALL ext_5ae710(void *m, u32 a);           // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);               // /GS check

// 0x5ae680, thiscall, plain ret: when ext_5b1440(this+0x4b8, this) is true: a 5-byte record R = {dword [0x6b09f0], byte [0x6b09f4]} with R[2] = this[2] + 1 goes to ext_5ad2b0(this+0x35a, &R), then
// ext_5c2c80(this+0x92); otherwise ext_5ad2b0(this+0x35a, this). When this[3] != 0x52: ext_5b1150(this+0x4b8, 0x6b08c0, 0). Then ext_5ae710(this, 0) and the /GS check.
static void THISCALL fn5ae680(u8 *self) {
  u8 R[8];
  if ((u8)ext_5b1440(self + 0x4b8, self)) {
    u32 d = G(u32, 0x6b09f0);
    R[0] = d; R[1] = d >> 8; R[2] = d >> 16; R[3] = d >> 24;
    R[4] = G(u8, 0x6b09f4);
    R[2] = self[2] + 1;
    ext_5ad2b0(self + 0x35a, R);
    ext_5c2c80(self + 0x92);
  } else {
    ext_5ad2b0(self + 0x35a, self);
  }
  if (self[3] != 0x52) ext_5b1150(self + 0x4b8, 0x6b08c0, 0);
  ext_5ae710(self, 0);
  ext_633654(0);
}
PCREG(5ae680, fn5ae680);
