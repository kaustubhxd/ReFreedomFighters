// batch37100.cpp - cascade s6 batch 37100: 0x575f90.
#include "ff.h"

extern "C" void THISCALL ext_576a30(u8 *self, u32 a);             // ret 4
extern "C" u32 THISCALL ext_573860(u8 *self, u32 id, u32 arg);    // ret 8
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd2_t)(void *, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline u16 idOf(u32 name, u32 line) { return (u16)vcall<u32>(tabObj(), 0x114, name, 0u, 0x6a945cu, line); }

// 0x575f90, thiscall(msg, arg) ret 8: message handler keyed by registered names (table slot 0x114 gives their ids, compared as 16-bit values): 0x6a77ac clears +0x20b; 0x6a77a0
// forwards arg through 0x576a30 (arg required, else error 0x13e is logged); 0x6a6698 forwards the record at [+0x94]+0x48, clears +0x20b, tells the owner (slot 0x84 -> 0x2fc),
// updates the table object (slot 0xb4) and the engine window object at +0x1a9f (slot 0x138); 0x6a9300 sets +0x20f; anything else goes to 0x573860.
static u32 THISCALL fn575f90(u8 *self, u32 msg, u32 arg) {
  u16 id = (u16)msg;
  if (id == idOf(0x6a77ac, 0x131)) {
    self[0x20b] = 0;
    return 0;
  }
  if (id == idOf(0x6a77a0, 0x136)) {
    if (arg) {
      ext_576a30(self, arg);
      return 0;
    }
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6a945c, 0x13e);
    (*(cd2_t **)L)[0x2c / 4](L, 0x6a9488);
    return 0;
  }
  if (id == idOf(0x6a6698, 0x142)) {
    ext_576a30(self, D32(self, 0x94) + 0x48);
    self[0x20b] = 0;
    void *o = (void *)vcall<u32>(self, 0x84);
    vcall<void>(o, 0x2fc, D32(self, 0x44));
    vcall<void>(tabObj(), 0xb4, 1u);
    void *w = *(void **)(*(u8 **)0x70039c + 0x1a9f);
    if (w) vcall<void>(w, 0x138, 1u);
    return 0;
  }
  if (id == idOf(0x6a9300, 0x14c)) {
    self[0x20f] = 1;
    return 0;
  }
  return ext_573860(self, msg, arg);
}
PCREG(575f90, fn575f90);
