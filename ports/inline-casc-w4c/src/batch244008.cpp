// batch244008.cpp - Sonnet-w4c: hand ports of two free-list block initialisers (GUESS names).
#include "ff.h"

struct W4c_u16 { u16 v; } __attribute__((packed));
typedef u32(THISCALL *w4c_vt0_t)(void *);

// this->slot 0x30() gives a block (0: return false); block header: [1] = byte this[0x10], ring links at +8/+0xc to itself, [0] = 0, word [+2] = 0;
// n = this->slot 0x28(); n-1 entries of `stride` bytes from +0x10 get the next index as a word; the last gets 0xffff; the block is linked into the ring at [this+8].
template <u32 STRIDE>
static u8 init_block(u8 *self) {
  u8 *blk = (u8 *)(*(w4c_vt0_t **)self)[0x30 / 4](self);
  if (!blk) return 0;
  blk[1] = self[0x10];
  u32 n = (*(w4c_vt0_t **)self)[0x28 / 4](self);
  *(u8 **)(blk + 8) = blk;
  u8 *p = blk + 0x10;
  *(u8 **)(blk + 0xc) = blk;
  blk[0] = 0;
  u32 last = n - 1;
  ((W4c_u16 *)(blk + 2))->v = 0;
  u32 i = 0;
  if (last != 0) {
    do {
      u32 cx = i + 1;
      i++;
      ((W4c_u16 *)p)->v = (u16)cx;
      p += STRIDE;
    } while (i != last);
  }
  ((W4c_u16 *)p)->v = 0xffff;
  u8 *ecx = *(u8 **)(self + 8);
  if (ecx) {
    *(u8 **)(blk + 8) = ecx;
    u8 *e = *(u8 **)(ecx + 0xc);
    *(u8 **)(blk + 0xc) = e;
    *(u8 **)(e + 8) = blk;
    *(u8 **)(ecx + 0xc) = blk;
  }
  *(u8 **)(self + 8) = blk;
  return 1;
}
static u8 THISCALL fn6155d0(u8 *self) { return init_block<0x138>(self); }
PCREG(6155d0, fn6155d0);
static u8 THISCALL fn648d50(u8 *self) { return init_block<0x20>(self); }
PCREG(648d50, fn648d50);
