from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def read(em,p):
  b=bytearray()
  while True:
   v=em.rbytes(p+len(b),1)[0]
   if not v:return bytes(b)
   b.append(v)
 def string(b):
  p=rnd(c,len(b)+1);e.wbytes(p,b+b'\0');return p
 rec=rnd(c,0x80);ctx=rnd(c,0x300);arg=rnd(c,8);e.w32(arg,rec);e.w32(arg+4,ctx)
 e.w32(rec+16,r.randrange(8));e.w32(rec+4,r.choice([0,r.getrandbits(32)]));e.w32(rec+8,r.choice([0,r.getrandbits(32)]))
 codes=[r.getrandbits(32) or 1 for _ in range(r.randrange(6))]
 for i,code in enumerate(codes):e.w32(0x6e40d8+i*8,code);e.w32(0x6e40dc+i*8,string(('exception%d'%i).encode()))
 e.w32(0x6e40d8+len(codes)*8,0);e.w32(rec,r.choice(codes+[0,r.getrandbits(32)]))
 e.w32(ctx,r.choice([0,1,2,4,8,16,0x10000,r.getrandbits(32)]))
 stamp=r.getrandbits(32)
 e.w32(0x676438,pystub(c,1,pop=0,stackmark=(0,),ret=stamp,side=lambda em,k:em.w32(em.arg32(0),stamp)))
 datestr=string(b'fixed date\n')
 e.w32(0x676440,pystub(c,1,pop=0,stackmark=(0,),ret=datestr,side=lambda em,k:em.calllog.append(('time',em.r32(em.arg32(0))))))
 hook_rec(c,0x421500,0,this=True,ret=r.getrandbits(32))
 query=[r.getrandbits(32) for _ in range(7)];query[4]=r.choice([0,0x1000,0x2000]);query[1]=r.choice([0,r.getrandbits(32)])
 def q(em,k):em.wbytes(em.arg32(1),b''.join(x.to_bytes(4,'little') for x in query))
 e.w32(0x6760e8,pystub(c,3,stackmark=(1,),ret=28,side=q))
 module=r.choice([b'C:\\game\\Freedom.exe',b'Freedom.exe',b'C:\\x\\'])
 def mod(em,k):em.wbytes(em.arg32(1),module+b'\0')
 e.w32(0x67607c,pystub(c,3,ret=len(module),side=mod))
 def last(em,k):
  p,ch=em.arg32(0),em.arg32(1)&255;b=read(em,p);idx=(b+b'\0').rfind(bytes([ch]));em.ret(p+idx if idx>=0 else 0,0)
 e.w32(0x676258,e.stub_fn('strrchr',last))
 zero={0x677bc8,0x677bcc,0x677bf8,0x677ca4,0x677d58,0x677dcc,0x677e60}
 two={0x677ae0,0x677b2c,0x677b44,0x677bb0,0x677cd8}
 strings={0x677a70:[0],0x677ae0:[1],0x677b2c:[1],0x677b64:[0],0x677bb0:[1],0x677cd8:[1]}
 def log(em,k):
  f=em.arg32(0);n=0 if f in zero else 2 if f in two else 1
  args=[em.arg32(i+1) for i in range(n)]
  for i in strings.get(f,[]):args[i]=read(em,args[i])
  em.calllog.append(('log',f,args));em.ret(0,0)
 e.hook(0x421870,log)
 from recruits_util import _HOOKED
 _HOOKED.add(0x421870)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [r.getrandbits(32),arg]
S(0x424910,'GUESS dump exception context','cdecl',None,ret=None,gen=g,note='batch128014')
