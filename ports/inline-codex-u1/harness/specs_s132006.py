import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0x6400);info=rnd(c,0x8600);fx=obj(c,0x50,{8:pystub(c,0,this=True)})
 idx=r.choice([-1,0,0,1,2]);e.w32(p+0x2d,idx&0xffffffff);e.w32(p+8,info)
 e.w32(p+0x63f4,r.choice([0,fx,fx]));e.w32(p+0x39,r.choice([0,1,1,2]));e.w32(p+0x63d7,fb(r.uniform(-5,5)))
 e.w32(info+0x8065,r.choice([0,1,1,1]))
 for j in range(3):
  n=r.choice([-1,0,1,2,3,4,5]);e.w32(info+0x8071+j*0x110,n&0xffffffff)
  for i in range(max(n,0)):
   v=rnd(c,16);e.w32(v+12,fb(r.uniform(-2,2)));entry=info+0x8079+j*0x110+8*i;e.w32(entry,v);e.w32(entry+4,r.choice([1,1,8,2,0,0xffffffff]))
 return [p]
S(0x54c970,'GUESS accumulate active effect adjustments','thiscall',None,ret=None,gen=gen)
