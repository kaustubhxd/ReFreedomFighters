// batch524.cpp - weapons thread, batch 524: ZLNKWHANDS::ControlPushButton and ZLNKWHANDS::ControlPickup (generic
// versions; the hero has its own ControlPickup). Hand action ids: 1 / 2 push a button (left hand free / busy),
// 5 put the left item away, 6 put the right item away, 9 drop left, 0xa drop right. The current action is read
// again (slot 0x3f0) at every test, as in the exe.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u8(THISCALL *vBU)(void *self, u32 a);

static inline u32 act(u8 *s) { return ((vU0)VT(s, 0x3f0))(s); }
static inline void add(u8 *s, u32 id, u32 h) { ((vUUU)VT(s, 0x45c))(s, id, h); }

// 0x473240 ControlPushButton(geom): only when no action runs; action 1 when the left hand is empty (type slot
// 0x514 == 0), else 2, with the button's handle.
static void THISCALL controlPushButton(u8 *s, u32 geom) {
  if (act(s))
    return;
  u32 lt = ((vU0)VT(s, 0x514))(s);
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 h = ((vUU)VT(rm, 0x4c))(rm, geom);
  add(s, lt ? 2 : 1, h);
}
PCREG(473240, controlPushButton);

static inline u32 itemSize(u8 *it) {
  u8 *t = (u8 *)((vU0)VT(it, 0x2e8))(it);
  return ((vU0)VT(t, 0x308))(t);
}

// 0x4730b0 ControlPickup(item): returns 0 (nothing to do / busy), 1 or 2 (hands being made free first). Nothing
// during actions 3 and 4. Items of class 0x1007da (guess: carried objects that need the left hand) first free the
// left hand: put away (5) a size-0 item, otherwise drop it (9). Other items need action 4 and free the right hand:
// drop (0xa) an item in state 2, put away (6) a size-0 item; a larger item returns 2 without an action.
static u32 THISCALL controlPickup(u8 *s, u8 *item) {
  if (act(s) == 4)
    return 0;
  if (act(s) == 3)
    return 0;
  ((vU0)VT(item, 0x2e8))(item);
  if (((vBU)VT(item, 0x1e0))(item, 0x1007da)) {
    if (act(s) == 3)
      return 0;
    u8 *l = (u8 *)((vU0)VT(s, 0x500))(s);
    if (!l)
      return 1;
    if (!itemSize(l)) {
      if (act(s) == 5)
        return 0;
      add(s, 5, 0);
      return 1;
    }
    if (act(s) == 9)
      return 0;
    add(s, 9, 0);
    return 1;
  }
  if (act(s) != 4)
    return 0;
  u8 *r = (u8 *)((vU0)VT(s, 0x504))(s);
  if (!r)
    return 2;
  u8 *t = (u8 *)((vU0)VT(r, 0x2e8))(r);
  if (((vU0)VT(t, 0x300))(t) == 2) {
    if (act(s) == 0xa)
      return 0;
    add(s, 0xa, 0);
    return 2;
  }
  if (itemSize(r))
    return 2;
  if (act(s) == 6)
    return 0;
  add(s, 6, 0);
  return 2;
}
PCREG(4730b0, controlPickup);
