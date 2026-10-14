// batch34037.cpp - cascade tier E, batch 34037: 0x4a9330 (swap the tracked object), 0x4b8ab0 (send every id of a list to a sink), 0x4caed0 (copy or clear a
// pair on a matching id).
#include "ff.h"

extern "C" void THISCALL ext_4a90b0(void *self, void *o);   // thiscall ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4a9330, thiscall(n) ret 4: old = [this+0xbb] (unaligned); nothing when n == old. Otherwise the old object (engine table slot 0x58(old)) gets slot 0xbc(1) when found; [this+0xbb] = n;
// when n: the object for n gets slot 0xbc(0) and 0x4a90b0(this, object).
static void THISCALL fn4a9330(u8 *self, u32 n) {
  u32 old = rd32u(self + 0xbb);
  if (n == old) return;
  if (old) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, old);
    if (o) vcall<void>(o, 0xbc, 1u);
  }
  wr32u(self + 0xbb, n);
  if (n) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, n);
    if (o) {
      vcall<void>(o, 0xbc, 0u);
      ext_4a90b0(self, o);
    }
  }
}
PCREG(4a9330, fn4a9330);

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

// 0x4caed0, thiscall(k, unused) ret 8, returns 0: when the low word of k equals the word at +0x90: [this+0x8c] (when set) gets +0x18 = [this+0x70], +0x1c = [this+0x74], otherwise
// this->slot0x64(0x10). When it equals the word at +0x92: the same member gets +0x18 = +0x1c = 0 (and the function returns) or, when missing, this->slot0x68(0x10, 0).
static u32 THISCALL fn4caed0(u8 *self, u32 k, u32 unused) {
  (void)unused;
  u16 di = (u16)k;
  if (di == *(u16 *)(self + 0x90)) {
    u8 *p = *(u8 **)(self + 0x8c);
    if (p) {
      *(u32 *)(p + 0x18) = *(u32 *)(self + 0x70);
      p = *(u8 **)(self + 0x8c);
      *(u32 *)(p + 0x1c) = *(u32 *)(self + 0x74);
    } else {
      vcall<void>(self, 0x64, 0x10u);
    }
  }
  if (di == *(u16 *)(self + 0x92)) {
    u8 *p = *(u8 **)(self + 0x8c);
    if (p) {
      *(u32 *)(p + 0x18) = 0;
      p = *(u8 **)(self + 0x8c);
      *(u32 *)(p + 0x1c) = 0;
      return 0;
    }
    vcall<void>(self, 0x68, 0x10u, 0u);
  }
  return 0;
}
PCREG(4caed0, fn4caed0);
