// batch1025.cpp - unclaimed-04 batch 26 (docs/20-unclaimed-04.md): 0x41dd70, no arguments, plain ret (cdecl).
#include "ff.h"

typedef u32(__attribute__((stdcall)) *getproc_t)(void);
#define CRT_GET_CURRENT_PROCESS (*(getproc_t *)0x6760ac)

// the call site pushes the handle and has no `add esp`, so the target pops its own argument (stdcall)
typedef void(__attribute__((stdcall)) *handle_fn_t)(u32 handle);
#define GLOBAL_HANDLE_FN (*(handle_fn_t *)0x6fcd54)

// 0x41dd70
static void __attribute__((cdecl)) unk41dd70CounterGated(void) {
  s32 *count = (s32 *)0x6fcd7c;
  *count -= 1;
  if (*count != 0) return;
  u32 h = CRT_GET_CURRENT_PROCESS();
  GLOBAL_HANDLE_FN(h);
}
PCREG(41dd70, unk41dd70CounterGated);
