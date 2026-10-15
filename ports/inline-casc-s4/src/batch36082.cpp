// batch36082.cpp - cascade s4 batch 36082: 0x425170 (tier F row).
#include "ff.h"

typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(STDCALL *find_t)(u32, u32);
typedef u32(STDCALL *peek_t)(void *, u32, u32, u32, u32);
typedef u32(STDCALL *get_t)(void *, u32, u32, u32);
typedef u32(STDCALL *msg1_t)(void *);
typedef void(STDCALL *sleep_t)(u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x425170, thiscall(wnd) ret 4 (this = t): t[0x20] = wnd; t->slot 6 (0x18)(9, wnd, 0); FindWindowA(0, 0x678640) == 0 -> t[0x10] = 1, return.
// Else up to 200 rounds: while PeekMessageA(&m, wnd, 0, 0, 0): GetMessageA(&m, wnd, 0, 0) == 0 -> break; TranslateMessage(&m); DispatchMessageA(&m);
// after the pump: t[0x24] != 0 -> leave; else Sleep(5). Finally t[0x10] = 1.
static void THISCALL fn425170(u8 *t, u32 wnd) {
  u32 m[8];
  wr(t + 0x20, wnd);
  (*(v3_t **)t)[0x18 / 4](t, 9, wnd, 0);
  if (!G(find_t, 0x676224)(0, 0x678640)) {
    t[0x10] = 1;
    return;
  }
  for (s32 k = 0; k < 0xc8;) {
    while (G(peek_t, 0x676220)(m, wnd, 0, 0, 0)) {
      if (!G(get_t, 0x6761e0)(m, wnd, 0, 0)) break;
      G(msg1_t, 0x6761dc)(m);
      G(msg1_t, 0x67624c)(m);
    }
    if (rd(t + 0x24)) break;
    G(sleep_t, 0x6760e4)(5);
    k++;
  }
  t[0x10] = 1;
}
PCREG(425170, fn425170);
