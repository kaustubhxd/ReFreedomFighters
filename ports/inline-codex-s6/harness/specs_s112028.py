from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));sysobj(c)
 def string(p):
  data=bytes(r.randrange(65,91) for _ in range(r.randrange(0,65)))+b'\0';e.wbytes(p,data)
 base=rnd(c,80);name=rnd(c,80);string(base);string(name);hook_rec(c,0x4cc1d0,0,this=True,ret=base)
 def observe(em,k):
  p=em.arg32(0);data=bytearray()
  while em.rbytes(p,1)!=b'\0':data+=em.rbytes(p,1);p+=1
  em.calllog.append(('path',bytes(data)))
 me=obj(c,32,{0x4c:pystub(c,1,this=True,stackmark=(0,),side=observe),0x5c:pystub(c,1,this=True,stackmark=(0,),side=observe,ret=r.getrandbits(32))})
 def delete(em,res):
  observe(em,0);em.ret(1,4)
 e.w32(0x676118,e.stub_fn("delete",delete))
 return [me,r.getrandbits(32),r.getrandbits(32),name]
S(0x426af0,'GUESS construct_paths','thiscall',None,ret='eax',gen=gen)
