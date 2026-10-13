// batch13011.cpp - fresh slice 13, batch 11 (docs/20-fresh-13.md), 2026-10-12.
// 0x498750 ZBaseGeomLists::RemoveBaseGeoms(unsigned list, ZBaseGeom* lo, ZBaseGeom* hi, unsigned type) (name map high).
// Thiscall, four arguments (ret 0x10); returns the (possibly new) list head.
// A list is a chain of blocks: byte +8 = dword count n (odd n: the first dword at +0xc is the next block), byte +9 = the
// block's allocated size in dwords, then (a, b) ranges whose low 3 bits are the type. The first range of `type` with
// a <= lo|type and b >= hi|type is edited (geoms are 0x70 bytes apart):
//   a == lo|type, b == hi|type: the range is removed (per-type count byte blk[type] -1, n -= 2, the tail moved down with
//     the memmove import); a block left with n < 2 is unlinked (prev+0xc or the head = its next, or 0 when n == 0), its
//     memory released through 0x4ce1c0(this[0]; blk - this[4], (blk[9]*4 + 0x1b) & ~15) (thiscall, ret 8) and reported
//     to *(0x70038c)->vtbl[+0x30](0x68e4c8, offset, size) (thiscall, ret 0xc) when that object exists;
//   a == lo|type, hi|type < b: a = (hi|type) + 0x70;   a < lo|type, b == hi|type: b = (lo|type) - 0x70;
//   a < lo|type, hi|type < b: b = (lo|type) - 0x70 and 0x495950(this; list, (hi|type & ~7) + 0x70, b & ~7, type, 8)
//     (thiscall, ret 0x14) inserts the upper part; its result is returned;
//   any other passing range runs the hook at 0x7003b0 (int3 when null) and the search goes on.
// Not found: *(0x700390)->vtbl[+0x20](0x68e36c, 0xa23) (thiscall, ret 8) gives a log object whose vtbl[+0x2c] is called
// cdecl as (log, 0x68e4d8); then the hook at 0x7003b0 (int3 when null).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4ce1c0[], ext_495950[];
typedef void (*Hook0)(void);
typedef void *(*Memmove3)(void *d, const void *s, u32 n);
typedef void(THISCALL *Free2)(void *self, u32 off, u32 size);
typedef u32(THISCALL *Insert5)(void *self, u32 list, u32 lo, u32 hi, u32 type, u32 eight);
typedef void(THISCALL *Report3)(void *self, u32 name, u32 off, u32 size);
typedef u8 *(THISCALL *Log2)(void *self, u32 file, u32 line);
typedef void (*Print2)(void *log, u32 fmt);

static inline void hook7003b0() {
  u32 h = G(u32, 0x7003b0);
  if (!h)
    __builtin_debugtrap();
  ((Hook0)h)();
}

static u32 THISCALL removeBaseGeoms(u8 *self, u32 list, u32 lo, u32 hi, u32 type) {
  if (!list)
    return 0;
  u32 L = lo | type, H = hi | type;
  u8 *prev = 0;
  u8 *blk = (u8 *)list;
  do {
    u32 *p = (u32 *)(blk + 0xc);
    u32 *end = p + blk[8];
    u32 next = 0;
    if (blk[8] & 1)
      next = *p++;
    while (p != end) {
      u32 a = p[0], b = p[1];
      p += 2;
      if ((a & 7) != type || a > L || H > b)
        continue;
      if (a == L) {
        if (b == H) {
          blk[type]--;
          blk[8] += 0xfe;
          u8 n = blk[8];
          if (p != end) {
            (*(Memmove3 *)0x676278)(p - 2, p, (u32)((u8 *)end - (u8 *)p));
            return list;
          }
          if (n >= 2)
            return list;
          if (prev)
            AT(u32, prev, 0xc) = n == 1 ? AT(u32, blk, 0xc) : 0;
          else
            list = n == 1 ? AT(u32, blk, 0xc) : 0;
          u32 size = ((u32)blk[9] * 4 + 0x1b) & ~0xfu;
          ((Free2)(void *)ext_4ce1c0)(*(void **)self, (u32)blk - AT(u32, self, 4), size);
          u8 *rep = (u8 *)G(u32, 0x70038c);
          if (!rep)
            return list;
          ((Report3)(*(u32 *)(*(u32 *)rep + 0x30)))(rep, 0x68e4c8, (u32)blk - AT(u32, self, 4), size);
          return list;
        }
        if (H < b) {
          p[-2] = H + 0x70;
          return list;
        }
      } else {
        if (H == b) {
          p[-1] = L - 0x70;
          return list;
        }
        if (H < b) {
          p[-1] = L - 0x70;
          return ((Insert5)(void *)ext_495950)(self, list, (H & ~7u) + 0x70, b & ~7u, type, 8);
        }
      }
      hook7003b0();
    }
    prev = blk;
    blk = (u8 *)next;
  } while (blk);
  u8 *obj = (u8 *)G(u32, 0x700390);
  u8 *log = ((Log2)(*(u32 *)(*(u32 *)obj + 0x20)))(obj, 0x68e36c, 0xa23);
  ((Print2)(*(u32 *)(*(u32 *)log + 0x2c)))(log, 0x68e4d8);
  u32 h = G(u32, 0x7003b0);
  if (!h)
    __builtin_debugtrap();
  ((Hook0)h)();
  return list;
}
PCREG(498750, removeBaseGeoms);
