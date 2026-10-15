from pilot import S
from recruits_util import clear_hooks,rnd,hook_rec,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,64);b=rnd(c,0xa00);st=rnd(c,32);e.w32(s+0x1c,b if r.randrange(12) else 0)
 seq=[]
 n=r.randrange(4);seq.append(n-1)
 for bound in [1,2,3,1]:
  nn=r.randrange(1,4);seq.append(nn-1);seq.extend(r.randrange(bound) for _ in range(nn))
 nn=r.randrange(4);seq.append(nn-1)
 for _ in range(nn):seq.extend([r.randrange(2),0,0,0])
 seq.append(1)
 if r.randrange(2):seq[r.randrange(len(seq))]=r.choice([-1,1,2])
 state={'i':0,'alloc':0}
 def read(em,_):
  i=state['i'];state['i']+=1;v=seq[i] if i<len(seq) else 1;em.calllog.append(('bits',em.arg32(0),em.arg32(1),v));em.ret(eax=v&0xffffffff,argbytes=0)
 allocations=[rnd(c,0x40) for _ in range(32)]
 def alloc(em,_):
  i=state['alloc'];state['alloc']+=1;em.calllog.append(('alloc',em.arg32(0),em.arg32(1)));em.ret(eax=allocations[i],argbytes=0)
 def factory(em,_):
  em.calllog.append(('factory',em.arg32(0),em.arg32(1)));em.ret(eax=r.choice([0,allocations[-1],allocations[-2],allocations[-2]]),argbytes=0)
 for i in range(7):
  t=rnd(c,16);e.w32(t+4,e.stub_fn('factory',factory));e.w32(0x6f1dc0+i*4,t)
 for addr,h in [(0x410de0,read),(0x634df4,alloc)]:e.hook(addr,h);_HOOKED.add(addr)
 hook_rec(c,0x405ca0,nargs=2,pop=0,ret=r.choice([0,0,0,1]));hook_rec(c,0x4010c0,nargs=1,pop=0,ret=0)
 return [s,st]
S(0x401510,'GUESS load codec setup','cdecl',None,ret='eax',gen=gen)
