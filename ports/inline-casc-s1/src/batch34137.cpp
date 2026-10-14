// batch34137.cpp - cascade tier E, batch 34137: 0x53b710 (free four buffers), 0x53c210 (find a name in a packed table), 0x54de40 (reset a list).
#include "ff.h"

extern "C" void ext_634273(u32 p, u32 flag);   // cdecl free
typedef int (*stricmp_t)(const char *, const char *);

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x53b710, thiscall plain: frees the unaligned pointer fields +0x11f9 (flag 0xa4), +0x11fd (0xc), +0x1201 (8), +0x1205 (4) and +4 (1) with ext_634273(p, flag) when non-zero (in that order),
// then zeroes +0x11f9, +0x11fd, +0x1201, +0x1205, +0x11e9, +0x11ed, +0x11f1, +0x11f5, +4 and +8 (dwords) and the byte at +0x1209.
static void THISCALL fn53b710(u8 *self) {
  u32 p;
  if ((p = rd32(self + 0x11f9))) ext_634273(p, 0xa4);
  if ((p = rd32(self + 0x11fd))) ext_634273(p, 0xc);
  if ((p = rd32(self + 0x1201))) ext_634273(p, 8);
  if ((p = rd32(self + 0x1205))) ext_634273(p, 4);
  if ((p = rd32(self + 4))) ext_634273(p, 1);
  static const u16 z[] = {0x11f9, 0x11fd, 0x1201, 0x1205, 0x11e9, 0x11ed, 0x11f1, 0x11f5, 4, 8};
  for (int i = 0; i < 10; i++) wr32(self + z[i], 0);
  self[0x1209] = 0;
}
PCREG(53b710, fn53b710);

// 0x53c210, fastcall-like (ecx = name, edx = table, stack n) ret 4: the table is packed entries "string\0" + dword; scans while offset < n (signed): when _stricmp(name, entry) is 0 returns the unaligned dword after
// the string, otherwise skips the string, its terminator and the dword. -1 when nothing matches.
static u32 FASTCALL fn53c210(const char *name, u8 *table, int n) {
  int off = 0;
  while (off < n) {
    const char *s = (const char *)table + off;
    int len = 0;
    while (s[len]) len++;
    if (!G(stricmp_t, 0x676414)(name, s)) return rd32(table + off + len + 1);
    off += 4 + len + 1;
  }
  return 0xffffffff;
}
PCREG(53c210, fn53c210);

// 0x54de40, thiscall plain: clears the dwords +0x8059, +0x804d, +0x8065, +0x8051; frees [+0x8031] then [+0x802d] (flag 1 each, when non-zero; both fields zeroed); for i < signed [+0x805d]: o = [[+0x803d]+4i]; o->slot0x24(); o->slot0x40();
// [o+0x18] = 7; then [+0x8061]->slot0x14() when set; clears +0x8018 and +0x8014. All unaligned.
static void THISCALL fn54de40(u8 *self) {
  u32 a = rd32(self + 0x8031);
  wr32(self + 0x8059, 0);
  wr32(self + 0x804d, 0);
  wr32(self + 0x8065, 0);
  wr32(self + 0x8051, 0);
  if (a) ext_634273(a, 1);
  u32 b = rd32(self + 0x802d);
  wr32(self + 0x8031, 0);
  if (b) ext_634273(b, 1);
  wr32(self + 0x802d, 0);
  for (int i = 0; i < (int)rd32(self + 0x805d); i++) {
    u8 **arr = (u8 **)rd32(self + 0x803d);
    vcall<void>(arr[i], 0x24);
    arr = (u8 **)rd32(self + 0x803d);
    vcall<void>(arr[i], 0x40);
    arr = (u8 **)rd32(self + 0x803d);
    *(u32 *)(arr[i] + 0x18) = 7;
  }
  u32 p = rd32(self + 0x8061);
  if (p) vcall<void>((void *)p, 0x14);
  wr32(self + 0x8018, 0);
  wr32(self + 0x8014, 0);
}
PCREG(54de40, fn54de40);
