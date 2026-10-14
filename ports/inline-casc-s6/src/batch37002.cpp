// batch37002.cpp - cascade s6 batch 37002: 0x6392e0.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);                 // alloc, cdecl
extern "C" void ext_634273(u8 *p, u32 n);         // free, cdecl
extern "C" void FASTCALL ext_636de0(u32 hasAlpha, u32 four, u32 z0, u32 z1, u32 *blk, u32 *tmp, u32 *out);  // 4x4 block encoder, ecx/edx + 5 stack, ret 0x14
typedef void(THISCALL *v6_t)(void *, u8 *, u32, u32, u32, u32, u32);

// 0x6392e0, thiscall(a8, w, h, src) ret 0x10: encodes the w x h dword pixel image src (stride w) as 4x4 blocks (edges clamped, flag =
// any alpha < 0x80) with 0x636de0 into two dwords each, then hands the buffer to slot 0x58 of this and frees it.
static void THISCALL fn6392e0(u8 *self, u32 a8, s32 w, s32 h, u32 *src) {
  s32 ww = (w + 3) & ~3, hh = (h + 3) & ~3;
  s32 nb = (s32)((u32)hh * (u32)ww) >> 3;
  u64 p4 = (u64)(u32)nb * 4;
  u32 req = (p4 >> 32) ? 0xffffffffu : (u32)p4;
  u32 *out = (u32 *)ext_41e290(req);
  u32 idx = 0;
  s32 rem_y = h;
  for (s32 y = 0; y < hh - 3; y += 4, rem_y -= 4) {
    s32 rem_x = w;
    for (s32 x = 0; x < ww - 3; x += 4, rem_x -= 4) {
      u32 blk[16], tmp[16], res[2];
      u32 flag = 0;
      int n = 0;
      for (s32 dy = 0; dy < 4; dy++) {
        for (s32 dx = 0; dx < 4; dx++) {
          s32 row = dy < rem_y ? y + dy : h - 1;
          s32 col = dx < rem_x ? x + dx : w - 1;
          u32 p = src[w * row + col];
          blk[n++] = p;
          if ((p & 0xff000000) < 0x80000000) flag = 1;
        }
      }
      ext_636de0(flag, 4, 0, 0, blk, tmp, res);
      out[idx] = res[0];
      out[idx + 1] = res[1];
      idx += 2;
    }
  }
  (*(v6_t **)self)[0x58 / 4](self, (u8 *)out, (u32)nb << 2, (u32)w, (u32)h, a8, 1);
  ext_634273((u8 *)out, 4);
}
PCREG(6392e0, fn6392e0);
