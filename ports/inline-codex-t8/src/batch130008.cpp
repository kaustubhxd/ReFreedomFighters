#include "ff.h"
extern "C" void ext_410bc0(void*,u32,u32);
extern "C" s32 ext_410de0(void*,u32);
extern "C" void ext_401320(void*,void*,u32);
extern "C" s32 ext_401350(void*,void*);
extern "C" s32 ext_401430(void*,void*);
extern "C" s32 ext_401510(void*,void*);
extern "C" u32 THISCALL ext_4db9a0(void*,u32);
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" u16* THISCALL ext_60ed80(void*,u32*,u32*);
static bool input(u32 slot,u32 key){return (u8)vcall<u32>(G(void*,0x70039c),slot,key)!=0;}
static void THISCALL fn6553a0(u8*s){u32 flags=G(u32,s+0x1157);bool fast=input(0xe4,0x11)&&input(0xe4,0x21);if(fast){if(!G(u8,0x7f6414)){G(u8,0x7f6414)=1;G(u32,G(u8*,0x70039c)+0x1b40)=0x41200000;}}else if(G(u8,0x7f6414)){G(u8,0x7f6414)=0;G(u32,G(u8*,0x70039c)+0x1b40)=0x3f800000;}
 bool slow=input(0xe4,0x11)&&input(0xe4,0x22);if(slow){if(!G(u8,0x7f6415)){G(u8,0x7f6415)=1;G(u32,G(u8*,0x70039c)+0x1b40)=0x3dcccccd;}}else if(G(u8,0x7f6415)){G(u8,0x7f6415)=0;G(u32,G(u8*,0x70039c)+0x1b40)=0x3f800000;}
 if(input(0xe8,0x38)){u8*o=G(u8*,G(u8*,0x70039c)+0x1aa3);o[0x79]=!o[0x79];}if(input(0xe8,0x39))flags^=1;if(input(0xe8,0x30))flags^=2;G(u32,s+0x1157)=flags;}
PCREG(6553a0,fn6553a0);
static s32 fn401220(u8*out,u8*other,u8*buf){if(!buf)return -133;u32 reader[5];ext_410bc0(reader,G(u32,buf),G(u32,buf+4));s32 kind=ext_410de0(reader,8);u8 magic[6]={};ext_401320(reader,magic,6);for(u32 i=0;i<6;i++)if(magic[i]!=G(u8,0x6efd38+i))return -132;
 if(kind==1){if(G(u32,buf+8)&&!G(u32,out+8))return ext_401350(out,reader);}else if(kind==3){if(G(u32,out+8))return ext_401430(other,reader);}else if(kind==5){if(G(u32,out+8)&&G(u32,other+0xc))return ext_401510(out,reader);}return -133;}
PCREG(401220,fn401220);
static void THISCALL fn48dcb0(u8*s){u8*stream=G(u8*,s+0xaec);if(!stream)return;u32 old=vcall<u32>(G(void*,0x70038c),0x48,0x8080ffu);if(G(u32,stream))vcall<void>(G(void*,G(u8*,G(u8*,0x70039c)+0x9b)+0xadc),0x300,1u);u8*cursor=stream+0x10;
 void*m=G(void*,G(u8*,G(u8*,0x70039c)+0x9b)+0xadc);u8*n=G(u8*,(u8*)m+8);while(n){u8*o=G(u8*,n+0x54);u32 flags=o?G(u32,G(u8*,o+0xc)+0x23):0x200002;if((flags&0x100000)&&(u8)ext_4db9a0(n,0x100020)){o=G(u8*,n+0x54);if((u8)vcall<u32>(o,0x308))cursor=vcall<u8*>(o,0x32c,cursor);}m=G(void*,G(u8*,G(u8*,0x70039c)+0x9b)+0xadc);vcall<void>(m,0x50,&n);}
 while(G(u32,cursor)!=~0u){void*d=G(void*,G(u8*,G(u8*,0x70039c)+0x1aa3)+0x1c);cursor=vcall<u8*>(d,0x50,cursor);}cursor+=4;void*d=G(void*,G(u8*,G(u8*,0x70039c)+0x1aa3)+0x1c);u32 remaining=G(u32,s+0xae8)+(u32)stream-(u32)cursor;vcall<void>(d,0x40,cursor,remaining);vcall<void>(G(void*,0x70038c),0x48,old);}
PCREG(48dcb0,fn48dcb0);
static u8 THISCALL fn4c2280(u8*s,void*reader){G(u32,s+4)&=~0x40u;vcall<void>(reader,0x48,s+0x48);vcall<void>(reader,0x44,s+0x4c);vcall<void>(reader,0x44,s+0x4e);for(u32 off=0x50;off<=0x54;off++)vcall<void>(reader,0x68,s+off);for(u32 off=0x55;off<=0x6d;off+=4)vcall<void>(reader,0x50,s+off);for(u32 off=0x71;off<=0x73;off++)vcall<void>(reader,0x68,s+off);return 1;}
PCREG(4c2280,fn4c2280);
static void THISCALL fn551fb0(void*unused,u8*p){u32 count=0;u32 id=G(u32,ext_5003d0(G(void*,p+4),0));u8*o=vcall<u8*>(G(void*,G(u8*,0x70039c)+0x9b),0x58,id);if(o&&G(void*,o+0x18)){u32 it[3];vcall<void>(G(void*,o+0x18),0x4c,it);u32 key=vcall<u32>(G(void*,o+0x18),0x5c,it);while(it[0]){void*ch=vcall<void*>(G(void*,G(u8*,0x70039c)+0x9b),0x58,key);if((u8)vcall<u32>(ch,0x1e0,0x200074u)&&!(u8)vcall<u32>(ch,0x438))count++;key=vcall<u32>(G(void*,o+0x18),0x5c,it);}}
 u8*out=ext_5003d0(G(void*,p+8),0);if(out[4]>1){void*l=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x104u);typedef void(*print_t)(void*,u32,u32);(*(print_t*)(*(u8**)l+0x2c))(l,0x69c6b0,0x69c938);typedef void(*assert_t)();G(assert_t,0x7003b0)();}G(u32,out)=count;out[4]=1;}
PCREG(551fb0,fn551fb0);
template<class R,class...A>static R com(void*o,u32 off,A...a){typedef R(STDCALL*fn)(void*,A...);return (*(fn*)(*(u8**)o+off))(o,a...);}
static void THISCALL fn61a520(void*unused,u32 count,u32 start,u8*s){if(!count)return;u8*buf=G(u8*,s+0x13f6);void*device=G(void*,s+0x1377);u32 n=count*6,offset;u16*out=ext_60ed80(buf,&n,&offset);for(u32 i=0;i<count;i++)for(u32 j=0;j<6;j++)out[i*6+j]=(u16)(start+4*i+G(u16,0x6efd2c+2*j));void*res=G(void*,buf);if(buf[0xc]&&res){com<void>(res,0x30);buf[0xc]=0;}res=G(void*,buf);if(G(void*,0x7249f0)!=res||G(u32,0x7249f4)){G(void*,0x7249f0)=res;G(u32,0x7249f4)=0;com<void>(G(void*,0x724a00),0x154,res,0u);}com<void>(device,0x11c,4u,start,count*4,offset,count*2);}
PCREG(61a520,fn61a520);
