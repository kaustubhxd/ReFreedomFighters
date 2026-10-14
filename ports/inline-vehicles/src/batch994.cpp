// batch994.cpp - residue-11 (core todo), batch 994: ZFFSearchLightGroup::PutAnimatedGeomsIntoList(tagSPOTINFO*), 0x5c7570, thiscall, ret 4.
// Only one pass of the outer loop (the second would read the buffer as a pointer, and the loop test stops it). R = 0x4db2f0(X+8, 1) with
// X = [a+0x1c] (stood in); p2 = X+4 or the default 0x67c8e8; buf = copy of the string 0x6b4718 (strlen bytes), buf[3..4] = p2[3..4],
// buf[len] = 0 (len >= 0x80 is a fatal path, not taken here). h = R vslot 0x25c(buf, 0). When h is set: id = render manager vslot 0x4c(h);
// [a+0x10] vslot 4(id); this+0x44 vslot 0x130(h, word 0x714348, 0). Otherwise the debug channel prints (cdecl 0x2c(ch, 0x6b4728, a)).
// Then [a+0x10] vslot 4([a]) and this+0x44 vslot 0x12c([a], word 0x714348, 0).
#include "ff.h"

extern "C" u32 THISCALL ext_4db2f0(void *self, u32 a);   // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5c7570 ZFFSearchLightGroup::PutAnimatedGeomsIntoList(tagSPOTINFO*).
static void THISCALL putAnimGeoms(u8 *self, u8 *a) {
  u8 *x = (u8 *)D(a, 0x1c);
  u8 *r = (u8 *)ext_4db2f0((void *)D(x, 8), 1u);
  u32 p2 = D(x, 4) != 0 ? D(x, 4) : 0x67c8e8u;
  const char *src = (const char *)0x6b4718;
  char buf[0x80];
  u32 len = 0;
  while (src[len])
    len++;
  for (u32 k = 0; k < len; k++)
    buf[k] = src[k];
  buf[3] = ((u8 *)p2)[3];
  buf[4] = ((u8 *)p2)[4];
  buf[len] = 0;
  u32 w = *(u16 *)0x714348;
  u32 h = vcall<u32>(r, 0x25c, (u32)buf, 0u);
  if (h != 0) {
    void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
    u32 id = vcall<u32>(rm, 0x4c, h);
    vcall<void>((void *)D(a, 0x10), 4, id);
    vcall<void>((void *)D(self, 0x44), 0x130, h, w, 0u);
  } else {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6b45c0u, 0x25du);
    u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
    // The exe pushes EDI here, which still holds the source string (EDI is reloaded with a only after the print).
    ((u32(*)(void *, u32, u32))fn)(ch, 0x6b4728u, (u32)src);
  }
  vcall<void>((void *)D(a, 0x10), 4, D(a, 0));
  vcall<void>((void *)D(self, 0x44), 0x12c, D(a, 0), w, 0u);
}
PCREG(5c7570, putAnimGeoms);
