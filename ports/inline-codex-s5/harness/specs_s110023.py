from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def memset(em,_):
  p,v,n=em.arg32(0),em.arg32(1),em.arg32(2);em.wbytes(p,bytes([v&255])*n);em.ret(eax=p)
 e.stub_import("memset",memset)
 cfg=rnd(c,0x20);e.wbytes(cfg,b'quality\x00')
 def query(em,n):em.w32(em.arg32(1),cfg)
 sysobj(c,slots={0x5c:pystub(c,2,this=True,nullflag=(1,),side=query,ret=r.choice([0,1,256,257]))})
 line=obj(c,0x20,{0x2c:pystub(c,3,pop=0)})
 e.w32(0x700390,obj(c,0x20,{0x20:pystub(c,2,this=True,ret=line)}))
 match=r.choice([0,0x6b0284,0x6b0290,0x6b0298,0x6b02a0])
 def cmp(em,_):
  a,b=em.arg32(0),em.arg32(1);em.calllog.append(('stricmp',a,b));em.ret(eax=0 if a==match else 1)
 e.w32(0x676414,e.stub_fn('stricmp',cmp))
 return [rnd(c,0x180)]
S(0x5acc20,'GUESS quality settings constructor','thiscall',None,ret='eax',gen=gen)
