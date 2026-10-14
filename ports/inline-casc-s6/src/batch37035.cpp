// batch37035.cpp - cascade s6 batch 37035: 0x54e1f0.
#include "ff.h"

extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);   // memcpy thunk, cdecl
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef void(*cdl_t)(void *, ...);
#define F32(o) (*(u32 *)(self + (o)))

// 0x54e1f0, thiscall(dst, want, outRead, outPos) ret 0x10: reads up to want bytes from the current block of a block queue. this: +0x2e current index, +0x1e[] block data
// markers, +0x26[] block flags (bit 0: last block), +0x47 block size, +0x5b last-block size, +0x4f data base, +0x63 cursor, +0x37 block count, +0x32 stop flag. Returns 3 when
// stopped, 0 when the block is missing (error 0x6b), else 1 (2 when a block was finished and it was a last block). The bytes are copied to dst (when not null), outRead gets the
// count (limited to what remains, error 0x8a when a non-final block is short), outPos the source offset; a finished block is released through slot 8 and the index advances.
static u32 THISCALL fn54e1f0(u8 *self, u8 *dst, s32 want, u32 *outRead, u32 *outPos) {
  if (*(u8 *)(self + 0x32)) {
    *outRead = 0;
    return 3;
  }
  u32 idx = F32(0x2e);
  if (F32(0x1e + idx * 4) == 0) {
    *outRead = 0;
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6a3ed4, 0x6b);
    (*(cdl_t **)L)[0x2c / 4](L, 0x6a3f04);
    if (outPos) *outPos = F32(0x47) * F32(0x2e) + F32(0x63) + F32(0x4f);
    return 0;
  }
  u32 fl = F32(0x26 + idx * 4);
  u32 fl1 = fl & 1;
  u32 ebx = 1;
  bool done = false;
  s32 rem = (s32)((fl1 ? F32(0x5b) : F32(0x47)) - F32(0x63));
  if (rem > want) {
    *outRead = (u32)want;
  } else {
    if (!(rem == want && !fl1)) {
      if (!fl1) {
        u8 *lg = *(u8 **)0x700390;
        void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6a3ed4, 0x8a);
        (*(cdl_t **)L)[0x2c / 4](L, 0x6a3f38, (u32)want, (u32)rem);
      } else if (*(u8 *)(self + 0x57) == 0) {
        *(u8 *)(self + 0x32) = 1;
      }
    }
    done = true;
    *outRead = (u32)rem;
    ebx = (F32(0x26 + idx * 4) & 1) + 1;
  }
  if (dst && *outRead != 0) ext_634d22(dst, (u8 *)(F32(0x47) * idx + F32(0x4f) + F32(0x63)), *outRead);
  if (outPos) *outPos = F32(0x47) * idx + F32(0x4f) + F32(0x63);
  F32(0x63) += *outRead;
  if (done) {
    F32(0x26 + F32(0x2e) * 4) = 0;
    F32(0x63) = 0;
    F32(0x1e + F32(0x2e) * 4) = 0;
    (*(v1_t **)self)[8 / 4](self, 1);
    F32(0x2e)++;
    if (F32(0x2e) == F32(0x37)) F32(0x2e) = 0;
  }
  return ebx;
}
PCREG(54e1f0, fn54e1f0);
