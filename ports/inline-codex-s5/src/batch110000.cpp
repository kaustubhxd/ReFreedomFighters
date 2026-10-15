#include "ff.h"
extern "C" void THISCALL ext_460100(void*,void*,void*,void*,void*,float);
extern "C" long double THISCALL ext_4602b0(void*,void*,float,void*,u32);
extern "C" long double FASTCALL ext_4e0830(void*,void*);
static float THISCALL f44b140(u8*t,u8*p,u8*chosen){
 void* mgr=*(void**)(*(u32*)(G(u32,0x70039c)+0x1aa3)+0x18);
 u32 id=*(u32*)(*(u32*)(t+8)+0x6c);
 u8*items=(u8*)vcall<u32>(mgr,0xfc,id);
 u32 count=*(u32*)vcall<u32>(mgr,0x100,id),index=0;
 u8*best=0;
 if(chosen){bool found=false;for(u32 i=0;i<count;i++)if(chosen==items+36*i){index=i;found=true;break;}
 if(found)best=chosen;else { ((void(*)())G(u32,0x7003b0))(); }
 }else{float dist=G(float,0x67cd44);for(u32 i=0;i<count;i++)for(int j=0;j<3;j++){
 float d=(float)ext_4e0830(items+36*i+12*j,p);if(dist>d){dist=d;best=items+36*i;index=i;}
 }}
 u8 local[0x38];*(u32*)local=0x67f86c;*(u32*)(local+0x34)=0xbf800000;
 ext_460100(local,best,(void*)((u32)best+12),(void*)((u32)best+24),(void*)((u32)best+36),0.1f);
 float out;ext_4602b0(local,p,0.0f,&out,10);
 float den=(float)(s32)(count-1);return (float)(s32)index/den+0.0f/den;
}
PCREG(44b140,f44b140);
