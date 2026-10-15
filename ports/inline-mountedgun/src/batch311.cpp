// batch311.cpp - mounted gun tree, batch 311: the last two nest natives of CFFTools_if: FireMachineGun and MGCanFireAt.
// Names from the GC CFFTools_if::addMethodDefinitions table, whose order matches the PC registration list
// (IsMachineGunFree, FireMachineGun, GetMachineGun, GetMachineGunInfo, MGCanFireAt).
// Script parameters (OpaqueCallParameters_t, see inline-recruits batch 1503): +4 the input block, +8 the output block;
// 0x5003d0(block, i) gives the address of value i: {dword value, byte type}. Types seen: 0 none, 1 int, 2 float, 4 an
// object with slot 0x24 (copy) and 0x28 (release) (inferred: string). A nest is talked to with its event slot 0x128
// (Command(msg id, data, 0)), the message id coming from database slot 0x114(name, 0, file, line).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef u32(THISCALL *vcallU0)(void *self);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);
typedef void(THISCALL *vcallVUUU)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *regMsg)(void *self, const char *name, u32 z, const char *file, u32 line);
typedef void *(THISCALL *logOpen)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *pr, const char *fmt, ...);
typedef void (*assertHook)();

extern "C" u8 *THISCALL ext_5003d0(void *block, u32 i);    // parameter accessor (batch 1503)
extern "C" void *THISCALL ext_5002f0(void *p, u32 v);      // set int parameter (batch 1503)
extern "C" void FASTCALL ext_4e09b0(float *v);             // vneg
extern "C" void FASTCALL ext_451890(float *dst, const float *src, float s);   // vaddscalar (batch 302)

static inline u8 *db() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *byRef(u32 ref) { return ((vcallPU)VT(db(), 0x58))(db(), ref); }
static inline u16 msgId(u32 name, u32 line) {
  return (u16)((regMsg)VT(db(), 0x114))(db(), (const char *)name, 0, (const char *)0x6a57fc, line);   // fftools_if.cpp
}
// Send a message to a nest; the nest's vtable is read before the id is registered, as in the original.
static inline void send(u8 *o, u32 name, u32 line, u32 data) {
  void **vt = *(void ***)o;
  u16 id = msgId(name, line);
  ((vcallVUUU)vt[0x128 / 4])(o, id, data, 0);
}

// The "wrong type" check of sdl_extendtypes.h (line 0x104): log "RAISE_EXCEPTION %s" "NO! WRONG TYPE", then the assert hook.
static void wrongType() {
  void *lg = G(void *, 0x700390);
  void *pr = ((logOpen)VT(lg, 0x20))(lg, (const char *)0x69c8e0, 0x104);
  ((logPrintf)VT(pr, 0x2c))(pr, (const char *)0x69c6b0, (const char *)0x69c938);
  assertHook h = G(assertHook, 0x7003b0);
  if (!h)
    asm volatile("int3");
  h();
}
static inline u32 getInt(u8 *p) {
  if (p[4] != 0 && p[4] != 1)
    wrongType();
  return *(u32 *)p;
}
static inline void setFloat(u8 *p, float f) {
  if (p[4] != 0 && p[4] != 2)
    wrongType();
  p[4] = 2;
  *(float *)p = f;
}

typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);

// 0x553690 CFFTools_if::FireMachineGun(OpaqueCallParameters_t&) (GameCube reference; position in the native list); thiscall,
// ret 4. In: shots (int, type-checked), nest. A GetItemWeapon id is registered (line 0x104, unused), then the nest is
// asked for its gun (GetItemWeapon, line 0x105). With shots > 0 (signed): gun slot 0x2d0(0, 0), slot 0x360(shots),
// slot 0x358(1), slot 0x2d0(3, 0) (inferred: reset, burst length, trigger, fire state 3, as in the tank's
// UpdateWeaponFireAndPos); otherwise only slot 0x2d0(0, 0) (stop).
static void THISCALL fireMachineGun(void *self, u8 *par) {
  (void)self;
  u32 shots = getInt(ext_5003d0(*(void **)(par + 4), 0));
  u8 *nest = byRef(*(u32 *)ext_5003d0(*(void **)(par + 4), 1));
  msgId(0x6a584c, 0x104);   // "GetItemWeapon", unused
  u32 w;
  send(nest, 0x6a584c, 0x105, (u32)&w);
  u8 *gun = byRef(w);
  if ((s32)shots > 0) {
    ((vcallVUU)VT(gun, 0x2d0))(gun, 0, 0);
    ((vcallVU)VT(gun, 0x360))(gun, shots);
    ((vcallVU)VT(gun, 0x358))(gun, 1);
    ((vcallVUU)VT(gun, 0x2d0))(gun, 3, 0);
  } else {
    ((vcallVUU)VT(gun, 0x2d0))(gun, 0, 0);
  }
}
PCREG(553690, fireMachineGun);

// 0x555f20 CFFTools_if::MGCanFireAt(OpaqueCallParameters_t&) (GameCube reference); thiscall, ret 4. In: nest, target (raw).
// Out 0 (int) = 1 when the nest's CanAimWeaponRef (line 0x19a) keeps the target (target inside the narrow arc).
static void THISCALL mgCanFireAt(void *self, u8 *par) {
  (void)self;
  u32 nest = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u32 t = *(u32 *)ext_5003d0(*(void **)(par + 4), 1);
  u8 *n = byRef(nest);
  send(n, 0x6a5874, 0x19a, (u32)&t);
  ext_5002f0(ext_5003d0(*(void **)(par + 8), 0), t != 0);
}
PCREG(555f20, mgCanFireAt);
