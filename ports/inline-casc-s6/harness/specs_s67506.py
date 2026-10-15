"""specs_s67506.py - cascade s6 batch 67506 (0x50b860, stdcall(a) ret 4). Hooked 0x5003d0 (call order: result node, argument 1, argument 0, argument 1 again), 0x5002f0, 0x441730,
0x440530 (the helpers get ecx = 0x69d8f0); table slots 0x58 (object per call or none), 0x114 (4 args, id with random high bits); the first object answers slot 0x1e0 and has a name
at +4; the target has callee-pops slot 0x130 (explicit this + 2 args); the logger logs each error (2 or 3 args)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g50b860(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg(em, res_):
        n = 3 if em.arg32(1) == 0x69d5fc else 2
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(1, n))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    first_ok = r.random() < 0.9
    kind_ok = r.random() < 0.8
    target_ok = r.random() < 0.85
    first = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: 1 if kind_ok else 0)})
    _w(c, first + 4, r.getrandbits(32))
    target = obj(c, 0x40, {0x130: pystub(c, 3, ret=0)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: (first if first_ok else 0) if k == 0 else (target if target_ok else 0)),
                           0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x130)
    nodes = [rnd(c, 0x10) for _ in range(3)]
    res = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: [res, nodes[0], nodes[1], nodes[2]][min(k, 3)])
    hook_rec(c, 0x5002f0, 1, this=True)
    hook_rec(c, 0x441730, 0, this=True)
    hook_rec(c, 0x440530, 0, this=True)
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    _w(c, a + 8, rnd(c, 0x10))
    return [a]


S(0x50b860, 'GUESS send_command', 'stdcall', None, ret=None, gen=_g50b860, note='batch67506')
