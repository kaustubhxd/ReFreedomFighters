from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x4dc630,2,this=True)
 o=obj(c,32,{0x74:pystub(c,2,this=True),0x154:pystub(c,0,this=True),0x158:pystub(c,0,this=True),0x124:pystub(c,4,this=True)})
 inner=rnd(c,0x50);e.w32(inner+0x3c,r.choice([0,0x800000]));e.w32(o+8,inner)
 alive=[r.randrange(2) for _ in range(2)];alive2=[r.randrange(2) for _ in range(2)]
 sysobj(c,table_slots={0x10:pystub(c,0,this=True,ret=r.randrange(2)),0x4c:pystub(c,1,this=True,ret=r.getrandbits(32)),0x58:pystub(c,1,this=True,ret=lambda em,k:alive[min(k,1)]),0x54:pystub(c,1,this=True,ret=lambda em,k:alive2[min(k,1)])})
 me=obj(c,32,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2)),0x1b8:pystub(c,5,this=True,ret=o)})
 return [me]+[r.choice([0,r.getrandbits(32)]) for _ in range(7)]
S(0x45dde0,'GUESS spawn_and_validate','thiscall',None,ret='eax',gen=gen)
