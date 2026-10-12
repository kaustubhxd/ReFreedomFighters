// batch264.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch264"): stopping a scripted
// train and the item bomb constructor. Names from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);   // base constructor (verified in inline-mountedgun; runs as exe code)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

typedef void(THISCALL *send128_t)(u8 *, u32, u32, u32);

// Sends RegisterZMsg(msg, 0, ZFFSimpleTrain2.cpp, line) to g with SendCommand slot 0x128 (cmd, 0, 0). The two zero words
// are pushed before RegisterZMsg's four; g's vtable is read before the db call, as in the exe.
static void sendMsg(u8 *g, u32 msg, u32 line) {
  u8 *gv = *(u8 **)g;
  u32 r = vcall<u32>(DB, 0x114, msg, 0u, 0x6b2690u, line);
  (*(send128_t *)(gv + 0x128))(g, (u16)r, 0u, 0u);
}

// 0x5b9250 ZFFSimpleTrain2::Stop() (no args): "MSG_PATHS_ON" (line 0xd1) to the path object at +0xe2 when set;
// "Msg_FFVehicle_Stop" (line 0xd9) to every geom of the wagon list at [+0x4c] (vt 0x4c start, vt 0x5c next) when set,
// and (line 0xdc) to the engine geom of id +0x48; then byte +0xdd = 1.
static void THISCALL trainStop_5b9250(u8 *self) {
  if (*(u8 **)(self + 0xe2)) {
    u8 *pv = **(u8 ***)(self + 0xe2);
    u32 r = vcall<u32>(DB, 0x114, 0x6b26f4u, 0u, 0x6b2690u, 0xd1u);
    (*(send128_t *)(pv + 0x128))(*(u8 **)(self + 0xe2), (u16)r, 0u, 0u);
  }
  if (*(u8 **)(self + 0x4c)) {
    u32 it[3];
    vcall<void>(*(u8 **)(self + 0x4c), 0x4c, (u32)it);
    u32 id = vcall<u32>(*(u8 **)(self + 0x4c), 0x5c, (u32)it);
    while (it[0]) {
      sendMsg((u8 *)vcall<u32>(DB, 0x58, id), 0x6b2704u, 0xd9u);
      id = vcall<u32>(*(u8 **)(self + 0x4c), 0x5c, (u32)it);
    }
  }
  sendMsg((u8 *)vcall<u32>(DB, 0x58, *(u32 *)(self + 0x48)), 0x6b2704u, 0xdcu);
  self[0xdd] = 1;
}
PCREG(5b9250, trainStop_5b9250);

// 0x5d4090 ZFFItemBomb::ZFFItemBomb() (no args), returns this: base constructor 0x469870; flag 0x20 at +4; +0x44 = 0;
// vtable 0x6b5204; message ids "EXPLODE_explode", "MSG_ITEMNOTIFY", "Activate", "MSG_EVENT_STARTED" (ZFFItemBomb.cpp
// lines 0x19 to 0x1c) into the words +0x4e, +0x50, +0x52, +0x54; +0x5f, +0x63, +0x48, +0x67 = 0.
static u8 *THISCALL itemBombCtor_5d4090(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5204u;
  *(u16 *)(self + 0x4e) = (u16)vcall<u32>(DB, 0x114, 0x6b52bcu, 0u, 0x6b5288u, 0x19u);
  *(u16 *)(self + 0x50) = (u16)vcall<u32>(DB, 0x114, 0x6b2da8u, 0u, 0x6b5288u, 0x1au);
  *(u16 *)(self + 0x52) = (u16)vcall<u32>(DB, 0x114, 0x682e18u, 0u, 0x6b5288u, 0x1bu);
  *(u16 *)(self + 0x54) = (u16)vcall<u32>(DB, 0x114, 0x6b2d24u, 0u, 0x6b5288u, 0x1cu);
  *(u32 *)(self + 0x5f) = 0;
  *(u32 *)(self + 0x63) = 0;
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x67) = 0;
  return self;
}
PCREG(5d4090, itemBombCtor_5d4090);
#undef DB
