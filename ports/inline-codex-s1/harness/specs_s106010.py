from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def string(em,k):
  p=em.arg32(0);b=bytearray()
  for i in range(128):
   x=em.r8(p+i)
   if not x:break
   b.append(x)
  em.calllog.append(('text',bytes(b).hex()))
 final=obj(c,16,{0x30:pystub(c,1,this=True,nullflag=(0,),side=string)})
 cell=rnd(c,8);e.w32(cell,final)
 lst=rnd(c,16)
 result=obj(c,16,{0x4c:pystub(c,1,this=True,pop=0,ret=lst)})
 first=obj(c,16,{0x18:pystub(c,1,this=True,ret=r.choice([0,result,result]))})
 hook_rec(c,0x5003d0,1,this=True,ret=cell)
 text=e.cstr(r.choice(['target','prefix\\name','', 'other']))
 found=rnd(c,8);e.w32(found+4,text)
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,found]))})
 hook_rec(c,0x633654,0,ret=lambda em,k:em.reg("eax"))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [first,r.getrandbits(32),r.getrandbits(32)]
S(0x5007e0,'translate event name','stdcall',None,ret='eax',gen=gen)
