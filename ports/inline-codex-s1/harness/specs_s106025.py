import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,reftab,clear_hooks,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 targets=[obj(c,16,{0x230:pystub(c,1,this=True)}) for _ in range(4)]
 ids=[r.getrandbits(32) for _ in range(r.randrange(5))]
 mapping={i:r.choice([0]+targets) for i in ids}
 sys=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:mapping[em.arg32(0)])})
 content=bytes(r.getrandbits(8) for _ in range(60))
 def load(em,k):em.wbytes(em.arg32(1),content)
 manager=obj(c,16,{0x88:pystub(c,2,this=True,nullflag=(1,),side=load),0xa8:pystub(c,2,this=True,deref={1:15})})
 parent=rnd(c,32);e.w32(parent+0x18,manager);e.w32(sys+0x1aa3,parent)
 me=obj(c,0x40,{0x238:pystub(c,0,this=True),0x220:pystub(c,1,this=True)})
 e.w32(me+0x1c,r.choice([0,reftab(c,ids)]));e.w32(me+8,rnd(c,0x80))
 e.w32(0x7003b0,pystub(c,0))
 v=r.choice(EDGE_F+[r.uniform(-10,10)])
 return [me,struct.unpack('<I',struct.pack('<f',v))[0]]
S(0x449a00,'notify children and update manager state','thiscall',None,ret=None,gen=gen)
