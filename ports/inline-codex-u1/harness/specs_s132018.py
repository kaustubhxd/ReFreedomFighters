import struct
from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0x80);parent=rnd(c,16);e.w32(p+0x5c,parent)
 values=[0,0,-0.0,1,-1,r.uniform(-100,100)]
 e.w32(p+0x6c,fb(r.choice(values)));e.w32(p+0x74,fb(r.choice(values)))
 target=[r.choice(values) for _ in range(3)]
 def get(e,k):
  for i,x in enumerate(target):e.w32(e.arg32(0)+4*i,fb(x))
 hook_rec(c,0x5233a0,2,this=True,stackmark=(0,),side=get)
 rec=rnd(c,24)
 def inputs(e,k):e.wbytes(rec,e.rbytes(e.reg('ecx'),12));e.wbytes(rec+12,e.rbytes(e.reg('edx'),12))
 threshold=struct.unpack('<f',e.rbytes(0x683770,4))[0]
 angle=r.choice([0,threshold,threshold-0.0001,threshold+0.0001,r.uniform(-1,4)])
 hook_rec(c,0x4e0030,0,this='mark',side=inputs,st0=angle)
 return [p,F(r.uniform(-5,5))]
S(0x5133d0,'GUESS horizontal predicted heading alignment','thiscall',None,ret='al',gen=gen)
