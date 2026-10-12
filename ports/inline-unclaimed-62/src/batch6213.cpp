// batch6213.cpp - unclaimed-62 claim 6 (slice 1): DBLK::Get(short *out, int count) [map 0x4e1110; thiscall, ret 8]. For count items, starting
// at the block's current pointer (this+8): an item whose tag is not 0xff and has type (tag & 0x3f) 3, 8, 10 or 11 is accepted, otherwise the
// assert hook is called (a trap when none) and the message 0x6970f8 goes to g_pDebug's slot 0x24. Then the item must be type 10 and not 0xff:
// its word at +1 is written to out; otherwise the same hook and message. The current pointer advances by the item skip 0x4e1590 (exe, returns
// its size) plus one, and out advances by one short.
#include "ff.h"

extern "C" u32 THISCALL ext_4e1590(u8 *self);   // exe: skip the current item, returns its size (ret 0)

typedef void (*dbgFn)(void *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void dblkError() {
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h();
  else __builtin_debugtrap();
  void *g = G(void *, 0x700390);
  dbgFn f = *(dbgFn *)(*(u8 **)g + 0x24);
  f(g, (const char *)0x6970f8);
}

static void THISCALL dblkGet(u8 *self, u8 *out, u32 count) {
  u16 *o = (u16 *)out;
  u32 remaining = count;
  for (;;) {
    u8 *p = rdp(self + 8);
    u8 t = p[0];
    bool typeOk = (t != 0xff) && ((t & 0x3f) == 3 || (t & 0x3f) == 0xa || (t & 0x3f) == 0xb || (t & 0x3f) == 8);
    if (!typeOk) dblkError();
    if ((t != 0xff) && (t & 0x3f) == 0xa) {
      *o = *(const u16 *)(p + 1);
    } else {
      dblkError();
    }
    u32 sz = ext_4e1590(self);
    wr32u(self + 8, rd32u(self + 8) + sz + 1);
    if (remaining == 1) break;
    remaining--;
    o++;
  }
}
PCREG(4e1110, dblkGet);
