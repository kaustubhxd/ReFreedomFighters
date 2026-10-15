#include "ff.h"
extern "C" u8* ext_41e290(u32);
extern "C" void* THISCALL ext_4db7e0(void*);
extern "C" void THISCALL ext_442050(void*,void*);
extern "C" void THISCALL ext_443c80(void*,void*);
extern "C" void THISCALL ext_610100(void*,u32);
extern "C" void THISCALL ext_4e12e0(void*,void*,u32);
extern "C" void THISCALL ext_4e12f0(void*,void*,u32);
extern "C" void THISCALL ext_4e11e0(void*,void*,u32);
extern "C" u32 THISCALL ext_4e1600(void*);
extern "C" void THISCALL ext_4e1b30(void*);
extern "C" void THISCALL ext_4dc630(void*,u32,u32);
extern "C" void THISCALL ext_4db6c0(void*,void*,void*);
extern "C" u8* THISCALL ext_4dc110(void*);
typedef s32(*cmp_t)(u8*,u8*);
static s32 cmp(u8*a,u8*b){return G(cmp_t,0x676414)(a,b);}
static u32 THISCALL fn4279c0(u8*s,u8*path){typedef u8*(*last_t)(u8*,u32);u8*name=G(last_t,0x676258)(path,0x5c);name=name?name+1:path;
 void*t=G(void*,s+0x10c);u32 it[3];if(t){vcall<void>(t,0x4c,it);for(u8*p=vcall<u8*>(t,0x64,it);p;p=vcall<u8*>(t,0x64,it)){if(cmp(G(u8*,p),name)==0){G(u32,p+8)++;return G(u32,p+4);}}}
 typedef u32(STDCALL*load_t)(u8*);u32 h=G(load_t,0x676164)(path);u32 n=0;while(name[n])n++;u8*copy=ext_41e290(n+1);for(u32 i=0;i<=n;i++)copy[i]=name[i];u8*p=vcall<u8*>(G(void*,s+0x10c),4,copy);G(u32,p)=h;G(u32,p+4)=1;G(u32,p+8)=0;G(u32,p+0xc)=0;return h;}
PCREG(4279c0,fn4279c0);
static void THISCALL fn4438a0(u8*s,u32 arg){u8 a=arg;if(s[0x75]==a)return;if(!a)vcall<void>(s,0x330);s[0x75]=a?1:0;if((u8)vcall<u32>(s,0x310))return;if(!vcall<void*>(s,0x20))return;u8*o=vcall<u8*>(s,0x20);void*owner=ext_4db7e0(G(void*,o+8));if(!owner)return;
 if(a)ext_442050(owner,s);else ext_443c80(owner,s);u8*p=G(u8*,s+0x7b);if(p&&G(u16,p)){u32 i=0;do{void*ch=G(void*,G(u8*,s+0x7b)+4+4*i);if(a)ext_443c80(owner,ch);else ext_442050(owner,ch);i++;}while(i!=G(u16,G(u8*,s+0x7b)));}}
PCREG(4438a0,fn4438a0);
static void THISCALL fn454e10(u8*s,void*p){ext_610100(s,(u32)p);u32 offs[]={0x18,0x1c,0x20,0x34,0x28};for(u32 off:offs)ext_4e12e0(p,s+off,1);ext_4e12f0(p,s+0x30,1);ext_4e11e0(p,s+0x2c,1);ext_4e12e0(p,s+0x24,1);for(u32 off=0x3c;off<=0x48;off+=4)if((u8)ext_4e1600(p)==8)ext_4e12e0(p,s+off,1);ext_4e1b30(p);ext_4dc630(G(void*,s+8),0x400,0x200ff);vcall<void>(s,0x214);}
PCREG(454e10,fn454e10);
static void logmsg(u32 line,u32 msg){void*l=vcall<void*>(G(void*,0x700390),0x20,0x691edcu,line);typedef void(*print_t)(void*,u32);(*(print_t*)(*(u8**)l+0x2c))(l,msg);}
static u32 THISCALL fn4b1570(u8*s,u32 key,u32 unused){if((u16)key!=G(u16,s+0x48))return 0;void*tab=G(void*,G(u8*,0x70039c)+0x9b);void*o=vcall<void*>(tab,0x54,G(u32,s+0xf6));if(!o){logmsg(0xedb,0x6926d0);return 0;}
 u32 a[9],b[3],it[3];ext_4db6c0(o,a,b);void*t=s+0x4a;vcall<void>(t,0x4c,it);u32 val=vcall<u32>(t,0x5c,it);while(it[0]){void*ch=vcall<void*>(G(void*,G(u8*,0x70039c)+0x9b),0x58,val);if(ch)vcall<void>(ch,0x7c,a,b);else logmsg(0xed7,0x6926b0);val=vcall<u32>(t,0x5c,it);}return 0;}
PCREG(4b1570,fn4b1570);
static u32 THISCALL fn4b5500(u8*s,u32 key){void*tab=G(void*,G(u8*,0x70039c)+0x9b);void*base=vcall<void*>(tab,0x54,key);u8*owner=G(u8*,s+0x12a);if(!owner)return 0;void*t=G(void*,owner+0x18);u32 it[3];if(t){vcall<void>(t,0x4c,it);u32 val=vcall<u32>(t,0x5c,it);while(it[0]){void*o=vcall<void*>(G(void*,G(u8*,0x70039c)+0x9b),0x54,val);if(o){u8*b=ext_4dc110(o);u8*a=ext_4dc110(base);if(cmp(a,b)==0)return val;}val=vcall<u32>(t,0x5c,it);}}
 u32 out=key;u32 h=vcall<u32>(G(void*,G(u8*,0x70039c)+0x9b),0x114,0x692114u,0u,0x691edcu,0x2b6u,&out);vcall<void>(G(void*,s+0x44),0x130,owner,h&0xffff);return out==key?0:out;}
PCREG(4b5500,fn4b5500);
