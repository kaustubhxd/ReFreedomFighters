from pilot import S
from recruits_util import clear_hooks,rnd,obj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;record=rnd(c,0x60);src=rnd(c,36*20+16);dst=rnd(c,256);indices=rnd(c,64)
 e.w16(record+2,r.choice([0,0,0,1]));e.w16(record+14,r.randrange(5));e.w32(record+0x50,r.randrange(6));e.w32(record+0x40,r.randrange(16))
 id=r.getrandbits(32);e.w32(record+0x14,0x1234);e.w32(record+0x3c,0x5678)
 def get(em,_):
  key=em.arg32(0);em.calllog.append(('get',key));em.ret(eax=record if key==id else indices if key==0x5678 else src,argbytes=4)
 s=obj(c,32,{12:e.stub_fn('get',get)})
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:(em.calllog.append(('assert',)),em.ret(eax=r.getrandbits(32),argbytes=0))))
 return [s,id,r.choice([1,2,4,8,16,0,99]),dst,r.randrange(17)]
S(0x657060,'GUESS extract vertex or index fields','thiscall',None,ret=None,gen=gen)
