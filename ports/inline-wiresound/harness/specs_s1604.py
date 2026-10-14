"""specs_s1604.py - soundtimers batch 1604: ZFFActor::InitSounds.
FindInSoundSet is a Python stub that logs (set, pattern) and answers a hash, or 0 for patterns this case leaves out
of the set; the name registry lookup is a Python stub that logs the name and writes the out-reference."""
import zlib
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook

NAMES = ['*Nothing*', '*Pain*', '*Grenade*', '*Scout*', '*Helped*', '*Obs*', '*Attack*']


def _crt(c, seq):
    def new(e):
        return e.alloc(e.r32(e.reg('esp') + 4), 16)
    hook(c, seq, 0x41e290, 1, ret=new, this=False, pop=False)

    def memset(e, r):
        sp = e.reg('esp')
        d, v, n = e.r32(sp + 4), e.r32(sp + 8), e.r32(sp + 12)
        e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d)
    from sthelp import HOOKED
    c.emu.hook(0x634d10, memset)
    HOOKED.add(0x634d10)


def _findset(c, seq, missing):
    log = c.emu.alloc(4 + 50 * 20, 4)

    def h(e, r):
        sp = e.reg('esp')
        st, pat = e.r32(sp + 4), e.r32(sp + 8)
        s = bytes(e.rbytes(pat, 16)).split(b'\0')[0]
        n = e.r32(log)
        if n < 50:
            e.w32(log + 4 + 20 * n, st)
            e.wbytes(log + 8 + 20 * n, s[:16])
        e.w32(log, n + 1)
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(eax=0 if s.decode() in missing else (zlib.crc32(s) ^ st), argbytes=8)
    return c.emu.stub_fn('FindInSoundSet', h)


def _registry(c, seq, ref):
    log = c.emu.alloc(4 + 24, 4)

    def h(e, r):
        sp = e.reg('esp')
        name, out = e.r32(sp + 4), e.r32(sp + 8)
        e.wbytes(log + 4, bytes(e.rbytes(name, 20)).split(b'\0')[0][:20])
        e.w32(log, e.r32(log) + 1)
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        if ref is not None:
            e.w32(out, ref)
        e.ret(eax=0, argbytes=8)
    return c.emu.stub_fn('NameRegistry_Find', h)


def _init(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _crt(c, seq)
    missing = set(n for n in NAMES if r.random() < 0.3)
    dll = obj(c, 0x40, {0x60: _findset(c, seq, missing), 0x80: stub(c, seq, 1)})
    k = r.random()
    ref = None if k < 0.1 else (0 if k < 0.2 else r.getrandbits(32) | 1)
    reg = obj(c, 0x100, {0x88: _registry(c, seq, ref)})
    cc = rnd(c, 0x20)
    geom = obj(c, 0x200, {0x100: stub(c, seq, 1, ret=cc)})
    db = obj(c, 0x200, {0x138: stub(c, seq, 0, ret=reg), 0x58: stub(c, seq, 1, ret=geom)})
    sysobj(c, db=db, extra={0x1a9f: dll if r.random() < 0.9 else 0})
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 2, pop=False)})
    log = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, log)
    me = obj(c, 0xa00, {0x680: stub(c, seq, 0, ret=r.getrandbits(32) if r.random() < 0.85 else 0)})
    tm = rnd(c, 0x10)
    c.emu.w32(tm + 4, r.choice([0, 0, 1, 2, r.getrandbits(32)]))
    c.emu.w32(me + 0x54, tm)
    return [me]


S(0x5a04f0, 'ZFFActor::InitSounds', 'thiscall', None, ret=None, gen=_init,
  note='batch1604; 38-entry shout table, priority class, Character_Controller lookup')
