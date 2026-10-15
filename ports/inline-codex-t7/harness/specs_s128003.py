from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def read(em,p):
  b=bytearray()
  while True:
   x=em.rbytes(p+len(b),1)[0]
   if not x:return bytes(b)
   b.append(x)
 def string(b):
  p=rnd(c,len(b)+1);e.wbytes(p,b+b'\0');return p
 keys=[0x679a48,0x679a58,0x679a60,0x679a6c,0x679a78,0x679a80,0x679bc0]
 name=string(r.choice([read(e,k) for k in keys]+[b'unknown',b'',b'x']).swapcase())
 def ci(em,k):
  a,b=em.arg32(0),em.arg32(1);x,y=read(em,a).lower(),read(em,b).lower();em.calllog.append(('cmp',a,b));em.ret((x>y)-(x<y),0)
 e.w32(0x676414,e.stub_fn('stricmp',ci))
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
 def split(em,k):
  # Snapshot uninitialised stack arrays before filling them to verify the stack model.
  em.calllog.append(('split',em.arg32(0),em.rbytes(em.arg32(1),32),em.rbytes(em.arg32(2),32)))
  em.wbytes(em.arg32(1),b'first\0');em.wbytes(em.arg32(2),b'second\0')
 def dispatch(em,k):
  mode=em.arg32(0)
  if mode==0:em.calllog.append(('dispatch',mode,read(em,em.arg32(1)),read(em,em.arg32(2))))
  else:em.calllog.append(('dispatch',mode,em.arg32(1),em.arg32(2)))
 # Mode-dependent pointers are normalized in recorder; raw argument values separately logged above.
 sub=obj(c,32,{0x12c:slot(3,stackmark=(1,2),side=dispatch)})
 me=obj(c,0xc0,{0x20:slot(1),0x68:slot(3,stackmark=(1,2),side=split)})
 e.w32(me+0x9b,r.choice([0,sub,sub]))
 e.w32(0x700394,obj(c,32,{0x74:slot(0)}))
 e.w32(0x70038c,obj(c,32,{0x84:slot(0)}))
 def printline(em,k):em.calllog.append(('print',em.arg32(0),em.arg32(1)))
 lg=obj(c,32,{0x2c:pystub(c,2,pop=0,side=printline)})
 e.w32(0x700390,obj(c,32,{0x20:slot(2,lg,side=lambda em,k:em.calllog.append(('log',em.arg32(0),em.arg32(1))))}))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,name,r.getrandbits(32)]
S(0x42c4c0,'GUESS console command dispatch','thiscall',None,ret='al',gen=g,note='batch128003')
