from pilot import S
from recruits_util import clear_hooks,rnd,obj,hook_rec,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x80);e.w32(s+9,r.choice([0,1,1,4,4,7]));data=rnd(c,80);size=r.randrange(65)
 name=rnd(c,80);txt=''.join(r.choice('abc/\\XYZ_') for _ in range(r.randrange(32))).encode();e.wbytes(name,txt+b'\0')
 for off in [0x46,0x52]:e.w32(s+off,r.randrange(4));e.w32(s+off+4,r.randrange(4));e.w32(s+off+8,rnd(c,42*10))
 def good(em,_):em.calllog.append(('valid',em.arg32(0)));em.ret(eax=r.randrange(2),argbytes=4)
 def tell(em,_):v=r.randrange(10000);em.calllog.append(('tell',em.arg32(0),v));em.ret(eax=v,argbytes=4)
 def seek(em,_):em.calllog.append(('seek',*[em.arg32(i) for i in range(3)]));em.ret(eax=0,argbytes=12)
 def write(em,_):
  p,n,h=[em.arg32(i) for i in range(3)];em.calllog.append(('write',n,h,em.rbytes(p,n)));em.ret(eax=r.choice([n,n,n-1])&0xffffffff,argbytes=12)
 file=obj(c,32,{8:e.stub_fn('good',good),12:e.stub_fn('tell',tell),16:e.stub_fn('seek',seek),24:e.stub_fn('write',write)});e.w32(s+21,file)
 def logger(em,_):em.calllog.append(('logger',em.arg32(0),em.arg32(1)));em.ret(eax=log,argbytes=8)
 def logfn(em,_):
  fmt=em.arg32(1);em.calllog.append(('log',fmt,em.arg32(2) if fmt==0x69697c else 0));em.ret(eax=0,argbytes=0)
 log=obj(c,16,{0x2c:e.stub_fn('log',logfn)});e.w32(0x700390,obj(c,16,{0x20:e.stub_fn('logger',logger)}))
 def time(em,_,fallback=False):
  a=em.arg32(0 if fallback else 1);b=em.arg32(1 if fallback else 2);x=r.randrange(65536);y=r.randrange(65536);em.w16(a,x);em.w16(b,y);em.calllog.append(('time',fallback,x,y));em.ret(eax=r.randrange(2),argbytes=8 if fallback else 12)
 e.w32(0x676134,e.stub_fn('time',time))
 def grow(em,_):p=em.reg('ecx');em.calllog.append(('grow',p));em.w32(p,em.r32(p)+8);em.ret(eax=0,argbytes=0)
 def crc(em,_):
  a,p,n=[em.arg32(i) for i in range(3)];em.calllog.append(('crc',a,em.rbytes(p,n) if p else b''));em.ret(eax=r.getrandbits(32),argbytes=12)
 def compress(em,_):
  entry=em.arg32(0);em.calllog.append(('compress',em.reg('ecx'),entry,em.arg32(1),em.rbytes(entry+2,26)));em.w32(entry+16,r.choice([0,size,size+1]));em.ret(eax=0,argbytes=8)
 for addr,h in [(0x4d6250,grow),(0x4d68e0,lambda em,_:time(em,_,True)),(0x62fb30,crc),(0x4d79d0,compress)]:e.hook(addr,h);_HOOKED.add(addr)
 return [s,name,rnd(c,16) if r.randrange(2) else 0,data,size]
S(0x4d7c30,'GUESS append archive entry','thiscall',None,ret=None,gen=gen)
