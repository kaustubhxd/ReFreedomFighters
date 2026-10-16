#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, void *, void *);
typedef u32(THISCALL *V3)(void *, void *, u32, u32);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32u(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// 0x47b7a0: thiscall(this, flag) ret 4: finishes a pending action stored at +0x727 (1..4 call slot 0x640 / 0x644 / 0x648 / 0x64c), and when
// flag is set and +0x695 is clear re-reads the position through slots 0x57c, 0x620 and 0x578 (locals buffer and vector), then clears the
// pending fields. /GS cookie check at the end.
void THISCALL fn_47b7a0(u8 *self, u32 flag) {
  u32 pending = rd32u(self + 0x727);
  if (pending != 0) {
    u8 *vt = *(u8 **)self;
    u32 k = pending - 1;
    if (k <= 3) {
      switch (k) {
        case 0:
          if (rd32u(self + 0x695) != 0) break;
          (*(V1 *)(vt + 0x640))(self, 0);
          break;
        case 1: (*(V1 *)(vt + 0x644))(self, rd32u(self + 0x72b)); break;
        case 2: (*(V1 *)(vt + 0x648))(self, rd32u(self + 0x732)); break;
        default: (*(V1 *)(vt + 0x64c))(self, 0); break;
      }
    }
    if (rd32u(self + 0x695) == 0) {
      self[0x726] = 0;
      if ((u8)flag) {
        u8 buf[0x24];
        float vec[3];
        vt = *(u8 **)self;
        (*(V2 *)(vt + 0x57c))(self, buf, vec);
        vt = *(u8 **)self;
        (*(V3 *)(vt + 0x620))(self, vec, 1, 1);
        *(float *)(self + 0x660) = vec[0];
        *(float *)(self + 0x664) = vec[1];
        *(float *)(self + 0x668) = vec[2];
        vt = *(u8 **)self;
        (*(V2 *)(vt + 0x578))(self, buf, vec);
      }
    }
    wr32u(self + 0x650, 0);
    wr32u(self + 0x64c, 0);
    wr32u(self + 0x727, 0);
    wr32u(self + 0x72b, 0);
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(47b7a0, fn_47b7a0);
