from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def readstr(em,p):
 out=bytearray()
 while em.r8(p):
  out.append(em.r8(p)); p+=1
 return bytes(out)

def gen(c):
 clear_hooks(c); e=c.emu; r=c.rng
 sysobj(c,slots={0xd4:pystub(c,1,ret=r.choice([0,1,0x100,0x101]),this=True),0xd8:pystub(c,1,ret=r.choice([0,1,0x100,0x101]),this=True)})
 # The getter reads the string object's first pointer, not its inline bytes.
 name=r.choice([b'no_extension',b'file0000.sav',b'path.abc  17.sav',b'file9999.sav',b'file-123.sav'])
 p=rnd(c,128); e.wbytes(p,name+b'\0')
 me=obj(c,0x2400,{0x160:pystub(c,1,this=True,stackmark=(0,),side=lambda em,k:em.w32(em.arg32(0),r.getrandbits(32))),0x16c:pystub(c,0,this=True)})
 e.w32(me+0x2346,p); e.w8(me+0x1a9b,r.choice([0,0,0,1]))
 target=obj(c,0x20,{0x90:pystub(c,1,this=True,side=lambda em,k:em.calllog.append(('save',readstr(em,em.arg32(0)))))})
 e.w32(me+0x190f,target)
 count=[r.randrange(5)]
 def exists(em,k):
  em.calllog.append(('name',readstr(em,em.arg32(0))))
 def result(em,k):
  ans=count[0]>0; count[0]-=1; return int(ans)
 fs=obj(c,0x20,{0x34:pystub(c,2,this=True,ret=result,side=exists)})
 e.w32(0x700394,fs)
 def last(em,res):
  p=em.arg32(0); s=readstr(em,p); ch=em.arg32(1)&255
  if isinstance(s,str): s=s.encode('latin1')
  i=s.rfind(bytes([ch])); em.calllog.append(('strrchr',s,ch)); em.ret(eax=p+i if i>=0 else 0)
 def atol(em,res):
  s=readstr(em,em.arg32(0)); em.calllog.append(('atol',s))
  if isinstance(s,bytes):s=s.decode('latin1')
  import re
  m=re.match(r'\s*([+-]?\d+)',s); em.ret(eax=int(m[1]) if m else 0)
 def fmt(em,k):
  p=em.arg32(0); n=em.arg32(2); n=n if n<0x80000000 else n-0x100000000
  text=('%4d'%n).encode(); em.wbytes(p,text+b'\0')
 hook_rec(c,0x42ac56,3,pop=0,side=fmt)
 e.stub_import('strrchr',last);e.stub_import('atol',atol)
 return [me]
S(0x420bb0,'GUESS save path with numbered collision suffix','thiscall',None,ret=None,gen=gen,note='batch34168')
