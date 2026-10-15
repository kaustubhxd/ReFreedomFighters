import struct,math
from pilot import S
from recruits_util import rnd,obj,sysobj,pystub,clear_hooks

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def fp():return struct.pack('<3f',*[r.choice([0.,-1.,1.,r.uniform(-3,3)]) for _ in range(3)])
 record=e.alloc(64,4)
 def packet(em,k):em.wbytes(record+32*k,em.rbytes(em.arg32(2),12 if k==0 else 28))
 after=fp();before=fp()
 def transform(em,k):em.wbytes(em.arg32(0),after)
 def effect(em,k):em.wbytes(em.arg32(0),before)
 me=obj(c,0x300,{0x8c:pystub(c,1,this=True,deref={0:3},side=transform),0x84:pystub(c,1,this=True,deref={0:3},side=effect),0x130:pystub(c,3,this=True,stackmark=(2,),side=packet)})
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=lambda em,k:0x12345678+k)})
 e.wbytes(me+0x2b3,fp())
 for off in [0x223,0x227,0x22b]:e.wbytes(me+off,struct.pack('<f',r.choice([0.,1.,2.,4.,-1.,math.nan])))
 return [me]
S(0x514f60,'GUESS vehicle actor front bounds and events','thiscall',None,ret='al',gen=gen,nan_heap=True)
