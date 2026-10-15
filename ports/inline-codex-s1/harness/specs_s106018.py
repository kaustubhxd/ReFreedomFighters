from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 actor=obj(c,16,{0xdc:pystub(c,0,this=True,ret=r.getrandbits(32)),0xd8:pystub(c,1,this=True,ret=r.getrandbits(32)),0x134:pystub(c,3,this=True),0x138:pystub(c,2,this=True),0x50:pystub(c,0,this=True)})
 logger=obj(c,16,{0xc:pystub(c,3,this=True)})
 sys=sysobj(c,slots={0x1cc:pystub(c,1,this=True)})
 e.w32(sys+0x190f,actor);e.w32(sys+0x1907,r.choice([0,logger]));e.w32(sys+0x40,r.getrandbits(32))
 hook_rec(c,0x5d7b10,0)
 e.w32(0x7003b0,pystub(c,0))
 return [rnd(c,0x200)]
S(0x5d78e0,'initialize level actor state','thiscall',None,ret=None,gen=gen)
