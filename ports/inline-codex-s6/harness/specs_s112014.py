from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec
from pe_emu import REGS

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 start=r.choice([0,0xfffffff0,0xffffffff,0x100000010]);step=r.choice([0,1,10,100]);calls=rnd(c,4);e.w32(calls,0)
 def clock(em,res):
  k=em.r32(calls);em.w32(calls,k+1);t=start+step*k
  em.calllog.append(('clock',em.arg32(0),em.arg32(1)));em.mu.reg_write(REGS['edx'],t>>32);em.ret(t&0xffffffff,8)
 sysobj(c,{0x1c8:e.stub_fn('clock',clock)})
 me=rnd(c,0x8280);limit=r.choice([-1,0,10,100]);n=r.randrange(0,7);rd=r.choice([0,0x1ffe,0x1fff]);wr=(rd+n)%0x2000
 for j in range(n):
  p=rnd(c,16);e.w32(p,r.choice([-1,0,10,101])&0xffffffff);e.wbytes(p+5,bytes([r.randrange(2)]));e.w32(me+0x270+4*((rd+j)%0x2000),p if r.randrange(5) else 0)
 e.w32(me+0x268,me+0x270+4*wr);e.w32(me+0x26c,me+0x270+4*rd)
 item=rnd(c,16);e.wbytes(item+1,bytes([r.randrange(4)]))
 hook_rec(c,e.r32(0x6c2784+0x2c),1,this='mark',ret=item)
 hook_rec(c,0x64ba70,1,this=True);hook_rec(c,0x63e480,1,this=True)
 for j in range(1,4):e.w32(me+0x68+4*j,rnd(c,16))
 return [me,r.choice([0,1,10,100]),limit&0xffffffff]
S(0x63cc50,'GUESS drain_resource_ring','thiscall',None,ret=None,gen=gen)
