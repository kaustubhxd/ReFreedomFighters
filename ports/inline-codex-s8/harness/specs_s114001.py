from pilot import S
from recruits_util import clear_hooks,rnd,obj,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 a=rnd(c,0x30);e.w8(a+12,r.choice([0,1,2,255]))
 e.w32(0x701a78,r.choice([0,1,37,39,40,41,48,49,50,51,99]))
 e.wbytes(0x701a80,bytes(r.getrandbits(8) for _ in range(200)))
 def error(em,_):
  em.calllog.append(('error',em.reg('ecx'),em.arg32(0)))
  if r.random()<0.2:em.w8(a+12,0)
  em.ret(eax=r.getrandbits(32),argbytes=4)
 s=obj(c,0x20,{0x44:e.stub_fn('error',error)})
 def assertion(em,_):
  em.calllog.append(('assert',))
  if r.random()<0.2:em.w32(0x701a78,r.randrange(50))
  em.ret(eax=r.getrandbits(32),argbytes=0)
 e.w32(0x7003b0,e.stub_fn('assert',assertion))
 hook_rec(c,0x51aba0,nargs=1,ret=r.getrandbits(32))
 return [s,a]
S(0x522940,'GUESS register tank methods','thiscall',None,ret='eax',gen=gen)
