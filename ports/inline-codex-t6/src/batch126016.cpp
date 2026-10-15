#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_4de4b0(void*,void*,void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_4419f0(void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" void FASTCALL ext_4de480(void*,void*);
extern "C" void FASTCALL ext_441970(void*,void*,void*);
static void STDCALL world(u8* dest,u8* source,u8* reference){
 float relative[3],matrix[9];ext_43e920(relative,source+0x24,reference+0x24);ext_441a60(relative,reference);ext_4de4b0(matrix,source,reference);ext_4de420(dest+0x10,matrix);
 for(int i=0;i<3;++i)G(float,dest+4*i)=relative[i];u8* node=source;
 while(!(G(u32,node+0x3c)&0x40000)){node=G(u8*,node+0x50);ext_4419f0(dest,node);ext_441940(dest,node+0x24);ext_4de480(dest+0x10,node);}
 float pivot[3];ext_441970(pivot,source+0x30,dest+0x10);ext_441940(dest,pivot);
 G(u32,dest+0xc)=G(u32,source+0x4c);G(u32,dest+0x34)=G(u32,source+0x40);G(u32,dest+0x38)=G(u32,source+0x44);G(u32,dest+0x3c)=G(u32,source+0x48);
}
PCREG(64a700,world);
