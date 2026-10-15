from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 slots={}
 for off in [0x4c,0x3c,0x64]:
  def write(em,_,off=off):em.calllog.append(('save',off,em.reg('ecx'),em.arg32(0)));em.ret(argbytes=4)
  slots[off]=e.stub_fn('save',write)
 return [rnd(c,0x90),obj(c,0x20,slots)]
S(0x5c9180,'CMachinegunControlGroup Save','thiscall',None,ret='al',gen=gen)
