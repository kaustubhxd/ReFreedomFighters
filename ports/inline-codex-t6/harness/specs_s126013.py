from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0xd00);out=rnd(c,12)
 camera=obj(c,0x20,{0xac:pystub(c,0,this=True,st0=r.uniform(1,100))});e.w32(me+0xb54,camera)
 for off in [0xa72,0xa7e,0xcad]:e.wbytes(me+off,struct.pack('<3f',*[r.uniform(1,10) for _ in range(3)]))
 end=[r.uniform(-100,100) for _ in range(3)]
 if r.random()<0.3:end=[r.uniform(-1e5,1e5) for _ in range(3)]
 def hit(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*end))
 hook_rec(c,0x5ceed0,6,this=True,side=hit)
 adjusted=struct.pack('<3f',*[r.uniform(-100,100) for _ in range(3)])
 def adjust(em,k):em.wbytes(em.arg32(0),adjusted)
 hook_rec(c,0x5cefc0,4,this=True,side=adjust)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,out]
S(0x5cfa00,'GUESS recruit precision aim position','thiscall',None,ret='al',gen=gen)
