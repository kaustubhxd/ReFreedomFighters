// batch1603.cpp - the script natives FFActor_If.PlaySound_Enum and PlaySound_Enum_GetTime (soundtimers thread).
//
// PC addresses found through the method tables: GC ZFFActorIf::addMethodDefinitions registers 103
// methods from the PMF table at 803eb120; PC's (0x55cfb0) registers 104 into 0x713f18 in the same order with one
// extra method between GC index 27 and 56 (anchors: 15 name-map pairs, all at PC index = GC index or GC index + 1).
// GC 72 PlaySound_EnumBased -> PC 73 0x55baa0; GC 73 PlaySound_EnumBased_GetTime -> PC 74
// 0x55bad0. The bodies agree (both call ZFFActor vtable +0x6e8 = PlaySound_Enum, slot 442).
//
// Script call frame (OpaqueCallParameters_t): +4 the argument view, +8 the result view; ext_5003d0(view, i) returns
// the address of slot i (8 bytes: value, then a type byte at +4; 2 = float).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
extern "C" u8 *THISCALL ext_5003d0(void *view, u32 i);

// 0x55baa0 ZFFActorIf::PlaySound_EnumBased(OpaqueCallParameters_t&): PlaySound_Enum(byte arg 0, false, 0) on the
// interface's actor (+0x1c); the handle is dropped.
void THISCALL ZFFActorIf_PlaySound_EnumBased(void *self, u8 *params) {
  u8 *a0 = ext_5003d0(AT(void *, params, 4), 0);
  vcall<u32>(AT(void *, self, 0x1c), 0x6e8, (u32)*a0, (u32)0, (u32)0);
}
PCREG(55baa0, ZFFActorIf_PlaySound_EnumBased);

// 0x55bad0 ZFFActorIf::PlaySound_EnumBased_GetTime(OpaqueCallParameters_t&): PLAYS the shout (PlaySound_Enum(arg 0,
// false, 0)) and returns, as a float, the started sound's time left (+0x70, its full length at start), or 0.0 when
// nothing started (refused by CanIPlay, no table sound, or the handle has no object). Not a timer lookup.
// A result slot whose type is neither 0 nor 2 raises the engine's "NO! WRONG TYPE" exception (the handler at
// *0x7003b0, int3 without one) before the store.
void THISCALL ZFFActorIf_PlaySound_EnumBased_GetTime(void *self, u8 *params) {
  float t = 0.0f;
  u8 *a0 = ext_5003d0(AT(void *, params, 4), 0);
  u32 h = vcall<u32>(AT(void *, self, 0x1c), 0x6e8, (u32)*a0, (u32)0, (u32)0);
  u8 *o = vcall<u8 *>(AT(void *, sys(), 0x9b), 0x60, h);
  if (o) t = AT(float, o, 0x70);
  u8 *res = ext_5003d0(AT(void *, params, 8), 0);
  u8 ty = res[4];
  if (ty != 0 && ty != 2) {
    void *log = G(void *, 0x700390);
    void *ch = vcall<void *>(log, 0x20, (const char *)0x69c8e0, (u32)0x104);  // source file, line 0x104
    typedef void (*Printf)(void *, const char *, const char *);
    (*(Printf *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x69c6b0, (const char *)0x69c938);  // cdecl, "RAISE_EXCEPTION %s"
    typedef void (*Handler)();
    Handler handler = G(Handler, 0x7003b0);
    if (!handler) __builtin_trap();
    handler();
  }
  res[4] = 2;
  AT(float, res, 0) = t;
}
PCREG(55bad0, ZFFActorIf_PlaySound_EnumBased_GetTime);
