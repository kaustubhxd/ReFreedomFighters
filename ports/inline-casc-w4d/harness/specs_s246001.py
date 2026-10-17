"""specs_s246001.py - w4d batch 246001: 0x496350, 0x4d9230."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g496350(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    this = rnd(c, 0x20)
    O = rnd(c, 0x20)
    VT = rnd(c, 0x40)
    em.w32(this + 8, O)
    em.w32(O, VT)
    em.w32(VT + 0x14, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True,
                             side=lambda emu, k: emu.calllog.append(('v14', emu.reg('ecx') - O, emu.arg32(0)))))
    flags = r.choice([0, 0, 0x40000000, 0x40000001, 0xc0000000, 1, 0x3fffffff, r.getrandbits(32), r.getrandbits(32) & ~0x40000000])
    return [this, flags]


def g4d9230(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    THIS = rnd(c, 0x20)
    n = r.choice([0, 1, 2, 5, 12, 30, 80])
    alpha = b'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@[`{0123456789 _'
    txt = bytes(r.choice(alpha) if r.random() < 0.8 else r.randrange(1, 256) for _ in range(n))
    cs = rnd(c, 0x60)
    em.wbytes(cs, txt + b'\0')
    heaps = []
    sr = [seh_record(c, 2) for _ in range(4)]

    def mk(j):
        def f(emu, k):
            sr[j](emu, k)
        return f

    def s630(emu, k, _s=mk(0)):
        obj = emu.reg('ecx'); src = emu.arg32(0)
        t = emu.rbytes(src, 100).split(b'\0')[0] + b'\0'
        emu.calllog.append(('asg', src == cs, t.hex()))
        if r.random() < 0.5 and len(t) <= 0x70:
            nb = obj + 4
        else:
            nb = rnd(c, 0x90); heaps.append(nb)
        emu.wbytes(nb, t)
        emu.w32(obj, nb)
        _s(emu, k)
    hook_rec(c, 0x4cc630, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=s630)

    def s9190(emu, k, _s=mk(1)):
        p, n_ = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('f9190', emu.reg('ecx') - THIS, n_, emu.rbytes(p, 100).split(b'\0')[0].hex(), heaps.index(p) if p in heaps else -1))
        _s(emu, k)
    hook_rec(c, 0x4d9190, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this='mark', stackmark=(0,), side=s9190)

    def s273(emu, k, _s=mk(2)):
        a = emu.arg32(0)
        emu.calllog.append(('free', heaps.index(a) if a in heaps else -1, emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, stackmark=(0,), side=s273)
    return [THIS, cs]


S(0x496350, 'GUESS FUN_496350', 'thiscall', None, ret='al', gen=g496350, note='batch246001')
S(0x4d9230, 'GUESS FUN_4d9230', 'thiscall', None, ret=None, gen=g4d9230, note='batch246001')
