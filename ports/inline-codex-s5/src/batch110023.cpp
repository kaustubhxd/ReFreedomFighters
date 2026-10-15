#include "ff.h"
#define A23(T,o) (*(T*)(t+(o)))
typedef s32(*Compare23)(u32,u32);
typedef u32(*Log23)(void*,u32,u32);
static u8* THISCALL ctor23(u8*t){
 A23(u32,4)=0;A23(u32,0)=0x6b0214;for(int i=0;i<0xa0;i++)t[0xbe + i]=0;
 t[8]=0;t[0x48]=0;t[0x4d]=0;A23(u32,0x60)=2;
 u32 cfg;u8 yes=vcall<u8>(G(void*,0x70039c),0x5c,0x6b021cu,&cfg);
 if(yes){void*l=vcall<void*>(G(void*,0x700390),0x20,0x6b022cu,0x12u);((Log23)(*(u32*)(*(u32*)l+0x2c)))(l,0x6b0260,cfg);
 Compare23 cmp=G(Compare23,0x676414);
 if(!cmp(0x6b0284,cfg))A23(u32,0x60)=0;
 else if(!cmp(0x6b0290,cfg))A23(u32,0x60)=1;
 else if(!cmp(0x6b0298,cfg))A23(u32,0x60)=2;
 else if(!cmp(0x6b02a0,cfg))A23(u32,0x60)=3;
 else{l=vcall<void*>(G(void*,0x700390),0x20,0x6b022cu,0x20u);((Log23)(*(u32*)(*(u32*)l+0x2c)))(l,0x6b02a8,cfg);}}
 A23(u32,0x6a)=0;A23(u32,0x6e)=0;A23(u16,0x4d)=0x414e;A23(u32,0x50)=1;t[0x64]=0;
 A23(u32,0x54)=0;A23(u32,0x58)=0;A23(u32,0x5c)=0;A23(u16,0x68)=0;A23(u32,0x72)=0;
 for(int i=0;i<3;i++){A23(u32,0xb2+4*i)=0;for(int j=0;j<5;j++)A23(u32,0x76+20*i+4*j)=0;}
 return t;
}
PCREG(5acc20,ctor23);
