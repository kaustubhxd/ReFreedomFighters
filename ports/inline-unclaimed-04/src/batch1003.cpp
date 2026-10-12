// batch1003.cpp - unclaimed-04 batch 3 (docs/20-unclaimed-04.md): ZActor::GetMoveSetId (0x478db0, medium name).
// thiscall, one stack argument (the name), ret 4; this is not read. The CRT calls go through the exe's import slots
// (_stricmp at 0x676414, cdecl; atol at 0x6762e0, cdecl). 0x4cc850 is original code (fastcall: name in ecx, 0x68ac60
// in edx), left as the exe has it.
#include "ff.h"

typedef int(__attribute__((cdecl)) *stricmp_t)(const char *a, const char *b);
typedef long(__attribute__((cdecl)) *atol_t)(const char *s);
#define CRT_STRICMP (*(stricmp_t *)0x676414)
#define CRT_ATOL (*(atol_t *)0x6762e0)

extern "C" u32 FASTCALL ext_4cc850(const char *name, const char *table);  // original code

// 0x478db0: "Walk" (0x68ac54) gives 1, "Run" (0x68ac5c) gives 2; then 0x4cc850(name, 0x68ac60) nonzero gives 0;
// otherwise atol(name + 4) + 3.
static u32 THISCALL actorGetMoveSetId(u8 *self, const char *name) {
  (void)self;
  if (CRT_STRICMP(name, (const char *)0x68ac54) == 0) return 1;
  if (CRT_STRICMP(name, (const char *)0x68ac5c) == 0) return 2;
  if (ext_4cc850(name, (const char *)0x68ac60) != 0) return 0;
  return (u32)CRT_ATOL(name + 4) + 3;
}
PCREG(478db0, actorGetMoveSetId);
