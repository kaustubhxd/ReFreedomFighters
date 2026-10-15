from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x1b0);transform=rnd(c,0x40)
 e.wbytes(transform+0x24,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]))
 child=obj(c,0x20,{0x258:pystub(c,2,this=True,deref={0:2}),0x70:pystub(c,1,this=True,deref={0:3})})
 root=obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=child)});e.w32(root+8,transform);e.w32(me+0x54,root)
 value=r.randrange(256)
 def flag(em,k):em.wbytes(em.arg32(1),bytes([value]))
 cfg=obj(c,0x20,{0x90:pystub(c,2,this=True,nullflag=(1,),side=flag)})
 so=sysobj(c,table_slots={0x134:pystub(c,0,this=True,ret=cfg)})
 for off in [0x6f,0x73]:e.w32(so+off,r.choice([0,1,15,16,640,1080,0xffffffff,r.getrandbits(32)]))
 state=rnd(c,0x1050);e.wbytes(state+0x103f,bytes([r.randrange(2)]));e.w32(me+0x94,r.choice([0,state,state]))
 hook_rec(c,0x562440,0,this=True);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x57a8e0,'GUESS layout grid and configuration flag','thiscall',None,ret=None,gen=gen)
