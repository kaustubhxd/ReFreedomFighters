import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x350)
 for i,off in enumerate([0x2c3,0x2ec,0x315]):
  val=r.uniform(-50,50)
  def output(em,k,val=val):em.wbytes(em.arg32(0),struct.pack('<f',val))
  o=obj(c,0x24,{8:pystub(c,1,this=True,stackmark=(0,),side=output),0x20:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101,0xffffffff])),4:pystub(c,3,this=True)})
  e.w32(s+off,e.r32(o))
 e.wbytes(s+0x28e,struct.pack('<3f',*(r.uniform(-20,20) for _ in range(3))))
 values=[r.choice([0.0,1.0,-1.0,r.uniform(-5,5)]) for _ in range(3)]
 sysobj(c,slots={0x1c4:pystub(c,2,this=True,st0=lambda em,k:values[min(k,2)])})
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s]
S(0x51d8f0,'GUESS update three helicopter delta controllers','thiscall',None,ret=None,gen=gen)
