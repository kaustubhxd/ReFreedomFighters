"""specs_s37011.py - cascade s6 batch 37011: 0x421b40 (window procedure, stdcall 4 args). IAT stubs (logged, callee pops): 0x67619c (7 args), 0x676198 (2), 0x6761c8 (1), 0x6761bc (4),
0x676200 DefWindowProc (4, random result). 0x533b80 hooked. Objects at 0x700390 (slots 0x10, 0x1c), 0x7003a0 (0x54, 0x58), engine +0x190f (slot 0x200)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g421b40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    e.w32(0x67619c, pystub(c, 7, ret=lambda em, k: r.getrandbits(32)))
    e.w32(0x676198, pystub(c, 2, ret=lambda em, k: r.getrandbits(32)))
    e.w32(0x6761c8, pystub(c, 1))
    e.w32(0x6761bc, pystub(c, 4, ret=lambda em, k: r.getrandbits(32)))
    e.w32(0x676200, pystub(c, 4, ret=lambda em, k: r.getrandbits(32)))
    hook_rec(c, 0x533b80, 0, this=True)
    cur = r.choice([0x10, 0x113, 0x400, 6, 7, 2])
    msg = r.choice([cur, cur, 6, 6, 7, 8, 2, 0x112, 0x112, 0x10, 0x100, 0x20, r.getrandbits(32)])
    if msg == 0x112:
        wp = r.choice([0x1000, 0xf120, 0xf060, r.getrandbits(32)])
    elif msg == 6:
        wp = r.choice([0, 0, 1, 2, 0x10000, 0x10001, r.getrandbits(32)])
    else:
        wp = r.getrandbits(32)
    if r.random() < 0.06:
        e.w32(0x700390, 0)
    else:
        lg = obj(c, 0x40, {0x10: pystub(c, 0, this=True, ret=cur), 0x1c: pystub(c, 3, this=True, ret=lambda em, k: r.getrandbits(32))})
        e.w32(0x700390, lg)
    if r.random() < 0.85:
        e.w32(0x7003a0, obj(c, 0x20, {0x54: pystub(c, 0, this=True), 0x58: pystub(c, 0, this=True)}))
    else:
        e.w32(0x7003a0, 0)
    so = sysobj(c, slots={0x16c: pystub(c, 0, this=True)})
    e.wbytes(so + 0x63, bytes([r.choice([0, 1, 7])]))
    e.wbytes(so + 0x1b48, bytes([r.choice([0, 1, 5])]))
    e.wbytes(so + 0x1a9f, (rnd(c, 0x10) if r.random() < 0.7 else 0).to_bytes(4, 'little'))
    h = obj(c, 0x220, {0x200: pystub(c, 3, this=True, ret=lambda em, k: r.getrandbits(32))}) if r.random() < 0.6 else 0
    e.wbytes(so + 0x190f, h.to_bytes(4, 'little'))
    return [r.getrandbits(32), msg, wp, r.getrandbits(32)]


S(0x421b40, 'GUESS window procedure', 'stdcall', None, ret='eax', gen=_g421b40, note='batch37011')
