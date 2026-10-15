#include "ff.h"
extern "C" s32 VECTORCALL ext_633910(float);
static float clip(float x){if(0.0f>x)return 0;return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(G(float,0x678858)),_mm_set_ss(x)));}
extern "C" void THISCALL saturation(u8* me,float strength){
 for(u32 i=0;i<*(u32*)(me+0x32);++i){
  u32* pixels=*(u32**)(me+0x2d);u32 old=pixels[i];
  float scale=G(float,0x682eb8);
  float b=(float)((old>>16)&255)*scale;
  float g=(float)((old>>8)&255)*scale;
  float r=(float)(old&255)*scale;
  float gray=g*G(float,0x6be13c)+b*G(float,0x6be144);
  gray=gray+r*G(float,0x6be140);
  b=clip((b-gray)*strength+gray);
  g=clip((g-gray)*strength+gray);
  r=clip((r-gray)*strength+gray);
  u32 bo=(u32)ext_633910(b*G(float,0x68af18));
  u32 go=(u32)ext_633910(g*G(float,0x68af18));
  u32 ro=(u32)ext_633910(r*G(float,0x68af18));
  pixels[i]=(old&0xff000000)+(((bo<<8)+go)<<8)+ro;
 }
}
PCREG(636c30,saturation);
