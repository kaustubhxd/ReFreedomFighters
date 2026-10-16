"""specs_s237.py - ladder thread batch 237: ZLNKWHANDS constructor (base and ZTARGET ctors hooked; registrations logged)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _ctor(c):
    e, r = c.emu, c.rng
    for addr, name in ((0x468030, 'ZCTRLIKLNKOBJ::ctor'), (0x465650, 'ZTARGET::ctor')):
        def mk(name=name):
            def h(e2, res):
                e2.calllog.append((name, e2.reg('ecx'), tuple(K.nostack(e2.arg32(i)) for i in range(3 if 'CTRL' in name else 0))))
                e2.ret(argbytes=12 if 'CTRL' in name else 0)
            return h
        e.hook(addr, mk())
    eng = K.engine(c)
    d = K.rnd(c, 0x100)
    e.w32(eng + 0x9b, d)

    def reg(e2, a):
        msg = a[0]
        e2.calllog.append(('RegisterZMsg', msg, a[3]))
        return ((msg * 2654435761) >> 7) & 0xffff, None, None
    e.w32(d, K.vt(c, 'database', {0x114: (4, reg)}, nslots=0x60))
    return [K.rnd(c, 0x400), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x471b50, 'ZLNKWHANDS::ctor', 'thiscall', None, ret='eax', gen=_ctor, note='batch237')
