// batch240009.cpp - Sonnet-w4a: CRT onexit/atexit start-up (module handle + proc lookup).
#include "ff.h"

extern "C" u32 ext_634d46(u32 a, u32 b, u32 c);                 // import thunk, cdecl 3 args
extern "C" u32 THISCALL ext_634aae(u32 self, u32 a);            // import thunk, ecx = this, callee pops 4
extern "C" u32 ext_6344f2(u32 v);                                // cookie-encode (verified)
extern "C" u32 ext_633f0f(u32 p);                                // cdecl 1 arg
extern "C" u32 ext_634879(u32 code);                             // fatal handler (does not return)

// 0x634432: cdecl(): sets up the encoded callbacks used by the atexit machinery
static u32 fn_634432() {
  ext_634d46(0x7257d8, 0xfa0, 0);
  u32 m = (*(u32(__stdcall **)(u32))0x676060)(0x6c169c);
  if (m == 0) return ext_634879(7);
  typedef u32(__stdcall * gp_t)(u32, u32);
  gp_t gp = *(gp_t *)0x6760b4;
  u32 ebx = gp(m, 0x6c16b8);
  u32 edi = gp(m, 0x6c16d4);
  u32 esi = gp(m, 0x6c16f0);
  if (ebx && edi && esi) {
    G(u32, 0x7257f4) = 0;
    ext_634aae(ebx, 0x7257f0);
    ((u32(*)())ebx)();
    u32 a = ext_6344f2(edi);
    G(u32, 0x7257f8) = a;
    u32 b = ext_6344f2(esi);
    G(u32, 0x7257fc) = b;
  } else {
    u32 r = (*(u32(__stdcall **)(u32, u32, u32, u32))0x676064)(0, 1, 0, 0);
    G(u32, 0x7257f4) = r;
    if (r == 0) return ext_634879(7);
  }
  ext_633f0f(0x63450f);
  return 0;
}
PCREG(634432, fn_634432);
