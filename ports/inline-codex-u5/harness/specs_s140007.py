import struct
from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 n=r.randrange(1,18);blocks=(n+3)//4
 for off in [0x300,0x500,0x580,0x600]:
  values=[r.choice([0.,1.,-1.,0.5,0.999,2.,256.,32768.,1e20,float('nan'),float('inf'),r.uniform(-2,2)]) for _ in range(blocks*4)]
  e.wbytes(0x812a40+off,struct.pack('<'+'f'*len(values),*values))
 src=rnd(c,n*36+72);dst=rnd(c,n*36+72)
 mode=r.randrange(5)
 if mode==0:dst=src
 if mode==1:dst=src+4
 return [dst,src,n]
S(0x61a980,'GUESS copy vertices with packed SIMD color','stdcall',None,ret=None,gen=gen)
