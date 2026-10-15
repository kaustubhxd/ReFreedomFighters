from pilot import S
from recruits_util import clear_hooks,rnd,obj,hook_rec,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x1000);e.w32(s+0xcee,r.choice([0,1,2,3,4,5,6,0xffffffff]));e.w32(s+0x94,rnd(c,0x400))
 def get(slot):
  def h(em,_):em.calllog.append(('get',slot,em.reg('ecx')));em.ret(eax=r.getrandbits(32),argbytes=0)
  return e.stub_fn('get',h)
 o=obj(c,32,{slot:get(slot) for slot in [0x14,0x1c,0x28]});e.w32(s+0xc5e,o)
 hook_rec(c,0x564b50,nargs=0,this=True,ret=0)
 def widget(em,_):em.calllog.append(('widget',em.reg('ecx'),*[em.arg32(i) for i in range(11)]));em.ret(eax=r.getrandbits(32),argbytes=44)
 e.hook(0x57fa80,widget);_HOOKED.add(0x57fa80)
 return [s]
S(0x56ba10,'GUESS initialize mode dependent dialog controls','thiscall',None,ret=None,gen=gen)
