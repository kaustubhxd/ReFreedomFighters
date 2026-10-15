#include "ff.h"
extern "C" void* FASTCALL ext_59d4e0(void*,void*,void*);
extern "C" u8* FASTCALL ext_59d530(void*,void*,void*);
extern "C" u8* STDCALL ext_6014a0(u32);
extern "C" void THISCALL ext_54f870(void*,void*,u32);
static void copy64(void* dst,const void* src){
 for(int i=0;i<4;++i)_mm_storeu_ps((float*)((u8*)dst+16*i),_mm_loadu_ps((float*)((const u8*)src+16*i)));
}
static void THISCALL insertRecord(u8** s,u8* at,const u8* value){
 u8* end=s[1];
 if(end!=s[2]){
  if(end)copy64(end,end-64);
  s[1]=end+64;
  u8 local[64];copy64(local,value);
  ext_59d4e0(at,end-64,end);
  copy64(at,local);
 }else{
  s32 count=((s32)((u32)end-(u32)s[0]))>>6;
  u32 capacity=count?(u32)count*2:1;
  u8* data=capacity?ext_6014a0(capacity*64):nullptr;
  u8* next=ext_59d530(s[0],at,data);
  if(next)copy64(next,value);
  next=ext_59d530(at,s[1],(u8*)((u32)next+64));
  s32 oldcap=((s32)((u32)s[2]-(u32)s[0]))>>6;
  if(oldcap)ext_54f870(s,s[0],(u32)oldcap*64);
  s[0]=data;s[2]=(u8*)((u32)data+capacity*64);s[1]=next;
 }
}
PCREG(5a3550,insertRecord);
