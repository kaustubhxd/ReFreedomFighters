#include "ff.h"
static u8 THISCALL test(u8* me){
 float p[3]={*(float*)(me+0x2b3),*(float*)(me+0x2b7),*(float*)(me+0x2bb)};vcall<void>(me,0x8c,p);
 if(!((double)*(float*)(me+0x227)>__builtin_fabs((double)p[0])))return 0;
 if(!((double)*(float*)(me+0x22b)>__builtin_fabs((double)p[1])))return 0;
 if(!((double)*(float*)(me+0x223)>__builtin_fabs((double)p[2])))return 0;
 u32 first[3]={0x43960000,0,0};void* tab=*(void**)(G(u8*,0x70039c)+0x9b);first[2]=vcall<u32>(tab,0x4c,me);
 vcall<void>(me,0x130,*(u32*)(me+0x2af),(u32)*(u16*)(me+0x2d4),first);
 float packet[7];float x=*(float*)(me+0x227);packet[0]=x+x;packet[1]=p[1];packet[2]=p[2];packet[3]=x*G(float,0x692b60);packet[4]=p[1];packet[5]=p[2];
 tab=*(void**)(G(u8*,0x70039c)+0x9b);*(u32*)(packet+6)=vcall<u32>(tab,0x4c,me);
 vcall<void>(me,0x84,packet);vcall<void>(me,0x84,packet+3);
 vcall<void>(me,0x130,*(u32*)(me+0x2af),(u32)*(u16*)(me+0x2d2),packet);
 return 1;
}
PCREG(514f60,test);
