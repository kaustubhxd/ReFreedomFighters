// batch35076.cpp - cascade s5 batch 35076: 0x498e60 (GUESS serialise the engine table's list into a stream, terminated by -1).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, void *, u32);
typedef void(THISCALL *v1p_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);

static u8 *list_obj() {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  return *(u8 **)(tab + 0xc);
}

// 0x498e60, stdcall(s) ret 4. s slot 8(0xf). L = [[[engine+0x9b]]+0xc] (re-read before every use; null: skip). L slot 0x4c(&it); for each e returned by L slot 0x5c(&it) while it[0] != 0: s slot 0x10(&e, 4).
// Finally s slot 0x10(&-1, 4).
static void STDCALL fn498e60(u8 *s) {
  u32 it[3];
  u32 e;
  (*(v1_t **)s)[8 / 4](s, 0xf);
  u8 *L = list_obj();
  if (L) {
    (*(v1p_t **)L)[0x4c / 4](L, it);
    L = list_obj();
    e = (*(g1p_t **)L)[0x5c / 4](L, it);
    if (it[0] != 0) {
      do {
        (*(v2_t **)s)[0x10 / 4](s, &e, 4);
        L = list_obj();
        e = (*(g1p_t **)L)[0x5c / 4](L, it);
      } while (it[0] != 0);
    }
  }
  u32 term = 0xffffffff;
  (*(v2_t **)s)[0x10 / 4](s, &term, 4);
}
PCREG(498e60, fn498e60);
