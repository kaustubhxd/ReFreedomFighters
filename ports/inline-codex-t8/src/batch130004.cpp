#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" u8* THISCALL ext_5ffb00(void*,u32);
extern "C" void* ext_5fa630();
extern "C" u8* ext_41e290(u32);
extern "C" u32 THISCALL ext_4cd9b0(void*,u32,u32);
extern "C" void THISCALL ext_4ce1c0(void*,u32,u32);
extern "C" void ext_634273(void*,u32);
typedef s32(*compare_t)(u8*,u8*);
typedef void(*assert_t)();
static void THISCALL fn44ce80(u8*s){void*tab=G(void*,G(u8*,0x70039c)+0x9b);void*cfg=vcall<void*>(tab,0x138);u32 id=vcall<u32>(G(void*,G(u8*,0x70039c)+0x9b),0x50,G(u32,s+8),0x10u);vcall<void>(cfg,0x60,0x680a0cu,id);
 G(u8*,s+0x20)=s+0x28;for(u32 i=0;i<8;i++){u8*d=s+0x48+0x20*i;G(u8*,s+0x28+4*i)=d;G(u8*,d+0x1c)=s+0x148+0xc0*i;G(u8*,d+0x14)=s+0x748+0x180*i;G(u32,d+0x18)=0;}G(u32,s+0x24)=0;}
PCREG(44ce80,fn44ce80);
static u8* THISCALL fn4d4de0(u8*s,u8*name){u8 buf[512];u32 len=0;do{u8 c=name[len];buf[len]=c=='/'?'\\':c;len++;}while(name[len-1]);u8*root=G(u8*,s+0x11);u32 flags=G(u32,root+4);u32 count=G(u32,root+0xc);if(!(flags&0x80000000)||!count)return 0;u8*p=root+((flags&0x40000000)?0x14+4*G(u32,root+0x10):0x10);
 while(count--){u32 kind=G(u32,p+4)&0xc0000000;u8*str=p+(kind?G(u32,p+8):8);if(G(compare_t,0x676414)(buf,str)==0)return p;p+=G(u32,p+4)&0x3fffffff;}return 0;}
PCREG(4d4de0,fn4d4de0);
static u32 script_id(u8*e){if(e[4]==3)return G(u32,e);if(e[4]==4)return vcall<u32>(G(void*,e),0x34);void*l=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);typedef void(*print_t)(void*,u32,u32);(*(print_t*)(*(u8**)l+0x2c))(l,0x69c6b0,0x69c9b0);G(assert_t,0x7003b0)();return 0;}
static u32 THISCALL fn503330(u8*s,u8*p){void*t=G(void*,p+4);u32 key=G(u32,ext_5003d0(t,0));u32 id=script_id(ext_5003d0(t,1));u32 vals[5];for(u32 i=0;i<5;i++)vals[i]=G(u32,ext_5003d0(t,i+2));u32 h=vcall<u32>(G(void*,G(u8*,0x70039c)+0x9b),0x114,id,0u,0x69ca10u,0x117u,vals);return vcall<u32>(G(void*,s+0xc),0x12c,key,h&0xffff);}
PCREG(503330,fn503330);
static u32 THISCALL fn5ffe80(u8*s,u8*query){u8*value=query;u8*last=query;for(u8*p=s;p;p=G(u8*,p+0x9c)){for(u32 i=0;i<G(u32,p+0xd0);i++){u32 key=G(u16,G(u8*,p+0xf0)+2*i);u32 n=G(u32,p+0xa8);if(n&&G(u32,p+0xa0)<=key){u32 j=(u16)(key-G(u16,p+0xa0));if(j<n){last=G(u8*,p+0xb0)+G(u32,G(u8*,p+0xac)+4*j);value=last;}else{void*l=vcall<void*>(G(void*,0x700390),0x20,0x6b9420u,0x137u);typedef void(*print_t)(void*,u32,u32);(*(print_t*)(*(u8**)l+0x2c))(l,0x69c6b0,0x6b9474);G(assert_t,0x7003b0)();value=last;}}
 else{void*parent=G(void*,p+0x9c);if(parent)value=ext_5ffb00(parent,key);else G(assert_t,0x7003b0)();}if(G(compare_t,0x676414)(query,value)==0)return G(u32,G(u8*,p+0xe0)+4*i);}}
 void*l=ext_5fa630();typedef void(*print_t)(void*,u32,u8*);(*(print_t*)(*(u8**)l+0xc))(l,0x6b9608,query);return 0;}
PCREG(5ffe80,fn5ffe80);
static void THISCALL fn659220(u8*s,u8*packed,u8*owner){G(u8*,s+0xc)=owner;u32 count=G(u16,packed);packed+=2;G(u32,s)=count;u8*data=count==1?s+0x10:ext_41e290(count*8);G(u8*,s+8)=data;G(u32,s+4)=0;for(u32 i=0;i<count;i++){u32 n=G(u16,packed);packed+=2+2*n;G(u32,data+8*i)=n;G(u32,s+4)+=n;}
 u32 index=ext_4cd9b0(owner+4,G(u32,s+4),1);if(index==~0u){void*l=vcall<void*>(G(void*,0x700390),0x20,0x6c44fcu,0x56u);typedef void(*print_t)(void*,u32);(*(print_t*)(*(u8**)l+0x30))(l,0x6c4524);data=G(u8*,s+8);if(data){u32 old=G(u32,data+4);if(old)ext_4ce1c0(G(u8*,s+0xc)+4,old&0x7fffffff,G(u32,s+4));data=G(u8*,s+8);if(data!=s+0x10)ext_634273(data,8);G(u32,s+8)=0;}return;}
 for(u32 i=0;i<G(u32,s);i++){data=G(u8*,s+8);G(u32,data+8*i+4)=index|0x80000000;index+=G(u32,data+8*i);}}
PCREG(659220,fn659220);
