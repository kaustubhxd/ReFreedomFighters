from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 for a,n in [(0x515620,0),(0x527ee0,4),(0x520f20,1)]:hook_rec(c,a,n,this=True)
 y=obj(c,0x60,{8:pystub(c,0,this=True),0x4c:pystub(c,0,this=True),0x54:pystub(c,1,this=True)})
 e.w32(y+4,r.getrandbits(32)&~1)
 x=obj(c,0x40,{0x10c:pystub(c,2,this=True,ret=y)})
 turret=obj(c,0x40,{0x25c:pystub(c,2,this=True,ret=x)})
 flags=rnd(c,0x40);e.w32(flags+0x23,r.choice([0,0x100000,0x20000]));e.w32(turret+0xc,flags)
 wc=obj(c,0x20,{0x330:pystub(c,0,this=True,ret=r.choice([11,3]))})
 w=obj(c,0x40,{0x350:pystub(c,0,this=True,ret=wc)})
 t=obj(c,0x2800,{0x328:pystub(c,3,this=True,ret=r.choice([0,w,w]))})
 e.w32(t+0x25d1,turret)
 for off in [0x25d5,0x25d9]:e.w32(t+off,r.choice([0,r.getrandbits(32)]))
 e.w32(t+0x25e1,r.choice([0,w]));e.w32(t+0x25dd,0);e.w8(t+0x260a,0);e.wf32(t+0x25cd,r.uniform(-3,3))
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 return [t]
S(0x520670,'ZTank ClassInit2','thiscall',None,ret=None,gen=gen,note='normal valid turret/child flags; invalid branches in original dereference null')
