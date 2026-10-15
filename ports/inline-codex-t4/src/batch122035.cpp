#include "ff.h"
static void FASTCALL fn4e0ab0(float* dst,float* src,float* angle){
 dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];
 float sx=(float)crt::sin((double)angle[0]),cx=(float)crt::cos((double)angle[0]);
 float sy=(float)crt::sin((double)angle[1]),cy=(float)crt::cos((double)angle[1]);
 float sz=(float)crt::sin((double)angle[2]),cz=(float)crt::cos((double)angle[2]);
 float x=dst[0],y=dst[1],z=dst[2];float a=x*cz;float b=sz*y;a=a-b;float c=cz*y;float d=x*sz;c=c+d;
 dst[0]=a;float zz=z*cx;float t=c*sx;zz=zz+t;float yy=c*cx;float e=z*sx;yy=yy-e;
 float f=a*sy;float g=a*cy;dst[1]=yy;float h=zz*cy;h=h-f;float j=zz*sy;g=g+j;dst[2]=h;dst[0]=g;
}
PCREG(4e0ab0,fn4e0ab0);
