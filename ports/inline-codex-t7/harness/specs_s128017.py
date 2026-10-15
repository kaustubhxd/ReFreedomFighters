from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def api(at,n,ret=0,**kw):e.w32(at,pystub(c,n,ret=ret,**kw))
 me=obj(c,0x180,{0xe0:pystub(c,2,this=True),0x88:pystub(c,1,this=True)})
 sys=sysobj(c);cfg=rnd(c,0x80);e.w32(sys+0x1aa3,cfg);e.wbytes(cfg+0x76,bytes([r.randrange(2)]));e.wbytes(sys+0x63,bytes([r.choice([0,1,255])]))
 for off in [0x6f,0x73]:e.w32(sys+off,r.randrange(4000))
 e.w32(sys+0x87,r.choice([0xffffffff,0,r.randrange(1000)]));e.w32(sys+0x8b,r.randrange(1000))
 metrics={key:r.randrange(-100,4000) for key in [16,17,78,79]}
 api(0x6761b4,1,ret=lambda em,k:metrics[em.arg32(0)])
 view=rnd(c,4);e.w32(view,r.randrange(8));api(0x676044,6,ret=r.getrandbits(32));api(0x67604c,5,ret=r.choice([0,view]));api(0x676048,1,ret=r.getrandbits(32))
 def adjust(em,k):
  p=em.arg32(0);em.calllog.append(('adjust',[em.r32(p+i*4) for i in range(4)]))
  for i,v in enumerate([-4,-20,4,4]):em.w32(p+i*4,(em.r32(p+i*4)+v)&0xffffffff)
 api(0x676218,4,stackmark=(0,),side=adjust,ret=r.getrandbits(32))
 for at,n in [(0x6761fc,3),(0x676208,6),(0x6761b8,2),(0x676198,2),(0x6761f4,1),(0x676228,2)]:api(at,n,ret=r.getrandbits(32))
 rect1=[r.randrange(4096) for _ in range(4)];rect2=[r.randrange(4096) for _ in range(4)]
 def rectangle(em,k,vals):em.wbytes(em.arg32(1),b''.join(v.to_bytes(4,'little') for v in vals))
 api(0x676210,2,stackmark=(1,),side=lambda em,k:rectangle(em,k,rect1),ret=1)
 api(0x676214,2,stackmark=(1,),side=lambda em,k:rectangle(em,k,rect2),ret=1)
 def output(em,k):
  fmt=em.arg32(1);n=4 if fmt==0x6c3b84 else 2;em.calllog.append(('print',fmt,[em.arg32(i+2) for i in range(n)]));em.ret(0,0)
 code=e.stub_fn('log',output)
 lg=obj(c,32,{0x2c:code});e.w32(0x700390,obj(c,32,{0x20:pystub(c,2,this=True,ret=lg)}))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,r.getrandbits(32)]
S(0x6519a0,'GUESS configure main window','thiscall',None,ret=None,gen=g,note='batch128017')
