// batch36056.cpp - cascade s4 batch 36056: 0x4efcf0 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v3r_t)(void *, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *ext_4f00f0();   // cdecl, returns the pending list or 0

// 0x4efcf0, stdcall(a, b, c) ret 0xc returns eax: l = 0x4f00f0(); iterate l (slot 0x4c(&it); e = slot 0x5c(&it) while it[0]): M = [0x70039c][0x1aa3][0x18]; r = M->slot 0xc(e); r[6] (u16) == 0 -> claim:
// r[0xc] = c, u16 r[4] = a, r[0x1c] = b, r[8] = 0, r[0] = 0x20100, r[0x10] = 0, r[0x18] = 0, u16 r[6] = 0; l->slot 0x44(&it) (remove); return e. Otherwise (none claimed or no list): return M->slot 0x108(a, b, c).
static u32 STDCALL fn4efcf0(u32 a, u32 b, u32 c) {
  u32 it[3];
  u8 *l = ext_4f00f0();
  if (l) {
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    u32 e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
    if (it[0] != 0) {
      do {
        u8 *M = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
        u8 *r = (*(v1o_t **)M)[0xc / 4](M, e);
        if (*(u16 *)(r + 6) == 0) {
          wr(r + 0xc, c);
          *(u16 *)(r + 4) = (u16)a;
          wr(r + 0x1c, b);
          wr(r + 8, 0);
          wr(r, 0x20100);
          wr(r + 0x10, 0);
          wr(r + 0x18, 0);
          *(u16 *)(r + 6) = 0;
          (*(v1_t **)l)[0x44 / 4](l, (u32)it);
          return e;
        }
        e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
      } while (it[0] != 0);
    }
  }
  u8 *M = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  return (*(v3r_t **)M)[0x108 / 4](M, a, b, c);
}
PCREG(4efcf0, fn4efcf0);
