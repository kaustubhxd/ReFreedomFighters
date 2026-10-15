#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
template<class R,class...A>static R com429(void *p,u32 off,A...a){return ((R(STDCALL *)(void *,A...))U(U(p,0),off))(p,a...);}
template<class R,class...A>static R imp429(u32 addr,A...a){return ((R(STDCALL *)(A...))G(u32,addr))(a...);}
extern "C" s32 ext_42ac96(u32,u32,u32 *);
static u32 contains429(u32 p,u32 text){return ((u32(*)(u32,u32))G(u32,0x676274))(p,text);}
static u32 THISCALL detect429470(u32 *s) {
 void *locator=0,*service=0,*enumerator=0,*items[20]={};u32 count=0;u32 first=0,second=0,third=0,result=0;
 bool initialized=imp429<s32>(0x67648c,0)>=0;
 if(imp429<s32>(0x676490,0x678ea8,0,1,0x678eb8,&locator)<0||!locator)goto cleanup;
 first=imp429<u32>(0x676174,0x678ec8);if(!first)goto cleanup;
 second=imp429<u32>(0x676174,0x678ee8);if(!second)goto frees;
 third=imp429<u32>(0x676174,0x678f08);if(!third)goto frees;
 if(com429<s32>(locator,12,first,0,0,0,0,0,0,&service)<0||!service)goto frees;
 imp429<s32>(0x676488,service,10,0,0,3,3,0,0);
 if(com429<s32>(service,0x48,second,0,0,&enumerator)<0||!enumerator)goto frees;
 if(com429<s32>(enumerator,16,10000,20,items,&count)<0)goto frees;
 while(count) {
  for(u32 i=0;i<count;i++) {
   u8 variant[16];
   if(com429<s32>(items[i],16,third,0,variant,0,0)>=0&&*(u16 *)variant==8&&U(variant,8)) {
    u32 value=U(variant,8);
    if(contains429(value,0x678f1c)) {
     u32 low=0,high=0,p=contains429(value,0x678f24);
     if(p&&ext_42ac96(p,0x678f30,&low)!=1)low=0;
     p=contains429(value,0x678f40);if(p&&ext_42ac96(p,0x678f4c,&high)!=1)high=0;
     if(((high<<16)|(low&65535))==*s){result=1;goto frees;}
    }
   }
   if(items[i]){com429<u32>(items[i],8);items[i]=0;}
  }
  if(com429<s32>(enumerator,16,10000,20,items,&count)<0)break;
 }
frees:
 imp429<void>(0x676170,first);if(third)imp429<void>(0x676170,third);if(second)imp429<void>(0x676170,second);
cleanup:
 for(u32 i=0;i<20;i++)if(items[i])com429<u32>(items[i],8);
 if(enumerator)com429<u32>(enumerator,8);if(locator)com429<u32>(locator,8);if(service)com429<u32>(service,8);
 if(initialized)imp429<void>(0x676484);return result;
}
PCREG(429470,detect429470);
