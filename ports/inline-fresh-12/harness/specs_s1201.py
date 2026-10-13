"""specs_s1201.py - fresh slice 12, batch 1 (15 small leaves and wrappers). Exe callees are hooked by address and logged
(this, stack args); virtual calls go to logging vtables whose results are drawn from the case rng."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _rand_obj(c, n):
    a = c.emu.alloc(n, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hk(addr, name, nargs, retfn=None):
    def h(em, r):
        args = tuple(em.arg32(k) for k in range(nargs))
        em.calllog.append((name, 0, em.reg('ecx'), args))
        em.ret(eax=retfn(em) if retfn else 0x1234abcd ^ addr, argbytes=4 * nargs)
    return h


def _hk_cdecl(addr, name, nargs):
    def h(em, r):
        em.calllog.append((name, 0, 0, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=0x5eed0000 ^ addr, argbytes=0)
    return h


def _obj(n):
    def g(c):
        o = _rand_obj(c, n)
        c.emu.mu.ctl_flush_tb()
        return [o]
    return g


S(0x638c80, 'FUN_00638c80 get dword this+0x29', 'thiscall', None, ret='eax', gen=_obj(0x40))
S(0x615000, 'FUN_00615000 clear byte this+4', 'thiscall', None, ret=None, gen=_obj(0x10))
S(0x603d00, 'FUN_00603d00 return 0x6b91c8', 'thiscall', None, ret='eax', gen=_obj(0x10))
S(0x614ec0, 'FUN_00614ec0 return 0x8c', 'thiscall', None, ret='eax', gen=_obj(0x10))


def _g654700(c):
    o = zero_obj(c, 0x1200)
    c.emu.w8(o + 0x11e7, c.rng.choice([0, 1, c.rng.getrandbits(8)])) if hasattr(c.emu, 'w8') else \
        c.emu.wbytes(o + 0x11e7, bytes([c.rng.choice([0, 1, c.rng.getrandbits(8)])]))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x654700, 'FUN_00654700 get byte this+0x11e7', 'thiscall', None, ret='al', gen=_g654700)


def _g613340(c):
    o = zero_obj(c, 0x22010)
    c.emu.w32(o + 0x22008, c.rng.choice([0, 0, 1, 0x80000000, c.rng.getrandbits(32)]))
    c.emu.w32(o + 0x22004, c.rng.getrandbits(32))
    c.emu.w32(o + 0x2200c, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x613340, 'FUN_00613340 dword this+0x22008 != 0', 'thiscall', None, ret='al', gen=_g613340)


def _g63b840(c):
    v = c.rng.getrandbits(32)
    o = logged_obj(c, 'Obj', 0x40, impl={0x20: lambda e, a: (v, None)})
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x63b840, 'FUN_0063b840 slot 0x20 << 12', 'thiscall', None, ret='eax', gen=_g63b840)


def _g656f00(c):
    buf = _rand_obj(c, 0x20)
    o = logged_obj(c, 'Obj', 0x40, impl={0xc: lambda e, a: (buf, None)}, argwords={0xc: 1})
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x656f00, 'FUN_00656f00 u16 at slot0xc(arg)+0xe / 3', 'thiscall', None, ret='eax', gen=_g656f00)


def _g655380(c):
    v1, v2 = c.rng.getrandbits(32), c.rng.getrandbits(32)
    o = logged_obj(c, 'Obj', 0x40, impl={0xc8: lambda e, a: (v1, None), 0x90: lambda e, a: (v2, None)},
                   argwords={0x90: 1})
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x655380, 'FUN_00655380 slot 0xc8 then slot 0x90(arg)', 'thiscall', None, ret='eax', gen=_g655380)


def _g656780(c):
    v1, v2 = c.rng.getrandbits(32), c.rng.getrandbits(32)
    o = logged_obj(c, 'Obj', 0x60, impl={0xc: lambda e, a: (v1, None), 0x150: lambda e, a: (v2, None)},
                   argwords={0xc: 1, 0x150: 2})
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x656780, 'FUN_00656780 slot 0x150(b, slot 0xc(a)); true', 'thiscall', None, ret='al', gen=_g656780)


def _g659ac0(c):
    me = _rand_obj(c, 0x20)
    v = c.rng.getrandbits(32)
    h = logged_obj(c, 'Handler', 0x10, impl={4: lambda e, a: (v, None)}, argwords={4: 2})
    q = _rand_obj(c, 0x20)
    c.emu.w32(q + 0x14, h if c.rng.random() < 0.7 else 0)
    p = _rand_obj(c, 0x20)
    c.emu.w32(p + 0x10, q)
    c.emu.mu.ctl_flush_tb()
    return [me, p]


S(0x659ac0, 'FUN_00659ac0 p+0x18 = (p+0x10)->+0x14->slot4(p, this)', 'thiscall', None, ret='eax', gen=_g659ac0)


def _s63eb80(c):
    c.emu.hook(0x63eb40, _hk(0x63eb40, 'f63eb40', 0, lambda em: em.reg('ecx') ^ 0x77))


def _g63eb80(c):
    o = _rand_obj(c, 0x80)
    c.emu.w32(o + 0x60, c.rng.choice([0, _rand_obj(c, 0x10), c.rng.getrandbits(32)]))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x63eb80, 'FUN_0063eb80 0x63eb40(this->+0x60)', 'thiscall', None, ret='eax', gen=_g63eb80, setup=_s63eb80,
  note='0x63eb40 hooked (GUESS-free: logged this, returns ecx^0x77)')


def _s659c00(c):
    c.emu.hook(0x4ce1c0, _hk(0x4ce1c0, 'f4ce1c0', 2, lambda em: em.arg32(0) ^ em.arg32(1)))


def _g659c00(c):
    o = _rand_obj(c, 0x10)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 4, 0)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x659c00, 'FUN_00659c00 release handle this+4 via 0x4ce1c0', 'thiscall', None, ret='eax', gen=_g659c00,
  setup=_s659c00, note='0x4ce1c0 hooked, ret 8')


def _sdd(base):
    def s(c):
        c.emu.hook(base, _hk(base, 'base_dtor', 0, lambda em: 0x600d0000 ^ em.reg('ecx')))
        c.emu.hook(0x634273, _hk_cdecl(0x634273, 'delete_sized', 2))
    return s


def _gdd(c):
    o = _rand_obj(c, 0x80)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x54fd00, 'FUN_0054fd00 scalar deleting dtor (size 0x6d)', 'thiscall', None, ret='eax', gen=_gdd, setup=_sdd(0x54fb70))
S(0x5f14c0, 'FUN_005f14c0 scalar deleting dtor (size 0x15)', 'thiscall', None, ret='eax', gen=_gdd, setup=_sdd(0x602240))
