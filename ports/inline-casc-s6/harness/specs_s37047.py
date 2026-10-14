"""specs_s37047.py - cascade s6 batch 37047: 0x421940 (window creation). IAT slots are logging stubs (callee pops): 0x67618c (3 args, nonzero for the first n calls), 0x6761b4 (1),
0x6761cc (2), 0x676034 (1), 0x676188 (1, records the 12-dword class), 0x67609c (0), 0x6760ec (7), 0x676190 (12), 0x6761fc (3); 0x42ac56 hooked (cdecl, 3 args); the assert hook is set."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _g421940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x42ac56, 3, pop=0)
    n = r.choice([0, 1, 3, 5, 1000])
    sm = [r.choice([640, 1024, 1920, 0, -5, 1, 0x7fffffff, r.getrandbits(12)]) & 0xffffffff for _ in range(2)]

    def metrics(em, k):
        return sm[em.arg32(0) - 0x10]

    def regclass(em, res_):
        wp = em.arg32(0)
        em.calllog.append(('wc', tuple(em.r32(wp + 4 * i) for i in range(12))))
        em.ret(eax=(r.getrandbits(32) & 0xffff0000) if r.random() < 0.1 else r.getrandbits(32), argbytes=4)
    e.w32(0x67618c, pystub(c, 3, stackmark=(2,), ret=lambda em, k: 1 if k < n else 0, side=lambda em, k: em.calllog.append(('gci', em.r32(em.arg32(2))))))
    e.w32(0x6761b4, pystub(c, 1, ret=metrics))
    e.w32(0x6761cc, pystub(c, 2, ret=lambda em, k: r.getrandbits(32)))
    e.w32(0x676034, pystub(c, 1, ret=lambda em, k: r.getrandbits(32)))
    e.w32(0x676188, e.stub_fn('RegisterClassEx', regclass))
    e.w32(0x67609c, pystub(c, 0, ret=lambda em, k: r.getrandbits(32)))
    e.w32(0x6760ec, pystub(c, 7, stackmark=(4,), ret=lambda em, k: r.getrandbits(32)))
    e.w32(0x676190, pystub(c, 12, ret=lambda em, k: 0 if r.random() < 0.15 else r.getrandbits(32)))
    e.w32(0x6761fc, pystub(c, 3, ret=lambda em, k: r.getrandbits(32)))
    me = rnd(c, 0xa00)
    return [me]


S(0x421940, 'GUESS create main window', 'thiscall', None, ret='al', gen=_g421940, note='batch37047')
