// batch1419.cpp - unclaimed-14 batch 19 (residue 13): ZBombDamageList::CopyData(ZEventBase*).
#include "ff.h"

// 0x5dbe50, ZBombDamageList::CopyData(ZEventBase*) (high): thiscall, one stack argument (src, ret 4). If src->+0x48 is null it
// returns. Otherwise L = src->+0x48: L.vt[+0x4c](&tmp); item = L.vt[+0x5c](&tmp); while tmp != 0: D.vt[+4](item) with
// D = this->+0x48, then item = L.vt[+0x5c](&tmp).
static void THISCALL bombListCopyData(u8 *self, u8 *src) {
  typedef void(THISCALL * v1_t)(u8 *, u32 *);
  typedef u32(THISCALL * r1_t)(u8 *, u32 *);
  typedef void(THISCALL * d4_t)(u8 *, u32);
  u8 *l = *(u8 **)(src + 0x48);
  if (l == 0)
    return;
  u32 tmp = 0;
  (*(v1_t *)(*(u32 *)l + 0x4c))(l, &tmp);
  u32 item = (*(r1_t *)(*(u32 *)l + 0x5c))(l, &tmp);
  if (tmp == 0)
    return;
  while (tmp != 0) {
    u8 *d = *(u8 **)(self + 0x48);
    (*(d4_t *)(*(u32 *)d + 4))(d, item);
    item = (*(r1_t *)(*(u32 *)l + 0x5c))(l, &tmp);
  }
}
PCREG(5dbe50, bombListCopyData);
