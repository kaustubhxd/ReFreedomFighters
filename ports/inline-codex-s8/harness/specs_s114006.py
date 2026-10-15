from pilot import S
from recruits_util import clear_hooks,rnd

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x60);e.w32(s+0x44,r.choice([1,2,4]))
 state={'token':0,'space':0}
 def token(em,_):
  args=[em.arg32(i) for i in range(7)];k=state['token'];state['token']+=1
  values=[r.choice([0,0x123400+k*16,0x200000+k*4]),r.randrange(20),r.randrange(1000,2000),r.randrange(2000,2100)]
  for a,v in zip(args[3:],values):em.w32(a,v)
  em.calllog.append(('token',*args[:3],*values));em.ret(eax=r.choice([0,1,1,1]),argbytes=0)
 def compare(em,_):
  em.calllog.append(('compare',*[em.arg32(i) for i in range(4)]));em.ret(eax=r.choice([0,1]),argbytes=0)
 def char(em,_):
  v=r.choice([0,32,64,65,90,91,96,97,122,123,255,-1]);em.calllog.append(('char',*[em.arg32(i) for i in range(3)]));em.ret(eax=v&0xffffffff,argbytes=0)
 def space(em,_):
  state['space']+=1;em.calllog.append(('space',em.arg32(0)));em.ret(eax=int(state['space']<r.randrange(1,5)),argbytes=0)
 def convert(em,_):em.calllog.append(('convert',*[em.arg32(i) for i in range(3)]));em.ret(eax=r.getrandbits(32),argbytes=0)
 from recruits_util import _HOOKED
 for addr,fn in [(0x62c270,token),(0x62c600,char),(0x628ee0,space)]:e.hook(addr,fn);_HOOKED.add(addr)
 e.w32(s+0x1c,e.stub_fn('compare',compare));cb=e.stub_fn('convert',convert)
 outputs=[rnd(c,4) for _ in range(6)]
 return [cb,r.randrange(2),s,r.randrange(100),r.randrange(2000,2110),outputs[0],*[p if r.randrange(2) else 0 for p in outputs[1:]]]
S(0x628810,'GUESS parse structured declaration','cdecl',None,ret='eax',gen=gen)
