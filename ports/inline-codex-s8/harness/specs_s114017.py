from pilot import S
from recruits_util import clear_hooks,rnd,obj,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;good=r.randrange(4)==0
 def choose(values):return values[0] if good else r.choice(values)
 s=rnd(c,4);e.w32(s,choose([0,0x1234abcd,r.getrandbits(32)]));e.w32(s,0x1234abcd) if good else None;string=rnd(c,32);e.wbytes(string,b'fake device\0');state={'enum':0}
 def release(em,_):em.calllog.append(('release',em.arg32(0)));em.ret(eax=0,argbytes=4)
 def prop(em,_):
  args=[em.arg32(i) for i in range(6)];v=args[3];kind=choose([8,8,0]);em.wbytes(v,b'\0'*16);em.w16(v,kind);em.w32(v+8,choose([string,string,0]));em.calllog.append(('property',args[0],args[1],args[2],args[4],args[5]));em.ret(eax=choose([0,0,0xffffffff]),argbytes=24)
 items=[obj(c,16,{8:e.stub_fn('release',release),16:e.stub_fn('property',prop)}) for _ in range(4)]
 def enumeration(em,_):
  args=[em.arg32(i) for i in range(5)];k=state['enum'];state['enum']+=1;n=r.randrange(1,4) if k<2 else 0
  for i in range(n):em.w32(args[3]+i*4,items[i])
  em.w32(args[4],n);em.calllog.append(('enum',*args[:3],n));em.ret(eax=choose([0,0,0xffffffff]),argbytes=20)
 enum=obj(c,16,{8:e.stub_fn('release',release),16:e.stub_fn('enum',enumeration)})
 def query(em,_):
  args=[em.arg32(i) for i in range(5)];em.w32(args[4],choose([enum,enum,0]));em.calllog.append(('query',*args[:4]));em.ret(eax=choose([0,0,0xffffffff]),argbytes=20)
 service=obj(c,16,{8:e.stub_fn('release',release),0x48:e.stub_fn('query',query)})
 def connect(em,_):
  args=[em.arg32(i) for i in range(9)];em.w32(args[8],choose([service,service,0]));em.calllog.append(('connect',*args[:8]));em.ret(eax=choose([0,0,0xffffffff]),argbytes=36)
 locator=obj(c,16,{8:e.stub_fn('release',release),12:e.stub_fn('connect',connect)})
 def simple(name,nargs,pop=None,retval=0):
  def h(em,_):em.calllog.append((name,*[em.arg32(i) for i in range(nargs)]));em.ret(eax=retval() if callable(retval) else retval,argbytes=4*nargs if pop is None else pop)
  return e.stub_fn(name,h)
 def create(em,_):
  em.calllog.append(('create',*[em.arg32(i) for i in range(4)]));em.w32(em.arg32(4),choose([locator,locator,0]));em.ret(eax=choose([0,0,0xffffffff]),argbytes=20)
 e.w32(0x676490,e.stub_fn('create',create));e.w32(0x67648c,simple('init',1,retval=lambda:choose([0,1,0xffffffff])));e.w32(0x676484,simple('uninit',0))
 e.w32(0x676174,simple('allocate',1,retval=lambda:choose([string,string,string,0])));e.w32(0x676170,simple('free',1));e.w32(0x676488,simple('proxy',8))
 e.w32(0x676274,simple('contains',2,pop=0,retval=lambda:choose([string,string,0])))
 def scan(em,_):
  fmt=em.arg32(1);v=0xabcd if fmt==0x678f30 else 0x1234;em.w32(em.arg32(2),v);em.calllog.append(('scan',em.arg32(0),fmt,v));em.ret(eax=choose([1,1,0]),argbytes=0)
 def zero(em,_):
  p,v,n=[em.arg32(i) for i in range(3)];em.wbytes(p,bytes([v&255])*n);em.ret(eax=p,argbytes=0)
 for addr,h in [(0x42ac96,scan),(0x634d10,zero)]:e.hook(addr,h);_HOOKED.add(addr)
 return [s]
S(0x429470,'GUESS enumerate COM device identifiers','thiscall',None,ret='eax',gen=gen)
