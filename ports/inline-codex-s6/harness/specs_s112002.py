from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x8230);e.wbytes(me+0x1e9,bytes([r.randrange(2)]));e.wbytes(me+0x821b,bytes([r.randrange(2)]));e.w32(me+0x8220,rnd(c,16) if r.randrange(2) else 0)
 size=r.choice([0,1,15,16,17,31,0x1fffd0,0x1fffd1,r.randrange(1,1000)])
 length=r.choice([0,16,32,64,128,1024]);raw=rnd(c,0x1000);block=raw+16;owner=rnd(c,0x30)
 e.w32(owner+0x11,block);e.w32(block+8,length);e.w32(block+12,r.choice([0,1]));e.w32(block+16+length+12,r.choice([length,length,0xffffffff]));e.w32(block+16+length+8,r.choice([0,1]))
 hook_rec(c,0x4d0590,1,ret=owner,this=True);hook_rec(c,0x4d0c70,2,this=True)
 ret=r.choice([0,raw+0x900]);hook_rec(c,0x4d0840,2,ret=ret,this=True);hook_rec(c,0x4d08c0,2,ret=ret,this=True)
 malloc=rnd(c,0x100)
 def mh(em,res):
  em.calllog.append(('malloc',em.arg32(0)));em.ret(malloc,0)
 e.stub_import('malloc',mh)
 return [me,size]
S(0x4d0700,'GUESS allocate_aligned_block','thiscall',None,ret='eax',gen=gen)
