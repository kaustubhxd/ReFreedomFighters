// batch37047.cpp - cascade s6 batch 37047: 0x421940.
#include "ff.h"

extern "C" void ext_42ac56(u32 a, u32 b, u32 c);   // formatting helper, cdecl
typedef u32 (*hook_t)();
typedef u32(STDCALL *i3_t)(u32, u32, u32);
typedef u32(STDCALL *i1_t)(u32);
typedef u32(STDCALL *i2_t)(u32, u32);
typedef u32(STDCALL *i0_t)();
typedef u32(STDCALL *i7_t)(u32, u32, u32, u32, u32, u32, u32);
typedef u32(STDCALL *i12_t)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
#define IAT(T, a) (*(T *)(a))

static void reportError() {
  char buf[0x200];
  u32 e = IAT(i0_t, 0x67609c)();
  IAT(i7_t, 0x6760ec)(0x1000, 0, e, 0, (u32)buf, 0x200, 0);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x421940, thiscall, no args, returns 1: creates the main window. Looks for the first unused class name (the formatting helper 0x42ac56 builds name i at 0x6e4094 and
// the GetClassInfo import 0x67618c tests the shared name 0x6e4088 until it fails, at most 1000 tries), then registers a window class
// (style 0xab, window proc 0x421b40, 4 extra bytes, instance this+0x9cf, arrow cursor, stock brush 4) and creates a 640x480 window centred on the screen (client size from
// GetSystemMetrics 0x10 / 0x11 halved +/- 0x140 / 0xf0). Failures format the last error and call the assert hook. The window handle is kept at this+0x9db and the window's
// long 0 is set to this.
static u32 THISCALL fn421940(u8 *self) {
  u32 wc[12];
  u32 inst = *(u32 *)(self + 0x9cf);
  u32 i = 0;
  do {
    ext_42ac56(0x6e4094, 0x678440, i);
    wc[0] = 0x30;
    if (!IAT(i3_t, 0x67618c)(inst, 0x6e4088, (u32)wc)) break;
    i++;
  } while (i != 0x3e8);
  s32 sm1 = (s32)IAT(i1_t, 0x6761b4)(0x10);
  s32 half1 = (sm1 - (sm1 >> 31)) >> 1;
  u32 ax = (u32)half1 - 0x140;
  s32 sm2 = (s32)IAT(i1_t, 0x6761b4)(0x11);
  s32 half2 = (sm2 - (sm2 >> 31)) >> 1;
  u32 edi = (u32)half1 + 0x140;
  wc[0] = 0x30;
  wc[1] = 0xab;
  wc[2] = 0x421b40;
  wc[3] = 0;
  wc[4] = 4;
  wc[5] = *(u32 *)(self + 0x9cf);
  wc[6] = 0;
  u32 y0 = (u32)half2 - 0xf0;
  u32 esi = (u32)half2 + 0xf0;
  wc[7] = IAT(i2_t, 0x6761cc)(0, 0x7f00);
  wc[8] = IAT(i1_t, 0x676034)(4);
  wc[9] = 0;
  wc[10] = 0x6e4088;
  wc[11] = 0;
  if ((u16)IAT(i1_t, 0x676188)((u32)wc) == 0) reportError();
  u32 w = IAT(i12_t, 0x676190)(0, 0x6e4088, 0x678448, 0x86000000, ax, y0, edi - ax, esi - y0, 0, 0, *(u32 *)(self + 0x9cf), 0);
  *(u32 *)(self + 0x9db) = w;
  if (w == 0) reportError();
  IAT(i3_t, 0x6761fc)(*(u32 *)(self + 0x9db), 0, (u32)self);
  return 1;
}
PCREG(421940, fn421940);
