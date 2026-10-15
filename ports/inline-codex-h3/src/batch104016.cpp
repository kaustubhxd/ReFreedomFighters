#include "ff.h"
extern "C" void FASTCALL ext_633654(u32,u32);
static void THISCALL transform_vector_rows(u8* self,float* input) {
  u32 buffer[26];
  for(u32 i=0;i<26;i++) buffer[i]=0;
  buffer[0]=3;
  u32 object=G(u32,0x724a00);
  for(u32 i=0;i<3;i++) {
    u32 off=i*0x20;
    float x=G(float,(u8*)input+off+0x10);
    float y=G(float,(u8*)input+off+0x14);
    float z=G(float,(u8*)input+off+0x18);
    bool skip=(x==0.0f && y==0.0f && z==0.0f && i!=2);
    if(!skip) {
      buffer[1]=G(u32,(u8*)input+off+0x10);
      buffer[2]=G(u32,(u8*)input+off+0x14);
      buffer[3]=G(u32,(u8*)input+off+0x18);
      buffer[4]=G(u32,(u8*)input+off+0x1c);
      if(i==2) for(u32 j=0;j<4;j++) buffer[9+j]=G(u32,(u8*)input+0x60+j*4);
      buffer[16]=G(u32,(u8*)input+off)^0x80000000u;
      buffer[17]=G(u32,(u8*)input+off+4)^0x80000000u;
      buffer[18]=G(u32,(u8*)input+off+8)^0x80000000u;
      vcall<u32>((void*)object,0xb0,object,i,(u32)buffer);
    }
    vcall<u32>((void*)object,0xb8,object,i,skip?0u:1u);
  }
  for(u32 i=3;i<4;i++) vcall<u32>((void*)object,0xb8,object,i,0u);
}
PCREG(611710,transform_vector_rows);
