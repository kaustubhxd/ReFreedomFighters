// batch37101.cpp - cascade s6 batch 37101: 0x535300.
#include "ff.h"

typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define CUR(s) (*(u8 **)((u8 *)(s) + 0x51a9))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline void *winObj() { return *(void **)(*(u8 **)0x70039c + 0x1a9f); }

// 0x535300, thiscall(list) ret 4: drains a key list (slot 0x4c resets, slot 0x5c yields the next key and sets a "more" flag, at most 0x41 keys). For each key the entity is
// fetched from the table object (slot 0x60), its window handle is resolved (window slot 0x54 on ent+0x7c, then slot 0x1dc); a missing window logs error 0x8c7 with the handle's
// name (slot 0x1e8). Otherwise, when the window has state bits above bit 0, a record is filled in at the cursor +0x51a9 (state, key, entity fields at +0xd0 / +0x40 / +0x8c /
// +0x90 / +8, entity state 5 becoming 1), handed to slot 0x184 and the cursor advances by the record's size (+4).
static void THISCALL fn535300(u8 *self, u8 *list) {
  s32 count = 0;
  if (!list) return;
  u32 flag = 0;
  vcall<void>(list, 0x4c, (u32)&flag);
  u32 key = vcall<u32>(list, 0x5c, (u32)&flag);
  if (flag == 0) return;
  while (count <= 0x40) {
    count++;
    u8 *ent = (u8 *)vcall<u32>(tabObj(), 0x60, key);
    u8 *rec = CUR(self);
    u32 h = vcall<u32>(winObj(), 0x54, D32(ent, 0x7c));
    u8 *w = (u8 *)vcall<u32>(winObj(), 0x1dc, h);
    if (!w) {
      u8 *lg = *(u8 **)0x700390;
      void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6a1e2c, 0x8c7);
      u32 nm = vcall<u32>(self, 0x1e8, h);
      (*(cd3_t **)L)[0x2c / 4](L, 0x6a2398, nm);
    } else if (D32(w, 8) & 0xfffffffeu) {
      if (D32(ent, 4) == 5) {
        D32(ent, 4) = 1;
        D32(rec, 8) = 1;
      } else {
        D32(rec, 8) = 0;
      }
      D32(rec, 0x1c) = key;
      D32(rec, 0x14) = D32(ent, 0xd0);
      D32(rec, 0x20) = D32(w, 8) & 0xfffffffeu;
      D32(rec, 0x18) = (D32(ent, 0x40) >> 3) & 1;
      D32(rec, 0x10) = (s32)D32(ent, 0x8c) > 0 ? D32(ent, 0x90) : 0xffffffffu;
      D32(rec, 0xc) = 0;
      D32(rec, 0x24) = D32(ent, 8);
      vcall<void>(self, 0x184, (u32)ent, (u32)rec);
      u8 *c = CUR(self);
      CUR(self) = c + D32(c, 4);
    }
    key = vcall<u32>(list, 0x5c, (u32)&flag);
    if (flag == 0) break;
  }
}
PCREG(535300, fn535300);
