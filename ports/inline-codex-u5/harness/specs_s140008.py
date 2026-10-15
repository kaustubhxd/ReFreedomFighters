import struct
from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 m=rnd(c,36)
 values=[r.uniform(-100,100) for _ in range(9)]
 mode=r.randrange(7)
 if mode==0:values=[1.,0.,0.,0.,1.,0.,0.,0.,1.]
 if mode==1:values=[0.]*9
 if mode==2:values[6:9]=values[3:6]
 if mode==3:values[r.randrange(9)]=float('nan')
 if mode==4:values=[r.choice([0.,-0.,1.,-1.,2.]) for _ in range(9)]
 if mode==5:values=[r.uniform(-1e-20,1e-20) for _ in range(9)]
 e.wbytes(m,struct.pack('<9f',*values))
 return [m]
S(0x4e2aa0,'GUESS rebuild orthonormal basis','thiscall',None,ret=None,gen=gen,nan_heap=True)
