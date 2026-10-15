#include "ff.h"
extern "C" void THISCALL ext_4dc5d0(void*,float,float,float);
extern "C" void THISCALL ext_4dc600(void*,float*);
extern "C" void THISCALL ext_4dd060(void*,float*);
extern "C" void THISCALL ext_4dce50(void*,float);
extern "C" void FASTCALL ext_4e08d0(float*,const float*);
extern "C" void FASTCALL ext_4e0900(float*,const float*);
extern "C" void FASTCALL ext_4e09e0(float*,const float*);
extern "C" void FASTCALL ext_43e8e0(float*,const float*,const float*);
extern "C" void FASTCALL ext_43e960(float*,const float*);
extern "C" void THISCALL ext_4e0d00(float*,float);
static void THISCALL fn43e330(u8* s){
 void* target=G(void*,s+8);ext_4dc5d0(target,0,0,0);
 float lo[3]={bitsf(0x7e967699),bitsf(0x7e967699),bitsf(0x7e967699)};
 float hi[3]={bitsf(0xfe967699),bitsf(0xfe967699),bitsf(0xfe967699)};
 u8 flags=G(u8,s+0x18);
 if(flags&0x11){float p[3]={70,70,70},q[3]={-70,-70,-70};ext_4e08d0(hi,p);ext_4e0900(lo,q);}
 for(u32 k=0;k<2;++k){if(flags&(k?8:2)){float p[3],q[3];for(int j=0;j<3;++j)p[j]=G(float,s+0x1c+12*k+4*j);ext_4e09e0(q,(float*)(s+0x1c+12*k));ext_4e08d0(hi,p);ext_4e0900(lo,q);}}
 if(flags&4){lo[0]=lo[1]=-0.1f;lo[2]=G(float,s+0x34)*G(float,0x67a6b0);hi[0]=hi[1]=0.1f;hi[2]=G(float,s+0x34)*G(float,0x67a6ac);}
 float mid[3];ext_43e8e0(mid,hi,lo);ext_4e0d00(mid,0.5f);ext_4dc600(target,mid);ext_43e960(mid,lo);ext_4dd060(target,mid);
 float sum=mid[0]*mid[0]+mid[1]*mid[1];sum=sum+mid[2]*mid[2];float radius=(float)crt::sqrt((double)sum);ext_4dce50(target,radius+G(float,0x678858));
}
PCREG(43e330,fn43e330);
