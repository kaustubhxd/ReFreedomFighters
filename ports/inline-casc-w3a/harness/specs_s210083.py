"""specs_s210083.py - Sonnet-w3a: 0x4618c0 (/GS). The strchr import at IAT 0x676254 is a stub returning a pointer into its argument (like the real one); report slot 0x2c is a custom stub that logs the string passed in the stack buffer."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g4618c0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, side=lambda emu, k: emu.calllog.append(('gs', emu.reg('ecx'))))
    e.w32(0x6f5630, 0)  # cookie 0 so the exe passes ecx = 0 like the port

    def strchr(emu, k):
        p = emu.arg32(0)
        s = emu.rbytes(p, 0x3e8)
        n = s.find(b'\0')
        i = s.find(b'#', 0, n)
        return 0 if i < 0 else p + i
    e.w32(0x676254, pystub(c, 2, ret=strchr, pop=0, stackmark=(0,)))

    def s2c(emu, res):
        buf = emu.arg32(4)
        s = emu.rbytes(buf, 0x3e8)
        s = s[:s.find(b'\0')]
        emu.calllog.append(('rep', emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.arg32(3), s))
        emu.ret(eax=emu.reg('eax'), argbytes=0)
    rep = obj(c, 0x40, {0x2c: e.stub_fn('rep', s2c)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=rep, this=True)}, nslots=0x20)
    e.w32(0x700390, g)
    o = rnd(c, 0x10); e.w32(o + 4, c.rng.choice([0, 0x1234, _r(c)]))
    s = obj(c, 0x20, {0x20: pystub(c, 0, ret=o, this=True)}, nslots=0x20)
    e.w32(s + 4, c.rng.choice([0, 0x5678, _r(c)]))
    n = c.rng.choice([0, 1, 5, 40])
    txt = bytes(c.rng.choice(b'ab#c') for _ in range(n)) + b'\0'
    st = rnd(c, 0x80); e.wbytes(st, txt)
    return [s, st, _r(c)]


S(0x4618c0, 'report_message_cut_at_hash', 'thiscall', None, ret='al', gen=g4618c0, note='batch210083')
