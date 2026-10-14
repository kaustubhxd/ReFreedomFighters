"""specs_s948.py - area 56 residue 15, claim A7: ZFFActor::Load2() (0x5a0af0).

The object is 0xa00 random bytes (the fields used reach +0x929), with a fake vtable whose slot 0x678 logs and returns a random
dword. The engine object M (global+0x9b) has slot 0x58 (logs its argument; returns R). R has slot 0x100 (logs its argument;
returns a random dword). The global at 0x7003b8 is a heap object. The exe helpers 0x4790e0, 0x5a04f0 and 0x5a0290 (thiscall,
no arguments) and 0x589fd0 (one argument) are GUESS recording stubs: they log their object and argument. All unverified."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    v678 = rng.getrandbits(32)
    r100 = [rng.getrandbits(32), rng.getrandbits(32)]
    ctr = {'i': 0}

    def h678(e2, r):
        e2.calllog.append(('Vt678',))
        e2.ret(eax=v678, argbytes=0)

    def h58(e2, r):
        e2.calllog.append(('M58', e2.arg32(0)))
        e2.ret(eax=robj, argbytes=4)

    def h100(e2, r):
        i = ctr['i'] % 2
        ctr['i'] += 1
        e2.calllog.append(('R100', e2.arg32(0)))
        e2.ret(eax=r100[i], argbytes=4)

    def hlog(name, argbytes):
        def h(e2, r):
            e2.calllog.append((name, e2.reg('ecx'), e2.arg32(0) if argbytes else None))
            e2.ret(eax=0 if not argbytes else rng.getrandbits(32), argbytes=argbytes)
        return h

    for addr, name, nb in ((0x4790e0, 'E4790e0', 0), (0x5a04f0, 'E5a04f0', 0), (0x5a0290, 'E5a0290', 0), (0x589fd0, 'E589fd0', 4)):
        e.hook(addr, hlog(name, nb))

    robj = e.fake_object('load2_r', 0x40, slots={0x100: h100})
    m = e.fake_object('load2_m', 0x40, slots={0x58: h58})
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, m)
    e.w32(0x70039c, g)
    g2 = _rnd(c, 0x40)
    e.w32(0x7003b8, g2)
    this = e.fake_object('load2_this', 0xa00, slots={0x678: h678})
    e.wbytes(this + 4, bytes(rng.getrandbits(8) for _ in range(0xa00 - 4)))
    return [this]


S(0x5a0af0, 'ZFFActor::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A7; all calls are GUESS recording stubs (unverified)')
