#include "ff.h"
extern "C" float THISCALL ext_43d310(void *);
static s32 timedCvtt(float f) {return _mm_cvttss_si32(_mm_set_ss(f*G(float,0x67862c)));}
static u8 THISCALL enqueueEffect(u8 *self,u32 kind,float delay,float weight) {
 if(*(s32 *)(self+0x80)>=5)return 0;
 if(!kind) {*(u32 *)(self+0x80)=0;__builtin_memset(self+8,0,120);return 1;}
 u8 *rec=self+8+*(u32 *)(self+0x80)*24;
 *(u32 *)(rec+4)=*(u32 *)(G(u8 *,0x70039c)+0x30)-(u32)timedCvtt(delay);
 *(u32 *)rec=kind;*(float *)(rec+12)=weight;
 if(kind-1u<=10u) *(float *)(rec+8)=ext_43d310(self+0x91+kind*0x3a);
 s32 until=(s32)(*(u32 *)(rec+4)-(u32)timedCvtt(*(float *)(rec+8)));
 if(*(s32 *)(self+0x84)<=until) *(s32 *)(self+0x84)=until;
 ++*(u32 *)(self+0x80);return 1;
}
PCREG(43d980,enqueueEffect);
