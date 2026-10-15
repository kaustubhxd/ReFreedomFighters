#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" int THISCALL ext_530e80(void*,u16*,const u16*,u32,u32,float);
static int THISCALL nearest(u8* it,u16* out,float* p,u8* flag){
 *flag=1;u8* oct=*(u8**)it;float extent[3];ext_43e920(extent,(float*)(oct+0x12),(float*)(oct+6));
 float x=(p[0]-*(float*)(oct+6))/extent[0]*(float)*(s32*)(oct+0x3c);
 float y=(p[1]-*(float*)(oct+10))/extent[1]*(float)*(s32*)(oct+0x44);
 float z=(p[2]-*(float*)(oct+14))/extent[2]*(float)*(s32*)(oct+0x40);
 u16 c[3]={(u16)_mm_cvtt_ss2si(_mm_set_ss(x)),(u16)_mm_cvtt_ss2si(_mm_set_ss(z)),(u16)_mm_cvtt_ss2si(_mm_set_ss(y))};
 return ext_530e80(*(void**)it,out,c,10,1,1.0f);
}
PCREG(530bf0,nearest);
