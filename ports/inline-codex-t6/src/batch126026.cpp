#include "ff.h"
extern "C" void THISCALL ext_4db670(void*,void*);
extern "C" long double FASTCALL ext_4e0870(void*,void*);
extern "C" s32 THISCALL ext_4a0e40(void*,s32);
extern "C" s32 THISCALL ext_4a15b0(void*,s32);
static u32 rotateRight(u32 v){return (v>>1)|(v<<31);}
static void THISCALL choose(u8* me,u32 hash){
 s32 index=-1,count=(s32)(G(u32,me+0x820)+1);for(s32 i=0;i<count;++i)if(G(u32,me+4+4*i)==hash){index=i;break;}
 u8* entity=vcall<u8*>(G(void*,0x70038c),0xcc,hash);void* transform=vcall<void*>(G(void*,G(u32,0x70039c)+0x9b),0x54,G(u32,me));
 if(!G(u32,me))return;
 float a[3]={0,0,0},b[3]={0,0,0};vcall<void>(G(void*,entity+0x44),0x84,(void*)a);ext_4db670(transform,b);float distance=(float)ext_4e0870(a,b);s32 rank=ext_4a0e40(me,index);
 if(rank<=0)return;u32 k=(u32)rank&31;u32 mask=k?((1u<<k)|(1u>>(32-k))):1;
 do{--rank;u32 threshold=rank<0?0:rotateRight(mask)*500u;float bound=(float)(s32)threshold;if(!(bound>distance))break;index=ext_4a15b0(me,index);mask=rotateRight(mask);}while(rank>0);
}
PCREG(4a2380,choose);
