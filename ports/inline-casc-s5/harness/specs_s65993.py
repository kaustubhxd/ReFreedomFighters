import struct
import recruits_util as ru
from pilot import S
from recruits_util import rnd,clear_hooks

def gen(c):
    clear_hooks(c);e=c.emu;r=c.rng
    fb=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
    fl=lambda b:struct.unpack('<f',struct.pack('<I',b))[0]
    def vec():return [float(r.randrange(-5,6)) for _ in range(3)]
    def put(em,p,v):
        for i,x in enumerate(v):em.w32(p+4*i,fb(x))
    def read(em,p):return tuple(em.r32(p+4*i) for i in range(3))
    normal=vec();mode=r.randrange(5);point=vec()
    if mode==0:point=list(normal)
    elif mode in [1,2,3]:point=[-x for x in normal]
    me=e.alloc(0x18200,4)
    for k in range(4):
        corner=vec()
        if mode==1:corner=[10*x for x in normal]
        if mode==2:corner=[(-10 if k==r.randrange(4) else 10)*x for x in normal]
        if mode==3:corner=[-x for x in normal]
        put(e,me+0x181c9+12*k,corner)
    plane=rnd(c,16);out=rnd(c,48);mat=rnd(c,48);shift=rnd(c,12);inp=rnd(c,48)
    put(e,shift,[0,0,0])
    for k in range(4):put(e,inp+12*k,vec())
    count=[0];subcount=[0]
    def sub(em,_):
        em.calllog.append(('sub',read(em,em.reg('edx')),read(em,em.arg32(0))))
        subcount[0]+=1
        put(em,em.reg('ecx'),[subcount[0],2,3]);em.ret(argbytes=4)
    def cross(em,_):
        em.calllog.append(('cross',em.reg('ecx'),read(em,em.reg('edx')),read(em,em.arg32(0))))
        put(em,em.reg('ecx'),normal);em.ret(argbytes=4)
    def rotate(em,_):
        em.calllog.append(('rotate',em.reg('ecx'),em.reg('edx'),read(em,em.reg('ecx'))))
        put(em,em.reg('ecx'),normal);em.ret()
    def transform(em,_):
        k=count[0];count[0]+=1
        em.calllog.append(('transform',em.reg('ecx'),em.reg('edx'),read(em,em.reg('edx')),em.arg32(0)))
        put(em,em.reg('ecx'),point if k==0 else [k,k+1,k+2]);em.ret(argbytes=4)
    def add(em,_):
        dst=em.reg('ecx');src=em.reg('edx')
        em.calllog.append(('add',dst,src,read(em,dst),read(em,src)))
        put(em,dst,[fl(em.r32(dst+4*i))+fl(em.r32(src+4*i)) for i in range(3)]);em.ret()
    for addr,h in [(0x43e920,sub),(0x446ee0,cross),(0x4419f0,rotate),(0x441970,transform),(0x441940,add)]:
        e.hook(addr,h);ru._HOOKED.add(addr)
    return [me,plane,out,mat,shift,inp]
S(0x64cb10,'GUESS transform quad and reject by plane','thiscall',None,ret='al',gen=gen,nan_heap=True,note='batch65993')
