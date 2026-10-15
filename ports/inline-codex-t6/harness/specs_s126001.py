from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=obj(c,0x80,{0x84:pystub(c,1,this=True,deref={0:3})});point=rnd(c,12)
 values=[[r.uniform(-100,100) for _ in range(3)] for j in range(32)]
 distances=[r.choice([0,1,100,1e20,r.uniform(0,10000)]) for j in range(32)]
 def side(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*values[k%32]))
 hook_rec(c,0x460aa0,2,this=True,nullflag=(0,),side=side)
 hook_rec(c,0x4e0830,0)
 count=e.alloc(4,4)
 def dist(em,res):
  k=em.r32(count);em.w32(count,k+1)
  em.calllog.append(('distance',em.rbytes(em.reg('ecx'),12),em.reg('edx')))
  em.ret(eax=0,st0=distances[k%32])
 e.hook(0x4e0830,dist)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,r.getrandbits(32),point,F(r.choice([0.1,0.25,0.5,1,2,4]))]
S(0x44ac00,'GUESS nearest sampled curve parameter','thiscall',None,ret='st0',gen=gen)
