#include "ff.h"
extern "C" void FASTCALL ext_4de420(float*,const float*);
extern "C" void FASTCALL ext_4419f0(float*,const float*);
extern "C" void FASTCALL ext_441940(float*,const float*);
static void THISCALL fn4fe700(u8* s){
 if(!G(u8,s+0x48))return;
 u32 offset=G(u32,s+0x5f)==G(u32,s+0x70)?0x74:0xa4;
 float pos[3];for(int i=0;i<3;++i)pos[i]=G(float,s+offset+4*i);
 float matrix[9];ext_4de420(matrix,(float*)(s+offset+12));
 float p0=G(float,s+0xd4),p1=G(float,s+0xd8),p2=G(float,s+0xdc),p3=G(float,s+0xe0);
 double x=crt::sin((double)p0)+crt::sin((double)p1);float dx=(float)(x+x);
 double y=crt::sin((double)p2)+crt::sin((double)p3);float dy=(float)(y+y);
 float delta[3]={dx,dy,0};
 G(float,s+0xd4)=p0+G(float,0x67da00);G(float,s+0xd8)=p1+G(float,0x697880);
 G(float,s+0xdc)=p2+G(float,0x69c69c);G(float,s+0xe0)=p3+G(float,0x699088);
 ext_4419f0(delta,matrix);ext_441940(pos,delta);
 vcall<void>(G(void*,s+0x44),0x7c,matrix,pos);
}
PCREG(4fe700,fn4fe700);
