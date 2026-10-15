#include "ff.h"
extern "C" void THISCALL ext_4de7a0(void*);
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" float THISCALL ext_44c840(float*);
extern "C" void FASTCALL ext_446ee0(float*,float*,float*);
extern "C" void FASTCALL ext_4e0d40(float*,float*,float);
extern "C" void FASTCALL ext_441940(float*,float*);
static u8 THISCALL resolve(u8* me,float* matrix,float* out,u32 key,u8* ob){
 u32 id=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x50,key);
 u32 count=*(u32*)(me+0x69);u8* found=0;
 for(u32 i=0;i<count;i++){u8* row=me+0x6d+i*0x38;if(*(u32*)row==id){found=row;break;}}
 if(!found)return 0;
 float f=*(float*)(me+0x251);
 if(f!=0.0f && !*(u16*)(*(u8**)(ob+8)+0x5a) && *(u32*)(found+4)==0x15){
  out[0]=0;out[1]=160.0f;out[2]=0;
  ext_4de7a0(matrix);ext_43e920(matrix,(float*)(me+0x259),out);ext_44c840(matrix);
  matrix[6]=0;matrix[7]=-1.0f;matrix[8]=0;
  ext_446ee0(matrix+3,matrix+6,matrix);ext_44c840(matrix+3);ext_446ee0(matrix+6,matrix+3,matrix);
  float tmp[3];ext_4e0d40(tmp,matrix,20.0f);ext_441940(out,tmp);
 }else vcall<void>(me,0xc,matrix,out,*(u32*)(found+4),ob);
 return 1;
}
PCREG(646060,resolve);
