#include "ff.h"
extern "C" void THISCALL ext_4e3630(void*,void*,u32,u32,u32,u32);
extern "C" void ext_633654(u32);
static void THISCALL transform_query(u8* me,u8* out,const float* a,const float* b){
 float first[3],second[3];float scale=*(float*)(me+0x10),bias=G(float,0x6972d4);
 for(int i=0;i<3;i++)first[i]=(a[i]-*(float*)(me+4+4*i))*scale+bias;
 for(int i=0;i<3;i++)second[i]=(b[i]-*(float*)(me+4+4*i))*scale+bias;
 u8* data=*(u8**)(me+0x14);
 *(void**)(out+0xc)=data+0x14;
 data=*(u8**)(me+0x14);
 *(void**)(out+0x30)=first;*(void**)(out+0x10)=data+*(u32*)data;*(void**)(out+0x34)=second;
 ext_4e3630(*(void**)(out+0xc),out,0x10000,0x8000,0x8000,0x8000);
 ext_633654(0);
}
PCREG(4e39e0,transform_query);
