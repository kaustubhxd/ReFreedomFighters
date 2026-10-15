from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 root=rnd(c,32);first=rnd(c,32);last=rnd(c,32);prev=rnd(c,32);other=rnd(c,32);me=rnd(c,16)
 e.w32(me,root);e.w32(me+4,r.randrange(3));e.w32(root+5,first);e.w32(root+9,last);e.w32(prev+9,r.randrange(2))
 vals=[r.choice([-1,0,1])&0xffffffff for _ in range(2)]
 def compare(em,res):
  em.calllog.append(('compare',em.reg('ecx'),em.reg('edx'),em.arg32(0),em.arg32(1)))
  k=em.r32(rec);em.w32(rec,k+1);em.ret(vals[min(k,1)],8)
 rec=rnd(c,4);e.w32(rec,0);e.hook(0x42feb0,compare)
 from recruits_util import _HOOKED
 _HOOKED.add(0x42feb0)
 hook_rec(c,0x42ffc0,0,this='mark',side=lambda em,k:em.w32(em.reg('ecx'),prev))
 value=r.getrandbits(32)
 hook_rec(c,0x4300c0,4,this=True,side=lambda em,k:em.w32(em.arg32(0),value))
 def fallback(em,k):em.w32(em.arg32(0),value)
 hook_rec(c,0x430fc0,2,this=True,stackmark=(0,),side=fallback,ret=lambda em,k:em.arg32(0))
 return [me,rnd(c,4),r.choice([root,first,other]),rnd(c,8)]
S(0x430eb0,'GUESS insert_with_hint','thiscall',None,ret='eax',gen=gen)
