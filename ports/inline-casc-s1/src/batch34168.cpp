#include "ff.h"
extern "C" char* THISCALL ext_4cc1d0(void*);
extern "C" void ext_42ac56(char*,const char*,int);
typedef char*(*LastFn)(char*,int);
typedef int(*NumFn)(char*);
static void THISCALL save420bb0(u8* self) {
 if(self[0x1a9b]) return;
 void* eng=G(void*,0x70039c);
 if(!vcall<u8>(eng,0xd4,0x11)) return;
 eng=G(void*,0x70039c);
 if(!vcall<u8>(eng,0xd8,0x7b)) return;
 char* s=ext_4cc1d0(self+0x2346); char* dst=(char*)0x6fd830;
 do { *dst++=*s; } while(*s++);
 char* dot=G(LastFn,0x676258)((char*)0x6fd830,'.');
 if(!dot) return;
 u32 local;
 vcall<void>(self,0x160,&local);
 char* digits=dot-4; *dot=0;
 int n=G(NumFn,0x6762e0)(digits); *dot='.';
 while(vcall<u8>(G(void*,0x700394),0x34,(char*)0x6fd830,0)) {
  ext_42ac56(digits,(const char*)0x677fb0,n);
  ++n;
  for(int i=0;i<4;++i) if(digits[i]==' ') digits[i]='0';
  digits[4]='.';
 }
 vcall<void>(*(void**)(self+0x190f),0x90,(char*)0x6fd830);
 vcall<void>(self,0x16c);
}
PCREG(420bb0,save420bb0);
