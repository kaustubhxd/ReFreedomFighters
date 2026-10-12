"""specs_s307.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md), batch 307: six small forwarders and setters. Exe
helpers: 0x41e2c0 (free: a GUESS recording stub), 0x61be80 and 0x61bb20 (run as original code), the engine's object table at
0x724278 (+0x3c) with a logged slot 0 for the word-returning calls."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _free(c):
    e = c.emu

    def h(em, r):
        em.calllog.append(('free41e2', 0x41e2c0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    e.hook(0x41e2c0, h)
    p = c.rng.choice([0, _rnd(c, 0x20)])
    return [p]


def _eng_setup(c, retv):
    e = c.emu
    o_vt = e.logging_vtable('obj6044', 0x2, impl={0: lambda em, a: (retv, None)}, argwords={0: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, o_vt)
    holder = _rnd(c, 0x80)
    e.w32(holder + 0x3c, obj)
    e.w32(0x724278, holder)


def _store(c):
    e = c.emu
    _eng_setup(c, c.rng.randrange(0, 0x40))
    self_ = _rnd(c, 0x40)
    return [self_, c.rng.getrandbits(32)]


def _clear(c):
    e = c.emu
    _eng_setup(c, c.rng.randrange(0, 0x40))
    self_ = _rnd(c, 0x40)
    table = _rnd(c, 0x1000)                  # indices below 0x40 (the word from slot 0 is small)
    e.w32(self_ + 8, table)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _forward4(c):
    e = c.emu
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 4, c.rng.getrandbits(32))
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _forward5(c):
    e = c.emu
    vt = e.logging_vtable('obj61bd', 0x1d + 1, impl={}, argwords={0x1c: 5})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt)
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _init(c):
    e = c.emu

    def h(em, r):
        em.calllog.append(('ext61bb20', 0x61bb20, (em.reg('ecx'),)))
        em.ret(eax=0, argbytes=0)

    e.hook(0x61bb20, h)
    self_ = _rnd(c, 0x40)
    return [self_, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])]


def _ext4(c):
    e = c.emu
    def h(em, r):
        em.calllog.append(('ext61be', 0x61be80, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0x1234, argbytes=0)
    e.hook(0x61be80, h)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 4, c.rng.getrandbits(32))
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x601570, 'freeIf (GUESS)', 'stdcall', None, ret=None, gen=_free, note='batch307; ret 4; 0x41e2c0 recorded')
S(0x61bbf0, 'forward4 (GUESS)', 'thiscall', None, ret='eax', gen=_ext4, note='batch307; ret 0xc; 0x61be80 recorded')
S(0x61bd00, 'forward5 (GUESS)', 'cdecl', None, ret='eax', gen=_forward5, note='batch307; plain ret')
S(0x6044f0, 'storeWord (GUESS)', 'thiscall', None, ret=None, gen=_store, note='batch307; ret 4')
S(0x604540, 'clearSlot (GUESS)', 'thiscall', None, ret=None, gen=_clear, note='batch307; ret 8')
S(0x61ba30, 'initObj (GUESS)', 'thiscall', None, ret='eax', gen=_init, note='batch307; ret 4; 0x61bb20 recorded')
