// batch701.cpp - soldier AI, batch 701 (2026-10-11): CCheckVisible seer/object registration.
// Seer record (0x1b8 bytes at +0x694 + i*0x1b8): +0 geom ref, +4 view range (3000 at add), +8 cos(half fov)
// (cos(1.0472) = 0.5 at add, so 60 degrees each side), +0xc 1.0 (light multiplier, inferred from OnSetVisLightMultiplier),
// +0x10..+0x18 zero, +0x1c kind flags (1 = ZCTRLIKLNKOBJ, 2 = ZActor), +0x20 time of add (engine tick),
// +0x24 zero, +0x28 u16 state per object: bit 15 "valid/pending", bit 14 "currently visible", low 14 bits timer.
// Object record (8 bytes at +0x54 + i*8): +0 geom ref, +4 kind flags (same bits).
#include "ff.h"

#define CV_ASSERT() do { void (*h)() = *(void (**)())0x7003b0; if (h) { h(); return 0; } __builtin_debugtrap(); } while (0)

// The engine's geom database (engine +0x9b, unaligned): slot 0x58 = ref -> ZGEOM*. ZGEOM slot 0x1e0 = IsKindOf(class id).
static inline void *geom_of(u32 ref) {
  void *db = *(void **)(*(u8 **)0x70039c + 0x9b);
  return vcall<void *>(db, 0x58, ref);
}
static inline bool is_kind(void *g, u32 cls) { return vcall<bool>(g, 0x1e0, cls); }

// 0x4a9a10 CCheckVisible::AddObject(unsigned int) [medium]: returns the existing slot of ref, or takes the first free
// slot (ref 0) and records the kind flags. No free slot: assert (0x7003b0 hook, returns 0; int3 when no hook).
static u32 THISCALL cv_AddObject(u8 *self, u32 ref) {
  for (u32 i = 0; i < 200; i++)
    if (*(u32 *)(self + 0x54 + i * 8) == ref)
      return i;
  u32 i = 0;
  for (; i < 200; i++)
    if (*(u32 *)(self + 0x54 + i * 8) == 0)
      break;
  if (i == 200)
    CV_ASSERT();
  *(u32 *)(self + 0x54 + i * 8) = ref;
  *(u32 *)(self + 0x58 + i * 8) = 0;
  void *g = geom_of(ref);
  if (is_kind(g, 0x200074))
    *(u32 *)(self + 0x58 + i * 8) |= 1;
  if (is_kind(g, 0x2007d0))
    *(u32 *)(self + 0x58 + i * 8) |= 2;
  return i;
}
PCREG(4a9a10, cv_AddObject);

// 0x4a9ad0 CCheckVisible::AddSeer(unsigned int) [medium]: same search/assert pattern over the seer table, then fills
// the defaults listed at the top. cos() is the CRT routine at 0x634d70 (called directly, argument/result in XMM0).
extern "C" double VECTORCALL ext_634d70(double);
static u32 THISCALL cv_AddSeer(u8 *self, u32 ref) {
  for (u32 i = 0; i < 200; i++)
    if (*(u32 *)(self + 0x694 + i * 0x1b8) == ref)
      return i;
  u32 i = 0;
  for (; i < 200; i++)
    if (*(u32 *)(self + 0x694 + i * 0x1b8) == 0)
      break;
  if (i == 200)
    CV_ASSERT();
  u8 *s = self + 0x694 + i * 0x1b8;
  *(u32 *)s = ref;
  float c = (float)ext_634d70(G(double, 0x690988));   // 1.0472 (pi/3)
  *(u32 *)(s + 4) = 0x453b8000;                       // 3000.0f
  *(u32 *)(s + 0xc) = 0x3f800000;                     // 1.0f
  *(u32 *)(s + 0x1c) = 0;
  *(float *)(s + 8) = c;
  u32 *now = (u32 *)(*(u8 **)0x70039c + 0x40);
  if ((u32 *)(s + 0x20) != now)
    *(u32 *)(s + 0x20) = *now;
  *(u32 *)(s + 0x24) = 0;
  *(u32 *)(s + 0x18) = 0;
  *(u32 *)(s + 0x14) = 0;
  *(u32 *)(s + 0x10) = 0;
  u16 *st = (u16 *)(s + 0x28);
  for (int j = 0; j < 200; j++)
    st[j] &= 0x7fff;
  void *g = geom_of(ref);
  if (is_kind(g, 0x200074))
    *(u32 *)(s + 0x1c) |= 1;
  if (is_kind(g, 0x2007d0))
    *(u32 *)(s + 0x1c) |= 2;
  return i;
}
PCREG(4a9ad0, cv_AddSeer);

