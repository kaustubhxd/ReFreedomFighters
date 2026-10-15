from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def start(c):clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
def fv(r,n,scale=100):return struct.pack('<%df'%n,*[r.uniform(-scale,scale) for _ in range(n)])
def focal(c):
 start(c);r=c.rng;e=c.emu;payload=fv(r,9);position=fv(r,3)
 def fill(em,k):em.wbytes(em.arg32(0),payload);em.wbytes(em.arg32(1),position)
 s=obj(c,0xc00,{0x438:pystub(c,0,this=True,ret=r.choice([0,0,1,0x100,0x101])),0x4d0:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101])),0x3a8:pystub(c,2,this=True,stackmark=(0,),ret=lambda em,k:em.arg32(0),side=fill),0x390:pystub(c,1,this=True,deref={0:9})})
 e.w32(s+0x417,r.choice([0,0x400,0x401,0x402,0x8000000,0x8000400,0x8000401]))
 sub=rnd(c,0xb80);e.w8(sub+0xb45,r.randrange(2));e.w32(s+0x85a,sub)
 e.wbytes(s+0x81f,struct.pack('<f',r.choice([0.,120.,130.,155.,165.,180.,210.,300.,r.uniform(-100,400)])))
 sys=sysobj(c);e.wbytes(sys+0x48,struct.pack('<f',r.choice([0.,0.001,0.016,1.,10.,-0.016])))
 return [s,rnd(c,12)]
S(0x591bb0,'GUESS_camera_focal_point','thiscall',None,ret=None,gen=focal)

def pickup(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x30);mat=bytes(r.getrandbits(8) for _ in range(48));position=fv(r,3)
 def fill(em,k):em.wbytes(em.arg32(0),mat);em.wbytes(em.arg32(1),position)
 item=obj(c,0x20,{0x2e0:pystub(c,2,this=True,stackmark=(0,1),side=fill),0x98:pystub(c,2,this=True,deref={0:12,1:3})})
 pvals=struct.unpack('<3f',position);height=r.choice([-100.,-60.,-59.,0.,20.,21.,50.,51.,80.,81.,100.,r.uniform(-150,150)])
 actorpos=struct.pack('<3f',pvals[0],pvals[1]+height,pvals[2])
 def actorfill(em,k):em.wbytes(em.arg32(0),actorpos)
 actor=obj(c,0x20,{0x94:pystub(c,2,this=True,deref={0:12,1:3}),0x3a8:pystub(c,1,this=True,stackmark=(0,),side=actorfill,ret=lambda em,k:em.arg32(0)),0x398:pystub(c,1,this=True,deref={0:3}),0x228:pystub(c,5,this=True)})
 helper=obj(c,0x20,{0x1c:pystub(c,8,this=True,deref={1:12,2:3})})
 e.w32(s+8,item);e.w32(s+0xc,actor);e.w32(s+0x10,helper)
 return [s]
S(0x4865a0,'GUESS_execute_pickup','thiscall',None,ret='al',gen=pickup)

def frames(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x400);count=r.randrange(10);e.w32(s+0x28d,rnd(c,0x20))
 words=[r.getrandbits(32) for _ in range(22)];vecs=[bytes(r.getrandbits(8) for _ in range(12)) for _ in range(10)];mats=[bytes(r.getrandbits(8) for _ in range(36)) for _ in range(10)]
 def readword(em,k):em.w32(em.arg32(0),count if k==1 else words[k%len(words)])
 reader=obj(c,0x20,{0x68:pystub(c,1,this=True,stackmark=(0,),side=lambda em,k:em.w32(em.arg32(0),words[k%22])),0x40:pystub(c,1,this=True,stackmark=(0,),side=readword),0x6c:pystub(c,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),vecs[k%10])),0x74:pystub(c,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),mats[k%10])),0x48:pystub(c,1,this=True,stackmark=(0,),side=lambda em,k:em.w32(em.arg32(0),words[-1]))})
 hook_rec(c,0x644df0,1,this=True,ret=r.getrandbits(32))
 return [s,reader]
S(0x6471a0,'GUESS_read_frame_records','thiscall',None,ret='al',gen=frames)

def dust(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x2200)
 for off in (0x68,0x78,0x7c):e.wbytes(s+off,struct.pack('<f',r.choice([0.,-0.,0.01,-0.01,1.,-1.,10.,-10.,100.,r.uniform(-100,100)])))
 e.w32(s+0x8d,r.choice([-1,0,1,2,3])&0xffffffff);e.w32(s+0x91,r.choice([-1,0,1,2,3])&0xffffffff)
 sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=r.choice([0.,0.01,0.5,1.]))})
 hook_rec(c,0x516250,0,this=True,ret=r.choice([0,r.getrandbits(32)]));hook_rec(c,0x52a070,1,this=True);hook_rec(c,0x516f40,1,this=True,deref={0:3})
 return [s]
S(0x5292c0,'GUESS_update_wheel_dust','thiscall',None,ret=None,gen=dust)

def save(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x40)
 vals=[r.getrandbits(32) for _ in range(6)]
 for off,v in zip([0x10,0x14,0x1c,0x18,0x20,0x24],vals):e.w32(s+off,v)
 e.w32(s+0x28,r.choice([0]+vals+[r.getrandbits(32)]))
 writer=obj(c,0x20,{off:pystub(c,1,this=True,ret=r.getrandbits(32)) for off in [0x4c,0x60,0x3c]})
 return [s,writer]
S(0x486f30,'GUESS_save_chamber_item','thiscall',None,ret=None,gen=save)
