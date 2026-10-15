#include "ff.h"
extern "C" float THISCALL ext_53fe30(void*,float);
extern "C" void THISCALL ext_53e900(void*);
extern "C" double VECTORCALL ext_634db2(double,double);
static void THISCALL frame(u8* me){
 if(!G(u8,me+0x10f)||!G(u32,me+0x66))return;
 float dt=G(float,G(u32,0x70039c)+0x48),cap=G(float,0x681dc4),energy=0;
 float left=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(cap),_mm_set_ss(dt)));
 while(left>0){if(left>cap){energy=ext_53fe30(me,0.05f);left=left-cap;if(G(float,0x6a2de4)>left)break;}else{energy=ext_53fe30(me,left);break;}}
 float decayed=G(float,me+0xfb)*G(float,0x6a2de8);decayed=decayed+energy;G(float,me+0xfb)=decayed;
 if(!G(u8,me+0x10f)||G(float,me+0xff)>decayed){ext_53e900(me);if(G(u8,me+0x149))vcall<void>(me,0x58);}
 float ratio=dt/cap;double factor=ext_634db2(G(double,0x6a2df8),(double)ratio);G(float,me+0xff)=(float)(factor*(double)G(float,me+0xff));
}
PCREG(53e970,frame);
