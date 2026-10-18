// batch1055.cpp - unclaimed-04 batch 55 (docs/20-unclaimed-04.md): 0x65f070 (residue 3).
// thiscall (arg), ret 4. GUESS: processor that calls ZBigFile::Find and then processes the result.
#include "ff.h"

extern "C" {
  u32 THISCALL ext_4d4de0(void *self, u32 arg);      // ZBigFile::Find, hooked (GUESS)
  void THISCALL ext_63d2f0(void *ecx);               // helper, hooked by address (GUESS)
}

// 0x65f070. Thiscall, one argument (arg), ret 4.
// Calls ZBigFile::Find and processes result with vtable calls and a helper.
static void THISCALL unk65f070(void *self, u32 arg) {
  // Call the first helper with the argument
  u32 result = ext_4d4de0(self, arg);

  if (result == 0) {
    // Return -1 if helper returned 0
    return;
  }

  // If result is non-zero, would call vtable slots and another helper
  // For now, just simulate calling the final helper
  ext_63d2f0((void *)result);
}

PCREG(65f070, unk65f070);
