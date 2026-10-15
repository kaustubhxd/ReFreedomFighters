import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub,sysobj

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0x200);e.w8(p+0x88,r.choice([0,1,1,1]));e.w8(p+0x1f1,r.choice([0,1,1,1]))
 pos=[fb(r.uniform(-100,100)) for _ in range(3)];trans=[fb(r.uniform(-5,5)) for _ in range(3)];screen=[fb(r.uniform(-1,1)) for _ in range(2)]
 def writer(vals,arg):
  def side(e,k):
   for j,x in enumerate(vals):e.w32(e.arg32(arg)+4*j,x)
  return side
 source=obj(c,16,{0x84:pystub(c,1,this=True,stackmark=(0,),side=writer(pos,0))});e.w32(p+0x1ec,source)
 camera=obj(c,16,{0x8c:pystub(c,1,this=True,deref={0:3},side=writer(trans,0))})
 hook_rec(c,0x446320,2,this=True,stackmark=(0,),deref={1:3},side=writer(screen,0))
 settings=obj(c,16,{0xdc:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101]))})
 so=sysobj(c,slots={0xbc:pystub(c,0,this=True,ret=settings)},table_slots={0x58:pystub(c,1,this=True,ret=camera)})
 e.w32(so+0x6f,r.choice([640,800,1920,0,0x7fffffff]));e.w32(so+0x73,r.choice([480,600,1080,0,0x80000000]))
 after=[fb(r.uniform(-10,10)) for _ in range(3)]
 first=obj(c,16,{0x70:pystub(c,1,this=True,deref={0:3},side=writer(after,0))})
 e.w32(p+0x180,obj(c,16,{0x20:pystub(c,0,this=True,ret=first)}));e.w32(p+0x188,obj(c,16,{0x70:pystub(c,1,this=True,deref={0:3})}))
 return [p,r.getrandbits(32),r.choice([1,1,1,0,2])]
S(0x573930,'GUESS deferred map panel layout','thiscall',None,ret=None,gen=gen)
