"""specs_s922.py - unclaimed-09 batch 14 (docs/20-unclaimed-09.md, claim 14): CCheckInsideBox::Load(ZLoadGame*).

The object is 0x100 random bytes. The loader is a fake object with a logged slot 0x40 handler that writes the next value
of a random sequence (four values per case) at its pointer argument; it logs the value, never the pointer (a stack
pointer for the reused argument slot). The global's +0x9b object M has slot 0x58 that logs its argument and returns a
random dword. Both are unverified callees."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    seq = [rng.getrandbits(32) for _ in range(4)]
    state = {'i': 0}
    mret = [rng.getrandbits(32), rng.getrandbits(32)]
    mi = {'i': 0}

    def h40(e2, r):
        p = e2.arg32(0)
        v = seq[state['i'] % 4]
        state['i'] += 1
        e2.w32(p, v)
        e2.calllog.append(('L40', v))
        e2.ret(argbytes=4)

    def h58(e2, r):
        a = e2.arg32(0)
        e2.calllog.append(('M58', a))
        v = mret[mi['i'] % 2]
        mi['i'] += 1
        e2.ret(eax=v, argbytes=4)

    ld = e.fake_object('checkinside_loader', 0x40, slots={0x40: h40})
    m = e.fake_object('checkinside_mgr', 0x40, slots={0x58: h58})
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, m)
    e.w32(0x70039c, g)
    this = _rnd(c, 0x100)
    return [this, ld]


S(0x5b8180, 'CCheckInsideBox::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b14; loader slot 0x40 and manager slot 0x58 stubbed (unverified callees)')
