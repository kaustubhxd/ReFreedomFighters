// batch41006.cpp - cascade t2 (Sonnet): tier H float function 0x5b9050.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

extern "C" void FASTCALL ext_633654(u32 cookie);                              // /GS check
extern "C" void THISCALL ext_4db7c0(u8 *self, float *out);                    // thiscall ret 4: out = dwords [self+0x40..0x48]
extern "C" void FASTCALL ext_451890(void *acc, const void *v, float f);       // x87: acc += v * f (ecx = acc, edx = v, stack f, ret 4)

// 0x5b9050, thiscall(acc) ret 4 (/GS frame): it = [this+0x4c] (null -> only the /GS check); it slot 0x4c(&st[3 dwords]); e = it slot 0x5c(&st); while st[0] != 0:
// o = sys[0x9b] slot 0x58(e); o slot 0x78(acc); 0x4db7c0([o+8], &v); f = v[2] * K(0x692b60); 0x451890(acc, this+0xa2, f) (exe code: acc += vec * f); e = [this+0x4c] slot 0x5c(&st).
static void THISCALL fn5b9050(u8 *self, u8 *acc) {
  if (rd32(self + 0x4c)) {
    u32 st[3];
    float v[3];
    vcall<void>((void *)rd32(self + 0x4c), 0x4c, (u32)st);
    u32 e = vcall<u32>((void *)rd32(self + 0x4c), 0x5c, (u32)st);
    if (st[0] != 0) {
      do {
        void *o = vcall<void *>((void *)rd32(G(u8 *, 0x70039c) + 0x9b), 0x58, e);
        vcall<void>(o, 0x78, (u32)acc);
        ext_4db7c0((u8 *)rd32((u8 *)o + 8), v);
        float f = v[2] * G(float, 0x692b60);
        ext_451890(acc, self + 0xa2, f);
        e = vcall<u32>((void *)rd32(self + 0x4c), 0x5c, (u32)st);
      } while (st[0] != 0);
    }
  }
  ext_633654(0);
}
PCREG(5b9050, fn5b9050);
