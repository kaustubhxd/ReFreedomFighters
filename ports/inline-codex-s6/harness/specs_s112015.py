from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 for a in (0x563510,0x563610):hook_rec(c,a,1,this=True)
 hook_rec(c,0x572240,2,this=True)
 children=[obj(c,32,{0x2e8:pystub(c,1,this=True),0x36c:pystub(c,1,this=True)}) for _ in range(3)]
 parent=obj(c,32,{0x25c:pystub(c,2,this=True,ret=lambda em,k:children[k])});provider=obj(c,32,{0x25c:pystub(c,2,this=True,ret=parent)})
 def getter(slot):
  counter=e.alloc(4);vals=[r.getrandbits(32),r.getrandbits(32)]
  def h(em,res):
   k=em.r32(counter);em.w32(counter,k+1);em.calllog.append(('get',slot,em.reg('ecx'),em.arg32(0) if k else None));em.ret(vals[min(k,1)],4 if k else 0)
  return e.stub_fn('setting',h)
 settings=obj(c,32,{slot:getter(slot) for slot in (0x7c,0x84,0x8c)})
 sysobj(c,{0xbc:pystub(c,0,this=True,ret=settings)},{0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 me=rnd(c,0x200);e.w32(me+0x54,provider)
 return [me]
S(0x571f20,'GUESS initialize_sound_menu','thiscall',None,ret=None,gen=gen)
