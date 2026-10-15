#include "ff.h"
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
extern "C" void FASTCALL ext_43e960(void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" u32 THISCALL ext_63db70(void*);
static void THISCALL fn4f0270(u8*s,u8*hit,float*point,u32 mode){
 if(s[0x21]==0x80)return;u8*geo=*(u8**)(s+8);float world[3];ext_43e8e0(world,point,geo+0x24);
 void*thing=*(void**)(hit+0x10);void*manager=*(void**)(G(u8*,0x70039c)+0x190f);
 void*entry=vcall<void*>(manager,0x20,*(u32*)((u8*)thing+8));u32 type=ext_63db70(entry);
 float result[3],aux[3],matrix[9];vcall<void>(s,0x220,type,thing,mode,world,result,aux,matrix);
 float low[3],high[3];ext_43e8e0(low,*(u8**)(s+8)+0x30,result);for(int i=0;i<3;i++)high[i]=low[i];ext_43e960(low,*(u8**)(s+8)+0x40);ext_441940(high,*(u8**)(s+8)+0x40);
 if(low[0]<0 && high[0]>0 && low[1]<0 && high[1]>0 && *(float*)(hit+0xc)>result[2]){
  *(u32*)hit=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x4c,s);for(int i=0;i<3;i++)*(float*)(hit+4+4*i)=result[i];
 }
}
PCREG(4f0270,fn4f0270);
