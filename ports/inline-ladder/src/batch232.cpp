// batch232.cpp - ZLNKWHANDS::ResetTargets / RemoveTargets (inline-ladder thread, 2026-10-11).
#include "ff.h"

// 0x44a1f0 is a thunk: jmp 0x4690b0, the empty function lifted in batch 222. ZLNKWHANDS::ResetTargets (GC 801888b8)
// and RemoveTargets (GC 801888d8) are both this thunk; the body does nothing.
static void THISCALL noTargets(void *) {}
PCREG(44a1f0, noTargets);
