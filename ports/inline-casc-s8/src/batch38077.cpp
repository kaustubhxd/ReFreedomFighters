// batch38077.cpp - cascade s8 batch 38077: 0x639510 (process an image in 4x4 blocks: gather with edge clamping, transform, store, pass the result to the owner).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);                                        // operator new (cdecl)
extern "C" void ext_634273(void *p, u32 size);                              // free(ptr, size) (cdecl)
extern "C" void STDCALL ext_6378c0(u32 a, u32 b, u32 *g, u32 *tmp, u32 *out);  // ret 0x14: 4x4 block transform
typedef u32(THISCALL *v6_t)(void *, u32, u32, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

// 0x639510, thiscall(a8, W, H, src) ret 0x10, void. The image is W x H dwords; both sizes are padded to a multiple of 4 for the loop bounds, source reads clamp to the last row / column.
static void THISCALL fn639510(u8 *self, u32 a8, int W, int H, u32 *src) {
  int Hp = (H + 3) & ~3, Wp = (W + 3) & ~3;
  int n = (int)((u32)(Hp * Wp)) >> 2;
  u64 bytes = (u64)(u32)n * 4;
  u32 size = bytes > 0xffffffffull ? 0xffffffffu : (u32)bytes;
  u32 *B = (u32 *)ext_41e290(size);
  int c = 0;
  u32 g[16], tmp[16], out[4];
  for (int y0 = 0; y0 < Hp - 3; y0 += 4) {
    int rowsLeft = H - y0;
    if (Wp - 3 > 0) {
      for (int x0 = 0; x0 < Wp - 3; x0 += 4) {
        int colsLeft = W - x0;
        for (int dy = 0; dy < 4; dy++) {
          int row = dy < rowsLeft ? y0 + dy : H - 1;
          for (int dx = 0; dx < 4; dx++) {
            int col = colsLeft > dx ? x0 + dx : W - 1;
            g[dy * 4 + dx] = src[W * row + col];
          }
        }
        ext_6378c0(0, 0, g, tmp, out);
        for (int k = 0; k < 4; k++) B[c + k] = out[k];
        c += 4;
      }
    }
  }
  SLOT(self, 0x58, v6_t)(self, (u32)B, (u32)n << 2, (u32)W, (u32)H, a8, 1);
  ext_634273(B, 4);
}
PCREG(639510, fn639510);
