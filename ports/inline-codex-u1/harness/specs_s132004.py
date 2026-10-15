import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 n=r.randrange(1,7);a=rnd(c,0x200);b=rnd(c,0x200)
 p=obj(c,0x100,{0x2cc:pystub(c,0,this=True,ret=b)});e.w32(p+0x20,n)
 e.w32(p+0x6c,obj(c,16,{0x58:pystub(c,1,this=True,ret=a)}))
 for base in [a,b]:
  for off in range(0,0x200,4):e.w32(base+off,fb(r.uniform(-3,3)))
 for i in range(1,n):
  if r.random()<0.35:
   for off in [0x48,0x4c,0x50]:e.w32(a+off+(i-1)*0x30,0)
 best=rnd(c,4);e.w32(best,fb(r.uniform(-2,2)))
 points=[rnd(c,12) for _ in range(3)]
 for v in points:
  for k in range(3):e.w32(v+4*k,fb(r.uniform(-5,5)))
 hits=[r.uniform(-2,2) for _ in range(8)];rets=[r.randrange(2) for _ in range(8)]
 def side(e,k):e.w32(e.reg('ecx'),fb(hits[min(k,7)]))
 hook_rec(c,0x4e2800,12,this='mark',side=side,ret=lambda e,k:rets[min(k,7)])
 return [p,best]+points
S(0x461aa0,'GUESS closest candidate hit','thiscall',None,ret='eax',gen=gen)
