from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def string(s):
  p=rnd(c,len(s)+1);e.wbytes(p,s.encode()+b'\0');return p
 path=r.choice(['root\\foo.txt','ROOT\\bar.bin','root\\foo','other\\thing.txt','foo.txt','.bin','root','rooted\\x.bin',''])
 arg=string(path)
 items=[string(r.choice(['.txt','.bin','*.txt','*','other'])) for _ in range(r.randrange(4))]
 def begin(em,k):
  p=em.arg32(0);em.w32(p,0);em.w32(p+4,0);em.w32(p+8,0)
 def nxt(em,k):
  p=em.arg32(0);i=em.r32(p+4);em.w32(p+4,i+1);em.w32(p,int(i<len(items)));return items[i] if i<len(items) else 0
 tab=obj(c,16,{0x4c:pystub(c,1,this=True,nullflag=(0,),side=begin),0x5c:pystub(c,1,this=True,nullflag=(0,),ret=nxt)})
 me=obj(c,0x20,{0x6c:pystub(c,1,this=False)})
 e.w32(me+8,r.choice([tab,tab,0]))
 prefix=r.choice([0,string(r.choice(['root','ROOT','root\\','other','','longer_than_any_input_path']))])
 sysobj(c)
 hook_rec(c,0x4cc1d0,0,this=True,ret=prefix)
 hook_rec(c,0x4cc850,0,this=True,side=lambda em,k:em.calllog.append(('pattern',em.reg('edx'))),ret=r.choice([0,1]))
 def text(em,p):
  b=bytearray()
  while em.r8(p):b.append(em.r8(p));p+=1
  return b.decode("latin1")
 def chars(em,k,last=False):
  s=text(em,em.arg32(0));ch=chr(em.arg32(1)&255);i=s.rfind(ch) if last else s.find(ch)
  em.ret(eax=em.arg32(0)+i if i>=0 else 0)
 e.stub_import('strchr',lambda em,k:chars(em,k))
 e.stub_import('strrchr',lambda em,k:chars(em,k,True))
 def cmp(em,k,n=False):
  a=text(em,em.arg32(0)).lower();b=text(em,em.arg32(1)).lower()
  if n:a=a[:em.arg32(2)];b=b[:em.arg32(2)]
  em.ret(eax=(a>b)-(a<b))
 e.stub_import('_stricmp',lambda em,k:cmp(em,k))
 e.stub_import('_memicmp',lambda em,k:cmp(em,k,True))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [me,arg]
S(0x4351c0,'filter extension and strip root','thiscall',None,ret='eax',gen=gen)
