from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0xa0);sys=rnd(c,0x100);e.w32(0x70039c,sys)
 for p,v in [(s+0x78,r.uniform(0,1000)),(sys+0x48,r.uniform(0,1)),(s+0x8c,r.uniform(-30,30))]:e.wbytes(p,struct.pack('<f',v))
 start=rnd(c,12*20);e.w32(s+0x7c,start);e.w32(s+0x80,start+12*r.randrange(1,20))
 for i in range(28):e.w32(s+4+4*i,rnd(c,0x20))
 rec=e.alloc(28*20,4)
 def first(em,k):
  for j,v in enumerate([em.reg('ecx'),em.arg32(0),em.arg32(1)]):em.w32(rec+k*20+j*4,v)
 def second(em,k):em.w32(rec+k*20+12,em.reg('ecx'));em.w32(rec+k*20+16,em.arg32(0))
 hook_rec(c,0x5ac640,2,this=True,side=first);hook_rec(c,0x5ac5b0,1,this=True,side=second)
 return [s]
S(0x5f09b0,'GUESS animate scrolling item strip','thiscall',None,ret=None,gen=gen)
