"""specs_s67502.py - cascade s6 batch 67502 (0x58bc60, thiscall(entry) ret 4). The entry's slot 0x2e8 object carries a name pointer (the exe string at 0x6ac9a0, a near miss, another
string or null = default) so both pose branches run; the matrix helpers 0x4de7a0 / 0x4deb20 / 0x4de480 (floats as bit patterns) and 0x4dcbb0 are recording hooks; this slot 0x290
(4 args, callee pops) logs the offset vector content; the table object supplies the handle."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g58bc60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4de7a0, 0, this='mark')
    hook_rec(c, 0x4deb20, 4, this='mark')

    def h480(em, res_):
        em.calllog.append(('4de480', 1 if em.reg('ecx') >= 0x30000000 else 0))
        em.ret(eax=0, argbytes=0)
    e.hook(0x4de480, h480)
    ref = e.rbytes(0x6ac9a0, 0x40)
    ref = ref[:ref.index(0)]
    mode = r.choice(['same', 'same', 'prefix', 'other', 'null', 'longer'])
    if mode == 'same':
        s = ref
    elif mode == 'prefix':
        s = ref[:max(0, len(ref) - 1)]
    elif mode == 'longer':
        s = ref + b'x'
    elif mode == 'other':
        s = bytes(r.randrange(65, 90) for _ in range(r.randint(1, 8)))
    else:
        s = None
    rr = rnd(c, 0x10)
    if s is None:
        _w(c, rr + 4, 0)
    else:
        a = e.alloc(len(s) + 8, 1)
        e.wbytes(a, s + b'\x00' + bytes(r.randrange(1, 255) for _ in range(7)))
        _w(c, rr + 4, a)
    entry = obj(c, 0x40, {0x2e8: pystub(c, 0, this=True, ret=rr)})
    _w(c, entry + 8, rnd(c, 0x20))
    hook_rec(c, 0x4dcbb0, 1, this=True)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    this = obj(c, 0xf00, {0x290: pystub(c, 4, this=True, stackmark=(2, 3), side=lambda em, k: em.calllog.append(('vec', em.rbytes(em.arg32(3), 12))))})
    _w(c, this + 0xeec, r.choice([0, 0, 1, 5]), 1)
    return [this, entry]


S(0x58bc60, 'GUESS pose_entry', 'thiscall', None, ret=None, gen=_g58bc60, note='batch67502')
