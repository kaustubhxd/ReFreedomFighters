// batch1113.cpp - unclaimed-11 batch 14 (slice 10, full list): four leaves. Names are GUESS where the body disagrees.
#include "ff.h"

// 0x429460, GUESS (no GC name): al = (dword at this+4 == arg).
static bool THISCALL guessCompareAt4(u8 *self, u32 a) { return *(u32 *)(self + 4) == a; }
PCREG(429460, guessCompareAt4);

// 0x5ac620, GUESS name CMessageBasics::SetPositionScreenX (doubtful): stores arg1 at this+9 and arg2 at this+0x11.
static void THISCALL messageBasicsSetPosition(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 9) = a1;
  *(u32 *)(self + 0x11) = a2;
}
PCREG(5ac620, messageBasicsSetPosition);

// 0x43d960, GUESS name ZHapticsBase::SetEnabled (sense doubtful): stores (byte arg == 0) at this+0x349.
static void THISCALL hapticsSetEnabled(u8 *self, u8 a) { self[0x349] = (a == 0); }
PCREG(43d960, hapticsSetEnabled);

// 0x48f760, GUESS (no GC name), stdcall: al = (dword at *a1 == dword at *a2).
static bool STDCALL guessEqualDwords(u32 *a1, u32 *a2) { return *a1 == *a2; }
PCREG(48f760, guessEqualDwords);
