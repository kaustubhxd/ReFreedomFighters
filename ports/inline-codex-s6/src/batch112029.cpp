#include "ff.h"
extern "C" void THISCALL ext_63da80(void*,void*);
extern "C" u32 THISCALL ext_658f50(void*);
extern "C" u32 THISCALL ext_658d30(void*);
static void THISCALL use(u8*me,u8*main){
 ext_63da80(*(void**)(me+0x1005d),main);vcall<void>(me+0x10171,8,&main);++(*(u8**)(main+8))[0x3e];
 for(u8*res=*(u8**)(main+0x1c);res;res=*(u8**)(res+0x1c)){
 ext_63da80(*(void**)(me+0x1005d),res);auto data=*(u8**)(res+8);u8 old=data[9]++;if(!old)vcall<void>(*(void**)(me+0x1005d),0xa0,data);
 auto meta=*(u8**)(data+0x10);if(!meta)continue;
 u16 before=(*(u16*)(meta+12))++;if(!before)ext_63da80(*(void**)(me+0x1005d),meta);
 u32 index=*(u16*)(*(u8**)(meta+8)+6)&0xfff;auto record=(*(u8***)(me+0x10071))[index];u32 prev=(*(u32*)(record+12))++;if(!prev)vcall<void>(me,0x48,record);
 auto queue=*(u32**)(me+0x181c5);if(queue){if(queue[0]+1>0x2000){typedef void(*A)();auto a=G(A,0x7003b0);if(a)a();else asm volatile("int3");}queue[queue[0]+1]=(u32)res;++queue[0];}
 if(ext_658f50(meta)>1)res[5]|=8;
 }
 if(ext_658d30(*(void**)(main+8)))vcall<void>(me+0x10199,8,&main);
 if(*(u32*)(main+12)){auto local=main;vcall<void>(me+0x101ad,8,&local);}
}
PCREG(64c090,use);
