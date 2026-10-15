from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def compare(em,res):
  a,b,n=[em.arg32(i) for i in range(3)];aa=em.rbytes(a,n);bb=em.rbytes(b,n);v=(aa>bb)-(aa<bb);em.calllog.append(('compare',a,b,n,v));em.ret(v&0xffffffff,0)
 e.w32(0x676408,e.stub_fn('compare',compare))
 def span():
  p=rnd(c,32);s=bytes(r.choice(b'ABCabc') for _ in range(r.randrange(0,12)));e.wbytes(p,s);return p,p+len(s)
 def node():
  p=rnd(c,24);a,b=span();e.w32(p+13,a);e.w32(p+17,b);e.w32(p+5,0);e.w32(p+9,0);return p
 head=node();nodes=[node() for _ in range(r.randrange(0,5))]
 for i,p in enumerate(nodes[:-1]):e.w32(p+r.choice([5,9]),nodes[i+1])
 e.w32(head+1,nodes[0] if nodes else 0);e.w32(head+5,r.choice(nodes) if nodes else head)
 prev=node();hook_rec(c,0x42ffc0,0,this='mark',side=lambda em,k:em.w32(em.reg('ecx'),prev))
 value=r.getrandbits(32)
 hook_rec(c,0x5fb400,4,this=True,stackmark=(0,),side=lambda em,k:em.w32(em.arg32(0),value),ret=lambda em,k:em.arg32(0))
 me=rnd(c,16);e.w32(me,head);key=rnd(c,8);a,b=span();e.w32(key,a);e.w32(key+4,b)
 return [me,rnd(c,8),key]
S(0x5fc480,'GUESS insert_string_key','thiscall',None,ret='eax',gen=gen)
