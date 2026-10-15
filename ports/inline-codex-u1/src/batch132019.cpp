#include "ff.h"
extern "C" u8* THISCALL ext_658d30(void*);
extern "C" u8* THISCALL ext_658d00(void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_4de4f0(void*,void*);
extern "C" void FASTCALL ext_43e960(void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void THISCALL ext_4de7a0(void*);
extern "C" void FASTCALL ext_4de1d0(void*,void*);
static void STDCALL bones19(u8* entry,u32 enabled){
 u8* bones=ext_658d30(entry);
 u8* geom=*(u8**)(entry+0x38);u8* owner=*(u8**)(geom+0x54);
 vcall<void>(owner,0x280,bones);
 u8* model=*(u8**)(owner+8);u8* cfg=*(u8**)(G(u8*,0x70039c)+0x1aa3);
 u8* hierarchy=vcall<u8*>(*(void**)(cfg+0x18),0xc4,*(u32*)(model+0x6c));
 float* output=(float*)ext_658d00(entry);
 for(u32 i=0;i<entry[0x3f];++i){
  float matrix[9],position[3];
  if(i){
   u8* bone=bones+0x30*i;ext_4de420(matrix,bone);
   for(int k=0;k<3;++k)position[k]=*(float*)(bone+0x24+4*k);
   u8* parent=bones+0x30*(*(u32*)(hierarchy+0xc+0x30*i));
   ext_4de4f0(matrix,parent);ext_43e960(position,parent+0x24);ext_441a60(position,parent);
  }else{ext_4de7a0(matrix);for(int k=0;k<3;++k)position[k]=0;}
  if(!(u8)enabled)((u32*)output)[i*9+7]=0xffffffff;
  ext_4de1d0(output+i*9,matrix);
  output[i*9+4]=position[0];output[i*9+5]=position[1];output[i*9+6]=position[2];
 }
}
PCREG(63ce50,bones19);
