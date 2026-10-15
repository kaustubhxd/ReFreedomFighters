from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0xa0)
 for off in range(0x48,0x90,4):e.wbytes(me+off,struct.pack('<f',r.uniform(-10,10)))
 values=[r.uniform(-1,1) for _ in range(6)]
 sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=lambda em,k:values[k%6])})
 target=obj(c,0x20,{0x7c:pystub(c,2,this=True,deref={0:9,1:3})});e.w32(me+0x44,target)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x4c9a00,'GUESS randomized object transform','thiscall',None,ret=None,gen=gen)
