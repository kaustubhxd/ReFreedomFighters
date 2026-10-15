from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def start(c):clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
def pack(c):
 start(c);r=c.rng;e=c.emu;data=rnd(c,0x40)
 out=obj(c,0x20,{0x4c:pystub(c,0,this=True,ret=data)})
 factory=obj(c,0x20,{0x18:pystub(c,1,this=True,ret=r.choice([0,out,out]))})
 nodes=[rnd(c,0x10) for _ in range(7)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:nodes[em.arg32(0)%7])
 hook_rec(c,0x500360,1,this=True);hook_rec(c,0x5002f0,1,this=True)
 return [factory,r.getrandbits(32),rnd(c,28)]
S(0x551340,'GUESS_pack_seven_fields','stdcall',None,ret='eax',gen=pack)

def trace(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x20);data=rnd(c,0x80);e.w32(s+8,data)
 query=rnd(c,0x80);payload=bytes(r.getrandbits(8) for _ in range(72))
 def fill(em,k):em.wbytes(em.arg32(0),payload)
 mgr=obj(c,0x20,{0x30:pystub(c,8,this=True,deref={0:18},side=fill,ret=r.choice([0,1,0x100,0x101,0xffffffff]))})
 sys=sysobj(c,table_slots={0x50:pystub(c,1,this=True,ret=r.getrandbits(32))});root=rnd(c,0x30);e.w32(root+0x1c,mgr);e.w32(sys+0x1aa3,root)
 return [s,query]+[r.getrandbits(32) for _ in range(5)]
S(0x4429d0,'GUESS_trace_geometry','thiscall',None,ret='al',gen=trace)
