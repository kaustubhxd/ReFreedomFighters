"""specs_s939.py - unclaimed-09 batch 31 (docs/20-unclaimed-09.md, claim 33): ZActorIf::RemoveFromMovingGroup(P).

Objects: P (0x100 random; P+4 -> Q, P+8 -> R2, both 0x100 random); this (0x100 random; +0x18 -> X). X is 0x800 random bytes
(the byte at +0x6fe lies inside it) with vtable slots 0x20 (returns Y), 0x370 (logs the 12 bytes behind both pointers) and 0x654
(logs its argument). Y (vt 0x20 returns Z; Y+8 -> a 0x40 object). Z is a 0x40 object. B (vt 0x288 logs its arguments) and C (vt
0x80 writes 12 random bytes behind each pointer and logs them). The engine object M (global+0x9b): vt 0x58 returns B then C and
logs the value it is given; vt 0x4c logs its argument and returns a random dword.

GUESS recording stubs (unverified callees), all hooked: 0x5003d0 (keyed lookup: logs its object and index; returns the heap cell
for that index: cells 0, 1, 2 and 3; cell 2 holds a 0/1 flag), 0x4dbe30 and 0x4dc440 (log object and argument), 0x5002f0 (logs
its object and its one argument, the value from M's vt+0x4c; ret 4). The cells are heap values, so every logged value is stable across exe and port."""
from pilot import S
from serial_stubs import rec


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    cells = {k: _rnd(c, 4) for k in (0, 1, 2, 3)}
    e.w32(cells[0], rng.getrandbits(32))
    e.w32(cells[1], rng.getrandbits(32))
    e.w32(cells[2], rng.randint(0, 1))
    mret = rng.getrandbits(32)
    seq = {'b': None, 'c': None}

    def h5003(e2, r):
        this = e2.reg('ecx')
        k = e2.arg32(0)
        cell = cells.get(k, cells[3])
        e2.calllog.append(('E5003d0', this, k))
        e2.ret(eax=cell, argbytes=4)

    def h4dbe(e2, r):
        e2.calllog.append(('Dbe30', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def h4dc4(e2, r):
        e2.calllog.append(('Dc440', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def h5002(e2, r):
        e2.calllog.append(('F5002f0', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    for addr, h in ((0x5003d0, h5003), (0x4dbe30, h4dbe), (0x4dc440, h4dc4), (0x5002f0, h5002)):
        e.hook(addr, h)

    def h_b288(e2, r):
        e2.calllog.append(('B288', e2.arg32(0), e2.arg32(1), e2.arg32(2)))
        e2.ret(argbytes=12)

    def h_c80(e2, r):
        p1, p2 = e2.arg32(0), e2.arg32(1)
        a = bytes(c.rng.getrandbits(8) for _ in range(12))
        b = bytes(c.rng.getrandbits(8) for _ in range(12))
        e2.wbytes(p1, a)
        e2.wbytes(p2, b)
        e2.calllog.append(('C80', a, b))
        e2.ret(argbytes=8)

    def h_x370(e2, r):
        p1, p2 = e2.arg32(0), e2.arg32(1)
        e2.calllog.append(('X370', bytes(e2.rbytes(p1, 12)), bytes(e2.rbytes(p2, 12))))
        e2.ret(argbytes=8)

    def h_x654(e2, r):
        e2.calllog.append(('X654', e2.arg32(0)))
        e2.ret(argbytes=4)

    def h_x20(e2, r):
        e2.calllog.append(('X20',))
        e2.ret(eax=yobj, argbytes=0)

    def h_y20(e2, r):
        e2.calllog.append(('Y20',))
        e2.ret(eax=zobj, argbytes=0)

    def h_m58(e2, r):
        a = e2.arg32(0)
        e2.calllog.append(('M58', a))
        i = seq['i'] if 'i' in seq else 0
        seq['i'] = i + 1
        e2.ret(eax=(bobj if i == 0 else cobj), argbytes=4)

    def h_m4c(e2, r):
        e2.calllog.append(('M4c', e2.arg32(0)))
        e2.ret(eax=mret, argbytes=4)

    zobj = e.fake_object('rmg_z', 0x40)
    yobj = e.fake_object('rmg_y', 0x40, slots={0x20: h_y20})
    e.w32(yobj + 8, _rnd(c, 0x40))
    xobj = e.fake_object('rmg_x', 0x800, slots={0x20: h_x20, 0x370: h_x370, 0x654: h_x654})
    e.wbytes(xobj + 4, bytes(rng.getrandbits(8) for _ in range(0x800 - 4)))
    bobj = e.fake_object('rmg_b', 0x40, slots={0x288: h_b288})
    cobj = e.fake_object('rmg_c', 0x40, slots={0x80: h_c80})
    m = e.fake_object('rmg_m', 0x40, slots={0x58: h_m58, 0x4c: h_m4c})
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, m)
    e.w32(0x70039c, g)
    p = _rnd(c, 0x100)
    e.w32(p + 4, _rnd(c, 0x100))
    e.w32(p + 8, _rnd(c, 0x100))
    this = _rnd(c, 0x100)
    e.w32(this + 0x18, xobj)
    return [this, p]


S(0x507b40, 'ZActorIf::RemoveFromMovingGroup (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b31; GUESS recording stubs for the keyed lookup, the engine/result vtables and the helpers')
