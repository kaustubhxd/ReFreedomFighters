// batch841.cpp - area 50 (residue-10 list, taken because residue 9 is fully claimed): three small core functions.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_49fa80(void *self, void *arg);      // CActionController::AddEvaluator (not ported here)
extern "C" void THISCALL ext_4a1850(void *self, void *arg);      // CActionController::RemoveEvaluator (not ported here)
extern "C" void THISCALL ext_465a80(void *self, u32 a0, float a1, float a2, u32 a3, u32 a4, float a5, float a6);   // (not ported here)

// ZOnScreenDisplay::MapIconClear() [high]: clears the map-icon flag at +0x69d, then for each of the 24 entries of the
// icon pointer table at +0x4cc: its byte +0x35 is cleared and its vt +8 is called.
static void THISCALL MapIconClear(u8 *self) {
  F32(self, 0x69d) = 0;
  u8 *esi = self + 0x4cc;
  for (u32 i = 0; i != 0x18; i++) {
    void *p = FP(esi, 0);
    F8(p, 0x35) = 0;
    vcall<void>(p, 8);
    esi += 4;
  }
}
PCREG(5aa6e0, MapIconClear);

// CActionController::Command(unsigned short cmd, void* arg) [high, vtable slot 17]: cmd equal to the word at +0x8b0 adds
// the evaluator, equal to the word at +0x8b2 removes it. Returns 0.
static u32 THISCALL ActionControllerCommand(u8 *self, u16 cmd, void *arg) {
  if (cmd == F16(self, 0x8b0)) ext_49fa80(self, arg);
  else if (cmd == F16(self, 0x8b2)) ext_4a1850(self, arg);
  return 0;
}
PCREG(49ff20, ActionControllerCommand);

// FUN_004778e0 (GUESS name: an actor movement entry). Returns (no value) early when the flag at +0x726 is set and the
// state word at +0x64c is 10; else forwards its seven arguments, in the order the exe pushes them, to 0x465a80.
static void THISCALL GUESS_4778e0(u8 *self, u32 a0, float a1, float a2, u32 a3, u32 a4, float a5, float a6) {
  if (F8(self, 0x726) != 0 && F32(self, 0x64c) == 10) return;
  ext_465a80(self, a0, a1, a2, a3, a4, a5, a6);
}
PCREG(4778e0, GUESS_4778e0);
