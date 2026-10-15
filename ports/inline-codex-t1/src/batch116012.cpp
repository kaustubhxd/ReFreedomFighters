#include "ff.h"
extern "C" double VECTORCALL ext_634db2(double,double);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_451890(void*,void*,float);
extern "C" void THISCALL ext_516e20(void*,void*);
static void THISCALL fn546860(u8*s,float dt){
 float ratio=G(float,0x678858),old=*(float*)(s+0x61);
 if(old>G(float,0x6785d0))ratio=dt/old;
 float gravity=G(float,0x6ec48c)*dt;gravity*=dt;
 u8 *particles=*(u8**)(s+0xf);*(float*)(s+0x61)=dt;
 double power=ext_634db2(G(double,0x680148),(double)(dt/G(float,0x681dc4)));
 __m128 v=_mm_max_ss(_mm_set_ss(G(float,0x67c194)),_mm_set_ss(ratio));
 v=_mm_min_ss(_mm_set_ss(G(float,0x679544)),v);
 float damping=(float)(power*(double)_mm_cvtss_f32(v));
 for(s32 i=0;i<*(s32*)(s+0x28);i++){
  u8 *p=particles+0x34*i;float delta[3];ext_43e920(delta,p+0xc,p+0x18);
  for(int j=0;j<3;j++)*(u32*)(p+0x18+4*j)=*(u32*)(p+0xc+4*j);
  ext_451890(p+0xc,delta,damping);
  if(!(*(float*)(p+0x30)==G(float,0x67ff1c)))*(float*)(p+0x10)-=gravity;
 }
}
PCREG(546860,fn546860);
static u8 THISCALL fn529fa0(u8*s,void*stream){
 vcall<void>(stream,0x68,s+4);vcall<void>(stream,0x10,s+0x10,4u);
 vcall<void>(stream,0x4c,*(u32*)(s+0x14));vcall<void>(stream,0x64,*(u32*)(s+0x18));
 vcall<void>(stream,0x68,s+0x1c);vcall<void>(stream,0x60,(u32)s[0x28]);
 for(u32 off=0x29;off<=0x39;off+=4)vcall<void>(stream,0x4c,*(u32*)(s+off));
 ext_516e20(s+0x3d,stream);ext_516e20(s+0xb6,stream);return 1;
}
PCREG(529fa0,fn529fa0);
