import struct
from pilot import S
from recruits_util import rnd,obj,pystub,sysobj,reftab_vt,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 values=[r.uniform(-100,100) for _ in range(3)]
 def wf(em,a,vs):em.wbytes(a,struct.pack('<%df'%len(vs),*vs))
 source=obj(c,0xb0,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2))})
 wf(e,source+0x9f,[r.choice([r.uniform(-1e5,1e5),float('nan'),float('inf')])])
 s=obj(c,0x110,{0x68:pystub(c,2,this=True)})
 e.w32(s+0x44,source);e.w8(s+0xf8,r.randrange(2));e.w8(s+0xf9,r.randrange(2));e.w32(s+0xf4,r.choice([0,1,0xffffffff,0x7fffffff,r.getrandbits(32)]))
 ids=list(range(r.randrange(7)));actors={};dims={}
 for idx in ids:
  if not r.randrange(4):actors[idx]=0;continue
  shape=rnd(c,0x60);dims[shape]=[r.uniform(-20,20),r.uniform(-20,20)]
  wf(e,shape+0x40,[r.uniform(-20,20),r.uniform(-20,20)])
  def change(em,k):
   shape=em.r32(em.reg('ecx')+8);wf(em,shape+0x40,dims[shape])
  actor=obj(c,0x20,{0x70:pystub(c,1,this=True,deref={0:3},side=change)})
  e.w32(actor+8,shape);actors[idx]=actor
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:actors[em.arg32(0)])})
 e.w32(s+0x48,reftab_vt(c,ids))
 hook_rec(c,0x4db500,1,this=True,stackmark=(0,),side=lambda em,k:wf(em,em.arg32(0),values))
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s]
S(0x4f68b0,'GUESS arrangeReferences','thiscall',None,ret=None,gen=gen)
