// batch37046.cpp - cascade s6 batch 37046: 0x43b820.
#include "ff.h"

typedef int(*stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define D32(o) (*(u32 *)(self + (o)))

// 0x43b820, thiscall(name) ret 4: parses a name into this+0xb1 (kind 1..8 for eight keywords tested in order with _stricmp; none: 0) or sets the flag byte this+0xb0 for the ninth
// keyword; an unknown name logs error 0x279. The fields +0xb0 (byte), +0xb1 (dword) and +0xb5 (word) are cleared first.
static void THISCALL fn43b820(u8 *self, const char *name) {
  *(u8 *)(self + 0xb0) = 0;
  D32(0xb1) = 0;
  *(u16 *)(self + 0xb5) = 0;
  if (!imp_stricmp(name, (const char *)0x67a0a8)) { D32(0xb1) = 2; return; }
  if (!imp_stricmp(name, (const char *)0x67a0e0)) { D32(0xb1) = 8; return; }
  if (!imp_stricmp(name, (const char *)0x67a0ac)) { D32(0xb1) = 3; return; }
  if (!imp_stricmp(name, (const char *)0x67c0e4)) { D32(0xb1) = 5; return; }
  if (!imp_stricmp(name, (const char *)0x67a0a0)) { D32(0xb1) = 1; return; }
  if (!imp_stricmp(name, (const char *)0x67a0c8)) { D32(0xb1) = 6; return; }
  if (!imp_stricmp(name, (const char *)0x67a0d4)) { D32(0xb1) = 7; return; }
  if (!imp_stricmp(name, (const char *)0x67a0b4)) { D32(0xb1) = 4; return; }
  if (!imp_stricmp(name, (const char *)0x677b5c)) { *(u8 *)(self + 0xb0) = 1; return; }
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x67bd78, 0x279);
  (*(cdl_t **)L)[0x2c / 4](L, 0x67c0f0, (u32)name);
}
PCREG(43b820, fn43b820);
