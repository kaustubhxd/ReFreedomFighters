#include "ff.h"
extern "C" void THISCALL ext_446320(void*,float*,float*);
static void THISCALL layout23(u8* self,u32 unused,u32 state){
 if(!self[0x88] || state!=1 || !self[0x1f1])return;
 float p[3]={0,0,0};vcall<void>(*(void**)(self+0x1ec),0x84,p);
 void* camera=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,*(u32*)(self+0x1c4));
 float local[3]={p[0],p[1],p[2]};vcall<void>(camera,0x8c,local);
 float screen[2]={0,0};ext_446320(camera,screen,local);
 u8* sys=G(u8*,0x70039c);
 p[0]=(float)(*(s32*)(sys+0x6f))*(screen[0]+G(float,0x67a6ac));
 p[1]=(float)(*(s32*)(sys+0x73))*(screen[1]+G(float,0x67a6ac));
 float factor=G(float,0x67da0c);
 void* settings=vcall<void*>(sys,0xbc);if(vcall<u8>(settings,0xdc))factor=G(float,0x6a913c);
 float x=(float)(*(s32*)(G(u8*,0x70039c)+0x6f))*factor;
 p[0]=(float)_mm_cvttss_si32(_mm_set_ss(x));p[2]=0;
 void* panel=vcall<void*>(*(void**)(self+0x180),0x20);vcall<void>(panel,0x70,p);
 p[0]=(float)(*(s32*)(G(u8*,0x70039c)+0x6f))-p[0]*G(float,0x680a60);p[1]=20.0f;
 vcall<void>(*(void**)(self+0x188),0x70,p);self[0x1f1]=0;
}
PCREG(573930,layout23);
