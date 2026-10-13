// batch1204.cpp - unclaimed-12: batch 4 (docs/20-unclaimed-12.md, claim 4). Thiscall; the callee pops the stack args.
// ext_<hex> is the original code at that address (build.sh binds it); 0x4ba310 and 0x44c840 are ported elsewhere (batch 24, 35).
#include "ff.h"

// 0x4ba310, initScales (plain thiscall, no arguments; original code here).
extern "C" void THISCALL ext_4ba310(u8 *self);

// 0x44c840, vnorm: normalises the vector at ecx in place and returns its length in st0 (original code here; the caller discards it).
extern "C" float THISCALL ext_44c840(u8 *vec);

// 0x4b9530, ZProjectile::CopyData(ZEventBase*) (high): copies dword +0x4c, +0x48, byte +0x50, dword +0x91 and +0x89 from the
// source, then calls initScales (ext_4ba310) on this. The source is still on the stack, so the caller's ret 4 pops it.
static void THISCALL projectileCopyData(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x4c) = *(const u32 *)(src + 0x4c);
  *(u32 *)(self + 0x48) = *(const u32 *)(src + 0x48);
  self[0x50] = src[0x50];
  *(u32 *)(self + 0x91) = *(const u32 *)(src + 0x91);
  *(u32 *)(self + 0x89) = *(const u32 *)(src + 0x89);
  ext_4ba310(self);
}
PCREG(4b9530, projectileCopyData);

// the vtable slot +0x12c of the object at this+0x44 takes (dword +0x4c, word +0x4a zero-extended, arg2) in that stack order
typedef u32(THISCALL *ObjectCommandFn)(u8 *self, u32 a, u32 b, void *c);

// 0x4b85c0, ZRelayMessage::Command(unsigned short, void*) (high): when the word argument equals the word at +0x48, calls
// virtual slot +0x12c of the object at +0x44. Always returns 0.
static u32 THISCALL relayMessageCommand(u8 *self, u32 cmd, void *arg) {
  if ((u16)cmd == *(const u16 *)(self + 0x48)) {
    u8 *target = *(u8 **)(self + 0x44);
    const u32 vtbl = *(const u32 *)target;
    ObjectCommandFn fn = (ObjectCommandFn)(*(const u32 *)(vtbl + 0x12c));
    fn(target, *(const u32 *)(self + 0x4c), *(const u16 *)(self + 0x4a), arg);
  }
  return 0;
}
PCREG(4b85c0, relayMessageCommand);

// 0x47bd90, ZActor::SetEndDir(const float*) (high): a null argument clears the flag byte +0x699. Otherwise the three dwords of
// the argument go to +0x69a, +0x69e and +0x6a2, the dword at +0x69e is then zeroed (so the vector is (x, 0, z)), the vector
// is normalised in place by vnorm, and the flag byte +0x699 becomes 1. vnorm's float result is discarded.
static void THISCALL actorSetEndDir(u8 *self, const u32 *dir) {
  if (!dir) {
    self[0x699] = 0;
    return;
  }
  u8 *vec = self + 0x69a;
  *(u32 *)vec = dir[0];
  *(u32 *)(vec + 4) = dir[1];
  *(u32 *)(vec + 8) = dir[2];
  *(u32 *)(self + 0x69e) = 0;
  ext_44c840(vec);
  self[0x699] = 1;
}
PCREG(47bd90, actorSetEndDir);
