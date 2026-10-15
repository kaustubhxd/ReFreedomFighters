import struct
from pilot import S,F
from recruits_util import rnd,clear_hooks

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 n=r.choice([0,1,2,3,8,16,32]);count=r.choice([0,1,2,3,4,5,6,7,8,9])
 out=rnd(c,4*(n+1));idx=rnd(c,4*(n+1));roots=rnd(c,4*max(1,count))
 vals=[];v=r.randrange(-30,30)
 for i in range(n):
  if r.random()<0.5:v+=r.randrange(1,4)
  vals.append(v);e.wbytes(out+4*i,struct.pack('<f',r.uniform(-10,10)))
 vals.append(100000)
 for i,v in enumerate(vals):e.w32(idx+4*i,v&0xffffffff)
 for i in range(count):e.wbytes(roots+4*i,struct.pack('<f',r.uniform(-3,3)))
 return [out,idx,n,r.choice([16,32,64,100,127]),roots,count,F(r.uniform(-1,1)),F(r.uniform(-3,3))]
S(0x40fa80,'GUESS cosine root spectral gain filter','cdecl',None,ret=None,gen=gen,nan_heap=True)
