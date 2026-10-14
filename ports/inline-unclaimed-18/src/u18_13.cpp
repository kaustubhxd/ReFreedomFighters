// u18_13.cpp - core-todo residue 17 (unclaimed-18 thread): three functions. Engine call argument counts are from the exe
// call sites: slot 0x114 (RegisterZMsg) takes FOUR arguments (ret 0x10); slot 0x128 takes three on the geom classes (ret 0xc).
#include "ff.h"

static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline u8 *engineDb() { return *(u8 **)(sys() + 0x9b); }

static inline float readFloatUnaligned(const u8 *p) {
  float f;
  for (int q = 0; q < 4; ++q)
    ((u8 *)&f)[q] = p[q];
  return f;
}

// 0x438110, ZInputActions::CheckActionDigital(name, arg) (GC map high). thiscall, two stack args (ret 8). If slot 0x38
// (name, arg) is false, the answer is false. Otherwise the magnitude of the signed byte from slot 0xa4(name) is compared
// with 0x40: the answer is (|v| > 64).
static bool THISCALL checkActionDigital(u8 *self, const char *name, u32 arg) {
  if (!vcall<u8>(self, 0x38, name, arg))
    return false;
  s32 v = (s8)vcall<u8>(self, 0xa4, name);
  if (v < 0)
    v = -v;
  return v > 0x40;
}
PCREG(438110, checkActionDigital);

// 0x4e7110, ZRunParamAnim::Save(ZSaveGame*) (GC map medium). thiscall, one stack arg (ret 4). Writes a float (+0xb8),
// the byte at +0xbc, and an unaligned float at +0xbd, through the save object's slots 0x4c, 0x60 and 0x4c.
static void THISCALL runParamAnimSave(u8 *self, u8 *sg) {
  vcall<void>(sg, 0x4c, readFloatUnaligned(self + 0xb8));
  vcall<void>(sg, 0x60, (u32)self[0xbc]);
  vcall<void>(sg, 0x4c, readFloatUnaligned(self + 0xbd));
}
PCREG(4e7110, runParamAnimSave);

// 0x5eafd0, unnamed (GC name is ZFFActionThrow::CallBack, low confidence; str "ActionDone"). thiscall, no args; returns 0.
// Registers the message "ActionDone" (file ZFFActorActions.cpp, line 0x10c) with the engine and sends the id to the object
// at +8 through its slot 0x128 (one argument).
static bool THISCALL actionDoneCallBack(u8 *self) {
  u8 *o = *(u8 **)(self + 8);
  u16 id = vcall<u16>(engineDb(), 0x114, (const char *)0x6a5688, 0u, (const char *)0x6b80b4, 0x10cu);
  vcall<void>(o, 0x128, (u32)id, 0u, 0u);   // leftover pushes of the exe as arguments 2 and 3
  return false;
}
PCREG(5eafd0, actionDoneCallBack);
