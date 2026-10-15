from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 vals=[r.getrandbits(32) for _ in range(4)]
 hook_rec(c,0x6352f0,1,this=True,nullflag=(0,),side=lambda em,k:em.w32(em.arg32(0),vals[0]))
 for a,ret,st in [(0x4e5e80,0,r.choice(EDGE_F+[r.uniform(-10,10)])),(0x4e5e40,r.getrandbits(32),None),(0x4e5e60,r.choice([0,1,0x100,0xffffffff]),None)]:
  hook_rec(c,a,0,this='mark',ret=ret,st0=st,side=lambda em,k:em.calllog.append(('value',em.r32(em.reg('ecx')))))
 def advance(em,k):
  em.calllog.append(('stream-prev',em.r32(em.arg32(0))));em.w32(em.arg32(0),vals[k%4])
 stream=obj(c,16,{0x40:pystub(c,1,this=True,nullflag=(0,),side=advance)})
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:vals[(k+1)%4])})
 e.w32(0x7003b0,pystub(c,0))
 return [rnd(c,0x80),stream]
S(0x5d3660,'deserialize entity references','thiscall',None,ret='al',gen=gen,nan_heap=True)
