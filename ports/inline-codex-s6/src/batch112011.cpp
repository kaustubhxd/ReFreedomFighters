#include "ff.h"
extern "C" s32 FASTCALL ext_42feb0(u32,u32,u32,u32);
extern "C" void THISCALL ext_42ffc0(u8**);
extern "C" void THISCALL ext_4300c0(void*,u32*,u8*,u8*,u32*);
extern "C" u32* THISCALL ext_430fc0(void*,u32*,u32*);
static u32* THISCALL insert(u8*me,u32*out,u8*hint,u32*key){
 u8*root=*(u8**)me;
 if(hint==*(u8**)(root+5)){
 if(*(u32*)(me+4)&&ext_42feb0(key[0],key[1],*(u32*)(hint+13),*(u32*)(hint+17))<0){ext_4300c0(me,out,hint,hint,key);return out;}
 }else if(hint==root){
 u8*last=*(u8**)(root+9);
 if(ext_42feb0(*(u32*)(last+13),*(u32*)(last+17),key[0],key[1])<0){ext_4300c0(me,out,0,last,key);return out;}
 }else{
 u8*prev=hint;ext_42ffc0(&prev);
 if(ext_42feb0(*(u32*)(prev+13),*(u32*)(prev+17),key[0],key[1])<0&&ext_42feb0(key[0],key[1],*(u32*)(hint+13),*(u32*)(hint+17))<0){
 if(!*(u32*)(prev+9))ext_4300c0(me,out,0,prev,key);else ext_4300c0(me,out,hint,hint,key);return out;
 }}
 u32 local[3];auto result=ext_430fc0(me,local,key);*out=*result;return out;
}
PCREG(430eb0,insert);
