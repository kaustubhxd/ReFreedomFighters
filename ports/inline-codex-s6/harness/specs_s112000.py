from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 logger(c)
 def string():return bytes(r.randrange(65,91) for _ in range(r.randrange(0,80)))+b'\0'
 def consume(em,k):
  p=em.arg32(0);s=bytearray()
  while em.rbytes(p,1)!=b'\0':s+=em.rbytes(p,1);p+=1
  em.calllog.append(('text',bytes(s)))
 resource=obj(c,0xc0,{0x284:pystub(c,1,this=True,stackmark=(0,),side=consume)})
 source=rnd(c,0x100);e.wbytes(source,string());e.w32(resource+0x97,source)
 provider=obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=resource if r.randrange(4) else 0)})
 extra=string()
 def format(em,k):em.wbytes(em.arg32(1),extra)
 fmt=obj(c,0x20,{0x198:pystub(c,6,pop=4,stackmark=(1,),side=format)})
 so=sysobj(c,{0x190:pystub(c,0,this=True,ret=fmt)},table_size=0xb00)
 table=e.r32(so+0x9b);lookup=obj(c,0x20,{0:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(table+0xae4,lookup)
 me=rnd(c,0x300);state=rnd(c,0x13300);e.w32(me+0x54,provider);e.w32(me+0x94,state);e.wbytes(state+0x1043,bytes([r.randrange(2)]));e.wbytes(me+0x100,string() if r.randrange(2) else b'\0')
 return [me]
S(0x5638e0,'GUESS refresh_resource_text','thiscall',None,ret=None,gen=gen)
