#include "ff.h"
extern "C" int THISCALL ext_5307c0(void *,void *,const u16 *,int);
#define LEVELS(o) (*(int *)((o)+0x38))
static u32 THISCALL iterSetPosition(u8 *it, const u16 *pos, int level) {
  *(u16 *)(it + 0xc) = pos[0];
  *(u16 *)(it + 0xe) = pos[1];
  *(u16 *)(it + 0x10) = pos[2];
  if (*(int *)(it + 0x12) != level) {
    *(int *)(it + 0x12) = level;
    u32 L = (u32)LEVELS(*(u8 **)it) - (u32)level;
    if (L) {
      u32 s = (L - 1) & 0x1f;
      *(u32 *)(it + 0x21) = 8u << s;
      *(u32 *)(it + 0x25) = 8u << s;
      *(u32 *)(it + 0x29) = 1u << s;
    } else {
      *(u32 *)(it + 0x21) = 1;
      *(u32 *)(it + 0x25) = 1;
      *(u32 *)(it + 0x29) = 1;
    }
  }
  u8 rec[12];
  if (!ext_5307c0(*(u8 **)it, rec, pos, *(int *)(it + 0x12))) return 0;
  __builtin_memcpy(it + 0x16, rec, 8);
  *(u16 *)(it + 0x1e) = *(u16 *)(rec + 8);
  it[0x20] = rec[0xa];
  return *(u16 *)(it + 0x16);
}
PCREG(531740, iterSetPosition);
