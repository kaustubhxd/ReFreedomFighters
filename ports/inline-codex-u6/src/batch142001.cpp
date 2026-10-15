#include "ff.h"
extern "C" float FASTCALL ext_4e0870(float*,float*);
extern "C" void FASTCALL ext_4e2c60(float*,float*);
extern "C" void FASTCALL ext_4de040(void*,float*,u32);
static void THISCALL update(u8* me,float* a,float* b,float* c,float* d){
 void* owner=*(void**)(me+0x164a); if(!owner)return;
 float p[3]={0,0,0}; vcall<void>(owner,0x84,p); vcall<void>(me,0x8c,p);
 u8* data=*(u8**)(me+8); float radius=*(float*)(data+0x4c);
 float dist=ext_4e0870(p,(float*)(data+0x30));
 if(!(radius+G(float,0x67da2c)>dist))return;
 u8* sys=G(u8*,0x70039c); void* ob=vcall<void*>(*(void**)(sys+0x9b),0x58,*(u32*)(me+0x123));
 float mat[9],q[3]; vcall<void>(ob,0x80,mat,q); vcall<void>(me,0x94,mat,q);
 u8* od=*(u8**)((u8*)ob+8); float vec[3]={*(float*)(od+0x40),*(float*)(od+0x44),*(float*)(od+0x48)};
 ext_4e2c60(mat,vec);
 u8 packet[0x79]; packet[0]=0; *(void**)(packet+1)=ob; *(float*)(packet+5)=100.0f;
 *(float*)(packet+9)=vec[0]; *(float*)(packet+13)=vec[1]+G(float,0x680a84); *(float*)(packet+17)=vec[2];
 *(float*)(packet+0x75)=1.0f;
 q[0]=a[0]; q[1]=0; q[2]=a[2]; ext_4de040(packet+0x15,q,0);
 q[0]=c[0]; q[1]=0; q[2]=c[2]; ext_4de040(packet+0x45,q,0);
 for(int i=0;i<3;i++){ *(float*)(packet+0x39+4*i)=b[i]; *(float*)(packet+0x69+4*i)=d[i]; }
 packet[0]=0; *(float*)(packet+0x75)=1.0f;
 vcall<void>(me,0x130,owner,(u32)*(u16*)(me+0x2ce),packet);
}
PCREG(5172e0,update);
