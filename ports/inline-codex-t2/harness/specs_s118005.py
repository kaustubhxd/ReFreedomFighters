from pilot import S,F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger
import struct

def start(c):clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
def fv(r,n,scale=100):return struct.pack('<%df'%n,*[r.uniform(-scale,scale) for _ in range(n)])
def facing(c):
 start(c);e=c.emu;r=c.rng;s=obj(c,0x300,{0x408:pystub(c,0,this=True)})
 e.w8(s+0x158,r.choice([0,0,0,1]));sys=sysobj(c)
 e.w32(sys+0x40,r.choice([0,1,1024,0xffffffff,0x80000000,r.getrandbits(32)]))
 dur=r.choice([0.,-0.,1.,-1.,10.,-10.,float("nan"),float("inf"),-float("inf"),r.uniform(-100,100)])
 time=r.choice([0.,-0.,1.,-1.,100.,-100.,float("nan"),float("inf"),-float("inf"),r.uniform(-100,100)])
 def init(em,k):
  em.wbytes(s+0x16d+0x31,struct.pack('<f',dur));em.wbytes(s+0x16d+0x35,struct.pack('<f',time))
 hook_rec(c,0x4658d0,1,this=True,side=init)
 return [s]+[r.getrandbits(32) for _ in range(5)]
S(0x4675e0,'GUESS_reset_facing','thiscall',None,ret=None,gen=facing)

def sound(c):
 start(c);r=c.rng;e=c.emu;logger(c,nargs=2)
 s=obj(c,0x5100,{0x104:pystub(c,2,this=True),0x1f8:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101]))})
 cfg=obj(c,0x20,{x:pystub(c,1,this=True,ret=r.getrandbits(32)) for x in [0x7c,0x84,0x8c]})
 vt=e.r32(cfg);e.w32(vt+0x5c,pystub(c,2,this=True,ret=r.choice([0,1,0x7fffffff,0x80000000,0xffffffff,r.getrandbits(32)])))
 sysobj(c,slots={0xbc:pystub(c,0,this=True,ret=r.choice([0,cfg,cfg]))},table_slots={0x114:pystub(c,4,this=True,ret=r.getrandbits(32))})
 return [s]
S(0x5378a0,'GUESS_initialize_sound','thiscall',None,ret=None,gen=sound)

def shadow(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0xd00);p=rnd(c,12);direction=rnd(c,12)
 e.wbytes(p,fv(r,3));e.wbytes(direction,fv(r,3,2) if r.randrange(4) else bytes(12))
 hit=fv(r,3)
 def collision(em,k):em.wbytes(s+0xb83,hit)
 collider=obj(c,0x20,{0x2e0:pystub(c,6,this=True,deref={0:3},ret=r.choice([0,1,0x100,0x101]),side=collision)})
 sys=sysobj(c,table_size=0xb00);e.w32(e.r32(sys+0x9b)+0xadc,collider)
 return [s,p,direction,F(r.choice([0.,-0.,1.,-1.,r.uniform(-100,100)])),r.getrandbits(32)]
S(0x5cefc0,'GUESS_shadow_position','thiscall',None,ret=None,gen=shadow)

def frame(c):
 start(c);r=c.rng;e=c.emu
 s=obj(c,0x400,{0x98:pystub(c,1,this=True),0x94:pystub(c,1,this=True)})
 hook_rec(c,0x562260,0,this=True);hook_rec(c,0x4f7950,0,this=True)
 e.w32(s+0xdc,r.choice([0,1,2,3]));e.w32(s+0x33c,r.choice([0,1]));e.wbytes(s+0x34b,fv(r,3))
 sub=rnd(c,0x20);e.w32(sub+8,rnd(c,0x20));e.w32(s+0x54,sub)
 payload=fv(r,3)
 hook_rec(c,0x4db500,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),payload))
 for off in (0x310,0x314):e.w32(s+off,obj(c,0x20,{0x70:pystub(c,1,this=True,deref={0:3})}))
 returns=[r.choice([0,1,0x100,0x101]) for _ in range(2)]
 manager=obj(c,0x20,{0x2c:pystub(c,2,this=True,ret=lambda em,k:returns[k%2])})
 sys=sysobj(c);e.w32(sys+0x1907,manager)
 return [s]
S(0x57d340,'GUESS_update_frame_vectors','thiscall',None,ret=None,gen=frame)

def axis(c):
 start(c);r=c.rng;out=rnd(c,48)
 vals=[r.choice([0.,-0.,1.,-1.,r.uniform(-10,10)]) for _ in range(4)]
 return [out]+[F(v) for v in vals]
S(0x4deb20,'GUESS_axis_angle_matrix','thiscall',None,ret=None,gen=axis)
