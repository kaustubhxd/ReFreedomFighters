from pilot import S
from recruits_util import clear_hooks,rnd,obj,sysobj,_HOOKED
import fnmatch

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x1a0)
 def string(em,p):
  b=bytearray()
  while True:
   v=em.rbytes(p,1)[0];p+=1
   if not v:return b.decode('ascii')
   b.append(v)
 token=r.choice(['Female','Male','Alpha','Beta','', 'x'*29]);text='prefix'+token+r.choice(['','_extra']);input=rnd(c,80);e.wbytes(input,text.encode()+b'\0')
 names=[f'Actor_{token}_{i}' for i in range(r.randrange(1,13))] if token in ['Female','Male'] else [r.choice(['something','Actor_Alpha_x','BetaHero','empty','x'*40]) for _ in range(r.randrange(5))]
 items=[]
 for name in names:
  p=rnd(c,80);e.wbytes(p,name.encode()+b'\0');desc=rnd(c,16);e.w32(desc+4,p)
  def getter(em,_,desc=desc):em.calllog.append(('name',em.reg('ecx')));em.ret(eax=desc,argbytes=0)
  items.append(obj(c,32,{0x20:e.stub_fn('name',getter)}))
 def resolve(em,_):id=em.arg32(0);em.calllog.append(('resolve',id));em.ret(eax=items[id],argbytes=4)
 system=sysobj(c,table_slots={0x58:e.stub_fn('resolve',resolve)})
 def begin(em,_):p=em.arg32(0);em.w32(p,len(items));em.w32(p+4,0);em.w32(p+8,0);em.calllog.append(('begin',));em.ret(eax=0,argbytes=4)
 def next(em,_):
  p=em.arg32(0);i=em.r32(p+4);em.w32(p,1 if i<len(items) else 0);em.w32(p+4,i+1);em.calllog.append(('next',i));em.ret(eax=i,argbytes=4)
 lst=obj(c,32,{0x4c:e.stub_fn('begin',begin),0x5c:e.stub_fn('next',next)});data=rnd(c,32);e.w32(data+24,lst);e.w32(s+0x180,data)
 def match(em,_):
  a=string(em,em.reg('ecx'));b=string(em,em.reg('edx'));em.calllog.append(('match',a,b));em.ret(eax=0 if fnmatch.fnmatchcase(a,b) else 1,argbytes=0)
 e.hook(0x4cc850,match);_HOOKED.add(0x4cc850)
 def seed(em,_):em.calllog.append(('seed',em.arg32(0)));em.ret(eax=0,argbytes=0)
 def random(em,_):v=r.randrange(0x7fffffff);em.calllog.append(('random',v));em.ret(eax=v,argbytes=0)
 e.w32(0x676454,e.stub_fn('seed',seed));e.w32(0x67644c,e.stub_fn('random',random))
 def log(em,_):em.calllog.append(('log',em.arg32(1),string(em,em.arg32(2))));em.ret(eax=0,argbytes=0)
 lo=obj(c,16,{0x2c:e.stub_fn('log',log)})
 def logger(em,_):em.calllog.append(('logger',em.arg32(0),em.arg32(1)));em.ret(eax=lo,argbytes=8)
 e.w32(0x700390,obj(c,16,{0x20:e.stub_fn('logger',logger)}))
 return [s,input]
S(0x566360,'GUESS select named actor variant','thiscall',None,ret='eax',gen=gen)
