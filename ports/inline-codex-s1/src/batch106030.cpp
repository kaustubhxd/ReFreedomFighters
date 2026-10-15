#include "ff.h"
extern "C" long double ext_634dca(double);
static void paired_round(float a,float b,float c,float d,float* first,float* second,u32 flag){
 bool a_larger=__builtin_fabsf(b)<__builtin_fabsf(a);
 long double rounded_a=ext_634dca((double)((long double)a*(long double)d+(long double)G(float,0x6bdffc)));
 float saved_a=(float)(rounded_a*(long double)c);
 long double rounded_b=ext_634dca((double)((long double)b*(long double)d+(long double)G(float,0x6bdffc)));
 long double live_b=rounded_b*(long double)c;
 if(a_larger)*first=saved_a;else *first=(float)live_b;
 long double sign_source=a_larger?(long double)saved_a:live_b;
 long double difference=sign_source>(long double)G(float,0x6bdfd4)?(long double)saved_a-live_b:live_b-(long double)saved_a;
 *second=(float)difference;
 if(flag){
  long double magnitude=__builtin_fabsl((long double)*first);
  if(magnitude*(long double)G(double,0x6be0a8)<(long double)*second){
   *second=(float)(magnitude*(long double)G(double,0x6be0a0));
   *first=-*first;
  }
 }
}
PCREG(404ed0,paired_round);
