from pilot import S,F
from recruits_util import rnd,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x40);n=r.randrange(0,24);pixels=rnd(c,max(4,n*4))
 for i in range(n):e.w32(pixels+i*4,r.choice([r.getrandbits(32),0,0xffffffff,0xff000000,0xff0000,0xff00,0xff,0x808080]))
 e.w32(me+0x2d,pixels);e.w32(me+0x32,n)
 return [me,F(r.choice([0.,-0.,1.,-1.,0.5,2.,10.,r.uniform(-4,4)]))]
S(0x636c30,'GUESS pixel saturation adjustment','thiscall',None,ret=None,gen=gen)
