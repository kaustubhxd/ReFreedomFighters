import struct
from pilot import S
from recruits_util import rnd,obj,pystub,sysobj,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=rnd(c,0x20);body=rnd(c,0x90);e.w32(s+8,body);e.w32(body+0x6c,r.choice([0,1,r.getrandbits(32)]))
 info=[r.uniform(-10,10) for _ in range(14)];info[7]=r.uniform(-1000,1000);info[9]=r.choice([0.,1.,-1.,r.uniform(-3,3)])
 def fill(em,k):em.wbytes(em.arg32(1),struct.pack('<14f',*info))
 table=obj(c,0x20,{0x84:pystub(c,2,this=True,stackmark=(1,),side=fill)})
 tree=rnd(c,0x20);e.w32(tree+0x18,table);sys=sysobj(c);e.w32(sys+0x1aa3,tree)
 hook_rec(c,0x4dce50,1,this=True)
 hook_rec(c,0x4dd060,1,this=True,deref={0:3})
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s]
S(0x448430,'GUESS updateBounds','thiscall',None,ret=None,gen=gen)
