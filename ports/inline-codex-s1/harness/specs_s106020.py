import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=obj(c,0x600,{0x380:pystub(c,0,this=True)})
 for off in [0x22e,0x232,0x236,0x23a,0x342,0x346]:e.wf32(me+off,r.choice(EDGE_F+[r.uniform(-100,100)]))
 for off in (0x39f,0x3c8):
  vals=[r.uniform(-100,100) for _ in range(2)]
  def fill(em,k,vals=vals):em.wbytes(em.arg32(0),struct.pack('<ff',*vals))
  ch=obj(c,16,{8:pystub(c,1,this=True,side=fill),0x20:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101])),4:pystub(c,3,this=True)})
  e.w32(me+off,e.r32(ch))
 vals=[r.choice([0.,1.,-1.,r.uniform(-10,10)]) for _ in range(2)]
 sysobj(c,slots={0x1c4:pystub(c,2,this=True,st0=lambda em,k:vals[k%2])})
 e.w32(0x7003b0,pystub(c,0))
 return [me]
S(0x51e340,'update embedded motion channels','thiscall',None,ret=None,gen=gen,nan_heap=True)
