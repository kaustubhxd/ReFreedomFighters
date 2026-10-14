"""specs_s34041.py - cascade tier E, batch 34041.
0x54e6a0: enabled byte +0x1bc zero in a fifth; pool size n (unaligned +0x1c5) -2..4; usage bytes at +0x68 + i*0x6b random with the first free slot anywhere or none; every entry's embedded object
vtable pointer (+0x10 + i*0x6b, unaligned) has slot 4 as a recorder; a is unused.
0x552200 (stdcall): hooked 0x5003d0 returns an entry whose kind byte +4 is 3, 4 or another value (logger object at 0x700390 and assert hook set); kind 4 leads to an object with slot 0x34; hooked 0x589c20
returns a handle, hooked 0x59a580 (three stack args) returns random; global 0x7003b8 is a heap object.
0x562c20: logger object at 0x700390; hooked 0x562d90; key is 0x1388, 0x2b67 or another value."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _logger(c, slot2c=0x2c):
    lg2 = obj(c, 0x20, {slot2c: pystub(c, 3, this=True, pop=0)}, nslots=0x40 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)


def _g54e6a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x300)
    st = obj(c, 0x20, {4: pystub(c, 0, this=True)}, nslots=4)
    vt = e.r32(st)
    n = r.choice([-2, 0, 1, 2, 3, 4, r.randint(0, 4)])
    e.wbytes(me + 0x1c5, (n & 0xffffffff).to_bytes(4, 'little'))
    e.wbytes(me + 0x1bc, bytes([0 if r.random() < 0.2 else r.randrange(1, 256)]))
    free = r.choice([0, 1, 2, 3, -1])
    for i in range(4):
        e.wbytes(me + 0x68 + 0x6b * i, bytes([0 if i == free or r.random() < 0.15 else r.randrange(1, 256)]))
        e.wbytes(me + 0x10 + 0x6b * i, vt.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g552200(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    _logger(c)
    q = obj(c, 0x20, {0x34: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x40 // 4)
    ent = rnd(c, 0x20)
    kind = r.choice([3, 4, 4, 0, 1, 2, 5, 0x103, r.getrandbits(8)])
    c.emu.wbytes(ent + 4, bytes([kind & 0xff]))
    c.emu.w32(ent, q if (kind & 0xff) == 4 else r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, ret=ent, this=True)
    hook_rec(c, 0x589c20, 1, ret=rnd(c, 0x20), this=True)
    hook_rec(c, 0x59a580, 3, ret=r.getrandbits(32), this=True)
    c.emu.w32(0x7003b8, rnd(c, 0x20))
    a = rnd(c, 0x20)
    c.emu.w32(a + 4, rnd(c, 0x20))
    return [a]


def _g562c20(c):
    clear_hooks(c)
    r = c.rng
    _logger(c)
    hook_rec(c, 0x562d90, 1, this=True)
    k = r.choice([0x1388, 0x2b67, 0x1388, 0x2b67, 0, 1, 0x1387, 0x2b68, r.getrandbits(32)])
    return [rnd(c, 0x20), k]


S(0x54e6a0, 'GUESS claim free slot of a 0x6b-byte-entry pool', 'thiscall', None, ret='eax', gen=_g54e6a0, note='batch34041')
S(0x552200, 'GUESS resolve value by kind and hand to two helper objects', 'stdcall', None, ret='eax', gen=_g552200, note='batch34041')
S(0x562c20, 'GUESS log key and map two keys to commands', 'thiscall', None, ret='al', gen=_g562c20, note='batch34041')
