import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 values=[fb(r.uniform(-500,500)),fb(r.uniform(-500,500))]
 def pos(e,k):
  for i,x in enumerate(values):e.w32(e.arg32(0)+4*i,x)
 sys=obj(c,16,{0x308:pystub(c,1,this=True,stackmark=(0,),side=pos),0x34c:pystub(c,5,this=True),0x350:pystub(c,3,this=True)})
 p=obj(c,0xe0,{0x2c4:pystub(c,0,this=True,ret=sys),0x358:pystub(c,0,this=True)})
 ident=r.getrandbits(32);e.w32(p+0xab,ident);e.w8(p+0xd3,r.randrange(2))
 return [p,r.choice([ident,ident,ident^1]),r.choice([1,1,2,2,8,0,3,0xffffffff])]
S(0x4f8120,'GUESS slider state notifications','thiscall',None,ret='al',gen=gen)
