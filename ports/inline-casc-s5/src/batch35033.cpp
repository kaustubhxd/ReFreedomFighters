// batch35033.cpp - cascade s5 batch 35033: 0x5bf8a0 (GUESS recompute an on/off state from three conditions and push it to the target when it changed).
#include "ff.h"

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline u32 rd16u(const u8 *p) { return p[0] | p[1] << 8; }

typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);

// 0x5bf8a0, thiscall, no arguments, every field unaligned. a = dword [+0x59], f = dword [+0x6a]; c = f != 0, or (byte [+0x65] set) c = (slot 0x14() of [[+0x61]+0x18]) == f.
// mode = dword [+0x6e]: mode == 1 gives s = a && c, any other mode s = a || c. When s differs from byte [+0x72]: w = s ? word [+0x51] : word [+0x53]; target [+0x4c] slot 0x214(w, 0) when the
// byte [+0x50] is set, else slot 0x128(w, 0, 0); then byte [+0x72] = s.
static void THISCALL fn5bf8a0(u8 *self) {
  u32 a = rd32u(self + 0x59);
  u32 f = rd32u(self + 0x6a);
  u8 c = f != 0;
  if (self[0x65]) {
    u8 *o = (u8 *)rd32u(self + 0x61);
    void *k = *(void **)(o + 0x18);
    c = (*(g0_t **)k)[0x14 / 4](k) == f;
  }
  u8 s;
  if (rd32u(self + 0x6e) == 1) {
    s = (a != 0 && c) ? 1 : 0;
  } else {
    s = (a != 0 || c) ? 1 : 0;
  }
  if (s != self[0x72]) {
    u32 w = s ? rd16u(self + 0x51) : rd16u(self + 0x53);
    u8 *t = (u8 *)rd32u(self + 0x4c);
    if (self[0x50]) {
      (*(v2_t **)t)[0x214 / 4](t, w, 0);
      self[0x72] = s;
      return;
    }
    (*(v3_t **)t)[0x128 / 4](t, w, 0, 0);
    self[0x72] = s;
  }
}
PCREG(5bf8a0, fn5bf8a0);
