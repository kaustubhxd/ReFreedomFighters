// batch1219.cpp - fresh slice 12, batch 19. Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

typedef s32(__attribute__((cdecl)) * stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)                     // api-ms-win-crt-string _stricmp (IAT)
extern "C" void THISCALL ext_435a10(u8 *self);                 // base constructor, ret 0
extern "C" void THISCALL ext_4361a0(u8 *self, u32 name);       // ret 4
extern "C" void THISCALL ext_436170(u8 *self, float v);        // ret 4

// 0x4cc400: name order test, fastcall(a, b). Equal ignoring case (_stricmp) -> false. Else compares the first
// min(len a, len b) bytes ASCII-lowercased as signed chars: a's byte greater -> true, smaller -> stop; returns whether
// b ends where the compare stopped.
static bool __attribute__((fastcall)) after4cc400(const char *a, const char *b) {
  if (!imp_stricmp(a, b)) return false;
  s32 la = 0, lb = 0;
  while (a[la]) la++;
  while (b[lb]) lb++;
  s32 n = la > lb ? lb : la;
  s32 i = 0;
  for (; i != n; i++) {
    s8 ca = (s8)a[i], cb = (s8)b[i];
    if ((u8)(ca - 0x41) <= 0x19) ca += 0x20;
    if ((u8)(cb - 0x41) <= 0x19) cb += 0x20;
    if (ca > cb) return true;
    if (ca != cb) break;
  }
  return b[i] == 0;
}
PCREG(4cc400, after4cc400);

// 0x428440: constructor (SEH frame, ESI restored), 16 bytes by value. Base 0x435a10, vtable 0x678df4, 0x4361a0(name
// 0x67936c), +0xa1 = the 16 bytes, +0xd/+0x11/+0x15/+0x19 = 0, +0x1d..+0x5c = 0, 0x436170(0.3f). Returns this. ret 0x10.
static u8 *THISCALL ctor428440(u8 *self, u32 v0, u32 v1, u32 v2, u32 v3) {
  ext_435a10(self);
  *(u32 *)self = 0x678df4;
  ext_4361a0(self, 0x67936c);
  *(u32 *)(self + 0xa1) = v0;
  *(u32 *)(self + 0xa5) = v1;
  *(u32 *)(self + 0xa9) = v2;
  *(u32 *)(self + 0xad) = v3;
  for (u32 o = 0xd; o <= 0x19; o += 4) *(u32 *)(self + o) = 0;
  for (u32 o = 0x1d; o < 0x5d; o += 4) *(u32 *)(self + o) = 0;
  ext_436170(self, 0.3f);
  return self;
}
PCREG(428440, ctor428440);
