// batch38012.cpp - cascade s8 batch 38012: 0x4b6b90 (refresh the entity for a request).
#include "ff.h"

extern "C" u32 THISCALL ext_4b48c0(u8 *self, u32 a);   // ret 4
extern "C" u32 THISCALL ext_4db9a0(u8 *node, u32 flags);   // ret 4
extern "C" void THISCALL ext_4b3a70(u8 *self);
extern "C" void THISCALL ext_4dc030(u8 *node);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))

// 0x4b6b90, thiscall(req) ret 4. Looks the request's node up in the table (slot 0x54 of [eng+0x9b]); when 0x4b48c0 finds a live entity for it, the entity is refreshed
// through its virtual slots (0x1e0 flag tests, 0x588, the 0x80/0x1b0/0x2f8/0x370 chain when req[4] is set, the 0x504 / 0x500 helpers) and handed the table's slot 0x4c value through
// slot 0x128; otherwise the node itself is checked (0x4db9a0), 0x4b3a70 runs when it is the current one (+0x84) and the node's +0x54 object gets the same slot 0x128 update.
// When req[0x10] is set 0x4dc030 runs on the node last.
static void THISCALL fn4b6b90(u8 *self, u8 *req) {
  u8 *t = TABLE;
  u8 *node = (u8 *)SLOT(t, 0x54, v1_t)(t, *(u32 *)req);
  if (!node) return;
  u8 *e = (u8 *)ext_4b48c0(self, *(u32 *)(node + 0x54));
  if (e) {
    if ((u8)SLOT(e, 0x1e0, v1_t)(e, 0x80200014) && self[0x9d]) {
      self[0x9d] = 0;
      SLOT(e, 0x588, v0_t)(e);
    }
    if (*(u32 *)(req + 4)) {
      u8 l34[0x24], l10[0xc];
      SLOT(e, 0x80, v2_t)(e, (u32)l34, (u32)l10);
      SLOT(e, 0x1b0, v0_t)(e);
      SLOT(e, 0x2f8, v1_t)(e, 0);
      SLOT(e, 0x370, v2_t)(e, (u32)l34, (u32)l10);
    } else {
      SLOT(e, 0x1b0, v0_t)(e);
    }
    if ((u8)SLOT(e, 0x1e0, v1_t)(e, 0x200073)) {
      if (SLOT(e, 0x504, v0_t)(e)) {
        u8 *p = (u8 *)SLOT(e, 0x504, v0_t)(e);
        SLOT(p, 0xbc, v1_t)(p, 0);
      }
      if (SLOT(e, 0x500, v0_t)(e)) {
        u8 *p = (u8 *)SLOT(e, 0x500, v0_t)(e);
        SLOT(p, 0xbc, v1_t)(p, 0);
      }
    }
    u8 **vt = *(u8 ***)e;
    t = TABLE;
    u32 v = SLOT(t, 0x4c, v1_t)(t, *(u32 *)(self + 0x44));
    ((v3_t)vt[0x128 / 4])(e, *(u16 *)(self + 0x50), v, 0);
  } else {
    if ((u8)ext_4db9a0(node, 0x400003)) {
      t = TABLE;
      u32 cur = SLOT(t, 0x50, v1_t)(t, (u32)node);
      if (*(u32 *)(self + 0x84) == cur) ext_4b3a70(self);
    }
    u8 *c = *(u8 **)(node + 0x54);
    SLOT(c, 0x1b0, v0_t)(c);
    t = TABLE;
    u32 v = SLOT(t, 0x4c, v1_t)(t, *(u32 *)(self + 0x44));
    c = *(u8 **)(node + 0x54);
    if (c) SLOT(c, 0x128, v3_t)(c, *(u16 *)(self + 0x50), v, 0);
  }
  if (*(u32 *)(req + 0x10)) ext_4dc030(node);
}
PCREG(4b6b90, fn4b6b90);
