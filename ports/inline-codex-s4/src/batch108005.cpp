#include "ff.h"
extern "C" void FASTCALL f4e69b0(u32* keys,u32* values,s32 lo,s32 hi){
 for(;;){
  u32 seed=G(u32,0x6e7b9c),shift=seed&31;
  u32 rotated=shift?(seed<<shift)|(seed>>(32-shift)):seed;
  seed+=rotated+3;G(u32,0x6e7b9c)=seed;
  s32 left=lo,right=hi;
  u32 pivot=keys[lo+(seed&0xffffff)%(hi-lo+1)];
  do{
   while(keys[left]<pivot)left++;
   while(keys[right]>pivot)right--;
   if(left<=right){
    u32 tmp=keys[left];keys[left]=keys[right];keys[right]=tmp;
    tmp=values[left];values[left]=values[right];values[right]=tmp;
    left++;right--;
   }
  }while(left<=right);
  if(lo<right)f4e69b0(keys,values,lo,right);
  if(left>=hi)return;
  lo=left;
 }
}
PCREG(4e69b0,f4e69b0);
extern "C" void* THISCALL ext_5003d0(void*,u32);
static void log5(u32 line,u32 text){
 void* log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,line);
 typedef void(*Print)(void*,u32,u32);
 ((Print)*(u32*)(*(u32*)log+0x2c))(log,0x69c6b0u,text);
 typedef void(*Assert)();((Assert)G(u32,0x7003b0))();
}
extern "C" void STDCALL f50f1f0(u8* input){
 u8* value=(u8*)ext_5003d0(*(void**)(input+4),0);
 u32 ref=0;
 if(value[4]==3)ref=*(u32*)value;
 else if(value[4]==4)ref=vcall<u32>(*(void**)value,0x34);
 else log5(0x111,0x69c9b0);
 void* sys=G(void*,0x70039c);
 void* lookup=vcall<void*>(*(void**)((u8*)sys+0x9b),0x138);
 u8 found=0;
 vcall<void>(lookup,0x90,ref,&found);
 value=(u8*)ext_5003d0(*(void**)(input+8),0);
 if(value[4]<=1){value[4]=1;*(u32*)value=found!=0;}
 else log5(0xc4,0x69c938);
}
PCREG(50f1f0,f50f1f0);
