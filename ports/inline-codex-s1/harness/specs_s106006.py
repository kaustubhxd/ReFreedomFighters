import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,logger,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def data(n):return bytes(r.getrandbits(8) for _ in range(n))
 basis=data(36);position=data(12);mat=data(36);base=data(12)
 def source(em,k):
  em.wbytes(em.arg32(0),basis);em.wbytes(em.arg32(1),position)
 src=obj(c,16,{0x80:pystub(c,2,this=True,nullflag=(0,1),side=source)})
 dst=obj(c,16,{0x74:pystub(c,2,this=True,deref={0:9,1:3})})
 parent=rnd(c,16);e.w32(parent+8,rnd(c,16))
 # Null combinations cover diagnostic branches as well as the full pipeline.
 targets=[dst,parent,src]
 for i in range(3):
  if r.random()<.2:targets[i]=0
 refs=[rnd(c,4) for _ in range(3)]
 for i,p in enumerate(refs):e.w32(p,0x100+i)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:refs[k%3])
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:targets[k%3])})
 def get_parent(em,k):em.wbytes(em.arg32(0),mat);em.wbytes(em.arg32(1),base)
 hook_rec(c,0x4db2c0,2,this=True,nullflag=(0,1),side=get_parent)
 for addr,n in [(0x4dfd10,36),(0x4de420,36),(0x4de480,36),(0x4419f0,12),(0x43e960,12)]:
  out=data(n)
  def h(em,k,n=n,out=out,addr=addr):
   em.calllog.append((hex(addr),em.rbytes(em.reg('edx'),36 if addr==0x4419f0 else n).hex()))
   if addr!=0x4dfd10:em.calllog.append(('old-dst',em.rbytes(em.reg('ecx'),n).hex()))
   em.wbytes(em.reg('ecx'),out)
  hook_rec(c,addr,0,this='mark',side=h)
 hook_rec(c,0x633654,0)
 logger(c)
 args=rnd(c,16);e.w32(args+4,rnd(c,16))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [args]
S(0x50f850,'transform linked object','stdcall',None,ret=None,gen=gen)
