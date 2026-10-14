// batch38068.cpp - cascade s8 batch 38068: 0x409ac0 (walk a tiled grid of index rows and call a callback for every flagged cell of every plane).
#include "ff.h"

extern "C" u32 ext_401820(u8 *a, u32 size);   // cdecl(2)
extern "C" int ext_405f20(u32 a, u8 *b);      // cdecl(2)
typedef int (*cb_t)(u32, u32, u8 *, int);

// 0x409ac0, cdecl(A, B, out, N, cb) -> 0 always. B[0] = {+0 start, +4 end, +8 stride S, +0x14 + 4*idx flag words}; *B[0x14] = W (tile width); B[0xc] = plane count; B[0x20][idx] = row-index tables;
// B[0x18][idx] = per-plane pointer arrays. N tile buffers P[i] (one pointer per tile row, allocated with 0x401820) are filled on the first plane, then for every cell with the plane's flag bit the callback
// cb(ptr, out[i] + 4*(start + r*S), A+4, S) is called; a -1 from the lookup 0x405f20 or the callback ends the walk.
static int fn409ac0(u8 *A, u8 *B, u8 *out, int N, cb_t cb) {
  u8 *C = *(u8 **)B;
  int W = **(int **)(B + 0x14);
  int S = *(int *)(C + 8);
  int Hn = (*(int *)(C + 4) - *(int *)C) / S;
  int rows = (Hn + W - 1) / W;
  u32 **P = (u32 **)__builtin_alloca((N > 0 ? N : 0) * 4);
  if (N > 0)
    for (int i = 0; i < N; i++) P[i] = (u32 *)ext_401820(A, rows * 4);
  int k = 0;
  if (*(int *)(B + 0xc) > 0) {
    do {
      int r = 0, g = 0;
      if (Hn > 0) {
        do {
          if (k == 0 && N > 0) {
            for (int i = 0; i < N; i++) {
              int idx = ext_405f20(*(u32 *)(B + 0x14), A + 4);
              if (idx == -1) return 0;
              P[i][g] = (*(u32 **)(B + 0x20))[idx];
              if (P[i][g] == 0) return 0;
            }
          }
          if (W > 0) {
            int col = 0;
            do {
              if (r >= Hn) break;
              for (int i = 0; i < N; i++) {
                u32 idx2 = ((u32 *)P[i][g])[col];
                if (*(u32 *)(C + idx2 * 4 + 0x14) & (1u << (k & 31))) {
                  u32 *Q = ((u32 **)*(u8 **)(B + 0x18))[idx2];
                  u32 q = Q[k];
                  if (q) {
                    u32 o = ((u32 *)out)[i];
                    if (cb(q, o + 4 * (*(u32 *)C + r * S), A + 4, S) == -1) return 0;
                  }
                }
              }
              col++;
              r++;
            } while (col < W);
          }
          g++;
        } while (r < Hn);
      }
      k++;
    } while (k < *(int *)(B + 0xc));
  }
  return 0;
}
PCREG(409ac0, fn409ac0);
