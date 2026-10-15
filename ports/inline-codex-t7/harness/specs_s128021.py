from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 me=rnd(c,0x700);stream=rnd(c,0x80);values=[r.getrandbits(32) for _ in range(58)]
 hook_rec(c,0x610100,1,this=True)
 def skip(em,k):
  em.calllog.append(('skip',em.reg('ecx'),em.r32(em.arg32(0))));em.w32(em.arg32(0),values[k%58])
 hook_rec(c,0x4e1440,1,this=True,stackmark=(0,),side=skip)
 floats=[r.getrandbits(32) for _ in range(50)];words=r.randbytes(174*4)
 def field(em,k,kind):
  p,n=em.arg32(0),em.arg32(1);em.calllog.append(('field',kind,p,n))
  data=words[:n*4] if kind=='word' else b''.join(floats[(k+i)%50].to_bytes(4,'little') for i in range(n))
  em.wbytes(p,data)
 hook_rec(c,0x4e12e0,2,this=True,side=lambda em,k:field(em,k,'float'))
 hook_rec(c,0x4e11e0,2,this=True,side=lambda em,k:field(em,k,'word'))
 hook_rec(c,0x4e1b30,0,this=True,side=lambda em,k:em.w32(stream+4,0))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,stream]
S(0x5a6660,'GUESS CopyDataBlock typed stream fields','thiscall',None,ret=None,gen=g,note='batch128021')
