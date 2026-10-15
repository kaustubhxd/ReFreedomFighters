from pilot import S
from recruits_util import clear_hooks,rnd,obj

def gen(c):
 clear_hooks(c); e,r=c.emu,c.rng
 w=r.choice([0,1,2,3,4,5,7,8,9,12,16]); h=r.choice([0,1,3,4,5,8,11,12])
 rw=(w+3)&~3; rh=(h+3)&~3
 src=rnd(c,max(16,rw*rh)); out=rnd(c,max(16,rw*rh*4+32))
 for i in range(rw*rh//16):
  a=r.randrange(65536); b=r.choice([a,r.randrange(65536),0,65535]); e.w32(src+i*16+8,a|(b<<16))
  e.w32(src+i*16+12,r.choice([r.getrandbits(32),0,0x55555555,0xaaaaaaaa,0xffffffff,0xe4e4e4e4]))
 d=rnd(c,0x20); e.w32(d+4,w); e.w32(d+8,h); e.w32(d+16,src)
 def get(em,_):
  em.calllog.append(('get',em.reg('ecx'),em.arg32(0))); em.ret(eax=d,argbytes=4)
 s=obj(c,0x20,{0x38:e.stub_fn('get',get)})
 return [s,out,r.getrandbits(32)]
S(0x6380e0,'GUESS decode explicit alpha blocks','thiscall',None,ret=None,gen=gen)
