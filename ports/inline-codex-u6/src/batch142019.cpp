#include "ff.h"
extern "C" void FASTCALL ext_443ef0(float*,float*,float*,float);
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" void THISCALL ext_523330(void*,float*);
extern "C" float FASTCALL ext_4e0030(float*,float*);
extern "C" void FASTCALL ext_446ee0(float*,float*,float*);
static void THISCALL position(u8* me,float* a,float* b,float* direction,float* angle){
 float p[3];ext_443ef0(p,(float*)(*(u8**)(me+8)+0x24),(float*)(me+0x15df),bitsf(*(u32*)(me+0x37c)^0x80000000));
 ext_43e920(direction,a,p);direction[1]=0;
 if(direction[0]!=0 || direction[2]!=0){long double x=direction[0],y=direction[1],z=direction[2];long double inv=1.0L/fsqrt_x87(x*x+y*y+z*z);direction[0]=(float)(x*inv);direction[1]=(float)(y*inv);direction[2]=(float)(z*inv);}
 ext_443ef0(b,a,direction,bitsf(*(u32*)(me+0x378)^0x80000000));
 float other[3];ext_523330(*(void**)(me+0x5c),other);other[1]=0;
 *angle=ext_4e0030(other,direction);float cross[3];ext_446ee0(cross,other,direction);
 if(cross[1]>0)*angle=bitsf(fbits(*angle)^0x80000000);
}
PCREG(518380,position);
