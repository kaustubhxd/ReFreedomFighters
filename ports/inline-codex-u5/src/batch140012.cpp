#include "ff.h"
extern "C" u8* ext_41e290(u32);
extern "C" void* ext_634d10(void*,u32,u32);
extern "C" void grid_write(u8* me,s32 x,s32 y,const char* text){
 if(*(float*)(G(u8*,0x70039c)+0x9c7)==G(float,0x6785d0))return;
 s32 width=vcall<s32>(me,0xec),height=vcall<s32>(me,0xf0);
 if(x>=width || x<0 || y>=height || y<0)return;
 u32 size=(u32)width*(u32)height;
 if(!*(void**)(me+0x74)){u8* p=ext_41e290(size);*(u8**)(me+0x74)=p;ext_634d10(p,0,size);}
 s32 len=0;while(text[len])++len;
 if(len+x>width)len=width-x;
 u8* base=*(u8**)(me+0x74);u8* end=base+size;u8* p=base+width*y;
 for(s32 i=0;i<x;++i){if(p>=end)return;++p;}
 s32 copied=0;
 for(;copied<len;++copied){if(p>=end)return;*p++=text[copied];}
 for(;copied<width;++copied){if(p>=end || !*p)return;*p++=0;}
}
PCREG(651230,grid_write);
