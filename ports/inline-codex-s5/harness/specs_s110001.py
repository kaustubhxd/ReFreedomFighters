"""specs_s218.py - ladder thread batch 218: ZFFActionUseHealth::CallBack."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K
from recruits_util import clear_hooks, pystub, _HOOKED


def _uh(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32)))

    def hk(addr, name, n, ab, st0=None):
        def h(e2, res):
            e2.calllog.append((name, e2.reg('ecx'), tuple(e2.arg32(i) for i in range(n))))
            e2.ret(argbytes=ab, st0=st0)
        e.hook(addr, h)
        _HOOKED.add(addr)
    hk(0x467410, 'fn467410', 6, 0x18)
    hk(0x59a580, 'MessageAdd', 3, 0xc)
    hk(0x5ab090, 'fn5ab090', 0, 0)
    hk(0x58b9c0, 'AdjustHitPoints', 3, 0xc, st0=1.5)
    owner = K.rnd(c, 0x2000)
    cam = r.getrandbits(32)
    e.w32(owner, K.vt(c, 'owner', {0x100: (1, lambda e2, a: (cam, None, None))}, nslots=0x60))
    if r.random() < 0.5:
        e.w32(owner + 0x85a, 0)
    mx = f32(r.choice([100.0, 50.0, 200.0]))
    e.wf32(owner + 0x7fb, mx)
    e.wf32(owner + 0x7ff, mx if r.random() < 0.3 else (float('nan') if r.random() < 0.05 else f32(r.uniform(0, 100))))
    osd = K.rnd(c, 0x2000)
    e.w32(owner + 0x852, osd if r.random() < 0.7 else 0)
    kit = K.rnd(c, 0x40)
    e.w32(kit, K.vt(c, 'kit', {0x2e8: (0, lambda e2, a: (0, None, None)), 0x2f4: (0, lambda e2, a: (owner, None, None)),
                              0x2d0: (2, lambda e2, a: (0, None, None)), 0x2f0: (3, lambda e2, a: (0, None, None)),
                              0x210: (1, lambda e2, a: (0, None, None))}, nslots=0x100))
    hand = K.rnd(c, 0x40)
    e.w32(hand, K.vt(c, 'hand', {0x10: (0, lambda e2, a: (kit, None, None)), 8: (2, lambda e2, a: (0, None, None))}, nslots=8))
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    e.w32(d, K.vt(c, 'database', {0x4c: (1, lambda e2, a: ((a[0] * 3 + 5) & 0xffffffff, None, None))}, nslots=0x40))
    txt = K.rnd(c, 0x10)
    e.w32(d + 0xae4, txt)
    e.w32(txt, K.vt(c, 'text', {0: (2, lambda e2, a: (0x6b74dc, None, None))}, nslots=4))
    s = K.rnd(c, 0x20)
    e.w32(s + 8, r.getrandbits(32))
    e.w32(s + 0xc, hand)
    e.w32(s + 0x14, r.choice([0x14, 0x15, 0x16, 0x13, 0x17, r.getrandbits(32)]))
    return [s]


S(0x5dfd00, 'ZFFActionUseHealth::CallBack', 'thiscall', None, ret='al', gen=_uh, note='batch218')
