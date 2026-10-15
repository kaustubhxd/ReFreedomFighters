from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 ctx=rnd(c,0x280);node=rnd(c,0x1c);buf=rnd(c,0x100);newbuf=rnd(c,0x100)
 text=rnd(c,0x80);data=bytes(r.randrange(65,91) for _ in range(r.randrange(0,64)))+b'\0';e.wbytes(text,data)
 e.wbytes(ctx+0x268,bytes([r.choice([0,1,10,13])]))
 e.w32(node+0x10,buf);e.w32(node+0x18,r.choice([0,8,64,128]));e.w32(ctx+0x210,node if r.randrange(2) else 0)
 def alloc(em,k):return (node if k==0 else buf) if rfail!=k else 0
 rfail=r.choice([-1,-1,0,1])
 e.w32(ctx+0xc,pystub(c,1,pop=0,ret=alloc));e.w32(ctx+0x10,pystub(c,2,pop=0,ret=newbuf if r.randrange(4) else 0));e.w32(ctx+0x14,pystub(c,1,pop=0));e.w32(ctx+0x64,pystub(c,3,pop=0) if r.randrange(2) else 0)
 parent=ctx+0x1dc if r.randrange(2) else rnd(c,8);lst=rnd(c,4)
 def memcpy(em,k):
  em.wbytes(em.arg32(0),em.rbytes(em.arg32(1),em.arg32(2)))
 hook_rec(c,0x634d22,3,pop=0,side=memcpy)
 return [ctx,parent,r.getrandbits(32),text,lst]
S(0x61c660,'GUESS insert_text_node','cdecl',None,ret='eax',gen=gen)
