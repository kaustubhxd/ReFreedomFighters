import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 args=rnd(c,0x10);inp=rnd(c,0x20);outlist=rnd(c,0x10);e.w32(args+4,inp);e.w32(args+8,outlist)
 values=[rnd(c,8) for _ in range(4)];out=rnd(c,8);e.wbytes(out+4,bytes([r.choice([0,2,1,3,255])]))
 for p in values[1:]:e.wbytes(p,struct.pack('<f',r.uniform(-100,100)))
 def lookup(em,k):return out if em.reg('ecx')==outlist else values[em.arg32(0)]
 hook_rec(c,0x5003d0,1,this=True,ret=lookup)
 pos=struct.pack('<3f',*(r.uniform(-100,100) for _ in range(3)));mat=struct.pack('<9f',*(r.uniform(-5,5) for _ in range(9)))
 def transform(em,k):e.wbytes(em.arg32(0),mat);e.wbytes(em.arg32(1),pos)
 o=obj(c,0x30,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=transform)})
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=o)})
 log=obj(c,0x30,{0x2c:pystub(c,3,pop=0)});logger=obj(c,0x30,{0x20:pystub(c,2,this=True,ret=log)});e.w32(0x700390,logger)
 e.w32(0x7003b0,pystub(c,0,pop=0,ret=r.getrandbits(32)))
 return [rnd(c,0x10),args]
S(0x510bf0,'GUESS store distance expression result','thiscall',None,ret=None,gen=gen)
