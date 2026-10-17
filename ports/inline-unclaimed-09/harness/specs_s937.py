"""specs_s937.py - unclaimed-09 batch 29 (docs/20-unclaimed-09.md, claim 31): CRigidBody::Setup2() (GUESS name).

The object is 0x200 random bytes; this+0x44 points to a sub-object whose +8 is a second object (both heap, 0x40 random
bytes). GUESS recording stubs (unverified callees, all hooked): 0x53eaa0 (logs ecx, returns a random dword); 0x53f630,
0x53f770, 0x53f980 (log ecx); 0x4db500 (writes 12 random bytes at its pointer; logs them); 0x43e960 (fastcall; logs ecx and the
12 bytes at edx); 0x4dc630 (logs ecx and its two arguments). The stack pointers are never logged."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)
    twelve = bytes(rng.getrandbits(8) for _ in range(12))

    def h53eaa0(e2, r):
        e2.calllog.append(('E53eaa0', e2.reg('ecx')))
        e2.ret(eax=rv, argbytes=4)

    def h_log(name):
        def h(e2, r):
            e2.calllog.append((name, e2.reg('ecx')))
            e2.ret(argbytes=0)
        return h

    def h4db500(e2, r):
        p = e2.arg32(0)
        e2.w8  # noqa: keep the attribute lookup cheap
        e2.wbytes(p, twelve)
        e2.calllog.append(('Db500', e2.reg('ecx'), twelve))
        e2.ret(argbytes=4)

    def h43e960(e2, r):
        e2.calllog.append(('E43e960', e2.reg('ecx'), bytes(e2.rbytes(e2.reg('edx'), 12))))
        e2.ret(argbytes=0)

    def h4dc630(e2, r):
        e2.calllog.append(('Dc630', e2.reg('ecx'), e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    for addr, h in ((0x53eaa0, h53eaa0), (0x53f630, h_log('F53f630')), (0x53f770, h_log('F53f770')),
                    (0x53f980, h_log('F53f980')), (0x4db500, h4db500), (0x43e960, h43e960), (0x4dc630, h4dc630)):
        e.hook(addr, h)

    sub_obj = _rnd(c, 0x40)
    inner = _rnd(c, 0x40)
    e.w32(sub_obj + 8, inner)
    this = _rnd(c, 0x200)
    e.w32(this + 0x44, sub_obj)
    return [this]


S(0x540bc0, 'CRigidBody::Setup2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  heap_mask=lambda c: [(c.args[0] + 0x14e, 4)],
  note='unclaimed-09 b29; GUESS name; GUESS recording stubs for the seven callees; heap_mask on this+0x14e (stack-local pointer)')
