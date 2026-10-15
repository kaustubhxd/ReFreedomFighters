#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,float*,float*);
extern "C" u32 THISCALL ext_530e80(void*,u16*,u16*,u32,u32,float);
static void THISCALL scale_widget_point(u8* self,u8* output,float* point,u8* flag) {
  G(u8,flag)=1;
  u8* obj=(u8*)G(u32,self);
  float origin[3];
  ext_43e920(origin,(float*)(obj+0x12),(float*)(obj+6));
  float dx=(G(float,point)-G(float,obj+6))/origin[0];
  float dy=(G(float,point+1)-G(float,obj+0xa))/origin[1];
  float dz=(G(float,point+2)-G(float,obj+0xe))/origin[2];
  float sx=(float)(s32)G(u32,obj+0x3c);
  float sy=(float)(s32)G(u32,obj+0x40);
  float sz=(float)(s32)G(u32,obj+0x44);
  u16 coords[3];
  coords[0]=(u16)(s32)(dx*sx);
  coords[1]=(u16)(s32)(dz*sy);
  coords[2]=(u16)(s32)(dy*sz);
  ext_530e80(obj,(u16*)output,coords,1,10,1.0f);
}
PCREG(530bf0,scale_widget_point);
