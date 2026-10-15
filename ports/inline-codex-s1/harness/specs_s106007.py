import struct
from pilot import S,EDGE_F
from recruits_util import rnd,clear_hooks

def fb(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 lo=[r.uniform(-20,0) for _ in range(3)];hi=[r.uniform(0,20) for _ in range(3)]
 p=[r.uniform(-40,40) for _ in range(3)];d=[r.choice([0.,1.,-1.,r.uniform(-40,40)]) for _ in range(3)]
 mode=r.randrange(6)
 if mode==0:p=[r.uniform(lo[i],hi[i]) for i in range(3)]
 if mode==1:
  lo=[-1.,-1.,-1.];hi=[1.,1.,1.];p=[r.choice([-2.,-1.,0.,1.,2.]) for _ in range(3)];d=[r.choice([-2.,-1.,0.,1.,2.]) for _ in range(3)]
 if mode==2:
  target=[r.uniform(lo[i],hi[i]) for i in range(3)];d=[target[i]-p[i] for i in range(3)]
 vals=lo+hi+p+d
 if mode==3:vals[r.randrange(12)]=r.choice(EDGE_F)
 if mode==4:vals=[r.choice(EDGE_F) for _ in range(12)]
 out=rnd(c,4)
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [out]+[fb(f) for f in vals]
S(0x4e2800,'segment box intersection','thiscall',None,ret='al',gen=gen,nan_heap=True)
