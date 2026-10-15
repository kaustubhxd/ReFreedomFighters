from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x562440,0,this=True);hook_rec(c,0x563510,1,this=True)
 service=obj(c,0x20,{0x60:pystub(c,2,this=True)});settings=obj(c,0x20,{0x68:pystub(c,3,this=True)})
 text=rnd(c,32);e.wbytes(text,b'9\0');scale=r.choice([0,1,9,10,-1,0x70000000])&0xffffffff
 def atoi(em,res):em.calllog.append(('atoi',em.arg32(0)));em.ret(scale,0)
 e.stub_import('atoi',atoi)
 def get(em,k):em.w32(em.arg32(1),text)
 sysobj(c,{0x5c:pystub(c,2,this=True,stackmark=(1,),side=get,ret=r.randrange(2))},{0x138:pystub(c,0,this=True,ret=service),0x4c:pystub(c,2,this=True,ret=r.getrandbits(32)),0x134:pystub(c,0,this=True,ret=settings)})
 tail=0
 for j in range(r.randrange(0,5)):
  scores=[r.choice([0,1,2,10,90,91,100,-1])&0xffffffff for _ in range(3)]
  def score(em,k,values=scores):return values[min(k,2)]
  actor=obj(c,0x20,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2)),0x310:pystub(c,0,this=True,ret=score),0x2dc:pystub(c,0,this=True)})
  info=rnd(c,0x30);e.w32(info+0x23,r.choice([0,0x100000,0x100001]));e.w32(actor+12,info)
  node=rnd(c,0x70);e.w32(node+0x54,actor if r.randrange(5) else 0);e.w32(node+0x60,tail);tail=node
 root=rnd(c,0x60);e.w32(root+0x50,tail);provider=obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=root)})
 me=rnd(c,0x80);e.w32(me+0x54,provider);e.w32(me+0x44,obj(c,0x20,{0xbc:pystub(c,1,this=True)}))
 return [me]
S(0x569430,'GUESS setup_and_filter_entries','thiscall',None,ret=None,gen=gen)
