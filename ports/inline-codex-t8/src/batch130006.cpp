#include "ff.h"
extern "C" void THISCALL ext_4ee210(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f3c00(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f1890(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f4080(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f4390(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f5960(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f6250(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f4ec0(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f4a30(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f6ab0(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f7960(void*,u32,u32,u32);
extern "C" void THISCALL ext_4f8630(void*,u32,u32,u32);
extern "C" void THISCALL ext_43ea20(void*);
extern "C" void THISCALL ext_4f3c30(void*);
extern "C" void THISCALL ext_4f1a10(void*);
extern "C" void THISCALL ext_4ee4e0(void*);
extern "C" void THISCALL ext_4f43d0(void*);
extern "C" void THISCALL ext_4f5990(void*);
extern "C" void THISCALL ext_4f6b80(void*);
extern "C" void THISCALL ext_4f7a00(void*);
extern "C" void THISCALL ext_4ccf60(void*);
extern "C" void THISCALL ext_4cbec0(void*);
static void fn4edef0(){u8 arena[0x8f4];
ext_4ee210(arena+0x8f4-0x64,0,0,0);ext_43ea20(arena+0x8f4-0x64);
ext_4f3c00(arena+0x8f4-0x6c,0,0,0);ext_4f3c30(arena+0x8f4-0x6c);
ext_4f1890(arena+0x8f4-0x8f4,0,0,0);ext_4f1a10(arena+0x8f4-0x8f4);
ext_4f4080(arena+0x8f4-0x98,0,0,0);ext_4ee4e0(arena+0x8f4-0x98);
ext_4f4390(arena+0x8f4-0xb8,0,0,0);ext_4f43d0(arena+0x8f4-0xb8);
ext_4f5960(arena+0x8f4-0xa4,0,0,0);ext_4f5990(arena+0x8f4-0xa4);
ext_4f6250(arena+0x8f4-0xa8,0,0,0);ext_4ee4e0(arena+0x8f4-0xa8);
ext_4f4ec0(arena+0x8f4-0xc8,0,0,0);ext_4ee4e0(arena+0x8f4-0xc8);
ext_4f4a30(arena+0x8f4-0x9c,0,0,0);ext_43ea20(arena+0x8f4-0x9c);
ext_4f6ab0(arena+0x8f4-0xac,0,0,0);ext_4f6b80(arena+0x8f4-0xac);
ext_4f7960(arena+0x8f4-0xd8,0,0,0);ext_4f7a00(arena+0x8f4-0xd8);
ext_4f8630(arena+0x8f4-0x2b8,0,0,0);ext_4ccf60(arena+0x8f4-0x1a9);ext_4cbec0(arena+0x8f4-0x229);ext_43ea20(arena+0x8f4-0x2b8);
}
PCREG(4edef0,fn4edef0);
extern "C" void THISCALL ext_562440(void*);
extern "C" void THISCALL ext_563610(void*,u32);
extern "C" void THISCALL ext_5613a0(void*,u32,u32);
extern "C" u32 THISCALL ext_4db580(void*,u32);
extern "C" u16* THISCALL ext_60ed80(void*,u32*,u32*);
static void THISCALL fn56ddc0(u8*s){ext_562440(s);void*tab=G(void*,G(u8*,0x70039c)+0x9b);void*cfg=vcall<void*>(tab,0x138);u32 name=vcall<u32>(G(void*,G(u8*,0x70039c)+0x9b),0x4c,G(u32,s+0x44));vcall<void>(cfg,0x60,0x6a82d0u,name,0x10u);ext_563610(s,0x6a6c1c);s[0x87]=0;s[0x204]=0;
 void*root=vcall<void*>(G(void*,s+0x54),0x25c,0x6a7590u,0u);u32 a=vcall<u32>(root,0x25c,0x6a82e4u,0u);u32 b=vcall<u32>(root,0x25c,0x6a82ecu,0u);tab=G(void*,G(u8*,0x70039c)+0x9b);u32 bn=vcall<u32>(tab,0x4c,b);u32 an=vcall<u32>(tab,0x4c,a);ext_5613a0(s,an,bn);u8*o=G(u8*,s+0x94);if(o)o[0x1043]=1;
 for(u32 off=0x209;off<=0x20d;off+=4){o=vcall<u8*>(G(void*,G(u8*,0x70039c)+0x9b),0x58,G(u32,s+off));if(o){u32 v[]={0x43a00000,0x3f000000};vcall<void>(o,0x258,v,0u);}}}
PCREG(56ddc0,fn56ddc0);
static bool contains(u32*list,s32 n,u32 value){for(s32 i=0;i<n;i++)if(list[i]==value)return true;return false;}
static u8 FASTCALL fn4dba00(u8*s,s32 n,u32*list){if(!n)return 0;u8*p=s;if(G(u32,p+0x3c)&0x40040000){for(;;){if(G(u32,p+0x3c)&0x40000){u32 key=G(u16,p+0x5c);if(!key)return 0;void*tab=G(void*,G(u8*,G(u8*,0x70039c)+0x9b)+8);u8*o=vcall<u8*>(tab,0x5c,key);if(!o||!o[0x1c])return 0;for(s32 i=0;i<n;i++)if(list[i]==ext_4db580(o,0))return 1;return 0;}
 p=G(u8*,p+0x50);void*o=G(void*,p+0x54);if(contains(list,n,(u32)o))return 1;if(!(vcall<u32>(o,0x2a8)&0x1000000))return 0;}}
 p=G(u8*,p+0x50);do{void*o=G(void*,p+0x54);if(contains(list,n,(u32)o))return 1;if(!(vcall<u32>(o,0x2a8)&0x1000000))return 0;p=G(u8*,p+0x50);}while(p);return 0;}
PCREG(4dba00,fn4dba00);
template<class R,class...A>static R comcall(void*o,u32 slot,A...a){typedef R(STDCALL*fn)(void*,A...);return (*(fn*)(*(u8**)o+slot))(o,a...);}
static void THISCALL fn60bfc0(u8*s,u32 count,u32 start){if(!count)return;u32 n=count*6,offset;u16*out=ext_60ed80(G(void*,s+0x13f6),&n,&offset);for(u32 i=0;i<count;i++){for(u32 j=0;j<6;j++)out[6*i+j]=(u16)(start+4*i+G(u16,0x6efce0+2*j));}
 u8*buf=G(u8*,s+0x13f6);void*resource=G(void*,buf);if(buf[0xc]&&resource){comcall<void>(resource,0x30);buf[0xc]=0;}resource=G(void*,G(u8*,s+0x13f6));if(G(void*,0x7249f0)!=resource||G(u32,0x7249f4)){G(void*,0x7249f0)=resource;G(u32,0x7249f4)=0;comcall<void>(G(void*,0x724a00),0x154,resource,0u);}comcall<void>(G(void*,s+0x1377),0x11c,4u,start,count*4,offset,count*2);G(u32,s+0x34)+=count*2;}
PCREG(60bfc0,fn60bfc0);
