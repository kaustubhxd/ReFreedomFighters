// batch604.cpp - damage thread, batch 604: ZFFHERO::AdjustHitPoints (every change to the Hero's health).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

extern "C" void THISCALL ext_5a5be0(void *self, float amount);  // OSD damage flash (unnamed)
extern "C" void THISCALL ext_5e0dd0(void *osd, float ratio);    // ZGameOSD::SetHealth

typedef void *(THISCALL *vP0)(void *self);
typedef void *(THISCALL *vPU)(void *self, u32 a);
typedef void (THISCALL *vGet)(void *self, const char *name, void *out);
// Render manager slot 0x114 is ZEngineDataBase::RegisterZMsg(name, flags, file, line) (4 args); MSVC pushed the send's
// data argument before it, so the message send (own slot 0x12c) takes (to, msg id, data).
typedef u16 (THISCALL *vMsgId)(void *self, const char *name, u32 a, const char *file, u32 line);
typedef void (THISCALL *vSend)(void *self, u32 to, u32 msg, void *data);

// 0x58b9c0 ZFFHERO::AdjustHitPoints(float delta, unsigned int owner, bool force) (GC 8007dbbc). Returns the new HP
// in ST0. Fields: +0x7ff HP, +0x7fb max HP, +0x9f4 tutorial byte, +0x653 damage-flash enable, +0x852 OSD.
//  Tutorial damage (delta < 0): HP below half max -> delta *= 0.45 * HP / max + 0.05; otherwise delta doubles.
//  The god-mode float 0x6ffa60 (cheats) blocks the change unless `force`. HP is clamped to max (not to 0).
//  Damage flash: OSD +0x1d0f gets -delta / max * 5. At HP <= 0 in a multiplayer game ("Multiplayer" option) with
//  an owner: MSG_MP_KILL {owner, own handle} to the "GameController". Last: OSD SetHealth(HP / max).
static float THISCALL adjustHitPoints(u8 *self, float delta, u32 owner, u8 force) {
  float *hp = (float *)(self + 0x7ff), *mx = (float *)(self + 0x7fb);
  if (self[0x9f4] && 0.0f > delta) {
    if (*mx * 0.5f > *hp)
      delta *= *hp * 0.45f / *mx + 0.05f;
    else
      delta += delta;
  }
  if (G(float, 0x6ffa60) == 0.0f || force) *hp = *hp + delta;
  float m = *mx;
  if (*hp > m) *hp = m;
  if (self[0x653] && 0.0f > delta) {
    u32 q = fbits(delta / m);
    asm("" : "+r"(q));                         // keep clang from moving the sign flip before the divide
    u32 neg = q ^ 0x80000000u;                 // xorps with 0x67af40 (flips a NaN's sign too)
    asm("" : "+r"(neg));
    float a = bitsf(neg) * 5.0f;               // * 5 (0x679544)
    ext_5a5be0(*(u8 **)(*(u8 **)(self + 0x852) + 0x1d0f), a);
  }
  if (*hp <= 0.0f) {
    u8 *rm = *(u8 **)(ENGINE + 0x9b);
    u8 *opts = (u8 *)((vP0)VT(rm, 0x134))(rm);
    u8 isMp = 0;
    ((vGet)VT(opts, 0x90))(opts, (const char *)0x68a9d4, &isMp);  // "Multiplayer"
    if (isMp && owner) {
      u32 data[2];
      data[0] = owner;
      rm = *(u8 **)(ENGINE + 0x9b);
      data[1] = (u32)((vPU)VT(rm, 0x4c))(rm, (u32)self);
      rm = *(u8 **)(ENGINE + 0x9b);
      u8 *scene = (u8 *)((vP0)VT(rm, 0x138))(rm);
      u32 ctrl = 0;
      ((vGet)VT(scene, 0x88))(scene, (const char *)0x67a1b8, &ctrl);  // "GameController"
      rm = *(u8 **)(ENGINE + 0x9b);
      u16 id = ((vMsgId)VT(rm, 0x114))(rm, (const char *)0x6ace1c, 0, (const char *)0x6ac6d0, 0x9ae);
      ((vSend)VT(self, 0x12c))(self, ctrl, id, data);  // "MSG_MP_KILL" {owner, own handle}
    }
  }
  u8 *osd = *(u8 **)(self + 0x852);
  if (osd) ext_5e0dd0(osd, *hp / *mx);
  return *hp;
}
PCREG(58b9c0, adjustHitPoints);
