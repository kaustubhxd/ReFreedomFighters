// batch603.cpp - area 49, batch 603: ZInputAction::AddNode(char *name, bool flag) (0x437900, 85 insns, thiscall, ret 8).
// Finds the owner object from this+0xc: a node whose first dword is 3 gives (node - 4); a node whose first dword is 1
// gives ((node+8) - 4) when that is non-null; otherwise 0. The object at +0x11 of that address has a virtual lookup
// (slot 0x64, one argument: the name) that returns an index or -1. An index calls this's slot 4 with (index, flag).
// -1 logs four messages (lines 0xfb4..0xfb7, file 0x67a850) through the debug logger.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
typedef u32(THISCALL *vTwo)(void *self, u32 a, u32 b);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);

static const char *const kFile = (const char *)0x67a850;

// 0x437900 AddNode(name, flag): thiscall, ret 8
static void THISCALL addNode(u8 *self, const char *name, u32 flag) {
  u32 node = *(u32 *)(self + 0xc);
  u32 ecx = 0;
  if (node) {
    if (*(u32 *)node == 3) {
      ecx = node - 4;
    } else if (*(u32 *)node == 1) {
      u32 y = *(u32 *)(node + 8);
      ecx = y ? y - 4 : 0;
    }
  }
  u8 *obj = *(u8 **)(ecx + 0x11);   // exe: mov ecx,[ecx+0x11] (ecx 0 reads address 0x11: not used by the specs)
  u32 idx = ((vOne)VT(obj, 0x64))(obj, (u32)name);
  if (idx != 0xffffffffu) {
    ((vTwo)VT(self, 4))(self, idx, flag);
    return;
  }
  u8 *lg = G(u8 *, 0x700390);
  void *st = ((vLogLine)VT(lg, 0x20))(lg, kFile, 0xfb4);
  ((logPrintf)VT(st, 0x2c))(st, (const char *)0x67ad6c, name, *(u32 *)(*(u8 **)(self + 0xc) + 4));
  st = ((vLogLine)VT(lg, 0x20))(lg, kFile, 0xfb5);
  ((logPrintf)VT(st, 0x2c))(st, (const char *)0x67ada8);
  st = ((vLogLine)VT(lg, 0x20))(lg, kFile, 0xfb6);
  ((logPrintf)VT(st, 0x2c))(st, (const char *)0x67adc8);
  st = ((vLogLine)VT(lg, 0x20))(lg, kFile, 0xfb7);
  ((logPrintf)VT(st, 0x2c))(st, (const char *)0x67ae30);
}
PCREG(437900, addNode);
