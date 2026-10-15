from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def start(c):
 clear_hooks(c);hook_rec(c,0x7003b0,0,ret=c.rng.getrandbits(32),pop=0)

def recycle(c):
 start(c);e=c.emu;r=c.rng
 sys=sysobj(c); tick=r.choice([-2147483648,-1024,0,1,1024,2147483647,r.randint(-100000,100000)])
 e.w32(sys+0x40,tick&0xffffffff)
 now=struct.unpack('<f',struct.pack('<f',float(tick)))[0]/1024
 n=r.randrange(7);s=rnd(c,0x90);e.w32(s+0x48,n)
 weapons=[obj(c,0x30,{0x2e8:pystub(c,0,this=True),0x210:pystub(c,1,this=True)}) for _ in range(n)]
 for i,w in enumerate(weapons):
  e.w32(s+0x4c+8*i,r.choice([0,w,w]));e.wbytes(s+0x50+8*i,struct.pack('<f',r.choice([now,now-1,now+1,0.,float('nan'),float('inf'),-float('inf')])))
 mgr=rnd(c,0x900);e.w32(0x7003b8,mgr)
 pool=[r.choice(weapons+[0]) for _ in range(r.randrange(8))]
 e.w32(mgr+0x8b4,len(pool))
 for i,w in enumerate(pool):e.w32(mgr+0x8b8+4*i,w)
 hook_rec(c,0x5e93f0,2,this=True)
 return [s]
S(0x5e9150,'GUESS_recycle_expired','thiscall',None,ret=None,gen=recycle)

def age(c):
 start(c);r=c.rng;e=c.emu;n=r.randrange(9);s=rnd(c,4+16*10);e.w32(s,n)
 for i in range(n):
  e.w16(s+4+16*i+12,r.choice([0,1,127,128,255,32767,32768,65535,r.getrandbits(16)]))
  e.w8(s+4+16*i+14,r.choice([0,1,2,127,128,255,r.getrandbits(8)]))
 return [s]
S(0x5a01e0,'GUESS_age_compact_entries','thiscall',None,ret=None,gen=age)

def anchors(c):
 start(c);e=c.emu;r=c.rng;s=rnd(c,0x2000)
 e.w32(s+0x8c,r.choice([-2,-1,0,1,2,3,4])&0xffffffff);e.w32(s+0x90,r.choice([-2,-1,0,1,2,3,4])&0xffffffff)
 mask=[r.getrandbits(32) for _ in range(3)]
 def transform(em,k):
  p=em.arg32(0)
  for i in range(3):em.w32(p+4*i,em.r32(p+4*i)^mask[i])
 e.w32(s+0x88,obj(c,0x20,{0x84:pystub(c,1,this=True,deref={0:3},side=transform)}))
 hook_rec(c,0x516620,1,this=True,deref={0:3},side=lambda em,k:(em.w32(em.reg('ecx'),em.r32(em.arg32(0))),em.w32(em.reg('ecx')+8,em.r32(em.arg32(0)+8))))
 return [s]
S(0x526360,'GUESS_update_damper_anchors','thiscall',None,ret=None,gen=anchors)

def place(c):
 start(c);e=c.emu;r=c.rng
 matrix=struct.pack('<9f',*[r.uniform(-2,2) for _ in range(9)])
 pos=struct.pack('<3f',*[r.uniform(-1000,1000) for _ in range(3)])
 def fill(em,k):em.wbytes(em.arg32(0),matrix);em.wbytes(em.arg32(1),pos)
 gun=obj(c,0x20,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=fill)})
 iface=obj(c,0x20,{0x370:pystub(c,2,this=True,deref={0:9,1:3})})
 user=obj(c,0x20,{0x2f4:pystub(c,0,this=True,ret=r.choice([0,iface]))})
 gunid=r.getrandbits(32);userid=gunid^0x80000000
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:gun if em.arg32(0)==gunid else user)})
 s=rnd(c,0x90);e.w32(s+0x74,gunid);e.w32(s+0x70,userid)
 return [s]
S(0x5c8650,'GUESS_place_gunner','thiscall',None,ret=None,gen=place)
