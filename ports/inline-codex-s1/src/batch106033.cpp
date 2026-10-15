#include "ff.h"
static void FASTCALL quaternion_matrix(float* out,const float* q){
 float x=q[0],y=q[1],z=q[2],w=q[3];
 float sum=((x*x+y*y)+z*z)+w*w;
 float scale=G(float,0x680a60)/sum;
 float xs=x*scale,ys=y*scale,zs=z*scale;
 float wz=w*zs,wx=w*xs,xz=x*zs,yz=y*zs,yy=y*ys,zz=z*zs,xx=x*xs,wy=w*ys,xy=x*ys;
 float one=G(float,0x678858);
 out[6]=one-(zz+yy);out[7]=xy+wz;out[3]=xy-wz;out[8]=xz-wy;
 out[4]=one-(zz+xx);out[2]=one-(yy+xx);out[5]=yz+wx;out[1]=yz-wx;out[0]=xz+wy;
}
PCREG(4df1e0,quaternion_matrix);
