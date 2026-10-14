// batch35062.cpp - cascade s5 batch 35062: 0x4238a0 (GUESS one step of a start-up state machine for a session object).
#include "ff.h"

extern "C" u8 THISCALL ext_424130(u8 *self);   // plain ret, bool in AL
typedef u8(THISCALL *b1_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4238a0, thiscall(a) ret 4, returns bool. Byte +0x1a9a clear: when byte +0x25ea is clear return false; otherwise this slot 0x100(0), +0x25ea = 0, the global object at 0x700394 slot 0 (), and
// 0x424130(this): false calls this slot 0x38() and returns false; true sets +0x1a9a = 1. Then: this slot 0x30(0) true with +0x25ea == 0 and +0x60 == 0 calls the function pointer at the unaligned
// dword +0x23d6 (thiscall, a), this slot 0x158() and returns true; otherwise this slot 0x38(), +0x1a9a = 0 and false.
static u8 THISCALL fn4238a0(u8 *self, u32 a) {
  if (self[0x1a9a] == 0) {
    if (self[0x25ea] == 0) return 0;
    (*(v1_t **)self)[0x100 / 4](self, 0);
    self[0x25ea] = 0;
    u8 *g = G(u8 *, 0x700394);
    (*(v0_t **)g)[0](g);
    if (!ext_424130(self)) {
      (*(v0_t **)self)[0x38 / 4](self);
      return 0;
    }
    self[0x1a9a] = 1;
  }
  if ((*(b1_t **)self)[0x30 / 4](self, 0) && self[0x25ea] == 0 && self[0x60] == 0) {
    ((v1_t)rd32u(self + 0x23d6))(self, a);
    (*(v0_t **)self)[0x158 / 4](self);
    return 1;
  }
  (*(v0_t **)self)[0x38 / 4](self);
  self[0x1a9a] = 0;
  return 0;
}
PCREG(4238a0, fn4238a0);
