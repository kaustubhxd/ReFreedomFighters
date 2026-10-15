from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 w,h=r.choice([640,800,1024,1920]),r.choice([480,600,768,1080])
 t=obj(c,0x1200,{0xd8:pystub(c,0,this=True,ret=w),0xdc:pystub(c,0,this=True,ret=h),0x1a4:pystub(c,0,this=True,ret=r.randrange(2))})
 for off in (0x60,0x64):e.wf32(t+off,r.choice([-.5,.5,0,r.uniform(-2,2)]))
 e.w8(t+0x11e7,r.randrange(2))
 sys=rnd(c,0xa00);e.w32(0x70039c,sys)
 for off in (0x9e7,0x9eb):e.wf32(sys+off,r.uniform(-100,100))
 ox,oy=r.randrange(-100,100),r.randrange(-100,100)
 def client(em,_):
  p=em.arg32(1);x,y=em.r32(p),em.r32(p+4);em.calllog.append(('ClientToScreen',em.arg32(0),x,y));em.w32(p,(x+ox)&0xffffffff);em.w32(p+4,(y+oy)&0xffffffff);em.ret(eax=1,argbytes=8)
 def rect(em,_):
  em.calllog.append(('GetClientRect',em.arg32(0)));p=em.arg32(1)
  for i,v in enumerate([0,0,w,h]):em.w32(p+4*i,v)
  em.ret(eax=1,argbytes=8)
 e.w32(0x676238,e.stub_fn('ClientToScreen',client));e.w32(0x676210,e.stub_fn('GetClientRect',rect));e.w32(0x676228,pystub(c,2,ret=1))
 return [t,r.getrandbits(32),r.choice([w//2,w//2+1,r.randrange(-1000,2000)]),r.choice([h//2,h//2+1,r.randrange(-1000,2000)])]
S(0x654ee0,'GUESS relative mouse movement','thiscall',None,ret=None,gen=gen)
