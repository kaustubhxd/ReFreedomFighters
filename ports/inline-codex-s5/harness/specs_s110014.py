from pilot import S
from recruits_util import clear_hooks,rnd,pystub,hook_rec

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 item=rnd(c,0x200);save=rnd(c,0x40);sub=rnd(c,0x40)
 hook_rec(c,0x4705a0,1,this=True)
 def writer(name):
  slots={}
  for off in [0x3c,0x44,0x4c,0x60,0x68,0x6c]:
   def fn(em,_,off=off):
    a=em.arg32(0);v=tuple(em.r32(a+4*i) for i in range(3)) if off==0x68 else a
    em.calllog.append((name,off,em.reg('ecx'),v));em.ret(eax=sub,argbytes=4)
   slots[off]=fn
  return e.fake_vtable(name,0x20,slots)
 e.w32(save,writer('save'));e.w32(sub,writer('sub'))
 return [item,save]
S(0x4707c0,'ZItemWeapon Save','thiscall',None,ret='al',gen=gen)
