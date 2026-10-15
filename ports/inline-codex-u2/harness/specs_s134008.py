from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;n=r.randrange(6);coeff=rnd(c,(n+1)*4);roots=rnd(c,max(n,1)*4)
 if r.random()<0.5:
  cs=[r.uniform(-3,3) for _ in range(n)]+[r.choice([1.,2.,-1.])]
 else:
  cs=[1.]
  for i in range(n):
   rt=r.choice([-3.,-2.,-1.,0.,1.,2.,3.]);new=[0.]*(len(cs)+1)
   for j,v in enumerate(cs):new[j]-=rt*v;new[j+1]+=v
   cs=new
 e.wbytes(coeff,struct.pack('<'+'f'*len(cs),*cs));e.wbytes(roots,struct.pack('<'+'f'*max(n,1),*[r.uniform(-5,5) for _ in range(max(n,1))]));e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [coeff,n,roots]
S(0x410000,'GUESS Newton refine polynomial roots','cdecl',None,ret='eax',gen=gen,nan_heap=True)
