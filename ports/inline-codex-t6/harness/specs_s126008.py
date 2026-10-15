from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x30);point=rnd(c,12)
 def wf(a,v):e.wbytes(a,struct.pack('<f',v))
 vals=[r.uniform(0.1,20) for _ in range(3)]
 def side(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*vals))
 o=obj(c,0x20,{0x274:pystub(c,2,this=True,nullflag=(0,),deref={1:3},side=side)})
 for i in range(3):wf(point+4*i,r.uniform(-20,20))
 wf(me+0x1c,r.uniform(0.1,10));lo=r.uniform(0,2);wf(me+0x24,lo);wf(me+0x20,lo+r.uniform(0.01,4))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,o,point]
S(0x47ff20,'GUESS distance opacity ramp','thiscall',None,ret='eax',gen=gen)
