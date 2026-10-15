import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,pystub,clear_hooks,hook_rec,reftab

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def fp(n):return struct.pack('<'+'f'*n,*[r.uniform(-5,5) for _ in range(n)])
 ob=obj(c,16,{0x84:pystub(c,1,this=True,deref={0:3}),0x128:pystub(c,1,this=True)})
 e.w32(ob+8,rnd(c,16));owner=obj(c,16,{0x8c:pystub(c,1,this=True,deref={0:3}),0x180:pystub(c,2,this=True,deref={0:3},ret=lambda em,k:hits[k])})
 hits=[r.choice([0,1,2,255]) for i in range(6)]
 sys=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=ob),0x114:pystub(c,6,this=True,ret=r.getrandbits(32))})
 e.wbytes(sys+0x48,struct.pack('<f',r.uniform(0,2)))
 me=rnd(c,0xb0);e.w32(me+0x44,owner)
 table=reftab(c,[r.getrandbits(32) for i in range(r.randrange(6))]);e.w32(me+0x48,r.choice([0,table,table,table]));e.wbytes(me+0x54,bytes([r.choice([0,1,1,2])]))
 for off in [0x50,0x87,0x8b,0x8f,0x97,0x9b]:e.wbytes(me+off,struct.pack('<f',r.uniform(-1,3)))
 v=fp(3);hook_rec(c,0x4daf90,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),v))
 return [me]
S(0x5dba60,'GUESS damage box frame timers and effect','thiscall',None,ret=None,gen=gen)
