// batch308.cpp - mounted gun tree, batch 308: CFFTools_if::GetMachineGun, the script native an AI soldier uses to pick a
// machine gun nest near it. Helpers as batch 307 (parameter blocks, nest Command slot 0x128, message ids).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u32(THISCALL *vcallUP)(void *self, void *a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVUUU)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *regMsg)(void *self, const char *name, u32 z, const char *file, u32 line);
typedef void *(THISCALL *logOpen)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *pr, const char *fmt, ...);
typedef void (*assertHook)();

extern "C" u8 *THISCALL ext_5003d0(void *block, u32 i);    // parameter accessor (batch 1503)
extern "C" void *THISCALL ext_5002f0(void *p, u32 v);      // set int parameter (batch 1503)
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);                // vdist2 (ST0)
extern "C" void THISCALL ext_5520c0(void *self, u32 nest, u32 unused, float *out);   // CalcMachineGunStandPosition (batch 307)

static inline u8 *db() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *byRef(u32 ref) { return ((vcallPU)VT(db(), 0x58))(db(), ref); }
static inline u16 msgId(u32 name, u32 line) {
  return (u16)((regMsg)VT(db(), 0x114))(db(), (const char *)name, 0, (const char *)0x6a57fc, line);   // fftools_if.cpp
}
static inline void send(u8 *o, u32 name, u32 line, u32 data) {
  void **vt = *(void ***)o;
  u16 id = msgId(name, line);
  ((vcallVUUU)vt[0x128 / 4])(o, id, data, 0);
}
static void wrongType() {
  void *lg = G(void *, 0x700390);
  void *pr = ((logOpen)VT(lg, 0x20))(lg, (const char *)0x69c8e0, 0x104);
  ((logPrintf)VT(pr, 0x2c))(pr, (const char *)0x69c6b0, (const char *)0x69c938);
  assertHook h = G(assertHook, 0x7003b0);
  if (!h)
    asm volatile("int3");
  h();
}
static inline void setFloat(u8 *p, float f) {
  if (p[4] != 0 && p[4] != 2)
    wrongType();
  p[4] = 2;
  *(float *)p = f;
}

// 0x554020 CFFTools_if::GetMachineGun(OpaqueCallParameters_t&), GC map [medium]; thiscall, ret 4.
// In: me (ref), target (ref or 0), radius (float). Out: 0 = nest geom ref (0 if none), 1..3 = stand position (cleared
// to 0 first). Walks g_pGameData+0x2c29 (the MachinegunList, batch 305) with its iterator at +0x18 (slot 0x4c begin,
// slot 0x5c returns the current element's ref and advances; the element field +0 of the iterator state is 0 at the
// end). Picks the closest nest within radius (squared distance from my slot-0x84 point to the nest's) that is not
// taken (GetTaken, line 0x154) and, with a target, can aim at it (CanAimWeaponRef, line 0x15e). The winner is reserved
// for me (MakeReservation, line 0x17b) and its stand position returned. A GetCenter id is registered (line 0x12f) but
// not used.
static void THISCALL getMachineGun(void *self, u8 *par) {
  u32 me = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u32 target = *(u32 *)ext_5003d0(*(void **)(par + 4), 1);
  float radius = *(float *)ext_5003d0(*(void **)(par + 4), 2);
  ext_5002f0(ext_5003d0(*(void **)(par + 8), 0), 0);
  for (u32 i = 1; i <= 3; i++)
    setFloat(ext_5003d0(*(void **)(par + 8), i), 0.0f);
  u8 *list = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c29);
  if (!list)
    return;
  float my[3] = {0.0f, 0.0f, 0.0f};
  u8 *meo = byRef(me);
  ((vcallVP)VT(meo, 0x84))(meo, my);
  float best = 9.999999680285692e+37f;   // 0x67cd44
  float r2 = radius * radius;
  msgId(0x6a585c, 0x12f);   // "GetCenter", unused
  u8 *it = *(u8 **)(list + 0x18);
  u8 *bestg = nullptr;
  if (!it)
    return;
  u32 st[4];
  ((vcallVP)VT(it, 0x4c))(it, st);
  u32 cur = ((vcallUP)VT(*(u8 **)(list + 0x18), 0x5c))(*(u8 **)(list + 0x18), st);
  while (st[0] != 0) {
    u8 *g = byRef(cur);
    if (g) {
      float p[3] = {0.0f, 0.0f, 0.0f};
      ((vcallVP)VT(g, 0x84))(g, p);
      float d = ext_4e0830(my, p);
      if (!(d > r2)) {
        u32 taken;
        send(g, 0x6a5868, 0x154, (u32)&taken);   // "GetTaken"
        if (taken == 0) {
          u32 cw = target;
          bool ok = true;
          if (target) {
            send(g, 0x6a5874, 0x15e, (u32)&cw);   // "CanAimWeaponRef"
            ok = cw != 0;
          }
          if (ok && best > d) {
            best = d;
            bestg = g;
          }
        }
      }
    }
    u8 *it2 = *(u8 **)(list + 0x18);
    cur = ((vcallUP)VT(it2, 0x5c))(it2, st);
  }
  if (!bestg)
    return;
  u32 ref = ((vcallUU)VT(db(), 0x4c))(db(), (u32)bestg);
  float sp[3];
  ext_5520c0(self, ref, target, sp);
  send(bestg, 0x6a5884, 0x17b, me);   // "MakeReservation"
  ext_5002f0(ext_5003d0(*(void **)(par + 8), 0), ref);
  for (u32 i = 0; i < 3; i++)
    setFloat(ext_5003d0(*(void **)(par + 8), 1 + i), sp[i]);
}
PCREG(554020, getMachineGun);
