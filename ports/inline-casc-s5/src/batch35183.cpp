// batch35183.cpp - cascade s5 batch 35183 (tier H): 0x597720 (GUESS find the nearest valid candidate object around the player, returning its id and the distance).
#include "ff.h"

extern "C" u8 THISCALL ext_597a20(u8 *self, u32 id);            // thiscall(id) ret 4, al
extern "C" u8 THISCALL ext_597b10(u8 *self, u32 id);            // thiscall(id) ret 4, al
extern "C" u32 THISCALL ext_59ffc0(u8 *self);                   // thiscall, plain ret: unaligned dword [this+0x77f]
extern "C" float FASTCALL ext_4e0830(float *b, float *a);       // fastcall (ecx = b, edx = a): squared distance, in st0
extern "C" double VECTORCALL ext_634d7c(double);                // CRT routine (sqrt), argument/result in XMM0
typedef u8 *(THISCALL *q_t)(void *, float *, u32, u32 *, u32);
typedef void(THISCALL *v1_t)(void *, float *);
typedef u8(THISCALL *b0_t)(void *);
typedef u32(THISCALL *i1_t)(void *, void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x597720, thiscall(out) ret 4 (stack cookie not reproduced), returns the id of the nearest candidate. O = unaligned dword [this+0x4f7]; O == 0 returns 0. P = unaligned dword [this+0x1d0b]; A = {0, 0, 0}; P slot 0x84(&A);
// T = [[P+0x54]+0x10]; state = 0xffffffff; best = float at 0x67cd44; bestId = 0. e = O slot 0x84(&A, 1500.0f (0x44bb8000), &state, T); while e: skipped when e == P, [[e+0x54]+8] == 4, e slot 0x438() is true; otherwise
// id = engine[+0x9b] slot 0x4c(e); skipped when id is in the int array at this+0x2ef (count at [this+0x4ef], signed), 0x597a20(id), 0x597b10(id) is true or 0x59ffc0(e) == 5; otherwise B = {0, 0, 0}; e slot 0x84(&B); d = 0x4e0830(&B, &A);
// not skipped when d > the float at 0x6ad31c; when best > d: best = d, bestId = id. Then e = O' slot 0x84(&A, ...) again with O re-read. Finally out (when non-null) = (float)sqrt(best); returns bestId.
static u32 THISCALL fn597720(u8 *self, float *out) {
  if (rd32u(self + 0x4f7) == 0) return 0;
  float A[3] = {0, 0, 0};
  float B[3];
  u32 state;
  u8 *P = (u8 *)rd32u(self + 0x1d0b);
  (*(v1_t **)P)[0x84 / 4](P, A);
  P = (u8 *)rd32u(self + 0x1d0b);
  u8 *O = (u8 *)rd32u(self + 0x4f7);
  float best = G(float, 0x67cd44);
  state = 0xffffffffu;
  u32 bestId = 0;
  u32 T = *(u32 *)(*(u8 **)(P + 0x54) + 0x10);
  u8 *e = (*(q_t **)O)[0x84 / 4](O, A, 0x44bb8000u, &state, T);
  while (e) {
    if (rd32u(self + 0x1d0b) != (u32)e && *(u32 *)(*(u8 **)(e + 0x54) + 8) != 4 && !(*(b0_t **)e)[0x438 / 4](e)) {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *tab = *(u8 **)(eng + 0x9b);
      u32 id = (*(i1_t **)tab)[0x4c / 4](tab, e);
      bool skip = false;
      s32 cnt = *(s32 *)(self + 0x4ef);
      for (s32 i = 0; i < cnt; i++)
        if (*(u32 *)(self + 0x2ef + 4 * i) == id) {
          skip = true;
          break;
        }
      if (!skip && !ext_597a20(self, id) && !ext_597b10(self, id) && ext_59ffc0(e) != 5) {
        B[0] = B[1] = B[2] = 0;
        (*(v1_t **)e)[0x84 / 4](e, B);
        float d = ext_4e0830(B, A);
        if (!(d > G(float, 0x6ad31c)) && best > d) {
          best = d;
          bestId = id;
        }
      }
    }
    O = (u8 *)rd32u(self + 0x4f7);
    e = (*(q_t **)O)[0x84 / 4](O, A, 0x44bb8000u, &state, T);
  }
  if (out) *out = (float)ext_634d7c((double)best);
  return bestId;
}
PCREG(597720, fn597720);
