#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
extern "C" void THISCALL ext_4d6250(void *);extern "C" void THISCALL ext_4d68e0(void *,void *,void *);extern "C" void THISCALL ext_4d79d0(void *,u8 *,void *);extern "C" u32 STDCALL ext_62fb30(u32,void *,u32);
static void log4d(u32 line,u32 fmt,const char *name=0){void *l=vcall<void *>(G(void *,0x700390),0x20,0x696924,line);typedef void(*Log)(void *,u32,...);if(name)((Log)U(U(l,0),0x2c))(l,fmt,name);else ((Log)U(U(l,0),0x2c))(l,fmt);}
static void write4d(u8 *s,void *p,u32 n){if(vcall<u32>((void *)U(s,21),24,p,n,U(s,17))!=n)s[0x6e]=1;}
static void seek4d(u8 *s,u32 pos){vcall<void>((void *)U(s,21),16,U(s,17),pos,0);}
static u32 tell4d(u8 *s){return vcall<u32>((void *)U(s,21),12,U(s,17));}
static void THISCALL add4d7c30(u8 *s,const char *name,void *timestamp,void *data,u32 size) {
 if(U(s,9)!=1&&U(s,9)!=4){log4d(0x176,0x696948);s[0x6e]=1;return;}
 if(!vcall<u32>((void *)U(s,21),8,U(s,17))){log4d(0x17b,0x69697c,name);s[0x6e]=1;}
 char normalized[65536];u32 n=0;for(;name[n];n++)normalized[n]=name[n]=='\\'?'/':name[n];normalized[n]=0;
 u32 off=s[33]?0x52:0x46;if(U(s,off+4)>=U(s,off))ext_4d6250(s+off);U(s,off+4)++;u8 *entry=(u8 *)U(s,off+8)+(U(s,off+4)-1)*42;
 H(entry,6)=8;U(entry,2)=20;U(entry,20)=size;U(entry,16)=0;U(entry,12)=0;H(entry,24)=n;H(entry,26)=0;
 bool timeok=false;if(timestamp)timeok=((u32(STDCALL *)(void *,void *,void *))G(u32,0x676134))(timestamp,entry+10,entry+8)!=0;
 if(!timeok)ext_4d68e0(s,entry+10,entry+8);
 U(entry,12)=ext_62fb30(0,0,0);U(entry,12)=ext_62fb30(U(entry,12),data,size);
 u32 start=tell4d(s),signature=0x04034b50;write4d(s,&signature,4);write4d(s,entry+2,26);write4d(s,normalized,H(entry,24));ext_4d79d0(s,entry,data);
 if(U(entry,16)>=U(entry,20)) {
  U(entry,16)=0;H(entry,6)=0;seek4d(s,start+4);write4d(s,entry+2,26);write4d(s,normalized,H(entry,24));ext_4d79d0(s,entry,data);
 }
 u32 end=tell4d(s);seek4d(s,start+4);write4d(s,entry+2,26);seek4d(s,end);
 H(entry,0)=0x616;U(entry,28)=0;H(entry,32)=0;U(entry,34)=0;U(entry,38)=start;
}
PCREG(4d7c30,add4d7c30);
