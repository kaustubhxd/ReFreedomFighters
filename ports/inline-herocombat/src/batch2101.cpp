// batch2101.cpp - hero and combat wiring thread (wire-hero-combat), batch 2101: ZAnimDefsList::GetAnim, the callee
// GetAnimFromStatus 0x5e3dd0 reaches through ZAnimDefsList vtable 0x68b604 slot 0x10. Lifted 2026-10-13 from the exe
// (an earlier lift, inline-anim batch820, has only a 1-case doc row; this one is written plain so the wasm build can use it).
#include "ff.h"

typedef void(THISCALL *vcallIt)(void *self, u32 *it);
typedef u32 *(THISCALL *vcallNext)(void *self, u32 *it);

// 0x4837e0, thiscall, one stack arg (the anim id), ret 4. First stamps the list's last-use time +0xc with the engine
// clock [[0x70039c]+0x40] (int ticks) times the float at 0x6785e4 (1/1024). With a node list at +0x14 (slot 0x4c starts
// an iterator in a 12-byte local, slot 0x64 returns the next node or 0), the first node whose +4 equals the id makes its
// +0 the current anim +4. Returns the current anim +4. Name ZAnimDefsList::GetAnim .
static u32 THISCALL getAnim(u8 *self, u32 id) {
  u8 *sys = G(u8 *, 0x70039c);
  *(float *)(self + 0xc) = (float)*(s32 *)(sys + 0x40) * G(float, 0x6785e4);
  void *list = *(void **)(self + 0x14);
  if (list != 0) {
    u32 it[3];
    ((vcallIt)(*(void ***)list)[0x4c / 4])(list, it);
    u32 *n = ((vcallNext)(*(void ***)(*(void **)(self + 0x14)))[0x64 / 4])(*(void **)(self + 0x14), it);
    while (n != 0) {
      if (n[1] == id) {
        *(u32 *)(self + 4) = n[0];
        return n[0];
      }
      list = *(void **)(self + 0x14);
      n = ((vcallNext)(*(void ***)list)[0x64 / 4])(list, it);
    }
  }
  return *(u32 *)(self + 4);
}
PCREG(4837e0, getAnim);
