import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 value=rnd(c,8);tag=r.choice([0,1,2,4,1,2,4,255]);e.wbytes(value+4,bytes([tag]))
 if tag==2:e.wbytes(value,struct.pack('<f',r.choice([0.,-1.,1e20,r.uniform(-100,100)])))
 string=rnd(c,16);e.wbytes(string,b'u5-string-test!\x00\x00')
 arg=rnd(c,12);arr=rnd(c,16);e.w32(arg+4,arr)
 hook_rec(c,0x5003d0,1,this=True,ret=value)
 hook_rec(c,0x506040,0,this=True,ret=string)
 rec=e.alloc(512,4)
 def fmt(em,rr):
  em.w32(rec,em.arg32(0));em.w32(rec+4,em.arg32(2));n=8 if em.arg32(2)==0x6792bc else 4
  em.wbytes(rec+8,em.rbytes(em.reg('esp')+16,n));em.wbytes(em.arg32(1),b'formatted-u5!!!\x00\x00');em.calllog.append(('format',n));em.ret(eax=15,argbytes=0)
 formatter=obj(c,0x10,{0x14:e.stub_fn('format',fmt)})
 hook_rec(c,0x5fa630,0,pop=0,ret=formatter)
 def log(em,rr):
  k=em.r32(rec+500);p=rec+64+48*k;em.w32(p,em.arg32(0));f=em.arg32(1);em.w32(p+4,f)
  if f==0x69d39c:
   em.wbytes(p+8,em.rbytes(em.reg('esp')+12,8));s=em.arg32(4);em.w32(p+16,1 if s else 0)
   if s:em.wbytes(p+20,em.rbytes(s,16))
  else:em.w32(p+8,em.arg32(2))
  em.w32(rec+500,k+1);em.calllog.append(('log',f));em.ret(eax=0,argbytes=0)
 logger=obj(c,0x10,{0x2c:e.stub_fn('log',log)})
 e.w32(0x700390,obj(c,0x10,{0x20:pystub(c,2,this=True,ret=logger)}))
 so=sysobj(c);e.wbytes(so+0x1b3d,bytes([r.choice([0,1,1,1])]))
 e.w32(so+0x40,r.getrandbits(32))
 return [rnd(c,8),arg]
S(0x50aac0,'GUESS debug log typed parameter','thiscall',None,ret=None,gen=gen)
