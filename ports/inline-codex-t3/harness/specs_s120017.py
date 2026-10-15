from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,hook_rec

def init(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=obj(c,0x90,{0x68:pystub(c,2,this=True)});sys=rnd(c,0x50);e.w32(0x70039c,sys)
 e.w32(self+0x44,obj(c,0x20,{0x3c:pystub(c,1,this=True)}))
 hook_rec(c,0x4a7fb0,1,this=True)
 for off in range(0x5a,0x72,4):e.wf32(self+off,r.choice([0.0,-0.0,0.0,1.0,-1.0,float('nan'),float('inf'),r.uniform(-50,50)]))
 if r.random()<0.25:
  for off in range(0x5a,0x72,4):e.wf32(self+off,0.0)
 e.w8(self+0x7a,r.choice([0,1,255]));e.w16(self+0x50,r.choice([0,1,r.getrandbits(16)]))
 return [self,rnd(c,16),rnd(c,16)]
S(0x4a7e20,'GUESS_initialize_motion_flags','thiscall',None,ret=None,gen=init,nan_heap=True)
