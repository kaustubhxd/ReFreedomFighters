// batch607.cpp - damage thread, batch 607: ZFFHERO::PerformDie (the Hero's death sequence).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

extern "C" void THISCALL ext_466f60(void *self, u32 snd);  // ZIKLNKOBJ::PlaySound

typedef void *(THISCALL *vLog)(void *self, const char *file, u32 line);
typedef void (*vMsg)(void *self, const char *msg);
// RegisterZMsg (render manager slot 0x114) takes 4 args; the 0 pushed before it is the send's data argument.
typedef u16 (THISCALL *vMsgId)(void *self, const char *name, u32 a, const char *file, u32 line);
typedef void (THISCALL *vSend)(void *self, u32 to, u32 msg, u32 data);
typedef void *(THISCALL *vP0)(void *self);
typedef void (THISCALL *v0)(void *self);
typedef void (THISCALL *vU)(void *self, u32 a);
typedef void (THISCALL *vGet)(void *self, const char *name, void *out);

static const char *const kFile = (const char *)0x6ac6d0;

static inline u16 msgId(const char *name, u32 line) {
  u8 *rm = *(u8 **)(ENGINE + 0x9b);
  return ((vMsgId)VT(rm, 0x114))(rm, name, 0, kFile, line);
}

// 0x593cc0 ZFFHERO::PerformDie() (GC 800830d0).
//  Logs "Hero died", plays the death sound (+0xef6), sends "coolioOUT" to +0x846 when set, own slot 0x584(),
//  death time +0x817 = now (s), +0x81b = 0. The held item (slot 0x4f8 -> its slot 0x10) is released (slot 0x520(0),
//  slot 0x4f4(item)). Multiplayer (+0x9e7): the item joins the global list at [0x7003b8] (+0x8b4 count, +0x8b8 items,
//  no duplicates), MSG_REMOVEALLFROMINVENTORY to itself, +0x81b = 5.0. Single player: Msg_Music_HeroDead to the scene's
//  "LevelController", +0x81b = 3.0. Last: own slots 0x518(0) and 0x51c(0).
static void THISCALL performDie(u8 *self) {
  *(u32 *)(self + 0x9e3) = 0;
  self[0x827] = 0;
  u8 *lg = G(u8 *, 0x700390);
  u8 *o = (u8 *)((vLog)VT(lg, 0x20))(lg, kFile, 0x1003);
  ((vMsg)VT(o, 0x2c))(o, (const char *)0x6acf6c);  // "Hero died"
  ext_466f60(self, *(u32 *)(self + 0xef6));
  if (*(u32 *)(self + 0x846)) {
    u16 id = msgId((const char *)0x6acf78, 0x1005);  // "coolioOUT"
    ((vSend)VT(self, 0x12c))(self, *(u32 *)(self + 0x846), id, 0);
  }
  ((v0)VT(self, 0x584))(self);
  *(u32 *)(self + 0x81b) = 0;
  *(float *)(self + 0x817) = (float)*(s32 *)(ENGINE + 0x40) * 0.0009765625f;
  u8 *holder = (u8 *)((vP0)VT(self, 0x4f8))(self);
  u8 *item = (u8 *)((vP0)VT(holder, 0x10))(holder);
  if (item) {
    ((vU)VT(self, 0x520))(self, 0);
    ((vU)VT(self, 0x4f4))(self, (u32)item);
  }
  if (self[0x9e7]) {
    u8 *g = G(u8 *, 0x7003b8);
    u8 **it = (u8 **)(g + 0x8b8), **end = (u8 **)(g + (*(s32 *)(g + 0x8b4) + 0x22e) * 4);
    for (; it != end; ++it)
      if (*it == item) break;
    if (it == end) {
      *(u8 **)(g + *(s32 *)(g + 0x8b4) * 4 + 0x8b8) = item;
      ++*(s32 *)(g + 0x8b4);
    }
    u16 id = msgId((const char *)0x690a14, 0x1015);  // "MSG_REMOVEALLFROMINVENTORY"
    ((vSend)VT(self, 0x130))(self, (u32)self, id, 0);
    *(u32 *)(self + 0x81b) = 0x40a00000;  // 5.0
  } else {
    u8 *rm = *(u8 **)(ENGINE + 0x9b);
    u8 *scene = (u8 *)((vP0)VT(rm, 0x138))(rm);
    u32 ctrl = 0;
    ((vGet)VT(scene, 0x88))(scene, (const char *)0x6a5c48, &ctrl);  // "LevelController"
    u16 id = msgId((const char *)0x6a4f9c, 0x101b);                 // "Msg_Music_HeroDead"
    ((vSend)VT(self, 0x12c))(self, ctrl, id, 0);
    *(u32 *)(self + 0x81b) = 0x40400000;  // 3.0
  }
  ((vU)VT(self, 0x518))(self, 0);
  ((vU)VT(self, 0x51c))(self, 0);
}
PCREG(593cc0, performDie);
