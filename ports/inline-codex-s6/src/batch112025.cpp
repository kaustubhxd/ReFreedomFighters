#include "ff.h"
extern "C" void THISCALL ext_65c730(void*);
static void THISCALL stats(u8*me){
 ext_65c730(me);u32 base=G(u32,G(u32,G(u32,0x70039c)+0x1aa3)+0x20);
 for(u32 i=0;i!=*(u32*)(me+0x20);++i){u8*entry=me+0x28+8*i;u32 kind=*(u32*)entry&15;if(kind>2)continue;auto obj=*(u8**)(entry+4);auto meta=*(u8**)(*(u8**)(*(u8**)(obj+8)+0x10)+8);auto counters=*(u8**)(me+0x10051);
 if(kind==2){auto data=*(u8**)(obj+0x1c);u32 n=*(u32*)data,mode=*(u32*)(meta+12);if(mode==3||mode==4)n*=*(u32*)(data+0x1c);*(u32*)(counters+0x44)+=n;}
 else{auto data=(u16*)(base+*(u32*)(meta+0x3c));u32 n=*data++,sum=0;for(u32 j=0;j<n;++j){u32 len=*data;sum+=len-2;data+=len+1;}sum-=*(u32*)(meta+0x78);
 if(kind==1){++*(u32*)(counters+0x58);*(u32*)(counters+0x44)+=n;*(u32*)(counters+0x38)+=sum;}
 else{*(u32*)(counters+0x3c)+=n;*(u32*)(counters+0x34)+=sum;}
 }}
}
PCREG(65c840,stats);
