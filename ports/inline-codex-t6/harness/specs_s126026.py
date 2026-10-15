from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x830);count=r.randrange(8);e.w32(me+0x820,count-1 & 0xffffffff);e.w32(me,r.choice([0,1,r.getrandbits(32)]));key=r.getrandbits(32)
 for i in range(count):e.w32(me+4+4*i,r.choice([key,r.getrandbits(32)]))
 pos=struct.pack('<3f',*[r.uniform(-300,300) for _ in range(3)]);other=struct.pack('<3f',*[r.uniform(-300,300) for _ in range(3)])
 def putpos(em,k):em.wbytes(em.arg32(0),pos)
 pose=obj(c,0x20,{0x84:pystub(c,1,this=True,nullflag=(0,),side=putpos)});entity=rnd(c,0x60);e.w32(entity+0x44,pose)
 manager=obj(c,0x20,{0xcc:pystub(c,1,this=True,ret=entity)});e.w32(0x70038c,manager);ref=rnd(c,0x30);sysobj(c,table_slots={0x54:pystub(c,1,this=True,ret=ref)})
 def putother(em,k):em.wbytes(em.arg32(0),other)
 hook_rec(c,0x4db670,1,this=True,nullflag=(0,),side=putother);hook_rec(c,0x4a0e40,1,this=True,ret=r.choice([0,1,2,3,6,10,32,33]))
 hook_rec(c,0x4a15b0,1,this=True,ret=lambda em,k:(em.arg32(0)+1)&0xffffffff)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,key]
S(0x4a2380,'GUESS select target distance level','thiscall',None,ret=None,gen=gen)
