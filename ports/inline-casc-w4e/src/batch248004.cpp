// batch248004.cpp - Sonnet-w4e, hand-written port of 0x4fc460 (doubly linked list teardown; the lifter rejects its prologue).
#include "ff.h"
extern "C" u32 ext_634273_cdecl2(u32, u32) __asm__("ext_634273");
static inline u32 rd32(u32 a) { u32 v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline void wr32(u32 a, u32 v) { __builtin_memcpy((void *)a, &v, 4); }

extern "C" u32 THISCALL lifted_4fc460(u32 ecx_in) {
  u32 esi = ecx_in, eax = 0, edx = 0, ecx = 0;
  if (rd32(esi + 0x48) != 0) {  // @0_4fc460
    do {
      eax = rd32(esi + 0x48);  // @1_4fc460
      if (eax != 0) {  // @2_4fc460
        edx = rd32(eax + 0x10);  // @3_4fc460
        if (rd32(edx + 0x50) == eax) wr32(edx + 0x50, rd32(eax + 0xc));  // @4_4fc460
        edx = rd32(eax + 8);  // @5_4fc460
        ecx = rd32(eax + 0xc);  // @6_4fc460
        if (edx != 0) wr32(edx + 0xc, ecx);  // @7_4fc460
        else { edx = rd32(eax + 0x10); wr32(edx + 0x48, ecx); }  // @8_4fc460
        edx = rd32(eax + 0xc);  // @9_4fc460
        ecx = rd32(eax + 8);  // @10_4fc460
        if (edx != 0) wr32(edx + 8, ecx);  // @11_4fc460
        else { edx = rd32(eax + 0x10); wr32(edx + 0x4c, ecx); }  // @12_4fc460
        eax = ext_634273_cdecl2(eax, 0x15);  // @13_4fc460
      }
    } while (rd32(esi + 0x48) != 0);  // @14_4fc460
  }
  wr32(esi + 0x4c, 0);  // @15_4fc460
  wr32(esi + 0x48, 0);  // @16_4fc460
  wr32(esi + 0x50, 0);  // @17_4fc460
  return eax;  // @18_4fc460
}
PCREG(4fc460, lifted_4fc460);
