// batch37041.cpp - cascade s6 batch 37041: 0x4ef210.
#include "ff.h"

extern "C" void THISCALL ext_45d5b0(u8 *self, u8 *src);   // tail-jumps to slot 0x48 of this (1 arg)
extern "C" void THISCALL ext_4de7a0(u8 *m);                // resets a 3x3 matrix-like block (plain ret)
extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);       // memcpy thunk, cdecl
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define B8(p, o) (*(u8 *)((u8 *)(p) + (o)))

static void *mgr() { return *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x18); }

// 0x4ef210, thiscall(src) ret 4: copy-constructs this entry from src when src answers slot 0x1e0(0x20002c): runs this->slot 0x48(src) and slot 0x230, copies a set of packed
// fields, duplicates the 40-byte records at src+0x2a (this+0x2e of them, through manager slot 0x2c and memcpy) unless src+0x91 is set, and, when src+0x3a is set, the
// parallel arrays at +0x36 / +0x3a (counts +0x32; slots 0x34 / 0x38 of the manager allocate, record pointers are rebased into the new copy, slot 0xc of the manager +
// slot 0x218 of this create the per-item handles). Ends by zeroing a set of fields and resetting the matrix block at this+0x52 (0x4de7a0).
static void THISCALL fn4ef210(u8 *self, u8 *src) {
  ext_45d5b0(self, src);
  if (!(u8)(*(v1_t **)src)[0x1e0 / 4](src, 0x20002c)) return;
  (*(v0_t **)self)[0x230 / 4](self);
  D32(self, 0x18) = D32(src, 0x18);
  D32(self, 0x22) = D32(src, 0x22);
  D32(self, 0x26) = D32(src, 0x26);
  B8(self, 0x21) = B8(src, 0x21);
  D32(self, 0x1c) = D32(src, 0x1c);
  B8(self, 0x8e) = B8(src, 0x8e);
  B8(self, 0x20) = B8(src, 0x20);
  D32(self, 0x3e) = D32(src, 0x3e);
  D32(self, 0x42) = D32(src, 0x42);
  D32(self, 0x2a) = D32(src, 0x2a);
  if (B8(src, 0x91) == 0 && D32(src, 0x2a) != 0) {
    void *m = mgr();
    u8 *p = (u8 *)(*(v1_t **)m)[0x2c / 4](m, D32(self, 0x2e));
    D32(self, 0x2a) = (u32)p;
    ext_634d22(p, *(u8 **)(src + 0x2a), D32(self, 0x2e) * 40);
  }
  B8(self, 0x91) = B8(src, 0x91);
  if (D32(src, 0x3a) != 0) {
    u32 n = D32(src, 0x32);
    D32(self, 0x32) = n;
    void *m = mgr();
    D32(self, 0x36) = (*(v1_t **)m)[0x34 / 4](m, n);
    m = mgr();
    D32(self, 0x3a) = (*(v1_t **)m)[0x38 / 4](m, D32(self, 0x32));
    for (u32 i = 0; i < D32(self, 0x32); i++) {
      u32 v = ((u32 *)D32(src, 0x3a))[i * 2 + 1];
      s32 q = (s32)(v - D32(src, 0x2a)) / 40;
      ((u32 *)D32(self, 0x3a))[i * 2 + 1] = D32(self, 0x2a) + (u32)q * 40;
      ((u32 *)D32(self, 0x3a))[i * 2] = ((u32 *)D32(src, 0x3a))[i * 2];
      m = mgr();
      u8 *r = (u8 *)(*(v1_t **)m)[0xc / 4](m, ((u32 *)D32(src, 0x36))[i]);
      u32 h = (*(v3_t **)self)[0x218 / 4](self, *(u16 *)(r + 4), D32(r, 0x1c), 5);
      ((u32 *)D32(self, 0x36))[i] = h;
    }
  }
  D32(self, 0x4e) = 0;
  D32(self, 0x4a) = 0;
  D32(self, 0x46) = 0;
  ext_4de7a0(self + 0x52);
  D32(self, 0x7e) = 0;
  D32(self, 0x7a) = 0;
  D32(self, 0x76) = 0;
  D32(self, 0x8a) = 0;
  D32(self, 0x86) = 0;
  D32(self, 0x82) = 0;
}
PCREG(4ef210, fn4ef210);
