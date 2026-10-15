from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 strings=[bytes(r.randrange(65,91) for _ in range(r.randrange(0,30)))+b'\0' for _ in range(4)]
 vals=[r.randrange(256) for _ in range(4)];write=[r.randrange(2) for _ in range(4)]
 def format(em,k):em.wbytes(em.arg32(1),strings[k])
 fmt=obj(c,0x20,{0x198:pystub(c,4,pop=0,stackmark=(1,),side=format)})
 def read(em,k):
  em.calllog.append(('key',em.rbytes(em.arg32(0),len(strings[k])),'initial',em.rbytes(em.arg32(1),1)))
  if write[k]:em.wbytes(em.arg32(1),bytes([vals[k]]))
 settings=obj(c,0x20,{0x90:pystub(c,2,this=True,stackmark=(0,1),side=read)})
 sysobj(c,{0x190:pystub(c,0,this=True,ret=fmt)},{0x134:pystub(c,0,this=True,ret=settings)})
 return [rnd(c,0x200)]
S(0x578900,'GUESS load_four_flags','thiscall',None,ret=None,gen=gen)
