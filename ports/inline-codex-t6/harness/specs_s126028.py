from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;count=r.randrange(13);source=rnd(c,max(4,count*36));dest=rnd(c,max(4,count*36))
 if r.random()<0.25:dest=source
 for i in range(count):e.wbytes(0x812640+16*i,struct.pack('<4f',*[r.choice([0,0.5,1,-1,2,r.uniform(-4,4)]) for _ in range(4)]))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [dest,source,count]
S(0x61a7d0,'GUESS pack global colors into vertex records','stdcall',None,ret=None,gen=gen)
