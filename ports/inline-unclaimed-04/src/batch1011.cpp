// batch1011.cpp - unclaimed-04 batch 11 (docs/20-unclaimed-04.md): CImpactResponse::Init(ZSTDOBJ*, DBREAD&) (0x5dc3f0).
// thiscall, two stack arguments (ret 8). The first argument is not read. The DBREAD reference goes to two DBREAD helpers
// (0x4e6330 with this+0x48 as a stack argument, 0x4e5ea0 returning a string); the string is copied with _strdup, which
// is an import at IAT 0x676404 (cdecl). The copy goes to this+0x4c. The helpers are original code here (the spec stubs them).
#include "ff.h"

typedef char *(__attribute__((cdecl)) *strdup_t)(const char *s);
#define CRT_STRDUP (*(strdup_t *)0x676404)

extern "C" void THISCALL ext_4e6330(void *b, u32 arg);  // DBREAD helper, original code (ret 4)
extern "C" u32 THISCALL ext_4e5ea0(void *b);            // DBREAD helper, original code (returns a string pointer)

// 0x5dc3f0.
static void THISCALL impactResponseInit(u8 *self, u32 unusedA, u8 *b) {
  (void)unusedA;
  ext_4e6330(b, *(u32 *)(self + 0x48));
  const char *s = (const char *)ext_4e5ea0(b);
  *(u32 *)(self + 0x4c) = (u32)CRT_STRDUP(s);
}
PCREG(5dc3f0, impactResponseInit);
