#include "ff.h"
extern "C" void* ext_634d22(void*,const void*,u32);
static void* THISCALL create(u8*me,void*src){
 u32 fmt=vcall<u32>(src,8);fmt=fmt==0x44585431?0x31545844:fmt==0x44585433?0x33545844:(u32)src;
 u32 levels=vcall<u32>(src,0x34),start=G(u32,G(u32,0x70039c)+0x93),w=0,h=0,remaining=0;bool first=true;
 while(w<4||h<4){if(!first)--start;first=false;u32 max=levels-1;if(max<start)start=max;remaining=levels-start;auto level=vcall<u32*>(src,0x38,start);w=level[1];h=level[2];}
 void*out;auto factory=*(void**)(me+0x22004);typedef void(STDCALL *Make)(void*,u32,u32,u32,u32,u32,u32,void**);(*(Make*)(*(u8**)factory+0x50))(factory,w,h,remaining,0,fmt,1,&out);
 void* copydest=me;for(u32 i=start,j=0;i<levels;++i,++j){auto level=vcall<u32*>(src,0x38,i);u32 lock[2]={0xcccccccc,(u32)copydest};typedef void(STDCALL *Lock)(void*,u32,u32*,u32,u32);(*(Lock*)(*(u8**)out+0x40))(out,j,lock,0,0);copydest=(void*)lock[1];ext_634d22(copydest,(void*)level[4],level[0]);typedef void(STDCALL *Unlock)(void*,u32);(*(Unlock*)(*(u8**)out+0x44))(out,j);}
 return out;
}
PCREG(612900,create);
