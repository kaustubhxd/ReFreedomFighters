#include "ff.h"
extern "C" void THISCALL ext_562440(void*);
extern "C" void THISCALL ext_563510(void*,u32);
extern "C" void THISCALL ext_561f10(void*,u32);
extern "C" void* ext_634dee(void*,u32);
extern "C" u32 THISCALL ext_578e30(void*);
extern "C" u32 THISCALL ext_578db0(void*);
extern "C" u32 THISCALL ext_578eb0(void*);
extern "C" u32 THISCALL ext_578d30(void*);
extern "C" void THISCALL ext_579bd0(void*,u32);
extern "C" void THISCALL ext_579b20(void*,u32);
extern "C" void THISCALL ext_579ca0(void*,u32);
extern "C" void THISCALL ext_579a60(void*,u32);
extern "C" void THISCALL ext_579d20(void*);
extern "C" u32 THISCALL ext_562d90(void*,u32);
static void THISCALL fn573180(u8*s){ext_562440(s);vcall<void>(G(void*,s+0x44),0xbc,1u);ext_563510(s,0x6a6850);
 u8*text;void*sys=G(void*,0x70039c);s32 limit=0;if((u8)vcall<u32>(sys,0x5c,0x6a7584u,&text)){typedef s32(*atoi_t)(u8*);limit=G(atoi_t,0x6762d8)(text);}
 u8*root=vcall<u8*>(G(void*,s+0x54),0x25c,0x6a7590u,0u);u8*n=G(u8*,root+0x50);
 while(n){u8*o=G(u8*,n+0x54);u32 flags=o?G(u32,G(u8*,o+0xc)+0x23):0x200002;if(!(flags&0x100000))break;
 if((u8)vcall<u32>(o,0x1e0,0x100033u)){if((s32)vcall<u32>(o,0x310)<limit)vcall<void>(o,0x2dc);}n=G(u8*,n+0x60);}
 void*cfg=vcall<void*>(G(void*,0x70039c),0xbc);if((u8)vcall<u32>(cfg,0x60,0x6a8ba8u,0u)){ext_561f10(s,1);cfg=vcall<void*>(G(void*,0x70039c),0xbc);vcall<void>(cfg,0x64,0x6a8ba8u,0u);}}
PCREG(573180,fn573180);
static void fn410bf0(u8*s,u32 val,u32 width){u32 off=G(u32,s);u32 cap=G(u32,s+0x10);if((s32)(off+4)>=(s32)cap){u8*p=(u8*)ext_634dee(G(void*,s+8),cap+0x100);G(u8*,s+8)=p;G(u32,s+0x10)=cap+0x100;G(u8*,s+0xc)=p+off;}
 u32 bit=G(u32,s+4);u32 total=width+bit;val&=G(u32,0x6f2834+4*width);u8*p=G(u8*,s+0xc);p[0]|=(u8)(val<<(bit&31));if((s32)total>=8){p[1]=(u8)(val>>((8-bit)&31));if((s32)total>=16){p[2]=(u8)(val>>((16-bit)&31));if((s32)total>=24){p[3]=(u8)(val>>((24-bit)&31));if((s32)total>=32)p[4]=bit?(u8)(val>>((32-bit)&31)):0;}}}
 s32 bytes=(s32)total/8;G(u32,s+4)=total&7;G(u32,s)=off+bytes;G(u8*,s+0xc)=p+bytes;}
PCREG(410bf0,fn410bf0);
template<class R,class...A>static R com(void*o,u32 slot,A...args){typedef R(STDCALL*fn)(void*,A...);return (*(fn*)(*(u8**)o+slot))(o,args...);}
static u8 THISCALL fn429230(u8*s,void*dev){u32 line=0,msg=0x6792d0;
 if(com<u32>(dev,0xc,s+0x1a1,(void**)(s+0xd),0u))line=0x327;
 else{void*o=G(void*,s+0xd);if(com<u32>(o,0x2c,0x6be160u))line=0x330;else if(com<u32>(o,0x34,G(u32,G(u8*,0x70039c)+0x9db),6u))line=0x33b;else{u32 desc[]={0x14,0x10,0,0,0x14};if(com<u32>(o,0x18,1u,desc)){line=0x355;msg=0x679300;}else{if(G(void*,s+0xd))vcall<void>(s,0x28);return 1;}}}
 void*l=vcall<void*>(G(void*,0x700390),0x20,0x678f5cu,line);typedef void(*print_t)(void*,u32);(*(print_t*)(*(u8**)l+0x2c))(l,msg);return 0;}
PCREG(429230,fn429230);
static void THISCALL fn571a40(u8*s,u8*out){u32 mode=0;void*o=G(void*,s+0xf4);if(o&&(u8)vcall<u32>(o,0x1e0,0x80100032u))mode=vcall<u32>(G(void*,s+0xf4),0x354);if(mode<1||mode>3)return;
 void*table=G(void*,G(u8*,G(u8*,0x70039c)+0x9b)+0xae4);u32 key=mode==1?0x6a67d4:mode==2?0x6a67f8:0x6a680c;u8*text=vcall<u8*>(table,0,0x6a67e8u,key);
 if(mode==3){u32 dollars=0;for(u32 i=0;text[i];i++)if(text[i]=='$'&&++dollars==3){text+=i;break;}}
 u32 n=0;while(out[n])n++;G(u16,out+n)=G(u16,0x679e6c);while(out[n])n++;for(u32 i=0;;i++){out[n+i]=text[i];if(!text[i])break;}}
PCREG(571a40,fn571a40);
static u8 THISCALL fn579880(u8*s,u32 key){if((u8)vcall<u32>(s,0xd8))return 0;if(key==0x102||key==0x103){void*o=vcall<void*>(s,0x84);void*tab=G(void*,G(u8*,0x70039c)+0x9b);u32 id=vcall<u32>(o,0x2f0);u32 v=vcall<u32>(tab,0x4c,id);bool found=true;
 if(v==G(u32,s+0x180))ext_579bd0(s,!(u8)ext_578e30(s));else if(v==G(u32,s+0x184))ext_579b20(s,!(u8)ext_578db0(s));else if(v==G(u32,s+0x188)){ext_579ca0(s,!(u8)ext_578eb0(s));ext_578eb0(s);}else if(v==G(u32,s+0x190))ext_579a60(s,!(u8)ext_578d30(s));else found=false;
 ext_579d20(s);if(found)return 1;}
 return (u8)ext_562d90(s,key);}
PCREG(579880,fn579880);
