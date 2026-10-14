// batch38013.cpp - cascade s8 batch 38013: 0x5c3560 (apply a state change to every item of a list).
#include "ff.h"

extern "C" void THISCALL ext_43ec00(void *obj, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);   // ret 0x18
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))
#define LOOKUP(id) ({ u8 *t_ = TABLE; (u8 *)SLOT(t_, 0x58, v1_t)(t_, (u32)(id)); })

// 0x5c3560, thiscall(a, b) ret 8 (both bytes). When b is set and this+0x10a resolves through the table (slot 0x58), that object gets slot 0x128(nameId, 0, 0) with the id from
// the table's slot 0x114 (string 0x682e18 / line 0xbe when a, else 0x69c83c / line 0xc0). Then every item of the list at this+0x48 (iterator: slot 0x4c start, slot 0x5c next,
// a dword at the cursor tells whether more) that resolves is updated: flags 0x80800004 -> slot 0x214 (a) / 0x218 (not a); else flags 0x20000b -> slot 0xbc(a ? 0 : 1)
// on the table object; otherwise slot 0xbc(a ? 0 : 1) on the item itself. When a is set the item counter (+0x112) steps and at the wrap the item's +8 payload goes to 0x43ec00.
static void THISCALL fn5c3560(u8 *self, u32 a_, u32 b_) {
  u8 a = (u8)a_;
  u8 b = (u8)b_;
  u8 *x = LOOKUP(*(u32 *)(self + 0x10a));
  if (x && b) {
    u8 **vt = *(u8 ***)x;
    u8 *t = TABLE;
    u32 id;
    if (a) id = SLOT(t, 0x114, v4_t)(t, 0x682e18, 0, 0x6b3d9c, 0xbe);
    else id = SLOT(t, 0x114, v4_t)(t, 0x69c83c, 0, 0x6b3d9c, 0xc0);
    ((v3_t)vt[0x128 / 4])(x, id & 0xffff, 0, 0);
  }
  u8 bl = self[0x112];
  u8 *list = self + 0x48;
  u32 cur[5];
  SLOT(list, 0x4c, v1_t)(list, (u32)cur);
  u32 item = SLOT(list, 0x5c, v1_t)(list, (u32)cur);
  if (cur[0] == 0) return;
  do {
    u8 *esi = LOOKUP(item);
    if (esi) {
      bool tail = false;   // true: go to the counter step (5c36ef)
      if ((u8)SLOT(esi, 0x1e0, v1_t)(esi, 0x80800004)) {
        u8 *y = LOOKUP(item);
        if (a) {
          SLOT(y, 0x214, v0_t)(y);
          tail = true;
        } else {
          SLOT(y, 0x218, v0_t)(y);
        }
      } else if ((u8)SLOT(esi, 0x1e0, v1_t)(esi, 0x20000b)) {
        u8 *y = LOOKUP(item);
        if (a) {
          SLOT(y, 0xbc, v1_t)(y, 0);
          tail = true;
        } else {
          SLOT(y, 0xbc, v1_t)(y, 1);
        }
      } else {
        if (a) {
          SLOT(esi, 0xbc, v1_t)(esi, 0);
          tail = true;
        } else {
          SLOT(esi, 0xbc, v1_t)(esi, 1);
        }
      }
      if (tail) {
        bl++;
        if (!((u16)bl < *(u16 *)(self + 0x112))) {
          bl = 0;
          if (*(u32 *)(ENG + 0x1a9f) != 0) {
            u32 edx = *(u32 *)(self + 0x10e);
            if (edx != 0) {
              u32 p = *(u32 *)(esi + 8);
              u32 obj = SLOT(esi, 0x20, v0_t)(esi);
              ext_43ec00((void *)obj, p, p + 0x24, edx, 0, 0, 0);
            }
          }
        }
      }
    }
    item = SLOT(list, 0x5c, v1_t)(list, (u32)cur);
  } while (cur[0] != 0);
}
PCREG(5c3560, fn5c3560);
