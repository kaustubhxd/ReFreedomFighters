import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 count=r.randrange(0,9);arr=rnd(c,max(4,count*4));arr2=rnd(c,max(4,count*4));s=rnd(c,0x20);e.w32(s,count);e.w32(s+4,arr);e.w32(s+8,arr2)
 selected=r.randrange(count+1)
 for i in range(count):
  a=obj(c,0x20,{0x2c:pystub(c,0,this=True),0x70:pystub(c,1,this=True,deref={0:3}),0x128:pystub(c,3,this=True)})
  b=obj(c,0x20,{0x2c:pystub(c,0,this=True),0x74:pystub(c,2,this=True,deref={0:9,1:3}),0x128:pystub(c,3,this=True)})
  p=rnd(c,0x50);e.w32(p+0x3c,0x400 if i==selected else 0);e.w32(a+8,p);e.w32(arr+4*i,a);e.w32(arr2+4*i,b)
 position=rnd(c,12);direction=rnd(c,12)
 for p in [position,direction]:e.wbytes(p,struct.pack('<3f',*(r.uniform(-5,5) for _ in range(3))))
 matrix=struct.pack('<9f',*(r.uniform(-5,5) for _ in range(9)))
 def make(em,k):
  em.calllog.append(('direction',em.rbytes(em.reg('edx'),12)));em.wbytes(em.reg('ecx'),matrix)
 hook_rec(c,0x4de040,1,this='mark',side=make)
 assertstub=pystub(c,0,pop=0,ret=r.getrandbits(32));e.w32(0x7003b0,assertstub)
 return [s,position,direction]
S(0x5a5950,'GUESS activate first flagged paired effect','thiscall',None,ret='eax',gen=gen)
