from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x1380);inp=rnd(c,0x60)
 device=obj(c,0x20,{0x94:pystub(c,3,deref={2:16})})
 tex=obj(c,0x20,{0xf4:pystub(c,3)})
 e.w32(0x724a00,tex);e.w32(me+0x1377,device);e.w32(me+0x115f,r.getrandbits(32))
 t=r.getrandbits(32);e.w32(inp+0x38,t);e.w32(0x724848,r.choice([t,r.getrandbits(32)]))
 for a in [0x60ff30,0x60feb0]:
  hook_rec(c,a,2)
  def h(em,res,a=a):
   em.calllog.append(('state',a,em.reg('ecx'),em.reg('edx'),em.arg32(0),em.arg32(1)));em.ret(eax=0,argbytes=8)
  e.hook(a,h)
 hook_rec(c,0x60d840,0,this=True,st0=r.uniform(-10,10));hook_rec(c,0x60d8e0,0,this=True,st0=r.uniform(-10,10))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,inp,r.choice([0,1,256,0xffffffff,r.getrandbits(32)])]
S(0x612030,'GUESS render texture and matrix setup','thiscall',None,ret=None,gen=gen)
