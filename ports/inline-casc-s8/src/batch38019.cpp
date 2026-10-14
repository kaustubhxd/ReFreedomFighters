// batch38019.cpp - cascade s8 batch 38019: 0x50c030 (validate two named objects of a request and bind them).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);   // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
typedef u32(*log3_t)(void *, u32, u32);
typedef u32(*log4_t)(void *, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))

static void *log_stream(u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  return (void *)SLOT(lg, 0x20, v2_t)(lg, 0x69d420, line);
}

// 0x50c030, stdcall(req) ret 4. Starts by running 0x5003d0 / 0x5002f0 on req[8], then resolves req[4]'s first and second ids through the table's slot 0x58 into two objects, each
// checked with slot 0x1e0 (0x200073 and 0x1007d1); every failure logs an error line (0x358, 0x35f, 0x365, 0x36a) and returns. When the second object's slot 0x2f4 result is neither
// the first object's slot 0x20 result nor the first object itself the mismatch is logged (0x370); otherwise the first object gets slot 0x520(0) and 0x5002f0 runs again on req[8].
static void STDCALL fn50c030(u8 *req) {
  u8 *o = (u8 *)ext_5003d0(*(u8 **)(req + 8), 0);
  ext_5002f0(o, 0);
  u32 *a = ext_5003d0(*(u8 **)(req + 4), 0);
  u8 *t = TABLE;
  u8 *ebx = (u8 *)SLOT(t, 0x58, v1_t)(t, *a);
  if (!ebx) {
    void *st = log_stream(0x358);
    (*(log2_t **)st)[0x2c / 4](st, 0x69d838);
    return;
  }
  if (!(u8)SLOT(ebx, 0x1e0, v1_t)(ebx, 0x200073)) {
    void *st = log_stream(0x35f);
    (*(log3_t **)st)[0x2c / 4](st, 0x69d858, *(u32 *)(ebx + 4));
    return;
  }
  u32 *b = ext_5003d0(*(u8 **)(req + 4), 1);
  t = TABLE;
  u8 *esi = (u8 *)SLOT(t, 0x58, v1_t)(t, *b);
  if (!esi) {
    void *st = log_stream(0x365);
    (*(log2_t **)st)[0x2c / 4](st, 0x69d780);
    return;
  }
  if (!(u8)SLOT(esi, 0x1e0, v1_t)(esi, 0x1007d1)) {
    void *st = log_stream(0x36a);
    (*(log3_t **)st)[0x2c / 4](st, 0x69d5fc, *(u32 *)(esi + 4));
    return;
  }
  u32 c = SLOT(esi, 0x2f4, v0_t)(esi);
  u32 d = SLOT(ebx, 0x20, v0_t)(ebx);
  if (c != d && c != (u32)ebx) {
    void *st = log_stream(0x370);
    u8 *x = (u8 *)SLOT(esi, 0x2e8, v0_t)(esi);
    u32 xs = *(u32 *)(x + 4);
    u8 *d2 = (u8 *)SLOT(ebx, 0x20, v0_t)(ebx);
    (*(log4_t **)st)[0x2c / 4](st, 0x69d880, *(u32 *)(d2 + 4), xs);
    return;
  }
  SLOT(ebx, 0x520, v1_t)(ebx, 0);
  o = (u8 *)ext_5003d0(*(u8 **)(req + 8), 0);
  ext_5002f0(o, 1);
}
PCREG(50c030, fn50c030);
