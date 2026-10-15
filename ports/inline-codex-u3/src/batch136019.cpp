#include "ff.h"
struct Record53{u8 bytes[53];};
extern "C" void THISCALL ext_4ae2b0(u8*,Record53);
static void FASTCALL fn4add60(u8*first,u8*last){
 if(first==last || first+53==last)return;
 for(u8*p=first+53;p!=last;p+=53){
  Record53 value;for(int j=0;j<53;j++)value.bytes[j]=p[j];
  if(*(float*)first>*(float*)value.bytes){
   for(u8*q=p;q!=first;q-=53)for(int j=0;j<53;j++)q[j]=(q-53)[j];
   for(int j=0;j<53;j++)first[j]=value.bytes[j];
  }else ext_4ae2b0(p,value);
 }
}
PCREG(4add60,fn4add60);
