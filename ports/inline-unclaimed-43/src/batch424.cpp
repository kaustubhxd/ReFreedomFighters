// batch424.cpp - residue 2 row 0x54e720 (thiscall, four stack arguments a1..a4, ret 0x10; returns a3 in eax).
// [this+0x2da] = dword [a1+0x43]; [this+0x2e2] = a2; [this+0x2e6] = a3; [this+0x2ea] = a4;
// [this+0x2de] = dword [a1+0x4f] + a2; then SetEvent(dword [this+0x2ce]) through IAT slot 0x67613c (KERNEL32, stdcall one argument).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

typedef u32(STDCALL *SetEventFn)(u32 handle);

static u32 THISCALL storeAndSignal(u8 *self, u8 *a1, u32 a2, u32 a3, u32 a4) {
  u32 handle = U32(self, 0x2ce);
  U32(self, 0x2da) = U32(a1, 0x43);
  U32(self, 0x2e2) = a2;
  U32(self, 0x2e6) = a3;
  U32(self, 0x2ea) = a4;
  U32(self, 0x2de) = U32(a1, 0x4f) + a2;
  SetEventFn fn = (SetEventFn)(unsigned long)(*(u32 *)0x67613cu);
  fn(handle);
  return a3;
}
PCREG(54e720, storeAndSignal);
