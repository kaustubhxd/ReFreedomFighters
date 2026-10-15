from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def blend(c):
    clear_hooks(c); e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    cam=rnd(c,0xf00)
    for off in (0xd36,0xd87):
        vt=e.alloc(4,4)
        done=(r.getrandbits(24)<<8)|r.choice([0,1,0xff])
        e.w32(vt,pystub(c,0,ret=done,this=True));e.w32(cam+off,vt)
    for addr in (0x662c50,0x662f40):
        data=bytes(r.getrandbits(8) for _ in range(12))
        def write(em,k,data=data): em.wbytes(em.arg32(0),data)
        hook_rec(c,addr,1,this=True,deref={0:3},side=write,ret=r.getrandbits(32))
    mat=bytes(r.getrandbits(8) for _ in range(36))
    def create(em,k):
        em.calllog.append(('create',em.rbytes(em.reg('edx'),12)))
        em.wbytes(em.reg('ecx'),mat)
    hook_rec(c,0x4de040,1,side=create,ret=r.getrandbits(32))
    # Run real mcpy to exercise all nine stored matrix words.
    return [cam]
S(0x5cebc0,'GUESS_camera_focus_blend','thiscall',None,ret=None,gen=blend)
