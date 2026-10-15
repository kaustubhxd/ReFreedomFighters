#include "ff.h"
#define AT7(T,p,o) (*(T*)((u8*)(p)+(o)))
typedef u32(STDCALL *WinPoint)(u32,s32*);
typedef u32(STDCALL *WinCursor)(s32,s32);
static void THISCALL mouse(u8*t,u32 unused,s32 x,s32 y){
 AT7(u32,t,0x118e)=AT7(u32,t,0x68);AT7(u32,t,0x1192)=AT7(u32,t,0x6c);
 float w=(float)(s32)vcall<u32>(t,0xd8),h=(float)(s32)vcall<u32>(t,0xdc);
 s32 p[2]={x,y};G(WinPoint,0x676238)(AT7(u32,t,0x133),p);
 AT7(u32,t,0x68)=p[0];AT7(u32,t,0x6c)=p[1];
 if(!AT7(u8,t,0x11e7))return;
 s32 origin[4];G(WinPoint,0x676210)(AT7(u32,t,0x133),origin);G(WinPoint,0x676238)(AT7(u32,t,0x133),origin);
 s32 cx=_mm_cvttss_si32(_mm_set_ss(w*G(float,0x67a6ac))),cy=_mm_cvttss_si32(_mm_set_ss(h*G(float,0x67a6ac)));
 s32 dx=(u32)x-(u32)cx,dy=(u32)y-(u32)cy;
 if(!dx&&!dy)return;
 if(!vcall<u32>(t,0x1a4)){u8*s=G(u8*,0x70039c);AT7(float,s,0x9e7)=(float)dx+AT7(float,s,0x9e7);AT7(float,s,0x9eb)=(float)dy+AT7(float,s,0x9eb);}
 G(WinCursor,0x676228)((u32)origin[0]+(u32)cx,(u32)origin[1]+(u32)cy);
 float a=(float)dx/w+AT7(float,t,0x60),b=(float)dy/h+AT7(float,t,0x64);
 AT7(float,t,0x60)=a;AT7(float,t,0x64)=b;
 if(a>G(float,0x67a6ac))AT7(u32,t,0x60)=0x3f000000;
 if(b>G(float,0x67a6ac))AT7(u32,t,0x64)=0x3f000000;
 if(G(float,0x67a6b0)>AT7(float,t,0x60))AT7(u32,t,0x60)=0xbf000000;
 if(G(float,0x67a6b0)>AT7(float,t,0x64))AT7(u32,t,0x64)=0xbf000000;
}
PCREG(654ee0,mouse);
