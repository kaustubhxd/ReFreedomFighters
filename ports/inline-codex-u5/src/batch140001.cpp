#include "ff.h"
extern "C" void FASTCALL ext_441940(void*,void*);
static float mx(float a,float b){return _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(a),_mm_set_ss(b)));}
static float mn(float a,float b){return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a),_mm_set_ss(b)));}
extern "C" void THISCALL viewport_bind(u8* me,u8* target){
 if(!target)return;
 float pos[3]={0,0,0};
 for(void* node=me;node;node=vcall<void*>(node,0x20)){
  if(!vcall<u8>(node,0x1e0,0x10002eu))break;
  vcall<void>(node,0x1a8,pos);
  ext_441940(pos,*(u8**)((u8*)node+8)+0x24);
 }
 float one=G(float,0x678858);
 if(one>*(float*)(me+0x9b))*(float*)(me+0x9b)=1.0f;
 if(one>*(float*)(me+0x9f))*(float*)(me+0x9f)=1.0f;
 u8* sys=G(u8*,0x70039c);
 float rect[4]={pos[0]/(float)*(s32*)(sys+0x6f),pos[1]/(float)*(s32*)(sys+0x73),0,0};
 u8* owner=vcall<u8*>(me,0x2c4);
 float h=*(float*)(me+0x9f);
 float w=*(float*)(owner+0x9b)* *(float*)(me+0x9b);
 sys=G(u8*,0x70039c);
 w=w/(float)*(s32*)(sys+0x6f);h=h/(float)*(s32*)(sys+0x73);
 rect[1]=mx(rect[1],0);rect[0]=mx(rect[0],0);
 rect[3]=mn(h,one-rect[1]);rect[2]=mn(w,one-rect[0]);
 vcall<void>(target,0x23c,rect);
 vcall<void>(me,0x358,1u);
 u32 id=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x4c,me);
 vcall<void>(target,0x27c,id);
 *(u32*)(target+0x48)|=0x8000;
 *(u32*)(target+0x4c)=*(u32*)(me+0x97);
 vcall<void>(target,0x250);
}
PCREG(4f7730,viewport_bind);
