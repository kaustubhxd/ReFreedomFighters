// batch307.cpp - mounted gun tree, batch 307: script natives of CFFTools_if (fftools_if.cpp) that let the AI use nests:
// CalcMachineGunStandPosition, IsMachineGunFree, GetMachineGunInfo.
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
extern "C" void THISCALL ext_5520c0(void *self, u32 nest, u32 unused, float *out);   // this batch

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

// 0x5520c0 CFFTools_if::CalcMachineGunStandPosition(unsigned int nest, unsigned int, float *out), GC map [low]; thiscall
// (this unused), ret 0xc. Asks the nest for its center (GetCenter, line 0x3f0), takes the center geom's matrix and
// position (slot 0x80), swaps matrix rows 1 and 2, negates row 0, and returns position + 58 * row0 - 106 * row1 +
// 3.66 * row2: where a soldier stands to man the gun. (The gunner placement in 0x5c8650 uses 58.65 and -3.66.)
static void THISCALL calcMachineGunStandPosition(void *self, u32 nest, u32 unused, float *out) {
  (void)self;
  (void)unused;
  u8 *n = byRef(nest);
  u32 center;
  send(n, 0x6a585c, 0x3f0, (u32)&center);   // "GetCenter"
  u8 *c = byRef(center);
  float m[9], p[3];
  ((vcallVPP)VT(c, 0x80))(c, m, p);
  for (int i = 0; i < 3; i++) {
    float t = m[3 + i];
    m[3 + i] = m[6 + i];
    m[6 + i] = t;
  }
  ext_4e09b0(m);
  ext_451890(p, m, 58.0f);
  ext_451890(p, m + 3, -106.0f);
  ext_451890(p, m + 6, 3.66f);
  out[0] = p[0];
  out[1] = p[1];
  out[2] = p[2];
}
PCREG(5520c0, calcMachineGunStandPosition);

// 0x555a40 CFFTools_if::IsMachineGunFree(OpaqueCallParameters_t&), GC map [low]; thiscall, ret 4.
// In: nest, me. Out 0 (int): 1 when the nest's user (GetOwner, line 0xdc) is me; 0 when someone else uses it;
// with no user: 1 when not reserved (GetReservedBy, line 0xed) or reserved by me, else 0.
static void THISCALL isMachineGunFree(void *self, u8 *par) {
  (void)self;
  u32 nest = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u32 me = *(u32 *)ext_5003d0(*(void **)(par + 4), 1);
  u8 *n = byRef(nest);
  u32 owner, by;
  send(n, 0x6a5830, 0xdc, (u32)&owner);   // "GetOwner"
  u32 v;
  if (owner == me) {
    v = 1;
  } else if (owner != 0) {
    v = 0;
  } else {
    send(n, 0x6a583c, 0xed, (u32)&by);   // "GetReservedBy"
    v = (by == 0 || by == me) ? 1 : 0;
  }
  ext_5002f0(ext_5003d0(*(void **)(par + 8), 0), v);
}
PCREG(555a40, isMachineGunFree);

// 0x5544f0 CFFTools_if::GetMachineGunInfo(OpaqueCallParameters_t&), GC map [high]; thiscall, ret 4.
// In: nest (int), me (int). Reserves the nest for me (MakeReservation, line 0x18c; 2 s, batch 304) and returns
// out 0 = the nest parameter (copied as a value: a type-4 value is copied with its slot 0x24, an old type-4 output is
// released with slot 0x28 first) and out 1..3 = the stand position (floats).
static void THISCALL getMachineGunInfo(void *self, u8 *par) {
  u8 *p0 = ext_5003d0(*(void **)(par + 4), 0);
  u32 nest = getInt(p0);
  u8 *p1 = ext_5003d0(*(void **)(par + 4), 1);
  u32 me = getInt(p1);
  float pos[3];
  ext_5520c0(self, nest, 0, pos);
  u8 *n = byRef(nest);
  send(n, 0x6a5884, 0x18c, me);   // "MakeReservation"
  u8 *src = ext_5003d0(*(void **)(par + 4), 0);
  u8 *dst = ext_5003d0(*(void **)(par + 8), 0);
  if (src != dst) {
    if (dst[4] == 4) {
      u8 *o = *(u8 **)dst;
      ((vcallV0)VT(o, 0x28))(o);
    }
    u32 v;
    if (src[4] == 4) {
      u8 *o = *(u8 **)src;
      v = ((vcallU0)VT(o, 0x24))(o);
    } else {
      v = *(u32 *)src;
    }
    *(u32 *)dst = v;
    dst[4] = src[4];
  }
  for (u32 i = 0; i < 3; i++)
    setFloat(ext_5003d0(*(void **)(par + 8), 1 + i), pos[i]);
}
PCREG(5544f0, getMachineGunInfo);
