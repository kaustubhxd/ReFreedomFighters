#include "ff.h"
// 0x4b8ab0, thiscall(a) ret 4: m = [this+0x4c] (return when null): it = {}; m->slot0x4c(&it); id = m->slot0x5c(&it); while it[0]: [this+0x44]->slot0x12c(id, word [this+0x4a], a);
// id = [this+0x4c]->slot0x5c(&it).
static void THISCALL fn4b8ab0(u8 *self, u32 a) {
  u32 it[3];
  u8 *m = *(u8 **)(self + 0x4c);
  if (!m) return;
  vcall<void>(m, 0x4c, (u32)it);
  u32 id = vcall<u32>(*(u8 **)(self + 0x4c), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    vcall<void>(*(u8 **)(self + 0x44), 0x12c, id, (u32)(self[0x4a] | self[0x4b] << 8), a);
    id = vcall<u32>(*(u8 **)(self + 0x4c), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(4b8ab0, fn4b8ab0);

