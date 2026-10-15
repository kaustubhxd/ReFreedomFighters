#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" u32 FASTCALL ext_4cc850(const char *,const char *);
static bool eq566(const char*a,const char*b){while(*a&&*a==*b){a++;b++;}return *a==*b;}
static u32 THISCALL choose566360(u8 *s,const char *input) {
 char pattern[32];u32 len=0,n=0;while(input[len])len++;
 if(len>6)while(n<30&&n+6<len&&input[n+6]!='_'){pattern[n+1]=input[n+6];n++;}
 pattern[0]='*';pattern[n+1]=0;pattern[n+2]=0;
 bool special=eq566(pattern+1,(char *)0x6a6df4)||eq566(pattern+1,(char *)0x6a6dfc);
 if(!special)pattern[n+1]='*';
 u32 chosen[8],count=0,it[3];void *list=(void *)U(U(s,0x180),24);
 if(list){vcall<void>(list,0x4c,it);u32 id=vcall<u32>((void *)U(U(s,0x180),24),0x5c,it);
  while(it[0]) {
   void *table=(void *)U(G(void *,0x70039c),0x9b);u32 item=vcall<u32>(table,0x58,id);u8 *desc=vcall<u8 *>((void *)item,0x20);const char *name=(const char *)U(desc,4);if(!name)name=(char *)0x67c8e8;
   if(!special){if(!ext_4cc850(name,pattern))return item;}
   else {u32 match=0;for(u32 i=0;name[i];i++){if(pattern[1+match]==name[i]){if(++match==n){if(count<8)chosen[count++]=item;break;}}else match=0;}}
   id=vcall<u32>((void *)U(U(s,0x180),24),0x5c,it);
  }
 }
 if(!special){void *logger=vcall<void *>(G(void *,0x700390),0x20,0x6a6d50,0x188);typedef void(*Log)(void *,u32,const char *);((Log)U(U(logger,0),0x2c))(logger,0x6a6e08,pattern);return 0;}
 ((void(*)(s32))G(u32,0x676454))((s32)U(G(void *,0x70039c),48)>>10);s32 value=((s32(*)())G(u32,0x67644c))();return chosen[value%(s32)count];
}
PCREG(566360,choose566360);
