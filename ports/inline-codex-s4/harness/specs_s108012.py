from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def reader(c,slots):
 e=c.emu;r=c.rng
 out={}
 for slot,n in slots.items():
  values=[bytes(r.getrandbits(8) for _ in range(n)) for _ in range(16)]
  def write(em,k,values=values):em.wbytes(em.arg32(0),values[k%16])
  out[slot]=pystub(c,1,this=True,side=write)
 return obj(c,0x20,out)

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def g43f0(c):
 base(c)
 return [rnd(c,0x200),reader(c,{0x44:2,0x50:4,0x68:1,0x70:36})]

def g5be0(c):
 base(c)
 me=obj(c,0xa0,{0x98:pystub(c,1,this=True)})
 return [me,reader(c,{0x48:4,0x58:8,0x50:4,0x40:4})]
S(0x4a43f0,'GUESS load packed flags scalars bytes and two matrices','thiscall',None,ret='al',gen=g43f0)
S(0x4b5be0,'GUESS load cut-sequence sound fields after assert and reset','thiscall',None,ret='al',gen=g5be0)
