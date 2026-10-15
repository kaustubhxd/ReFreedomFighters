// batch66044.cpp - cascade s4 batch 66044: 0x4062e0 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" void ext_634d52(void *p);   // cdecl free
extern "C" void ext_410b90(void *p);   // cdecl release

// 0x4062e0, cdecl(p): p == 0 -> return. Frees the members at +0, +4, +0x14, +0x30, +0x34, +0x38 when set. p[0x78] set: p[8] == 0 -> 0x410b90(p[0x78]) then free; p[8] > 0 -> 0x410b90(p[0x78] + 0x14 * i) for i < p[8] (re-read each time), then free p[0x78]; p[8] < 0 -> free p[0x78].
// p[0x7c] set -> free. Then p[0..0x1f] (0x20 dwords) = 0.
extern "C" void fn4062e0(u8 *p) {
  if (!p) return;
  static const u8 offs[6] = {0, 4, 0x14, 0x30, 0x34, 0x38};
  for (int i = 0; i < 6; i++)
    if (rd(p + offs[i])) ext_634d52((void *)rd(p + offs[i]));
  u32 q = rd(p + 0x78);
  if (q) {
    s32 n = (s32)rd(p + 8);
    if (n == 0) {
      ext_410b90((void *)q);
      ext_634d52((void *)rd(p + 0x78));
    } else {
      s32 i = 0;
      u32 off = 0;
      if (n > 0) {
        do {
          ext_410b90((void *)(off + rd(p + 0x78)));
          i++;
          off += 0x14;
        } while (i < (s32)rd(p + 8));
      }
      ext_634d52((void *)rd(p + 0x78));
    }
  }
  if (rd(p + 0x7c)) ext_634d52((void *)rd(p + 0x7c));
  for (int i = 0; i < 0x20; i++) ((u32 *)p)[i] = 0;
}
PCREG(4062e0, fn4062e0);
