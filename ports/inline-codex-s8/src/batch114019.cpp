#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" void THISCALL ext_4824c0(void *);extern "C" void THISCALL ext_58b930(void *);extern "C" void THISCALL ext_5889c0(void *,u32);extern "C" void THISCALL ext_589710(void *,void *);extern "C" u32 THISCALL ext_58b6a0(void *);
static u8 *sys58(){return G(u8 *,0x70039c);}static void *table58(){return (void *)U(sys58(),0x9b);}static void *query58(u32 off){return vcall<void *>(table58(),off);}
static void THISCALL hero58e720(u8 *s) {
 if(U(sys58(),0x1b5d)==1) {
  u32 mode=U(s,0x684),key=G(u32,0x6ed188+mode*28);
  u32 resource=vcall<u32>(query58(0x134),0x9c,key,2);void *p=vcall<void *>((void *)U(table58(),0xadc),0x25c,resource,0);U(U(s,8),0x6c)=U(U(p,8),0x6c);
  key=G(u32,0x6ed17c+U(s,0x684)*28);s32 flag=0;vcall<void>(query58(0x134),0x88,key,&flag);
  s32 index=((s32)U(s,0x684)-1)/2;u32 name=flag==3?0x6ac888:0x6ac890;void *manager=(void *)U(sys58(),0x1a9f);
  if(manager){void *x=vcall<void *>(manager,0x64,name);if(x){vcall<void>(s,0x57c,x);U(s,0xf5e)=index*100-50;}}
 }
 ext_4824c0(s);if(!U(s,0x85a))U(s,0x85a)=vcall<u32>(s,0x100,0x6a6e88);
 if(U(s,0x684)==1){void *q=query58(0x138);u32 id=vcall<u32>(table58(),0x4c,s);vcall<void>(q,0x60,0x6ac89c,id,16);}
 U(s,0x688)=0;u32 mode=U(s,0x684),a=mode==2?0x68fcbc:mode==3?0x68fccc:mode==4?0x68fcdc:0x681320,b=mode==2?0x6ac8a8:mode==3?0x6ac8b4:mode==4?0x6ac8c0:0x685a0c;
 void *q=query58(0x138);u32 id=vcall<u32>(table58(),0x4c,s);vcall<void>(q,0x60,a,id,4);
 q=query58(0x138);u32 value=0;vcall<void>(q,0x88,b,&value);U(s,0x676)=value;ext_58b930(s);
 U(G(void *,0x7003b8),0x2c39+U(s,0x684)*4)=(u32)s;
 u8 record[244];ext_5889c0(record,0);u8 *registry=G(u8 *,0x7003b8);ext_589710(registry+0xd91+U(registry,0xd8d)*244,record);U(registry,0xd8d)++;
 registry=G(u8 *,0x7003b8);*(u16 *)(s+0xeec)=0x101;U(s,0x64f)=(u32)(registry+0xc9d+U(registry,0xd8d)*244);
 u8 *scenario=(u8 *)U(registry,0x2c15);
 if(scenario){if(scenario[0x4a]=='1')s[0xeec]=0;else if(scenario[0x4a]=='2'){s[0xeec]=0;if(scenario[0x4b]=='A'){u32 args[2]={(u32)query58(0x134),0x6a757c};if(!(ext_58b6a0(args)&255))s[0xeed]=0;}}}
 if(U(s,0x852))*((u8 *)U(s,0x852)+0xe1)=0;
}
PCREG(58e720,hero58e720);
