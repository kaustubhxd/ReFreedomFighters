// batch67533.cpp - cascade s6 batch 67533: 0x45bba0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)
typedef u32 (__cdecl *cmp67533_t)(u32, u32);
typedef void (__cdecl *log67533_t)(u8 *, ...);

// 0x45bba0, thiscall() plain ret (eax unused): for each of this[0x20] indices resolves an object (this[8][0x6c], index) through the object manager (sys[0x1aa3][0x18] slot 0x60), looks its record
// up (slot 0xe4 with the string 0x678d04, then sys[0x1aa3] slot 0x80), asks the table (sys[0x9b] slot 0x160) for the byte at record[2] and stores the object in this[0x254][i]. When this[4] (default 0x67c8e8)
// equals the string 0x684c6c (0x676414 returns 0) and the table object exists it also records the index at table object[0x38]; with the flag set and no table object it logs (0x273). A missing record
// logs (0x278). Stops at the first unresolved object.
static void THISCALL fn45bba0(u8 *self) {
  u32 name = D32(self, 4) ? D32(self, 4) : 0x67c8e8u;
  bool flag = ((cmp67533_t)*(u32 *)0x676414)(0x684c6c, name) == 0;
  u32 n = D32(self, 0x20);
  if (n == 0) return;
  u32 i = 0;
  do {
    u8 *mgr = *(u8 **)(*(u8 **)(SYS + 0x1aa3) + 0x18);
    u8 *obj = vcall<u8 *>(mgr, 0x60, D32(*(u8 **)(self + 8), 0x6c), i);
    if (!obj) return;
    u8 *mgr2 = *(u8 **)(*(u8 **)(SYS + 0x1aa3) + 0x18);
    u8 *rec = vcall<u8 *>(mgr2, 0xe4, (u32)obj, 0x678d04u);
    if (rec) {
      u8 *r3 = vcall<u8 *>(*(u8 **)(SYS + 0x1aa3), 0x80, (u32)rec);
      if (r3) {
        u8 *t = vcall<u8 *>(*(u8 **)(SYS + 0x9b), 0x160, (u32)r3[2]);
        bool done = false;
        if (flag) {
          if (t) {
            D32(t, 0x38) = i;
            D32(*(u8 **)(self + 0x254), i * 4) = (u32)obj;
            done = true;
          } else {
            u8 *lg = *(u8 **)0x700390;
            u8 *y = vcall<u8 *>(lg, 0x20, 0x684bf4u, 0x273u);
            (*(log67533_t *)(*(u8 **)y + 0x2c))(y, 0x684c78u, (u32)(r3 + 0x20));
          }
        }
        if (!done) D32(*(u8 **)(self + 0x254), i * 4) = (u32)obj;
      } else {
        u8 *lg = *(u8 **)0x700390;
        u8 *y = vcall<u8 *>(lg, 0x20, 0x684bf4u, 0x278u);
        (*(log67533_t *)(*(u8 **)y + 0x2c))(y, 0x684c24u);
      }
    }
    i++;
  } while (i != D32(self, 0x20));
}
PCREG(45bba0, fn45bba0);
