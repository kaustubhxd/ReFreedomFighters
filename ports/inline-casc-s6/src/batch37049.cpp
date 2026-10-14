// batch37049.cpp - cascade s6 batch 37049: 0x4ac460.
#include "ff.h"

extern "C" u32 FASTCALL ext_4ace80(u8 *self, u8 *buf, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);   // ecx = this+0x44, edx = buf, 6 stack args, ret 0x18
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*cd4_t)(void *, u8 *, u32, u32);

static inline u8 *tabObj() { return *(u8 **)(*(u8 **)0x70039c + 0x9b); }

// 0x4ac460, thiscall, no args: for every item of the list embedded at this+0x11a (slots 0x4c / 0x5c) whose table object answers slot 0x1e0(0x1007d1) and whose state object
// (slot 0x2e8) answers a non-zero slot 0x300, builds a name string through the formatting object at [table+0xae4] (slot 0, twice) and the engine's slot 0x190 object (cdecl slot
// 0x198 into a 0x80-byte stack buffer), creates a record from it with 0x4ace80 (priority starting at 100 and falling by 10 per item), looks the record's allocator object up
// (0x70038c slot 0xcc) and, when found, stores the table's slot-0x4c id of the object at +0x106 and hands the record to slot 4 of the object embedded at this+0x1c6.
static void THISCALL fn4ac460(u8 *self) {
  u8 buf[0x84];
  void *l = self + 0x11a;
  u32 v;
  (*(v1_t **)l)[0x4c / 4](l, (u32)&v);
  u32 item = (*(v1_t **)l)[0x5c / 4](l, (u32)&v);
  if (v == 0) return;
  u32 prio = 0x64;
  do {
    u8 *t = tabObj();
    u8 *o = (u8 *)(*(v1_t **)t)[0x58 / 4](t, item);
    if (o && (u8)(*(v1_t **)o)[0x1e0 / 4](o, 0x1007d1)) {
      u8 *st = (u8 *)(*(v0_t **)o)[0x2e8 / 4](o);
      if ((*(v0_t **)st)[0x300 / 4](st) != 0) {
        u32 nm = *(u32 *)(st + 4);
        if (!nm) nm = 0x67c8e8;
        void *x = *(void **)(tabObj() + 0xae4);
        u32 r1 = (*(v2_t **)x)[0]((x), 0x6889b8, 0x6889b0);
        x = *(void **)(tabObj() + 0xae4);
        u32 r2 = (*(v2_t **)x)[0]((x), 0x68899c, nm);
        u8 *e = *(u8 **)0x70039c;
        u8 *obj = (u8 *)(*(v0_t **)e)[0x190 / 4](e);
        (*(cd4_t **)obj)[0x198 / 4](obj, buf, r1, r2);
        u32 rec = ext_4ace80(*(u8 **)(self + 0x44), buf, (u32)buf, 0, 0, 0, prio, 0);
        prio -= 10;
        u8 *g = *(u8 **)0x70038c;
        u8 *w = (u8 *)(*(v1_t **)g)[0xcc / 4](g, rec);
        if (w) {
          t = tabObj();
          u32 id = (*(v1_t **)t)[0x4c / 4](t, (u32)o);
          *(u32 *)(w + 0x106) = id;
          void *sub = self + 0x1c6;
          (*(v1_t **)sub)[4 / 4](sub, rec);
        }
      }
    }
    item = (*(v1_t **)l)[0x5c / 4](l, (u32)&v);
  } while (v != 0);
}
PCREG(4ac460, fn4ac460);
