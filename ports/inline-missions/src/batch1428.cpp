// batch1428.cpp - missions thread, batch 1428: ZObjectives::DrawUpdate (the objectives map overlay).
// Interface slots are unnamed (GUESS names in comments only; the code uses the slot numbers):
//   ZSysInterface slot 0xbc() -> object, its slot 0xdc() -> bool ("map open" test);
//   object at [this+0x1ec] slot 0x84(float*) fills 3 floats; object at [this+0x180] slot 0x20() -> object, whose slot
//   0x70(float*) moves the icon; object at [this+0x188] slot 0x70(float*) likewise.
// ZBaseMap::GetScreenPos (0x573c70) and ZBaseMap::DrawUpdate (0x573930) are other areas' code, called directly.
#include "missions.h"

extern "C" void THISCALL ext_573c70(u8 *self, u32 id, float *out);       // ZBaseMap::GetScreenPos(unsigned, float[2]&)
extern "C" void THISCALL ext_573930(u8 *self, u8 *cam, u32 id);          // ZBaseMap::DrawUpdate(ZCAMERA*, EDrawID)

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
// The unnamed slots, by number.
static inline u8 *slot0bc_obj() { return ((u8 *(THISCALL *)(u8 *))(*(void ***)sysi())[0xbc / 4])(sysi()); }
static inline u8 slot0dc(u8 *o) { return ((u8(THISCALL *)(u8 *))(*(void ***)o)[0xdc / 4])(o); }
static inline u8 *slot20(u8 *o) { return ((u8 *(THISCALL *)(u8 *))(*(void ***)o)[0x20 / 4])(o); }
static inline void slot70(u8 *o, float *v) { ((void(THISCALL *)(u8 *, float *))(*(void ***)o)[0x70 / 4])(o, v); }
static inline void slot84(u8 *o, float *v) { ((void(THISCALL *)(u8 *, float *))(*(void ***)o)[0x84 / 4])(o, v); }

// 0x577bb0 ZObjectives::DrawUpdate(ZCAMERA *cam, EDrawID id).
//  - [this+0x88] == 0: nothing.
//  - sys.slot0xbc().slot0xdc() false: ZBaseMap::DrawUpdate(cam, id).
//  - otherwise, when [this+0x1f1] is set: the icon from [this+0x1ec].slot84 is placed through GetScreenPos([this+0x1c4]),
//    then [this+0x180].slot20().slot70 and [this+0x188].slot70 get the moved vector: v[0] = (float)sys_int(+0x6f)
//    minus 2*v0 (after the screen scale), v[1] = 20.0, v[2] = 0 (the int at sys+0x6f is scaled by 1/8 first).
//    [this+0x1f1] is cleared.
static void THISCALL zobjDrawUpdate(u8 *self, u8 *cam, u32 id) {
  if (!self[0x88])
    return;
  u8 *o = slot0bc_obj();
  if (!slot0dc(o)) {
    ext_573930(self, cam, id);
    return;
  }
  if (!self[0x1f1])
    return;
  float v[3];
  v[0] = 0.0f;
  v[1] = 0.0f;
  v[2] = 0.0f;
  slot84(*(u8 **)(self + 0x1ec), v);
  ext_573c70(self, *(u32 *)(self + 0x1c4), v);
  float w = (float)(s32)((float)(s32)*(s32 *)(sysi() + 0x6f) * 0.125f);   // see note above
  v[0] = w;
  u8 *x = slot20(*(u8 **)(self + 0x180));
  slot70(x, v);
  float dbl = v[0] * 2.0f;
  float s = (float)(s32)*(s32 *)(sysi() + 0x6f) - dbl;
  v[0] = s;
  v[1] = 20.0f;
  v[2] = 0.0f;
  slot70(*(u8 **)(self + 0x188), v);
  self[0x1f1] = 0;
}
PCREG(577bb0, zobjDrawUpdate);
