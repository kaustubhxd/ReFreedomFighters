#include "ff.h"
extern "C" void THISCALL ext_4db500(void*,void*);
extern "C" void THISCALL ext_4db2a0(void*,void*);
static void THISCALL initialize(u8*me){
 const u32 names[4]={0x6ac968,0x6ac8fc,0x6ac920,0x6ac944};
 auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto service=vcall<void*>(table,0x138);
 table=*(void**)(G(u8*,0x70039c)+0x9b);auto id=vcall<u32>(table,0x4c,*(void**)(me+0x44),0x10);vcall<void>(service,0x60,names[*(u32*)(me+0x5a)],id);
 const u32 labels[3]={0x6b597c,0x6b5a80,0x6ac8e4};for(u32 i=0;i<3;++i){table=*(void**)(G(u8*,0x70039c)+0x9b);*(u16*)(me+0x54+2*i)=vcall<u16>(table,0x114,labels[i],0,(u32)0x6b5a48,0x2e + i);}
 table=*(void**)(G(u8*,0x70039c)+0x9b);auto old=vcall<u8*>(table,0x58,*(u32*)(me+0x50));void*result;
 if(old){u32 position[3],matrix[9];ext_4db500(*(void**)(old+8),position);ext_4db2a0(*(void**)(old+8),matrix);
 result=vcall<void*>(old,0x1bc,*(void**)(me+0x44),matrix,position,0,0,0,1);vcall<void>(result,0x2c);vcall<void>(result,0xbc,0);
 }else result=*(void**)(me+0x44);
 table=*(void**)(G(u8*,0x70039c)+0x9b);*(u32*)(me+0x50)=vcall<u32>(table,0x4c,result);*(u32*)(me+0x48)=0;*(u32*)(me+0x7b)=0;
}
PCREG(5d67e0,initialize);
