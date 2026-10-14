// u69_76.cpp - area 69, group 76 (slice 8). Walks a chain of nodes (flag byte +8, next link +0xc) and writes (word, word) pairs to an output array up to a limit.
// The helper 0x440ce0 (other area, pure: writes three dwords through ECX, one stack arg, ret 4) runs as real code.
#include "ff.h"

extern "C" void THISCALL ext_440ce0(void *out3, u32 arg);   // real code

// 0x444b00, ZROOM::GetStaticCustomDrawGeomsListsRecur(...) (GC map high). thiscall two stack args (out, limit; ret 8), returns the out pointer reached.
// L = three dwords filled by 0x440ce0 from [self+0xb4]: L0 = the current node, L1 = the entry cursor, L2 = its end.
static u32 THISCALL walk444b00(u8 *self, u32 out, u32 limit) {
  u32 L[3];
  ext_440ce0(L, *(u32 *)(self + 0xb4));
  u32 edx = L[1];
  u32 esi = out;
  if (edx == 0)
    return esi;
  u32 ebx = L[2];
  u32 ecx = L[0];
  for (;;) {
    u32 edi = *(u32 *)edx & 0xfffffff8u;
    u32 eax = *(u32 *)(edx + 4) & 0xfffffff8u;
    edx += 8;
    if (limit <= esi)
      return esi;
    *(u32 *)esi = edi;
    *(u32 *)(esi + 4) = eax;
    esi += 8;
    if (edx == ebx) {
      if (ecx == 0)
        return esi;
      for (;;) {
        if ((*(u8 *)(ecx + 8) & 1) == 0)
          return esi;
        ecx = *(u32 *)(ecx + 0xc);
        if (ecx == 0)
          return esi;
        if (*(u8 *)(ecx + 8) >= 2)
          break;
      }
      u8 al = *(u8 *)(ecx + 8);
      edx = ecx + 0xc;
      if (al & 1)
        edx += 4;
      ebx = ecx + (u32)(al + 3) * 4;
    }
    if (edx == 0)
      return esi;
  }
}
PCREG(444b00, walk444b00);
