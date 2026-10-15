#include "ff.h"
extern "C" void THISCALL ext_54e3f0(u8 *self);
typedef u32 (STDCALL *CreateEventFn)(u32, u32, u32, u32);
typedef u32 (STDCALL *CreateThreadFn)(u32, u32, u32, u32, u32, u32);
typedef u32 (STDCALL *WaitFn)(u32, u32);
static void THISCALL fn54e770(u8 *self) {
  u32 event_a = (*(CreateEventFn *)0x676148)(0, 1, 0, 0);
  *(u32 *)(self + 0x2d6) = 0;
  u32 event_b = (*(CreateEventFn *)0x676148)(0, 0, 0, 0);
  *(u32 *)(self + 0x2ce) = event_a;
  *(u32 *)(self + 0x2d2) = event_b;
  u32 tid = 0;
  u32 thread = (*(CreateThreadFn *)0x67614c)(0, 0, 0x54e7e0, (u32)self, 0, (u32)&tid);
  *(u32 *)(self + 0x2ca) = thread;
  (*(WaitFn *)0x676150)(thread, 2);
  ext_54e3f0(self);
}
PCREG(54e770, fn54e770);
