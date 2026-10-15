#include "ff.h"
extern "C" u32 THISCALL ext_591b20(u8*);
static float minss(float a,float b){return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a),_mm_set_ss(b)));}
static void THISCALL fn5d0df0(u8* s){
 float x=*(float*)(s+0xe0f)**(float*)(s+0xadd);float y=*(float*)(s+0xe13)**(float*)(s+0xadd);
 if(ext_591b20(*(u8**)(s+0x44))==9){
  float low=G(float,0x6b4fd8),high=G(float,0x681dc4);
  x=low>x?low:minss(high,x);y=low>y?low:minss(high,y);
 }
 float wrap=G(float,0x67da18);
 if(x>G(float,0x6ad1fc)||G(float,0x6ad234)>x)x=wrap;
 float yaw=*(float*)(s+0xa54)-x;
 if(yaw>wrap)yaw=yaw-G(float,0x68aef8);else if(G(float,0x6ad238)>yaw)yaw=yaw+G(float,0x68aef8);
 *(float*)(s+0xa54)=yaw;
 float pitch=*(float*)(s+0xa5c)-y,low=G(float,0x6b4ff0);
 *(float*)(s+0xa5c)=low>pitch?low:minss(G(float,0x6a09e4),pitch);
}
PCREG(5d0df0,fn5d0df0);
