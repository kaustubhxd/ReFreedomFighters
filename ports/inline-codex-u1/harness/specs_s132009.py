import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub,sysobj

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0x400)
 for off in [0x60,0x222,0x23e,0x256]:
  vals=[r.uniform(-5,5) for _ in range(3)]
  if off==0x23e and r.random()<0.5:vals=r.choice([[0,0,0],[0.00001,0,0]])
  for i,v in enumerate(vals):e.w32(p+off+4*i,fb(v))
 if r.random()<0.4:target=[e.r32(p+0x60+4*i) for i in range(3)]
 else:target=[fb(r.uniform(-10,10)) for _ in range(3)]
 def side(e,k):
  for i,x in enumerate(target):e.w32(e.arg32(0)+4*i,x)
 o=obj(c,16,{0x84:pystub(c,1,this=True,stackmark=(0,),side=side)})
 so=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=o)})
 e.w32(so+0x48,fb(r.choice([0,0.016,0.5,1.0,r.uniform(0,2)])))
 e.w32(p+0x34a,r.choice([0,0,r.getrandbits(32) or 1]))
 return [p]
S(0x51e560,'GUESS helicopter turn mode update','thiscall',None,ret=None,gen=gen)
