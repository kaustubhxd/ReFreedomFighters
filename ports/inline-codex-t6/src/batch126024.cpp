#include "ff.h"
extern "C" void FASTCALL ext_451890(void*,void*,float);
static void THISCALL project(float* weights,float* a,float* b,float* normal,u32 unused){
 if(normal[0]!=0||normal[1]!=0||normal[2]!=0){long double length=(long double)normal[0]*normal[0];length=length+(long double)normal[1]*normal[1];length=length+(long double)normal[2]*normal[2];long double inv=1.0L/fsqrt_x87(length);for(int i=0;i<3;++i)normal[i]=(long double)normal[i]*inv;}
 float ad=a[1]*normal[1];ad=ad+a[0]*normal[0];ad=ad+a[2]*normal[2];float bd=b[1]*normal[1];bd=bd+b[0]*normal[0];bd=bd+b[2]*normal[2];
 float sum=weights[0]+weights[1];float value=weights[0]*bd;value=value+weights[1]*ad;value=value/sum;
 ext_451890(a,normal,value-ad);ext_451890(b,normal,value-bd);
}
PCREG(4e64b0,project);
