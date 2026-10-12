#include "ff.h"
// batch7904.cpp - unclaimed-79 batch 4 (docs/20-unclaimed-79.md). Name from the residue list (no GC conflict).

// One registration: slot +0x114 of the object at (system interface +0x9b) with (name, 0, file 0x68fe94, line), four arguments
// (ret 0x10). The returned eax is stored as a word at `dst`.
static void registerZMsg(u32 name, u32 line, u32 dst) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *t = *(u8 **)(sys + 0x9b);
  G(u16, dst) = (u16)vcall<u32, u32, u32, u32, u32>(t, 0x114, name, 0u, 0x68fe94u, line);
}

// 0x4a5c20, ZMatPosAnim::RegisterMessages() (residue list, no GC conflict). Plain ret, no arguments.
static void matPosAnimRegisterMessages(void) {
  registerZMsg(0x688c10u, 0x167u, 0x7002fcu);
  registerZMsg(0x688c1cu, 0x168u, 0x700300u);
  registerZMsg(0x68fee8u, 0x169u, 0x700304u);
  registerZMsg(0x68fef8u, 0x16au, 0x700308u);
  registerZMsg(0x68ff10u, 0x16bu, 0x70030cu);
  registerZMsg(0x68ff1cu, 0x16cu, 0x700310u);
  registerZMsg(0x68ff2cu, 0x16du, 0x700318u);
  registerZMsg(0x68ff3cu, 0x16eu, 0x700314u);
  registerZMsg(0x68ff4cu, 0x16fu, 0x70031cu);
}
PCREG(4a5c20, matPosAnimRegisterMessages);
