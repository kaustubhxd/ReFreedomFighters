import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,sysobj,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def writefloats(em,p,values):em.wbytes(p,struct.pack('<%df'%len(values),*values))
 matrix=[r.uniform(-10,10) for _ in range(9)];pos=[r.uniform(-10,10) for _ in range(3)]
 def transform(em,k):writefloats(em,em.arg32(0),matrix);writefloats(em,em.arg32(1),pos)
 src=obj(c,0x40,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=transform)})
 instance=obj(c,0x40,{0x2c:pystub(c,0,this=True),0x7c:pystub(c,2,this=True,deref={0:9})})
 factory=obj(c,0x40,{0x1bc:pystub(c,7,this=True,deref={1:9},ret=r.choice([0,instance,instance]))})
 rv=[r.uniform(-1,2) for _ in range(3)]
 sys=sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=lambda em,k:rv[k%3])},table_slots={0x58:pystub(c,1,this=True,ret=factory)},table_size=0xb00)
 s=rnd(c,0x90);entries=rnd(c,25*5);idx=r.randrange(5)
 e.w32(s+0x44,src);e.w32(s+0x4c,entries)
 e.w32(entries+25*idx+4,r.choice([0,instance]))
 for i in range(6):writefloats(e,s+0x64+4*i,[r.uniform(-100,100)])
 def add(em,k):
  p=em.reg('ecx');q=em.reg('edx');em.calllog.append(('vector',q))
  a=struct.unpack('<3f',em.rbytes(p,12));b=struct.unpack('<3f',em.rbytes(q,12))
  writefloats(em,p,[x+y for x,y in zip(a,b)])
 hook_rec(c,0x441940,0,this=True,side=add)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,rnd(c,12),idx,r.getrandbits(32)]
S(0x5c4cc0,'GUESS spawnEntry','thiscall',None,ret=None,gen=gen)
