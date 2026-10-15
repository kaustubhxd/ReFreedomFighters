from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def string(b):
  p=rnd(c,len(b)+1);e.wbytes(p,b+b'\0');return p
 def read(em,p,n=4096):
  b=bytearray()
  for i in range(n):
   x=em.rbytes(p+i,1)[0]
   if not x:break
   b.append(x)
  return bytes(b)
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
 me=rnd(c,0x1ac0)
 e.wbytes(me+0x6b,bytes([r.choice([0,0,0,1])]))
 e.wbytes(me+0x63,bytes([r.choice([0,0,1,255])]))
 holder=rnd(c,16);e.w32(holder+4,string(r.choice([b'',b'value',b'abc 123'])));e.w32(me+0x1aa3,holder)
 path=string(r.choice([b'@config.ini',b'@x',b'wrong',b'']))
 hook_rec(c,0x4cc1d0,0,this=True,ret=path)
 names=[read(e,p) for p in [0x678400,0x678308,0x67820c,0x6781c0,0x678358,0x678398]]
 lines=[]
 for _ in range(r.randrange(12)):
  name=r.choice(names+[b'Unknown',b'#comment',b''])
  if r.randrange(2):name=name.swapcase()
  lines.append(name+b'=old'+r.choice([b'\n',b'\r',b'\r\n']))
 data=b''.join(lines)+r.choice([b'',b'Unknown tail',names[1]+b'tail'])
 buf=rnd(c,len(data)+1)
 hook_rec(c,0x41e290,1,pop=0,ret=buf)
 hook_rec(c,0x634273,2,pop=0)
 def fill(em,k):em.wbytes(em.arg32(1),data)
 def wr(em,k):em.calllog.append(('write',em.arg32(0),em.rbytes(em.arg32(1),em.arg32(2))))
 fs=obj(c,32,{0x34:slot(2,r.choice([0,1,1,1,0x100])),0x30:slot(2,len(data)),0x60:slot(5,side=fill),0x14:slot(1,r.getrandbits(32)),0x38:slot(3,stackmark=(1,),side=wr),0x1c:slot(1)})
 e.w32(0x700394,fs)
 lg=obj(c,32,{0x2c:pystub(c,3,pop=0)})
 e.w32(0x700390,obj(c,32,{0x20:slot(2,lg)}))
 def output1(em,k):em.w32(em.arg32(0),0x1234)
 def output2(em,k):em.w32(em.arg32(1),0x5678)
 sub=obj(c,32,{0x1cc:slot(1,stackmark=(0,),deref={0:1},side=output1),0x1d4:slot(2,stackmark=(1,),deref={1:1},side=output2)})
 e.w32(me+0x190f,sub)
 def strchr(em,k):
  p,ch=em.arg32(0),em.arg32(1)&255;ix=(read(em,p)+b'\0').find(bytes([ch]));em.ret(p+ix if ix>=0 else 0,0)
 e.w32(0x676254,e.stub_fn('strchr',strchr))
 def sni(em,k):
  a,b,n=em.arg32(0),em.arg32(1),em.arg32(2);x,y=read(em,a)[:n].lower(),read(em,b)[:n].lower();em.ret((x>y)-(x<y),0)
 e.w32(0x67640c,e.stub_fn('strnicmp',sni))
 def fmt(em,k):
  dst,f=em.arg32(0),em.arg32(1)
  if f==0x6784ec:
   args=[em.arg32(2),em.arg32(3)];b=('%08x%08x'%tuple(args)).encode()
  elif f==0x6784f4:
   args=[em.arg32(2)];b=('%08x'%args[0]).encode()
  elif f==0x6784f8:
   args=[read(em,em.arg32(2)),read(em,em.arg32(3))];b=args[0]+b'='+args[1]+b'\n'
  elif f==0x678500:
   args=[read(em,em.arg32(2))];b=args[0]+b'\n'
  else:raise ValueError(hex(f))
  em.calllog.append(('fmt',f,args));em.wbytes(dst,b+b'\0');em.ret(len(b),0)
 # Variable arguments are logged by value, including strings in stack buffers.
 e.hook(0x42ac56,fmt)
 from recruits_util import _HOOKED
 _HOOKED.add(0x42ac56)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x4239c0,'GUESS rewrite renderer settings','thiscall',None,ret='al',gen=g,note='batch128002')
