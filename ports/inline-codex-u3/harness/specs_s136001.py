import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 coords=[r.choice([0.0,r.uniform(-30,30)]) for _ in range(3)]
 def position(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*coords))
 target=obj(c,0x30,{0x84:pystub(c,1,this=True,stackmark=(0,),side=position)})
 out=rnd(c,0x100)
 def localize(em,k):
  p=em.arg32(0);v=struct.unpack('<3f',em.rbytes(p,12));em.wbytes(p,struct.pack('<3f',*(x+delta[i] for i,x in enumerate(v))))
 delta=[r.uniform(-5,5) for _ in range(3)]
 local=obj(c,0x30,{0x8c:pystub(c,1,this=True,deref={0:3},side=localize)})
 e.w32(local+0x18,out)
 manager=obj(c,0x30,{0xec:pystub(c,0,this=True,ret=r.choice([0,1,3,3])),0xc0:pystub(c,0,this=True,ret=r.choice([target,target,0]))})
 key=r.getrandbits(32)
 def query(em,k):em.w32(em.arg32(1),key)
 q=obj(c,0x30,{0x88:pystub(c,2,this=True,stackmark=(1,),side=query)})
 so=sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=q),0x58:pystub(c,1,this=True,ret=r.choice([target,target,0]))})
 e.w32(so+0x1a9f,r.choice([manager,manager,manager,0]))
 s=rnd(c,0x60);e.w32(s+0x44,local)
 e.wbytes(s+0x48,struct.pack('<3f',*(r.choice([0.0,1.0,-1.0,r.uniform(-50,50)]) for _ in range(3))))
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s]
S(0x4bce60,'GUESS update spatial attenuation','thiscall',None,ret=None,gen=gen)
