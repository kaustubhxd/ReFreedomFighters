"""specs_s213061.py - batch 213061: screen state machine message handler, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g56b730(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True)
    X = obj(c, 0x20, {0x5c: sl(3)}, nslots=0x20)
    tab = obj(c, 0x40, {0x134: sl(0, X), 0x20: sl(0)}, nslots=0x80)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, tab)
    o20 = obj(c, 0x20, {0x20: sl(0)}, nslots=0x10)
    this = obj(c, 0xd00, {0xd0: sl(1), 0xfc: sl(1)}, nslots=0x60)
    e.w32(this + 0xc5e, o20)
    e.w32(this + 0x94, rnd(c, 0x100))
    st = r.choice([8, 9, 13, 18, 16, 17, 20, 21, 23, 24, 26, 27, 29, 30, 32] * 2 + [10, 11, 12, 14, 15, 19, 22, 25, 28, 31, 7, 33, 0, 0xffffffff, r.getrandbits(32)])
    e.w32(this + 0xc82, st)
    e.w32(this + 0xcee, r.choice([4, 4, 4, 3, 0, r.getrandbits(32)]))
    for a, n in ((0x564600, 1), (0x5646e0, 1), (0x565100, 1), (0x56b460, 1), (0x56c6a0, 0), (0x562bc0, 0), (0x563440, 0), (0x5ae710, 1)):
        hook_rec(c, a, n, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x563400, 0, ret=r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)]), this=True)
    msg = r.choice([0x457, 0x8ae, 0xd05, 0x457, 0x8ae, 0xd05, 0, r.getrandbits(32)])
    return [this, msg]


S(0x56b730, 'screen_msg_handler', 'thiscall', None, ret=None, gen=g56b730)
