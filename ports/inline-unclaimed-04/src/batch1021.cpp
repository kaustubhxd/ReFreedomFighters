// batch1021.cpp - unclaimed-04 batch 22 (docs/20-unclaimed-04.md): three slice-3 functions (GUESS labels).
#include "ff.h"

typedef u32(__attribute__((stdcall)) *event_t)(u32 handle);
#define CRT_RESET_EVENT (*(event_t *)0x676140)
#define CRT_SET_EVENT (*(event_t *)0x67613c)

extern "C" void THISCALL ext_54cd00(void *self);  // original code: stores vtable 0x6a3e14 and returns

// 0x533bb0: return ResetEvent(*0x701b6c) (eax as the call leaves it).
static u32 __attribute__((cdecl)) unk533bb0ResetGlobal(void) {
  return CRT_RESET_EVENT(*(u32 *)0x701b6c);
}
PCREG(533bb0, unk533bb0ResetGlobal);

// 0x54ab30: return SetEvent(*0x701b6c) (eax as the call leaves it).
static u32 __attribute__((cdecl)) unk54ab30SetGlobal(void) {
  return CRT_SET_EVENT(*(u32 *)0x701b6c);
}
PCREG(54ab30, unk54ab30SetGlobal);

// 0x549370: store vtable 0x6a3338, then tail-jump to 0x54cd00 (which stores 0x6a3e14).
static void THISCALL unk549370TailSetVtable(u8 *self) {
  *(u32 *)self = 0x6a3338;
  ext_54cd00(self);
}
PCREG(549370, unk549370TailSetVtable);
