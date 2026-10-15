#include "ff.h"
extern "C" void FASTCALL ext_4de420(float*,float*);
extern "C" void FASTCALL ext_446ee0(float*,float*,float*);
extern "C" float THISCALL ext_44c840(float*);
static u8 THISCALL fn5a7560(u8* s,u8* obj,u32 key){
 if(key!=*(u32*)(s+0x1c))return 0;
 if(!*(u32*)(s+0x18))return 1;
 float* dst=vcall<float*>(obj,0x38);float* src=vcall<float*>(obj,0x40);
 if(*(u32*)(s+0x18)==2){ext_4de420(dst,src);return 1;}
 float* basis=vcall<float*>(obj,0x3c);
 float dot=basis[1]*src[1];float p=basis[0]*src[0];dot=dot+p;dot=dot+basis[2]*src[2];
 double abs=_mm_cvtsd_f64(_mm_and_pd(_mm_set_sd((double)dot),G(__m128d,0x67cd50)));
 if(abs>G(double,0x680148)){ext_4de420(dst,src);return 1;}
 dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];
 ext_446ee0(dst+6,basis+3,dst);ext_44c840(dst+6);ext_446ee0(dst+3,dst,dst+6);return 1;
}
PCREG(5a7560,fn5a7560);
