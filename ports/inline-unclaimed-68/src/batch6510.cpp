// batch6510.cpp - unclaimed-68 batch 51 (claim 51, gap band). Name is a GUESS carried from the working notes (not verified against the name map).
#include "ff.h"

typedef u32(THISCALL *VNoArg)(u8 *self);
typedef u32(THISCALL *VOutRet)(u8 *self, u32 *out);
typedef u32(THISCALL *VMgrSlot58)(u8 *mgr, u32 v);

static u8 *soundMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x4a3d60, ZSoundAmbient::CanPlayInRoom(int room) (GUESS name): thiscall, one stack argument (ret 4), bool result in AL.
//   mgr = engine->+0x9b. If room == mgr->+0xadc, return false.
//   List A at this+0x5c: if A.slot14() != 0, walk it: A.slot4c(&l), v = A.slot5c(&l); while l != 0: if mgr.slot58(v) == room return true;
//   v = A.slot5c(&l). Return false when the walk ends.
//   Otherwise list B at this+0x108: if B.slot14() == 0 return true; A-style start with B.slot4c / B.slot5c; if the first element is absent
//   return true; while l != 0: if mgr.slot58(v) == room return false; v = B.slot5c(&l). Return true when the walk ends.
static u8 THISCALL soundAmbientCanPlayInRoom(u8 *self, u32 room) {
  u8 *mgr = soundMgr();
  if (room == *(u32 *)(mgr + 0xadc)) return 0;
  u8 *A = self + 0x5c;
  if (((VNoArg)*(u32 *)(*(u8 **)A + 0x14))(A) != 0) {
    u32 l = 0;
    ((VOutRet)*(u32 *)(*(u8 **)A + 0x4c))(A, &l);
    u32 v = ((VOutRet)*(u32 *)(*(u8 **)A + 0x5c))(A, &l);
    while (l != 0) {
      mgr = soundMgr();
      if (((VMgrSlot58)*(u32 *)(*(u8 **)mgr + 0x58))(mgr, v) == room) return 1;
      v = ((VOutRet)*(u32 *)(*(u8 **)A + 0x5c))(A, &l);
    }
    return 0;
  }
  u8 *B = self + 0x108;
  if (((VNoArg)*(u32 *)(*(u8 **)B + 0x14))(B) == 0) return 1;
  u32 l = 0;
  ((VOutRet)*(u32 *)(*(u8 **)B + 0x4c))(B, &l);
  u32 v = ((VOutRet)*(u32 *)(*(u8 **)B + 0x5c))(B, &l);
  if (l == 0) return 1;
  do {
    mgr = soundMgr();
    if (((VMgrSlot58)*(u32 *)(*(u8 **)mgr + 0x58))(mgr, v) == room) return 0;
    v = ((VOutRet)*(u32 *)(*(u8 **)B + 0x5c))(B, &l);
  } while (l != 0);
  return 1;
}
PCREG(4a3d60, soundAmbientCanPlayInRoom);
