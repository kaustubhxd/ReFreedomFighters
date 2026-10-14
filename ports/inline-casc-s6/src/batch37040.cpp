// batch37040.cpp - cascade s6 batch 37040: 0x5355a0.
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define CUR(self) (*(u32 **)((self) + 0x51a9))

static void emitList(u8 *self, void *l) {
  u32 v;
  (*(v1_t **)l)[0x4c / 4](l, (u32)&v);
  u32 item = (*(v1_t **)l)[0x5c / 4](l, (u32)&v);
  while (v != 0) {
    u32 *rec = CUR(self);
    rec[1] = 0x10;
    rec[0] = 4;
    rec[2] = item;
    rec[3] = 0;
    u32 *c = CUR(self);
    CUR(self) = (u32 *)((u8 *)c + c[1]);
    item = (*(v1_t **)l)[0x5c / 4](l, (u32)&v);
  }
}

// 0x5355a0, thiscall(a8, list2, list1) ret 0xc: appends records to the command buffer whose write cursor is at this+0x51a9 (each record {type, size, ...}, the cursor moves by
// its size): one type-4 record {4, 0x10, item, 0} per item of list1 then of list2 (slots 0x4c start / 0x5c next of the list objects, items while the flag it writes is
// non-zero), then, if the object at this+0x52fe has a non-empty sub-object (at +0x19, count slot 0x14), a type-0x32 record {0x32, 12 + 4n, n, items...}. Finally runs slots
// 0x17c, 0x180(a8), 0x188 of this and terminates the buffer with a 0x10000 word at the cursor.
static void THISCALL fn5355a0(u8 *self, u32 a8, void *list2, void *list1) {
  if (list1) emitList(self, list1);
  if (list2) emitList(self, list2);
  u8 *obj = *(u8 **)(self + 0x52fe);
  if (obj) {
    void *sub = obj + 0x19;
    if ((*(v0_t **)sub)[0x14 / 4](sub)) {
      u32 *rec = CUR(self);
      rec[0] = 0x32;
      u32 n2 = (*(v0_t **)sub)[0x14 / 4](sub);
      rec[1] = n2 * 4 + 0xc;
      u32 *rec2 = CUR(self);
      rec2[2] = (*(v0_t **)sub)[0x14 / 4](sub);
      u32 *d = rec2 + 3;
      u32 v;
      (*(v1_t **)sub)[0x4c / 4](sub, (u32)&v);
      u32 item = (*(v1_t **)sub)[0x5c / 4](sub, (u32)&v);
      if (v != 0) {
        do {
          *d = item;
          d++;
          item = (*(v1_t **)sub)[0x5c / 4](sub, (u32)&v);
        } while (v != 0);
      }
      u32 *c = CUR(self);
      CUR(self) = (u32 *)((u8 *)c + c[1]);
    }
  }
  (*(v0_t **)self)[0x17c / 4](self);
  (*(v1_t **)self)[0x180 / 4](self, a8);
  (*(v0_t **)self)[0x188 / 4](self);
  *CUR(self) = 0x10000;
}
PCREG(5355a0, fn5355a0);
