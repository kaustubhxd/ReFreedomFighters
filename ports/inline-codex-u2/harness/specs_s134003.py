from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def put(p,vs):e.wbytes(p,struct.pack('<'+'f'*len(vs),*vs))
 rect=[r.uniform(-2,2),r.uniform(-2,2),r.choice([0.1,1,2,0.5]),r.choice([0.1,1,2,0.5])]
 def rectangle(em,k):em.wbytes(em.arg32(0),struct.pack('<4f',*rect))
 viewport=obj(c,0x40,{0:pystub(c,0,this=True,ret=r.choice([1,640,1920,0x7fffffff,0x80000000])),4:pystub(c,0,this=True,ret=r.choice([1,480,1080,0x7fffffff,0x80000000]))})
 camera=obj(c,0x280,{0x240:pystub(c,1,this=True,nullflag=(0,),side=rectangle)})
 put(camera+0x58,[r.choice([1,0.25,-1,10])]);me=rnd(c,0x80);put(me+0x22,[r.choice([0,-0.,0.5,-0.25,1,2]),r.choice([0,-0.,0.5,-0.25,1,2])]);put(me+0x3e,[r.uniform(-10,10),r.uniform(-10,10)])
 matrix=rnd(c,36);put(matrix,[r.uniform(-20,20) for _ in range(9)]);inp=rnd(c,12);put(inp,[r.uniform(-100,100),r.uniform(-100,100),r.uniform(1,100)])
 out=rnd(c,12);scale=rnd(c,12);matout=rnd(c,36);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,viewport,camera,matrix,inp,out,scale,matout]
S(0x4eed30,'GUESS project UI position and scale','thiscall',None,ret=None,gen=gen)
