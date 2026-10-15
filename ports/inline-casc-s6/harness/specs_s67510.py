"""specs_s67510.py - cascade s6 batch 67510 (0x6526e0, thiscall(cls, name, style, exstyle, rect, parent) ret 0x1c, returns al). IAT slots are logging stubs (callee pops): AdjustWindowRectEx
0x676218 (4 args, grows the rect in place and logs it), GetClassInfo 0x67618c (3 args, found or not), LoadIcon 0x676248 / LoadCursor 0x6761cc (2), GetStockObject 0x676034 (1),
RegisterClassEx 0x676188 (1, logs the 12-dword class; the answer may have a zero low half), CreateWindowEx 0x676190 (12), SetWindowLong 0x6761fc (3)."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def _g6526e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    found = r.random() < 0.4
    deltas = [r.randrange(-40, 40) for _ in range(4)]

    def adj(em, res_):
        rp = em.arg32(0)
        vals = [em.r32(rp + 4 * i) for i in range(4)]
        em.calllog.append(('adj', tuple(vals), em.arg32(1), em.arg32(2), em.arg32(3)))
        for i in range(4):
            em.w32(rp + 4 * i, (vals[i] + deltas[i]) & 0xffffffff)
        em.ret(eax=1, argbytes=16)
    e.w32(0x676218, e.stub_fn('Adjust', adj))
    e.w32(0x67618c, pystub(c, 3, stackmark=(2,), ret=lambda em, k: 1 if found else 0))
    hv = [r.getrandbits(32) for _ in range(3)]
    e.w32(0x676248, pystub(c, 2, ret=hv[0]))
    e.w32(0x6761cc, pystub(c, 2, ret=hv[1]))
    e.w32(0x676034, pystub(c, 1, ret=hv[2]))
    reg_ok = r.random() < 0.75
    reg_val = r.choice([1, 0x10001, 0x5555]) if reg_ok else r.choice([0, 0x10000, 0xabcd0000])

    def regclass(em, res_):
        wp = em.arg32(0)
        em.calllog.append(('wc', tuple(em.r32(wp + 4 * i) for i in range(12))))
        em.ret(eax=reg_val, argbytes=4)
    e.w32(0x676188, e.stub_fn('RegisterClassEx', regclass))
    e.w32(0x676190, pystub(c, 12, ret=lambda em, k: r.getrandbits(32), side=lambda em, k: em.calllog.append(('cw', em.r32(0x725824)))))
    e.w32(0x6761fc, pystub(c, 3, ret=lambda em, k: r.getrandbits(32)))
    this = rnd(c, 0x140)
    rect = e.alloc(0x10, 4)
    for i in range(4):
        e.w32(rect + 4 * i, r.randrange(-100, 1200) & 0xffffffff)
    cls = 0 if r.random() < 0.6 else rnd(c, 0x10)
    return [this, cls, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), rect, r.getrandbits(32), r.getrandbits(32)]


S(0x6526e0, 'GUESS create_window', 'thiscall', None, ret='al', gen=_g6526e0, note='batch67510')
