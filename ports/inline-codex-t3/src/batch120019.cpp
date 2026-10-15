#include "ff.h"
extern "C" u32 THISCALL ext_532420(void *,u32,const u16 *);
extern "C" u32 THISCALL ext_52e320(void *,const s16 *);
extern "C" u32 THISCALL ext_531070(void *,const s16 *);
extern "C" u32 THISCALL ext_530a40(void *);
extern "C" void THISCALL ext_52d250(void *,u32,u32);
#define DIRS ((const s16 *)0x6e9004)
static u32 THISCALL visitNeighbor(u8 *self, u32 from, u8 *it, u32 dir, float, const u16 *x) {
  if (dir == 10) return ext_532420(self, from, x);
  u16 id;
  if (dir == 11) id = *(u16 *)(it + 0x16);
  else if (it[0x20] == 3) id = (u16)ext_52e320(it, DIRS + dir * 3);
  else id = (u16)ext_531070(it, DIRS + dir * 3);
  if (!id) return 0;
  u16 idx = (u16)ext_530a40(it);
  if (!idx) return 0xffff;
  u8 *base = *(u8 **)(self + 0x98);
  u8 *n = base + idx * 0x15;
  float f = *(float *)(base + (u16)from * 0x15 + 0xa) + 1.0001f;   // 0x6a1584
  if (*(float *)(n + 0xa) > f + 0.1f) {                             // 0x67a284
    n[0x14] &= 0xfe;
    *(u16 *)(n + 0xe) = (u16)from;
    *(float *)(n + 0xa) = f;
    *(u16 *)n = *(u16 *)(it + 0x16);
    *(u16 *)(n + 4) = *(u16 *)(it + 0x18);
    *(u16 *)(n + 6) = *(u16 *)(it + 0x1a);
    *(u16 *)(n + 8) = *(u16 *)(it + 0x1c);
    ext_52d250(self, from, idx);
  }
  return 1;
}
PCREG(531b40, visitNeighbor);
