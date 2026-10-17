"""specs_s932.py - unclaimed-09 batch 24 (docs/20-unclaimed-09.md, claim 26): ZFFItemBomb::Load(ZLoadGame*).

The object is 0x100 random bytes (fields up to +0x6f). The global at 0x70039c is 0x2000 random bytes with +0x9b = M.
Every virtual call is a logged Python handler (unverified callees): the loader's slots 0x40 and 0x50 write a random dword at their
pointer argument and log it; slot 0x68 writes a random byte (the real byte loader); M's slot 0x58 logs its argument and returns a random dword; M's slot 0x138
returns R; R's slot 0x4c logs its two arguments (the constant and the value)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    dwords = [rng.getrandbits(32) for _ in range(8)]
    st = {'i': 0}
    mret = [rng.getrandbits(32) for _ in range(4)]
    mi = {'i': 0}

    def hload(e2, r):
        p = e2.arg32(0)
        v = dwords[st['i'] % 8]
        st['i'] += 1
        e2.w32(p, v)
        e2.calllog.append(('Load', v))
        e2.ret(argbytes=4)

    def hbyte(e2, r):
        p = e2.arg32(0)
        v = rng.getrandbits(8)
        e2.w8(p, v)
        e2.calllog.append(('Lbyte', v))
        e2.ret(argbytes=4)

    def hm58(e2, r):
        a = e2.arg32(0)
        v = mret[mi['i'] % 4]
        mi['i'] += 1
        e2.calllog.append(('M58', a))
        e2.ret(eax=v, argbytes=4)

    def hm138(e2, r):
        e2.calllog.append(('M138',))
        e2.ret(eax=robj, argbytes=0)

    def hr4c(e2, r):
        e2.calllog.append(('R4c', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    ld = e.fake_object('itembomb_loader', 0x40, slots={0x40: hload, 0x50: hload, 0x68: hbyte})
    robj = e.fake_object('itembomb_r', 0x40, slots={0x4c: hr4c})
    m = e.fake_object('itembomb_m', 0x40, slots={0x58: hm58, 0x138: hm138})
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, m)
    e.w32(0x70039c, g)
    this = _rnd(c, 0x100)
    return [this, ld]


S(0x5d4770, 'ZFFItemBomb::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b24; loader, manager and R stubbed (unverified callees)')
