import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 vec=[r.uniform(-10,10) for _ in range(3)]
 def fill(em,k):
  em.calllog.append(('vector-before',em.rbytes(em.arg32(0),12).hex()));em.wbytes(em.arg32(0),struct.pack('<fff',*vec))
 target=obj(c,16,{0x84:pystub(c,1,this=True,nullflag=(0,),side=fill)})
 converter=obj(c,16,{0x218:pystub(c,2,this=True,deref={0:3},ret=r.getrandbits(32))})
 config=obj(c,16,{0x58:pystub(c,3,this=True)})
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,target,target])),0x138:pystub(c,0,this=True,ret=config)})
 me=rnd(c,0x60);e.w32(me+0x44,converter)
 hook_rec(c,0x633654,0);e.w32(0x7003b0,pystub(c,0))
 return [me]
S(0x4c91c0,'update configuration color channels','thiscall',None,ret=None,gen=gen)
