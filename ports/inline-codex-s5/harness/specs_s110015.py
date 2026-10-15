from pilot import S
from recruits_util import clear_hooks,rnd,pystub,hook_rec

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 t=rnd(c,0x200)
 for off in [0xbb,0xc0,0xc7]:e.wf32(t+off,r.uniform(-1e4,1e4))
 slots={}
 for off in [0x40,0x44,0x4c,0x54,0x60,0x68,0x70]:
  def fn(em,_,off=off):
   a=em.arg32(0);v=tuple(em.r32(a+4*i) for i in range(3)) if off in [0x68,0x70] else a
   em.calllog.append(('field',off,em.reg('ecx'),v));em.ret(eax=0,argbytes=4)
  slots[off]=fn
 b=rnd(c,0x40);e.w32(b,e.fake_vtable('fields',0x20,slots))
 hook_rec(c,0x4e7be0,1,this=True)
 return [t,b]
S(0x4a5dd0,'GUESS apply serialized fields','thiscall',None,ret='al',gen=gen)
