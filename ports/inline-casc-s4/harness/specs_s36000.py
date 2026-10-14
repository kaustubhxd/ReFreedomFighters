"""specs_s36000.py - cascade s4 batch 36000: 0x435c90 (three vcall loops), 0x427900 (buffer + vcalls + log), 0x41f8f0 (string + IsBadReadPtr + engine slot 0x34)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g435c90(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c)
    st = pystub(c, 1, this=True)
    me = rnd(c, 0x80)
    e = c.emu
    for off, mx in ((4, 2), (0x10, 3), (0x20, 16)):
        for i in range(mx):
            e.w32(me + off + 4 * i, obj(c, 0x10, {0x24: st}))
    for off, mx in ((0xc, 2), (0x1c, 3), (0x60, 16)):
        e.w32(me + off, r.choice([0, 1, mx, r.randint(0, mx)]))
    return [me]


def _g427900(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    fill = rnd(c, 0x400)
    rv = (0xffffffff if r.random() < 0.3 else r.getrandbits(32))
    rv2 = (0xffffffff if r.random() < 0.4 else r.getrandbits(32))

    def fillbuf(em, k):
        em.wbytes(em.arg32(0), em.rbytes(fill, 0x400))
    me = obj(c, 0x40, {0x144: pystub(c, 3, this=True, deref={0: -0x400}, side=fillbuf),
                       0xe0: pystub(c, 2, this=True, ret=rv)})
    e2 = obj(c, 0x20, {0x60: pystub(c, 5, this=True, deref={0: -0x400}, ret=rv2)})
    e.w32(0x700394, e2)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g41f8f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    flag = r.random() < 0.5
    ev = r.getrandbits(32)

    def isbad(em, res):
        em.calllog.append(('isbad', em.arg32(0), em.arg32(1)))
        em.ret(eax=1 if flag else 0, argbytes=8)
    e.stub_import('IsBadReadPtr', isbad)

    def v34(em, res):
        a = [em.arg32(i) for i in range(6)]
        s = b''
        p = a[1]
        while True:
            ch = em.rbytes(p, 1)
            if ch == b'\0':
                break
            s += ch
            p += 1
        em.calllog.append(('v34', a[0], s, tuple(a[2:])))
        em.ret(eax=ev, argbytes=0)
    eng = obj(c, 0x20, {0x34: e.stub_fn('v34', v34)})
    e.w32(0x700390, eng)
    n = r.choice([0, 1, 5, r.randint(0, 0x1c0)])
    a = e.alloc(0x200, 4)
    e.wbytes(a, bytes(r.randint(1, 255) for _ in range(n)) + b'\0')
    b = rnd(c, 0x30)
    return [a, b]


S(0x435c90, 'GUESS notify three child lists', 'thiscall', None, ret=None, gen=_g435c90, note='batch36000')
S(0x427900, 'GUESS fill buffer, lookup, log on failure', 'thiscall', None, ret='al', gen=_g427900, note='batch36000')
S(0x41f8f0, 'GUESS format string + log', 'stdcall', None, ret=None, gen=_g41f8f0, note='batch36000')
