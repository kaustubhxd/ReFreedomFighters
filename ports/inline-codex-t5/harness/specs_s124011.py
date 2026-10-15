from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def g(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x26b0)
 nested=obj(c,16,{4:pystub(c,2,this=True,deref={0:3,1:3})})
 e.w32(me+0x2695,e.r32(nested))
 vec=rnd(c,12)
 # Real scaling callee; finite values plus deliberate zero and NaN branches.
 values=r.choice([[0.,0.,0.],[1.,0.,0.],[0.,0.,1.],[float('nan'),0.,1.],[r.uniform(-100,100),r.uniform(-100,100),r.uniform(-100,100)]])
 e.wbytes(vec,struct.pack('<3f',*values));e.wbytes(me+0x2f0,struct.pack('<f',r.choice([0.,1.,-1.,2.,r.uniform(-10,10)])))
 return [me,vec]
S(0x520e40,'GUESS set hull direction','thiscall',None,ret=None,gen=g,nan_heap=True,note='batch124011')
