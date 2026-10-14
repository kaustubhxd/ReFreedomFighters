// batch997.cpp - residue-11/10 remainder (area 53), batch 997: ZActorIf::ReplaceMove(OpaqueCallParameters_t&), 0x507c60, thiscall, ret 4.
// (Released claim, docs/20-unclaimed-50.md.) Id cells come from 0x5003d0(p->[4], k) (stood in) for k = 0, 1, 2. For k = 0 and k = 1 the byte at
// cell+4 selects: 3 -> the dword at the cell; 4 -> that object's vslot 0x34(); otherwise the debug print (0x111) and the hook (esi / ebx = 0).
// The third cell's dword v: when v <= 0, the debug print (0xe3) and return. Otherwise a global function (0x676414, cdecl) tests four strings
// to choose a mode (1, 2, 3, or 4 / 0); then the object at [this+0x18] runs vslot 0x598(rm+0x44+v), 0x5c4(ebx), 0x5c8(esi), and vslot
// 0x5b4(mode, r5c4, r598, r5c8).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 k);   // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void debugPrint111(u8 *t) {
  (void)t;
  u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x69c8e0u, 0x111u);
  u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
  ((u32(*)(void *, u32, u32))fn)(ch, 0x69c6b0u, 0x69c9b0u);
  void (*hook)() = *(void (**)())0x7003b0;
  if (!hook)
    __asm__ volatile("int3");
  hook();
}

// 0x507c60 ZActorIf::ReplaceMove(OpaqueCallParameters_t&).
static void THISCALL replaceMove(u8 *t, u8 *p) {
  u8 *c1 = (u8 *)ext_5003d0((void *)D(p, 4), 0);
  u32 esi;
  u8 e1 = c1[4];
  if (e1 == 3) {
    esi = D(c1, 0);
  } else if (e1 == 4) {
    esi = vcall<u32>((void *)D(c1, 0), 0x34);
  } else {
    debugPrint111(t);
    esi = 0;
  }
  u8 *c2 = (u8 *)ext_5003d0((void *)D(p, 4), 1u);
  u32 ebx;
  u8 e2 = c2[4];
  if (e2 == 3) {
    ebx = D(c2, 0);
  } else if (e2 == 4) {
    ebx = vcall<u32>((void *)D(c2, 0), 0x34);
  } else {
    debugPrint111(t);
    ebx = 0;
  }
  u32 ev = ebx;
  u8 *c3 = (u8 *)ext_5003d0((void *)D(p, 4), 2u);
  u32 v = D(c3, 0);
  if ((int)v <= 0) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x69cff0u, 0xe3u);
    u32 fn = *(u32 *)(*(u32 *)ch + 0x30);
    ((u32(*)(void *, u32, u32, u32))fn)(ch, 0x69d020u, esi, ebx);
    return;
  }
  u8 *sys = *(u8 **)0x70039c;
  u32 rm44v = D(*(u8 **)(sys + 0x9b), 0x44) + v;
  u32 (*f)(u32, u32) = *(u32 (**)(u32, u32))0x676414;
  u32 mode;
  if (!f(esi, 0x68ac54u))
    mode = 1;
  else if (!f(esi, 0x68ac5cu))
    mode = 2;
  else if (!f(esi, 0x69d064u))
    mode = 3;
  else
    mode = f(esi, 0x69d06cu) == 0 ? 4 : 0;
  u8 *a = (u8 *)D(t, 0x18);
  u32 r598 = vcall<u32>(a, 0x598, rm44v);
  u32 r5c4 = vcall<u32>(a, 0x5c4, ev);
  u32 r5c8 = vcall<u32>(a, 0x5c8, r5c4);
  vcall<void>(a, 0x5b4, mode, r5c4, r598, r5c8);
}
PCREG(507c60, replaceMove);
