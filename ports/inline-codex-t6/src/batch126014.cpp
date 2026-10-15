#include "ff.h"
extern "C" double VECTORCALL ext_633c60(u32,u32);
static void THISCALL calibrate(u8* me){
 if(!(G(float,me+0x58)==G(float,0x6785d0)))return;
 G(u8,me+0x1e90)=0;
 u64 start=vcall<u64>(G(void*,0x70039c),0x1c8,0x677fb4,0x9ce);
 typedef void(STDCALL *sleepfn)(u32);G(sleepfn,0x6760e4)(500);
 u64 finish=vcall<u64>(G(void*,0x70039c),0x1c8,0x677fb4,0x9d0);u64 difference=finish-start;
 double duration=ext_633c60((u32)difference,(u32)(difference>>32));duration=duration+duration;G(float,me+0x58)=(float)duration;
 void* log=vcall<void*>(G(void*,0x700390),0x20,0x677fb4,0x9d2);
 typedef void(*print)(void*,u32,double);(*(print*)(*(u8**)log+0x2c))(log,0x6784a8,(double)G(float,me+0x58));
 vcall<void>(me,0x1fc,(void*)(me+0x1e90),1,10,0x677fb4,0x9d4);
 vcall<void>(me,0x1fc,(void*)(me+0x58),4,15,0x677fb4,0x9d5);
}
PCREG(420070,calibrate);
