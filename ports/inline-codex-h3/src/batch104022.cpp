#include "ff.h"
typedef u32 (STDCALL *qpc_fn)(u64*);
typedef u32 (*clock_fn)();
static void THISCALL stamp_event_time(u8* self) {
  u64 qpc=0;
  (*(qpc_fn*)0x6760e0)(&qpc);
  G(u64,self+0x23c6)=qpc;
  u8* embedded=self+0xc;
  u32 tick=(*(clock_fn*)0x676434)();
  double value=(double)(s32)tick*G(double,0x6785e8);
  double rounded=(double)(float)value;
  G(double,embedded)=rounded;
  vcall<void>((void*)self,0x1fc,(u32)embedded,8u,6u,0x677fb4u,0x9b1u);
  vcall<void>((void*)self,0x1fc,(u32)(self+0x23c6),8u,0xbu,0x677fb4u,0x9b2u);
}
PCREG(4234f0,stamp_event_time);
