// batch310.cpp - unclaimed-03 batch 10 (docs/20-unclaimed-03.md): CEnemyFlag::SetFlagFrame(GameEntity::TEAM) at 0x5c2120.
// Name from the GC name map (high). The team picks a float from a small table (0x678858 = 1.0, 0x680a60 = 2.0, 0.0);
// then a render-manager chain calls two virtuals (slot +0x58 on one object, slot +0xe0 on another), both stubs in the spec.
#include "ff.h"

// 0x5c2120, CEnemyFlag::SetFlagFrame(GameEntity::TEAM) (high). Value by team (jump table at 0x5c219c): 0 -> 1.0, 1 -> 2.0,
// 2 -> 0.0, 3 -> 1.0, 4 -> 2.0, 5 -> 1.0, 6 -> 2.0, 7 -> 0.0; any other team -> 0.0 (unsigned compare with 7).
// Then if [[render mgr + 0x9b]]->vtbl[+0x58]() returns obj2 (not null): obj4 = [[render mgr + 0x1aa3] + 0x18], and
// obj4->vtbl[+0xe0](obj2->+8, value) (thiscall, two arguments, callee pops 8). Callee pops 4 (ret 4).
static void THISCALL enemyFlagSetFlagFrame(u8 *self, u32 team) {
  (void)self;
  static const float kValue[8] = {1.0f, 2.0f, 0.0f, 1.0f, 2.0f, 1.0f, 2.0f, 0.0f};
  float v = team < 8 ? kValue[team] : 0.0f;
  typedef u32(THISCALL * call0_fn)(void *);
  typedef void(THISCALL * call2_fn)(void *, u32, float);
  u8 *rm = (u8 *)G(u32, 0x70039c);
  void *o = (void *)*(u32 *)(rm + 0x9b);
  u32 obj2 = ((call0_fn)(*(u32 *)(*(u32 *)o + 0x58)))(o);
  if (!obj2) return;
  void *obj4 = (void *)*(u32 *)(*(u32 *)(rm + 0x1aa3) + 0x18);
  ((call2_fn)(*(u32 *)(*(u32 *)obj4 + 0xe0)))(obj4, *(u32 *)(obj2 + 8), v);
}
PCREG(5c2120, enemyFlagSetFlagFrame);
