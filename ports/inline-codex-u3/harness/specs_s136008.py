import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def f3():return [r.uniform(-100,100) for _ in range(3)]
 initial=f3();delta=f3()
 def source(em,k):
  p=em.arg32(0);em.calllog.append(('initial-position',em.rbytes(p,12)));em.wbytes(p,struct.pack('<3f',*initial))
 def transform(em,k):
  p=em.arg32(0);v=struct.unpack('<3f',em.rbytes(p,12));em.wbytes(p,struct.pack('<3f',*(a+b for a,b in zip(v,delta))))
 o=obj(c,0x30,{0x84:pystub(c,1,this=True,stackmark=(0,),side=source)})
 g=obj(c,0x30,{0x8c:pystub(c,1,this=True,deref={0:3},side=transform)})
 s=rnd(c,0x140);e.wbytes(s+0x14,struct.pack('<f',r.uniform(-100,100)))
 hook_rec(c,0x516b60,3,this=True)
 hook_rec(c,0x516f40,1,this=True,deref={0:3})
 hook_rec(c,0x516fd0,1,this=True,deref={0:3})
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,g,o]
S(0x529ae0,'GUESS initialize wheel emitter pair','thiscall',None,ret=None,gen=gen)
