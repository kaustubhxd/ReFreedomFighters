"""specs_s37020.py - cascade s6 batch 37020: 0x619e70. Hooked: 0x441730, 0x440530, 0x610f20, 0x610e20, 0x6107e0, 0x610070, 0x611710, 0x61a6b0 (fastcall, ecx and edx
recorded). Device (arg 2) slots 0x29c/0x28c (thiscall, 3 args); global device at [0x724a00] has stdcall slots 0xc8/0x130/0x14c/0x154; cache words at 0x724948,
0x7249f8, 0x724970, 0x7249b0, 0x7249f0, 0x7249f4 start equal to the compared constants or random."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g619e70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x441730, 0, this=True)
    hook_rec(c, 0x440530, 0, this=True)
    for a in (0x610f20, 0x610e20, 0x6107e0, 0x610070, 0x611710):
        hook_rec(c, a, 1, this=True)

    def h61(em, res_):
        em.calllog.append(('f61a6b0', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=0, argbytes=0)
    e.hook(0x61a6b0, h61)
    # global device
    gdev = obj(c, 0x20, {0xc8: pystub(c, 3), 0x130: pystub(c, 2), 0x14c: pystub(c, 4), 0x154: pystub(c, 3)})
    e.w32(0x724a00, gdev)
    e.w32(0x724948, r.choice([1, 0, 2]))
    e.w32(0x7249f8, r.choice([0x152, 0x152, 0, 5]))
    ed = r.getrandbits(32)
    e.w32(0x724970, ed)
    e.w32(0x7249b0, r.choice([0x24, 0x24, 7]))
    # objects
    esiO = obj(c, 0x40, {0x8: pystub(c, 0, this=True)})
    e.w32(esiO + 0x30, r.choice([0, 0, 3]))
    sv = r.choice([ed, ed, r.getrandbits(32)])
    e.w32(esiO + 0x2c, sv)
    ediO = obj(c, 0x40, {0x8: pystub(c, 0, this=True)})
    e.w32(ediO + 0x18, r.choice([0, 0, 5]))
    ev = r.getrandbits(32)
    e.w32(ediO + 0x14, ev)
    z28 = r.getrandbits(32)
    e.w32(0x7249f0, r.choice([ev, ev, r.getrandbits(32)]))
    e.w32(0x7249f4, r.choice([z28, z28, r.getrandbits(32)]))
    dev = obj(c, 0x1420, {0x29c: pystub(c, 3, this=True), 0x28c: pystub(c, 3, this=True)})
    e.wbytes(dev + 0x115f, bytes([r.choice([0, 2, 3, 1])]))
    e.wbytes(dev + 0x13fa, esiO.to_bytes(4, 'little'))
    e.wbytes(dev + 0x140a, ediO.to_bytes(4, 'little'))
    # this
    Y = rnd(c, 0x50)
    W = rnd(c, 0x20)
    e.w32(W + 8, Y)
    Z = rnd(c, 0x40)
    e.w32(Z + 4, W)
    e.w32(Z + 0x28, z28 if r.random() < 0.9 else 0)
    if r.random() < 0.15:
        e.w32(Z + 0x14, 0)
    else:
        e.w32(Z + 0x14, r.getrandbits(32) | 1)
    me = rnd(c, 0x20)
    e.w32(me + 4, Z)
    # p
    q = rnd(c, 0x20)
    e.wbytes(q + 5, bytes([r.choice([0, 4, 5, 0xff])]))
    e.w32(q + 0xc, r.choice([0, rnd(c, 0x40)]))
    e.w32(q + 8, rnd(c, 0x40))
    p = rnd(c, 0x40)
    e.wbytes(p + 5, bytes([r.choice([0, 4, 5, 0xff])]))
    e.w32(p + 0x14, q)
    e.w32(p + 0xc, r.choice([0, 0, rnd(c, 0x40)]))
    return [me, p, dev]


S(0x619e70, 'GUESS draw batch with cached device state', 'thiscall', None, ret=None, gen=_g619e70, note='batch37020')
