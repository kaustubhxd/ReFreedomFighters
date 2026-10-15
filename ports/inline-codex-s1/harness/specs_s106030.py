import struct,math
from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def floor64(em,k):
  bits=em.arg32(0)|(em.arg32(1)<<32)
  return float(math.floor(struct.unpack('<d',struct.pack('<Q',bits))[0]))
 hook_rec(c,0x634dca,2,pop=0,st0=floor64)
 e.w32(0x7003b0,pystub(c,0))
 a=r.uniform(-200,200);b=r.uniform(-200,200);c1=r.uniform(.05,10);d=r.uniform(.05,10)
 if r.random()<.25:a=r.choice([0.,-0.,.5,-.5,1.,-1.,100.,-100.])
 if r.random()<.25:b=r.choice([0.,-0.,.5,-.5,1.,-1.,100.,-100.])
 if r.random()<.2:c1=r.choice([.5,1.,1.5,2.]);d=r.choice([.5,1.,1.5,2.])
 return [F(a),F(b),F(c1),F(d),rnd(c,4),rnd(c,4),r.randrange(2)]
S(0x404ed0,'paired rounded float outputs with live x87 intermediate','cdecl',None,ret=None,gen=gen)
