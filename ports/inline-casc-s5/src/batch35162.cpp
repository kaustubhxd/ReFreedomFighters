// batch35162.cpp - cascade s5 batch 35162: 0x4d7ba0 (GUESS write a file header: two magics and two 0x12-byte records, flagging short writes).
#include "ff.h"

typedef u32(THISCALL *w_t)(void *, void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4d7ba0, thiscall, no args, no return value. w = unaligned pointer [this+0x15], h = unaligned dword [this+0x11]. Four writes through w slot 0x18(buf, n, h): the local magic 0x06054b50 (4 bytes),
// this+0x22 (0x12 bytes), the local magic 0x52756e65 (4 bytes), this+0x34 (0x12 bytes). Each result differing from n sets byte this[0x6e] = 1 (w re-read each time).
static void THISCALL fn4d7ba0(u8 *self) {
  u32 magic = 0x6054b50;
  u8 *w = (u8 *)rd32u(self + 0x15);
  if ((*(w_t **)w)[0x18 / 4](w, &magic, 4, rd32u(self + 0x11)) != 4) self[0x6e] = 1;
  w = (u8 *)rd32u(self + 0x15);
  if ((*(w_t **)w)[0x18 / 4](w, self + 0x22, 0x12, rd32u(self + 0x11)) != 0x12) self[0x6e] = 1;
  w = (u8 *)rd32u(self + 0x15);
  magic = 0x52756e65;
  if ((*(w_t **)w)[0x18 / 4](w, &magic, 4, rd32u(self + 0x11)) != 4) self[0x6e] = 1;
  w = (u8 *)rd32u(self + 0x15);
  if ((*(w_t **)w)[0x18 / 4](w, self + 0x34, 0x12, rd32u(self + 0x11)) != 0x12) self[0x6e] = 1;
}
PCREG(4d7ba0, fn4d7ba0);
