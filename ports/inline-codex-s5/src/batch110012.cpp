#include "ff.h"
#define D12(T,p,o) (*(T*)((u8*)(p)+(o)))
extern "C" u32 THISCALL ext_466290(void*,u32,u32);
extern "C" long double THISCALL ext_467ca0(void*);
extern "C" u32 THISCALL ext_467000(void*,u32,u32,s32,u32);
static u8* lookup12(u32 h){return vcall<u8*>(D12(void*,G(void*,0x70039c),0x9b),0x60,h);}
static void pitch12(u8*t,u8*o){u32 p=D12(u32,t,0xf5e);D12(u32,o,0x60)=p-D12(u32,o,0x64);D12(u32,o,0x64)=p;}
static s32 ms12(float t){return _mm_cvttss_si32(_mm_set_ss(t*G(float,0x67d164)));}
static s32 THISCALL command12(u8*t,u32 line,u32 all){
 u32*tab=(u32*)(t+0xef2);
 if(D12(u32,t,0x13f)==tab[line]){float d=(float)ext_467ca0(t);if(!(G(float,0x67c194)>d))return ms12(0.f);D12(u32,t,0x13f)=0;}
 if((u8)all&&tab[line+1]){u32 h=ext_466290(t,tab[line+1],1);if(h){float d=(float)ext_467ca0(t);u8*o=lookup12(h);if(o)pitch12(t,o);return ms12(d);}}
 if(!tab[line])return ms12(0.f);
 u32 h=ext_466290(t,tab[line],1);float d=(float)ext_467ca0(t);u8*o=lookup12(h);if(o)pitch12(t,o);
 if(!(u8)all)return ms12(d);
 u32 h2=ext_467000(t,D12(u32,t,0xf4e),0,ms12(d),0);u8*o2=lookup12(h2);if(!o2)return ms12(d);
 float sum=D12(float,o2,0x70)+d;pitch12(t,o2);return ms12(sum);
}
PCREG(594040,command12);
