// batch240019.cpp - Sonnet-w4a: 0x63379b the CRT main sequence (SEH4 frame, table 0x6dcd08) that runs the program.
#include "ff.h"

extern "C" u32 ext_633d35(u32 mode);                          // cdecl 1 arg (CRT init), al
extern "C" u32 ext_634879(u32 code);                          // crash report
extern "C" u32 ext_633d00();                                  // thread-owner lock (verified), al
extern "C" u32 ext_634e3c(u32 a, u32 b);                      // cdecl 2 args (initterm_e)
extern "C" u32 ext_634e36(u32 a, u32 b);                      // cdecl 2 args (initterm)
extern "C" u32 ext_633e8f(u32 flag);                          // cdecl 1 arg
extern "C" u32 *ext_63486d();                                 // returns &pointer (constant)
extern "C" u32 *ext_634873();
extern "C" u32 ext_633e05(u32 *p);                            // cdecl 1 arg, al
extern "C" void THISCALL ext_634aae(u32 fn);                  // guard-check thunk, ecx = target
extern "C" u32 ext_634e54(u32 p);                             // cdecl 1 arg
extern "C" u32 ext_634994();                                  // startup show window (verified)
extern "C" u32 ext_634e30();                                  // returns the command line pointer
extern "C" u32 STDCALL ext_41c9c0(u32 a, u32 b, u32 c, u32 d);   // WinMain wrapper (verified)
extern "C" u32 ext_6349c7();                                  // al: is the main module's PE image valid
extern "C" u32 STDCALL ext_634d5e(u32 code);                  // exit
extern "C" u32 ext_634e48();                                  // no args
extern "C" u32 ext_633eac(u32 a, u32 b);                      // cdecl 2 args

struct Eh4 {
  Eh4 *next;
  u32 handler;
  u32 xtable;
  s32 level;
};

static u32 fn_63379b() {
  volatile Eh4 reg;
  reg.next = (Eh4 *)seh_head();
  reg.handler = 0x633665;
  reg.xtable = 0x6dcd08 ^ G(u32, 0x6f5630);
  reg.level = -2;
  seh_set_head((volatile SehRecord *)&reg);
  if ((ext_633d35(1) & 0xff) == 0) ext_634879(7);
  u32 bl = 0;
  reg.level = 0;
  u32 locked = ext_633d00() & 0xff;
  for (;;) {                 // 0x6337b3 re-enters through the crash report, which does not return in the exe
    u32 state = G(u32, 0x725490);
    if (state == 1) {
      ext_634879(7);
      continue;
    }
    if (state == 0) {
      G(u32, 0x725490) = 1;
      if (ext_634e3c(0x676a04, 0x676a18) != 0) {
        reg.level = -2;
        seh_set_head((volatile SehRecord *)reg.next);
        return 0xff;
      }
      ext_634e36(0x6764b0, 0x676a00);
      G(u32, 0x725490) = 2;
    } else {
      bl = 1;
    }
    break;
  }
  ext_633e8f(locked);
  u32 *p = ext_63486d();
  if (*p != 0 && (ext_633e05(p) & 0xff)) {
    u32 fn = *p;
    ext_634aae(fn);
    ((u32(STDCALL *)(u32, u32, u32))fn)(0, 2, 0);
  }
  p = ext_634873();
  if (*p != 0 && (ext_633e05(p) & 0xff)) ext_634e54(*p);
  u32 show = ext_634994() & 0xffff;
  u32 cmdline = ext_634e30();
  u32 r = ext_41c9c0(0x400000, 0, cmdline, show);
  if ((ext_6349c7() & 0xff) == 0) ext_634d5e(r);
  if ((bl & 0xff) == 0) ext_634e48();
  ext_633eac(1, 0);
  reg.level = -2;
  seh_set_head((volatile SehRecord *)reg.next);
  return r;
}
PCREG(63379b, fn_63379b);
