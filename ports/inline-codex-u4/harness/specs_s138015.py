from pilot import S
from recruits_util import rnd,obj,pystub,sysobj,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=rnd(c,0x890);payload=rnd(c,0x20)
 actor=obj(c,0x20,{0xbc:pystub(c,1,this=True)})
 e.w32(s+0x44,r.choice([0,actor]));e.w32(s+0x872,r.choice([0,actor]))
 keys=r.sample(range(65536),5)
 for i in range(4):e.w16(s+0x48+2*i,keys[i])
 which=r.randrange(5);key=keys[which]|(r.getrandbits(16)<<16)
 if which==0 and r.randrange(3)==0:payload=0
 if payload:
  e.w32(payload+8,r.choice([0,actor]));e.w32(payload+0xc,r.choice([0,r.getrandbits(32)]))
 strings=obj(c,0x20,{0:pystub(c,2,this=True,ret=r.getrandbits(32))})
 sys=sysobj(c,table_size=0xb00);table=e.r32(sys+0x9b);e.w32(table+0xae4,strings)
 hook_rec(c,0x572850,2,this=True)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,key,payload]
S(0x5725b0,'GUESS dispatchTransition','thiscall',None,ret='eax',gen=gen)
