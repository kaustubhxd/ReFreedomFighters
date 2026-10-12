// batch784.cpp - unclaimed-77 claim 14 (docs/20-unclaimed-77.md): ZTreeGroup::CheckDynamicLineColi (low name). Thiscall, six
// arguments, ret 24. The body is a constant false (xor al, al).
#include "ff.h"

// 0x4429c0, ZTreeGroup::CheckDynamicLineColi(eGlobalTreeType, float*, float*, bool, int, int) const (low): returns false.
static u8 THISCALL treeGroupCheckDynamicLineColi(u8 *self, u32 treeType, float *a, float *b, u8 flag, s32 c, s32 d) {
  (void)self; (void)treeType; (void)a; (void)b; (void)flag; (void)c; (void)d;
  return 0;
}
PCREG(4429c0, treeGroupCheckDynamicLineColi);