// 0x4ab100 CCheckVisible::OnObjectAdd(void*) [high]: event handler (the event argument is the ref itself). Adds the
// object, then marks its state word "pending" (0x8000, timer 0) in every used seer slot that does not already have it.
extern "C" u32 THISCALL ext_4a9a10(void *, u32);
static u32 THISCALL cv_OnObjectAdd(u8 *self, u32 ref) {
  u32 idx = ext_4a9a10(self, ref);
  u8 *seer = self + 0x694;
  u16 *st = (u16 *)(self + 0x6bc) + idx;
  for (int i = 0; i < 200; i++) {
    if (*(u32 *)seer != 0 && !(*st >> 15 & 1))
      *st = 0x8000;
    seer += 0x1b8;
    st = (u16 *)((u8 *)st + 0x1b8);
  }
  return 0;
}
PCREG(4ab100, cv_OnObjectAdd);

// 0x4ab2d0 CCheckVisible::OnSeerObjectAdd(void*) [high]: event = {seer ref, object ref}. Adds both and marks that one
// pair pending (0x8000) unless it already is.
extern "C" u32 THISCALL ext_4a9ad0(void *, u32);
static u32 THISCALL cv_OnSeerObjectAdd(u8 *self, u32 *ev) {
  u32 obj = ev[1];
  u32 s = ext_4a9ad0(self, ev[0]);
  u32 o = ext_4a9a10(self, obj);
  u16 *st = (u16 *)(self + 0x6bc) + (o + s * 0xdc);
  if (!(*st >> 15 & 1))
    *st = 0x8000;
  return 0;
}
PCREG(4ab2d0, cv_OnSeerObjectAdd);

// 0x4ab160 CCheckVisible::OnObjectDel(void*) [high]: DelObject(ref), returns 0.
extern "C" void THISCALL ext_4a9e70(void *, u32);
static u32 THISCALL cv_OnObjectDel(u8 *self, u32 ref) {
  ext_4a9e70(self, ref);
  return 0;
}
PCREG(4ab160, cv_OnObjectDel);

// 0x4a9e70 CCheckVisible::DelObject(unsigned int) [high]. Unknown ref: logs
// "Warning: CCheckVisible::DelObject() %s is not a registered object" with the geom's name (slot 0x1d8 fills a MYSTR,
// 0x4cc1d0 = its c_str, 0x4cbec0 = MYSTR::~MYSTR). Known ref: in every seer, a pair that is pending and visible loses
// its visible bit and the seer gets a "lost sight" event: this+0x44 dispatcher slot 0x12c(seer ref, event id u16 at
// +0x52, object ref); then every seer's pending bit for the object is cleared and the slot is freed.
// (The PC code also sets up an SEH frame and stack cookie for the MYSTR temporary; not observable, not reproduced.)
struct MYSTR_buf { u8 b[0x80]; };
extern "C" const char *THISCALL ext_4cc1d0(void *);
extern "C" void THISCALL ext_4cbec0(void *);
static void THISCALL cv_DelObject(u8 *self, u32 ref) {
  u32 i = 0;
  for (; i < 200; i++)
    if (*(u32 *)(self + 0x54 + i * 8) == ref)
      break;
  if (i == 200) {
    void *g = geom_of(ref);
    void *logger = *(void **)0x700390;
    void *log = vcall<void *>(logger, 0x20, (const char *)0x690610, 0x219);
    MYSTR_buf name;
    void *ms = vcall<void *>(g, 0x1d8, &name, 1);
    const char *s = ext_4cc1d0(ms);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6908f0, s);
    ext_4cbec0(&name);
    return;
  }
  u8 *seer = self + 0x694;
  for (int k = 0; k < 200; k++, seer += 0x1b8) {
    u16 *st = (u16 *)(seer + 0x28) + i;
    if ((*st & 0xc000) == 0xc000) {
      u16 v = *st;
      if (v >> 14 & 1) {
        *st = v & 0xbfff;
        void *disp = *(void **)(self + 0x44);
        vcall<void>(disp, 0x12c, *(u32 *)seer, (u32) * (u16 *)(self + 0x52), *(u32 *)(self + 0x54 + i * 8));
      }
    }
    *st &= 0x7fff;
  }
  *(u32 *)(self + 0x54 + i * 8) = 0;
}
PCREG(4a9e70, cv_DelObject);
