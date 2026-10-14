// batch35026.cpp - cascade s5 batch 35026: 0x424850 (GUESS pump the window messages, guarded against re-entry).
#include "ff.h"

typedef u32(STDCALL *peek_t)(void *, u32, u32, u32, u32);
typedef u32(STDCALL *get_t)(void *, u32, u32, u32);
typedef u32(STDCALL *m1_t)(void *);

// 0x424850, thiscall(hwnd) ret 4, returns bool. Re-entry guard byte +0x2241: set -> true at once. Otherwise set it and while PeekMessageA(&msg, hwnd, 0, 0, 0) (IAT 0x676220) is non-zero:
// GetMessageA(&msg, hwnd, 0, 0) (IAT 0x6761e0) == 0 returns false (guard stays set); TranslateMessageA (0x6761dc) and DispatchMessageA (0x67624c) on &msg. Guard cleared at the end, returns true.
static u8 THISCALL fn424850(u8 *self, u32 hwnd) {
  u8 msg[0x1c];
  if (self[0x2241]) return 1;
  self[0x2241] = 1;
  while ((*(peek_t *)0x676220)(msg, hwnd, 0, 0, 0)) {
    if (!(*(get_t *)0x6761e0)(msg, hwnd, 0, 0)) return 0;
    (*(m1_t *)0x6761dc)(msg);
    (*(m1_t *)0x67624c)(msg);
  }
  self[0x2241] = 0;
  return 1;
}
PCREG(424850, fn424850);
