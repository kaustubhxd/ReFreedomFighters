// batch38056.cpp - cascade s8 batch 38056: 0x6491b0 (refresh the effect instances attached to a record).
#include "ff.h"

extern "C" void THISCALL ext_64d490(u8 *self, u8 *inst);   // ret 4
extern "C" void THISCALL ext_64d5f0(u8 *self, u8 *inst);   // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define F32(off) (*(u32 *)(self + (off)))

// 0x6491b0, thiscall(rec) ret 4. For a record with flag 0x10 in byte +5: first prunes the chain rec[0x1c] (+0x1c = next): an instance is kept when it has flag 0x10, and either the word at
// [[inst[8]+0x10]+8]+2 is not 0 / 1 or its byte +0x30 shares a bit with rec[0x14]; every other instance is detached (its owner's +0x14 loses the mask this[0x10059], 0x64d5f0, unlink).
// Then walks the rec[8] block's entries (count byte +0x3d, table +0x40 of {instance, source} pairs): for each entry whose source passes the mask test (+0x30 & flags) a missing instance is built from
// the two pools (this[0x1005d][0x224] and this[0x1015d]; slot 0xa8 / 0xac of this[0x1005d] set up / release it) and an existing one that is not masked out (this[0x10059]) gets a new link; the link
// is activated by slot 0x54(instance) (slot 0x58 and the pool free on failure) and pushed on the chain with 0x64d490. A walk that stops early marks the record with 0x80 in byte +0x14.
static void free_obj(u8 *self, u8 *obj) {
  u8 *p1 = *(u8 **)(*(u8 **)(self + 0x1005d) + 0x224);
  SLOT(p1, 0xc, v1_t)(p1, (u32)obj);
}
static void release_edi(u8 *self, u8 *edi, u8 *obj) {
  u8 *p2 = *(u8 **)(self + 0x1015d);
  SLOT(p2, 0xc, v1_t)(p2, (u32)edi);
  u8 *m2 = *(u8 **)(self + 0x1005d);
  SLOT(m2, 0xac, v1_t)(m2, (u32)obj);
  free_obj(self, obj);
}
static void THISCALL fn6491b0(u8 *self, u8 *rec) {
  if (!(rec[5] & 0x10)) return;
  u8 cl = rec[0x14];
  u8 *B = *(u8 **)(rec + 8);
  u32 *head = (u32 *)(rec + 0x1c);
  if (*head != 0) {
    do {
      u8 *edi = *(u8 **)head;
      u8 *own = *(u8 **)(edi + 8);
      bool keep = false;
      if (edi[5] & 0x10) {
        u8 *edx = *(u8 **)(*(u8 **)(own + 0x10) + 8);
        u32 ax = *(u16 *)(edx + 2);
        if (ax != 0 && ax != 1) keep = true;
        else if (edx[0x30] & cl) keep = true;
      }
      if (keep) {
        head = (u32 *)(edi + 0x1c);
      } else {
        *(u32 *)(own + 0x14) &= ~F32(0x10059);
        ext_64d5f0(self, edi);
        *head = *(u32 *)(edi + 0x1c);
      }
    } while (*head != 0);
  }
  u32 i = 0;
  u8 *tab = *(u8 **)(B + 0x40);
  u32 mask = cl;
  u32 count = B[0x3d];
  if (count != 0) {
    do {
      u8 *C = *(u8 **)(tab + i * 8 + 4);
      if ((*(u32 *)(C + 0x30) & mask) != 0) {
        u8 *slot = *(u8 **)(tab + i * 8);
        if (!slot) {
          u8 *pool1 = *(u8 **)(*(u8 **)(self + 0x1005d + 0) + 0x224);
          u8 *obj = (u8 *)SLOT(pool1, 8, v0_t)(pool1);
          if (!obj) goto done;
          u8 *pool2 = *(u8 **)(self + 0x1015d);
          u8 *edi = (u8 *)SLOT(pool2, 8, v0_t)(pool2);
          if (!edi) {
            free_obj(self, obj);
            goto done;
          }
          obj[8] = (u8)i;
          *(u8 **)(obj + 0xc) = B;
          *(u8 **)(tab + i * 8) = obj;
          u8 *m = *(u8 **)(self + 0x1005d);
          u8 ok = (u8)SLOT(m, 0xa8, v3_t)(m, (u32)obj, (u32)C, (u32)B);
          if (!ok) {
            release_edi(self, edi, obj);
            goto done;
          }
          *(u8 **)(edi + 0x14) = rec;
          *(u8 **)(edi + 8) = obj;
          edi[0x10] = rec[0x16];
          if (!(u8)SLOT(self, 0x54, v1_t)(self, (u32)edi)) {
            SLOT(self, 0x58, v1_t)(self, (u32)edi);
            release_edi(self, edi, obj);
            goto done;
          }
          ext_64d490(self, edi);
          *(u32 *)(edi + 0x1c) = *(u32 *)(rec + 0x1c);
          *(u32 *)(rec + 0x1c) = (u32)edi;
        } else if (!(F32(0x10059) & *(u32 *)(slot + 0x14))) {
          u8 *pool2 = *(u8 **)(self + 0x1015d);
          u8 *edi = (u8 *)SLOT(pool2, 8, v0_t)(pool2);
          if (!edi) goto done;
          *(u8 **)(edi + 8) = slot;
          *(u8 **)(edi + 0x14) = rec;
          edi[0x10] = rec[0x16];
          if (!(u8)SLOT(self, 0x54, v1_t)(self, (u32)edi)) {
            SLOT(self, 0x58, v1_t)(self, (u32)edi);
            u8 *p2 = *(u8 **)(self + 0x1015d);
            SLOT(p2, 0xc, v1_t)(p2, (u32)edi);
            goto done;
          }
          ext_64d490(self, edi);
          *(u32 *)(edi + 0x1c) = *(u32 *)(rec + 0x1c);
          *(u32 *)(rec + 0x1c) = (u32)edi;
        }
      }
      i++;
    } while (i != (u32)B[0x3d]);
  }
done:
  if (i != (u32)B[0x3d]) rec[0x14] |= 0x80;
}
PCREG(6491b0, fn6491b0);
