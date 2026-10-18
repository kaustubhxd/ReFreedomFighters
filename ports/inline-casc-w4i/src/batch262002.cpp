// batch262002.cpp - Sonnet-w4i hand ports (lifter cannot take `ebp` as a plain operand here).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" void FASTCALL ext_633654(u32 cookie);
typedef u32 (STDCALL *keyname_t)(u32, char *, u32);
typedef u32 (STDCALL *lasterr_t)(void);

// 0x420fd0 stdcall(dest, code) ret 8: key-name text of a scan code into the string object `dest` (constructor 0x4cbe80(dest, c_str)); returns dest.
// code 0xfd / 0xfe / 0xff select the constants 0x677f98 / 0x677fa0 / 0x677fa8; any other code asks the API at 0x6761a8 for (code << 16, buf, 0x63)
// and uses buf on success, else calls the API at 0x67609c (result unused) and uses the constant 0x677b5a.
extern "C" u32 STDCALL lifted_420fd0(u32 dest, u32 code) {  // @h_420fd0
  char buf[0x68];
  u32 s;
  switch (code) {  // @0_420fd0
    case 0xfd: s = 0x677f98; break;  // @1_420fd0
    case 0xfe: s = 0x677fa0; break;  // @2_420fd0
    case 0xff: s = 0x677fa8; break;  // @3_420fd0
    default:
      if (G(keyname_t, 0x6761a8)(code << 16, buf, 0x63)) {  // @4_420fd0
        s = (u32)buf;  // @5_420fd0
      } else {
        G(lasterr_t, 0x67609c)();  // @6_420fd0
        s = 0x677b5a;  // @7_420fd0
      }
  }
  ext_4cbe80_thiscall2(dest, s);  // @8_420fd0
  ext_633654(G(u32, 0x6f5630));
  return dest;  // @9_420fd0
}
PCREG(420fd0, lifted_420fd0);
