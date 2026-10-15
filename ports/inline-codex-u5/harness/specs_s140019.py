import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 data=rnd(c,0x60);point=rnd(c,12)
 dims=[r.choice([0.,1.,-1.,10.,r.uniform(-100,100)]) for _ in range(3)];e.wbytes(data+0x40,struct.pack('<3f',*dims))
 basis=[r.uniform(-2,2) for _ in range(9)];pos=[r.uniform(-10,10) for _ in range(3)]
 def transform(em,k):em.wbytes(em.arg32(0),struct.pack('<9f',*basis));em.wbytes(em.arg32(1),struct.pack('<3f',*pos))
 node=obj(c,0x20,{0x80:pystub(c,2,this=True,nullflag=[0],side=transform)});e.w32(node+8,data)
 randoms=[r.choice([0.,0.5,1.,r.uniform(-1,2)]) for _ in range(3)]
 sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=lambda em,k:randoms[k%3])})
 return [node,point]
S(0x5c4a00,'GUESS sample transformed random shape point','stdcall',None,ret=None,gen=gen)
