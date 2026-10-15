#include "ff.h"
extern "C" void* ext_41e290(u32);
#define A34(T,o) (*(T*)(t+(o)))
static u8* THISCALL ctor34(u8*t,u32 shift,u32 n){
 A34(u32,0x14)=shift;A34(u32,0)=0x695b48;A34(u32,0x10)=n-1;
 u32*p=(u32*)ext_41e290(0x1c);if(p){p[0]=0x695734;p[4]=0x80;p[5]=0;p[6]=1;p[3]=0x80;p[1]=0;p[2]=0;}
 A34(u32*,8)=p;
 u32 bytes=n<=0x3fffffff?n*4:0xffffffff;u32*a=(u32*)ext_41e290(bytes);A34(u32*,4)=a;
 u32 vectorEnd=n&~7u;
 for(u32 i=0;i<vectorEnd;i++)a[i]=shift<32?G(u32,0x695d80+4*(i&3))<<shift:0;
 for(u32 i=vectorEnd;i<n;i++)a[i]=1u<<(A34(u32,0x14)&31);
 A34(u32,0xc)=0;t[0x18]=1;return t;
}
PCREG(4cc930,ctor34);
