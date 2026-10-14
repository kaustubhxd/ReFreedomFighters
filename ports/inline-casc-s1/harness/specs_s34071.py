"""specs_s34071.py - cascade tier E, batch 34071.
0x55c9b0: [a+4] manager with hooked 0x5003d0 returning a cell (byte +4 in 0, 1 or other); the engine object 0x700390 slot 0x20 returns a printer whose slot 0x2c is a cdecl recorder; assert hook 0x7003b0 recorder; [this+0x1c] slot 0x728 recorder.
0x5764c0: byte +0x20b mostly set; [this+0x94] block with byte +0x103e / +0x1040 random, name at +0x48 equal to the exe string 0x6a6e5c in half the cases (also a one-byte difference); hooked 0x575ee0 / 0x562b50; this slot 0xe8 recorder.
0x57dfb0 (2 args, b used): this+0x264 is an object whose slot 0x2c returns random (zero in a third); table object slot 0x58 returns an object with [+8] = receiver; hooked 0x4db500; /GS recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g55c9b0(c):
    clear_hooks(c)
    r = c.rng
    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))
    cell = rnd(c, 0x10)
    c.emu.wbytes(cell + 4, bytes([r.choice([0, 1, 2, 4, 0xff])]))
    hook_rec(c, 0x5003d0, 1, ret=cell, this=True)
    pr = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)}, nslots=0x30 // 4)
    sysx = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, sysx)
    tgt = obj(c, 0x20, {0x728: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x72c // 4)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, tgt)
    a = rnd(c, 0x10)
    c.emu.w32(a + 4, rnd(c, 0x10))
    return [me, a]


def _g5764c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x575ee0, 0, this=True, pop=0)
    hook_rec(c, 0x562b50, 1, this=True)
    me = obj(c, 0x230, {0xe8: pystub(c, 0, this=True)}, nslots=0xec // 4)
    c.emu.wbytes(me + 0x20b, bytes([r.choice([0, 1, 1, 1, 7])]))
    e = rnd(c, 0x1050)
    ref = bytes(c.emu.rbytes(0x6a6e5c, 40)).split(b'\0')[0]
    mode = r.choice(['eq', 'eq', 'diff', 'rnd', 'prefix'])
    name = ref + b'\0'
    if mode == 'diff' and ref:
        i = r.randrange(len(ref))
        name = ref[:i] + bytes([ref[i] ^ 0x20]) + ref[i + 1:] + b'\0'
    elif mode == 'prefix':
        name = ref[:-1] + b'\0' if ref else b'\0'
    elif mode == 'rnd':
        name = bytes(r.getrandbits(8) | 1 for _ in range(5)) + b'\0'
    c.emu.wbytes(e + 0x48, name)
    c.emu.wbytes(e + 0x103e, bytes([r.choice([0, 1, 1, 1, 9])]))
    c.emu.wbytes(e + 0x1040, bytes([r.choice([0, 0, 3])]))
    c.emu.w32(me + 0x94, e)
    return [me]


def _g57dfb0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, pop=0)
    hook_rec(c, 0x4db500, 1, this=True, stackmark=(0,))
    recv = rnd(c, 0x20)
    o = rnd(c, 0x20)
    c.emu.w32(o + 8, recv)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(0x70039c, so)
    c.emu.w32(so + 0x9b, tbl)
    me = rnd(c, 0x360)
    sub = obj(c, 0x20, {0x2c: pystub(c, 1, ret=r.choice([0, 0, r.getrandbits(32) | 1]), this=True)}, nslots=0x30 // 4)
    c.emu.w32(me + 0x264, c.emu.r32(sub))   # embedded object: its vtable pointer lives in this+0x264
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x55c9b0, 'GUESS checked forward of a slot id', 'thiscall', None, ret='eax', gen=_g55c9b0, note='batch34071')
S(0x5764c0, 'GUESS pick message by name compare', 'thiscall', None, ret=None, gen=_g5764c0, note='batch34071')
S(0x57dfb0, 'GUESS lookup result bookkeeping', 'thiscall', None, ret='al', gen=_g57dfb0, note='batch34071')
