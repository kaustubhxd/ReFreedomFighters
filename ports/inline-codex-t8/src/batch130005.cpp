#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" void THISCALL ext_50d7b0(void*,u32*);
extern "C" void THISCALL ext_4db7c0(void*,void*);
extern "C" void THISCALL ext_64a120(void*,void*);
extern "C" void* ext_634d22(void*,void*,u32);
extern "C" u8* FASTCALL ext_42c130(u32,u8*);
extern "C" void FASTCALL ext_42f840(u8*);
extern "C" void FASTCALL ext_441970(void*,void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
static void THISCALL fn50db50(u8*unused,u8*p){u32 key=G(u32,ext_5003d0(G(void*,p+4),0));u8*o=vcall<u8*>(G(void*,G(u8*,0x70039c)+0x9b),0x58,key);
 if(o){u32 mat[9],v[3],w[3];vcall<void>(o,0x80,mat,v);ext_4db7c0(G(void*,o+8),w);void*tab=G(void*,G(u8*,0x70039c)+0x9b);u32 id=vcall<u32>(o,0x20);u32 value=vcall<u32>(tab,0x4c,id);void*maker=G(void*,G(u8*,G(u8*,0x70039c)+0x9b)+0xadc);u32 made=vcall<u32>(maker,0x364,value,mat,v,w);
 if(made){u32 out=vcall<u32>(G(void*,G(u8*,0x70039c)+0x9b),0x4c,made);ext_50d7b0(ext_5003d0(G(void*,p+8),0),&out);return;}}
 ext_5002f0(ext_5003d0(G(void*,p+8),0),0);}
PCREG(50db50,fn50db50);
static void THISCALL fn64dbb0(u8*s,u32 key){vcall<void>(G(void*,s+0x1005d),0x60);u32 count=G(u32,s+0x10089),idx=0;u8*arr=s+0x1008d;for(;idx<count;idx++){u8*o=G(u8*,arr+4*idx);if(G(u32,G(u8*,o+0xc)+0xc)==key)break;}
 if(idx==count){typedef void(*assert_t)();G(assert_t,0x7003b0)();return;}ext_64a120(s,G(void*,arr+4*idx));u32 left=G(u32,s+0x10089)-idx-1;if(left){ext_634d22(arr+4*idx,arr+4*idx+4,4*left);ext_634d22(s+0x100cd+4*idx,s+0x100d1+4*idx,4*left);}G(u32,s+0x10089)--;for(u32 i=0;i<G(u32,s+0x10089);i++)G(u8*,arr+4*i)[0x70]=(u8)(i+1);}
PCREG(64dbb0,fn64dbb0);
static void THISCALL fn42dd30(void*unused,u8*src,u32 arg,u8*dst){u32 n=0;while(src[n])n++;if(n>0x1fe){void*l=vcall<void*>(G(void*,0x700390),0x20,0x6799acu,0x340u);typedef void(*print_t)(void*,u32,u8*);(*(print_t*)(*(u8**)l+0x2c))(l,0x679d04,src);return;}
 u8 buf[512];for(u32 i=0;i<=n;i++)buf[i]=src[i];typedef u8*(*find_t)(u8*,u32);u8*q=G(find_t,0x676254)(buf,0x3d);if(q)*q=0x20;u8*p=ext_42c130(arg,buf);while(*p==' '||*p==9||*p==13||*p==10)p++;u32 i=0;while(p[i]){dst[i]=p[i];i++;}dst[i]=0;ext_42f840(dst);}
PCREG(42dd30,fn42dd30);
static void THISCALL fn453290(u8*s,void*draw,u32 unused,void*m,void*translate){if(!(s[0x14]&1))return;u32 v[4][3];ext_441970(v[0],s+0x22,m);ext_441970(v[1],s+0x2e,m);ext_441970(v[2],s+0x3a,m);ext_441970(v[3],s+0x46,m);for(u32 i=0;i<4;i++)ext_441940(v[i],translate);void*o=G(void*,s+0x52);u32 flags=o&&vcall<u32>(o,0x14)?0x24:0x34;vcall<void>(draw,0x8c,v[0],v[1],v[2],flags);vcall<void>(draw,0x8c,v[2],v[3],v[0],flags);}
PCREG(453290,fn453290);
static void transfer(u8*s,u8*p,u32 slot,u32 line,u32 fmt){ext_5002f0(ext_5003d0(G(void*,p+8),0),0);u32 a=G(u32,ext_5003d0(G(void*,p+4),0));void*owner=vcall<void*>(s,0x4c,a);if(!owner)return;u32 b=G(u32,ext_5003d0(G(void*,p+4),1));void*child=vcall<void*>(s,0x48,b);if(!child)return;void*link=vcall<void*>(child,0x2f4);void*base=vcall<void*>(owner,0x20);
 if(link!=base&&link!=owner){void*l=vcall<void*>(G(void*,0x700390),0x20,0x69d420u,line);u8*n=vcall<u8*>(child,0x2e8);u32 cn=G(u32,n+4);u8*o=vcall<u8*>(owner,0x20);u32 on=G(u32,o+4);typedef void(*print_t)(void*,u32,u32,u32);(*(print_t*)(*(u8**)l+0x2c))(l,fmt,on,cn);return;}
 vcall<void>(child,0xbc,0u);vcall<void>(child,0x2c);vcall<void>(owner,slot,child,0u);ext_5002f0(ext_5003d0(G(void*,p+8),0),1);}
static void THISCALL fn50b9b0(u8*s,u8*p){transfer(s,p,0x548,0x315,0x69d810);}
PCREG(50b9b0,fn50b9b0);
static void THISCALL fn50bab0(u8*s,u8*p){transfer(s,p,0x54c,0x2cd,0x69d7e8);}
PCREG(50bab0,fn50bab0);
