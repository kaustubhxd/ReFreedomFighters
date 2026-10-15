from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub,obj

def fill(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 cells=[rnd(c,8) for _ in range(8)];params=rnd(c,0x20)
 entry=obj(c,0x20,{0x4c:pystub(c,0,this=True,ret=params)})
 mgr=obj(c,0x20,{0x18:pystub(c,1,this=True,ret=r.choice([0,entry,entry,entry]))})
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:cells[em.arg32(0)])
 def store(em,k):em.w32(em.reg('ecx'),em.arg32(0))
 for a in (0x5002f0,0x500360):hook_rec(c,a,1,this=True,side=store)
 return [mgr,r.getrandbits(32),rnd(c,32)]
S(0x551c60,'GUESS_fill_eight_script_parameters','stdcall',None,ret='eax',gen=fill)
