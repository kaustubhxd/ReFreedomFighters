#include "ff.h"
extern "C" void* THISCALL ext_63eab0(void*,u32);
extern "C" u32 THISCALL ext_63f090(void*,void*);
extern "C" void THISCALL ext_63da80(void*,void*);
extern "C" void THISCALL ext_648810(void*,u8**,u32);
static void THISCALL add(u8*me,u8*arg){
 if(!me[0x10028]){u32 n=*(u32*)(me+0x1010d);if(n+1>16){typedef void(*A)();auto a=G(A,0x7003b0);if(a)a();else asm volatile("int3");}*(u8**)(me+0x10111+4*n)=arg;++*(u32*)(me+0x1010d);return;}
 auto mgr=*(u8**)(me+0x1005d);vcall<void>(mgr,0x60);auto data=*(u8**)(arg+8);auto block=vcall<u8*>(*(void**)(me+0x10151),8);u16 id=*(u16*)(data+0x5a);
 if(id)*(void**)(block+12)=ext_63eab0(mgr,id);
 else{auto record=vcall<u8*>(*(void**)(mgr+0x218),8);u32 handle=ext_63f090(mgr,record);*(u16*)(data+0x5a)=handle;(*(u8***)(mgr+0x68))[handle&0xfff]=record;*(u8**)(record+12)=arg;*(u8**)(block+12)=record;}
 id=*(u16*)(data+0x5a);(*(u8***)(me+0x10071))[id&0xfff]=block+4;auto record=*(u8**)(block+12);if(!(record[5]&1))ext_63da80(mgr,record);ext_63da80(mgr,block+4);
 u32 key=0-*(u32*)(*(u8**)(record+12)+0x4c);ext_648810(me+0x10089,&block,key);++(*(u8**)(block+12))[8];
 for(u32 i=0;i!=*(u32*)(me+0x10089);++i)(*(u8**)(me+0x1008d+4*i))[0x70]=i+1;
}
PCREG(648e50,add);
