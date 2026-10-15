#include "ff.h"
extern "C" void FASTCALL ext_4de040(float*,const float*,const float*);
extern "C" void FASTCALL ext_4ddcb0(float*,const float*,float);
extern "C" void FASTCALL ext_4de480(float*,const float*);
extern "C" void THISCALL ext_5254c0(void*);
extern "C" void THISCALL ext_526df0(void*);
extern "C" void THISCALL ext_524b00(void*);
extern "C" void THISCALL ext_526cf0(void*);
extern "C" void THISCALL ext_5255d0(void*);
#define A21(T,o) (*(T*)(t+(o)))
static void THISCALL init21(u8*t,const u32*p,const u32*d){
 for(int i=0;i<3;i++)A21(u32,4*i)=p[i];
 for(int i=0;i<3;i++)A21(u32,0x4c+4*i)=d[i];A21(u32,0x50)=0;
 for(int i=0;i<3;i++)A21(u32,0x58+4*i)=A21(u32,0x4c+4*i);
 float*m=(float*)(t+0xc);ext_4de040(m,(float*)(t+0x4c),0);vcall<void>(A21(void*,0x88),0x7c,m,t);
 ext_5254c0(t);ext_526df0(t);ext_524b00(t);
 float roll=A21(float,0x38),tilt=A21(float,0x30);A21(u32,0x50)=0;ext_4de040(m,(float*)(t+0x4c),0);
 float a[9],b[9];ext_4ddcb0(a,m,roll);ext_4ddcb0(b,m+6,tilt);ext_4de480(m,a);ext_4de480(m,b);
 vcall<void>(A21(void*,0x88),0x7c,m,t);ext_526cf0(t);ext_5255d0(t);vcall<void>(A21(void*,0x88),0x7c,m,t);
 u8*s=G(u8*,0x70039c);A21(float,0x48)=(float)*(s32*)(s+0x40)*G(float,0x6785e4);A21(u32,0x84)=*(u32*)(s+0x40)+0x1c00;
}
PCREG(525640,init21);
