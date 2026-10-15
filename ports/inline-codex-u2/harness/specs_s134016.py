from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def put(p,v):e.wf32(p,v)
 me=obj(c,0x100,{0x8c:pystub(c,2,this=True)});a=rnd(c,0x40);b=rnd(c,0x100);e.w32(a+0x18,b);e.w32(me+0x44,a);put(b+0x84,r.uniform(-10,10))
 sys=sysobj(c);e.w32(sys+0x1a9f,r.choice([0,1,2]));e.w32(sys+0x40,r.choice([0,1,100,1000,1024,10000,0x7fffffff,0x80000000]))
 e.w32(me+0x60,r.randrange(4));e.w32(me+0x64,r.randrange(3));e.w32(me+0xa8,r.randrange(5));e.w32(me+0xb4,r.choice([0,1,2,5,10,0xffffffff]))
 for off in [0x68,0x6c,0xd1,0xd5]:put(me+off,r.uniform(-10,10))
 put(me+0x98,r.choice([0,0.01,0.1,1.,10.]));put(me+0x9c,r.choice([0,0.5,1.,10.,r.uniform(-10,10)]));put(me+0xb8,r.choice([0,0.01,0.1,1.,5.,10.]))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x4bc910,'GUESS timed audio parameter interpolation','thiscall',None,ret=None,gen=gen,nan_heap=True)
