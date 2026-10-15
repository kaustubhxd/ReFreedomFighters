from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x980);sys=rnd(c,0x100);e.w32(0x70039c,sys)
 n=r.randrange(1,8);idx=r.randrange(n);e.w32(s+0x91e,r.choice([0,1,2,5]));e.w32(s+0x926,idx);e.w32(s+0x90c,n)
 p=s+0x4c+58*idx;e.wbytes(p+7,bytes([r.randrange(4),r.randrange(4)]));e.wbytes(p+0x35,struct.pack('<f',r.uniform(-10,10)));e.w32(sys+0x40,r.choice([0,100,0xffffffff,0x7fffffff]))
 count=r.randrange(7);e.w32(s+0x92a,count)
 e.wbytes(s+0x92e,bytes(r.randrange(32) for _ in range(count)))
 hook_rec(c,0x5be810,1,this=True,ret=r.choice([0,1,0x100,0x101]))
 hook_rec(c,0x5be720,0,this=True,ret=rnd(c,0x20))
 hook_rec(c,0x5bf340,2,this=True)
 return [s]
S(0x5be5b0,'GUESS civilian path frame update','thiscall',None,ret=None,gen=gen)
