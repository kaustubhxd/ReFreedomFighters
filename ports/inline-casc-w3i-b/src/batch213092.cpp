#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" u32 THISCALL ext_45f960(void *self, void *s);
extern "C" u32 THISCALL ext_463ff0(void *item, void *s);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x4640f0: thiscall(stream) ret 4 -> bool in AL: serializes this into a stream object (slots: 0x10 raw bytes(ptr, size), 0x60 byte, 0x24 / 0x3c dword, 0x4c float). Returns 0 when
// 0x45f960(this, stream) fails. Otherwise: this+0x70 (1 byte), byte [0x71], dword [0x58], H = this[0x6c] slot 4(stream), then the list this[0x18]: its count (slot 0x14) or 0 when absent,
// each item's first dword and 0x463ff0(item + 4, stream); then for each of the this[0x20] records of 0x18 bytes at this[0x1c]: raw 0x10 bytes, dwords [0x10] and [0xc], and the index
// (1-based position, counted with slot 0x4c / 0x64) of the list item whose address + 4 equals the record's [0x14] (all items when none, 0 without list / [0x14]); finally this+0x82 (0x30 raw bytes) and the float [0x116].
extern "C" u32 THISCALL fn_4640f0(u8 *self, u8 *S) {
  u32 it[3];
  if (!(u8)ext_45f960(self, S)) return 0;
  (*(V2 *)(vt(S) + 0x10))(S, (u32)(self + 0x70), 1);
  (*(V1 *)(vt(S) + 0x60))(S, self[0x71]);
  (*(V1 *)(vt(S) + 0x24))(S, rd32u(self + 0x58));
  {
    void *H = (void *)rd32u(self + 0x6c);
    (*(V1 *)(vt(H) + 4))(H, (u32)S);
  }
  u8 *L = (u8 *)rd32u(self + 0x18);
  if (!L) {
    (*(V1 *)(vt(S) + 0x3c))(S, 0);
  } else {
    u32 n = (*(V0 *)(vt(L) + 0x14))(L);
    (*(V1 *)(vt(S) + 0x3c))(S, n);
    L = (u8 *)rd32u(self + 0x18);
    if (L) {
      (*(V1 *)(vt(L) + 0x4c))(L, (u32)it);
      u8 *item = (u8 *)(*(V1 *)(vt(L) + 0x64))(L, (u32)it);
      while (item) {
        (*(V1 *)(vt(S) + 0x3c))(S, rd32u(item));
        ext_463ff0(item + 4, S);
        L = (u8 *)rd32u(self + 0x18);
        item = (u8 *)(*(V1 *)(vt(L) + 0x64))(L, (u32)it);
      }
    }
  }
  u32 count = rd32u(self + 0x20);
  u8 *rec = (u8 *)rd32u(self + 0x1c);
  if (count) {
    u32 idx = 0;
    do {
      (*(V2 *)(vt(S) + 0x10))(S, (u32)rec, 0x10);
      (*(V1 *)(vt(S) + 0x24))(S, rd32u(rec + 0x10));
      (*(V1 *)(vt(S) + 0x24))(S, rd32u(rec + 0xc));
      u32 m = 0;
      if (rd32u(rec + 0x14) != 0) {
        L = (u8 *)rd32u(self + 0x18);
        if (L) {
          (*(V1 *)(vt(L) + 0x4c))(L, (u32)it);
          u8 *item = (u8 *)(*(V1 *)(vt(L) + 0x64))(L, (u32)it);
          if (item) {
            for (;;) {
              m++;
              if ((u32)(item + 4) == rd32u(rec + 0x14)) break;
              L = (u8 *)rd32u(self + 0x18);
              item = (u8 *)(*(V1 *)(vt(L) + 0x64))(L, (u32)it);
              if (!item) break;
            }
          }
        }
      }
      (*(V1 *)(vt(S) + 0x3c))(S, m);
      idx++;
      rec += 0x18;
    } while (idx != rd32u(self + 0x20));
  }
  (*(V2 *)(vt(S) + 0x10))(S, (u32)(self + 0x82), 0x30);
  (*(V1 *)(vt(S) + 0x4c))(S, rd32u(self + 0x116));
  return 1;
}
PCREG(4640f0, fn_4640f0);
