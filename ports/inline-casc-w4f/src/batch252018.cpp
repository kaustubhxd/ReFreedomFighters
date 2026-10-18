// batch252018.cpp - Sonnet-w4f hand ports (lifter rejected: 0x65f070 pop mismatch on 0x63d2f0 whose stack args are pushed before the +0x20 slot call).
#include "ff.h"
extern "C" u32 THISCALL ext_63d2f0_thiscall3(u32, u32, u32) __asm__("ext_63d2f0");

// 0x65f070: stdcall(obj) ret 4, void (eax is junk at return)
extern "C" void STDCALL lifted_65f070(u32 obj) {
  u32 n = G(u32, obj + 0x44);
  if (n == 0) { G(u32, obj + 0x44) = 0; return; }
  u32 i = 0;
  do {
    u32 eng = G(u32, 0x70039c);
    u32 c1 = G(u32, eng + 0x9b);
    u32 r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)c1 + 0x54)))(c1, G(u32, obj + 0x48 + 4 * i));
    if (r != 0) {
      u32 eng2 = G(u32, 0x70039c);
      u32 c2 = G(u32, eng2 + 0x190f);
      u32 x = ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)c2 + 0x20)))(c2);
      ext_63d2f0_thiscall3(x, r, G(u32, obj + 0x58 + 4 * i));
    }
    i++;
  } while (i != G(u32, obj + 0x44));
  G(u32, obj + 0x44) = 0;
}
PCREG(65f070, lifted_65f070);
