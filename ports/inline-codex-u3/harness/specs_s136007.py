import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def floats(n):return struct.pack('<'+'f'*n,*(r.uniform(-10,10) for _ in range(n)))
 data=bytes([r.randrange(2)])+floats(21);mat=floats(9);pos=floats(3)
 def describe(em,k):em.wbytes(em.arg32(1),data)
 def transform(em,k):em.wbytes(em.arg32(0),mat);em.wbytes(em.arg32(1),pos)
 sub=obj(c,0x30,{0x98:pystub(c,2,this=True,deref={0:9,1:3})})
 target=obj(c,0x40,{0x128:pystub(c,3,this=True,stackmark=(1,),side=describe),0x80:pystub(c,2,this=True,stackmark=(0,1),side=transform),0x20:pystub(c,0,this=True,ret=sub),0x7c:pystub(c,2,this=True,deref={0:9,1:3})})
 s=rnd(c,0x150);e.w32(s+0x44,target);e.wbytes(s+0x11b,floats(6));e.wbytes(s+0xea,floats(1));e.w32(s+0xf6,r.choice([0,1,0xffffffff,0x7fffffff,r.getrandbits(32)]))
 hook_rec(c,0x4e73b0,5,this=True,deref={0:3,1:3,2:3})
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s]
S(0x4a71f0,'GUESS update attached effect transform','thiscall',None,ret=None,gen=gen)
