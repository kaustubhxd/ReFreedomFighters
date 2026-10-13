// fb0606.cpp - fresh slice 17, batch 6.
#include "ff.h"

extern "C" u32 THISCALL ext_469870(void *self);
extern "C" u32 THISCALL ext_45f960(u8 *self, void *sg);   // ZGEOM::Save(ZSaveGame*)
extern "C" void ext_634273(void *p, u32 size);            // __builtin_delete (sized)
extern "C" void *ext_41e290(u32 size);                    // __builtin_new

// Five object factories with the constructor inlined: engine allocator (engine db +0x9b -> +8, slot +0x44 with the ECX
// argument), base constructor 0x469870, flag 0x20 at +4, +0x44 = 0, then the class vtable. SEH frame not reproduced.
static inline u8 *engineAlloc(u32 x) {
  void *a = *(void **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8);
  return (u8 *)vcall<u32>(a, 0x44, x);
}
static inline u8 *make469870(u32 x, u32 vt) {
  u8 *p = engineAlloc(x);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = vt;
  }
  return p;
}
static u8 *FASTCALL create4a8190(u32 x) { return make469870(x, 0x6901b0); }   // 0x4a8190 (GUESS factory, vtable 0x6901b0)
PCREG(4a8190, create4a8190);
static u8 *FASTCALL create4b2a50(u32 x) { return make469870(x, 0x691050); }   // 0x4b2a50 (GUESS factory, vtable 0x691050)
PCREG(4b2a50, create4b2a50);
static u8 *FASTCALL create4b2cd0(u32 x) { return make469870(x, 0x691844); }   // 0x4b2cd0 (GUESS factory, vtable 0x691844)
PCREG(4b2cd0, create4b2cd0);
static u8 *FASTCALL create4c3490(u32 x) { return make469870(x, 0x693d70); }   // 0x4c3490 (GUESS factory, vtable 0x693d70)
PCREG(4c3490, create4c3490);
static u8 *FASTCALL create4cadd0(u32 x) { return make469870(x, 0x695388); }   // 0x4cadd0 (GUESS factory, vtable 0x695388)
PCREG(4cadd0, create4cadd0);

// 0x456ed0 ZParticleController::Save(ZSaveGame*): ZGEOM part, then the number of leading non-zero entries in the
// 8-byte table at this+0x1d (at most 256) and each entry's first word, all through slot +0x3c. Returns true (AL).
static u32 THISCALL save456ed0(u8 *self, void *sg) {
  ext_45f960(self, sg);
  u32 n = 0;
  while (n < 0x100 && *(u32 *)(self + 0x1d + 8 * n))
    n++;
  u32 r = vcall<u32>(sg, 0x3c, n);
  for (u32 i = 0; i < n; i++)
    r = vcall<u32>(sg, 0x3c, *(u32 *)(self + 0x1d + 8 * i));
  return (r & 0xffffff00u) | 1;
}
PCREG(456ed0, save456ed0);

// 0x54ea90 (GUESS scalar deleting destructor, two COM members): vtable 0x6a4124, Release (COM slot +8) of this+8,
// vtable 0x6a410c, Release of this+4; frees 0xf4 bytes when flag bit 0 is set. Returns this.
typedef u32(STDCALL *com1)(void *);
static u8 *THISCALL sdtor54ea90(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a4124;
  if (void *p = *(void **)(self + 8))
    (*(com1 *)(*(u8 **)p + 8))(p);
  *(u32 *)self = 0x6a410c;
  if (void *p = *(void **)(self + 4))
    (*(com1 *)(*(u8 **)p + 8))(p);
  if (flags & 1)
    ext_634273(self, 0xf4);
  return self;
}
PCREG(54ea90, sdtor54ea90);

// 0x4d4c90 (GUESS named-entry constructor): vtable 0x69666c, +0x11 = id, +0xd = a heap copy of the name.
static u8 *THISCALL ctor4d4c90(u8 *self, u32 id, const char *name) {
  *(u32 *)self = 0x69666c;
  *(u32 *)(self + 0x11) = id;
  u32 len = 0;
  while (name[len])
    len++;
  char *p = (char *)ext_41e290(len + 1);
  *(char **)(self + 0xd) = p;
  for (u32 i = 0;; i++) {
    p[i] = name[i];
    if (!name[i])
      break;
  }
  return self;
}
PCREG(4d4c90, ctor4d4c90);

// 0x424750 ZSysInterfaceGC::UPlotFNxt(const char*, ...) (this on the stack, cdecl): unless the engine float +0x9c7 equals
// the constant at 0x6785d0, formats into a 1 KB stack buffer (log object 0x700390 slot +0x4c, thiscall (buf, fmt, va))
// and hands the text to every listener in the list at this+0x190f (next at +8) through its cdecl slot +0x128(obj, buf).
// The /GS cookie check is not reproduced (it never fails here).
typedef void(THISCALL *vfmt_t)(void *, char *, const char *, void *);
typedef void (*plot_t)(void *, char *);
extern "C" void uPlotFNxt424750(u8 *self, const char *fmt, ...) {
  char buf[0x400];
  __builtin_va_list ap;
  __builtin_va_start(ap, fmt);
  if (!(*(float *)(G(u8 *, 0x70039c) + 0x9c7) == G(float, 0x6785d0))) {
    for (u8 *l = *(u8 **)(self + 0x190f); l; l = *(u8 **)(l + 8)) {
      void *log = G(void *, 0x700390);
      (*(vfmt_t *)(*(u8 **)log + 0x4c))(log, buf, fmt, (void *)ap);
      (*(plot_t *)(*(u8 **)l + 0x128))(l, buf);
    }
  }
  __builtin_va_end(ap);
}
PCREG(424750, uPlotFNxt424750);
